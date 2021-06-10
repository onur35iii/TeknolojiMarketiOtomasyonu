#ifndef TEMELVERIYONETICISI_H
#define TEMELVERIYONETICISI_H
#include <veriler/TANIMLAR.h>
#include <QObject>

template <class V, class P>
class TemelVeriYoneticisi
{

public:
    typedef V Veri ;
    typedef P Ptr ;
    typedef QList<Ptr> VeriListesi ;
    typedef  std::function<bool(Ptr)> Sart;

    explicit TemelVeriYoneticisi(){
        ensonId=0;
    }

    // 1 Veri Oluşturma
    Ptr yeni() const
{
    Ptr yeni =std::make_shared<Veri>();
    return yeni;
}

    // 2 Veri Ekleme
    void ekle(Ptr alis){
        alis->setId(ensonId++);
        veriler.append(alis);
    }

    // 3 Veri Silme
    Ptr Sil(Idturu AlisId) // id isteyen
    {for(int i=0;i<veriler.size();i++)
        {
            if(veriler[i]->getId()==AlisId) {
                Ptr sonuc=veriler.takeAt(i);
                return sonuc;
            }
        }
        throw QObject::tr("Aranılan Veri Bulunamadı.");}
    Ptr Sil(Ptr alis) // ilac isteyen biz tümü için yapıcaz
    {
        return Sil(alis->getId());
    }

    // 5 Veri Arama
    Ptr ilkiniBul(Sart f)
    {
        for(int i=0; i<veriler.size();i++){
            auto veri_i=veriler[i];
            if(f(veri_i)){

                return veri_i;
            }
        }
        throw QObject::tr("Aranılan Veri Bulunamadı");
        /*
          // 2.yol
          for(auto i=veriler.begin(); i!=veriler.end();i++){
              auto veri_i=*i;
              if(f(veri_i)){

                  return veri_i;
              }
          }
          throw tr("Aranılan Veri Bulunamadı");


          // 3.yol
          for( Ptr veri_i: qAsConst (veriler))
          {
              if(f(veri_i)){

                  return veri_i;
              }
          }
          throw tr("Aranılan Veri Bulunamadı"); */
    }
    Ptr sonuncuyuBul(Sart f)
    {
        for(int i=veriler.size()-1; i>0;i--){
            auto veri_i=veriler[i];
            if(f(veri_i)){

                return veri_i;
            }
        }
        throw QObject::tr("Aranılan Veri Bulunamadı");
     /*  // 2.yol   --->rbegin rend
        for(auto i=veriler.rbegin(); i!=veriler.rend();i++){
            auto veri_i=*i;
            if(f(veri_i)){

                return veri_i;
            }
        }
        throw tr("Aranılan Veri Bulunamadı"); */


    }
    VeriListesi TumunuBul(Sart f){
        VeriListesi sonuc ;
        for(int i=0; i<veriler.size();i++){
            Ptr veri_i=veriler[i];
            if(f(veri_i)){
               sonuc.append(veri_i);

            }
        }

        return sonuc;
    }
    protected:

    VeriListesi veriler;
    Idturu ensonId;
    template<class H, class M>
    friend QDataStream &operator<<(QDataStream &stream, TemelVeriYoneticisi<H,M>&veri);
    template<class F, class B>
    friend QDataStream &operator>>(QDataStream &stream, TemelVeriYoneticisi<F,B>&veri);

};

template<class V, class P>
QDataStream &operator<<(QDataStream &stream, TemelVeriYoneticisi<V,P>&veri)
{
    stream << veri.ensonId <<veri.veriler;
    return stream;
}

template<class V, class P>
QDataStream &operator>>(QDataStream &stream, TemelVeriYoneticisi<V,P>&veri)
{
    stream >> veri.ensonId >> veri.veriler;
    return stream;
}



#endif // TEMELVERIYONETICISI_H
