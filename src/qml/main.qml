import QtQuick 1.0
import com.routeme.types 1.0
import Qt.labs.components.native 1.0

Window {
    id: main

    RouteManager {
        id: manager

        destination: RouteCoordinate {
            latitude: -3.135661
            longitude: -59.992884
        }

        onRouteAvailable: {
            map.route = manager.route
        }
    }

    RoutePositionInfo {
        id: positionInfo

        onCurrentCoordinateAvailable: {
            map.coordinate = currentCoordinate
            manager.origin = currentCoordinate
            manager.calculateRoute()
        }

        Component.onCompleted: {
            startUpdates();
        }
    }

    RouteMeMap {
        id: map
        width: 480
        height: 864
        zoomLevel: 13
    }

    Page {
        orientationLock: PageOrientation.LockPortrait
    }
}
