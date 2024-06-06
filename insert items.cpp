#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int totalitems = 0;
const int MAX = 50;
int productId[MAX];
string productName[MAX];
string weight[MAX];
string mfgDate[MAX];
string expDate[MAX];
float price[MAX];
int quantity[MAX];

void readGroceryItems() {
	ifstream file;
	file.open("GroceryStore.txt");
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			stringstream ss(line);
			ss >> productId[totalitems] >> productName[totalitems] >> weight[totalitems] >> mfgDate[totalitems] >> expDate[totalitems] >> quantity[totalitems] >> price[totalitems];
			totalitems++;

		}
		file.close();
	}
}
void printgroceryitems() {

	for (int i = 1; i < totalitems; i++)
	{
		cout << productId[i] << "	" << productName[i] << "	" << weight[i] << "	" << mfgDate[i] << "	" << expDate[i] << "	" << quantity[i] << "	" << price[i] << endl;

	}
	totalitems++;

}
void insertGroceryItem() {
	int productid;
	string productname;
	string Weight;
	string mfgdate;
	string expdate;
	int Quantity;
	float Price;
	if (totalitems == MAX) {
		cout << "Grocery store is full. Cannot insert new item." << endl;
		return;
	}
	else {

		cout << "Enter Product Id ";
		cin >> productid;
		cout << "Enter Product Name ";
		cin >> productname;
		cout << "Enter Weight ";
		cin >> Weight;
		cout << "Enter MFG Date  ";
		cin >> mfgdate;
		cout << "Enter Exp Date ";
		cin >> expdate;
		cout << "Enter Quantity ";
		cin >> Quantity;
		cout << "Enter Price  ";
		cin >> Price;
		productId[totalitems] = productid;
		productName[totalitems] = productname;
		weight[totalitems] = Weight;
		mfgDate[totalitems] = mfgdate;
		expDate[totalitems] = expdate;
		quantity[totalitems] = Quantity;
		price[totalitems] = Price;
		totalitems++;
	}


}
void deleteGroceryItem() {
	int Id;
	int a = 0;
	cout << "Enter the product Id you wanna remove ";
	cin >> Id;
	for (int i = 0; i < totalitems; i++) {
		if (productId[i] == Id) {
			a++;
			for (int j = i; j < totalitems - 1; j++) {
				productId[j] = productId[j + 1];
				productName[j] = productName[j + 1];
				weight[j] = weight[j + 1];
				mfgDate[j] = mfgDate[j + 1];
				expDate[j] = expDate[j + 1];
				quantity[j] = quantity[j + 1];
				price[j] = price[j + 1];

			}

			totalitems--;


		}
	}
	if (a == 0)
	{
		cout << "Product Id Not Found " << endl;
	}
	else
		cout << "Item with product id " << Id << " deleted successfully." << endl;
}
void updateQuantity() {
	int Id, Q;
	int a = 0;
	cout << "Enter the product Id you wanna update ";
	cin >> Id;
	cout << "Enter the updated quantity ";
	cin >> Q;
	for (int i = 0; i < totalitems; i++)
	{
		if (productId[i] == Id)
		{
			a++;
			quantity[i] = Q;
			break;
		}
	}
	if (a == 0)
	{
		cout << "Product Id Not Found " << endl;
	}
	else

		cout << "Quantity of product id " << Id << " updated successfully to " << Q << endl;
}
void updatePrice() {
	int Id;
	float cost;
	int a = 0;
	cout << "Enter the product Id you wanna update ";
	cin >> Id;
	cout << "Enter the updated Price ";
	cin >> cost;
	for (int i = 0; i < totalitems; i++) {
		if (productId[i] == Id) {
			a++;
			price[i] = cost;
			break;
		}
	}
	if (a == 0)
	{
		cout << "Product Id Not Found " << endl;
	}
	else
		cout << "Price of product id " << Id << " updated successfully to" << cost << endl;
}
void searchPrice() {
	int Id;
	int a = 0;
	cout << "Enter the product Id= ";
	cin >> Id;

	for (int i = 1; i < totalitems; i++)

		if (productId[i] == Id)
		{
			cout << "The Price of item for following ID\t" << Id << " is = " << price[i] << endl;
			a++;
			break;
		}
	}
	if (a == 0)
	{
		cout << "Product Id Not Found " << endl;
	}
}
void updateDate() {
	int Id, mfg;
	int a = 0;
	string date;
	cout << "Enter the Id of product you wanna chnage ";
	cin >> Id;
	cout << "Press 1 for Mfg Date. Press 2 for Exp Date ";
	cin >> mfg;
	cout << "Enter the date you wanna change it to ";
	cin >> date;
	for (int i = 0; i < totalitems; i++) {
		if (productId[i] == Id) {
			a++;
			if (mfg == 1)
				mfgDate[i] = date;
			else if (mfg == 2)
				expDate[i] = date;
			else
				cout << "Wrong entry";

			break;
		}
	}
	if (a == 0)
	{
		cout << "Product Id Not Found " << endl;
	}
	else
		cout << "Mfg/Exp date of product id " << Id << " updated successfully to" << date << endl;
}
void searchQuantity() {
	int Id;
	int a = 0;
	cout << "Enter the Prodcut Id ";
	cin >> Id;
	for (int i = 0; i < totalitems; i++) {
		if (productId[i] == Id) {
			cout << "the quantity of item " << Id << " is" << quantity[i];
			a++;
			break;
		}

	}
	if (a == 0)
	{
		cout << "Product Id Not Found " << endl;
	}
}
void generateBill() {
	int n;
	int a = 0;
	int Id;
	int q;
	for (int i = 1; i < totalitems; i++)
	{
		cout << productId[i] << "\t\t" << productName[i] << "\t\t\t" << weight[i] << "\t\t" << price[i] << "\t\t\t" << quantity[i] << endl;
	}
	cout << "Enter the amount of items you have bought ";
	cin >> n;
	ofstream file;
	file.open("Bill.txt");
	double total = 0;
	file << "Product ID\tProduct Name\tQuantity\tPrice\t\tAmount" << endl;
	for (int i = 0; i < n; i++) {
		cout << "Enter the product ID  ";
		cin >> Id;
		cout << "Enter the quantity you bought  ";
		cin >> q;
		for (int j = 0; j < totalitems; j++) {
			if (productId[j] == Id)
			{
				if (q <= quantity[j])
				{
					a++;
					double amount = q * price[j];
					total += amount;
					quantity[j] = quantity[j] - q;
					file << productId[j] << "\t\t" << productName[j] << "\t\t" << q << "\t\t" << price[j] << "\t\t" << amount << endl;
					cout << "Bill generated successfully." << endl;
				}
				else
				{
					cout << "Quantity is exceeding available stock" << endl;
				}
			}
		}
	}
	if (a == 0)
	{
		cout << "Product Id Not Found " << endl;
	}
	file << "\n\nTotal = " << total << endl;
	file.close();

}
int main()
{

	readGroceryItems();
	cout << "*******************************************************************************************" << endl;
	cout << "*******************************************************************************************" << endl;
	cout << "                                   BHUPENDAR JOGI Store                                       " << endl;
	cout << "*******************************************************************************************" << endl;
	cout << "*******************************************************************************************" << endl;
	cout << "\n\t\tMenu";
	int Menu = 0;
	while (Menu != 10) {
		cout << "\n\t1.Print Grocery Items" << endl;
		cout << "\n\t2.Insert New Item" << endl;
		cout << "\n\t3.Search for Price" << endl;
		cout << "\n\t4.Delete an Item" << endl;
		cout << "\n\t5.Update Quantity" << endl;
		cout << "\n\t6.Update Price" << endl;
		cout << "\n\t7.Update mfg/exp date " << endl;
		cout << "\n\t8.Search Quantity " << endl;
		cout << "\n\t9.Generate Bill" << endl;
		cout << "\n\t10.Exit" << endl;
		cout << "\n\tSelect Suitable Option = ";
		cin >> Menu;
		cout << "\n\t***************************************************************" << endl;
		switch (Menu) {
		case 1: {
			printgroceryitems();
			break;
		}
		case 2: {insertGroceryItem();
			for (int i = 1; i < totalitems; i++)
			{
				cout << productId[i] << "\t\t" << productName[i] << "\t\t\t" << weight[i] << "\t\t" << price[i] << endl;
			}
			break;
		}
		case 3: {searchPrice();
			break;
		}
		case 4: {deleteGroceryItem();

			break;
		}
		case 5: {updateQuantity();
			for (int i = 1; i < totalitems; i++)
			{
				cout << productId[i] << "\t\t" << quantity[i] << endl;
			}
			break;
		}
		case 6: {updatePrice();
			for (int i = 1; i < totalitems; i++)
			{
				cout << productId[i] << "\t\t" << price[i] << endl;
			}
			break;
		}
		case 7: {updateDate();
			for (int i = 1; i < totalitems; i++)
			{
				cout << productId[i] << "\t\t" << mfgDate[i] << "\t\t" << expDate[i] << endl;
			}
			break;
		}
		case 8: {searchQuantity();
			break;
		}
		case 9: {generateBill();
			break;
		}
		}
	}
	return 0;
}











