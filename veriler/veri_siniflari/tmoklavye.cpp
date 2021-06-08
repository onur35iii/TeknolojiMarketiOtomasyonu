#include "tmoklavye.h"

TMOKlavye::TMOKlavye(QObject *parent) : QObject(parent)
{

}

Idturu TMOKlavye::getId() const
{
    return KlavyeId;
}

void TMOKlavye::setId(const Idturu &value)
{
    if(value==KlavyeId)
        return;
    KlavyeId = value;
    emit IdDegisti(KlavyeId);
}

Metin TMOKlavye::getKlavyeAdi() const
{
    return KlavyeAdi;
}

void TMOKlavye::setKlavyeAdi(const Metin &value)
{
    if(value==KlavyeAdi)
        return;
    KlavyeAdi = value;
    emit KlavyeAdiDegisti(KlavyeAdi);
}

Metin TMOKlavye::getKlavyeModelNo() const
{
    return KlavyeModelNo;
}

void TMOKlavye::setKlavyeModelNo(const Metin &value)
{
    if(value==KlavyeModelNo)
        return;
    KlavyeModelNo = value;
    emit KlavyeModelNoDegisti(KlavyeModelNo);
}

Metin TMOKlavye::getKlavyeTuru() const
{
    return KlavyeTuru;
}

void TMOKlavye::setKlavyeTuru(const Metin &value)
{
    if(value==KlavyeTuru)
        return;
    KlavyeTuru = value;
    emit KlavyeTuruDegisti(KlavyeTuru);
}

Metin TMOKlavye::getKlavyeRenk() const
{
    return KlavyeRenk;
}

void TMOKlavye::setKlavyeRenk(const Metin &value)
{
    if(value==KlavyeRenk)
        return;
    KlavyeRenk = value;
    emit KlavyeRenkDegisti(KlavyeRenk);
}
QDataStream &operator<<(QDataStream &stream, const TMOKlavyePtr &veri){
    stream << veri->getId()<<veri->getKlavyeAdi()<<veri->getKlavyeModelNo()<<veri->getKlavyeTuru()<<veri->getKlavyeRenk();
    return stream;
}
QDataStream &operator>>(QDataStream &stream, TMOKlavyePtr &veri){
    Idturu KlavyeId;
    Metin KlavyeAdi;
    Metin KlavyeModelNo;
    Metin KlavyeTuru;
    Metin KlavyeRenk;
    stream >> KlavyeId>>KlavyeAdi>>KlavyeModelNo>>KlavyeTuru>>KlavyeRenk;
    veri=std::make_shared<TMOKlavye>();
    veri->setId(KlavyeId);
    veri->setKlavyeAdi(KlavyeAdi);
    veri->setKlavyeModelNo(KlavyeModelNo);
    veri->setKlavyeTuru(KlavyeTuru);
    veri->setKlavyeRenk(KlavyeRenk);
    return stream;
}
