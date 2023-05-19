#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <fstream>

using namespace cv;
using namespace dnn;
using namespace std;

// Initialisiere die Klassenbezeichnungen
vector<string> classes;
void initClasses(const string& file) {
    ifstream ifs(file.c_str());
    string line;
    while (getline(ifs, line)) classes.push_back(line);
}

int main(int argc, char** argv) {
    // Lade das YOLOv3-Modell
    Net net = readNetFromDarknet("yolov3.cfg", "yolov3.weights");
    net.setPreferableBackend(DNN_BACKEND_OPENCV);
    net.setPreferableTarget(DNN_TARGET_CPU);

    // Initialisiere die Klassenbezeichnungen
    initClasses("coco.names");

    // Lade das Bild
    Mat img = imread("image.jpg");

    // Erstelle einen 4D-Blob aus dem Bild
    Mat blob;
    blobFromImage(img, blob, 1 / 255.0, Size(416, 416), Scalar(0, 0, 0), true, false);

    // Setze den Blob als Eingabe für das Netzwerk
    net.setInput(blob);

    // Führe einen Vorwärtsdurchlauf durch das Netzwerk durch
    vector<Mat> outs;
    net.forward(outs, net.getUnconnectedOutLayersNames());

    // Extrahiere die Bounding-Boxen und Klassenbezeichnungen
    vector<int> classIds;
    vector<float> confidences;
    vector<Rect> boxes;
    for (size_t i = 0; i < outs.size(); ++i) {
        for (int j = 0; j < outs[i].rows; ++j) {
            Mat scores = outs[i].row(j).colRange(5, outs[i].cols);
            Point classIdPoint;
            double confidence;
            minMaxLoc(scores, 0, &confidence, 0, &classIdPoint);
            if (confidence > 0.5) {
                int centerX = (int)(outs[i].at<float>(j, 0) * img.cols);
                int centerY = (int)(outs[i].at<float>(j, 1) * img.rows);
                int width = (int)(outs[i].at<float>(j, 2) * img.cols);
                int height = (int)(outs[i].at<float>(j, 3) * img.rows);
                int left = centerX - width / 2;
                int top = centerY - height / 2;

                classIds.push_back(classIdPoint.x);
                confidences.push_back((float)confidence);
                boxes.push_back(Rect(left, top, width, height));
            }
        }
    }

    // Wende Non-Maximum Suppression an
    vector<int> indices;
    NMSBoxes(boxes, confidences, 0.5, 0.4, indices);

    // Zeichne die Bounding-Boxen und Klassenbezeichnungen
    for (size_t i = 0; i < indices.size(); ++i) {
        int idx = indices[i];
        Rect box = boxes[idx];
        string label = classes[classIds[idx]];
        rectangle(img, box, Scalar(0, 255, 0));
        putText(img, label, box.tl(), FONT_HERSHEY_SIMPLEX, 1.0,
            Scalar(255, 255, 255), 2);
    }

    // Zeige das Ergebnis an
    imshow("YOLOv3", img);
    waitKey();

    return 0;
}