import QtQuick 2.15
import QtQuick.Dialogs
import QtQuick.Controls
import assets
import components
import QtQuick.Pdf
import SianReader

Item {

    Component.onCompleted: {
        masterController.ui_bookController.setPdfDocument(doc,view)
    }
    Rectangle {
        anchors.fill: parent
        color: Style.colourBackground
        anchors{
            left:  navigationBar.right
            top: parent.top
            right: parent.right
            bottom: commandBar.top
        }

        PdfBookmarkModel{
            document: doc
        }

        PdfDocument {
           id: doc
//           source: Qt.resolvedUrl(root.source)
           source: "file:///home/usama/Documents/Pride and Prejudice (Jane Austen) (Z-Library).pdf"
//           source: masterController.ui_bookController.ui_currentPdf
           onPasswordRequired: passwordDialog.open()
       }

       PdfMultiPageView {
           id: view
           anchors.fill: parent
           document: doc
//           searchString: searchField.text
           onCurrentPageChanged: masterController.ui_bookController.emitCurrentPageChanged()
       }

    }




    CommandBar {
        id: commandBar
        commandList: masterController.ui_commandController.ui_createClientViewContextCommands
    }

    NavigationBar{
        id: navigationBar
    }
}
