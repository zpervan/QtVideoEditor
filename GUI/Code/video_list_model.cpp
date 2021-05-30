#include "video_list_model.h"
#include "../../Backend/thumbnail_creator.h"
#include <QDebug>

VideoListModel::VideoListModel(QObject *parent) : QAbstractListModel(parent) {
  qDebug() << "VideoListModel constructor";
  PopulateVideoElementsList();
}

void VideoListModel::PopulateVideoElementsList() {
  qDebug() << "Populating VideoElementList";
  const auto video_file_path = utility::path::CreateAssetsVideoFolder();

  for (const auto &video_file : fs::directory_iterator(video_file_path)) {
    VideoElementInformation video_element_information;
    video_element_information.video_file_name = video_file.path().stem().c_str();
    video_element_information.thumbnail_file_path = thumbnail_creator::CreateThumbnailFromVideo(video_file.path());

    qDebug() << "Video file name: "
             << video_element_information.video_file_name;
    qDebug() << "Thumbnail file name: "
             << video_element_information.thumbnail_file_path;

    video_element_information_.append(std::move(video_element_information));
  }
}

QHash<int, QByteArray> VideoListModel::roleNames() const {
  QHash<int, QByteArray> roles;
  roles[kVideoFileName] = "name";
  roles[kThumbnailFilePath] = "thumbnailPath";
  return roles;
}

QVariant VideoListModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid()) {
    return QVariant();
  }

  auto video_element = video_element_information_.at(index.row());
  auto video_element_role = static_cast<VideoElementRoles>(role);

  if (video_element_role == VideoElementRoles::kVideoFileName) {
    return video_element.video_file_name;
  }

  if (video_element_role == VideoElementRoles::kThumbnailFilePath) {
    return video_element.thumbnail_file_path;
  }

  return QVariant();
}

int VideoListModel::rowCount(const QModelIndex &parent) const {
  if (parent.isValid() || video_element_information_.empty()) {
    return EXIT_FAILURE;
  }

  return video_element_information_.size();
}

QVector<VideoElementInformation>
VideoListModel::GetVideoElementInformation() const {
  return video_element_information_;
}
