#include "video_list_model.h"
#include "../../Backend/thumbnail_creator.h"
#include <QDebug>

VideoListModel::VideoListModel(QObject *parent) : QAbstractListModel(parent) {
  qDebug() << "VideoListModel constructor";
  PopulateVideoElementsList();
}

void VideoListModel::PopulateVideoElementsList() {
  qDebug() << "Populating VideoElementList";
  const auto video_file_path = path_creator::VideoFolder();

  for (const auto &video_file : fs::directory_iterator(video_file_path)) {
    VideoElementInformation video_element_information;
    video_element_information.video_file_name = video_file.path().stem().c_str();
    video_element_information.project_root_path = path_creator::ProjectRoot().c_str();

    thumbnail_creator::VideoThumbnail(video_file.path());

    qDebug() << "Video file name: " << video_element_information.video_file_name;
    qDebug() << "Project root path: " << video_element_information.project_root_path;

    video_element_information_.append(std::move(video_element_information));
  }
}

QHash<int, QByteArray> VideoListModel::roleNames() const {
  QHash<int, QByteArray> roles;
  roles[kVideoFileName] = "videoName";
  roles[kProjectRootPath] = "projectRootPath";
  return roles;
}

QVariant VideoListModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid()) {
    return QVariant();
  }

  const auto video_element = video_element_information_.at(index.row());

  switch (role) {
  case VideoElementRoles::kVideoFileName:
    return {video_element.video_file_name};

  case VideoElementRoles::kProjectRootPath:
    return {video_element.project_root_path};

  default:
    return QVariant();
  }
}

int VideoListModel::rowCount(const QModelIndex &parent) const {
  return (parent.isValid() || video_element_information_.empty())
             ? EXIT_FAILURE
             : video_element_information_.size();
}

QVector<VideoElementInformation> VideoListModel::GetVideoElementInformation() const {
  return video_element_information_;
}
