#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;
using namespace std::chrono;

#define MAX 1000005
double A[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<"Thoi gian cua std::sort\n";
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
        sort(A,A+n);
        auto end=high_resolution_clock::now();
        double duration_ms=duration<double,milli>(end-start).count();
        cout<<"test case "<<t<<": "<<fixed<<setprecision(2)<<duration_ms<<" ms\n";
    }
    return 0;
}
