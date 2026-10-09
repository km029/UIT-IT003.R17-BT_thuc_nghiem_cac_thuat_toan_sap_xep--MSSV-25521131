#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <iomanip>

using namespace std;
using namespace std::chrono;

#define MAX 1000005
double A[MAX];
void QuickSort (double A[],int l,int r)
{
    double M = A[l+(r-l)/2];
    int i=l;
    int j=r;

    while (i<=j)
    {
        while (A[i]<M)
            i++;
        while (A[j]>M)
            j--;
        if (i<=j)
        {
            swap(A[i],A[j]);
            i++;
            j--;
        }
    }
    if (l<j)
        QuickSort (A,l,j);
    if (i<r)
        QuickSort (A,i,r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<"Thoi gian cua Quick Sort tu viet"<<'\n';
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
        QuickSort(A,0,n-1);
        auto end=high_resolution_clock::now();
        double duration_ms=duration<double,milli>(end-start).count();
        cout<<"test case "<<t<<": "<<fixed<<setprecision(2)<<duration_ms<<" ms\n";
    }
    return 0;
}
