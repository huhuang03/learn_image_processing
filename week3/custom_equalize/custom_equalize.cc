//
// Created by hwf on 2021/11/3.
//

#include "custom_equalize.h"
#include <map>

void custom_equalize(cv::InputArray in, cv::OutputArray out) {
    std::map<int, int> count;
    for (unsigned char gray: cv::Mat_<unsigned char>(in.getMat())) {
        std::cout << (int)gray << " ";
    }
}
