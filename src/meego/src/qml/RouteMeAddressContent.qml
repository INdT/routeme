import QtQuick 1.0
import com.nokia.meego 1.0

import QtMobility.contacts 1.1

Item  {
    id: addressBookItem
    anchors.fill: parent

    property alias phonebookModel: phonebookModel
    property alias phoneNumberList: phoneNumberList

    function getTagName() {
        if(name.firstName !== "" || name.lastName !== "")
            return (firstChar(name.firstName)).toUpperCase()
                + (firstChar(name.lastName)).toUpperCase();
        else
            return (firstChar(nickname.nickname));
    }

    Text {
        id: blankscreentext
        text: "No Contacts"
        font.pixelSize: 48
        opacity: 0.7
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        visible: !routemepage.contactsAvailable
        color: "black"
    }

   BusyIndicator {
       id: spinner
       platformStyle: BusyIndicatorStyle { size: "large" }
       anchors.centerIn: parent
       opacity: (routemepage.contactsAvailable === true ? (contactListView.count > 0? 0 : 1) : 0 )
       running: (routemepage.contactsAvailable === true ? (contactListView.count > 0? false : true) : false )
   }

    ListView {
        id: contactListView

        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.left: parent.left

        model: phonebookModel.contacts
        delegate: contactDelegate
        clip: true

        section.property: "displayLabel"
        section.criteria: ViewSection.FirstCharacter

        section.delegate: Item {
            width: parent.width;
            height: 40

            Text {
                id: headerLabel
                anchors.right: parent.right
                anchors.rightMargin: 20

                anchors.bottom: parent.bottom
                anchors.bottomMargin: 2

                font.family: "Nokia Pure Text"
                font.pixelSize: 18
                font.bold: true
                color: rootWindow.secondaryForeground
                text: section.toUpperCase();
            }

            Image {
                anchors.right: headerLabel.left
                anchors.rightMargin: 24
                anchors.left: parent.left
                anchors.leftMargin: 16
                anchors.verticalCenter: headerLabel.verticalCenter

                source: "image://theme/meegotouch-groupheader"
                            + (theme.inverted ? "-inverted" : "") + "-background"
            }
        }

        onCountChanged: {
            if (contactListView.count) {
                if( blankscreentext.visible == true )
                    blankscreentext.visible = false

                spinner.opacity = 0;
                spinner.running = false;
            } else if (!firstCountChange && contactListView.count == 0) {
                blankscreentext.visible = true
            }

            firstCountChange = false
        }
    }

    ContactModel {
        id: phonebookModel
        autoUpdate: true

        filter: DetailFilter {
            detail: ContactDetail.PhoneNumber
            field: PhoneNumber.Number
        }

        sortOrders: SortOrder {
            detail: ContactDetail.DisplayLabel
            direction: Qt.AscendingOrder
            caseSensitivity: Qt.CaseInsensitive
        }
    }

    Component {
        id: contactDelegate

        Item {
            id: listItem
            width: parent.width
            height: 80

            BorderImage {
                id: background

                anchors.fill: parent
                anchors.leftMargin: -addressbookpage.anchors.leftMargin
                anchors.rightMargin: -addressbookpage.anchors.rightMargin

                visible: mouseArea.pressed
                source: "image://theme/meegotouch-list-inverted-background-pressed-center"
            }

            Image {
                id: contactImage
                height: 60
                width: 60
                source: "image://theme/meegotouch-avatar-placeholder-background"

                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 16


                smooth: true

                Image {
                    id: contactPic
                    anchors.fill: parent
                    source: avatar.imageUrl

                    onStatusChanged: if (status === Image.Error)
                                        contactPic.source = ""
                }

                Text {
                    id: tagName
                    anchors.centerIn: parent
                    color: "white"
                    font { bold: true; pixelSize: 32 }
                    opacity: (contactPic.source == "") ? 1.0 : 0.0
                    text: (name.firstName !== "" || name.lastName  !== "")?
                             ((firstChar(name.firstName)).toUpperCase()
                              +(firstChar(name.lastName)).toUpperCase()):(firstChar(nickname.nickname))
                }
            }

            Image {
                id: maskedImage
                height: 60
                width: 60
                source: "image://theme/meegotouch-avatar-mask-small"

                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 16

                smooth: true
                opacity: 0.0
            }

            Label {
                id: contactName
                width: parent.width - (contactPic.width + 36)
                anchors.left: contactImage.right
                anchors.leftMargin: 20
                anchors.verticalCenter: parent.verticalCenter
                anchors.rightMargin: 16
                font.family: "Nokia Pure Text"
                font.pixelSize: 26
                font.bold: true
                wrapMode: Text.Wrap
                elide: Text.ElideRight
                color: "black"
                text: displayLabel
                maximumLineCount: 1
            }

            MouseArea {
                id: mouseArea
                anchors.fill: background

                onClicked: {
                    if (phonebookModel.contacts[index].phoneNumbers.length == 1) {
                        routemepage.addressBookPhoneNumber =
                                phonebookModel.contacts[index].phoneNumber.number

                        if (phonebookModel.contacts[index].name.firstName !== "" || phonebookModel.contacts[index].name.lastName !== "")
                            routemepage.addressBookContactName =
                                phonebookModel.contacts[index].name.firstName + " "
                                + phonebookModel.contacts[index].name.lastName;
                        else
                            routemepage.addressBookContactName = phonebookModel.contacts[index].nickname.nickname;

                        routemepage.addressBookContactSelected = true;
                        pageStack.pop();

                        routemepage.smsSheet.open();
                    } else {
                        indexValue = index;

                        if (phonebookModel.contacts[index].name.firstName !== "")
                            selectedContactName = phonebookModel.contacts[index].name.firstName;
                        else if (phonebookModel.contacts[index].name.lastName !== "")
                            selectedContactName = phonebookModel.contacts[index].name.lastName;
                        else
                            selectedContactName = phonebookModel.contacts[index].nickname.nickname

                        updatephoneNumberList();
                        singleSelectionDialog.open()
                    }
                }
            }
        }
    }

    SelectionDialog {
        id: singleSelectionDialog
        titleText: selectedContactName
        model: phoneNumberList
        selectedIndex: 0

        onAccepted: {
            routemepage.addressBookPhoneNumber =
                        singleSelectionDialog.model.get(singleSelectionDialog.selectedIndex).name

            if (phonebookModel.contacts[indexValue].name.firstName !== "" || phonebookModel.contacts[indexValue].name.lastName !== "")
                routemepage.addressBookContactName =
                    phonebookModel.contacts[indexValue].name.firstName + " "
                    + phonebookModel.contacts[indexValue].name.lastName;
            else
                routemepage.addressBookContactName = phonebookModel.contacts[indexValue].nickname.nickname;

            routemepage.addressBookContactSelected = true;
            phoneNumberList.clear();
            pageStack.pop();

            routemepage.smsSheet.open();
        }

        onRejected: phoneNumberList.clear();
    }

    ScrollDecorator {
        flickableItem: contactListView
    }

    ListModel {
        id: phoneNumberList
    }
}
