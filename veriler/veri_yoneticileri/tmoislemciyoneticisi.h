#ifndef TMOISLEMCIYONETICISI_H
#define TMOISLEMCIYONETICISI_H

#include <QObject>
#include <QObject>
#include <veriler/TANIMLAR.h>
#include<veriler/veri_yoneticileri/temelveriyoneticisi.h>

class TMOIslemciYoneticisi : public QObject, public TemelVeriYoneticisi<TMOIslemci,TMOIslemciPtr>
{
    Q_OBJECT
public:
    explicit TMOIslemciYoneticisi(QObject *parent = nullptr);
 Ptr kopyaOlustur(Ptr kaynak)const;
signals:

};

#endif // TMOISLEMCIYONETICISI_H
