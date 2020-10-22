#include " threshold_filter.h"
#include <ctime>

int main()
{
    string folderPath = "/home/alex/CLionProjects/CV_Lab2/Images/*.jpg";
    const string before = "reference sample";
    const string after = "filtered sample";

    BinaryThreshold referenceSample;
    referenceSample.read(folderPath);

    BinaryThreshold workImages_ThrBin(referenceSample);
    BinaryThreshold workImages_ThrBinInv(referenceSample);


    uint32_t startTime = clock();
    for (size_t i = 0; i < referenceSample.getSize(); i++)
    {
        referenceSample.print(i, before);

        workImages_ThrBin.applyFilterToImage(i, BinaryThreshold::BINARY_FILTER);
        workImages_ThrBin.print(i, after);

        workImages_ThrBinInv.applyFilterToImage(i, BinaryThreshold::BINARY_FILTER_INV);
        workImages_ThrBinInv.print(i, after);
    }
    uint32_t endTime = clock();
    cout << double(endTime - startTime) / CLOCKS_PER_SEC << endl;
    startTime = clock();
    for(size_t i = 0; i < referenceSample.getSize(); i++){
        Mat show;
        cv::threshold(referenceSample.getImage(i), show, 125, 255, THRESH_BINARY);
        imshow("WINDOW", show);
    }
    endTime = clock();
    cout << double(endTime - startTime) / CLOCKS_PER_SEC;
}
