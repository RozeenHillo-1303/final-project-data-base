#include <mysql.h>
#include <iostream>
#include "book_store.h"
#include "database.h"

void commandList()
{
	std::cout << "List of commands:" << endl
		<< "1.	Is Book X in stock" << endl
		<< "2.	oldest customer" << endl
		<< "3.	What is the oldest book" << endl
		<< "4.	Current order list" << endl
		<< "5.	Several copies of Book Y were sold by the store" << endl
		<< "6.	Who is the most read writer in the middle of dates X to Y." << endl
		<< "7.	List of the 3 customers who have purchased the most books over the years" << endl
		<< "8.	Who is the book with the largest number of translations currently in stock" << endl
		<< "9.	Customer X Purchase History:What books did he purchase, on what datesand what price did he pay for each book." << endl
		<< "10.	Regarding person X: order history) what and when ordered. Sorted by Order dates.Indicate whether the book was indeed found, and if so, whether it was purchased" << endl
		<< "11.	Shipping cost calculation" << endl
		<< "12.	Has customer X ever split a book purchase for multiple shipments and if so What are the shipping data" << endl
		<< "13.	What is the current status of a particular shipment" << endl
		<< "14.	What is the amount of shipments made by Xpress in a particular month" << endl
		<< "15.	The total money transferred to the store account via the Bit app per monta certain" << endl
		<< "16.	What are the transactions that have been made during the last 12 months, and which have yielded Greater profit than the average trading profit in these 12 months" << endl
		<< "17.	Some shipments have been made in the last 12 months by mailIsrael, and some were made through Xpress." << endl
		<< "18.	Data on all shipments made, ever, and including at least 2 editions Variety of the same book" << endl
		<< "19.	Data on all customers who have previously purchased, at any time, at least one book From the store, and who have not made any purchases during the last 24 months" << endl
		<< "20.	List of customers who placed orders, the books they ordered arrived at the store, The store contacted them to inform them of the availability of the book. The contact was made 14 days ago, and customers have not yet purchased the book." << endl
		<< "21.	Number of books in the warehouse on a monthly basis" << endl
		<< "22 (22A). How many books did the store purchase between D1 and D2, and what was the total The payment for them." << endl
		<< "23 (22B). The store's profit from sales in a particular month" << endl
		<< "24.	Annual average monthly transactions" << endl
		<< "25.	The salary (gross) of employee Z in a given month" << endl
		<< "26.	Who sells the most deals in month X" << endl;
		
		

}




//1.
bool isInStock(){
	MySQL* sql = new MySQL();
	cout << "Enter tital: ";
	char input[50];
	cin.ignore();
	cin.getline((char*)&input, 50);
	string query = "select title, in_stock from books where title = '" + (string)input + "' and in_stock > 0";
	sql->ShowTables(query.c_str());
	return true;
}

//2.
void OldestCustomer() {
	MySQL* sql = new MySQL();
	string query = "SELECT customer.first_name, min(order_date) FROM book_store.books_transaction inner join customer on books_transaction.customer_id1 = customer.id; ";
	sql->ShowTables(query.c_str());
}

//3.
void OldestBook() {
	MySQL* sql = new MySQL();
	string query = "select books.title,min(date_reseived) from books";
	sql->ShowTables(query.c_str());
}

//4.
void OrderList() {
	MySQL* sql = new MySQL();
	string query = "select * from books_transaction where order_status<>'delivered' ORDER BY order_date desc";
	sql->ShowTables(query.c_str());
}

//5.
void SeveralCopies() {
	MySQL* sql = new MySQL();
	cout << "Enter tital: ";
	char input[50];
	cin.ignore();
	cin.getline((char*)&input, 50);
	string query = "select sum(quantity) from books_transaction inner join books on books.id = books_transaction.books_id where books.title ='" + (string)input + "'";
	sql->ShowTables(query.c_str());

}

