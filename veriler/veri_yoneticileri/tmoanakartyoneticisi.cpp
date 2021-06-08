#include "tmoanakartyoneticisi.h"
#include <veriler/veri_siniflari/tmoanakart.h>
TMOAnakartYoneticisi::TMOAnakartYoneticisi(QObject *parent) : QObject(parent)
{

}

TMOAnakartYoneticisi::Ptr TMOAnakartYoneticisi::kopyaOlustur(TemelVeriYoneticisi::Ptr kaynak) const
{
 Ptr kopya= yeni();
 kopya->setId(kaynak->getId());
 kopya->setAnakartAdi(kaynak->getAnakartAdi());
 kopya->setAnakartBoyutu(kaynak->getAnakartBoyutu());
 kopya->setAnakartChipseti(kaynak->getAnakartChipseti());
 kopya->setAnakartModelNo(kaynak->getAnakartModelNo());
 kopya->setAnakartRamTipi(kaynak->getAnakartRamTipi());
 kopya->setAnakartSoketTipi(kaynak->getAnakartSoketTipi());
 kopya->setAnakartVgaSlotu(kaynak->getAnakartVgaSlotu());
 return kopya;
}

