#include "video_filters.h"
#include "path_creator.h"
#include <QDebug>
#include <cassert>
#include <fmt/format.h>

VideoFilters::VideoFilters(QObject *parent) : QObject(parent) {}

void VideoFilters::ApplyBlur(const QString &video_file_path) {
  qDebug() << "[BLUR] Applying filter";
  Initialize(video_file_path.toStdString());

  if (!edited_video_file_path_.contains("edited")) {
    qDebug() << "[BLUR] Edited file does not exist";
    edited_video_file_path_ += "_edited.mp4";
  }

  video_output_.open(edited_video_file_path_.toStdString(), mp4_codec_, fps_,frame_size_);

  const cv::Size2i kernel = {15, 15};
  const int sigma = 0;

  while (true) {
    if (!video_capture_.read(source_video_frame_)) {
      break;
    }
    cv::GaussianBlur(source_video_frame_, edited_video_frame_, kernel, sigma);
    video_output_.write(edited_video_frame_);
  }

  video_capture_.release();
  video_output_.release();
  emit blurVideoFilterApplied();
}

void VideoFilters::ApplyMorphologicalTransformation(const QString &video_file_path) {
  qDebug() << "[MORPH] Applying filter";
  Initialize(video_file_path.toStdString());

  if (!edited_video_file_path_.contains("edited")) {
    qDebug() << "[MORPH] Edited file does not exist";
    edited_video_file_path_ += "_edited.mp4";
  }

  video_output_.open(edited_video_file_path_.toStdString(), mp4_codec_, fps_,frame_size_);

  const int morph_size = 2;
  cv::Mat element = getStructuringElement(
      cv::MORPH_RECT, cv::Size(2 * morph_size + 1, 2 * morph_size + 1),
      cv::Point(morph_size, morph_size));

  while (true) {
    if (!video_capture_.read(source_video_frame_)) {
      break;
    }
    morphologyEx(source_video_frame_, edited_video_frame_, cv::MORPH_GRADIENT,
                 element, cv::Point(-1, -1), 1);
    video_output_.write(edited_video_frame_);
  }

  video_capture_.release();
  video_output_.release();
  emit morphologicalVideoFilterApplied();
}

void VideoFilters::Initialize(const fs::path &video_file_path) {
  qDebug() << "Initializing video filter functionality...";
  assert( fs::exists(video_file_path) && fmt::format("Path does not exist: {} ", video_file_path.c_str()).c_str());

  source_video_file_path_ = video_file_path.c_str();
  edited_video_file_path_ = (path_creator::VideoFolder().string() + video_file_path.stem().string()).c_str();
  mp4_codec_ = cv::VideoWriter::fourcc('m', 'p', '4', 'v');
  video_capture_.open(source_video_file_path_.toStdString());
  frame_size_.width = video_capture_.get(cv::CAP_PROP_FRAME_WIDTH);
  frame_size_.height = video_capture_.get(cv::CAP_PROP_FRAME_HEIGHT);
}
