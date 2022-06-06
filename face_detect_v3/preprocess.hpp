//
// Created by iotuser on 22. 4. 27.
//

#ifndef FACE_DETECT_V3_PREPROCESS_HPP
#define FACE_DETECT_V3_PREPROCESS_HPP

#endif //FACE_DETECT_V3_PREPROCESS_HPP


#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void load_cascade(CascadeClassifier& cascade, string fname)
{
    String  path = "/home/iotuser/opencv/opencv-4.4.0/data/haarcascades/";	// 검출기 폴더
    String  full_name = path + fname;

    CV_Assert(cascade.load(full_name));					// 분류기 로드 및 예외처리
}

Mat preprocessing(Mat image)
{
    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);	// 명암도 영상변환
    equalizeHist(gray, gray);					// 히스토그램 평활화
    return gray;
}
