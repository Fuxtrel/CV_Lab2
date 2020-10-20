#include " threshold_filter.h"
#include <ctime>

int main()
{

    string before = "image before";
    string after1 = "image after1";
    string after2 = "image after2";
    BinaryThreshold thr;
    string folderPath = "/home/alex/CLionProjects/CV_Lab2/Images/*.jpg";
    thr.read(folderPath);
    BinaryThreshold filteredThr(thr, BinaryThreshold::BINARY_FILTER);
    BinaryThreshold filteredThrInv(thr, BinaryThreshold::BINARY_FILTER_INV);
    uint32_t startTime = clock();
    for (size_t i = 0; i < thr.size(); i++)
    {
       //thr.print(i, before);
        filteredThr.print(i, after1);
        //filteredThrInv.print(i, after2);
    }
    uint32_t endTime = clock();
    cout << double(endTime - startTime) / CLOCKS_PER_SEC << endl;
    startTime = clock();
    for(size_t i = 0; i < thr.size(); i++){
        Mat show;
        cv::threshold(thr.getImage(i), show, 125, 255, THRESH_BINARY);
        imshow("WINDOW", show);
    }
    endTime = clock();
    cout << double(endTime - startTime) / CLOCKS_PER_SEC;
}
