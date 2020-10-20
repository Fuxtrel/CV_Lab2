#ifndef CV_LAB2_THRESHOLD_FILTER_H
#define CV_LAB2_THRESHOLD_FILTER_H

#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/imgcodecs.hpp>
#include <string>
#include <vector>

using namespace std;
using namespace cv;

class BinaryThreshold
{

public:
    BinaryThreshold() = default;

    ~BinaryThreshold() = default;

    void read(string path);

    void print(size_t index, string &flow);


    size_t size();

    Mat getImage(size_t index);

    enum FilterTypes
    {
        BINARY_FILTER,
        BINARY_FILTER_INV
    };

    BinaryThreshold(BinaryThreshold &base, FilterTypes filterName);

    Mat applyFilterToImage(size_t index, FilterTypes filterName);


private:
    Mat applyBinaryFilterToImg(size_t index, int threshold, int maxValue, string &filterName);

    vector<Mat> image;

};

#endif //CV_LAB2_THRESHOLD_FILTER_H
