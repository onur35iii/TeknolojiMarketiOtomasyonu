#ifndef TMOTOPLAMABILGISAYARSATISFATURASI_H
#define TMOTOPLAMABILGISAYARSATISFATURASI_H

#include <QObject>
#include <veriler/TANIMLAR.h>

class TMOToplamaBilgisayarSatisFaturasi : public QObject
{
    Q_OBJECT
public:
    explicit TMOToplamaBilgisayarSatisFaturasi(QObject *parent = nullptr);

    Q_PROPERTY(Idturu ToplamaPCSatisFaturaId READ getId WRITE setId NOTIFY IdDegisti)
    Q_PROPERTY(Tarih ToplamaPCSatisFaturaTarihi READ getToplamaPCSatisFaturaTarihi WRITE setToplamaPCSatisFaturaTarihi NOTIFY ToplamaPCSatisFaturaTarihiDegisti)
    Q_PROPERTY(Tamsayi ToplamaPCSatisFaturaNo READ getToplamaPCSatisFaturaNo WRITE setToplamaPCSatisFaturaNo NOTIFY ToplamaPCSatisFaturaNoDegisti)
    Idturu getId() const;
    Tarih getToplamaPCSatisFaturaTarihi() const;
    Tamsayi getToplamaPCSatisFaturaNo() const;


signals:
    void IdDegisti(const Idturu &value);
    void ToplamaPCSatisFaturaTarihiDegisti(const Tarih &value);
    void ToplamaPCSatisFaturaNoDegisti(const Tamsayi &value);
public slots:
    void setId(const Idturu &value);
    void setToplamaPCSatisFaturaTarihi(const Tarih &value);
    void setToplamaPCSatisFaturaNo(const Tamsayi &value);
private:
    Idturu ToplamaPCSatisFaturaId;
    Tarih ToplamaPCSatisFaturaTarihi;
    Tamsayi ToplamaPCSatisFaturaNo;


};
QDataStream &operator<<(QDataStream &stream, const TMOToplamaBilgisayarSatisFaturasiPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOToplamaBilgisayarSatisFaturasiPtr &veri);
#endif // TMOTOPLAMABILGISAYARSATISFATURASI_H
