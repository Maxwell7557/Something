import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.2
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
        placeholderText: "Введи число секунд."

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
            host.startOfTimer();
            host.counting(timeField.text)
        }
    }

    Text
    {
        objectName: "textLable"
        id: timeLeft
        text: host.returnOfValue()
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 60
    }

}
