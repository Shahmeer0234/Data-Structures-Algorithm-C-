#include <iostream>
#include <string>
using namespace std;

class Item{
	private:
		int id;
		string name;
		int quantity;
		float price;
	public:
		Item() : id(0), name(""), quantity(0), price(0.0) {}
		
		Item(int i, string n, int q, float p) : id(i), name(n), quantity(q), price(p) {}
		
		int getId() {
			return id;
		}
		
		void displayItem() {
			cout<<"=====Item Details====="<<endl;
			cout<<"ID: "<<id<<endl;
			cout<<"Name: "<<name<<endl;
			cout<<"Quantity: "<<quantity<<endl;
			cout<<"Price: "<<price<<endl;
			cout<<"======================"<<endl;
		}
		
		void updateItem(string n, int q, float p) {
			name = n;
			quantity = q;
			price = p;
			cout<<"=====Item Updated======"<<endl;
		}
};

class Inventory{
	private:
		Item items[50];
		int count;
	public:
		Inventory() {
			count = 0;
		}
		void addItem() {
			if (count>=50) {
				cout<<"=====Inventory is Full====="<<endl;
				return;
			}
			int id, qty;
			string name;
			float price;
			
			cout<<"Enter Item ID: ";
        	cin>>id;
        	cout<<"Enter Item Name: ";
        	cin>>name;
        	cout<<"Enter Quantity: ";
        	cin>>qty;
        	cout<<"Enter Price: ";
        	cin>>price;
        	
        	items[count] = Item(id, name, qty, price);
        	count++;
        	cout<<"=====Item Added Successfully!======"<<endl;
			}
		
		void searchItem() {
        	int id;
        	cout<<"Enter Item ID to Search: ";
        	cin>>id;

        	for (int i = 0; i < count; i++) {
            	if (items[i].getId() == id) {
                	cout<<"=====Item Found!====="<<endl;
                	items[i].displayItem();
                	return;
            	}
        	}
        	cout<<"=====Item Not Found!====="<<endl;
    	}
    	void updateItem() {
        	int id;
        	cout<<"Enter Item ID to Update: ";
        	cin>>id;

        	for (int i = 0; i < count; i++) {
            	if (items[i].getId() == id) {
                	string name;
                	int qty;
                	float price;

                	cout<<"Enter New Name: ";
                	cin>>name;
                	cout<<"Enter New Quantity: ";
                	cin>>qty;
                	cout<<"Enter New Price: ";
                	cin>>price;

                	items[i].updateItem(name, qty, price);
                	return;
            	}
        	}
        	cout<<"=====Item Not Found!====="<<endl;
    	}
    	void deleteItem() {
        	int id;
        	cout<<"Enter Item ID to Delete: ";
        	cin>>id;

        	for (int i = 0; i < count; i++) {
            	if (items[i].getId() == id) {
                	for (int j = i; j < count - 1; j++) {
                    	items[j] = items[j + 1];
                	}
                	count--;
                	cout<<"=====Item Deleted Successfully!====="<<endl;
                	return;
            	}
        	}
        	cout<<"=====Item Not Found!====="<<endl;
    	}
    	void displayAll() {
        	if (count == 0) {
            	cout<<"=====Inventory is Empty!====="<<endl;
            	return;
        	}
        	cout<<"=====Inventory Items====="<<endl;
        	for (int i = 0; i < count; i++) {
            	items[i].displayItem();
        	}
    	}
};

int main() {
	Inventory inv;
    int choice;

    do {
        cout<<"\n=====Inventory Management System=====" << endl;
        cout<<"1. Add Item" << endl;
        cout<<"2. Search Item" << endl;
        cout<<"3. Update Item" << endl;
        cout<<"4. Delete Item" << endl;
        cout<<"5. Display All Items" << endl;
        cout<<"6. Exit" << endl;
        cout<<"Enter Choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                inv.addItem();
                break;
            case 2:
                inv.searchItem();
                break;
            case 3:
                inv.updateItem();
                break;
            case 4:
                inv.deleteItem();
                break;
            case 5:
                inv.displayAll();
                break;
            case 6:
                cout<<"Exiting System..."<<endl;
                break;
            default:
                cout<<"=====Invalid Input====="<<endl;
        }
    } while (choice != 6);
	
	return 0;
}