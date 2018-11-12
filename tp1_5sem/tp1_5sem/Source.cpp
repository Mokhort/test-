#include <iostream>
#include <conio.h>
#include <string>
#include "PRICE.h"
#include "COMMON_PRICE.h"
using namespace std;



//void any(CommonPrice p)
//{	
//}

int main() {

	CommonPrice p;
	Price q;
	string wstore, wproduct, storefp;
	int wcost, wnumber;

	cout << "Write the name of store, product and cost :" << endl;
	for (int i = 0; i < 3; i++) {

		cin >> wstore >> wproduct >> wcost;
		q.setStore(wstore);
		q.setProduct(wproduct);
		q.setCost(wcost);
		//p >> q;
		p.push(q);

	}
	p.sort();
	p.show();

	/*any(p);*/

	int r;
	bool fl = true;
	while (fl) {
		cout << "0 - exit" << endl;
		cout << "1 - add objects" << endl;
		cout << "2 - delete object" << endl;
		cout << "3 - show objects" << endl;
		cout << "4 - show procucts of one store" << endl;

		cin >> r;
		switch (r) {
		case 0:
			fl = false;
			break;
		case 1:
			cout << "Write the name of store, product and cost :" << endl;

			cin >> wstore >> wproduct >> wcost;
			q.setStore(wstore);
			q.setProduct(wproduct);
			q.setCost(wcost);
			//p >> q;
			p.push(q);
			

			p.sort();	//+сортировка по алфавиту
			break;
		case 2:
			cout << "Write the number, which you want to delete :" << endl;
			cin >> wnumber;
			try
			{
				p << wnumber;
				//p.pop(wnumber);
			}
			catch (int e)
			{
				cout << e << " " << "Error! Wrong number" << endl;
			}
			catch (...)
			{
				cout << "Error" << endl;
			}
			break;
		case 3:
			p.sort();//сортировка по алфавиту + show
			p.show();
			cout << endl;
			break;
		case 4:
			cout << "write a store:" << endl;
			cin >> storefp;
			p.prodofstore(storefp);// вывод всех товаров магазина
			break;

			_getch();
		}
	}
}

