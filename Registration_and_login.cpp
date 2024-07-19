#include<iostream>
#include<fstream>
using namespace std;


class temp{
    string username,Email,Password;
    string searchName,SearchPass,searchEmail;
    fstream file;
    public:
    void login();
    void signUP();
    void Forgot();

}obj;


int main(){

    char choice;
    cout<<"\n 1. Signup ";
    cout<<"\n 2. Login ";
    cout<<"\n 3. Forgot Password ";
    cout<<"\n 4. Exit ";
    cout<<"Enter your choice  ::"<<endl;
    cin>>choice;
    cin.ignore();


    switch (choice)
    {
    case '1':
    obj.signUP();

        break;
    case '2':
    obj.login();
        break;
    case '3':
    obj.Forgot();
        break;
    case '4':
    return 0;
        break;
    
    default:

        cout<<"Invalid Selection ......";
    }

}

void temp::signUP(){
    cout<<"\n Enter Your Username ::";
    getline(cin,username);
    cout<<"Enter Your Email Address ::";
    getline(cin,Email);
    cout<<"Enter Your Password ::";
    getline(cin,Password);

    file.open("LoginData.txt" , ios:: out | ios ::app);
    file<<username<<"*"<<Email<<"*"<<Password<<endl;
    file.close();
    cout<<"YOU SUCESSFULLY CREATE YOUR ACCOUNT"<<endl;
}

void temp::login(){
    cout<<"--------LOGIN--------"<<endl;
    cout<<"Enter your Userame ::"<<endl;
    getline(cin,searchName);
    cout<<"Enter your Password ::"<<endl;
    getline(cin,SearchPass);
    file.open("LoginData.txt",ios::in);
    getline(file,username,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');

    while (!file.eof())
    {
        if(username==searchName){
            if(Password==SearchPass){
                cout<<"You Sucessfully Login"<<endl;
                cout<<"\n Username  ::"<<username<<endl;
                cout<<"\n Email ::"<<Email<<endl;
                cout<<"You sucessfully Login in your account"<<endl;
            }
            else{
                cout<<"Please Enter your valid Username and Password"<<endl;
            }
            getline(file,username,'*');
            getline(file,Email,'*');
            getline(file,Password,'\n');
        }
        file.close();
    }
}

void temp ::Forgot(){
    cout<<"Enter your Username ::";
    getline(cin,searchName);
    cout<<"Enter your Email Address ::";
    getline(cin,searchEmail);

    file.open("LoginData.txt",ios :: in);
    getline(file,username,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');
    while (!file.eof())
    {
        if(username==searchName){
            if(Email==searchEmail){
                cout<<" Account Found ... "<<endl;
                cout<<"Your Password is :: "<<Password<<endl;

            }
            else{
                cout<<"Email not found in Database"<<endl;
            }


        }
        else{
            cout<<"Your Username does not exits in Database"<<endl;
        }

    }
    file.close();
    }