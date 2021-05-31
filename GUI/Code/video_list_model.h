#ifndef QTVIDEOEDITOR_GUI_CODE_VIDEO_LIST_MODEL_H_
#define QTVIDEOEDITOR_GUI_CODE_VIDEO_LIST_MODEL_H_

#include <QAbstractListModel>
#include <QUrl>

/// @brief Data container for storing information of a single video file
struct VideoElementInformation {
  QString video_file_name;
  QString project_root_path;
};

/// @brief Contains all necessary logic to fetch the populated video list.
class VideoListModel : public QAbstractListModel {
  Q_OBJECT
  Q_PROPERTY(QVector<VideoElementInformation> VideoListModel READ GetVideoElementInformation CONSTANT)

public:
  explicit VideoListModel(QObject *parent = nullptr);

  /// @brief Data roles for video element information
  enum VideoElementRoles {
    kVideoFileName = Qt::UserRole + 1,
    kProjectRootPath
  };

public slots:
  /// @brief Returns the specific role data from the video list element.
  /// @param [in] index Position of the video element in the populated list
  /// @param [in] role Data role
  /// @return Information of a data role from a specific video list element
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

  /// @brief Gets the list of video element information
  /// @return List of video element information
  QVector<VideoElementInformation> GetVideoElementInformation() const;

private:
  void PopulateVideoElementsList();
  QVector<VideoElementInformation> video_element_information_;
  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  QHash<int, QByteArray> roleNames() const override;
};

#endif // QTVIDEOEDITOR_GUI_CODE_VIDEO_LIST_MODEL_H_
