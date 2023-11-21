import QtQuick 2.15
import assets
import components

Item{
    Rectangle {
        anchors.fill: parent
        color: "orange"

        Text {
            anchors.centerIn: parent
            text: qsTr("Splash View")
        }

        CommandBar{
            commandList: masterController.ui_commandController.ui_createClientViewContextCommands
        }
    }
}
