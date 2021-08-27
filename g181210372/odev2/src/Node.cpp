/**
* @file Node.cpp
* @description Düğüm sınıfının (Node) kurucu fonksiyonunun yazıldığı dosya
* @course 1-B
* @assignment Odev-2
* @date 23.08.2021
* @author   Hatice SURUMLU , hatice.surumlu@ogr.sakarya.edu.tr
*/
#include "Node.hpp"

//kurucu fonk
Node::Node(const int &data, Kisi *kisiNesne, Node *left, Node *right)
{
    this->data = data;
    kisi = kisiNesne;
    level = 0;
    yukseklikStack = new Stack();
    derinlikStack=new Stack();
    this->left = left;
    this->right = right;
    height = 0; 
}

