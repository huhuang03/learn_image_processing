//
// Created by huhua on 2021/10/17.
//

#include <opencv2/opencv.hpp>
#include <math.h>

static void affineTransformation(cv::InputArray src, cv::OutputArray dst, int a11, int a12, int a21, int a22) {

}


// https://en.wikipedia.org/wiki/Affine_transformation#Image_transformation wiki show that rotate is anti clock, same as
// I though, so I don't verify for now.
static void rotate(cv::InputArray src, cv::OutputArray dst, double radian) {
//    affineTransformation(src, dst, cos(radian), )
}


