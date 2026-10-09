#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <iomanip>

using namespace std;
using namespace std::chrono;

#define MAX 1000005
double A[MAX];
double B[MAX];

void Merge(double A[],int l,int m,int r)
{
    int i=l,j=m+1,k=l;
    while(i<=m&&j<=r)
    {
        if(A[i]<=A[j]) B[k++]=A[i++];
        else B[k++]=A[j++];
    }
    while(i<=m) B[k++]=A[i++];
    while(j<=r) B[k++]=A[j++];
    for(int p=l;p<=r;++p) A[p]=B[p];
}

void MergeSort(double A[],int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        MergeSort(A,l,m);
        MergeSort(A,m+1,r);
        Merge(A,l,m,r);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<"Thoi gian cua Merge Sort\n";
    for(int t=1;t<=10;++t)
    {
        string filename="test_"+to_string(t)+".txt";
        ifstream fin(filename);
        int n;
        fin>>n;
        for(int i=0;i<n;++i)
        {
            fin>>A[i];
        }
        fin.close();
        auto start=high_resolution_clock::now();
        MergeSort(A,0,n-1);
        auto end=high_resolution_clock::now();
        double duration_ms=duration<double,milli>(end-start).count();
        cout<<"test case "<<t<<": "<<fixed<<setprecision(2)<<duration_ms<<" ms\n";
    }
    return 0;
}
