#include "tmoanapencere.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TMOAnaPencere w;
    w.show();
    return a.exec();
}

#include <veriler/veri_siniflari/tmoalisbilgileri.h>
#include <veriler/veri_siniflari/tmoalisfaturasi.h>
#include <veriler/veri_yoneticileri/tmoalisbilgileriyoneticisi.h>
#include <veriler/veri_yoneticileri/tmoalisfaturasiyoneticisi.h>
#include<QDir>
#include<QFile>
#include<QDataStream>
#include<QTextStream>

//git

void deneme()
{
    /*TMOAlisBilgileriYoneticisi yonetici;
    auto yeni= yonetici.yeni();

    yeni->setAlisFiyati(50);
    yeni->setAlisMiktari(100);
    yonetici.ekle(yeni);
    yeni=yonetici.yeni();

    yeni->setAlisFiyati(150);
    yeni->setAlisMiktari(10);
    yonetici.ekle(yeni);
    yeni=yonetici.yeni();


    auto alis=yonetici.ilkiniBul([](TMOAlisBilgileriPtr i){return i->getAlisFiyati()==50;});

    TMOAlisFaturasiYoneticisi yonetici1;
    auto yenialisfaturasi=yonetici1.yeni();

    yenialisfaturasi->setId(1);
     yonetici1.ekle(yenialisfaturasi);


     QFile dosya("veri.isbb");
     if(dosya.open(QIODevice::WriteOnly))
     {
         QDataStream dosya_yaz(&dosya);
          dosya_yaz << yeni;
             dosya.close();
     }
    QFile dosya1("veri.isbb");
    {
        if(dosya1.open(QIODevice::ReadOnly))
        {
            QDataStream dosya_oku(&dosya1);
            dosya_oku >> yeni;

        }
    }
*/
}
