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

        onTextChanged:
        {
            host.startOfTimer();
//            host.counting(timeField.text)
        }
    }

    Text
    {
        objectName: timeText
        id: timeLeft
        text: host.counting(timeField.text)
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 60
    }

}
