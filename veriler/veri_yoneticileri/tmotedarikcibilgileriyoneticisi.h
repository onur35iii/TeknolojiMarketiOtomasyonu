#ifndef TMOTEDARIKCIBILGILERIYONETICISI_H
#define TMOTEDARIKCIBILGILERIYONETICISI_H

#include <QObject>
#include <QObject>
#include <veriler/TANIMLAR.h>
#include<veriler/veri_yoneticileri/temelveriyoneticisi.h>

class TMOTedarikciBilgileriYoneticisi : public QObject, public TemelVeriYoneticisi<TMOTedarikciBilgileri,TMOTedarikciBilgileriPtr>
{
    Q_OBJECT
public:
    explicit TMOTedarikciBilgileriYoneticisi(QObject *parent = nullptr);
 Ptr kopyaOlustur(Ptr kaynak)const;
signals:

};

#endif // TMOTEDARIKCIBILGILERIYONETICISI_H
