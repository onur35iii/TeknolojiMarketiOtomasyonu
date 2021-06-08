#include "tmotedarikcibilgileriyoneticisi.h"
#include <veriler/veri_siniflari/tmotedarikcibilgileri.h>
TMOTedarikciBilgileriYoneticisi::TMOTedarikciBilgileriYoneticisi(QObject *parent) : QObject(parent)
{

}

TMOTedarikciBilgileriYoneticisi::Ptr TMOTedarikciBilgileriYoneticisi::kopyaOlustur(TemelVeriYoneticisi::Ptr kaynak) const
{
    Ptr kopya= yeni();
    kopya->setId(kaynak->getId());
    kopya->setTedarikciAdi(kaynak->getTedarikciAdi());
    kopya->setTedarikciAdresi(kaynak->getTedarikciAdresi());
    kopya->setTedarikciTelefonNo(kaynak->getTedarikciTelefonNo());
    kopya->setTedarikciYetkiliKisi(kaynak->getTedarikciYetkiliKisi());
    return kopya;
}
