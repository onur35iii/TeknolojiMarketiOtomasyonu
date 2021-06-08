#ifndef TMOGPUYONETICISI_H
#define TMOGPUYONETICISI_H

#include <QObject>
#include <QObject>
#include <veriler/TANIMLAR.h>
#include<veriler/veri_yoneticileri/temelveriyoneticisi.h>

class TMOGPUYoneticisi : public QObject, public TemelVeriYoneticisi<TMOGPU,TMOGPUPtr>
{
    Q_OBJECT
public:
    explicit TMOGPUYoneticisi(QObject *parent = nullptr);
 Ptr kopyaOlustur(Ptr kaynak)const;
signals:

};

#endif // TMOGPUYONETICISI_H
