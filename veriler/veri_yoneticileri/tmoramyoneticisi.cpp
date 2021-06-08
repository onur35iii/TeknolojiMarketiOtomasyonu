#include "tmoramyoneticisi.h"
#include <veriler/veri_siniflari/tmoram.h>
TMORAMYoneticisi::TMORAMYoneticisi(QObject *parent) : QObject(parent)
{

}

TMORAMYoneticisi::Ptr TMORAMYoneticisi::kopyaOlustur(TemelVeriYoneticisi::Ptr kaynak) const
{
    Ptr kopya= yeni();
    kopya->setId(kaynak->getId());
    kopya->setRamAdi(kaynak->getRamAdi());
    kopya->setRamBushizi(kaynak->getRamBushizi());
    kopya->setRamGecikmeSuresi(kaynak->getRamGecikmeSuresi());
    kopya->setRamKapasitesi(kaynak->getRamKapasitesi());
    kopya->setRamModelNo(kaynak->getRamModelNo());
    return kopya;
}
