#ifndef TMOKASAYONETICISI_H
#define TMOKASAYONETICISI_H

#include <QObject>
#include <QObject>
#include <veriler/TANIMLAR.h>
#include<veriler/veri_yoneticileri/temelveriyoneticisi.h>

class TMOKasaYoneticisi : public QObject, public TemelVeriYoneticisi<TMOKasa,TMOKasaPtr>
{
    Q_OBJECT
public:
    explicit TMOKasaYoneticisi(QObject *parent = nullptr);
 Ptr kopyaOlustur(Ptr kaynak)const;
signals:

};

#endif // TMOKASAYONETICISI_H
