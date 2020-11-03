#include " threshold_filter.h"
#include <ctime>

int main()
{
    string folderPath = "/home/alex/CLionProjects/CV_Lab2/Images/*.jpeg";
    const string before = "reference sample";
    const string after = "filtered sample";

    BinaryThreshold referenceSample;
    referenceSample.read(folderPath);

    BinaryThreshold workImages_ThrBin(referenceSample);
    BinaryThreshold workImages_ThrBinInv(referenceSample);


    uint32_t startTime = clock();

    //referenceSample.print(0, before);

    workImages_ThrBin.applyFilterToImage(0, BinaryThreshold::BINARY_FILTER);
    //workImages_ThrBin.print(0, after);

    //workImages_ThrBinInv.applyFilterToImage(0, BinaryThreshold::BINARY_FILTER_INV);
    //workImages_ThrBinInv.print(0, after);

    uint32_t endTime = clock();
    cout << double(endTime - startTime) / CLOCKS_PER_SEC << endl;

    uint32_t startTime1 = clock();

    Mat show;
    cv::threshold(referenceSample.getImage(0), show, 125, 255, THRESH_BINARY);
    //imshow("WINDOW", show);

    uint32_t endTime1 = clock();
    cout << double(endTime1 - startTime1) / CLOCKS_PER_SEC << endl;

    std::cout << "Difference " << workImages_ThrBin.getDifference(show, 0);
}
