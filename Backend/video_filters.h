#ifndef QTVIDEOEDITOR_BACKEND_VIDEO_FILTERS_H_
#define QTVIDEOEDITOR_BACKEND_VIDEO_FILTERS_H_

#include <QObject>
#include <experimental/filesystem>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

namespace fs = std::experimental::filesystem;

/// @brief Contains all the video filtering logic
class VideoFilters : public QObject {

  Q_OBJECT

public:
  explicit VideoFilters(QObject *parent = nullptr);

  /// @brief Apply a blur filter on the processed video
  /// @param video_file_path Path to the video file which should be processed
  Q_INVOKABLE void ApplyBlur(const QString &video_file_path);

  /// @brief Apply a morphological transformation filter on the processed video
  /// @param video_file_path Path to the video file which should be processed
  Q_INVOKABLE void
  ApplyMorphologicalTransformation(const QString &video_file_path);

signals:
  void blurVideoFilterApplied();
  void morphologicalVideoFilterApplied();

private:
  void Initialize(const fs::path &video_file_path);

  cv::VideoCapture video_capture_{};
  cv::VideoWriter video_output_{};
  cv::Mat source_video_frame_{};
  cv::Mat edited_video_frame_{};

  cv::Size2d frame_size_{0.0, 0.0};
  QString source_video_file_path_{};
  QString edited_video_file_path_{};
  double fps_{30.0};
  int mp4_codec_{0};
};

#endif // QTVIDEOEDITOR_BACKEND_VIDEO_FILTERS_H_
