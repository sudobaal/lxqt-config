#include "backlightsettings.h"
#include <QMessageBox>
#include <QDebug>

BacklightSettings::BacklightSettings(QWidget *parent) :
    QDialog(parent)
{
    ui = new Ui::BacklightSettings();
    ui->setupUi(this);
    mDbusKbdBacklight = new QDBusInterface("org.freedesktop.UPower", "/org/freedesktop/UPower/KbdBacklight", "org.freedesktop.UPower.KbdBacklight", QDBusConnection::systemBus());
    if (!mDbusKbdBacklight->isValid())
    {
        QMessageBox errorMsg;
        errorMsg.critical(this, "Error", "An error occured during the connection to DBus");
        errorMsg.show();
        close();
    }
    QDBusMessage msg = mDbusKbdBacklight->call("GetMaxBrightness");
    int maxBrightness = msg.arguments().at(0).toInt();
    msg = mDbusKbdBacklight->call("GetBrightness");
    int currentBrightness = msg.arguments().at(0).toInt();
    ui->backlightSlider->setRange(0,maxBrightness);
    ui->backlightSlider->setValue(currentBrightness);
}

void BacklightSettings::setBacklight(int val)
{
    QDBusMessage msg = mDbusKbdBacklight->call("SetBrightness", QVariant(val));
}
    
