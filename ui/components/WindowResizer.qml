import QtQuick
import assets

Item {
    // Declare properties that will store the position of the mouse cursor
    anchors.fill: parent
    property real previousX
    property real previousY
    property int drag_area_size: Style.windowDragAreaSize
    property real threshold: 5

    function resizeTop(initialY, currentY)
    {
        var dy = currentY - initialY

        window.setY(window.y + dy)
        window.setHeight(window.height - dy)
    }

    function resizeBottom(initialY, currentY)
    {
        var dy = currentY - initialY
        window.setHeight(window.height + dy)
    }

    function resizeLeft(initialX, currentX)
    {
        var dx = currentX - initialX
        window.setX(window.x + dx)
        window.setWidth(window.width - dx)
    }

    function resizeRight(initialX,currentX)
    {
        var dx = currentX - initialX
        window.setWidth(window.width + dx)
    }


    MouseArea {
        id: topArea
        height: drag_area_size
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }
        cursorShape: Qt.SizeVerCursor
        onPressed: {
            previousY = mouseY
        }

        onMouseYChanged: resizeTop(previousY,mouseY)
    }

    // Similar calculations for the remaining three areas of resize
    MouseArea {
        id: bottomArea
        height: drag_area_size
        anchors {
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }
        cursorShape: Qt.SizeVerCursor

        onPressed: {
            previousY = mouseY
        }

        onMouseYChanged: resizeBottom(previousY,mouseY)
    }

    MouseArea {
        id: leftArea
        width: drag_area_size
        anchors {
            top: topArea.bottom
            bottom: bottomArea.top
            left: parent.left
        }
        cursorShape: Qt.SizeHorCursor

        onPressed: {
            previousX = mouseX
        }

        onMouseXChanged: resizeLeft(previousX,mouseX)
    }

    MouseArea {
        id: rightArea
        width: drag_area_size
        anchors {
            top: topArea.bottom
            bottom: bottomArea.top
            right: parent.right
        }
        cursorShape:  Qt.SizeHorCursor

        onPressed: {
            previousX = mouseX
        }

        onMouseXChanged: resizeRight(previousX,mouseX)
    }

    MouseArea {
        id: topLeftCorner
        width: drag_area_size
        height: drag_area_size
        anchors {
            top: parent.top
            left: parent.left
        }
        cursorShape: Qt.SizeFDiagCursor

        property int initialX
        property int initialY

        onPressed: {
            initialX = mouseX
            initialY = mouseY
        }

        onMouseXChanged: resizeLeft(initialX,mouseX)
        onMouseYChanged: resizeTop(initialY,mouseY)
    }

    MouseArea {
        id: topRightCorner
        width: drag_area_size
        height: drag_area_size
        anchors {
            top: parent.top
            right: parent.right
        }
        cursorShape: Qt.SizeBDiagCursor

        property int initialX
        property int initialY

        onPressed: {
            initialX = mouseX
            initialY = mouseY
        }

        onMouseXChanged: resizeRight(initialX,mouseX)
        onMouseYChanged: resizeTop(initialY,mouseY)
    }

    MouseArea {
        id: bottomLeftCorner
        width: drag_area_size
        height: drag_area_size
        anchors {
            bottom: parent.bottom
            left: parent.left
        }
        cursorShape: Qt.SizeBDiagCursor

        property int initialX
        property int initialY

        onPressed: {
            initialX = mouseX
            initialY = mouseY
        }

        onMouseXChanged:resizeLeft(initialX,mouseX)
        onMouseYChanged: resizeBottom(initialY,mouseY)
    }

    MouseArea {
        id: bottomRightCorner
        width: drag_area_size
        height: drag_area_size
        anchors {
            bottom: parent.bottom
            right: parent.right
        }
        cursorShape: Qt.SizeFDiagCursor

        property int initialX
        property int initialY

        onPressed: {
            initialX = mouseX
            initialY = mouseY
        }

        onMouseXChanged: resizeRight(initialX,mouseX)
        onMouseYChanged: resizeBottom(initialY,mouseY)
    }

}
