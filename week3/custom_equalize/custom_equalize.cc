//
// Created by hwf on 2021/11/3.
//

#include "custom_equalize.h"
#include <map>

void custom_equalize(cv::InputArray in, cv::InputOutputArray out) {
    std::map<int, int> count;
    for (unsigned char gray: cv::Mat_<unsigned char>(in.getMat())) {
        count[gray] += 1;
    }

    // ok, now count.
    int sum = 0;
    for (int i = 0; i < 256; i++) {
        sum += count[i];
        count[i] = sum;
    }

    cv::Mat mat1;
    // 16 unsigned is ok for me
//    mat1.create(in.size(), CV_32S);
    mat1.create(in.size(), CV_32S);

   // now, fill the out
   for (int r = 0; r < in.rows(); r++) {
       for (int c = 0; c < in.cols(); c++) {
           mat1.at<int>(r, c) = count[in.getMat().at<unsigned char>(r, c)];
       }
   }

    // ok, now create the new output.
   out.create(in.size(), in.type());
   // ok can we normalized to cv::8U?
   cv::normalize(mat1, out, 0, 256, cv::NORM_MINMAX, CV_8U);
}
