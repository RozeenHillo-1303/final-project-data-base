#include <mysql.h>
#include <iostream>
#include "book_store.h"
int main(int argc, char* argv[])
{
	commandList();
	while (1)
	{
		int cmdNum;
		cout << endl << endl << "Choose command : "; cin >> cmdNum;

		if (cin.fail()) { cin.clear(); cin.ignore(); }
		cout << endl;
		switch (cmdNum)
		{
		case 0:commandList(); break;
		case 1:isInStock(); break;
		case 2:OldestCustomer(); break;
		case 3:OldestBook(); break;
		case 4:OrderList(); break;
		case 5:SeveralCopies(); break;
		case 6:MostReadWriter(); break;
		case 7:CustomerHaveMostBooks(); break;
		case 8:Translations(); break;
		case 9:CustomerHistory(); break;
		case 10:PersonOrderHistory(); break;
		case 11:ShippingCostCalculation(); break;
		case 12:CustomerSplitOrder(); break;
		case 13:StatusShipment(); break;
		case 14:AmountOfShipments(); break;
		case 15:BitApp(); break;
		case 16:Average(); break;
		case 17:XpressAndIsraelPost(); break;
		case 18:TwoEditionsOfSameBook(); break;
		case 19:DataOmAllCustomers(); break;
		case 20:StoreContactedWithCustomer(); break;
		case 21:BooksInStock(); break;
		case 22:BooksBetweenDats(); break;
		case 23:StoreProfit(); break;
		case 24:AverageTransactions(); break;
		case 25:EmployeeStore(); break;
		case 26:TheMostDeals(); break;
		case 27:return 0;
		}

		cout << endl;
	}

	return 0;
}