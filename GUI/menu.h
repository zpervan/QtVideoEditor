#ifndef QTVIDEOEDITOR_GUI_MENU_H_
#define QTVIDEOEDITOR_GUI_MENU_H_

#include <QObject>
#include <QStringList>

/// @brief Contains all the menu related logic
class Menu : public QObject {
  Q_OBJECT
  Q_PROPERTY(QStringList VideoTypeLabels READ GetVideoTypeLabels WRITE SetVideoTypeLabels NOTIFY comboListChanged)
  Q_PROPERTY(int CurrentIndex READ GetCurrentIndex WRITE SetCurrentIndex NOTIFY currentIndexChanged)

public:
  explicit Menu(QObject *parent = nullptr);

private:
  QStringList video_type_labels_;
  int current_index_;

signals:
  void comboListChanged();
  void currentIndexChanged();

public slots:
  QStringList GetVideoTypeLabels() const;
  void SetVideoTypeLabels(QStringList &labels);

  int GetCurrentIndex() const;
  void SetCurrentIndex(int current_index);
};

#endif // QTVIDEOEDITOR_GUI_MENU_H_
