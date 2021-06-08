#include "tmogpuyoneticisi.h"
#include <veriler/veri_siniflari/tmogpu.h>
TMOGPUYoneticisi::TMOGPUYoneticisi(QObject *parent) : QObject(parent)
{

}

TMOGPUYoneticisi::Ptr TMOGPUYoneticisi::kopyaOlustur(TemelVeriYoneticisi::Ptr kaynak) const
{
    Ptr kopya= yeni();
    kopya->setId(kaynak->getId());
    kopya->setGPUAdi(kaynak->getGPUAdi());
    kopya->setGPUBellekHizi(kaynak->getGPUBellekHizi());
    kopya->setGPUBoyutu(kaynak->getGPUBoyutu());
    kopya->setGPUModelNo(kaynak->getGPUModelNo());
    kopya->setGPUSlotSayisi(kaynak->getGPUSlotSayisi());
    kopya->setGucTuketimi(kaynak->getGucTuketimi());
    return kopya;
}
