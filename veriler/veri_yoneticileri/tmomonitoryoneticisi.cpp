#include "tmomonitoryoneticisi.h"
#include <veriler/veri_siniflari/tmomonitor.h>
TMOMonitorYoneticisi::TMOMonitorYoneticisi(QObject *parent) : QObject(parent)
{

}

TMOMonitorYoneticisi::Ptr TMOMonitorYoneticisi::kopyaOlustur(TemelVeriYoneticisi::Ptr kaynak) const
{
    Ptr kopya= yeni();
    kopya->setId(kaynak->getId());
    kopya->setMonitorBoyutu(kaynak->getMonitorBoyutu());
    kopya->setMonitorCozunurluk(kaynak->getMonitorCozunurluk());
    kopya->setMonitorHDMIBaglantiSayisi(kaynak->getMonitorCozunurluk());
    kopya->setMonitorModelNo(kaynak->getMonitorModelNo());
    kopya->setMonitorRenk(kaynak->getMonitorRenk());
    kopya->setMonitorYenilemeHizi(kaynak->getMonitorYenilemeHizi());
    return kopya;
}
