import QtQuick 2.0
import Action_enum 1.0
import QtQuick.Controls 2.12


Item{
    anchors.fill: parent

    Row{
        anchors.fill: parent
        spacing:5
    Rectangle{
        id: first_page
        width: parent.width*0.5
        height: parent.height
        color: nextmousearea.pressed ? "darkred" : "red"
        radius:10
        Text{
            anchors.centerIn: parent
            color:"white"
            text: "Continue"

        }
        MouseArea
        {
            id:nextmousearea
            anchors.fill: parent
            onClicked: {
                Form.update();
                if( formtype.validet_input() )
                {
                formcontent="qrc:/qml/adres_form.qml"
                formcontent_nav="qrc:/qml/last_form_nav.qml"
                }
            }

        }
    }
    Rectangle{
        id: backtologin
        width: parent.width*0.5
        height: parent.height
        color: backtologinarea.pressed ? "darkred" : "red"
        radius:10
        Text{
            fontSizeMode:Text.HorizontalFit
            anchors.centerIn: parent
            color:"white"
            text: "Back To Login"

        }
        MouseArea
        {
            id:backtologinarea
            anchors.fill: parent
            onClicked: {
                formtype.destroy()
                mainpage.source="qrc:/qml/login.qml"
            }
        }

        }
    }
}




