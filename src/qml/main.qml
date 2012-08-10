import QtQuick 1.0
import com.routeme.types 1.0

Item {
    id: main
    width: 480
    height: 864

    RouteMeMap {
        id: map
        width: parent.width
        height: parent.height

        latitude: -3.0
        longitude: -60.0
    }
}
