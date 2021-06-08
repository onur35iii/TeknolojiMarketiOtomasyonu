#include "tmotoplamabilgisayarsatisfaturasiyoneticisi.h"
#include <veriler/veri_siniflari/tmotoplamabilgisayarsatisfaturasi.h>
TMOToplamaBilgisayarSatisFaturasiYoneticisi::TMOToplamaBilgisayarSatisFaturasiYoneticisi(QObject *parent) : QObject(parent)
{

}

TMOToplamaBilgisayarSatisFaturasiYoneticisi::Ptr TMOToplamaBilgisayarSatisFaturasiYoneticisi::kopyaOlustur(TemelVeriYoneticisi::Ptr kaynak) const
{
    Ptr kopya= yeni();
    kopya->setId(kaynak->getId());
    kopya->setToplamaPCSatisFaturaNo(kaynak->getToplamaPCSatisFaturaNo());
    kopya->setToplamaPCSatisFaturaTarihi(kaynak->getToplamaPCSatisFaturaTarihi());
    return kopya;
}
