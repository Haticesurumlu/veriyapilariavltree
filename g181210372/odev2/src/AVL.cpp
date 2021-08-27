/**
* @file AVL.cpp
* @description Avl ağacının başlık dosyasında bulunan fonksiyonların işlevlerinin yazıldığı kaynak dosyası
* @course 1-B
* @assignment Odev-2
* @date 23.08.2021
* @author Hatice SURUMLU , hatice.surumlu@ogr.sakarya.edu.tr
*/



#include "AVL.hpp"
//ağaçta uygun bölgeye düğüm ekleme fonksiyonu
Node *AVLAgaci::AraveEkle(Node *alt_Dugum, const int &yeni, Kisi *kisi)
{

    if (alt_Dugum == NULL) //mevcut düğümün boş olması durumu
    {
        alt_Dugum = new Node(yeni, kisi);
    }
    else if (yeni <= alt_Dugum->data) //yeni gelenin küçük veya eşit olma durumu
    {
        alt_Dugum->left = AraveEkle(alt_Dugum->left, yeni, kisi);         
        if (Yukseklik(alt_Dugum->left) - Yukseklik(alt_Dugum->right) == 2)
        {
            if (yeni <= alt_Dugum->left->data)

                alt_Dugum = SolCocukIleDegistir(alt_Dugum);
            else
            {
                alt_Dugum->left = SagCocukIleDegistir(alt_Dugum->left);
                alt_Dugum = SolCocukIleDegistir(alt_Dugum);
            }
        }
    }
    else if (yeni > alt_Dugum->data) //yeni gelenin büyük olması durumu
    {
        alt_Dugum->right = AraveEkle(alt_Dugum->right, yeni, kisi);
        if (Yukseklik(alt_Dugum->right) - Yukseklik(alt_Dugum->left) == 2)
        {
            if (yeni > alt_Dugum->right->data)

            {
                alt_Dugum = SagCocukIleDegistir(alt_Dugum);
            }

            else 
            {
                alt_Dugum->right = SolCocukIleDegistir(alt_Dugum->right);
                alt_Dugum = SagCocukIleDegistir(alt_Dugum);
            }
        }
    }
    else // aynı eleman mevcut olma durumu
        ;
    alt_Dugum->height = Yukseklik(alt_Dugum); //yüksekliğini güncelleme

    return alt_Dugum;
}

//gelen düğümü sol çocukla değiştirme fonksiyonu
Node *AVLAgaci::SolCocukIleDegistir(Node *alt_Dugum)
{
    Node *tmp = alt_Dugum->left;
    alt_Dugum->left = tmp->right;
    tmp->right = alt_Dugum;

    alt_Dugum->height = Yukseklik(alt_Dugum);
    tmp->height = max(Yukseklik(tmp->left), alt_Dugum->height) + 1;

    return tmp;
}

//gelen düğümü sağ çocukla değiştirme fonksiyonu
Node *AVLAgaci::SagCocukIleDegistir(Node *alt_Dugum)
{
    Node *tmp = alt_Dugum->right;
    alt_Dugum->right = tmp->left;
    tmp->left = alt_Dugum;

    alt_Dugum->height = Yukseklik(alt_Dugum);
    tmp->height = max(Yukseklik(tmp->right), alt_Dugum->height) + 1;

    return tmp;
}

