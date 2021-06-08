#include "tmohddyoneticisi.h"
#include <veriler/veri_siniflari/tmohdd.h>
TMOHDDYoneticisi::TMOHDDYoneticisi(QObject *parent) : QObject(parent)
{

}

TMOHDDYoneticisi::Ptr TMOHDDYoneticisi::kopyaOlustur(TemelVeriYoneticisi::Ptr kaynak) const
{
    Ptr kopya= yeni();
    kopya->setId(kaynak->getId());
    kopya->setHDDAdi(kaynak->getHDDAdi());
    kopya->setHDDBaglantiArayuzu(kaynak->getHDDBaglantiArayuzu());
    kopya->setHDDBoyutu(kaynak->getHDDBoyutu());
    kopya->setHDDDonusHizi(kaynak->getHDDDonusHizi());
    kopya->setHDDKapasitesi(kaynak->getHDDKapasitesi());
    kopya->setHDDOnbellek(kaynak->getHDDOnbellek());
    return kopya;
}
