#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

vector<Rect> icons;
Mat image;

#include "menu.hpp"
#include "icon_flag.hpp"


int main() {

    image = Mat(500, 800, CV_8UC3, Scalar(255,255,255));
    place_icons(Size(60,60));

    Rect last_icon = *(icons.end() - 1);
    Point start_pale = Point(0, last_icon.br().y + 5);

    icons.push_back(Rect(start_pale, Size(100,100)));
    icons.push_back(Rect(start_pale + Point(105, 0), Size(15, 100)));

    create_hueIndex(icons[HUE_IDX]);
    create_palette(start_pale.y, icons[PALETTE]);

    imshow("image", image);
    waitKey();

    return 0;
}
