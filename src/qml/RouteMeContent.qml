import QtQuick 1.0
import com.nokia.meego 1.0
import com.nokia.extras 1.0
import com.routeme.types 1.0

Flickable {
    id: contact

    anchors.fill: parent

    flickableDirection: Flickable.VerticalFlick

    property alias contactsInput: contactsInput
    property alias contactsInputText: contactsInput.text
    property alias messageText: messageText.text
    property alias messageTextEdit: messageText
    property alias spinner: spinner
    property alias infobanner: infobanner
    property alias addButton: addButton
    property string focusedElement: ""

    Rectangle {
        id: contactsRect

        width: parent.width
        height: 72
        anchors.left: parent.left
        color: "#E0E1E2"

        Label {
            id: to
            anchors.left: contactsRect.left
            anchors.leftMargin: 16
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 28
            text: "To:"
            color: "#4591FF"
        }

        TextInput {
            id: contactsInput

            width: 300
            anchors.left: to.right
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 28
            horizontalAlignment: TextInput.AlignLeft
            color: "grey"
            focus: true
            inputMethodHints: Qt.ImhDialableCharactersOnly

            onActiveFocusChanged: {
                if (contactsInput.focus) {
                    focusedElement = "number";
                }
            }

            Text {
                id: placeHolder
                anchors.fill: parent.fill
                font.pixelSize: 28
                color: "#b2b2b4"
                opacity: 0.65
                visible: (contactsInput.text === "") ? true : false;
                text: "Add Contact";
            }

            Keys.onPressed: {
                if (event.key === Qt.Key_Backspace)
                    if (addressBookContactSelected === true) {
                        contactsInput.text = "";
                        addressBookPhoneNumber = "";
                        addressBookContactSelected = false;
                    }
            }
        }

        Button {
            id: addButton

            width: 43
            height: 42
            anchors.right: parent.right
            anchors.rightMargin: 20
            anchors.verticalCenter: parent.verticalCenter
            text: "+"
            font.pixelSize: 30
            font.bold: false

            onClicked: {
                messageText.closeSoftwareInputPanel();
                messageText.focus = false;
                routemepage.openFile("RouteMeAddressBook.qml");
            }
        }

    }

    Rectangle {
        id: messageBox
        width: parent.width
        height: parent.height - contactsRect.height

        anchors.top: contactsRect.bottom

        TextEdit {
            id: messageText

            anchors.fill: parent
            anchors.leftMargin: 10
            anchors.topMargin: 10
            font.pixelSize: 26
            cursorVisible: false
            wrapMode: TextEdit.Wrap

            onActiveFocusChanged: {
                if (messageText.focus) {
                    focusedElement = "text";
                }
            }

            Text {
                id: messageTextPlaceholder

                anchors.fill: parent.fill
                font.pixelSize: 26
                color: "#b2b2b4"
                visible: messageText.cursorPosition === 0 && !messageText.text &&
                         messageTextPlaceholder.text && !messageText.inputMethodComposing

                opacity: 0.65
                text: "Write your message here"
            }
        }
    }

    BusyIndicator {
        id: spinner
        platformStyle: BusyIndicatorStyle { size: "medium" }
        anchors.centerIn: parent
        opacity: 0.0
        running: false
    }

    InfoBanner { id: infobanner }
}
