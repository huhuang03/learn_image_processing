//
// Created by hwf on 2021/11/3.
//

#include "./custom_equalize.h"

int main() {
    cv::Mat1b img = cv::imread("../imgs/lena.jpg", cv::IMREAD_GRAYSCALE);
    cv::imshow("origin", img);

    cv::Mat equalize1;
    cv::equalizeHist(img, equalize1);
    cv::imshow("official equalize", equalize1);

//    cv::Mat equalize2;
//    custom_equalize(img, equalize2);
//    cv::imshow("custom equalize", equalize1);

    cv::waitKey(0);
    return 0;
}
