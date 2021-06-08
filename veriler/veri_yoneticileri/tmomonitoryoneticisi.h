#ifndef TMOMONITORYONETICISI_H
#define TMOMONITORYONETICISI_H

#include <QObject>
#include <QObject>
#include <veriler/TANIMLAR.h>
#include<veriler/veri_yoneticileri/temelveriyoneticisi.h>

class TMOMonitorYoneticisi : public QObject, public TemelVeriYoneticisi<TMOMonitor,TMOMonitorPtr>
{
    Q_OBJECT
public:
    explicit TMOMonitorYoneticisi(QObject *parent = nullptr);
 Ptr kopyaOlustur(Ptr kaynak)const;
signals:

};

#endif // TMOMONITORYONETICISI_H