//6.
void MostReadWriter() {
	MySQL* sql = new MySQL();
	cout << "Enter Start Date: ";
	char input[50];
	char input2[50];
	cin.ignore();
	cin.getline((char*)&input, 50);
	const char* dateStart = input;
	cout << "Enter End Date: ";
	cin.getline((char*)&input2, 50);
	const char* dateEnd = input2;
	string query = "select writer.name_writer  as books_amount from books inner join books_transaction on books.id = books_transaction.books_id inner join  writer_has_books on writer_has_books.books_id = books_transaction.books_id inner join writer on writer.id = writer_has_books.writer_id WHERE  books_transaction.order_date >= '" + (string)dateStart + "' and books_transaction.order_date < '" + (string)dateEnd + "' GROUP BY writer.id HAVING COUNT(writer.id) > 1 order by COUNT(writer.id) desc limit 1; ";
	sql->ShowTables(query.c_str());

}

//7.
void CustomerHaveMostBooks() {
	MySQL* sql = new MySQL();
	string query = "select customer.first_name,books_transaction.quantity from books_transaction inner join customer on books_transaction.customer_id1 = customer.id ORDER BY quantity desc LIMIT 3 ";
	sql->ShowTables(query.c_str());
}

//8.
void Translations() {
	MySQL* sql = new MySQL();
	string query = "select title from books inner join  books_has_languages on books.id = books_has_languages.books_id inner join languages on books_has_languages.books_id = languages.id WHERE books.in_stock > 0 group by books.id HAVING COUNT(books.id) > 0 order by count(books.id) desc limit 1";
	sql->ShowTables(query.c_str());
}

//9.
void CustomerHistory() {
	MySQL* sql = new MySQL();
	cout << "Enter First Name: ";
	char input[50];
	char input2[50];
	cin.ignore();
	cin.getline((char*)&input, 50);
	const char* firstname = input;
	cout << "Enter Last Name: ";
	cin.getline((char*)&input2, 50);
	const char* lastname = input2;
	string query = "select customer.first_name,customer.last_name, books.title,books_transaction.order_date,books.price from books_transaction inner join books on books_transaction.books_id = books.id inner join customer on customer.id = books_transaction.customer_id1 WHERE  customer.first_name = '" + (string)firstname + "' and customer.last_name = '" + (string)lastname + "' order by order_date";
	sql->ShowTables(query.c_str());

}

//10.
void PersonOrderHistory() {
	MySQL* sql = new MySQL();
	cout << "Enter First Name: ";
	char input[50];
	char input2[50];
	cin.ignore();
	cin.getline((char*)&input, 50);
	const char* firstname = input;
	cout << "Enter Last Name: ";
	cin.getline((char*)&input2, 50);
	const char* lastname = input2;
	string query = "select customer.first_name,customer.last_name, books_transaction.order_date,books.title, books_transaction.quantity,books.price,books.in_stock,books_transaction.total from books_transaction inner join books on books_transaction.books_id = books.id inner join customer on customer.id = books_transaction.books_id WHERE  customer.first_name = '" + (string)firstname + "' and customer.last_name = '" + (string)lastname + "' ORDER BY order_date desc";
	sql->ShowTables(query.c_str());
}

//11.
void ShippingCostCalculation() {
	MySQL* sql = new MySQL();
	string query = "select books_transaction.order_number, books.price,books.weight,books_transaction.quantity,deliveries.name_1,deliveries_methods.name_2,deliveries_methods.price,((books.price + books.weight) * (books_transaction.quantity) + (deliveries_methods.price)) AS total_price from books_transaction inner join books on books_transaction.books_id = books.id inner join deliveries on deliveries.deliveries_id = books_transaction.books_id inner join deliveries_methods on deliveries_methods.delivery_method_id = books.id";
	sql->ShowTables(query.c_str());
}

//12.
void CustomerSplitOrder() {
	MySQL* sql = new MySQL();
	cout << "Enter First Name: ";
	char input[50];
	char input2[50]; cin.ignore();
	cin.getline((char*)&input, 50);
	const char* firstname = input;
	cout << "Enter Last Name: ";
	cin.getline((char*)&input2, 50);
	const char* lastname = input2;
	string query = "select customer.first_name, customer.last_name, books.title, books_transaction.quantity, books_transaction.order_number, books_transaction.order_date from books inner join books_transaction on books.id =  books_transaction.books_id inner join customer on books_transaction.customer_id1 = customer.id where customer.first_name = '" + (string)firstname + "' and customer.last_name = '" + (string)lastname + "'";
	sql->ShowTables(query.c_str());
}
//13.
void StatusShipment()
{
	MySQL* sql = new MySQL();
	string query = "select order_status from books_transaction where id = 12444";
	sql->ShowTables(query.c_str());
}

