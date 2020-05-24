#include<iostream>
#include<map>
#include<string.h>
using namespace std;

class student           //creating class
{
public:
    map<string,string> mp1;
    map<string,string> mp2;
    map<string,string> mp3;
    student()           //student class constructor
    {
        cout<<"Student class constructor is involked "<<endl;
        cout<<" Press 1 to add user "<<endl;
        cout<<" press 2 to display user list"<<endl;
        cout<<" press 3 to search user list"<<endl;
        cout<<" press 4 to delete user list"<<endl;
        cout<<" press 5 to search by friend "<<endl;
        cout<<" press 6 to get suggssion "<<endl;
        cout<<" press 7 to only display list "<<endl;
    }
     void option()      //menu card
    {

        int op;
        cout<<" Enter the option :-  "<<endl;
        cin>>op;
        switch(op)
        {
            case 1 : add();
                     break;
            case 2: display();
                    break;
           case 3: search();
                   break;
            case 4:erase();
                    break;
            case 5:srchByFriend();
                    break;
            case 6:sugges();
                    break;
            case 7:onlyDisplay();
                    break;
            default:
                    cout<<" Entered option is in valid "<<endl;
        }
    }

    void add()              //function to add
    {
        string name;
        string email;
        string frnd;
        char a;
        cout<<" Enter the name "<<endl;
        cin>>name;
        cout<<" Enter the email "<<endl;
        cin>>email;
        cout<<" Enter friend name "<<endl;
        cin>>frnd;
        mp1.insert(make_pair(name,email));  //inserting
        mp2.insert(make_pair(name,frnd));
        cout<<" press a to add more or any key to go to options "<<endl;
        cin>>a;
        if(a=='a') { adding(); }
        else { option(); }

    }

      void adding()                  //adding more tolist
    {
        string name;
        string email;
        string frnd;
        char a;
        cout<<" Enter the name "<<endl;
        cin>>name;
        cout<<" Enter the email "<<endl;
        cin>>email;
        cout<<" Enter friend name :- "<<endl;
        cin>>frnd;
        cout<<" press a to add more or any key to go to options "<<endl;
        cin>>a;
        mp1.insert(make_pair(name,email));
        mp2.insert(make_pair(name,frnd));
        if(a=='a') { add(); }
        else { option(); }
    }

     void display()         //To display the list
    {
            cout<<" name "<<" \t \t "<<" email "<<"\t \t "<<" friend name "<<endl;
            for(auto it=mp1.begin();it!=mp1.end();it++) //using iterator
            {
                for(auto et=mp2.begin();et!=mp2.end();et++)
                {
                      string p=it->first;
                      string q=et->first;
                      if(p==q)
                      {
                          cout<<it->first<<" \t\t"<<it->second<<" \t\t "<<et->second<<endl;
                       }
                }
            }
            option();
    }
   void erase()             //delete function
    {
        string str;
        cout<<" Enter the name to delete :- "<<endl;
        cin>>str;
        for(auto it=mp2.begin();it!=mp2.end();it++)
        {
            for(auto et=mp1.begin();et!=mp1.end();et++)
            {
                if(et->first==str && it->first==str)
                {
                    mp1.erase(it->first);
                    mp2.erase(it->first);
                }
                if(et->second==str)
                {
                    string a;
                    a=et->first;
                    if(et->first==a && it->first==a)
                    {
                        mp1.erase(it->first);
                        mp2.erase(it->first);
                    }
                }
            }
        }
        option();
    }
    void search()       //searching function
    {
        string str;
        cout<<" enter name or email-id to search :- "<<endl;
        cin>>str;
        cout<<"Name"<<"\t \t"<<"Email"<<" \t\t "<<"Friend Name "<<endl;

        for(auto it=mp2.begin();it!=mp2.end();it++)
        {
            for(auto et=mp1.begin();et!=mp1.end();et++)
            {
                if(it->first==str && et->first==str)        //condition check
                {
                    cout<<it->first<<" "<<it->second<<"  "<<et->second<<endl;
                    option();
                }
                if(it->second==str)
                {
                    string a;
                    a=et->first;
                    if(et->first==a && it->first==a)
                    {
                        mp1.erase(et->first);       //erase from list
                        mp2.erase(it->first);
                    }
                }
            }


        }
    }
    void edit()     //editing function
    {
         string name;
         string Nname;
         string email;
         string nFrnd;
         cout<<" name to edit details "<<endl;
         cin>>name;
         cout<<" Propose a new name "<<endl;
         cin>>Nname;
         cout<<" new email "<<endl;
         cin>>email;
         cout<<" Enter the new friend name "<<endl;
         cin>>nFrnd;
         mp1.erase(name);
         mp2.erase(name);
         mp1.insert(make_pair(Nname,email));
         mp2.insert(make_pair(Nname,nFrnd));
        option();
    }
    ~student()
    {
        cout<<" Destructor is involked "<<endl;
    }
    void srchByFriend()
    {
        string fd;
        cout<<" Enter the friend name:- "<<endl;
        cin>>fd;
        for(auto et=mp2.begin();et!=mp2.end();et++)
        {
            string ele;
            ele=et->second;
            if(fd==ele)
            {
                cout<<et->second<<" is the friend of "<<et->first<<endl;
            }
        }
        option();
    }
     void onlyDisplay()         //To display the list
    {
            cout<<" name "<<" \t \t "<<" email "<<"\t \t "<<" friend name "<<endl;
            for(auto it=mp1.begin();it!=mp1.end();it++) //using iterator
            {
                for(auto et=mp2.begin();et!=mp2.end();et++)
                {
                      string p=it->first;
                      string q=et->first;
                      if(p==q)
                      {
                          cout<<it->first<<" \t\t"<<it->second<<" \t\t "<<et->second<<endl;
                       }
                }
            }

    }
    void sugges()   //function for suggession
    {
        string sug;
        cout<<" Enter the name to find suggssion :- "<<endl;
        cin>>sug;
        for(auto et=mp2.begin();et!=mp2.end();et++)
        {
            string a=et->first;
            if(sug==a)
            {
                string b=et->second;
                for(auto it=mp2.begin();it!=mp2.end();it++)
                {
                    if(b==it->first)
                    {
                        cout<<sug<<" suggesion is :- "<<it->second<<endl;
                    }
                }
            }
        }
        option();
    }

};
int main(int argc,char* argv[])
{
 if(argc>=2)
    {
        if(strcmp(argv[1],"-h")==0)     //help command
        {
            cout<<" case-1 "<<endl;
        }
    }

    else
    {
        student obj;            //creating object
        obj.option();
    }
}

