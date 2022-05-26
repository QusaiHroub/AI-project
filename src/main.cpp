
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "particle.hpp"
#include "utilities.hpp"
#include "robot.hpp"
#include "qtinterface.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    const int DEFAULT_PARTICLES_NUMBER = 45;

    //list contain the particles of robot
    vector<Particle> particlesList;

    //Array Contain the temperature for every point  on robot path
    double arr[1000] = {};

    Robot robot(arr, 1000);

    // calculate the average of temperature
    double avg = utilities::getTempForAllPositions(arr);

    double standardDeviation = utilities::getStandardDeviation(arr, avg);
    int numberOfRandomParticles = DEFAULT_PARTICLES_NUMBER;
	
	//function to  select random particles
    utilities::getRandomParticles(particlesList, arr, robot.getRobotPosition(), avg, standardDeviation, numberOfRandomParticles);

    QtInterface qtInterface(arr, 1000, &robot, particlesList, avg, standardDeviation);

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    engine.rootContext()->setContextProperty("qtInterface", &qtInterface);

    return app.exec();
}