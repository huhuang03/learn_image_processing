//
// Created by huhua on 2021/11/6.
//

#include <opencv2/opencv.hpp>


int main() {
    cv::Mat1b img = cv::imread("../imgs/lena.jpg", cv::IMREAD_GRAYSCALE);
    cv::imshow("origin", img);

    cv::Mat saltPepperNoise = cv::Mat::zeros(img.size(), CV_8U);
    cv::randu(saltPepperNoise, 0, 255);
    cv::Mat black = saltPepperNoise < 30;
    cv::Mat white = saltPepperNoise > 255;

    cv::Mat withSalt = img.clone();
    withSalt.setTo(255, white);
    withSalt.setTo(0, black);
    cv::imshow("with salt", withSalt);

    cv::Mat median;
    cv::medianBlur(withSalt, median, 3);

    cv::imshow("median 3", median);

    cv::medianBlur(withSalt, median, 5);
    cv::imshow("median 5", median);

    cv::medianBlur(withSalt, median, 7);
    cv::imshow("median 7", median);


    cv::waitKey(0);

    return 0;
}