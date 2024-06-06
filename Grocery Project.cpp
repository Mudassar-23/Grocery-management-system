////////////////////////////  ********* ( PF PROJECT ) ********** ///////////////////////
/////////////////////************ ( GROCERY STORE SYSTEM )  ************///////////////
#include<iostream>   
#include<fstream>
#include<string>

using namespace std;

int productId[50];
string productName[50];
double  weight[50];
string mfgDate[50];
string expDate[50];
double price[50];
int quantity[50];

int cart[50];
int cart_qty[50];
int cart_size = 0;

// Function to read an item from input file
void read_Items() {
    ifstream inFile;

    inFile.open("d:\\grocery.txt");
    if (inFile.is_open()) {
        for (int i = 0; i < 50; i++) {
            // read data from files ( items )
            inFile >> productId[i] >> productName[i] >> weight[i] >> mfgDate[i] >> expDate[i] >> price[i] >> quantity[i];
        }

        inFile.close();
    }
}
void searchItem() {
    int id;

    cout << "--> Enter the Product id (100 - 149 ) : ";
    cin >> id;
          
    for (int i = 0; i < 50; i++) {

        if (productId[i] == id) {
            cout << "--> Product name : " << productName[i] << endl;
            cout << "--> Expiry date of Product : " << expDate[i] << endl;
            cout << "--> Price :  " << price[i] << endl;
            break; // exit loop since item has been found
        }
    }
}
void insert_Item() {
    int id, qty, n;
     // prints items on console
    cout << "--> Items in the Grocery Store" << endl;
    for (int i = 0; i < 50; i++) {
        cout << "\t" << productId[i] << "\t" << productName[i] << "\t" << price[i] << endl;
    }

    cout << "--> How many items you want to buy: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {  // this loop runs , how he items buy
        cout << "--> Enter the product ID (100-149) you want to add in cart: " << endl;
        cin >> id;
        cout << "--> ENter quantity: " << endl;
        cin >> qty;

        // cheak if the item is avaliable in repository , and add the item in cart
        for (int j = 0; j < 50; j++) {
            if (productId[j] == id && quantity[j] >= qty) {
                // cheak
                if (cart_size >= 50) {
                    cout << "Cart is full . cannot add more items." << endl;
                }
                // add the item to the cart
                cart[cart_size] = j;
                cart_qty[cart_size] = qty;   // add quantity of item in cart

                cart_size++; // it increments , mean item added in cart

                quantity[j] -= qty; // update quantity of item in repository

                cout << "-> Item is" << "\t" << id << "\t" << productName[j] << "\t" << price[j] << "\t" << "added to cart" << endl;
                break; //exit the loop after adding item in cart
            }
            else if (productId[j] == id && quantity[j] < qty) {
                // Inform the user that the requested quantity is not available
                cout << "-> Insufficient quantity of item  " << id << "  in the repository" << endl;
                break;
            }

        }
    }
  
}

void delete_Item() {
    int id;
    cout << "--> Enter id of product you want to delete:" << endl;
    cin >> id;

    int count = 0;

    for (int  i = 0; i < cart_size; i++)
    {
        int index = cart[i]; // get the actual index in the cart array
        if (productId[index] == id) {
            count++; // if statement is true counter increment
            
            for (int j = i; j < cart_size - 1; j++) {
                // move all items after this one back by one position
                cart[j] = cart[j + 1];
            }
            cart_size--;   // item remove from cart
            break; 
        }
    }
    
    if (count == 0) {
        cout << "-> Product not found" << endl;
    }
    else {
        cout << "-> Item" << "\t" << id << "removed from cart successfully" << endl;
    }
}

void updateQuantity() {

    int id;
    int qty;
    int count = 0; 
    cout << "--> Enter The PRoduct id, to update(100 -149)" << endl;
    cin >> id;
    cout << "--> Enter the updated quantity" << endl;
    cin >> qty;

    for (int i =0; i < 50; i++) {
        if (productId[i] == id) {
            count++;  
            quantity[i] = qty; 
            break;
        }
    }
    if (count == 0) {
        cout << "->Product id not found " << endl;
        cout << "->Quantity Doesnot update " << endl;
    }
    else {
        cout << "->Quantity of product ID " << id << "Updated " << qty << endl;
    }
    // this loop shows that quantity updates of an item on console
    for (int i = 0; i < 50; i++) {
        cout << "\t" << productId[i] << "\t" << productName[i] << "\t" << quantity[i]  << endl;
    }
}

