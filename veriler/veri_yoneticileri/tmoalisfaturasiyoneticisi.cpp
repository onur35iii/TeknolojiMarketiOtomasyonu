#include "tmoalisfaturasiyoneticisi.h"
#include <veriler/veri_siniflari/tmoalisfaturasi.h>

TMOAlisFaturasiYoneticisi::TMOAlisFaturasiYoneticisi(QObject *parent) : QObject(parent)
{

}

TMOAlisFaturasiYoneticisi::Ptr TMOAlisFaturasiYoneticisi::kopyaOlustur(TMOAlisFaturasiYoneticisi::Ptr kaynak) const
{
    Ptr Kopya=yeni();
    Kopya->setId(kaynak->getId());
    Kopya->setParcaAlisFaturaNo(kaynak->getParcaAlisFaturaNo());
    Kopya->setParcaAlisTarihi(kaynak->getParcaAlisTarihi());

    return Kopya;
}

