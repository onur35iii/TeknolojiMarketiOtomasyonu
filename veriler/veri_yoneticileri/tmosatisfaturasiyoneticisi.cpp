#include "tmosatisfaturasiyoneticisi.h"
#include <veriler/veri_siniflari/tmosatisfaturasi.h>
TMOSatisFaturasiYoneticisi::TMOSatisFaturasiYoneticisi(QObject *parent) : QObject(parent)
{
}

TMOSatisFaturasiYoneticisi::Ptr TMOSatisFaturasiYoneticisi::kopyaOlustur(TemelVeriYoneticisi::Ptr kaynak) const
{

    Ptr kopya= yeni();
    kopya->setId(kaynak->getId());
    kopya->setParcaSatisFaturaNo(kaynak->getParcaSatisFaturaNo());
    kopya->setParcaSatisTarihi(kaynak->getParcaSatisTarihi());
    return kopya;
}
