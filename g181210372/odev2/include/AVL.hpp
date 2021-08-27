/**
* @file AVL.hpp
* @description AVL ağacıyla ilgili işlemleri gerçekleştiren fonksiyonların imzalarını barındıran dosya
* @course 1-B
* @assignment Odev-2
* @date 23.08.2021
* @author  Hatice SURUMLU , hatice.surumlu@ogr.sakarya.edu.tr
*/
#ifndef AVL_HPP
#define AVL_HPP
#include "Node.hpp"
class AVLAgaci
{
private:
	Node *root;
	//private fonksiyon imzaları
	Node *AraveEkle(Node *, const int &, Kisi *);
	void DugumVerileriYazdir(Node *, int) const; //düğüm veri yazdırma
	void DerinlikveYukseklikStackeEkle(Node *, int); //stacke verileri ekleme
	void DugumunLeveliBul(Node *, int) const; //level bulma
	int Yukseklik(Node *) const;
	bool DugumSil(Node *&);
	Node *SolCocukIleDegistir(Node *);
	Node *SagCocukIleDegistir(Node *);

	bool Ara(Node *, const int &);

public:
	//public fonksiyon imzaları
	void EkleveDugumuDoldur(Node *, int, int, Kisi *);
	bool Arama(const int &);
	void Temizle();
	int Yukseklik() const;
	AVLAgaci();
	bool Bosmu() const;
	void Ekle(const int &, Kisi *);
	Node *returnHead();
	void DerinlikveYukseklikHesaplat(Node *); //stacke veri ekleme erişim
	void Levelorder() const; //yazdırma level order 
	void DugumunLeveliniBuldur(Node *, int); //düğüm level bulma erişim

	~AVLAgaci();
};

#endif