#ifndef TMOFAREYONETICISI_H
#define TMOFAREYONETICISI_H

#include <QObject>
#include <QObject>
#include <veriler/TANIMLAR.h>
#include<veriler/veri_yoneticileri/temelveriyoneticisi.h>

class TMOFareYoneticisi : public QObject, public TemelVeriYoneticisi<TMOFare,TMOFarePtr>
{
    Q_OBJECT
public:
    explicit TMOFareYoneticisi(QObject *parent = nullptr);
 Ptr kopyaOlustur(Ptr kaynak)const;
signals:

};

#endif // TMOFAREYONETICISI_H
