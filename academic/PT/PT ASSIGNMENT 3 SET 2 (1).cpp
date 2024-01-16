//TAN ZHI MING A23CS0189 NG YUHIN A23CS0148
#include <iostream>
using namespace std;
const int MAX_OPERATIONS=100;
void displayMainMenu();
void performMultiplication(int&);
void displayResults(int);
int multiplyUsingAddition(int[],int);
int operands1[MAX_OPERATIONS],results[MAX_OPERATIONS];
int arrayCounter1=0,arrayCounter2=0;
int num[MAX_OPERATIONS];

int main() {
    int operationCount=0,choice;
    do{
        cout<<endl;
        cout<<"<<<<<Main Menu>>>>>"<<endl;
        cout<<"============================="<<endl;
        displayMainMenu();
        do{
            cout<<"Enter your choice: ";
            cin>>choice;
        }while((choice!=1)&&(choice!=2)&&(choice!=3));
        cout<<endl;
        if (choice==3) {
            cout << "Goodbye!" << endl;
            break;
        }
        switch (choice) {
            case 1:performMultiplication(operationCount);break;
            default:displayResults(operationCount);break;
        }
    }while(choice!=3);
    return 0;
}

void displayMainMenu(){
    cout<<"1. Perform Multiplication"<<endl;
    cout<<"2. Display Results"<<endl;
    cout<<"3. Quit"<<endl;

}

void performMultiplication(int& counter){
	char choice2;
label2:    cout<<"Enter the number of operands for multiplication: ";
    cin>>num[counter];
    if ((arrayCounter1+num[counter])>MAX_OPERATIONS){
        cout<<"Exceed the limit of number operands !"<<endl;
        do{
        	cout<<"Back to the menu? (y/n) : ";
        	cin>>choice2;
        	cout<<endl;
		}while ((choice2!='y')&&(choice2!='n'));

        if(choice2=='y'){
        	return;
		}else
			goto label2;
    }
    for (int i=1;i<=num[counter];i++){
        cout<<"Enter operand "<<i<<": ";
        cin>>operands1[arrayCounter1];
        arrayCounter1++;
    }
    results[counter]=multiplyUsingAddition(operands1,num[counter]);
    counter++;
    cout<<endl;
    cout<<"Multiplication performed successfully!"<<endl;

}

int multiplyUsingAddition(int a[],int b){
    int total=0;
    int num=a[arrayCounter1-b];
    for (int c=1;c<b;c++) {

        total=0;
        for (int i = 0; i < a[(arrayCounter1 - b + c)]; i++) {
            total += num;
        }
        num = total;
    }
    return total;
}


void displayResults(int opeCount){
    cout<<"Results of Mathematical Operations:"<<endl;
    cout<<"========================================"<<endl;
    for (int i=1;i<=opeCount;i++){
        cout<<"Operation "<<i<<" "<<results[(i-1)]<<" (Operands: "<<num[(i-1)]<<")"<<endl;
        cout<<endl;
    }
}
