#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
static long num_steps = 100000;
int main()
{
    auto start = high_resolution_clock::now();
    int i,x,total,constant,sum=0;
    constant = 12;
    for(i=0;i<num_steps;i++){
        x = i + constant;
        sum = sum + x;
    }
    total = constant * sum;
    cout<<"total :"<<total<<endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    return 0;
}