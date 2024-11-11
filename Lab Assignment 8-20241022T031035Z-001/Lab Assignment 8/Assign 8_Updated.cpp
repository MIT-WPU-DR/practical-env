#include <iostream>
#include <string>
#include <list>
#include<iomanip>
using namespace std;
class items
{
 
list<int>item_code;
list<string>item_name;
list<int>item_qty;
list<float>item_cost;

list<int>::iterator itr_code;
list<string>::iterator itr_name;
list<int>::iterator itr_qty;
list<float>::iterator itr_cost;

public:
void get_itemlist();
void display_itemall();
void searchlist();
};

void items::get_itemlist()
{
    int count,code,qty;
    string name;
    float cost;
    cout<<"\nEnter the number of item Records for Inventory: ";
    cin>>count;
    for(int i=1;i<=count;i++)
    {
        cout<<"\n\nEnter Details of item: "<<i;
        cout<<"\n\nEnter item code: ";
        cin>>code;
        item_code.push_back(code);
        
        cout<<"\nEnter item name: ";
        cin>>name;
        item_name.push_back(name);
        
        cout<<"\nEnter the quantity: ";
        cin>>qty;
        item_qty.push_back(qty);
        
        cout<<"\nEnter cost:";
        cin>>cost;
        item_cost.push_back(cost);
    }
}
    
  
void items::display_itemall()
{
    itr_code=item_code.begin();
    itr_name=item_name.begin();
    itr_qty=item_qty.begin();
    itr_cost=item_cost.begin();
   
    cout<<"\n ---------------------------------------------------";
    cout<<"\n"<<setw(10)<<"| Item Code "<<"| Item Name "<<"| Item Quantity "<<"| Item Cost |";
    cout<<"\n ---------------------------------------------------"<<endl;
    while(itr_code!=item_code.end())
    {
        cout<<setw(8)<<*itr_code<<setw(12)<<*itr_name<<setw(12)<<*itr_qty<<setw(15)<<*itr_cost<<endl;
        itr_code++;
        itr_name++;
        itr_cost++;
        itr_qty++;
    }
          }
          
void items::searchlist()
{
    int key;
    cout<<"Enter the item code to be searched: ";
    cin>>key;
   itr_code=item_code.begin();
   itr_name=item_name.begin();
   itr_cost=item_cost.begin();
   itr_qty=item_qty.begin();
   
    while(itr_code!=item_code.end())
    {
        if(key==*(itr_code))
        {
            cout<<"\nRequested Item is available!"<<endl;
            cout<<"Item Code: "<<*itr_code<<endl;
            cout<<"Item Name: "<<*itr_name<<endl;
            cout<<"Item Quantity: "<<*itr_qty<<endl;
            cout<<"Item Cost: "<<*itr_cost<<endl;
                    }
        itr_code++;
        itr_name++;
        itr_cost++;
        itr_qty++;
    }
    
}          


int main()
{
    items obj;
    string key;
    int ch,chr;
    char x='y';
    cout<<"**************************************************************************"<<endl;
    cout<<"                        Inventory Management System                       "<<endl;
    cout<<"**************************************************************************"<<endl;
    do
    {
    cout<<"1. Enter Item details\n2. Display Item Information\n3. Search Item Entry\n4. Purchase Item\n\nEnter Your Choice:";
    cin>>ch;
    switch(ch)
        {
        case 1:
            obj.get_itemlist();
            obj.display_itemall();
            break;
        case 2:
            obj.display_itemall();
            break;
        case 3:
            obj.searchlist();
            break;
        case 4:
            
            break;
        default:
            cout<<"Wrong choice"<<endl;
        }
   
    cout<<"Do you wish to continue? Y or N\n";
    cin>>x;
    }
    while(x=='y'||x=='Y');
    cout<<"End of the Program";
       return 0;
}