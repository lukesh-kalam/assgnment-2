#include<iostream>
#include<string.h>
using namespace std;

class student
{
public:
    string name[100];
    string email[100];
    string fname[100];
    string sg[100];

    int count;
    int i,s;
    string Nname;
    string Nemail;
    student()
    {
        cout<<" student class constructor involked "<<endl;
    }
    void option()
    {
        int op;
        cout<<" press 1 to add list "<<endl;
        cout<<" \n press 2 to edit list " <<endl;
        cout<<" \n press 3 to delete list "<<endl;
        cout<<" \n press 4 to display "<<endl;
        cout<<" \n press 5 to search details by name "<<endl;
        cout<<" \n press 6 to search details by email "<<endl;
        cout<<" \n enter your option "<<endl;
        cin>>op;
        switch(op)
        {
            case 1: add();
                    break;
            case 2:edit();
                    break;
            case 3:del();
                    break;
            case 4:display();
                    break;
            case 5:sername();
                    break;
            case 6:seremail();
                    break;

        }
    }
    void add()
    {
        cout<<" enter the number items to add :- "<<endl;
        cin>>count;
        for(i=1;i<=count;i++)
        {
            cout<<" enter the name :- "<<endl;
            cin>>name[i];
            cout<<" Enter the email :- "<<endl;
            cin>>email[i];
            cout<<" Enter one friend name :- "<<endl;
            cin>>fname[i];
        }
        option();
    }
    void display()
    {
        sug();
        cout<<"serial.no "<<" \t "<< " name "<<" \t "<< " email "<<" friend name "<<" \t "<<" suggesion "<<endl;
        cout<<" ------------------------------------------------------------------------------- "<<endl;
        for(i=1;i<=count;i++)
        {
            cout<<i<<" \t \t "<<name[i]<<" \t "<<email[i]<<" \t "<<fname[i]<<" \t \t "<<sg[i]<<endl;
        }
        cout<<" \n \n "<<endl;
        option();
    }
    void edit()
    {
        cout<<" Enter the serial number to edit :- "<<endl;
        cin>>i;
        if(i<=count)
        {
        cout<<" Enter the new name and email:- "<<endl;
        getline(cin,name[i]);
        getline(cin,email[i]);
        }
        else
        {
            cout<<" Serial number not found "<<endl;
        }
        option();

    }
    void del()
    {
        cout<<" Enter the serial number to delete :- "<<endl;
        cin>>i;
        if(i<=count)
        {
            name[i].erase();
            email[i].erase();
        }
        else
        {
            cout<<" serial number not found "<<endl;

        }
        option();
    }
	void sug()
	{
		for(i=1;i<=count;i++)
        {
            for(int j=1;j<=count;j++)
            {
                int s1=fname[i].compare(name[j]);
                if(s1>0)
                {
                    sg[i]=fname[j];
                }
            }
        }
	}
    void sername()
    {
        string str;
        cout<<" enter name to search :- "<<endl;
        cin>>str;
        for(i=1;i<=count;i++)
        {
            int a=str.compare(name[i]);
            if(a>0)
            {
                cout<<" sno "<<" \t \t "<<" name "<<" \t \t"<<" email "<<endl;
                cout<<i<<" \t \t "<<name[i]<<" \t \t "<<email[i]<<endl;
            }
            else
            {
                cout<<" entered search name not found "<<endl;
            }
        }
        option();
    }
    void seremail()
    {
        string str;
        cout<<" enter name to search :- "<<endl;
        cin>>str;
        for(i=1;i<=count;i++)
        {
            int a=str.compare(email[i]);
            if(a>0)
            {
                cout<<" sno "<<" \t \t "<<" name "<<" \t \t"<<" email "<<endl;
                cout<<i<<" \t \t "<<name[i]<<" \t \t "<<email[i]<<endl;
            }
            else
            {
                cout<<" entered search email not found "<<endl;
            }
        }
        option();
    }
};
int main()
{
    student obj;
    obj.option();

return 0;

}
