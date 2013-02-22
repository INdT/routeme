import QtQuick 1.1
import com.nokia.meego 1.0
import com.routeme.types 1.0

import QtMobility.contacts 1.1

Page {
    id: addressbookpage
    orientationLock: PageOrientation.LockPortrait

    property int indexValue;
    property string selectedContactName;
    property bool firstCountChange: true;

    function firstChar(stringValue) {
        return stringValue.charAt(0);
    }

    function updatephoneNumberList() {
        for (var i = 0; i < addressBookSheetContentId.phonebookModel.contacts[indexValue].phoneNumbers.length; i++) {
            addressBookSheetContentId.phoneNumberList.append({"name": addressBookSheetContentId.phonebookModel.contacts[indexValue].phoneNumbers[i].number})
        }
    }

    Sheet {
        id: addressBookSheet

        anchors.fill: parent
        rejectButtonText: "Cancel"

        content: RouteMeAddressContent { id: addressBookSheetContentId }

        onRejected: {
            pageStack.pop();

            routemepage.smsSheet.open();
        }
    }

    Component.onCompleted: {
        addressBookSheet.open();
    }
}
