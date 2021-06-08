#ifndef TMOHDD_H
#define TMOHDD_H
#include <veriler/TANIMLAR.h>
#include <QObject>

class TMOHDD : public QObject
{
    Q_OBJECT
public:
    explicit TMOHDD(QObject *parent = nullptr);

    Q_PROPERTY(Idturu HDDId READ getId WRITE setId NOTIFY IdDegisti)
    Q_PROPERTY(Metin HDDAdi READ getHDDAdi WRITE setHDDAdi NOTIFY HDDAdiDegisti)
    Q_PROPERTY(Metin HDDBaglantiArayuzu READ getHDDBaglantiArayuzu WRITE setHDDBaglantiArayuzu NOTIFY HDDBaglantiArayuzuDegisti)
    Q_PROPERTY(Metin HDDKapasitesi READ getHDDKapasitesi WRITE setHDDKapasitesi NOTIFY HDDKapasitesiDegisti)
    Q_PROPERTY(Metin HDDDonusHizi READ getHDDOnbellek WRITE setHDDOnbellek NOTIFY HDDOnbellekDegisti)
    Q_PROPERTY(Metin HDDBoyutu READ getHDDDonusHizi WRITE setHDDDonusHizi NOTIFY HDDDonusHiziDegisti)
    Q_PROPERTY(Metin HDDBoyutu READ getHDDBoyutu WRITE setHDDBoyutu NOTIFY HDDBoyutuDegisti)


    Idturu getId() const;
    Metin getHDDAdi() const;
    Metin getHDDBaglantiArayuzu() const;
    Metin getHDDKapasitesi() const;
    Metin getHDDOnbellek() const;
    Metin getHDDDonusHizi() const;
    Metin getHDDBoyutu() const;

signals:
    void IdDegisti(const Idturu &value);
    void HDDAdiDegisti(const Metin &value);
    void HDDBaglantiArayuzuDegisti(const Metin &value);
    void HDDKapasitesiDegisti(const Metin &value);
    void HDDOnbellekDegisti(const Metin &value);
    void HDDDonusHiziDegisti(const Metin &value);
    void HDDBoyutuDegisti(const Metin &value);
public slots:
    void setId(const Idturu &value);
    void setHDDAdi(const Metin &value);
    void setHDDBaglantiArayuzu(const Metin &value);
    void setHDDKapasitesi(const Metin &value);
    void setHDDOnbellek(const Metin &value);
    void setHDDDonusHizi(const Metin &value);
    void setHDDBoyutu(const Metin &value);


private:
    Idturu HDDId;
    Metin HDDAdi;
    Metin HDDBaglantiArayuzu;
    Metin HDDKapasitesi;
    Metin HDDOnbellek;
    Metin HDDDonusHizi;
    Metin HDDBoyutu;


};
QDataStream &operator<<(QDataStream &stream, const TMOHDDPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOHDDPtr &veri);
#endif // TMOHDD_H
