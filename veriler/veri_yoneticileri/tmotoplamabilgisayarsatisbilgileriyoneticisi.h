#ifndef TMOTOPLAMABILGISAYARSATISBILGILERIYONETICISI_H
#define TMOTOPLAMABILGISAYARSATISBILGILERIYONETICISI_H

#include <QObject>
#include <QObject>
#include <veriler/TANIMLAR.h>
#include<veriler/veri_yoneticileri/temelveriyoneticisi.h>

class TMOToplamaBilgisayarSatisBilgileriYoneticisi : public QObject, public TemelVeriYoneticisi<TMOToplamaBilgisayarSatisBilgileri,TMOToplamaBilgisayarSatisBilgileriPtr>
{
    Q_OBJECT
public:
    explicit TMOToplamaBilgisayarSatisBilgileriYoneticisi(QObject *parent = nullptr);
 Ptr kopyaOlustur(Ptr kaynak)const;
signals:

};

#endif // TMOTOPLAMABILGISAYARSATISBILGILERIYONETICISI_H
