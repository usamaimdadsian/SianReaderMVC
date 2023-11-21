import QtQuick 2.15
import components

Row{
    visible: false
    spacing: 10

    anchors{
        top: parent.top
        left: parent.left
        bottom: parent.bottom
        leftMargin: 10
    }
    Component.onCompleted: {
        totalPageNumber.text = masterController.ui_bookController.ui_totalPageCount
    }
    Connections{
        target: masterController.ui_bookController
        function onCurrentPageChanged()
        {
            currentPageNumber.text = masterController.ui_bookController.ui_currentPage
        }
    }

    IconButton{
        iconCharacter: "\ue24e"
        onButtonClicked: minimizeClicked()
        width: parent.height + 5
        height: parent.height - 10
        backgroundColor: "gray"
        checkable: true
        anchors.verticalCenter: parent.verticalCenter
    }

    Row{
        anchors{
            top: parent.top
            bottom: parent.bottom
        }

        Rectangle{
            width: 100
            height: parent.height
            radius: height*0.05
            clip: true
            color: "gray"

            Rectangle{
                width: parent.width/2
                height: parent.height
                anchors.left: parent.left

                TextInput{
                    id: currentPageNumber
                    anchors.fill: parent
                    validator: IntValidator{bottom: 1; top: 100}
                    text: "1"
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {currentPageNumber.focus = true}
                }
            }

            Rectangle{
                width: parent.width/2
                height: parent.height
                anchors.right: parent.right

                TextInput{
                    id: totalPageNumber
                    readOnly: true
                    text: "100"
                    anchors.fill: parent
                }
            }

        }



//        TextInput{
//            id: currentPageNumber
//            validator: IntValidator{bottom: 1; top: 100}
//            height: parent.height
//            width: 50
//            color: "yellow"
//        }
//        TextInput{
//            id: totalPageNumber
//            readOnly: true
//            text: "100"
//            height: parent.height
//            width: 50
//            color: "green"
//        }

    }
}
