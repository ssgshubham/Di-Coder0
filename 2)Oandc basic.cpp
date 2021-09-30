#include<iostream>
using namespace std;
class Books
{
public:
    int sum(int x,int y)
    {
        int answer;
        answer=x+y;
        cout<<"sum of "<<x ;cout<<" and " <<y; cout<<" is:"<<answer;
        return answer;
    }
};
int main()
{
    int x,y,answer;
    Books sObject;
    cout<<"enter two numbers\n"<< endl;
    cin>>x;
    cin>>y;
    sObject.sum(x,y);

    return 0;
}
