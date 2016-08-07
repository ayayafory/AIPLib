#include "AIPLib.hpp"

int main(void) {

	HANDLE hFind;
	WIN32_FIND_DATA win32fd;//defined at Windwos.h
	std::vector<std::string> file_names;
	std::string dir_name = "movie";
	cv::Mat frame;

	//ägí£éqÇÃê›íË
	std::string search_name = dir_name + "\\*." + "mp4";

	hFind = FindFirstFile(search_name.c_str(), &win32fd);

	if (hFind == INVALID_HANDLE_VALUE) {
		throw std::runtime_error("file not found");
	}

	do {
		if (win32fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
		}
		else {
			file_names.push_back(win32fd.cFileName);
			printf("%s\n", file_names.back().c_str());
			AiplCreateMovieThumbnail(dir_name, win32fd.cFileName, frame);
			std::string img_name = dir_name + "/" + win32fd.cFileName + ".jpg";
			cv::imwrite(img_name, frame);
		}
	} while (FindNextFile(hFind, &win32fd));

	FindClose(hFind);
	frame.release();
	getchar();
	return 0;

}

