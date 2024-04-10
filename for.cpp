#include<bits/stdc++.h>
#include <chrono>
#include<omp.h>
using namespace std;
using namespace std::chrono;

static long num_steps = 100000;
int main(){
    auto start = high_resolution_clock::now();
    int i,x,total,constant;
    constant = 12;
    omp_set_num_threads(4);
    #pragma omp parallel
    {
        int i,uniqueID,x,sum;
        uniqueID = omp_get_thread_num();
        #pragma omp for
        for(i=uniqueID;i<num_steps;i++)
        {
            x = i + constant;
            sum += x;
        }
        #pragma omp atomic
        total += sum * constant;
    }

    cout <<"Total : "<<total<<endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    return 0;

}