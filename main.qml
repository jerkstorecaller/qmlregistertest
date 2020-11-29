import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import MyQmlTypes 1.0




Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    function getRandomInt(min, max) {
      min = Math.ceil(min);
      max = Math.floor(max);
      return Math.floor(Math.random() * (max - min) + min);
    }

    Column {
        Button {
            text: "add adventurer";
            onClicked: {
                console.log("Before:" + GuildManager.adventurers.length);
                GuildManager.addAdventurer("warrior");
                console.log("After:" + GuildManager.adventurers.length);

                //initial task
                var adv = GuildManager.adventurers[0];
                var rnd = getRandomInt(1, 3);
                if (rnd === 1) {
                    adv.startQuesting();
                } else if (rnd === 2){
                    adv.startTrading();
                } else {
                    //idle
                }

                //connect to Adventurer's currentTaskChanged signal, so it's always logging to our textArea
                //?????
            }
        }

        Button {
            text: "Send idle adventurers on jobs";

            onClicked: {
                for (var i = 0; i < GuildManager.adventurers.length; i++) {
                    var adv = GuildManager.adventurers[i];
                    if (adv.currentTask === "") {
                        var rnd = getRandomInt(1, 3);
                        if (rnd === 1) {
                            adv.startQuesting();
                        } else {
                            adv.startTrading();
                        }
                    }
                }
            }
        }

        TextArea {
            id: textArea;
            Component.onCompleted: {
                textArea.append("LOGS GO HERE");
            }
        }

    }
}
