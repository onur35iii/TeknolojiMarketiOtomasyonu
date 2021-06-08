#include "tmoalisbilgileriyoneticisi.h"
#include <veriler/veri_siniflari/tmoalisbilgileri.h>
TMOAlisBilgileriYoneticisi::TMOAlisBilgileriYoneticisi(QObject *parent) : QObject(parent) , TemelVeriYoneticisi <TMOAlisBilgileri,TMOAlisBilgileriPtr>()

{

}

TMOAlisBilgileriYoneticisi::Ptr TMOAlisBilgileriYoneticisi::KopyaOlustur(TMOAlisBilgileriYoneticisi::Ptr Kaynak) const
{
 Ptr kopya =yeni();
 kopya ->setId(Kaynak->getId());
 kopya-> setAlisFiyati(Kaynak->getAlisFiyati());
 kopya->setAlisMiktari(Kaynak->getAlisMiktari());
 return kopya;
}