//parametre gelen düğümün içindeki verileri yazdırma fonksiyonu
void AVLAgaci::DugumVerileriYazdir(Node *alt_Dugum, int seviye) const
{
    if (alt_Dugum == NULL)
        return;
    if (seviye == 0)
    {
        alt_Dugum->kisi->kisiVerileriniEkranaBastir();

        cout<<"Y(";
        alt_Dugum->derinlikStack->call_print_the_stack();
        cout<<"),";
        //derinlik yazdır
        cout<<"D(";
        alt_Dugum->yukseklikStack->call_print_the_stack();
        cout<<") ";
    }
    else
    {
        DugumVerileriYazdir(alt_Dugum->left, seviye - 1);
        DugumVerileriYazdir(alt_Dugum->right, seviye - 1);
    }
}
//ağaca verileri ekleyen ve düğümün içindeki bilgileri dolduran fonksiyon
void AVLAgaci::EkleveDugumuDoldur(Node *kok, int sayac, int boy, Kisi *kisi)
{

    DugumunLeveliniBuldur(kok, sayac);

    Ekle(boy, kisi);

    kok = returnHead();

    DerinlikveYukseklikHesaplat(kok);
}
//düğümün stacklerine eklenecek değerleri yerleştiren fonksiyon
void AVLAgaci::DerinlikveYukseklikStackeEkle(Node *alt_Dugum, int count = 0)
{

    if (alt_Dugum != NULL)
    {
        alt_Dugum->yukseklikStack->push(count);
        alt_Dugum->derinlikStack->push(alt_Dugum->height);
        
        DerinlikveYukseklikStackeEkle(alt_Dugum->left, count + 1);
        DerinlikveYukseklikStackeEkle(alt_Dugum->right, count + 1);
    }
}
//düğümün levelini bulduran fonksiyon
void AVLAgaci::DugumunLeveliBul(Node *alt_Dugum, int seviyeSayaci) const
{
    if (alt_Dugum != NULL) 
    {
        alt_Dugum->level = seviyeSayaci; //level ataması

        DugumunLeveliBul(alt_Dugum->left, seviyeSayaci + 1);
        DugumunLeveliBul(alt_Dugum->right, seviyeSayaci + 1);
    }
}
//düğümün yüksekliğini bulan fonksiyon
int AVLAgaci::Yukseklik(Node *alt_Dugum) const
{
    if (alt_Dugum == NULL)
        return -1;
    return 1 + max(Yukseklik(alt_Dugum->left), Yukseklik(alt_Dugum->right));
}
//düğüm silen fonksiyon
bool AVLAgaci::DugumSil(Node *&alt_Dugum)
{
    Node *silinecekDugum = alt_Dugum;

    if (alt_Dugum->right == NULL)
        alt_Dugum = alt_Dugum->left;
    else if (alt_Dugum->left == NULL)
        alt_Dugum = alt_Dugum->right;
    else
    {
        silinecekDugum = alt_Dugum->left;
        Node *ebeveynDugum = alt_Dugum;
        while (silinecekDugum->right != NULL)
        {
            ebeveynDugum = silinecekDugum;
            silinecekDugum = silinecekDugum->right;
        }
        alt_Dugum->data = silinecekDugum->data;
        if (ebeveynDugum == alt_Dugum)
            alt_Dugum->left = silinecekDugum->left;
        else
            ebeveynDugum->right = silinecekDugum->left;
    }
    silinecekDugum->yukseklikStack->~Stack();
    silinecekDugum->derinlikStack->~Stack();
    delete silinecekDugum;
    return true;
}
//düğüm arama fonksiyonu
bool AVLAgaci::Ara(Node *alt_Dugum, const int &aranan)
{
    if (alt_Dugum == NULL)
        return false;
    if (alt_Dugum->data == aranan)
        return true;
    if (aranan < alt_Dugum->data)
        return Ara(alt_Dugum->left, aranan);
    if (aranan > alt_Dugum->data)
        return Ara(alt_Dugum->right, aranan);
    return false;
    
}
//kurucu
 AVLAgaci::AVLAgaci()
{
    root = NULL;
}
//ağaç boş mu diye kontrol eden fonksiyon
bool AVLAgaci::Bosmu() const
{
    return root == NULL;
}
//ağaca eleman ekleme fonksiyonu
void AVLAgaci::Ekle(const int &yeni, Kisi *kisi)
{
    root = AraveEkle(root, yeni, kisi);
}
//düğüm levelini bulma fonksiyonu
void AVLAgaci::DugumunLeveliniBuldur(Node *alt_dugum, int seviyeSayaci)
{
    DugumunLeveliBul(alt_dugum, seviyeSayaci);
}

//derinlik ve yüksekliği bulup stacke ekletme fonksiyonu
void AVLAgaci::DerinlikveYukseklikHesaplat(Node *alt_dugum)
{
    DerinlikveYukseklikStackeEkle(alt_dugum);
}
//kök düğümü döndüren fonksiyonu
Node *AVLAgaci::returnHead()
{
    return root;
}

//level order yazdırma
void AVLAgaci::Levelorder() const
{
    int h = Yukseklik();
    cout<<"Level Order:"<<endl;
    for (int level = 0; level <= h; level++)
        DugumVerileriYazdir(root, level);
}
//veriyi içeren düğümü arayan fonksiyona erişim
bool AVLAgaci::Arama(const int &aranan)
{
    return Ara(root, aranan);
}
//ağacı sıfırlayan fonksiyon
void AVLAgaci::Temizle()
{
    while (!Bosmu())
        DugumSil(root);
}
//yüksekliğe erişim fonksiyonu
int AVLAgaci::Yukseklik() const
{
    return Yukseklik(root);
}
//destructor
AVLAgaci::~AVLAgaci()
{
    Temizle();
}
