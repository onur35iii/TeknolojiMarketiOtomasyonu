#ifndef TMOGUCKAYNAGIYONETICISI_H
#define TMOGUCKAYNAGIYONETICISI_H

#include <QObject>
#include <QObject>
#include <veriler/TANIMLAR.h>
#include<veriler/veri_yoneticileri/temelveriyoneticisi.h>

class TMOGucKaynagiYoneticisi : public QObject, public TemelVeriYoneticisi<TMOGucKaynagi,TMOGucKaynagiPtr>
{
    Q_OBJECT
public:
    explicit TMOGucKaynagiYoneticisi(QObject *parent = nullptr);
 Ptr kopyaOlustur(Ptr kaynak)const;
signals:

};

#endif // TMOGUCKAYNAGIYONETICISI_H
