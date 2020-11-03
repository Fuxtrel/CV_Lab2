#include " threshold_filter.h"
#include <exception>

//бинарный фильтр
void BinaryThreshold::applyBinaryFilterToImg(Mat imageBase, int threshold, int maxValue, string &filterName)
{
    int minValue;
    if (filterName == "B")
    {
        minValue = 0;
    } else if (filterName == "BI")
    {
        minValue = maxValue;
        maxValue = 0;
    }
    for (int i = 0; i < imageBase.rows; i++)
    {
        for (int j = 0; j < imageBase.cols; j++)
        {
            switch (imageBase.channels())
            {
                case 3 :
                    if ((imageBase.at<Vec3b>(i, j)[0] <= threshold) || (imageBase.at<Vec3b>(i, j)[1] <= threshold) ||
                        (imageBase.at<Vec3b>(i, j)[2] <= threshold))
                    {
                        imageBase.at<Vec3b>(i, j)[0] = minValue;
                        imageBase.at<Vec3b>(i, j)[1] = minValue;
                        imageBase.at<Vec3b>(i, j)[2] = minValue;
                    } else
                    {
                        imageBase.at<Vec3b>(i, j)[0] = maxValue;
                        imageBase.at<Vec3b>(i, j)[1] = maxValue;
                        imageBase.at<Vec3b>(i, j)[2] = maxValue;
                    }
                    break;
                case 2:
                    if ((imageBase.at<Vec2b>(i, j)[0] <= threshold) || (imageBase.at<Vec2b>(i, j)[1] <= threshold))
                    {
                        imageBase.at<Vec2b>(i, j)[0] = minValue;
                        imageBase.at<Vec2b>(i, j)[1] = minValue;

                    } else
                    {
                        imageBase.at<Vec2b>(i, j)[0] = maxValue;
                        imageBase.at<Vec2b>(i, j)[1] = maxValue;
                    }
                    break;
                case 1:
                    if ((imageBase.at<uint8_t>(i, j) <= threshold))
                    {
                        imageBase.at<uint8_t>(i, j) = minValue;

                    } else
                    {
                        imageBase.at<uint8_t>(i, j) = maxValue;
                    }
                    break;
            }
        }
    }
}

//Считываем данные в вектора
void BinaryThreshold::read(string path)
{
    vector<string> imgName;
    glob(path, imgName);
    for (size_t i = 0; i < imgName.size(); i++)
    {
        image.push_back(imread(imgName[i]));
    }
}

//Выод на экран
void BinaryThreshold::print(size_t imgNumber, const string &name)
{
    imshow(name, image[imgNumber]);
    while (waitKey(1) != 'c');
}

//Копия изображений для применения фильтров
BinaryThreshold::BinaryThreshold(BinaryThreshold &baseImagesSets)
{
    for (size_t i = 0; i < baseImagesSets.image.size(); i++)
    {
        image.push_back(baseImagesSets.image[i].clone());
    }
}

Mat BinaryThreshold::getImage(size_t index)
{
    return image[index];
}

void BinaryThreshold::applyFilterToImage(size_t index, FilterTypes filterName)
{
    switch (filterName)
    {
        case BINARY_FILTER:
        {
            int threshold = 125;
            int maxValue = 255;
            string filter = "B";
            return applyBinaryFilterToImg(image[index], threshold, maxValue, filter);
        }
        case BINARY_FILTER_INV:
        {
            int threshold = 125;
            int maxValue = 255;
            string filter = "BI";
            return applyBinaryFilterToImg(image[index], threshold, maxValue, filter);
        }
    }
}

int BinaryThreshold::getDifference(Mat &original, size_t index)
{
    uint differenceCounter = 0;
    for (int i = 0; i < image[index].rows; i++)
    {
        for (int j = 0; j < image[index].cols; j++)
        {
            if ((abs(image[index].at<uint8_t>(i,j) - original.at<uint8_t>(i,j))) != 0)
            {
                differenceCounter++;
            }
        }
    }
    return (double)differenceCounter / (image[index].rows * image[index].cols);
}




