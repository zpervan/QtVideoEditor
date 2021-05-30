#ifndef QTVIDEOEDITOR_GUI_CODE_VIDEO_LIST_MODEL_H_
#define QTVIDEOEDITOR_GUI_CODE_VIDEO_LIST_MODEL_H_

#include <QAbstractListModel>
#include <QUrl>

struct VideoElementInformation {
  QString video_file_name;
  QString thumbnail_file_path;
};

class VideoListModel : public QAbstractListModel {
  Q_OBJECT
  Q_PROPERTY(QVector<VideoElementInformation> VideoListModel READ
                 GetVideoElementInformation CONSTANT)
public:
  enum VideoElementRoles {
    kVideoFileName = Qt::UserRole + 1,
    kThumbnailFilePath
  };

  explicit VideoListModel(QObject *parent = nullptr);

  int rowCount(const QModelIndex &parent = QModelIndex()) const override;

  QHash<int, QByteArray> roleNames() const override;

private:
  void PopulateVideoElementsList();
  QVector<VideoElementInformation> video_element_information_;

public slots:
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;
  QVector<VideoElementInformation> GetVideoElementInformation() const;
};

#endif // QTVIDEOEDITOR_GUI_CODE_VIDEO_LIST_MODEL_H_
