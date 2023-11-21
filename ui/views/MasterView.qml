import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls

import components
import assets
import SianReader

Window {
    id: window
    width: Style.windowWidth
    height: Style.windowHeight
    visible: true
//    flags: Qt.FramelessWindowHint
    flags: Qt.Window | Qt.CustomizeWindowHint

    TitleBar{
        id: titleBar
        onMinimizeClicked: window.showMinimized()
        onMaximizeClicked: window.showMaximized()
        onRestoreClicked: window.showNormal()
        onCloseClicked: window.close()
        title: "Sian Reader"
    }

    Item{
        id: content
        width: parent.width
        height: parent.height - titleBar.height
        anchors.top: titleBar.bottom


        StackView{
            id: contentFrame
            initialItem: "qrc:/views/SplashView.qml"
            anchors.fill: parent
            clip: true
        }


//        Component.onCompleted: masterController.ui_navigationController.triggerHomeView()
        Component.onCompleted: masterController.ui_navigationController.triggerContentView()
        Connections{
            target: masterController.ui_navigationController
            function onGoHomeView()
            {
                contentFrame.replace("qrc:/views/HomeView.qml")
                masterController.setView(ViewType.HOME)
            }
            function onGoContentView()
            {
                contentFrame.replace("qrc:/views/ContentView.qml")
                masterController.setView(ViewType.CONTENT)
            }
            function onGoSplashView()
            {
                contentFrame.replace("qrc:/views/SplashView.qml")
                masterController.setView(ViewType.SPLASH)
            }
        }
    }

    WindowResizer{}

}
