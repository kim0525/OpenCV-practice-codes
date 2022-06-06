#include <iostream>

#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

#include "histo.hpp"
#include "utils.hpp"

//int main()
//{
//    Vec3i divs(30, 42, 0);
//    Vec3f ranges(180, 256, 0);
//    vector<Mat> DB_hists = load_histo(divs, ranges);
//    Mat query = query_img();
//
//    Mat  hs_hist;
//    calc_histo(query, hs_hist, divs, ranges, 2);
//    Mat hist_img = draw_histo(hs_hist);
//
//    imshow("image", query);
//    imshow("hist_img", hist_img);
//    waitKey();
//
//    return 0;
//}

int main()
{
    Vec3i bins(30, 42, 0);
    Vec3f ranges(180, 256, 0);

    vector<Mat> DB_hists = load_histo1(bins, ranges, 100);
    Mat query = query_img();

    Mat hsv, query_hist;
    cvtColor(query, hsv, COLOR_BGR2HSV);					// HSV 컬러 변환
    calc_histo1(hsv, query_hist, bins, ranges, 2);
    Mat hist_img = draw_histo1(query_hist);

    Mat DB_similaritys = calc_similarity(query_hist, DB_hists);

    double  sinc ;
    cout << "   기준 유사도 입력: ";
    cin >> sinc;
//	select_view(sinc, DB_similaritys);
    select_view(sinc, DB_similaritys, bins, ranges);

    imshow("image", query);
    imshow("hist_img", hist_img);
    waitKey();

    return 0;
}