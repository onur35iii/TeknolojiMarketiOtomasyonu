#ifndef TMOMAGAZABILGILERI_H
#define TMOMAGAZABILGILERI_H

#include <QObject>
#include <veriler/TANIMLAR.h>


class TMOMagazaBilgileri : public QObject
{
    Q_OBJECT
public:
    explicit TMOMagazaBilgileri(QObject *parent = nullptr);

    Q_PROPERTY(Idturu MagazaId READ getId WRITE setId NOTIFY IdDegisti)
    Q_PROPERTY(Metin MagazaAdi READ getMagazaAdi WRITE setMagazaAdi NOTIFY MagazaAdiDegisti)
    Q_PROPERTY(Metin MagazaAdresi READ getMagazaAdresi WRITE setMagazaAdresi NOTIFY MagazaAdresiDegisti)
    Q_PROPERTY(Metin MagazaYetkilisi READ getMagazaYetkilisi WRITE setMagazaYetkilisi NOTIFY MagazaYetkilisiDegisti)
    Q_PROPERTY(Tamsayi MagazaTelefonu READ getMagazaTelefonu WRITE setMagazaTelefonu NOTIFY MagazaTelefonuDegisti)

    Idturu getId() const;
    Metin getMagazaAdi() const;
    Metin getMagazaAdresi() const;
    Metin getMagazaYetkilisi() const;
    Tamsayi getMagazaTelefonu() const;

signals:
    void IdDegisti(const Idturu &value);
    void MagazaAdiDegisti(const Metin &value);
    void MagazaAdresiDegisti(const Metin &value);
    void MagazaYetkilisiDegisti(const Metin &value);
    void MagazaTelefonuDegisti(const Tamsayi &value);
public slots:
    void setId(const Idturu &value);
    void setMagazaAdi(const Metin &value);
    void setMagazaAdresi(const Metin &value);
    void setMagazaYetkilisi(const Metin &value);
    void setMagazaTelefonu(const Tamsayi &value);
private:
    Idturu MagazaId;
    Metin MagazaAdi;
    Metin MagazaAdresi;
    Metin MagazaYetkilisi;
    Tamsayi MagazaTelefonu;

};
QDataStream &operator<<(QDataStream &stream, const TMOMagazaBilgileriPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOMagazaBilgileriPtr &veri);
#endif // TMOMAGAZABILGILERI_H
