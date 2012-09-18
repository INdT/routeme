import QtQuick 1.0
import com.routeme.types 1.0
import com.nokia.meego 1.0

Page {
    id: mainwindow

    property alias zoomLevel: map.zoomLevel

    tools: rootToolbar

    orientationLock: PageOrientation.LockPortrait

    RoutePositionInfo {
        id: positionInfo

        onCurrentCoordinateAvailable: {
            map.coordinate = currentCoordinate
            pixmap.coordinate = currentCoordinate
            positionInfo.stopUpdates()

            searchManager.coordinate = currentCoordinate
            searchManager.searchPlace()
        }

        Component.onCompleted: {
            positionInfo.startUpdates()
        }
    }

    RouteSearchManager {
        id: searchManager

        onPlaceAvailable: {
            mainwindow.tools.children[1].enabled = true
            rootWindow.address = "Address: "
            rootWindow.address += "\n"
            rootWindow.address += "City: " + place.address.city
            rootWindow.address += "\n"
            rootWindow.address += "Street: " + place.address.street
            rootWindow.address += "\n"
            rootWindow.address += "Postcode: " + place.address.postcode
            rootWindow.address += "\n"
            rootWindow.address += "Latitude: " + place.coordinate.latitude
            rootWindow.address += "\n"
            rootWindow.address += "Longitude: " + place.coordinate.longitude
        }
    }

    RouteMap {
        id: map

        currentPixmapLocation: pixmap
        visible: pageStack.busy ? false : true
        width: 480
        height: 864
        zoomLevel: 13
    }

    RoutePixmap {
        id: pixmap
        source: ":/qml/current_position.png"
    }
}
