#include<bits/stdc++.h>
using namespace std;

int coinExchange(int coins[],int value,int noOfCoins)
{
    int totalCoins = 0;
    int i=0,flag=0;
    while(value>0)
    {
        //cout<<"I is"<<i+1<<endl;
        if(value>=coins[i])
        {
            totalCoins++;
            if(flag!=0)
                cout<<" + ";
            cout<<coins[i];
            cout<<" ";
            value-=coins[i];
            flag++;
        }
        else
        {
            i++;
        }
    }
    return totalCoins;

}
int main()
{

    int value;
    int coins[] = {50,30,20,5,2,1};
    cout<<"Enter the Money value:";
    cin>>value;
    cout<<endl;

    int sizeOfCoins = sizeof(coins)/sizeof(coins[0]);
    cout<<"The coins are : ";
    int ans=coinExchange(coins,value,sizeOfCoins);
    cout<<"\nTotal number of Coins required is :"<<ans<<endl;

    return 0;
}
