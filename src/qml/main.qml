import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window{
    id: root
    width: 1000
    height: 600
    visible: true

    function printParticlesPostions() {
        let list = qtInterface.getParticlesPostions();
        particlesPositionBox.clear();
        for (let i = 0; i < list.length; i++) {
            particlesPositionBox.append("particle " + i + " in position " + list[i])
        }
    }

    Column {
        anchors.fill: parent
        Item {
            width: root.width
            height: root.height / 2

            Column {
                anchors.fill: parent

                Canvas {
                    id: mycanvas

                    height: parent.height / 2

                    function clear() {
                        var ctx = getContext("2d");
                        ctx.reset();
                        mycanvas.requestPaint();
                    }

                    property real particleRadius: 3
                    property real robotRadius: 12
                    property var particlesList : []
                    property int robotPosition: 0
                    anchors.right: parent.right
                    anchors.left: parent.left

                    onPaint: {
                        particlesList = qtInterface.getParticlesPostions();
                        robotPosition = qtInterface.getRobotPosition();
                        var ctx = getContext("2d");
                        ctx.save()
                        if(particlesList.length > 0){
                            for(var i=0; i < particlesList.length; i++){
                                var point= particlesList[i]
                                ctx.ellipse(point-particleRadius, 100-particleRadius, 2*particleRadius, 2*particleRadius)
                            }
                            ctx.ellipse(robotPosition-robotRadius, 100-robotRadius, 2*robotRadius, 2*robotRadius)
                            ctx.strokeStyle = Qt.rgba(255, 1, 1, 0)
                            ctx.fill()
                            ctx.stroke()
                        }
                        context.restore()
                        printParticlesPostions();
                        robotPositionLable.text = "Robot is in position: " + qtInterface.getRobotPosition();
                        let mean = qtInterface.getMeanValue();
                        meanValueLable.text = "Mean Value: " + mean;
                        varianceValueLable.text = "Variance value: " + qtInterface.getVariance(mean);
                    }
                }

                Canvas {
                    id: mycanvas2

                    height: parent.height / 2

                    property real radius: 1
                    property var list : []
                    anchors.right: parent.right
                    anchors.left: parent.left

                    onPaint: {
                        list = qtInterface.getHeatList();
                        var ctx = getContext("2d");
                        var cw = parent.width;
                        var ch = parent.height;
                        ctx.lineWidth = 2;
                        var amplitude = height

                        ctx.beginPath();
                        for (var x = 0; x < list.length; x++) {
                            ctx.lineTo(x, -list[x] / 2.6 * amplitude / 2 + amplitude / 2);
                        }
                        ctx.stroke();
                    }
                }
            }
        }

        Item {
            width: parent.width
            height: parent.height / 2

            Row {
                id: row
                anchors.fill: parent

                Flickable {
                    id: flickable
                    height: parent.height
                    width: 200

                    TextArea.flickable: TextArea {
                        id: particlesPositionBox
                    }

                    ScrollBar.vertical: ScrollBar { }
                }

                Item {
                    width: 200
                    height: parent.height

                    Column {
                        anchors.fill: parent
                        Button {
                            width: 200
                            height: 50
                            text: "Next step"
                            onClicked: {
                                qtInterface.moveOneStep();
                                mycanvas.clear();
                                mycanvas.requestPaint();
                            }
                        }
                        Label {
                            id: robotPositionLable
                        }
                        Label {
                            id: meanValueLable
                        }
                        Label {
                            id: varianceValueLable
                        }
                    }
                }
            }
        }
    }


}//Window

/*##^##
Designer {
    D{i:10;anchors_height:400;anchors_width:200;anchors_x:0;anchors_y:300}D{i:1;anchors_height:500;anchors_width:500}
}
##^##*/
