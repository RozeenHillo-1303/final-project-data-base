#pragma once


#include <iostream>
#include "mysql.h"
#include <string>
#include <iomanip>


using namespace std;
void commandList();

//1.Is Book X in stock
bool isInStock();

//2.oldest customer
void OldestCustomer();

//3.What is the oldest book
void OldestBook();

//4.Current order list
void OrderList();

//5.Several copies of Book Y were sold by the store
void SeveralCopies();

//6.Who is the most read writer in the middle of dates X to Y.
void MostReadWriter();

//7.List of the 3 customers who have purchased the most books over the years
void CustomerHaveMostBooks();

//8.Who is the book with the largest number of translations currently in stock
void Translations();

//9.Customer X Purchase History:What books did he purchase, on what datesand what price did he pay for each book.
void CustomerHistory();

//10.Regarding person X: order history) what and when ordered. Sorted by Order dates.Indicate whether the book was indeed found, and if so, whether it was purchased
void PersonOrderHistory();

//11.Shipping cost calculation
void ShippingCostCalculation();

//12.Has customer X ever split a book purchase for multiple shipments and if so What are the shipping data
void CustomerSplitOrder();

//13.What is the current status of a particular shipment
void StatusShipment();

//14.What is the amount of shipments made by Xpress in a particular month
void AmountOfShipments();

//15.The total money transferred to the store account via the Bit app per monta certain
void BitApp();

//16.What are the transactions that have been made during the last 12 months, and which have yielded Greater profit than the average trading profit in these 12 months
void Average();

//17.Some shipments have been made in the last 12 months by mailIsrael, and some were made through Xpress.
void XpressAndIsraelPost();

//18.Data on all shipments made, ever, and including at least 2 editions Variety of the same book
void TwoEditionsOfSameBook();

//19.Data on all customers who have previously purchased, at any time, at least one book From the store, and who have not made any purchases during the last 24 months
void DataOmAllCustomers();

//20.List of customers who placed orders, the books they ordered arrived at the store, The store contacted them to inform them of the availability of the book. The contact was made 14 days ago, and customers have not yet purchased the book.
void StoreContactedWithCustomer();

//21.Number of books in the warehouse on a monthly basis
void BooksInStock();

//22A.How many books did the store purchase between D1 and D2, and what was the total The payment for them.
void BooksBetweenDats();

//22B.The store's profit from sales in a particular month
void StoreProfit();

//23.Annual average monthly transactions
void AverageTransactions();

//24.The salary (gross) of employee Z in a given month
void EmployeeStore();

//25.Who sells the most deals in month X
void TheMostDeals();