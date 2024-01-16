//TANZHIMING A23CS0189 NGYUHIN A23CS0148
//PT ASSIGNMENT 3 SET1
#include <iostream>
using namespace std;
const int MAX_BOOKS=3;
void displayMainMenu();
void addBook(string&,string&,int&);
void displayLibrary(string[],string[],int[],int);
void searchByTitle(string[],string[],int[],int);
int main() {
    string title[MAX_BOOKS],author[MAX_BOOKS];
    int publication[MAX_BOOKS],choice,newYear,counter=0;
    string newTitle,newAuthor;
    do{
    	cout<<endl;
        cout<<"<<<<<Library Management System>>>>>"<<endl;
        cout<<"========================================"<<endl;
        displayMainMenu();
        do{
            cout<<"Enter your choice: ";
            cin>>choice;
        }while(choice!=1 && choice!=2 &&choice!=3 &&choice!=4 );
        if(choice==1){
        	if((counter)>=MAX_BOOKS){
        		cout<<"Exceed book limit,cannot add anymore!"<<endl;
        		continue;
			}
		}
        cout<<endl;
        switch (choice){
            case 1:{
                addBook(newTitle,newAuthor,newYear);
                title[counter]=newTitle;
                author[counter]=newAuthor;
                publication[counter]=newYear;
                counter++;
                break;
            }
            case 2:displayLibrary(title,author,publication,counter);break;
            case 3:searchByTitle(title,author,publication,counter);break;
            default:break;
        }

    }while(choice!=4);
    cout<<"Goodbye!"<<endl;
    return 0;
}

void displayMainMenu(){
    cout<<"1. Add a book"<<endl;
    cout<<"2. Display Library"<<endl;
    cout<<"3. Search by Title"<<endl;
    cout<<"4. Quit"<<endl;
}

void addBook(string& a,string& b,int& c){
    cout<<"Enter book title: ";
    cin>>a;
    cout<<"Enter author name: ";
    cin>>b;
    cout<<"Enter publication year: ";
    cin>>c;
    cout<<"\nBook added succesfully!"<<endl;
}

void displayLibrary(string title[],string author[],int year[],int c){
    cout<<"Library Contents:"<<endl;
    cout<<"===================="<<endl;
    for (int i=0;i<c;i++){
        cout<<"Title: "<<title[i]<<endl;
        cout<<"Author: "<<author[i]<<endl;
        cout<<"Year: "<<year[i];
        cout<<"\n";
    }

}

void searchByTitle(string title[],string author[],int year[],int c){
    string keyword;
    int index;
    cout<<"Enter the title to search: ";
    cin>>keyword;
    for (int i=0;i<c;i++){
        if (keyword==title[i])
            index=i;
        else
            index=-1;
    }
    cout<<endl;
    if (index==-1)
        cout<<"No Book was found!";
    else {
        cout<<"Book found:"<<endl;
        cout<<"===================="<<endl;
        cout << "Title: " << title[index] << endl;
        cout << "Author: " << author[index] << endl;
        cout << "Year: " << year[index] << endl;
    }
}