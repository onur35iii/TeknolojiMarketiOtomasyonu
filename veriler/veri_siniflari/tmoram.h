#ifndef TMORAM_H
#define TMORAM_H
#include <veriler/TANIMLAR.h>
#include <QObject>

class TMORAM : public QObject
{
    Q_OBJECT
public:
    explicit TMORAM(QObject *parent = nullptr);

    Q_PROPERTY(Idturu RamId READ getId WRITE setId NOTIFY IdDegisti)
    Q_PROPERTY(Metin RamAdi READ getRamAdi WRITE setRamAdi NOTIFY RamAdiDegisti)
    Q_PROPERTY(Metin RamModelNo READ getRamModelNo WRITE setRamModelNo NOTIFY RamModelNoDegisti)
    Q_PROPERTY(Metin Ramtipi READ getRamtipi WRITE setRamtipi NOTIFY RamtipiDegisti)
    Q_PROPERTY(Metin RamBushizi READ getRamBushizi WRITE setRamBushizi NOTIFY RamBushiziDegisti)
    Q_PROPERTY(Metin RamKapasitesi READ getRamKapasitesi WRITE setRamKapasitesi NOTIFY RamKapasitesiDegisti)
    Q_PROPERTY(Metin RamGecikmeSuresi READ getRamGecikmeSuresi WRITE setRamGecikmeSuresi NOTIFY RamGecikmeSuresiDegisti)
    Idturu getId() const;
    Metin getRamAdi() const;
    Metin getRamModelNo() const;
    Metin getRamtipi() const;
    Metin getRamBushizi() const;
    Metin getRamKapasitesi() const;
    Metin getRamGecikmeSuresi() const;


signals:
    void IdDegisti(const Idturu &value);
    void RamAdiDegisti(const Metin &value);
    void RamModelNoDegisti(const Metin &value);
    void RamtipiDegisti(const Metin &value);
    void RamBushiziDegisti(const Metin &value);
    void RamKapasitesiDegisti(const Metin &value);
    void RamGecikmeSuresiDegisti(const Metin &value);

public slots:
    void setId(const Idturu &value);
    void setRamAdi(const Metin &value);
    void setRamModelNo(const Metin &value);
    void setRamtipi(const Metin &value);
    void setRamBushizi(const Metin &value);
    void setRamKapasitesi(const Metin &value);
    void setRamGecikmeSuresi(const Metin &value);


private:
    Idturu RamId;
    Metin RamAdi;
    Metin RamModelNo;
    Metin Ramtipi;
    Metin RamBushizi;
    Metin RamKapasitesi;
    Metin RamGecikmeSuresi;


};
QDataStream &operator<<(QDataStream &stream, const TMORAMPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMORAMPtr &veri);
#endif // TMORAM_H
