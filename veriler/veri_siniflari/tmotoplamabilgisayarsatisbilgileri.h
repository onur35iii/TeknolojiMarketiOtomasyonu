#ifndef TMOTOPLAMABILGISAYARSATISBILGILERI_H
#define TMOTOPLAMABILGISAYARSATISBILGILERI_H

#include <QObject>
#include <veriler/TANIMLAR.h>

class TMOToplamaBilgisayarSatisBilgileri : public QObject
{
    Q_OBJECT
public:
    explicit TMOToplamaBilgisayarSatisBilgileri(QObject *parent = nullptr);


    Q_PROPERTY(Idturu ToplamaPCId READ getId WRITE setId NOTIFY IdDegisti)
    Q_PROPERTY(Tamsayi ToplamaPCSatisMiktari READ getToplamaPCSatisMiktari WRITE setToplamaPCSatisMiktari NOTIFY ToplamaPCSatisMiktariDegisti)
    Q_PROPERTY(Tamsayi ToplamaPCSatisFiyati READ getToplamaPCSatisFiyati WRITE setToplamaPCSatisFiyati NOTIFY ToplamaPCSatisFiyatiDegisti)

    Idturu getId() const;
    Tamsayi getToplamaPCSatisMiktari() const;
    Tamsayi getToplamaPCSatisFiyati() const;

signals:
    void IdDegisti(const Idturu &value);
    void ToplamaPCSatisMiktariDegisti(const Tamsayi &value);
    void ToplamaPCSatisFiyatiDegisti(const Tamsayi &value);
public slots:
    void setId(const Idturu &value);
    void setToplamaPCSatisMiktari(const Tamsayi &value);
    void setToplamaPCSatisFiyati(const Tamsayi &value);
private:
    Idturu ToplamaPCId;
    Tamsayi ToplamaPCSatisMiktari;
    Tamsayi ToplamaPCSatisFiyati;

};
QDataStream &operator<<(QDataStream &stream, const TMOToplamaBilgisayarSatisBilgileriPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOToplamaBilgisayarSatisBilgileriPtr &veri);
#endif // TMOTOPLAMABILGISAYARSATISBILGILERI_H
