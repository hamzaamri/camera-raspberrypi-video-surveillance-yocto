#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    std::string rtsp_url = "rtsp://your_camera_ip/stream"; 

    cv::VideoCapture cap(rtsp_url, cv::CAP_GSTREAMER);
    if (!cap.isOpened()) {
        std::cerr << "Error: Cannot open RTSP stream!" << std::endl;
        return -1;
    }

    cv::Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        cv::imshow("RTSP Stream", frame);
        if (cv::waitKey(30) == 27) break; // Exit on 'Esc'
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}
