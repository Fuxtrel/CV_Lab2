#include " threshold_filter.h"

BinaryThreshold::BinaryThreshold() : m_filter1("B"),
                                     m_filter2("BI")
{
    string folderPath = "/home/alex/CLionProjects/CV_Lab2/Images/*.jpg";
    glob(folderPath, imgName);
    for (int i = 0; i < imgName.size(); i++)
    {
        image.push_back(imread(imgName[i], ImreadModes::IMREAD_GRAYSCALE));
        copy_image.push_back(image[i].clone());
    }

}

void BinaryThreshold::applyFilterToImg(Mat &img, int threshold, int maxValue, string filterName)
{
    int minValue;
    if (filterName == m_filter1)
    {
        minValue = 0;
    } else if (filterName == m_filter2)
    {
        minValue = maxValue;
        maxValue = 0;
    } else exit(0);
    for (Mat &img : copy_image)
    {
        for (int i = 0; i < img.rows; i++)
        {
            for (int j = 0; j < img.cols; j++)
            {
                if ((img.at<Vec3b>(i, j)[0] <= threshold) &&
                    (img.at<Vec3b>(i, j)[1] <= threshold) &&
                    (img.at<Vec3b>(i, j)[2] <= threshold))
                {
                    img.at<Vec3b>(i, j)[0] = minValue;
                    img.at<Vec3b>(i, j)[1] = minValue;
                    img.at<Vec3b>(i, j)[2] = minValue;
                } else
                {
                    img.at<Vec3b>(i, j)[0] = maxValue;
                    img.at<Vec3b>(i, j)[1] = maxValue;
                    img.at<Vec3b>(i, j)[2] = maxValue;
                }

            }
        }
    }
}

void BinaryThreshold::useFilter()
{
    int threshold;
    int maxValue;
    string filter;
    cin >> threshold >> maxValue >> filter;
    for (int i = 0; i < copy_image.size(); i++)
    {
        imshow("img1", image[i]);
        while (waitKey(1) != 'c');//close
        applyFilterToImg(copy_image[i], threshold, maxValue, filter);
        imshow("img", copy_image[i]);
        while (waitKey(1) != 'c');//close
    }
}

BinaryThreshold::~BinaryThreshold()
= default;
