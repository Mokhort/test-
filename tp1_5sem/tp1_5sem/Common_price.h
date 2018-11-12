#pragma once
#ifndef COMMON_PRICE
#define COMMON_PRICE
#include <string>
#include <iostream>
using namespace std;

// Прайс состоит из товаров
class CommonPrice {
public:
	int tsize, n, counter = 1;
	Price *mas;
	CommonPrice()
	{
		cout << "\n //Constructor//\n";
		n = 3;
		tsize = 0;
		mas = new Price[n];
	}

	~CommonPrice() {
		cout << "\n //Destructor//\n";
		delete[]mas;
	}

	CommonPrice(const CommonPrice &obj)
	{
		mas = new Price;
		for (int i = 0; i<tsize; i++)
			mas[i] = obj.mas[i];

		tsize = obj.tsize;
		cout << "\n//Copy constructor//\n";
	}




	//CommonPrice & operator >> (CommonPrice& is ,Price & p)
	//CommonPrice &operator >>(CommonPrice q,Price p)
	//friend istream &operator >> (istream &stream, Price p)

	void push(Price p)
	{
		Price *tmp = new Price[tsize + 1];

		for (int i = 0; i<tsize; i++)
			tmp[i] = mas[i];

		tmp[tsize] = p;
		tmp[tsize].setNumber(counter);
		delete[] mas;
		mas = tmp;
		tsize++;
		counter++;
		//return stream;
	}

	CommonPrice & operator <<(int wnumber)//void pop(int wnumber)
	{
		int k = 0;

		if (wnumber <= 0) {
			throw 123;
		}

		Price *tmp = new Price[tsize - 1];
		for (int i = 0; i < tsize; i++) {
			if (wnumber != mas[i].getNumber()) {
				tmp[k] = mas[i];
				k++;
			}
		}
		delete[] mas;
		mas = tmp;
		tsize--;

	}


	void show() {
		if (tsize == 0) {
			cout << "spisok is empty" << endl;
		}
		else {
			for (int i = 0; i < tsize; i++)
				cout << mas[i].getNumber() << " " << mas[i].getStore() << " " << mas[i].getProduct() << " " << mas[i].getCost() << endl;
		}
	}
	void sort() {//сортировка пузырьком по алфавиту
		int counter = 1;
		for (int i = 0; i < tsize; i++)
			for (int j = tsize - 1; j > i; j--) {
				if (mas[j - 1].getStore() > mas[j].getStore()) {
					Price tmp = mas[j - 1];
					mas[j - 1] = mas[j];
					mas[j] = tmp;
				}
			}
		for (int i = 0; i < tsize; i++)
		{
			mas[i].setNumber(counter);
			counter++;
		}
	}

	void prodofstore(string storefp) {
		int count = 0;
		for (int i = 0; i < tsize; i++)
			if (mas[i].getStore() == storefp)
			{
				cout << mas[i].getProduct() << " " << mas[i].getCost() << endl;
				count++;
			}
		if (count == 0)
		{
			cout << "wrong store" << endl;
		}
	}
};
#endif