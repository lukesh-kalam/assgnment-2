#include<iostream>
using namespace std;
class student
{
  public:
            char mat1[10][10],mat2[10][10];
            int i,j,row,col;
        student()
        {
            cout<<" Constructor is involked "<<endl;
            
        }
        void input_matrix()
        {
            cout<<" Enter row and column "<<endl;
            cin>>row>>col;
            for(i=1;i<=row;i++)
            {
                for(j=1;j<=col;j++)
                {
                    cout<<" matrix ["<<i<<"]["<<j<<"] :- ";
                    cin>>mat1[i][j];
                    mat2[i][j]=mat1[i][j];
                    cout<<endl;
                }
            }
            cout<<" Entered matrix is :- "<<endl;
            for(i=1;i<=row;i++)
            {
                for(j=1;j<=col;j++)
                {
                    cout<<mat1[i][j];
                    cout<<"\t";
                }
                cout<<endl;
            }
        }
        void menu()
        {
            int op;
            cout<<" Press 1 for column operation"<<endl;
            cout<<" Press 2 for row operation "<<endl;
            cout<<" Enter option :- "<<endl;
            cin>>op;
            switch(op)
            {
                case 1:col_op();
                        break;
                case 2:row_op();
                        break;
            }
        }
        void col_op()
        {
            if(col>1)
            {
                cout<<" The column matrix is :- "<<endl;
                for(i=1;i<=row;i++)
                {
                    for(j=1;j<=col;j++)
                    {
                        if(mat1[i][j]!=mat1[i][j+1])
                        {
                            cout<<mat1[i][j]<<" \t "; 
                        }
                    }
                    for(j=col;j>=1;--j)
                    {
                        if(mat1[i][j]==mat1[i][j+1])
                        {
                            mat2[i][j]='*';
                            cout<<mat2[i][j]<<" \t ";
                        }
                    } 
                        cout<<endl;
                    }
            }
            else
            {
                cout<<"column should be greather than 1 "<<endl;
            }
        }
        void row_op()
        {
            if(row>1)
            {
                for(j=1;j<=col;j++)
                {
                    for(i=1;i<=row;i++)
                    {
                        if(mat1[i][j]!=mat1[i-1][j])
                        {
                            cout<<mat1[i][j];
                            cout<<endl;
                        }
                    }
                    for(i=row;i>=1;--i)
                    {
                        if(mat1[i][j]==mat1[i+1][j])
                        {
                            mat2[i][j]='*';
                            cout<<mat2[i][j];
                            cout<<endl;
                        }
                    }
                    cout<<"\t";
                }
            }
            else
            {
                cout<<" The value of row should be greather than 1 "<<endl;
            }
        }
};
int main()
{
    student obj;
    obj.input_matrix();
    obj.menu();
return 0;
}
