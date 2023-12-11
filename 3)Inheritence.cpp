//Name:Piyush Maonj Jain||Roll no:36||Div:SE-A

//Problem Statement: Imagine a publishing company which does marketing for book and audio cassette versions. Create a class publication that stores the
//title (a string) and price (type float) of publications. From this class derive two classes: book which adds a page count (type int) and tape which
//adds a playing time in minutes (type float).Write a program that instantiates the book and tape class, allows user to enter data and displays the data
//members. If an exception is caught, replace all the data member values with zero values

#include <iostream>
using namespace std;

class Publication{
public:
 string title;
 float price;

 Publication(){
    title = "None";
    price = 0.0;
 }

 void bc_getdata(string s){
    cout<<"Enter the title of the " << s <<": ";
    cin>>title;

    bool flag=false;
    while(flag==false)
    {
        cout<<"Enter Price(in Rs) of the "<< s << ": ";
        cin>>price;
        try{
            if(price<=0)
                throw price;
            else
                flag=true;
        }
        catch(float x){
        cout<<"Price "<<x<<" is invalid!.\nPlease Enter price again.\n"<<endl;
        }
    }

 }

 void bc_putdata(string s){
    cout<< s <<" Title: "<<title<<endl;
    cout<< s <<" Price: "<<price<<"Rs"<<endl;
 }
};

class Book:public Publication{
    public:
    int pages=0;

        void book_getdata()
        {
            bool flag=false;
            while(flag==false)
            {
                cout<<"Enter the no. of pages: ";
                cin>>pages;
                try
                {
                    if(pages<=0)
                        throw pages;
                    else
                        flag=true;
                }
                catch(int x)
                {
                    cout<<pages<<" is not a valid page input!\nPlease try again.\n"<<endl;
                }
            }
        }

        void book_putdata(){
            cout<<"Book's no. of pages: "<<pages<<endl;
        }

};

class tape: public Publication{
public:
    float time=0.0;
    void tape_getdata()
    {

        bool flag=false;
        while(flag==false)
        {
            cout<<"Enter Playing time of tape(in minutes): ";
            cin>>time;
            try
            {
                if(time<=0)
                throw time;
                else
                flag=true;
            }
            catch (float x)
            {
                cout<<x<<" is an invalid input.\nPlease try again."<<endl;
            }
        }

    }

    void tape_putdata(){
        cout<<"Tape's play time: "<<time<<" minutes"<<endl;
    }
};

int main(){
    int ch;
    Book bobj;
    tape tobj;

    cout<<"\t***Welcome to Gokhale Publications***"<<endl;
    do
    {
        cout<<"\n\t***MENU***";
        cout<<"\n1)Search for a book.\n2)Serach for an audio Cassette.\n3)Display Book details.\n4)Display audio cassette details.\n5)Exit";
        cout<<"\nMake your choice:-";
        cin>>ch;
        cout<<endl;

        switch(ch)
        {
        case 1: bobj.bc_getdata("Book");
                bobj.book_getdata();
                cout<<"****PROCESS COMPLETED*****";
                cout<<endl;
                break;
        case 2: tobj.bc_getdata("Tape");
                tobj.tape_getdata();
                cout<<"****PROCESS COMPLETED*****";
                cout<<endl;
                break;
        case 3: bobj.bc_putdata("Book");
                bobj.book_putdata();
                cout<<"****PROCESS COMPLETED*****";
                cout<<endl;
                break;
        case 4: tobj.bc_putdata("Tape");
                tobj.tape_putdata();
                cout<<endl;
                cout<<"****PROCESS COMPLETED*****";
                break;
        default: cout<<"You have entered an invalid choice! Please enter a valid one.";
        }

    }while(ch!=5);

cout<<"Thank You. Visit again!!";
return 0;
}




