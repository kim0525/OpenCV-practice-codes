#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
//    cout << "Hello, World!" << endl;
//    cout << CV_VERSION << endl;
//    return 0;

    cout << CV_VERSION << endl;
    Mat img = imread("/home/iotuser/CLionProjects/image/icon/brush.jpg", IMREAD_COLOR);
    imshow("img", img);
    waitKey();
    return 0;
}