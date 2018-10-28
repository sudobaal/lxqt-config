#ifndef LXQT_CONFIG_KDB_BACKLIGHT_H
#define LXQT_CONFIG_KDB_BACKLIGHT_H

#include <QDialog>
#include <QtDBus/QDBusInterface>
#include "ui_backlightsettings.h"

class BacklightSettings : public QDialog
{
    Q_OBJECT

public:
    BacklightSettings(QWidget *parent = 0);

public slots:
    void setBacklight(int val);
    
private:
    Ui::BacklightSettings *ui;
    QDBusInterface *mDbusKbdBacklight;
};

#endif // LXQT_CONFIG_KDB_BACKLIGHT_H
