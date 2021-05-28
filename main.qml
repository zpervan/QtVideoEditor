import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Dialogs.qml 1.0
import QtQuick.Controls 2.3
//import custom.widget.menu 1.0

Window {
    visible: true
    width: 1024
    height: 760
    color: "#c3c1c1"
    title: qsTr("Video Editor")

    ColumnLayout {
        id: column_mainmenu
        y: 0
        width: 258
        height: 760
        anchors.left: parent.left
        anchors.leftMargin: 0

        GroupBox {
            id: groupBox_menu
            width: 200
            height: 200
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            title: qsTr("Menu")

            RowLayout {
                Layout.topMargin: 23

                ComboBox {
                    id: comboBox
                    model: menu.VideoTypeLabels
                    onActivated: {
                            console.log("Current index: " + comboBox.currentIndex)
                            menu.CurrentIndex = comboBox.currentIndex
                     }
                }
            }
        }
    }

    Column {
        id: column_videosection
        anchors.left: column_mainmenu.right
        anchors.leftMargin: 6
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0

        GroupBox {
            id: groupBox
            width: 760
            height: 760
            clip: false
            visible: true
            title: qsTr("Group Box")

            GridView {
                id: gridView
                anchors.topMargin: 16
                anchors.fill: parent
                cellHeight: 70
                model: ListModel {
                    ListElement {
                        name: "Grey"
                        colorCode: "grey"
                    }

                    ListElement {
                        name: "Red"
                        colorCode: "red"
                    }

                    ListElement {
                        name: "Blue"
                        colorCode: "blue"
                    }

                    ListElement {
                        name: "Green"
                        colorCode: "green"
                    }
                }
                cellWidth: 70
                delegate: Item {
                    x: 5
                    height: 50
                    Column {
                        Rectangle {
                            width: 40
                            height: 40
                            color: colorCode
                            anchors.horizontalCenter: parent.horizontalCenter
                        }

                        Text {
                            x: 5
                            text: name
                            font.bold: true
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                        spacing: 5
                    }
                }
            }
        }
    }
}
