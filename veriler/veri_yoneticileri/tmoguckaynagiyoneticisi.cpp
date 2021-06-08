#include "tmoguckaynagiyoneticisi.h"
#include <veriler/veri_siniflari/tmoguckaynagi.h>
TMOGucKaynagiYoneticisi::TMOGucKaynagiYoneticisi(QObject *parent) : QObject(parent)
{

}

TMOGucKaynagiYoneticisi::Ptr TMOGucKaynagiYoneticisi::kopyaOlustur(TemelVeriYoneticisi::Ptr kaynak) const
{
    Ptr kopya= yeni();
    kopya->setId(kaynak->getId());
    kopya->setGucKaynagiAdi(kaynak->getGucKaynagiAdi());
    kopya->setGucKaynagiDegeri(kaynak->getGucKaynagiDegeri());
    kopya->setGucKaynagiFanBoyutu(kaynak->getGucKaynagiFanBoyutu());
    kopya->setGucKaynagiModelNo(kaynak->getGucKaynagiModelNo());

    return kopya;
}
