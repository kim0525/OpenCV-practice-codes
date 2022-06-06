#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

vector<Rect> icons;
Mat	 image, canvas;;
int  mouse_mode = 0, draw_mode = 0;
Point	pt1, pt2;
Scalar  Color(0, 0, 0);
int		thickness = 3;

#include "menu.hpp"
#include "icon_flag.hpp"
#include "draw.hpp"
#include "event.hpp"

void  onTrackbar(int value, void*) {
    mouse_mode = 0;
}

int main()
{
    image = Mat(500, 800, CV_8UC3, Scalar(255, 255, 255));	// 그림판 영상
    place_icons(Size(60, 60));						// 아이콘 배치, 아이콘 크기

    Rect last_icon = *(icons.end() - 1);				// 아이콘 사각형 마지막 원소
    Point start_pale = Point(0, last_icon.br().y + 5);		// 마지막 아이콘 5픽셀 아래

    icons.push_back(Rect(start_pale, Size(100, 100)));	// 팔레트 사각형 추가
    icons.push_back(Rect(start_pale + Point(105, 0), Size(15, 100))); // 색상인덱스 사각형 추가

    create_hueIndex(icons[HUE_IDX]);					// 팔레트 생성
    create_palette(start_pale.y, icons[PALETTE]);		// 색상인덱스 생성

    imshow("그림판", image);
    setMouseCallback("그림판", onMouse);

    // 11.5 추가
    createTrackbar("선굵기 ", "그림판", &thickness, 20, onThickbar);
    int  x = icons[1].br().x;
    canvas = image(Rect(x, 0, image.cols - x, image.rows));

    //11.5 추가 전 (똑같이 작동함)
//    createTrackbar("선굵기 ", "그림판", &thickness, 20, onTrackbar);	// 트렉바 등록
//    int  x = icons[1].br().x;									// 두번째 아이콘 x좌표
//    Rect canvas_rect(x, 0, image.cols - x, image.rows);			// 그림(캔버스) 영역
//    canvas = image(canvas_rect);									// 캔버스 행렬

    while (1)
    {
        if (mouse_mode == 1) 			// 마우스 버튼 떼기
            draw(image, Color);
        else if (mouse_mode == 3)			// 마우스 드래그
        {
            if (draw_mode == DRAW_BRUSH || draw_mode == ERASE) {
                draw(image, Color);
            }
            else {
                draw(image.clone());
            }
        }
        if (waitKey(30) == 27)  break;
    }

    waitKey();
    return 0;
}



//#include <opencv2/opencv.hpp>
//using namespace cv;
//using namespace std;
//
//vector<Rect> icons;
//Mat	  image;
//int   mouse_mode = 0, draw_mode = 0;
//Point   pt1, pt2;
//Scalar  Color(0, 0, 0);								// 색상 변수 – 전역변수 지정
//
//#include "menu.hpp"
//#include "icon_flag.hpp"							// 아이콘 상수
//
//void  command(int mode)				// 일반 명령 수행
//{
//    if (mode == PALETTE)						// 색상팔레트 영역 클릭
//    {
//        float  ratio1 = 256.0f / icons[PALETTE].width;		// 너비로 채도 비율 지정
//        float  ratio2 = 256.0f / icons[PALETTE].height;		// 높이로 명도 비율 지정
//
//        /// br을 tl으로 고침
//        Point pt = pt2 - icons[PALETTE].tl();						// 팔레트 내 클릭좌표
//        int saturation = cvRound(pt.x * ratio1);
//        int value = cvRound((icons[PALETTE].height - pt.y - 1) *ratio2);
//        Scalar  hsv(hue, saturation, value);					// HSV 색상 지정
//
//        Mat    m_color = image(icons[COLOR]);			// 색상아이콘 참조
//        m_color.setTo(hsv);
//        cvtColor(m_color, m_color, COLOR_HSV2BGR);		// HSV → BGR 변환
//        rectangle(image, icons[COLOR], Scalar(0, 0, 0), 1);	// 색상 아이콘 테두리색
//
//        Color = Scalar(m_color.at < Vec3b >(10, 10));
//    }
//    else if (mode == HUE_IDX)							// 색상인덱스 클릭시
//    {
//        create_palette(pt2.y, icons[PALETTE]);				// 팔레트 다시 그리기
//    }
//
//    imshow("그림판", image);
//}
//
//static void onMouse(int event, int x, int y, int, void*)
//{
//    Point pt(x, y);
//    if (event == EVENT_LBUTTONUP) 				// 왼쪽버튼 떼기
//    {
//        for (int i = 0; i < (int)icons.size(); i++) 		// 메뉴아이콘 사각형 조회
//        {
//            if (icons[i].contains(pt)) {					// 메뉴 클릭 여부 검사
//                if (i < 6)  							// 그리기 명령이면
//                {
//                    mouse_mode = 0;					// 마우스 상태 초기화
//                    draw_mode = i;					// 그리기 모드
//                }
//                else		command(i);					// 일반 명령이면
//                return;
//            }
//        }
//        pt2 = pt;										// 종료좌표 저장
//        mouse_mode = 1;								// 버튼 떼기 상태 지정
//    }
//    else if (event == EVENT_LBUTTONDOWN) 	// 왼쪽버튼 누르기
//    {
//        pt1 = pt;										// 시작좌표 저장
//        mouse_mode = 2;
//    }
//
//    if (mouse_mode >= 2) {							// 왼쪽버튼 누리기 or 드래그
//        Rect rect(0, 0, 125, image.rows);
//        mouse_mode = (rect.contains(pt)) ? 0 : 3;		// 마우스 상태 지정
//        pt2 = pt;
//    }
//}
//
//
//int main()
//{
//    image = Mat(500, 800, CV_8UC3, Scalar(255, 255, 255));	// 그림판 영상
//    place_icons(Size(60, 60));						// 아이콘 배치, 아이콘 크기
//
//    Rect last_icon = *(icons.end() - 1);				// 아이콘 사각형 마지막 원소
//    Point start_pale = Point(0, last_icon.br().y + 5);		// 마지막 아이콘 5픽셀 아래
//
//    icons.push_back(Rect(start_pale, Size(100, 100)));	// 팔레트 사각형 추가
//    icons.push_back(Rect(start_pale + Point(105, 0), Size(15, 100))); // 색상인덱스 사각형 추가
//
//    create_hueIndex(icons[HUE_IDX]);					// 팔레트 생성
//    create_palette(start_pale.y, icons[PALETTE]);		// 색상인덱스 생성
//
//    imshow("그림판", image);
//    setMouseCallback("그림판", onMouse);
//    waitKey();
//    return 0;
//}
