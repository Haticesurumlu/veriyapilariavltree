/**
* @file Stack.hpp
* @description Ağaçtaki düğümlerin içinde düğüm yüksekliği ve derinliğini saklayacak olan yapının başlık dosyası
* @course 1-B
* @assignment 2.Ödev
* @date 23.08.2021
* @author  Hatice SURUMLU , hatice.surumlu@ogr.sakarya.edu.tr
*/
#ifndef STACK_HPP
#define STACK_HPP
#include<Windows.h>
#include <iostream>
using namespace std;

class Stack{
	private:
		int *veriler; //düğümün yükseklik ve derinliğini tutacak dizi
		int stackBasi;
		int elemanSayisi;
		int kapasite;
		
		//private fonksiyon imzaları.
		bool dolumu();
		void print_the_stack();
		void yerAc(int boyut);
	public:
		//fonksiyon imzaları
		Stack();
		bool bosMU() const;
		void push(const int &);
		const int& top()const;
		void makeEmpty();
		void pop();
		void call_print_the_stack();
		
		~Stack();
};
#endif