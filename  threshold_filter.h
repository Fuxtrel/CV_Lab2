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
    BinaryThreshold();
    ~BinaryThreshold();
    void useFilter();

private:
    const string m_filter1;
    const string m_filter2;
    vector<string> imgName;
    vector<Mat> image;
    vector<Mat> copy_image;

    void applyFilterToImg(Mat &img, int threshold, int maxValue, string filterName);


};

#endif //CV_LAB2_THRESHOLD_FILTER_H
