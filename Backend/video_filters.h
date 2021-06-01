#ifndef QTVIDEOEDITOR_BACKEND_VIDEO_FILTERS_H_
#define QTVIDEOEDITOR_BACKEND_VIDEO_FILTERS_H_

#include <QObject>
#include <experimental/filesystem>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <string>

namespace fs = std::experimental::filesystem;

class VideoFilters : public QObject {

  Q_OBJECT
  Q_PROPERTY(QString Blur READ GetBlurredVideoFilePath WRITE ApplyBlur NOTIFY blurVideoFilterApplied)
  Q_PROPERTY(QString Gradient READ GetGradientVideoFilePath WRITE ApplyGradient NOTIFY gradientVideoFilterApplied)
public:
  explicit VideoFilters(QObject *parent = nullptr);

signals:
  void blurVideoFilterApplied();
  void gradientVideoFilterApplied();

public slots:
  void ApplyBlur(const QString &video_file_path);
  QString GetBlurredVideoFilePath() const;

  void ApplyGradient(const QString &video_file_path);
  QString GetGradientVideoFilePath() const;

private:
  void Initialize(const fs::path &video_file_path);

  cv::VideoCapture video_capture_{};
  cv::VideoWriter video_output_{};
  cv::Mat source_video_frame_{};
  cv::Mat edited_video_frame_{};

  cv::Size2d frame_size_{0.0, 0.0};
  QString source_video_file_path_{};
  QString edited_video_file_path_{};
  QString gradient_video_file_path_{};
  QString blurred_video_file_path_{};
  double fps_{30.0};
  int mp4_codec_{0};
};

#endif // QTVIDEOEDITOR_BACKEND_VIDEO_FILTERS_H_
