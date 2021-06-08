#ifndef TMOSATISBILGILERIYONETICISI_H
#define TMOSATISBILGILERIYONETICISI_H

#include <QObject>
#include <QObject>
#include <veriler/TANIMLAR.h>
#include<veriler/veri_yoneticileri/temelveriyoneticisi.h>

class TMOSatisBilgileriYoneticisi : public QObject , public TemelVeriYoneticisi<TMOSatisBilgileri,TMOSatisBilgileriPtr>
{
    Q_OBJECT
public:
    explicit TMOSatisBilgileriYoneticisi(QObject *parent = nullptr);
 Ptr kopyaOlustur(Ptr kaynak)const;
signals:

};

#endif // TMOSATISBILGILERIYONETICISI_H
