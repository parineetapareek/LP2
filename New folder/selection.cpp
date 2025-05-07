#include<iostream>
using namespace std;

void selectionsort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1; j<n;j++)
        {
            if(a[j]<a[i])
            {
                swap(a[j],a[i]);
            }
        }
       
    }
}                                      

int main()
{
    int a[]={50,20,12,7};
    int n=sizeof(a)/sizeof(a[0]);
    selectionsort(a,n);
    
for(int i=0;i<n;i++)
{
    cout<<a[i];
}
}