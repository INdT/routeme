import QtQuick 1.0
import com.routeme.types 1.0
import Qt.labs.components.native 1.0

Window {
    id: main

    RoutePositionInfo {
        id: positionInfo

        onCurrentCoordinateAvailable: {
            console.log("##: " + currentCoordinate.latitude)
            coordinateItem = currentCoordinate
        }
        Component.onCompleted: {
            console.log("initializing updates...")
            startUpdates();
        }
    }

    RouteCoordinate {
        id: coordinateItem

        latitude: -3.0
        longitude: -60.0
    }

    RouteMeMap {
        id: map
        width: 480
        height: 864
        zoomLevel: 10

        coordinate: coordinateItem
    }

    Page {
        orientationLock: PageOrientation.LockPortrait
    }
}
