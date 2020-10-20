#include " threshold_filter.h"

//бинарный фильтр
Mat BinaryThreshold::applyBinaryFilterToImg(size_t index, int threshold, int maxValue, string &filterName)
{
    Mat img = image[index].clone();
    string m_filter1 = "B";
    string m_filter2 = "BI";
    int minValue;
    if (filterName == m_filter1)
    {
        minValue = 0;
    } else if (filterName == m_filter2)
    {
        minValue = maxValue;
        maxValue = 0;
    } else exit(0);

    for (int i = 0; i < img.rows; i++)
    {
        for (int j = 0; j < img.cols; j++)
        {
            if ((img.at<uint8_t>(i, j) <= threshold) && (img.at<uint8_t>(i, j) <= threshold) &&
                (img.at<uint8_t>(i, j) <= threshold))
            {
                img.at<uint8_t>(i, j) = minValue;
                img.at<uint8_t>(i, j) = minValue;
                img.at<uint8_t>(i, j) = minValue;
            } else
            {
                img.at<uint8_t>(i, j) = maxValue;
                img.at<uint8_t>(i, j) = maxValue;
                img.at<uint8_t>(i, j) = maxValue;
            }

        }
    }
    return img;
}

void BinaryThreshold::read(string path)
{
    vector<string> imgName;
    glob(path, imgName);
    for (int i = 0; i < imgName.size(); i++)
    {
        image.push_back(imread(imgName[i], ImreadModes::IMREAD_GRAYSCALE));
    }
}

void BinaryThreshold::print(size_t index, string &flow)
{
    imshow("img1", image[index]);
   // while (waitKey(1) != 'c');
}

size_t BinaryThreshold::size()
{
    return image.size();
}

BinaryThreshold::BinaryThreshold(BinaryThreshold &base, FilterTypes filterName)
{
    for (size_t i = 0; i < base.size(); i++)
    {
        image.push_back(std::move(base.applyFilterToImage(i, filterName)));
    }
}

Mat BinaryThreshold::getImage(size_t index)
{
    return image[index];
}

Mat BinaryThreshold::applyFilterToImage(size_t index, FilterTypes filterName)
{
    switch (filterName)
    {
        case BINARY_FILTER:
        {
            int threshold = 125;
            int maxValue = 255;
            string filter = "B";
            return applyBinaryFilterToImg(index, threshold, maxValue, filter);
        }
        case BINARY_FILTER_INV:
        {
            int threshold = 125;
            int maxValue = 255;
            string filter = "BI";
            return applyBinaryFilterToImg(index, threshold, maxValue, filter);
        }
    }
}


