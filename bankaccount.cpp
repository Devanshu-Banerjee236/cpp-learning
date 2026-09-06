#include <iostream>
#include <string>
#include <vector>
using namespace std;
class BankAccount{
    private:
    float Balance;
    long long AccNo;
    public:
    string name;
    void SetBalance(float b){
        if(b>=0){
            Balance=b;
        }
    }
    void SetAccNo(long long a){
        if (a>=0){
            AccNo=a;
        }
    }
    void deposit(){
        float amount;
        cout<<"Enter amount to deposit:"<<endl;
        cin>>amount;
        Balance+=amount;
        cout<<"Now your current balance is:"<<Balance<<endl;
    }
    void withdraw (){
        float amount;
        cout<<"Enter amount to withdraw:"<<endl;
        cin>>amount;
        if (amount<=Balance){
            Balance-=amount;
            cout<<"Now your current balance is"<<Balance<<endl;
        }
        else{
            cout<<"Balance insufficient"<<endl;
        } 
    }
    void display(){
        cout<<name<<endl;
        cout<<AccNo<<endl;
        cout<<Balance<<endl;
    }
    long long GetAccNo(){
        return AccNo;
    }
    int GetBalance(){
        return Balance;
    }
    BankAccount(string n,long long acc,float bal)
    {
        name=n;
        AccNo=acc;
        Balance=bal;
    }
    BankAccount(){}
};
int main(){
    vector <BankAccount> BankAccounts;
    int No;
    cout<<"Enter the number of accounts you want to open: ";
    cin>>No;
    for(int i=0; i<No; i++){
        BankAccount b;
        cout<<"Enter your name:";
        cin>>b.name;
        long long acc;
        cout<<"Enter your account no:";
        cin>>acc;
        b.SetAccNo(acc);
        int bal;
        cout<<"Enter the balance:";
        cin>>bal;
        b.SetBalance(bal);
        BankAccounts.push_back(b);
    }
    for (int i=0;i<BankAccounts.size();i++){
        BankAccounts[i].display();
    }
    long long Acc;
    cout<<"Enter the ACCOUNT NUMBER of the account you want to access:";
    cin>>Acc;
    bool found=false;
    for(int i=0;i<No;i++){
        if (Acc==BankAccounts[i].GetAccNo()){
            found=true;
            int choice;
            cout<<"1.DEPOSIT\n2.WITHDRAW\n3.DISPLAY"<<endl;
            cout<<"Enter your choice:";
            cin>>choice;
            if (choice==1){
                BankAccounts[i].deposit();
            }
            if (choice==2){
                BankAccounts[i].withdraw();
            }
            if (choice==3){
                BankAccounts[i].display();
            }
        }
    }
    if(found==false){
        cout<<"Account not found"<<endl;
    }
    return 0;
}