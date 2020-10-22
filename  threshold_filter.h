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

    void print(size_t imgNumber, const string &name);

    Mat getImage(size_t index);

    enum FilterTypes
    {
        BINARY_FILTER,
        BINARY_FILTER_INV
    };

    int getSize();

    BinaryThreshold(BinaryThreshold &base);

    void applyFilterToImage(size_t index, FilterTypes filterName);


private:
    void applyBinaryFilterToImg(Mat imageBase, int threshold, int maxValue, string &filterName);

    vector<Mat> image;

};

#endif //CV_LAB2_THRESHOLD_FILTER_H
