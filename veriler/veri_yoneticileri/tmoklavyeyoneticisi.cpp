#include "tmoklavyeyoneticisi.h"
#include <veriler/veri_siniflari/tmoklavye.h>
TMOKlavyeYoneticisi::TMOKlavyeYoneticisi(QObject *parent) : QObject(parent)
{

}

TMOKlavyeYoneticisi::Ptr TMOKlavyeYoneticisi::kopyaOlustur(TemelVeriYoneticisi::Ptr kaynak) const
{
    Ptr kopya= yeni();
    kopya->setId(kaynak->getId());
    kopya->setKlavyeAdi(kaynak->getKlavyeAdi());
    kopya->setKlavyeModelNo(kaynak->getKlavyeModelNo());
    kopya->setKlavyeRenk(kaynak->getKlavyeRenk());
    kopya->setKlavyeTuru(kaynak->getKlavyeTuru());

    return kopya;
}

