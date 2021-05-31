import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Dialogs.qml 1.0
import QtQuick.Controls 2.3
import QtMultimedia 5.12
import custom 1.0

Window {
    id: main_window
    visible: true
    width: 1024
    height: 760
    color: "#c3c1c1"
    title: qsTr("Video Editor")

    property string videoSelected: ""
    property string projectRoot: ""

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
            title: qsTr("Videos")

            GridView {
                id: videoGridView
                anchors.topMargin: 16
                anchors.fill: parent
                cellHeight: 150
                cellWidth: 150
                model: VideoListModel { id: videoListModel}
                delegate: Item {
                    Column {
                        spacing: 10

                        Button {
                            width: 120
                            height: 120
                            anchors.horizontalCenter: parent.horizontalCenter

                            onClicked: {
                                console.log("RAW video clicked")
                                videoSelected = videoName
                                projectRoot = projectRootPath
                                console.log("videoSelected: " + videoSelected)
                                raw_video_popup.open()
                            }

                            Image {
                                anchors.fill: parent
                                source: "file:" + projectRootPath + "/Assets/Thumbnails/" + videoName + ".jpg"
                            }
                        }

                        Button {
                            text: "EDIT"
                            width: 80
                            height: 20
                            anchors.horizontalCenter: parent.horizontalCenter

                            onClicked: {
                                console.log("EDIT for " + videoName)
                                projectRoot = projectRootPath
                                edited_video_popup.open()
                            }
                        }

                        Text {
                            text: videoName
                            font.bold: true
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                    }
                }    
            }
        }
    }

    Popup {
        id: raw_video_popup
        x: 10
        y: 10
        width: main_window.width - 20
        height: main_window.height - 20
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent

        Rectangle {
            width: parent.width
            height: parent.height
            color: "black"

            MediaPlayer {
                id: player
                source: "file:" + projectRoot + "/Assets/Videos/" + videoSelected + ".mp4"
                autoPlay: true
            }

            VideoOutput {
                id: videoOutput
                source: player
                anchors.fill: parent
            }
        }
    } 
}
