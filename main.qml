import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.2
import MyModule 1.0

Window
{
    id: root

    visible: true
    width: 640
    height: 480
    title: qsTr("Timer")

    Host
    {
        id: host
    }

    TextField
    {
        id: timeField
        placeholderText: "Enter number of seconds."

        anchors.top: parent.top
        anchors.left: parent.left
    }

    Button
    {
        anchors.left: timeField.right
        anchors.top: parent.top
        text: "Set time"
        onClicked:
        {
            host.startOfTimer(timeLeft,timeField.text);
            host.counting(timeField.text)
        }
    }

    Text
    {
        id: timeLeft
        text: host.returnOfValue()
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 60
    }

    Dialog
    {
        id: dialog
        width: 200
        height: 100
        title: qsTr("---Attention---")
        Text
        {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            text: "Time's up!"
            font.pointSize: 40
        }
    }

    Connections
    {
        target: host
        onTimeIsUp: dialog.open()
    }
}
