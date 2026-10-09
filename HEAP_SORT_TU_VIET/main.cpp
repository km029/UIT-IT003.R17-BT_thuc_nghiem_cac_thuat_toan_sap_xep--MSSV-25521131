#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <iomanip>

using namespace std;
using namespace std::chrono;

#define MAX 1000005
double A[MAX];

void Heapify(double A[],int n,int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n&&A[l]>A[largest]) largest=l;
    if(r<n&&A[r]>A[largest]) largest=r;
    if(largest!=i)
    {
        swap(A[i],A[largest]);
        Heapify(A,n,largest);
    }
}

void HeapSort(double A[],int n)
{
    for(int i=n/2-1;i>=0;i--)
        Heapify(A,n,i);
    for(int i=n-1;i>0;i--)
    {
        swap(A[0],A[i]);
        Heapify(A,i,0);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<"Thoi gian cua Heap Sort\n";
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
        HeapSort(A,n);
        auto end=high_resolution_clock::now();
        double duration_ms=duration<double,milli>(end-start).count();
        cout<<"test case "<<t<<": "<<fixed<<setprecision(2)<<duration_ms<<" ms\n";
    }
    return 0;
}
