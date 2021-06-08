#ifndef TMOGUCKAYNAGI_H
#define TMOGUCKAYNAGI_H
#include <veriler/TANIMLAR.h>
#include <QObject>

class TMOGucKaynagi : public QObject
{
    Q_OBJECT
public:
    explicit TMOGucKaynagi(QObject *parent = nullptr);

    Q_PROPERTY(Idturu GucKaynagiId READ getId WRITE setId NOTIFY IdDegisti)
    Q_PROPERTY(Metin GucKaynagiAdi READ getGucKaynagiAdi WRITE setGucKaynagiAdi NOTIFY GucKaynagiAdiDegisti)
    Q_PROPERTY(Metin GucKaynagiModelNo READ getGucKaynagiModelNo WRITE setGucKaynagiModelNo NOTIFY GucKaynagiModelNoDegisti)
    Q_PROPERTY(Tamsayi GucKaynagiFanBoyutu READ getGucKaynagiFanBoyutu WRITE setGucKaynagiFanBoyutu NOTIFY GucKaynagiFanBoyutuDegisti)
    Q_PROPERTY(Tamsayi GucKaynagiDegeri READ getGucKaynagiDegeri WRITE setGucKaynagiDegeri NOTIFY GucKaynagiDegeriDegisti)





    Idturu getId() const;
    Metin getGucKaynagiAdi() const;
    Metin getGucKaynagiModelNo() const;
    Tamsayi getGucKaynagiFanBoyutu() const;
    Tamsayi getGucKaynagiDegeri() const;


signals:
    void IdDegisti(const Idturu &value);
    void GucKaynagiAdiDegisti(const Metin &value);
    void GucKaynagiModelNoDegisti(const Metin &value);
    void GucKaynagiFanBoyutuDegisti(const Tamsayi &value);
    void GucKaynagiDegeriDegisti(const Tamsayi &value);

public slots:
    void setId(const Idturu &value);
    void setGucKaynagiAdi(const Metin &value);
    void setGucKaynagiModelNo(const Metin &value);
    void setGucKaynagiFanBoyutu(const Tamsayi &value);
    void setGucKaynagiDegeri(const Tamsayi &value);

private:
    Idturu GucKaynagiId;
    Metin  GucKaynagiAdi;
    Metin  GucKaynagiModelNo;
    Tamsayi GucKaynagiFanBoyutu;
    Tamsayi GucKaynagiDegeri;

};
QDataStream &operator<<(QDataStream &stream, const TMOGucKaynagiPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOGucKaynagiPtr &veri);
#endif // TMOGUCKAYNAGI_H
