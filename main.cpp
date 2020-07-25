#include <iostream>

using namespace std;




class coins
{
public:
    int value;
    int number;
    coins(int val, int n)
    {
        value = val;
        number = n;
    }
};


void swap(int *a, int *b)
{
    int *copy;
    copy=a;
    a=b;
    b=copy;
}

int sorted(coins arr[],int n,int fanction(coins a),int lower=1)
{
    for(int i=1; i<n; i++)
    {
        if(fanction(arr[i])<fanction(arr[i-1]) && lower)
        {
            return 0;
        }
        if(fanction(arr[i])>fanction(arr[i-1]) && !lower)
        {
            return 0;
        }
    }
    return 1;
}

void quicksort(coins arr[],int n,int fanction(coins a), int lower=1)
{
    int i=1;
    while(!sorted(arr,n,fanction,lower))
    {
        if(i==n)
            i=1;


        if(fanction(arr[i])<fanction(arr[i-1]) && lower)
        {
            swap(arr[i],arr[i-1]);
        }
        if(fanction(arr[i])>fanction(arr[i-1]) && !lower)
        {
            swap(arr[i],arr[i-1]);
        }
        i++;
    }

}

void printlist(coins arr[],int n,int fanction(coins a))
{
    for(int i=0; i<n; i++)
    {
        cout << fanction(arr[i])<< "  " ;
    }
    cout<< endl;
}

int cmpfunc (coins  a)
{
    return a.number ;
}

int main()
{
    coins a(10,2),b(20,1),c(40,3),d(20,1);

    coins arr[]= {a,b,c,d};


    quicksort(arr,sizeof(arr)/sizeof(arr[0]),cmpfunc);

    printlist(arr,sizeof(arr)/sizeof(arr[0]),cmpfunc);


    return 0;
}
