#include "tmotoplamabilgisayarsatisbilgileriyoneticisi.h"
#include <veriler/veri_siniflari/tmotoplamabilgisayarsatisbilgileri.h>
TMOToplamaBilgisayarSatisBilgileriYoneticisi::TMOToplamaBilgisayarSatisBilgileriYoneticisi(QObject *parent) : QObject(parent)
{
}

TMOToplamaBilgisayarSatisBilgileriYoneticisi::Ptr TMOToplamaBilgisayarSatisBilgileriYoneticisi::kopyaOlustur(TemelVeriYoneticisi::Ptr kaynak) const
{

    Ptr kopya= yeni();
    kopya->setId(kaynak->getId());
    kopya->setToplamaPCSatisFiyati(kaynak->getToplamaPCSatisFiyati());
    kopya->setToplamaPCSatisMiktari(kaynak->getToplamaPCSatisMiktari());
    return kopya;
}
