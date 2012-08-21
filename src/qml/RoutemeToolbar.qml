import QtQuick 1.0
import com.nokia.meego 1.1

Item {
    id: toolbar
    width: parent.width
    height: 70

    signal zoomIn()
    signal zoomOut()
    signal routeMe()

    Rectangle {
        id: background
        opacity: 0.5
        color: "#343434"
        anchors.fill: parent
    }

    Row {
        anchors.centerIn: parent
        spacing: 20

        Button {
            id: send

            width: 150
            text: "Route Me"
            onClicked: toolbar.routeMe()
        }

        Button {
            id: zoomIn

            width: 50
            text: "+"
            onClicked: toolbar.zoomIn();
        }

        Button {
            id: zoomOut

            width: 50
            text: "-"
            onClicked: toolbar.zoomOut()
        }
    }
}
