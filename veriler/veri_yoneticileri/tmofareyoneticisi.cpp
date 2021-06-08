#include "tmofareyoneticisi.h"
#include <veriler/veri_siniflari/tmofare.h>
TMOFareYoneticisi::TMOFareYoneticisi(QObject *parent) : QObject(parent)
{

}

TMOFareYoneticisi::Ptr TMOFareYoneticisi::kopyaOlustur(TemelVeriYoneticisi::Ptr kaynak) const
{
    Ptr kopya= yeni();
    kopya->setId(kaynak->getId());
    kopya->setFareAdi(kaynak->getFareAdi());
    kopya->setFareBaglantiTuru(kaynak->getFareBaglantiTuru());
    kopya->setFareDPI(kaynak->getFareDPI());
    kopya->setFareModeli(kaynak->getFareModeli());
    kopya->setFareRenk(kaynak->getFareRenk());
    return kopya;
}
