#include<bits/stdc++.h>
#include <chrono>
#include<omp.h>
using namespace std;
using namespace std::chrono;

static long num_steps = 1000;
int main(){
    auto start = high_resolution_clock::now();
    int i,x,total,nthreads,constant;
    constant = 12;
    omp_set_num_threads(4);
    #pragma omp parallel
    {
        int i,uniqueID,x,nthrds,sum;
        uniqueID = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        if(uniqueID==0)
            nthreads = nthrds;
        for(i=uniqueID;i<num_steps;i=i+nthrds)
        {
            x = i + constant;
            sum += x;
        }
        #pragma omp critical
        //cout<<uniqueID;
        total += sum * constant;
    }

    cout <<"Total : "<<total<<endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    return 0;

}