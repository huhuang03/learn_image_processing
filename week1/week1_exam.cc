//
// Created by huhua on 2021/10/18.
//

#include <iostream>
#include <opencv2/opencv.hpp>

// Write  a computer program capable of reducing the number of intensity levels in an image from 256 to 2,
// in integer powers of 2. The desired number of  intensity levels needs to be a variable input to your program.

// For simple, I only process the max value when intensity levles. is 2.
// how to specify that image is gray image?
static void exam1(cv::InputArray src, cv::OutputArray out) {
    out.create(src.size(), src.type());

    std::cout << "Please input the number or intensity: ";
    int intensity;
    std::cin >> intensity;
    std::cout << "intensity: " << intensity << std::endl;

    int scale = 256 / intensity;
    for (int i = 0; i < src.total(); i++) {
        ((unsigned char*)out.getMat().data)[i] = src.getMat().data[i] / scale * scale;
    }
}

static int adjustPos(int origin, int max) {
    if (origin < 0) {
        return 0;
    }
    if (origin >= max) {
        return max - 1;
    }
    return origin;
}

/**
 * @param size is the one side size. for example, 1 means 3x3, 2 means 5x5
 */
static void applyOneKernel(cv::InputArray src, cv::OutputArray dst, int size) {
    dst.create(src.size(), src.type());

    auto srcMat = src.getMat();
    auto outMat = dst.getMat();
    for (int r = 0; r < src.size().height; r++) {
        for (int c = 0; c < src.size().width; c++) {
            cv::Vec3i item(0, 0, 0);
            for (int dr = -size; dr < size; dr++) {
                for (int dc = -size; dc < size; dc++) {
                    auto row = r + dr;
                    auto col = c + dc;
                    row = adjustPos(row, src.size().height);
                    col = adjustPos(col, src.size().width);
                    item += srcMat.at<cv::Vec3b>(row, col);
                }
            }
            item /= ((1 + size * 2) * (1 + size * 2));
            dst.getMatRef().at<cv::Vec3b>(r, c) = item;
        }
    }
}

//
// Using any programming language you feel comfortable with (it is though  recommended to use the provided free Matlab),
// load an image and then perform a simple spatial 3x3 average of image pixels. In other words,
// replace the value of every pixel by the average of the values in its 3x3  neighborhood.
// If the pixel is located at (0,0),
// this means averaging  the values of the pixels at the positions (-1,1), (0,1), (1,1), (-1,0),  (0,0), (1,0), (-1,-1), (0,-1),
// and (1,-1). Be careful with pixels at the  image boundaries.
// Repeat the process for a 10x10 neighborhood and again for a 20x20 neighborhood.
// Observe what happens to the image (we will  discuss this in more details in the very near future, about week 3).
//
void exam2(cv::InputArray src) {
    cv::Mat out;
    cv::imshow("src", src);
    applyOneKernel(src, out, 3);
    cv::imshow("3x3", out);

    applyOneKernel(src, out, 5);
    cv::imshow("11x11", out);

    applyOneKernel(src, out, 10);
    cv::imshow("21x21", out);
    cv::waitKey(0);
}



//Rotate the image by 45 and 90 degrees (Matlab provides simple command lines for doing this).
// I will use command line
void exam3(cv::InputArray src) {
    cv::Mat dst;

    cv::Point2f center(src.cols() / 2, src.rows() / 2);
    auto r = cv::getRotationMatrix2D(center, 45, 1.0);
    cv::warpAffine(src, dst, r, src.size());
    cv::imshow("rotate45", dst);

    r = cv::getRotationMatrix2D(center, 90, 1.0);
    cv::warpAffine(src, dst, r, src.size());
    cv::imshow("rotate90", dst);

    cv::waitKey(0);
}

//For  every 3×3 block of the image (without overlapping),
// replace  all corresponding 9 pixels by their average.
// This operation simulates  reducing the image spatial resolution.
// Repeat this for 5×5  blocks and 7×7 blocks.
// If you are using Matlab, investigate  simple command lines to do this important operation.
void exam4(cv::InputArray src) {
    // INTER_CUBIC look like the requirement. But it seems like take the weight.
    cv::Mat dst;
    cv::resize(src, dst, cv::Size(), 1 / 3.0, 1 / 3.0, cv::INTER_CUBIC);
    cv::imshow("1/3", dst);

    cv::resize(src, dst, cv::Size(), 1 / 5.0, 1 / 5.0, cv::INTER_CUBIC);
    cv::imshow("1/5", dst);

    cv::resize(src, dst, cv::Size(), 1 / 7.0, 1 / 7.0, cv::INTER_CUBIC);
    cv::imshow("1/7", dst);

    cv::waitKey(0);
}

int main() {
//    cv::Mat out;
//    cv::Mat img = cv::imread("../imgs/lena.jpg", cv::IMREAD_GRAYSCALE);
//    exam1(img, out);
//    cv::imshow("lena", out);
//    cv::waitKey(0);

    cv::Mat img = cv::imread("../imgs/lena.jpg");
//    exam2(img);
//    exam3(img);
    exam4(img);
}
