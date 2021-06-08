#include "tmomagazabilgileriyoneticisi.h"
#include <veriler/veri_siniflari/tmomagazabilgileri.h>
TMOMagazaBilgileriYoneticisi::TMOMagazaBilgileriYoneticisi(QObject *parent) : QObject(parent)
{

}

TMOMagazaBilgileriYoneticisi::Ptr TMOMagazaBilgileriYoneticisi::kopyaOlustur(TemelVeriYoneticisi::Ptr kaynak) const
{
    Ptr kopya= yeni();
    kopya->setId(kaynak->getId());
    kopya->setMagazaAdi(kaynak->getMagazaAdi());
    kopya->setMagazaAdresi(kaynak->getMagazaAdi());
    kopya->setMagazaTelefonu(kaynak->getMagazaTelefonu());
    kopya->setMagazaYetkilisi(kaynak->getMagazaYetkilisi());
    return kopya;
}
