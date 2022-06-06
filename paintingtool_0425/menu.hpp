#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#include "icon_flag.hpp"

//
// Created by iotuser on 22. 4. 25.
//

#ifndef PAINTINGTOOL_0425_MENU_H
#define PAINTINGTOOL_0425_MENU_H

#endif //PAINTINGTOOL_0425_MENU_H




//vector<Rect> btn;
int hue;


// 아이콘 배치 및 팔레트 생성

void place_icons(Size size) // size: 아이콘 크기
{
    vector<string> icon_name={
            "rect", "circle", "eclipe", "line", "brush", "eraser", "open",
            "save", "clear", "plus", "minus", "color"
    };

    int btn_rows = (int)cvCeil(icon_name.size()/ 2.0);

    for (int i = 0, k = 0; i <btn_rows; i++)
    {
        for (int j = 0; j < 2; j++, k++)
        {
            Point pt(j * size.width, i * size.height);  //각 아이콘 시작 위치
            icons.push_back(Rect(pt, size));                    // 각 아이콘 관심 영역

            Mat icon = imread("/home/iotuser/CLionProjects/image/icon/" + icon_name[k] + ".jpg", 1);
            if (icon.empty()) continue;    // 예외 처리

            resize(icon, icon, size);  //아이콘 영상 크기 통일
            icon.copyTo(image(icons[k]));               // 아이콘 영상 복사
        }
    }
}


// 색상 인덱스 영역 그리기

void create_hueIndex(Rect rect)             // rect : 색상 인덱스 영역
{
    Mat m_hueIdx = image(rect);             // 색상 인덱스 영역 참조
    float ratio = 180.0f / rect.height;     // 색상 인덱스 세로 크기의 hue 스케일

    for (int i = 0; i < rect.height; i++)
    {
        Scalar hue_color(i * ratio, 255, 255);  // HSV 색상 지정
        m_hueIdx.row(i).setTo(hue_color);         // 한 행의 색상 지정
    }
    cvtColor(m_hueIdx, m_hueIdx, COLOR_HSV2BGR); // HSV에서 RGB로 변환
}


// 팔레트 영역 그리기
void create_palette(int pos_y, Rect rect_pale)
{
    // pos_y : 마우스 클릭 y 좌표, rect_pale: 팔레트 영역

    Mat m_palette = image(rect_pale);               // 팔레트 영역 참조
    float ratio1 = 180.0f / rect_pale.height;   // 팔레트 높엥 따른 hue 비율
    float ratio2 = 256.0f / rect_pale.width;    // 팔레트 너비에 따른 saturation 비율
    float ratio3 = 256.0f / rect_pale.height;   // 팔레트 높이에 따른 intensity 비율

    hue = cvRound((pos_y - m_palette.rows) * ratio1);   // 색상 팔레트 기본 색상

    for (int i = 0; i< m_palette.rows; i++)     //색상 팔레트 조회
    {
        for (int j = 0; j < m_palette.cols; j++)
        {
            int saturation = cvRound(j * ratio2);   // 채도 계산
            int intensity = cvRound((m_palette.rows -i -1) * ratio3);   // 명도 계산
            m_palette.at<Vec3b>(i,j) = Vec3b(hue, saturation, intensity); //  HSV 색상 지정
        }
    }
    cvtColor(m_palette, m_palette, COLOR_HSV2BGR);     // HSV에서 RGB로 변환
}
