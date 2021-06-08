#include "tmomonitor.h"

TMOMonitor::TMOMonitor(QObject *parent) : QObject(parent)
{

}

Idturu TMOMonitor::getId() const
{
    return MonitorId;
}

void TMOMonitor::setId(const Idturu &value)
{
    if(value==MonitorId)
        return;
    MonitorId = value;
    emit IdDegisti(MonitorId);

}

Metin TMOMonitor::getMonitorModelNo() const
{
    return MonitorModelNo;
}

void TMOMonitor::setMonitorModelNo(const Metin &value)
{
    if(value==MonitorModelNo)
        return;
    MonitorModelNo = value;
    emit MonitorModelNoDegisti(MonitorModelNo);
}

Tamsayi TMOMonitor::getMonitorHDMIBaglantiSayisi() const
{
    return MonitorHDMIBaglantiSayisi;
}

void TMOMonitor::setMonitorHDMIBaglantiSayisi(const Tamsayi &value)
{
    if(value==MonitorHDMIBaglantiSayisi)
        return;
    MonitorHDMIBaglantiSayisi = value;
    emit MonitorHDMIBaglantiSayisiDegisti(MonitorHDMIBaglantiSayisi);
}

Tamsayi TMOMonitor::getMonitorYenilemeHizi() const
{
    return MonitorYenilemeHizi;
}

void TMOMonitor::setMonitorYenilemeHizi(const Tamsayi &value)
{
    if(value==MonitorYenilemeHizi)
        return;
    MonitorYenilemeHizi = value;
    emit MonitorYenilemeHiziDegisti(MonitorYenilemeHizi);
}

Tamsayi TMOMonitor::getMonitorBoyutu() const
{
    return MonitorBoyutu;
}

void TMOMonitor::setMonitorBoyutu(const Tamsayi &value)
{
    if(value==MonitorBoyutu)
        return;
    MonitorBoyutu = value;
    emit MonitorBoyutuDegisti(MonitorBoyutu);
}

Tamsayi TMOMonitor::getMonitorCozunurluk() const
{
    return MonitorCozunurluk;
}

void TMOMonitor::setMonitorCozunurluk(const Tamsayi &value)
{
    if(value==MonitorCozunurluk)
        return;
    MonitorCozunurluk = value;
    emit MonitorCozunurlukDegisti(MonitorCozunurluk);
}

Metin TMOMonitor::getMonitorRenk() const
{
    return MonitorRenk;
}

void TMOMonitor::setMonitorRenk(const Metin &value)
{
    if(value==MonitorRenk)
        return;
    MonitorRenk = value;
    emit MonitorRenkDegisti(MonitorRenk);
}
QDataStream &operator<<(QDataStream &stream, const TMOMonitorPtr &veri){
    stream << veri->getId()<<veri->getMonitorModelNo()<<veri->getMonitorHDMIBaglantiSayisi()<<veri->getMonitorYenilemeHizi()<<veri->getMonitorBoyutu()<<veri->getMonitorCozunurluk()<<veri->getMonitorRenk();
    return stream;
}
QDataStream &operator>>(QDataStream &stream, TMOMonitorPtr &veri){
    Idturu MonitorId;
    Metin MonitorModelNo;
    Tamsayi MonitorHDMIBaglantiSayisi;
    Tamsayi MonitorYenilemeHizi;
    Tamsayi MonitorBoyutu;
    Tamsayi MonitorCozunurluk;
    Metin MonitorRenk;
    stream >> MonitorId>>MonitorModelNo>>MonitorHDMIBaglantiSayisi>>MonitorYenilemeHizi>>MonitorBoyutu>>MonitorCozunurluk>>MonitorRenk;
    veri=std::make_shared<TMOMonitor>();
    veri->setId(MonitorId);
    veri->setMonitorModelNo(MonitorModelNo);
    veri->setMonitorHDMIBaglantiSayisi(MonitorHDMIBaglantiSayisi);
    veri->setMonitorYenilemeHizi(MonitorYenilemeHizi);
    veri->setMonitorBoyutu(MonitorBoyutu);
    veri->setMonitorCozunurluk(MonitorCozunurluk);
    veri->setMonitorRenk(MonitorRenk);
    return stream;

}
