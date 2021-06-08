#ifndef TMOANAKARTYONETICISI_H
#define TMOANAKARTYONETICISI_H

#include <QObject>
#include <veriler/TANIMLAR.h>
#include<veriler/veri_yoneticileri/temelveriyoneticisi.h>
class TMOAnakartYoneticisi : public QObject, public TemelVeriYoneticisi<TMOAnakart,TMOAnakartPtr>
{
    Q_OBJECT
public:
    explicit TMOAnakartYoneticisi(QObject *parent = nullptr);
 Ptr kopyaOlustur(Ptr kaynak)const;
signals:

};

#endif // TMOANAKARTYONETICISI_H
