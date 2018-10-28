#include <QApplication>
#include <LXQt/SingleApplication>
#include <QCommandLineParser>
#include "backlightsettings.h"

int main(int argn, char *argv[])
{
    LXQt::SingleApplication app(argn, argv);
    app.setAttribute(Qt::AA_UseHighDpiPixmaps, true);

    // Command line options
    QCommandLineParser parser;
    parser.setApplicationDescription(QStringLiteral("LXQt Config Brightness"));
    const QString VERINFO = QStringLiteral(LXQT_CONFIG_VERSION
                                           "\nliblxqt   " LXQT_VERSION
                                           "\nQt        " QT_VERSION_STR);
    app.setApplicationVersion(VERINFO);
    
    parser.addVersionOption();

    BacklightSettings *backlightsettings = new BacklightSettings();
    backlightsettings->setWindowIcon(QIcon(ICON_DIR "/brightnesssettings.svg"));
    backlightsettings->show();

    return app.exec();
}

