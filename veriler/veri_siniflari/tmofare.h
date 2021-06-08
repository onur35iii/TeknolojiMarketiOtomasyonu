#ifndef TMOFARE_H
#define TMOFARE_H
#include <veriler/TANIMLAR.h>
#include <QObject>

class TMOFare : public QObject
{
    Q_OBJECT
public:
    explicit TMOFare(QObject *parent = nullptr);

    Q_PROPERTY(Idturu FareId READ getId WRITE setId NOTIFY IdDegisti)
    Q_PROPERTY(Metin FareAdi READ getFareAdi WRITE setFareAdi NOTIFY FareAdiDegisti)
    Q_PROPERTY(Metin FareModeli READ getFareModeli WRITE setFareModeli NOTIFY FareModeliDegisti)
    Q_PROPERTY(Metin FareRenk READ getFareRenk WRITE setFareRenk NOTIFY FareRenkDegisti)
    Q_PROPERTY(Tamsayi FareDPI READ getFareDPI WRITE setFareDPI NOTIFY FareDPIDegisti)
    Q_PROPERTY(Metin FareBaglantiTuru READ getFareBaglantiTuru WRITE setFareBaglantiTuru NOTIFY FareBaglantiTuruDegisti)

    Idturu getId() const;
    Metin getFareAdi() const;
    Metin getFareModeli() const;
    Metin getFareRenk() const;
    Tamsayi getFareDPI() const;
    Metin getFareBaglantiTuru() const;


signals:
    void IdDegisti(const Idturu &value);
    void FareAdiDegisti(const Metin &value);
    void FareModeliDegisti(const Metin &value);
    void FareRenkDegisti(const Metin &value);
    void FareDPIDegisti(const Tamsayi &value);
    void FareBaglantiTuruDegisti(const Metin &value);

public slots:
    void setId(const Idturu &value);
    void setFareAdi(const Metin &value);
    void setFareModeli(const Metin &value);
    void setFareRenk(const Metin &value);
    void setFareDPI(const Tamsayi &value);
    void setFareBaglantiTuru(const Metin &value);

private:
    Idturu FareId;
    Metin FareAdi;
    Metin FareModeli;
    Metin FareRenk;
    Tamsayi FareDPI;
    Metin FareBaglantiTuru;


};
QDataStream &operator<<(QDataStream &stream, const TMOFarePtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOFarePtr &veri);
#endif // TMOFARE_H
