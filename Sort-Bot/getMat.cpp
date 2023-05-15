#pragma once
#include "getMat.h"
#include "InputMK.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "Checks.h"
using namespace std;
using namespace cv;

cv::Mat GetMat::getMat(HWND hWND) {
	RECT client_rect = { 0 };
	GetWindowRect(hWND, &client_rect);
	int width = client_rect.right - client_rect.left;
	int height = client_rect.bottom - client_rect.top;


	HDC hdcScreen = GetDC(HWND_DESKTOP);
	HDC hdc = CreateCompatibleDC(hdcScreen);
	HBITMAP hbmp = CreateCompatibleBitmap(hdcScreen, width, height);
	SelectObject(hdc, hbmp);

	BitBlt(hdc, 0, 0, width, height, hdcScreen, client_rect.left, client_rect.top, SRCCOPY);

	BITMAPINFO bmp_info = { 0 };
	bmp_info.bmiHeader.biSize = sizeof(bmp_info.bmiHeader);
	bmp_info.bmiHeader.biWidth = width;
	bmp_info.bmiHeader.biHeight = height;
	bmp_info.bmiHeader.biPlanes = 1;
	bmp_info.bmiHeader.biBitCount = 24;
	bmp_info.bmiHeader.biCompression = BI_RGB;

	int bmp_padding = (width * 3) % 4;
	if (bmp_padding != 0) bmp_padding = 4 - bmp_padding;

	BYTE* bmp_pixels = new BYTE[(width * 3 + bmp_padding) * height];
	GetDIBits(hdc, hbmp, 0, height, bmp_pixels, &bmp_info, DIB_RGB_COLORS);

	string Name = "TempIMG.png";
	wstring temp = wstring(Name.begin(), Name.end());
	LPCWSTR wideString = temp.c_str();

	BITMAPFILEHEADER bmfHeader{};
	HANDLE bmp_file_handle = CreateFile(wideString, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);


	// Add the size of the headers to the size of the bitmap to get the total file size
	DWORD dwSizeofDIB = (static_cast<unsigned long long>(width) * 3 + bmp_padding) * height + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

	//Offset to where the actual bitmap bits start.
	bmfHeader.bfOffBits = (DWORD)sizeof(BITMAPFILEHEADER) + (DWORD)sizeof(BITMAPINFOHEADER);

	//Size of the file
	bmfHeader.bfSize = dwSizeofDIB;

	//bfType must always be BM for Bitmaps
	bmfHeader.bfType = 0x4D42; //BM

	DWORD dwBytesWritten = 0;
	WriteFile(bmp_file_handle, (LPSTR)&bmfHeader, sizeof(BITMAPFILEHEADER), &dwBytesWritten, NULL);
	WriteFile(bmp_file_handle, (LPSTR)&bmp_info.bmiHeader, sizeof(BITMAPINFOHEADER), &dwBytesWritten, NULL);
	WriteFile(bmp_file_handle, (LPSTR)bmp_pixels, (width * 3 + bmp_padding) * height, &dwBytesWritten, NULL);

	//Close the handle for the file that was created
	CloseHandle(bmp_file_handle);

	Mat mat = cv::imread("TempIMG.png");
	return  mat;

	DeleteDC(hdc);
	DeleteObject(hbmp);
	ReleaseDC(HWND_DESKTOP, hdcScreen);
	ReleaseDC(hWND, hdcScreen);
	delete[] bmp_pixels;
}

std::vector<cv::Mat> GetMat::MatScreenVector;

void GetMat::TakeScreenshots(){//Please call first CheckScrollbarPositions!!
	Mat MatScreen;
	checksPublic ChecksPublic;
	
	const HWND hWND = FindeWindow();
	SetForegroundWindow(hWND);
	
	for (int i = 0; i < 6; i++) {
		Sleep(200);      
		MatScreenVector.push_back(getMat(hWND));
		Sleep(200);
		int keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key
		Keyboard::KeyboardInput(keyforInput);
	}
}

HWND GetMat::FindeWindow() {
	HWND hWND;
	LPCWSTR windowTitle = L"EscapeFromTarkov";
	hWND = FindWindow(NULL, windowTitle);
	while (!hWND)
	{
		system("cls");
		cout << "game not found" << endl;
		hWND = FindWindow(NULL, windowTitle);
		Sleep(100);
	}

	if (hWND) {
		cout << "Found" << endl;
		return hWND;
	}
}