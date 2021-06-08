#ifndef TMOALISBILGILERIYONETICISI_H
#define TMOALISBILGILERIYONETICISI_H

#include <QObject>
#include <veriler/TANIMLAR.h>
#include<veriler/veri_yoneticileri/temelveriyoneticisi.h>

class TMOAlisBilgileriYoneticisi : public QObject,
        public TemelVeriYoneticisi <TMOAlisBilgileri,TMOAlisBilgileriPtr>
{
    Q_OBJECT
public:

    explicit TMOAlisBilgileriYoneticisi(QObject *parent = nullptr);
 // 4 Veri Kopya Oluşturma
   Ptr KopyaOlustur(Ptr Kaynak) const;

signals:


};


#endif // TMOALISBILGILERIYONETICISI_H
