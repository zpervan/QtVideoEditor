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
    property bool playbackState: false
    property int numericalValue: 0
    property string firstGradientColor: "grey"
    property double firstGradientColorPosition: 0.95
    property string secondGradientColor: "white"
    property double secondGradientColorPosition: 0.25
    property int progressBarValue: 0
    property bool isIncrementing: true

// ####################### MAIN MENU ####################### 

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

// ####################### VIDEO SELECTION ####################### 

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
                                videoSelected = videoName
                                projectRoot = projectRootPath
                                edit_video_popup.open()
                                timer_text.running = !timer_text.running
                                timer_gradient.running = !timer_gradient.running 
                                timer_progress_bar.running = !timer_progress_bar.running 
                            }

                            background: Rectangle {
                                color: parent.down ? "#bbbbbb" : (parent.hovered ? "#d6d6d6" : "#f6f6f6")
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

// ####################### RAW VIDEO POPUP ####################### 

    Popup {
        id: raw_video_popup
        x: 10
        y: 10
        width: main_window.width - 20
        height: main_window.height - 20
        modal: true
        focus: true
        closePolicy: Popup.NoAutoClose

        Rectangle {
            width: parent.width
            height: parent.height
            color: "black"

            MediaPlayer {
                id: mediaPlayer
                source: {
                    if(!projectRoot || !videoSelected)
                    {
                     console.log("No source defined")
                     ""
                    } else {
                        "file:" + projectRoot + "/Assets/Videos/" + videoSelected + ".mp4"
                    }
                }
                autoPlay: false
                autoLoad: true
            }

            VideoOutput {
                id: videoOutput
                source: mediaPlayer
                anchors.fill: parent
            }

            Button{
                x: parent.width / 2 - 40
                y: parent.height - 60
                width: 80
                height: 40
                text: playbackState ? "PAUSE" : "PLAY"
   
                onClicked: {
                    if(!playbackState)
                    {
                        playbackState = true
                        mediaPlayer.play()
                    } else {
                        playbackState = false
                        mediaPlayer.pause()
                    } 
                }

                background: Rectangle {
                    color: parent.down ? "#bbbbbb" : (parent.hovered ? "#d6d6d6" : "#f6f6f6")
                }
            }

            Button{
                x: parent.width - 40
                y: 20
                width: 20
                height: 20
                text: "X"

                onClicked: {
                    playbackState = false
                    mediaPlayer.stop()
                    raw_video_popup.close()
                }

                background: Rectangle {
                    color: parent.down ? "#bbbbbb" : (parent.hovered ? "#d6d6d6" : "#f6f6f6")
                }
            }
        }
    }

// ####################### EDIT VIDEO POPUP #######################    

    Popup {
        id: edit_video_popup
        x: 10
        y: 10
        width: main_window.width - 20
        height: main_window.height - 20
        modal: true
        focus: true
        closePolicy: Popup.NoAutoClose

        Timer {
            id: timer_text
            interval: 300
            running: false
            repeat: true
            onTriggered: {numericalValue = randomGenerator.GenerateNumber}
        }

        Timer {
            id: timer_gradient
            interval: 1000
            running: false
            repeat: true
            onTriggered: {
                firstGradientColor = randomGenerator.GenerateColor
                firstGradientColorPosition = randomGenerator.GenerateNormalizedPosition
                // console.log("First gradient color: " + firstGradientColor)
                // console.log("First gradient color position: " + firstGradientColorPosition)

                secondGradientColor = randomGenerator.GenerateColor
                secondGradientColorPosition = randomGenerator.GenerateNormalizedPosition
                // console.log("Second gradient color: " + secondGradientColor)
                // console.log("Second gradient color position: " + secondGradientColorPosition)
            }
        }

        Timer {
            id: timer_progress_bar
            interval: 500
            running: false
            repeat: true
            onTriggered: {progressBarValue = changeProgressBarValue()
            console.log("Progress bar value: " + progressBarValue)}
        }

        GroupBox {
            width: parent.width
            height: parent.height
            visible: true
            title: "Edit video " + videoSelected

            Label{
                text: "Random numerical value: " + numericalValue
            }

            Rectangle{
                y: 20
                width: 100
                height: 100
                border.color: "black"
                gradient: Gradient {
                    GradientStop { position: firstGradientColorPosition; color: firstGradientColor }
                    GradientStop { position: secondGradientColorPosition; color: secondGradientColor }
                }
            }

            ProgressBar{
                y: 140
                from: 0
                to: 10
                width: parent.width
                value: progressBarValue
            }

            Button{
                y: parent.height - 40
                text: "EXIT"
                onClicked: {
                    timer_text.running = !timer_text.running
                    timer_gradient.running = !timer_gradient.running 
                    timer_progress_bar.running = !timer_progress_bar.running 
                    edit_video_popup.close()
                }

                background: Rectangle {
                    color: parent.down ? "#bbbbbb" : (parent.hovered ? "#d6d6d6" : "#f6f6f6")
                }
            }
        }
    }

    function changeProgressBarValue()
    {
        if(isIncrementing)
        {
            if(progressBarValue >= 9)
            {
                isIncrementing = false
            }
            return progressBarValue += 1
        } else {
            if(progressBarValue <= 1)
            {
                isIncrementing = true
            }
            return progressBarValue -= 1
        }
    }
}
