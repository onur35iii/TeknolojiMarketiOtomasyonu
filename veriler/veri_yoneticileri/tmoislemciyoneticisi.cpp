#include "tmoislemciyoneticisi.h"
#include <veriler/veri_siniflari/tmoislemci.h>
TMOIslemciYoneticisi::TMOIslemciYoneticisi(QObject *parent) : QObject(parent)
{

}

TMOIslemciYoneticisi::Ptr TMOIslemciYoneticisi::kopyaOlustur(TemelVeriYoneticisi::Ptr kaynak) const
{
    Ptr kopya= yeni();
    kopya->setId(kaynak->getId());
    kopya->setIslemciAdi(kaynak->getIslemciAdi());
    kopya->setIslemciBellekTuru(kaynak->getIslemciBellekTuru());
    kopya->setIslemciCekirdekSayisi(kaynak->getIslemciCekirdekSayisi());
    kopya->setIslemciEntegreGPUvarmi(kaynak->getIslemciEntegreGPUvarmi());
    kopya->setIslemciGucTuketimi(kaynak->getIslemciGucTuketimi());
    kopya->setIslemciHizi(kaynak->getIslemciHizi());
    kopya->setIslemciModelNo(kaynak->getIslemciModelNo());
    return kopya;
}
