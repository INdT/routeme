import QtQuick 1.0
import com.nokia.meego 1.0
import com.nokia.extras 1.0
import com.routeme.types 1.0

Page {
    id: routemepage

    orientationLock: PageOrientation.LockPortrait

    property bool addressBookContactSelected: false
    property bool contactsAvailable: false
    property string addressBookPhoneNumber: ""
    property alias smsSheet: sheet
    property alias addressBookContactName: routemeContent.contactsInputText
    property alias messageText: routemeContent.messageText

    function openFile(file) {
        var component = Qt.createComponent(file);
        contactsAvailable = controller.isContactsAvailable();

        if (component.status === Component.Ready) {
            sheet.close();
            pageStack.push(component);
        }
    }

    function phoneNumberValidator(phoneNumber) {
        if ((/[a-zA-Z#*]/.test(phoneNumber) === true))
            if (/[+]/.test(phoneNumber) === true) {
                if (phoneNumber[0] === "+")
                    phoneNumber = phoneNumber.replace("+","0")
                if (/[+]/.test(phoneNumber) === true)
                    return false;
        }
        return true;
     }

    function sendClicked() {
        if (routemeContent.contactsInput.text.length === 0) {
            routemeContent.infobanner.text = "Phone number is empty."
            routemeContent.contactsInput.forceActiveFocus()
        } else if (routemeContent.messageText.length === 0) {
            routemeContent.infobanner.text = "Message text is empty."
            routemeContent.messageTextEdit.forceActiveFocus()
        } else if (addressBookPhoneNumber === ""
                    && phoneNumberValidator(routemeContent.contactsInput.text) === false) {
            routemeContent.infobanner.text = "Invalid Phone number."
            routemeContent.contactsInput.forceActiveFocus()
        } else {
            if (routemeContent.focusedElement === "text") {
                routemeContent.messageText.forceActiveFocus();
                routemeContent.messageText.closeSoftwareInputPanel();
            } else if (routemeContent.focusedElement === "number") {
                routemeContent.contactsInput.forceActiveFocus();
                routemeContent.contactsInput.closeSoftwareInputPanel();
            }

            routemeContent.messageText.enabled = false
            sheet.acceptButton.enabled = false
            routemeContent.contactsInput.enabled = false
            routemeContent.addButton.enabled = false

            if (addressBookPhoneNumber === "") {
                routemeContent.spinner.running = true
                routemeContent.spinner.opacity = 1.0
                controller.sendMyCurrentLocation(routemeContent.contactsInput.text, routemeContent.messageText);

                routemeContent.spinner.opacity = 0.0
                routemeContent.spinner.running = false
            }
        }

        if (routemeContent.infobanner.text.length > 0) {
            routemeContent.infobanner.show()
        }
    }

    function cancelClicked() {
        if (routemeContent.focusedElement === "text") {
            routemeContent.messageText.forceActiveFocus();
            routemeContent.messageText.closeSoftwareInputPanel();
        } else if (routemeContent.focusedElement === "number") {
            routemeContent.contactsInput.forceActiveFocus();
            routemeContent.contactsInput.closeSoftwareInputPanel();
        }

        rootWindow.pageStack.pop()
    }

    Sheet {
        id: sheet
        acceptButtonText: "Send"
        rejectButtonText: "Cancel"

        anchors.fill: parent

        content: RouteMeContent { id: routemeContent }

        onAccepted: {
            sheet.open()
            sendClicked()
        }

        onRejected: {
            cancelClicked()
        }

    }

    Component.onCompleted: {
        sheet.open()
    }
}