//14.
void AmountOfShipments()
{
	MySQL* sql = new MySQL();
	cout << "month: ";
	char input[50];
	cin.ignore();
	cin.getline((char*)&input, 50);
	const char* month = input;
	string query = "SELECT count(MONTH(order_date)) as num_delivery_by_Xpress_fer_month,MONTH(order_date)  from books_transaction inner join deliveries on deliveries.deliveries_id = books_transaction.deliveries_deliveries_id1 inner join deliveries_methods on deliveries_methods.delivery_method_id = books_transaction.deliveries_deliveries_id1 WHERE  deliveries.name_1 = 'Xpress' and MONTH(order_date)= '" + (string)month + "' order by order_date desc";
	sql->ShowTables(query.c_str());
}

//15.
void BitApp()
{
	MySQL* sql = new MySQL();
	cout << "month: ";
	char input[50];
	cin.ignore();
	cin.getline((char*)&input, 50);
	const char* month = input;
	string query = "SELECT  books_transaction.method,MONTH(order_date) as month,count(total), sum(total) from books_transaction inner join books on books.id = books_transaction.books_id WHERE  books_transaction.method ='bit_app' and MONTH(order_date)= '" + (string)month + "'";
	sql->ShowTables(query.c_str());
}

//16.
void Average()
{
	MySQL* sql = new MySQL();
	cout << "Enter Start Date:";
	char input[50];
	char input2[50];
	cin.ignore();
	cin.getline((char*)&input, 50);
	const char* StartDate = input;
	cout << "Enter End Date: ";
	cin.getline((char*)&input2, 50);
	const char* EndDate = input2;
	string query = "select year(order_date),sum(total) from books_transaction WHERE  books_transaction.order_date >=  '" + (string)StartDate + "' and books_transaction.order_date <= '" + (string)EndDate + "'";
	sql->ShowTables(query.c_str());
}

//17.
void XpressAndIsraelPost()
{
	MySQL* sql = new MySQL();
	cout << "Enter Start Date:";
	char input[50];
	cin.ignore();
	cin.getline((char*)&input, 50);
	const char* StartDate = input;
	string query = "SELECT deliveries.name_1 as DeliveriesName,count(deliveries.name_1) as amount from deliveries inner join books_transaction on deliveries.deliveries_id = books_transaction.deliveries_deliveries_id1 WHERE order_date between '2019-01-01' and now() GROUP BY  deliveries.name_1 HAVING COUNT(deliveries.name_1) >= 1 order by deliveries.name_1 desc";
	sql->ShowTables(query.c_str());
}

//18.
void TwoEditionsOfSameBook()
{
	MySQL* sql = new MySQL();
	string query = "select books_transaction.order_date,books_transaction.order_number,publication.year_of_publication,books_transaction.quantity,books_transaction.total,(books.id) as booksId from books  inner join books_has_publication on books.id = books_has_publication.books_id inner join publication on books_has_publication.publication_id = publication.id inner join books_transaction on  books.id = books_transaction.books_id where books_transaction.order_date = '2013-12-11'";
	sql->ShowTables(query.c_str());
}

//19.
void DataOmAllCustomers()
{
	MySQL* sql = new MySQL();
	string query = "SELECT customer.id,books_transaction.order_date,customer.first_name,customer.last_name,customer.lines_phone from customer inner join books_transaction on customer.id = books_transaction.customer_id1 WHERE  books_transaction.order_date <  '2018-07-28'";
	sql->ShowTables(query.c_str());
}

//20.
void StoreContactedWithCustomer()
{
	MySQL* sql = new MySQL();
	string query = "select (shipped_date),customer.first_name, customer.last_name from books_transaction inner join customer on books_transaction.customer_id1 = customer.id where books_transaction.order_date < books_transaction.shipped_date";
	sql->ShowTables(query.c_str());
}

