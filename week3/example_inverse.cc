#include <opencv2/opencv.hpp>

void showHistogram(std::string const &name, cv::Mat1b const&img) {
    int bins = 256;
    int histSize[] = {bins};
    float lrangs[] = {0, 256};
    const float *ranges[] = {lrangs};

    cv::Mat hist;
    int channels = {0};
    int const hist_height = 256;
    cv::Mat3b hist_imge = cv::Mat3b::zeros(hist_height, bins);

    cv::calcHist(&img, 1, &channels, cv::Mat(), hist, 1, histSize, ranges);

    double maxVal = 0;
    cv::minMaxLoc(hist, 0, &maxVal);

    for (int b = 0; b < bins; b++) {
        float const binVal = hist.at<float>(b);
        int const height = cvRound(binVal * hist_height / maxVal);
        cv::line(hist_imge,
                 cv::Point(b, hist_height - height),
                 cv::Point(b, hist_height),
                 cv::Scalar::all(255));
    }
    cv::imshow(name, hist_imge);
}

int main() {
    cv::Mat1b img = cv::imread("../imgs/lena.jpg", cv::IMREAD_GRAYSCALE);
    cv::imshow("origin", img);

    showHistogram("origin hist", img);

//    cv::Mat histImg;
//    cv::equalizeHist(img, histImg);
//    cv::imshow("origin_hist", histImg);

    cv::Mat inverse = 255 - img;
    cv::imshow("inverse", inverse);
    showHistogram("inverse_hist", inverse);

//    cv::Mat histInverse;
//    cv::equalizeHist(inverse, histInverse);
//    cv::imshow("inverse_hist", histInverse);

    cv::waitKey(0);
    return 0;
}