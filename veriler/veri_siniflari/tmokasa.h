#ifndef TMOKASA_H
#define TMOKASA_H
#include <veriler/TANIMLAR.h>
#include <QObject>

class TMOKasa : public QObject
{
    Q_OBJECT
public:
    explicit TMOKasa(QObject *parent = nullptr);
    Q_PROPERTY(Idturu KasaId READ getId                          WRITE setId NOTIFY IdDegisti)
    Q_PROPERTY(Metin KasaAdi READ getKasaAdi                         WRITE setKasaAdi NOTIFY KasaAdiDegisti)
    Q_PROPERTY(Metin KasaModelNo READ getKasaModelNo                 WRITE setKasaModelNo NOTIFY KasaModelNoDegisti)
    Q_PROPERTY(Metin KasaFanSayisi READ getKasaFanSayisi             WRITE setKasaFanSayisi NOTIFY KasaFanSayisiDegisti)
    Q_PROPERTY(Metin KasaGucKaynagivarmi READ getKasaGucKaynagivarmi WRITE setKasaGucKaynagivarmi NOTIFY KasaGucKaynagivarmiDegisti)
    Q_PROPERTY(Tamsayi KasaBoyutu READ getKasaBoyutu                 WRITE setKasaBoyutu NOTIFY KasaBoyutuDegisti)
    Q_PROPERTY(Metin KasaAnakartYapisi READ getKasaAnakartYapisi     WRITE setKasaAnakartYapisi NOTIFY KasaAnakartYapisiDegisti)
    Q_PROPERTY(Metin KasaRenk READ getKasaRenk                       WRITE setKasaRenk NOTIFY KasaRenkDegisti)


    Idturu getId() const;
    Metin getKasaAdi() const;
    Metin getKasaModelNo() const;
    Metin getKasaFanSayisi() const;
    Metin getKasaGucKaynagivarmi() const;
    Tamsayi getKasaBoyutu() const;
    Metin getKasaAnakartYapisi() const;
    Metin getKasaRenk() const;

signals:
    void IdDegisti(const Idturu &value);
    void KasaAdiDegisti(const Metin &value);
    void KasaModelNoDegisti(const Metin &value);
    void KasaFanSayisiDegisti(const Metin &value);
    void KasaGucKaynagivarmiDegisti(const Metin &value);
    void KasaBoyutuDegisti(const Tamsayi &value);
    void KasaAnakartYapisiDegisti(const Metin &value);
    void KasaRenkDegisti(const Metin &value);
public slots:
         void setId(const Idturu &value);
         void setKasaAdi(const Metin &value);
         void setKasaModelNo(const Metin &value);
         void setKasaFanSayisi(const Metin &value);
         void setKasaGucKaynagivarmi(const Metin &value);
         void setKasaBoyutu(const Tamsayi &value);
         void setKasaAnakartYapisi(const Metin &value);
         void setKasaRenk(const Metin &value);

private:
     Idturu KasaId;
     Metin KasaAdi;
     Metin KasaModelNo;
     Metin KasaFanSayisi;
     Metin KasaGucKaynagivarmi;
     Tamsayi KasaBoyutu;
     Metin KasaAnakartYapisi;
     Metin KasaRenk;

};
QDataStream &operator<<(QDataStream &stream, const TMOKasaPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOKasaPtr &veri);
#endif //
