#ifndef TMOTOPLAMABILGISAYARSATISFATURASIYONETICISI_H
#define TMOTOPLAMABILGISAYARSATISFATURASIYONETICISI_H

#include <QObject>
#include <QObject>
#include <veriler/TANIMLAR.h>
#include<veriler/veri_yoneticileri/temelveriyoneticisi.h>

class TMOToplamaBilgisayarSatisFaturasiYoneticisi : public QObject, public TemelVeriYoneticisi<TMOToplamaBilgisayarSatisFaturasi,TMOToplamaBilgisayarSatisFaturasiPtr>
{
    Q_OBJECT
public:
    explicit TMOToplamaBilgisayarSatisFaturasiYoneticisi(QObject *parent = nullptr);
 Ptr kopyaOlustur(Ptr kaynak)const;
signals:

};

#endif // TMOTOPLAMABILGISAYARSATISFATURASIYONETICISI_H
