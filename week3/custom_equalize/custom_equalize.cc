//
// Created by hwf on 2021/11/3.
//

#include "custom_equalize.h"
#include <map>

void custom_equalize(cv::InputArray in, cv::OutputArray out) {
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

    // ok, now create the new output.
    out.create(in.size(), in.type());

   // now, fill the out
   for (int r = 0; r < in.rows(); r++) {
       for (int c = 0; c < in.cols(); c++) {
           out.getMatRef().at<unsigned char>(r, c) = count[in.getMat().at<unsigned char>(r, c)];
       }
   }

   cv::Mat normalized;
   // now normalize to 256
   cv::normalize(out, normalized, 0.0, 256.0);
   normalized.assignTo(out);
}
