#include "tmokasayoneticisi.h"
#include <veriler/veri_siniflari/tmokasa.h>
TMOKasaYoneticisi::TMOKasaYoneticisi(QObject *parent) : QObject(parent)
{

}

TMOKasaYoneticisi::Ptr TMOKasaYoneticisi::kopyaOlustur(TemelVeriYoneticisi::Ptr kaynak) const
{
    Ptr kopya= yeni();
kopya->setId(kaynak->getId());
kopya->setKasaAdi(kaynak->getKasaAdi());
kopya->setKasaAnakartYapisi(kaynak->getKasaAnakartYapisi());
kopya->setKasaBoyutu(kaynak->getKasaBoyutu());
kopya->setKasaFanSayisi(kaynak->getKasaFanSayisi());
kopya->setKasaGucKaynagivarmi(kaynak->getKasaGucKaynagivarmi());
kopya->setKasaModelNo(kaynak->getKasaModelNo());
kopya->setKasaRenk(kaynak->getKasaRenk());
    return kopya;
}
