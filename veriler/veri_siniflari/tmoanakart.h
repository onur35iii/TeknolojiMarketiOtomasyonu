#ifndef TMOANAKART_H
#define TMOANAKART_H
#include <veriler/TANIMLAR.h>
#include <QObject>

class TMOAnakart : public QObject
{
    Q_OBJECT
public:
    explicit TMOAnakart(QObject *parent = nullptr);

    Q_PROPERTY(Idturu  AnakartId READ getId WRITE setId NOTIFY IdDegisti)
    Q_PROPERTY(Metin AnakartAdi READ getAnakartAdi WRITE setAnakartAdi NOTIFY
                   AnakartAdiDegisti)
    Q_PROPERTY(Metin AnakartModelNo READ getAnakartModelNo WRITE setAnakartModelNo NOTIFY AnakartModelNoDegisti)
    Q_PROPERTY(Metin AnakartSoketTipi READ getAnakartSoketTipi WRITE setAnakartSoketTipi NOTIFY AnakartSoketTipiDegisti)
    Q_PROPERTY(Metin AnakartChipseti READ getAnakartChipseti WRITE setAnakartChipseti NOTIFY
                   AnakartChipsetiDegisti)
    Q_PROPERTY(Metin AnakartRamTipi READ getAnakartRamTipi WRITE setAnakartRamTipi NOTIFY AnakartRamTipiDegisti)
    Q_PROPERTY(Metin AnakartVgaSlotu READ getAnakartVgaSlotu WRITE setAnakartVgaSlotu NOTIFY AnakartVgaSlotuDegisti)
    Q_PROPERTY(Metin AnakartBoyutu READ getAnakartBoyutu WRITE setAnakartBoyutu NOTIFY
                   AnakartBoyutuDegisti)




    Idturu getId() const;
    Metin getAnakartAdi() const;
    Metin getAnakartModelNo() const;
    Metin getAnakartSoketTipi() const;
    Metin getAnakartChipseti() const;
    Metin getAnakartRamTipi() const;
    Metin getAnakartVgaSlotu() const;
    Metin getAnakartBoyutu() const;


signals:
    void IdDegisti(const Idturu &value);
    void AnakartAdiDegisti(const Metin &value);
    void AnakartModelNoDegisti(const Metin &value);
    void AnakartSoketTipiDegisti(const Metin &value);
    void AnakartChipsetiDegisti(const Metin &value);
    void AnakartRamTipiDegisti(const Metin &value);
    void AnakartVgaSlotuDegisti(const Metin &value);
    void AnakartBoyutuDegisti(const Metin &value);

public slots:
    void setId(const Idturu &value);
    void setAnakartAdi(const Metin &value);
    void setAnakartModelNo(const Metin &value);
    void setAnakartSoketTipi(const Metin &value);
    void setAnakartChipseti(const Metin &value);
    void setAnakartRamTipi(const Metin &value);
    void setAnakartVgaSlotu(const Metin &value);
    void setAnakartBoyutu(const Metin &value);


private:
    Idturu AnakartId ;
    Metin AnakartAdi;
    Metin AnakartModelNo;
    Metin AnakartSoketTipi;
    Metin AnakartChipseti;
    Metin AnakartRamTipi;
    Metin AnakartVgaSlotu;
    Metin AnakartBoyutu;



};
QDataStream &operator<<(QDataStream &stream, const TMOAnakartPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOAnakartPtr &veri);
#endif // TMOANAKART_H
