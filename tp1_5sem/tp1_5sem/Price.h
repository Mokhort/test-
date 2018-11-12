#pragma once
#ifndef PRICE
#define PRICE
#include <string>
#include <iostream>
using namespace std;

// Товар
class Price {
private:
	string store;
	string product;
	int cost;
	int number;
public:
	void setProduct(string p) {
		product = p;
	}

	string getProduct() {
		return product;
	}

	void setStore(string p) {
		store = p;
	}

	string getStore() {
		return store;
	}

	Price() {
		cost = 0;
	}
	void setCost(int p) {
		cost = p;
	}

	int getCost() {
		return cost;
	}
	void setNumber(int p) {
		number = p;
	}
	int getNumber() {
		return number;
	}
};
#endif