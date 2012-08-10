import QtQuick 1.0
import com.routeme.types 1.0
import Qt.labs.components.native 1.0

Window {
    id: main

    RouteMeMap {
        id: map

        latitude: -3.0
        longitude: -60.0
    }

    Page {
        orientationLock: PageOrientation.LockPortrait
    }
}
