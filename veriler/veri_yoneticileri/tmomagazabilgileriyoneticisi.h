#ifndef TMOMAGAZABILGILERIYONETICISI_H
#define TMOMAGAZABILGILERIYONETICISI_H

#include <QObject>
#include <QObject>
#include <veriler/TANIMLAR.h>
#include<veriler/veri_yoneticileri/temelveriyoneticisi.h>

class TMOMagazaBilgileriYoneticisi : public QObject, public TemelVeriYoneticisi<TMOMagazaBilgileri,TMOMagazaBilgileriPtr>
{
    Q_OBJECT
public:
    explicit TMOMagazaBilgileriYoneticisi(QObject *parent = nullptr);
 Ptr kopyaOlustur(Ptr kaynak)const;
signals:

};

#endif // TMOMAGAZABILGILERIYONETICISI_H
