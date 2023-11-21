import QtQuick
import assets

Item {
    property alias iconCharacter: textIcon.text

    property color backgroundColor: "gray"
    property color hoverColor: "darkgray"

    property color iconColor: "white"
    property int iconSize: Math.round(Math.min(width,height)*0.6)

    property int cursor: Qt.ArrowCursor

    property bool checkable: false
    property bool checked: false

    property int radius: 3


    width: 30
    height: 30

    signal buttonClicked()
    signal buttonHovered()

    Rectangle {
        id: background
        anchors.fill: parent
        color: (!parent.checkable)? parent.backgroundColor: ((parent.checked)? Qt.darker(parent.hoverColor): parent.backgroundColor)
        radius: parent.radius

        Text {
            id: textIcon
            width: parent.width
            height: parent.height
            font {
                family: Style.fontAwesome
                pixelSize: background.parent.iconSize
            }
            color: parent.parent.iconColor
            text: "\uf11a"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }


        MouseArea {
            anchors.fill: parent
            cursorShape: background.parent.cursor
            hoverEnabled: true
            onEntered: {
                background.parent.state = "hover"
                buttonHovered()
            }
            onExited: background.parent.state = ""
            onClicked: {
                buttonClicked()
                if (background.parent.checkable)
                    background.parent.checked = !background.parent.checked
            }
        }
    }

    states: [
        State {
            name: "hover"
            PropertyChanges {
                target: background
                color: hoverColor
            }
        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "hover"
            animations: [
                NumberAnimation {
                    target: textIcon
                    property: "scale"
                    to: 1.2
                    duration: 100
                }

            ]
        },
        Transition {
            from: "hover"
            to: ""
            animations: [
                NumberAnimation {
                    target: textIcon
                    property: "scale"
                    to: 1.0
                    duration: 100
                }
            ]
        }
    ]
}