//21.
void BooksInStock()
{
	MySQL* sql = new MySQL();
	cout << "Enter year: ";
	char input[50]; cin.ignore();
	cin.getline((char*)&input, 50);
	const char* year = input;
	string query = "SELECT month(date_reseived) as month,(in_stock) as total_books_in_stock FROM books WHERE year(date_reseived) = '" + (string)year + "'  group by month(date_reseived)";
	sql->ShowTables(query.c_str());
}

//22A.
void BooksBetweenDats()
{
	MySQL* sql = new MySQL();
	cout << "Enter firs Date: ";
	char input[50];
	char input2[50];
	cin.ignore();
	cin.getline((char*)&input, 50);
	const char* FirstDate = input;
	cout << "Enter End Date: ";
	cin.getline((char*)&input2, 50);
	const char* EndDate = input2;
	string query = "SELECT sum(total) as total_paid, sum(quantity) as total_num_of_books FROM books_transaction WHERE order_date >=  '" + (string)FirstDate + "'  and  order_date < '" + (string)EndDate + "'";
	sql->ShowTables(query.c_str());
}

//22B.  /23
void StoreProfit()
{
	MySQL* sql = new MySQL();
	cout << "Enter month payment: ";
	char input[50];
	char input2[50];
	char input3[50];
	char input4[50];
	cin.ignore();
	cin.getline((char*)&input, 50);
	const char* MonthPayment = input;
	cout << "Enter year payment: ";
	cin.getline((char*)&input2, 50);
	const char* YearPayment = input2;
	cout << "Enter month order: ";
	cin.getline((char*)&input3, 50);
	const char* MonthOrder = input3;
	cout << "Enter year order: ";
	cin.getline((char*)&input4, 50);
	const char* YearOrder = input4;
	string query = "SELECT MONTH(month_payment) as month,(price), (expenses_total), ((price) - (expenses_total)) AS store_profit  FROM store_payments inner join store_order WHERE MONTH(month_payment) = '" + (string)MonthPayment + "'  and  YEAR(month_payment) = '" + (string)YearPayment + "' and MONTH(order_date) = '" + (string)MonthOrder + "' and  YEAR(order_date) = '" + (string)YearOrder + "' GROUP BY store_payments.store_id order by (store_payments.store_id) desc limit 1;";
	sql->ShowTables(query.c_str());
}

//23.  /24
void AverageTransactions()
{
	MySQL* sql = new MySQL();
	cout << "Enter Year ";
	char input[50];
	cin.ignore();
	cin.getline((char*)&input, 50);
	const char* Year = input;
	string query = "SELECT month(order_date) as month,(total) as total FROM books_transaction WHERE year(order_date) = '" + (string)Year + "' group by month(order_date)";
	sql->ShowTables(query.c_str());
}

//24.  /25
void EmployeeStore()
{
	MySQL* sql = new MySQL();
	cout << "Enter Month ";
	char input[50];
	char input2[50];
	cin.ignore();
	cin.getline((char*)&input, 50);
	const char* Month = input;
	cout << "Enter First Name: ";
	cin.getline((char*)&input2, 50);
	const char* FirstName = input2;
	string query = "SELECT employee.first_name,(MONTH(month)) as salary_month,(salary) from salary_per_month inner join employee on salary_per_month.id = employee.employee_id WHERE  MONTH(month)= '" + (string)Month + "' or employee.first_name= '" + (string)FirstName + "' order by month desc";
	sql->ShowTables(query.c_str());
}

//25.
void TheMostDeals()
{
	MySQL* sql = new MySQL();
	cout << "Enter Month ";
	char input[50];
	cin.ignore();
	cin.getline((char*)&input, 50);
	const char* Month = input;
	string query = "select employee.first_name, employee.last_name,employee.employee_id from employee inner join books_transaction on employee.employee_id = books_transaction.employee_employee_id WHERE  MONTH(order_date)= '" + (string)Month + "' GROUP BY employee.employee_id order by COUNT(employee.employee_id) desc limit 1";
	sql->ShowTables(query.c_str());
}