void finalizeOrder() {
    string name; string  address; string  number;
    cout << "(*)-> Enter Your First Name ";      
    cin >> name;       


    cout << "(*)-> Enter your address (without spaces ) ";
    cin >> address;


    cout << "(*)-> Enter your number ";
    cin >> number;

    double total = 0.0;
    const double discount_rate = 0.2;// 20% discount
    const double delivery_charges = 200;
    const double tax_rate = 0.05; // 5 % TAX

    ofstream outFile;    // generate bill in output file
    outFile.open("d:\\Bill.txt");    

    outFile << "(*)->****************( Welcome )************<-(*)" << endl;
    outFile << "*************************************************" << endl;
    outFile << "                  ALEX STORE                  " << endl;
    outFile << "***********************************************" << endl;
    outFile << "\n";

    cout << "\t************************************" << endl;
    cout << "-> Finalizing order for " << name << endl;
    cout << "-> User address  " << address << endl;
    cout << "-> User number " << number << endl;
    cout << "\t***********************************" << endl;
    // display in output file
    outFile << "\t************************************" << endl;
    outFile << "-> Finalizing order for " << name << endl;
    outFile << "-> User address  " << address << endl;
    outFile << "-> User number " << number << endl;
    outFile << "\t***********************************" << endl;

    outFile << "\n";
    outFile << "\t************************************" << endl;
    outFile << "-> Items in the Cart:" << endl;

   for (int i = 0; i < cart_size; i++) {
       int index = cart[i]; // get the actual index in the cart array
       double itemTotal =  price[index] * cart_qty[i];

       cout << " (*)->Item ID :" << cart[i] << "\t" << "Product Name :" << productName[index] << "\t" << "Price :" << price[index] << "\t" << "Quantity :" << cart_qty[i] << endl;
       outFile << " (*)->Item ID :" << cart[i] << "\t" << "Product Name :" << productName[index] << "\t" << "Price :" << price[index] << "\t" << "Quantity :" << cart_qty[i] << endl;
        total = total + itemTotal;
    }
          // this condition work if order is equal or greater than 5
    if (cart_size >= 5) { 
        total = total * (1 - discount_rate);

        cout << "(*)->A 20% discouny has been applied to Loyal Customer" << endl;
        outFile << "(*)->A 20% discouny has been applied to Loyal Customer" << endl;
    }
    // calculates tax amount
    double taxamount = total * tax_rate;
    // add tax in total ( see above )
    total = total + taxamount;
    // add delivery charges , wavied of deleviery charges
    if (total > 10000) {  
        delivery_charges == 0;
        cout << "Your cart price exceeds 10,000 PKR delivery charges wavied off " << endl;
        
    }

    total = total + delivery_charges;

    cout << "\n";
    cout << "\tThe tax is 5 % applied " << endl; 
    cout << "\tThe delivery charges is 200 PKR" << endl;
    cout << "\tThe discount is applied if order is greater than 5" << endl;

    cout << "\t==================================" << endl;
    cout << "\t(*)->Total Bill Cost : " << total << endl;
    cout << "\t==================================" << endl;
    // display in output file
    outFile << "\n";
    outFile << "\tThe tax is 5 % applied " << endl;
    outFile << "\tThe delivery charges is 200 PKR" << endl;
    outFile << "\tThe discount is applied 20% if order is greater than 5" << endl;
    
    outFile << "\t======================================" << endl;
    outFile << "\t(*)->Total Bill Cost : " << total << endl;
    outFile << "\t=====================================" << endl;
    outFile << "\n";
    outFile << "\n*************************" << endl;
    outFile << "\n(*)Thanks for shopping(*)" << endl;
    outFile << "\n*************************" << endl;

    outFile.close();
 }

 
void main() {


    read_Items();  

    int choice;
    cout << "*->****************( Welcome )************<-*" << endl;
    cout << "*********************************************" << endl;
    cout << "                 ALEX STORE                  " << endl;
    cout << "*********************************************" << endl;
    
    while (true){
        cout << "\t1: Search Item in the Repository" << endl;
        cout << "\t2: Insert an Item in Cart" << endl;
        cout << "\t3  Delete an item in Cart" << endl;
        cout << "\t4: Update Quantity of Item" << endl;
        cout << "\t5: Finalized Order & Provide User Details  " << endl;
        cout << "\t6: Exiting Program" << endl;
        cout << "\tENter the Choice you want : ";
        cin >> choice;
           
        if (choice == 1) {
            searchItem();
        }

        else if (choice == 2) {

            insert_Item();

        }
        else if (choice == 3){

            delete_Item();
        }
        else if (choice == 4){
            updateQuantity();

        }
        else if (choice == 5) {
            finalizeOrder();

        }
        else if (choice == 6){
            cout << "\n*************************" << endl;
            cout << "\n(*)Thanks for shopping(*)" << endl;
            cout << "\n**************************" << endl;
            break;
        }
    }
}

