#include "tmosatisbilgileriyoneticisi.h"
#include <veriler/veri_siniflari/tmosatisbilgileri.h>
TMOSatisBilgileriYoneticisi::TMOSatisBilgileriYoneticisi(QObject *parent) : QObject(parent)
{

}

TMOSatisBilgileriYoneticisi::Ptr TMOSatisBilgileriYoneticisi::kopyaOlustur(TemelVeriYoneticisi::Ptr kaynak) const
{
    Ptr kopya= yeni();
    kopya->setId(kaynak->getId());
    kopya->setParcaSatisFiyati(kaynak->getParcaSatisFiyati());
    kopya->setParcaSatisMiktari(kaynak->getParcaSatisMiktari());
    return kopya;
}
