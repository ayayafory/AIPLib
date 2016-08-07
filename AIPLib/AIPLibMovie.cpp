#include "AIPLibCommon.h"
#include "AIPLibMovie.h"

int AiplCreateMovieThumbnail(const std::string& dir_name, const std::string& file_name, cv::Mat& frame) {

	std::string mp4_name = dir_name + "/" + file_name;
	cv::VideoCapture cap(mp4_name);
	cap >> frame;

	cap.release();
	return 0;
}