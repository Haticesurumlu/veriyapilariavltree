/**
* @file Stack.cpp
* @description Stack sınıfıyla ilgili fonksiyonların yazıldığı kaynak dosya
* @course 1-B
* @assignment Odev-2
* @date 23.08.2021
* @author  Hatice SURUMLU , hatice.surumlu@ogr.sakarya.edu.tr
*/
#include "Stack.hpp"
//stack dolu mu değil mi kontrol eden fonksiyon
bool Stack::dolumu()
{
    return elemanSayisi == kapasite;
}
//stacki genişleten fonksiyon
void Stack::yerAc(int boyut)
{
    int *tmp = new int[boyut];
    for (int j = 0; j < elemanSayisi; j++)
        tmp[j] = veriler[j];
    if (veriler != NULL)
        delete[] veriler;
    veriler = tmp;
    kapasite = boyut;
}

//kurucu fonksiyon
Stack::Stack()
{
    veriler = NULL;
    stackBasi = -1;
    elemanSayisi = 0;
    kapasite = 0;
}
//stack boş mu kontrol eden fonksiyon
bool Stack::bosMU() const
{
    return stackBasi == -1;
}

//stacke eleman ekleyen fonksiyon
void Stack::push(const int &eleman)
{
    if (dolumu())
    {
        yerAc(max(1, 2 * kapasite));
    }
    stackBasi++;
    veriler[stackBasi] = eleman;
    elemanSayisi++;
}

//en üstteki elemanı çıkaran fonksiyon
void Stack::pop()
{
    stackBasi--;
    elemanSayisi--;
}

//stack yazdırma fonksiyonunu çağıran fonksiyon
void Stack::call_print_the_stack(){ 
    print_the_stack();
}

//stacki yazdıran fonksiyon
void Stack::print_the_stack()
{
    for (int i = elemanSayisi-1; i >=0; i--)
    {
        cout<<veriler[i];
        if(i>0){
            cout<<",";
        }
        pop();
    }
    
}
//stackin tepesindeki elemanı döndürüyor
const int &Stack::top() const
{
    return veriler[stackBasi];
}

//stacki bosaltan fonksiyon
void Stack::makeEmpty()
{ 
    stackBasi = -1;
    elemanSayisi = 0;
}
Stack::~Stack() //destructor fonksiyonu
{
    if (veriler != NULL)
        delete[] veriler; //veriler dizisini bellekten siliyor
    veriler = NULL; 
}
