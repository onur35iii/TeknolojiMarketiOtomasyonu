#ifndef TMOSATISFATURASIYONETICISI_H
#define TMOSATISFATURASIYONETICISI_H

#include <QObject>
#include <QObject>
#include <veriler/TANIMLAR.h>
#include<veriler/veri_yoneticileri/temelveriyoneticisi.h>

class TMOSatisFaturasiYoneticisi : public QObject, public TemelVeriYoneticisi<TMOSatisFaturasi,TMOSatisFaturasiPtr>
{
    Q_OBJECT
public:
    explicit TMOSatisFaturasiYoneticisi(QObject *parent = nullptr);
 Ptr kopyaOlustur(Ptr kaynak)const;
signals:

};

#endif // TMOSATISFATURASIYONETICISI_H
