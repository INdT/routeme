import QtQuick 1.0
import com.routeme.types 1.0
import Qt.labs.components.native 1.0

Window {
    id: main

    RouteManager {
        id: manager

        //XXX Just for tests purpose
        destination: RouteCoordinate {
            latitude: -3.135661
            longitude: -59.992884
        }

        onRouteAvailable: {
            map.route = manager.route
        }
    }

    RouteSearchManager {
        id: searchManager

        onPlaceAvailable: {
            console.log("### state:  "+place.address.state)
            console.log("### city:  "+place.address.city)
            console.log("### street:  "+place.address.street)
            console.log("### postcode:  "+place.address.postcode)
            console.log("### latitude:  "+place.coordinate.latitude)
            console.log("### longitude:  "+place.coordinate.longitude)
        }
    }

    RoutePositionInfo {
        id: positionInfo

        onCurrentCoordinateAvailable: {
            map.coordinate = currentCoordinate
            manager.origin = currentCoordinate
            manager.calculateRoute()
            searchManager.coordinate = currentCoordinate
            searchManager.searchPlace()

            stopUpdates()
        }

        Component.onCompleted: {
            startUpdates();
        }
    }

    RouteMap {
        id: map
        width: 480
        height: 864
        zoomLevel: 13
    }

    RoutemeToolbar {
        id: mainToolbar
        anchors.bottom: map.bottom

        onZoomIn: {
            map.zoomLevel += 1
        }

        onZoomOut: {
            map.zoomLevel -= 1
        }

        onRouteMe: {
            //TODO it might send the current location as sms
            console.log("RouteMe: Sending your current location...")
        }
    }

    Page {
        orientationLock: PageOrientation.LockPortrait
    }
}
