#include<iostream>
#include<string.h>
using namespace std;
class matrix                    //matrix class is created
{
public:
   char arr[100][100],arr1[100][100],arr2[100][100],arr3[100][100];      //created empty array and required things
    int row,col,i,j,k,n;
    matrix()                    //constructor
    {
        cout<<" constructor of matrix is involked "<<endl;
        cout<<" press 1 for column operation "<<endl;
        cout<<" press 2 for row operation "<<endl;
        cout<<" press 3 for diagonal operation "<<endl;
    }
    void option()               //menu card
    {
        int op;
        cout<<" Enter the option :-  "<<endl;
        cin>>op;
        switch(op)
        {
            case 1 : column_op();
                     break;
            case 2: row_op();
                    break;
           case 3: diagonal_op();
                   break;
            default:
                    cout<<" Entered option is in valid "<<endl;
        }
    }
    ~matrix()                       //destructor
    {
        cout<<" Matrix Class Destructor is involked "<<endl;
    }
private:
  void  column_op()                 //column operation
    {
        cout<<"Enter row :- "<<endl;
        cin>>row;
        cout<<" Enter col :- "<<endl;
        cin>>col;
        if(col>1)                           //taking inputs
        {
                for(i=1;i<=row;i++)
                {
                    for(j=1;j<=col;j++)
                    {
                        cout<<" Enter arr["<<i<<"]["<<j<<"] :- "<<endl;
                        cin>>arr[i][j];
                        arr1[i][j]=arr[i][j];
                    }
                }
                 for(i=1;i<=row;i++)
                    {
                        for(j=1;j<=col;j++)
                        {
                            k=j+1;
                            if(arr[i][j]!=arr[i][k])
                            {
                                cout<<arr[i][j];                //giving output
                            }
                        }
                        for(j=col;j>=1;--j)
                        {
                            k=j+1;
                            if(arr[i][j]==arr[i][k])
                            {
                                arr1[i][j]='*';
                                cout<<arr1[i][j];                //giving output
                            }
                        }
                        cout<<endl;
                    }
        }
        else
        {
            cout<<" Need to enter column value should be > 1 "<<endl;
        }
    }
    void row_op()
    {
        cout<<" Enter Row :- "<<endl;               //entering  row and column
        cin>>row;
        cout<<" Enter Col :- "<<endl;
        cin>>col;
        if(row>1)                       //checking condition
        {
            for(i=1;i<=row;i++)         //taking inputs
            {
                for(j=1;j<=col;j++)
                {
                    cout<<" arr["<<i<<"]["<<j<<"] :-  "<<endl;
                    cin>>arr[i][j];
                    arr1[i][j]=arr[i][j];
                }
            }
            for(j=1;j<=col;j++)
            {
                for(i=1;i<=row;i++)
                {
                    if(arr[i][j]!=arr[i-1][j])
                    {
                        cout<<arr[i][j];
                        cout<<endl;
                    }
                }
                for(i=row;i>=1;--i)
                {
                    if(arr[i][j]==arr[i+1][j])
                    {
                        arr1[i][j]='*';
                        cout<<arr1[i][j];
                        cout<<endl;
                    }
                }
            }
        }
        else
        {
            cout<<" Need to enter row value should be >1 "<<endl;
        }
    }
        void diagonal_op()
        {
                cout<<"row and column:- "<<endl;
                cin>>row>>col;
                n=row;
                for(i=1;i<=row;i++)                 //taking inputs
                {
                    for(j=1;j<=col;j++)
                    {
                        cout<<" arr["<<i<<"]["<<j<<"] : - "<<endl;
                        cin>>arr[i][j];
                    }
                }
                for(i=1;i<=row;i++)             //printing matrix
                {
                    for(j=1;j<=col;j++)
                    {
                        cout<<arr[i][j];
                        cout<<"\t";
                    }
                    cout<<endl;
                }
                cout<<endl<<endl;
                for(i=1;i<=row;i++)
                {
                    for(j=col;j>=1;--j)
                    {
                        if(i==j)
                        {
                            if(arr[i][j]==arr[i+1][j+1])
                            {
                                arr[i][j]='*';
                                arr1[i][j]=arr[i][j];
                            }
                            else
                            {
                               arr2[i][j]=arr[i][j]; 
                            }
                        }
                        else if(i+j-1==n)
                        {
                            if(arr[i][j]==arr[i+1][j-1])
                            {
                                arr[i][j]='*';
                                arr1[i][j]=arr[i][j];
                            }
                            else
                            {
                                arr2[i][j]=arr[i][j];
                            }
                        }
                        else
                        {
                            arr3[i][j]=arr[i][j];
                        }
                    }
                    cout<<endl;
                }
                for(i=1;i<=row;i++)   //printing matrix
                {
                    for(j=1;j<=col;j++)
                    {
                        cout<<arr1[i][j];
                        cout<<arr2[i][j];
                        cout<<arr3[i][j];
                        cout<<"\t";
                    }cout<<endl;
                }
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
            matrix obj;
            obj.option();
    }
}
