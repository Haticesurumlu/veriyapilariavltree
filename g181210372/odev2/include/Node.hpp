/**
* @file Node.hpp
* @description Ağacın her bir düğümünü oluşturacak sınıfı içeren başlık dosyası
* @course  1-B
* @assignment Odev-2
* @date 23.08.2021
* @author   Hatice SURUMLU , hatice.surumlu@ogr.sakarya.edu.tr
*/
#ifndef DUGUM_HPP
#define DUGUM_HPP
#include "Kisi.hpp"
#include "Stack.hpp"
class Node{
    public:
	int data;
	Kisi *kisi;
	Stack *yukseklikStack; //yükseklik bilgisi tutacak stacki işaret eden pointer
	Stack *derinlikStack; //derinlik bilgisi tutacak stacki işaret eden pointer
	Node *left;
	Node *right;
	int height;
	int level;
	Node(const int& data,Kisi *ks=NULL,Node *left=NULL,Node *right=NULL);
};

#endif