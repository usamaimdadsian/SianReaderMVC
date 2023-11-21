import QtQuick 2.15
import assets 1.0

Item {
    property bool isCollapsed: true

    anchors {
        top: parent.top
        bottom: parent.bottom
        left: parent.left
    }
    width: isCollapsed ? Style.widthNavigationBarCollapsed : Style.heightNavigationBarExpanded

    Rectangle {
        anchors.fill: parent
        color: Style.colourNavigationBarBackground

        Column {
            width: parent.width

            NavigationButton {
                iconCharacter: "\uf0c9"
                description: ""
                hoverColour: "#993333"
                onNavigationButtonClicked: isCollapsed = !isCollapsed
            }
            NavigationButton {
                iconCharacter: "\uf015"
                description: "Home"
                hoverColour: "#dc8a00"
                onNavigationButtonClicked: masterController.ui_navigationController.goHomeView();
            }
            NavigationButton {
                iconCharacter: "\uf234"
                description: "Splash View"
                hoverColour: "#dccd00"
                onNavigationButtonClicked: masterController.ui_navigationController.goSplashView();
            }
            NavigationButton {
                iconCharacter: "\uf002"
                description: "Find Client"
                hoverColour: "#8aef63"
                onNavigationButtonClicked: masterController.ui_navigationController.goFindClientView();
            }
        }
    }
}
