#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

#define MAX 1000005
const int N = 1000000;
double a[MAX];

void DayTangDan()
{
    mt19937_64 rng(42);
    uniform_real_distribution<double> dist(-1000000.0, 1000000.0);
    for (int i=0;i<N;++i)
    {
        a[i]=dist(rng);
    }
    sort(a,a+N);
}

void DayGiamDan()
{
    mt19937_64 rng(42);
    uniform_real_distribution<double> dist(-1000000.0,1000000.0);
    for (int i=0;i<N;++i)
    {
        a[i] = dist(rng);
    }
    sort(a,a+N,greater<double>());
}

void DayNgauNhien(unsigned int seed)
{
    mt19937_64 rng(seed);
    uniform_real_distribution<double>dist(-1000000.0,1000000.0);
    for(int i=0;i<N;++i)
    {
        a[i]=dist(rng);
    }
}

void LuuFile(const string& filename)
{
    ofstream fout(filename);

    if (!fout.is_open()) return;
    fout << N << "\n";
    fout << fixed << setprecision(2);
    for (int i=0;i<N;++i) {
        fout<<a[i]<<(i==N-1?"":" ");
    }
    fout.close();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    DayTangDan();
    LuuFile("test_1.txt");
    DayGiamDan();
    LuuFile("test_2.txt");
    for (int t = 3; t <= 10; ++t)
    {
        DayNgauNhien(100 + t * 13);
        LuuFile("test_"+to_string(t)+".txt");
    }
    cout<<"Da tao Xong"<<'\n';
    return 0;
}
