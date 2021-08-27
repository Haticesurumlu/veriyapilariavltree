/**
* @file Kisi.hpp
* @description Dosyadan okunan kişinin bilgilerinin tutulacağı sınıfı içeren dosya
* @course 1-B
* @assignment Odev-2
* @date 23.08.2021
* @author  Hatice SURUMLU , hatice.surumlu@ogr.sakarya.edu.tr
*/
#ifndef KISI_HPP
#define KISI_HPP
#include<iostream>
using namespace std;
class Kisi
{
private:
    string isim;
    int yas;
    int boy;
    void kisiVerileriEkranaBas(); //kişinin verilerini  yazdıracak fonksiyonun imzası

public:
    //fonksiyon imzaları
    Kisi(string,int,int);
    void kisiVerileriniEkranaBastir();
};

#endif