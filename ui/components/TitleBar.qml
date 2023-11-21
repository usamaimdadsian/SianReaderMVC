import QtQuick
import QtQuick.Controls
import assets
import SianReader


Item {
    width: parent.width // Adjust the width as needed
    height: Style.titleBarHeight // Set the desired height
    property string title: "My Custom Title Bar"
    property int viewType: ViewType.UNKNOWN

    signal minimizeClicked()
    signal closeClicked()
    signal maximizeClicked()
    signal restoreClicked()


    Connections{
        target: masterController
        function onViewChanged() {
            viewStates.state = masterController.currentViewType
        }
    }

    function changeWindowSize()
    {
        if (resizeStates.state != "maximized")
        {
            resizeStates.state = "maximized"
            maximizeClicked()
        }
        else if (resizeStates.state != "minimized")
        {
            resizeStates.state = "minimized"
            restoreClicked()
        }
    }

    function titleBarMouseAreaLeft()
    {
        switch(viewStates.state)
        {
        case  ViewType.UNKNOWN:
            return background.left;
        case ViewType.HOME:
            return homeViewOptions.right;
        case ViewType.CONTENT:
            return contentViewOptions.right;
        default:
            return background.left;
        }

    }

    Rectangle {
        id: background
        width: parent.width
        height: parent.height
        color: Style.titleBarBackgroundColor

        ContentViewOptions{
            id: contentViewOptions
        }

        HomeViewOptions{
            id: homeViewOptions
        }


        Text {
            text: background.parent.title
            anchors.centerIn: background
        }


        MouseArea {
            id: titleMouseArea
            anchors{
                top: parent.top
                bottom: parent.bottom
                left: parent.left
                right: rightOfTitleBar.left
            }
            propagateComposedEvents: true
            property int previousX
            property int previousY

            onPressed: {
                previousX = mouseX
                previousY = mouseY
            }

            onMouseXChanged: {
                var dx = mouseX - previousX
                window.setX(window.x + dx)
            }

            onMouseYChanged: {
                var dy = mouseY - previousY
                window.setY(window.y + dy)
            }

            onDoubleClicked: changeWindowSize()
        }




        Row{
            id: rightOfTitleBar
            anchors{
                top: parent.top
                bottom: parent.bottom
                right: parent.right
            }

            IconButton{
                iconCharacter: "\uf2d1"
                onButtonClicked: minimizeClicked()
                width: Style.titlBarWindowOperationButtonWidth
                height: parent.height
                backgroundColor: background.color
            }

            IconButton{
                id: maximizeButton
                iconCharacter: "\uf2d0"
                onButtonClicked: changeWindowSize()
                width: Style.titlBarWindowOperationButtonWidth
                height: parent.height
                backgroundColor: background.color
            }

            IconButton{
                iconCharacter: "\uf00d"
                onButtonClicked: closeClicked()
                width: Style.titlBarWindowOperationButtonWidth
                height: parent.height
                backgroundColor: background.color
            }
        }
    }


    StateGroup{
        id: resizeStates
        states: [
            State {
                name: "maximized"
                PropertyChanges {
                    target: maximizeButton
                    iconCharacter: "\uf2d2"
                }
            },
            State{
                name: "minimized"
                PropertyChanges {
                    target: maximizeButton
                    iconCharacter: "\uf2d0"
                }
            }
        ]
    }

    StateGroup{
        id: viewStates
        states: [
            State{
                name: ViewType.UNKNOWN
                PropertyChanges {
                    target: contentViewOptions
                    visible: false
                }
                PropertyChanges {
                    target: homeViewOptions
                    visible: false
                }
            },
            State{
                name: ViewType.CONTENT
                PropertyChanges {
                    target: contentViewOptions
                    visible: true
                }
                PropertyChanges {
                    target: homeViewOptions
                    visible: false
                }
            },
            State{
                name: ViewType.HOME
                PropertyChanges {
                    target: contentViewOptions
                    visible: false
                }
                PropertyChanges {
                    target: homeViewOptions
                    visible: true
                }
            }
        ]
    }

}
