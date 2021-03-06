#ifndef QTVIDEOEDITOR_BACKEND_THUMBNAIL_CREATOR_H_
#define QTVIDEOEDITOR_BACKEND_THUMBNAIL_CREATOR_H_

#include "path_creator.h"
#include <QString>
#include <cassert>
#include <fmt/format.h>
#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
#include <string>

namespace thumbnail_creator {

/// @brief Creates a thumbnail picture in the assets folder from a video.
/// @param file_path Location of the video
static void VideoThumbnail(const fs::path &file_path) {
  assert(fs::exists(file_path) && fmt::format("Path does not exist: {} ", file_path.c_str()).c_str());

  /// @TODO: Refactor this a little bit...
  cv::Mat frame;
  cv::VideoCapture capture{file_path};
  capture.read(frame);

  if (!frame.empty()) {
    std::string picture_name{path_creator::ThumbnailsFolder() += file_path.stem() += ".jpg"};
    cv::imwrite(picture_name, frame);
  }
}

} // namespace thumbnail_creator

#endif // QTVIDEOEDITOR_BACKEND_THUMBNAIL_CREATOR_H_
