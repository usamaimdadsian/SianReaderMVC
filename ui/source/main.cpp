#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <controllers/master_controller.h>
#include <controllers/command_controller.h>


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterType<sianreader::controllers::MasterController>("SianReader",1,0, "MasterController");
    qmlRegisterType<sianreader::controllers::ViewType>("SianReader",1,0,"ViewType");
    qmlRegisterType<sianreader::controllers::NavigationController>("SianReader",1,0,"NavigationController");
    qmlRegisterType<sianreader::controllers::CommandController>("CM", 1, 0,"CommandController");
    qmlRegisterType<sianreader::framework::Command>("CM", 1, 0, "Command");

    sianreader::controllers::MasterController masterController;

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/");
    engine.rootContext()->setContextProperty("masterController",&masterController);
    const QUrl url(QStringLiteral("qrc:/views/MasterView.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
