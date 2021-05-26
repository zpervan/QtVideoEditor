#ifndef QTVIDEOEDITOR_GUI_MENU_H_
#define QTVIDEOEDITOR_GUI_MENU_H_

#include <QObject>

class Menu : public QObject {
  Q_OBJECT
public:
  explicit Menu(QObject *parent = nullptr);
};

#endif // QTVIDEOEDITOR_GUI_MENU_H_
