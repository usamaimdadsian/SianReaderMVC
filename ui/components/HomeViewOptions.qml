import QtQuick
import QtQuick.Dialogs

Row{
    visible: false
//            z: 1
    anchors{
        top: parent.top
        left: parent.left
        bottom: parent.bottom
    }
    FileDialog
    {
        id: fileDialog
        title: "Open a PDF file"
        nameFilters: [ "PDF files (*.pdf)" ]
        onAccepted: {
            console.log("The file is: ", selectedFile)
            masterController.ui_bookController.setPdfBook(selectedFile);
            masterController.ui_navigationController.triggerContentView();
        }
    }
    Rectangle{
        height: parent.height
        width: 50
        color: "green"

        Text {
            text: qsTr("Open")
            anchors.centerIn: parent
        }
        MouseArea{
            id: openBtnMouseArea
            anchors.fill: parent
            onClicked: fileDialog.open()
        }
    }
}
