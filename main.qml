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

    Text
    {
        id: timeLeft
        text: host.counting(timeField.text)
//        height: 200
//        width: 200
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 60
//        onTextChanged: host.amountOfTimeHaveChanged(timeLeft.text);
    }

    Connections
    {
        target: timeLeft

    }

}
