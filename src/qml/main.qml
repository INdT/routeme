import QtQuick 1.0
import com.routeme.types 1.0
import Qt.labs.components.native 1.0

Window {
    id: main

    RouteMeMap {
        id: map
        width: 480
        height: 864
        zoomLevel: 10
    }

    Page {
        orientationLock: PageOrientation.LockPortrait
    }
}
