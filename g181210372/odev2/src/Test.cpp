/**
* @file Test.cpp
* @description İstenilen işlemleri yapmak üzere kodlarımızı yazıp gereken fonksiyonları çağıracağımız kaynak dosyası
* @course 1-B
* @assignment Odev-2
* @date 23.08.2021
* @author Hatice SURUMLU , hatice.surumlu@ogr.sakarya.edu.tr
*/
#include <fstream>
#include "AVL.hpp"
#include<string>

int main()
{
    string file_name = "Kisiler.txt"; //dosya adı
    ifstream read_file(file_name); //dosya okumaya baslangic

    AVLAgaci *avlAgac = new AVLAgaci(); //avl agaci

    string name;
    int yas;
    int boy;
    string satir;
    string delimiter = "#"; //ayirac simge
    size_t pos = 0;
    string okunan_veri;
    int sayac = 0;

    while (getline(read_file, satir))
    {

        while ((pos = satir.find(delimiter)) != string::npos)
        {
            okunan_veri = satir.substr(0, pos);
            if (sayac == 0) //sayac 0 olduğunda gelen veri isim
            { 
                name = okunan_veri;
            }
            else if (sayac == 1) //sayac 1 olduğunda gelen veri yas
            { 
                yas = stoi(okunan_veri);
            }

            sayac+=1;
            satir.erase(0, pos + delimiter.length());
        }
        boy = stoi(satir); //son degerimiz ise boy oluyor.

        sayac = 0;

        //agaca ekleme ve dugum icindeki stackleri doldurma islemlerini yapan fonksiyonu cagiriyoruz
        avlAgac->EkleveDugumuDoldur(avlAgac->returnHead(), 0, boy, new Kisi(name, yas, boy));
        
    }
    avlAgac->Levelorder(); //agaci level order yazdiriyoruz.
    read_file.close(); //dosya okumayi kapatiyoruz.

    //bellekte cöp bırakmamak için agaci siliyoruz.
    delete avlAgac;

    return 0;
}