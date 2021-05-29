#include "menu.h"
#include <QDebug>

Menu::Menu(QObject *parent)
    : QObject(parent),
      video_type_labels_({"RAW", "EDITED"}),
      current_index_(0) {}

QStringList Menu::GetVideoTypeLabels() const{
  qDebug() << "GetVideoTypeLabels is called";
  return video_type_labels_;
}

void Menu::SetVideoTypeLabels(QStringList &labels) {
  qDebug() << "SetVideoTypeLabels is called";
  video_type_labels_ = std::move(labels);
  emit comboListChanged();
}

int Menu::GetCurrentIndex() const {
  qDebug() << "GetCurrentIndex is called";
  return current_index_;
}

void Menu::SetCurrentIndex(int current_index) {
  qDebug() << "SetCurrentIndex is called";
  current_index_ = current_index;
  emit currentIndexChanged();
}
