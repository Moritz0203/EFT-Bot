#pragma once
#include "Includes.h"
using namespace std;

struct GetMat {
	static cv::Mat getMat(HWND hWND);

	static void TakeScreenshots();

	static HWND FindeWindow();
};

//cv::Mat getMatNotWorking(HWND hWND) {
//	//HDC deviceContext = GetDC(hWND);
//	//HDC memoryDeviceContext = CreateCompatibleDC(deviceContext);
//
//	//RECT windowRect;
//	//GetClientRect(hWND, &windowRect);
//
//	//int height = windowRect.bottom;
//	//int width = windowRect.right;
//
//	//HBITMAP bitmap = CreateCompatibleBitmap(deviceContext, width, height);
//
//	//SelectObject(memoryDeviceContext, bitmap);
//	//BitBlt(memoryDeviceContext, 0, 0, width, height, deviceContext, 0, 0, SRCCOPY);
//
//	//BITMAPINFOHEADER bi;
//	//bi.biSize = sizeof(BITMAPINFOHEADER);
//	//bi.biWidth = width;
//	//bi.biHeight = -height;
//	//bi.biPlanes = 1;
//	//bi.biBitCount = 32;
//	//bi.biCompression = BI_RGB;
//	//bi.biSizeImage = 0;
//	//bi.biXPelsPerMeter = 1;
//	//bi.biYPelsPerMeter = 2;
//	//bi.biClrUsed = 3;
//	//bi.biClrImportant = 4;
//
//	//cv::Mat mat = cv::Mat(height, width, CV_8UC4); // 8 bit unsigned ints 4 Channels -> RGBA
//
//
//	//GetDIBits(memoryDeviceContext, bitmap, 0, height, mat.data, (BITMAPINFO*)&bi, DIB_RGB_COLORS);
//
//
//	//cout << "Update" << endl;
//
//	//DeleteObject(bitmap);
//	//DeleteDC(memoryDeviceContext);
//	//ReleaseDC(hWND, deviceContext);
//
//	RECT client_rect = { 0 };
//	GetWindowRect(hWND, &client_rect);
//	int width = client_rect.right - client_rect.left;
//	int height = client_rect.bottom - client_rect.top;
//
//
//	HDC hdcScreen = GetDC(HWND_DESKTOP);
//	HDC hdc = CreateCompatibleDC(hdcScreen);
//	HBITMAP hbmp = CreateCompatibleBitmap(hdcScreen, width, height);
//	SelectObject(hdc, hbmp);
//
//	BitBlt(hdc, 0, 0, width, height, hdcScreen, client_rect.left, client_rect.top, SRCCOPY);
//
//	BITMAPINFO bmp_info = { 0 };
//	bmp_info.bmiHeader.biSize = sizeof(bmp_info.bmiHeader);
//	bmp_info.bmiHeader.biWidth = width;
//	bmp_info.bmiHeader.biHeight = -height;
//	bmp_info.bmiHeader.biPlanes = 1;
//	bmp_info.bmiHeader.biBitCount = 24;
//	bmp_info.bmiHeader.biCompression = BI_RGB;
//
//	/*int bmp_padding = (width * 3) % 4;
//	if (bmp_padding != 0) bmp_padding = 4 - bmp_padding;
//
//	BYTE* bmp_pixels = new BYTE[(width * 3 + bmp_padding) * height];*/
//
//	cv::Mat mat = cv::Mat(height, width, CV_8UC4);
//	GetDIBits(hdc, hbmp, 0, height, mat.data, (BITMAPINFO*)&bmp_info, DIB_RGB_COLORS);
//
//
//	DeleteDC(hdc);
//	DeleteObject(hbmp);
//	ReleaseDC(HWND_DESKTOP, hdcScreen);
//	ReleaseDC(hWND, hdcScreen);
//
//	return mat;
//}