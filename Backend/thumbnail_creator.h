#ifndef QTVIDEOEDITOR_BACKEND_THUMBNAIL_CREATOR_H_
#define QTVIDEOEDITOR_BACKEND_THUMBNAIL_CREATOR_H_

#include "utility.h"
#include <fmt/format.h>
#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
#include <string>
#include <cassert>

namespace thumbnail_creator {

void CreateThumbnailFromVideo(const fs::path &file_path) {
  assert(fs::exists(file_path) && fmt::format("Path does not exist: {} ", file_path.c_str()).c_str());

  /// @TODO: Refactor this a little bit...
  cv::Mat frame;
  cv::VideoCapture capture{file_path};
  capture.read(frame);

  if (!frame.empty()) {
    const std::string picture_name{utility::path::CreateAssetsPictureFolder() += file_path.stem() += ".jpg"};
    cv::imwrite(picture_name, frame);
  }
}

} // namespace thumbnail_creator

#endif // QTVIDEOEDITOR_BACKEND_THUMBNAIL_CREATOR_H_
