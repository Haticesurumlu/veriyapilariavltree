/**
* @file Kisi.cpp
* @description Kişi sınıfının fonksiyonlarının gövdelerini yazdığımız kaynak dosyası
* @course 1-B
* @assignment Odev-2
* @date 23.08.2021
* @author  Hatice SURUMLU , hatice.surumlu@ogr.sakarya.edu.tr
*/
#include "Kisi.hpp"
//kurucu fonksiyon işlev tanımlaması
Kisi::Kisi(string isim,int yas,int boy)
{
    this->isim = isim;
    this->yas = yas;
    this->boy = boy;
}
//kişiye ait verileri ekrana basan fonksiyon
void Kisi::kisiVerileriEkranaBas(){
    cout<<isim<<" ";
    cout<<yas<<" ";
    cout<<boy<<" ";
}
//kişi verilerini ekrana basma fonksiyonuna erişim
void Kisi::kisiVerileriniEkranaBastir(){ 
    kisiVerileriEkranaBas();
}
