#include<bits/stdc++.h>
#include<omp.h>
using namespace std;

int main(){

    int current_num_threads = 0;
    // Create the omp parallel region, containing the number of threads as defined by OMP_NUM_THREADS
    #pragma omp parallel
    {
        if(omp_get_thread_num()==0)
        {
            current_num_threads = omp_get_num_threads();
        }
        // Each thread prints its identifier
        cout << "Loop 1: we are " << current_num_threads << " threads, I am thread " << omp_get_thread_num() << ",\n";
    }
    // Tell openmp to now use one more thread in parallel regions
    omp_set_num_threads(omp_get_num_procs());
    // create the openmp parallel region which will contain 8 thread
    #pragma omp parallel
    {
        if(omp_in_parallel()){
            cout << "Loop 1: we are " << omp_get_num_threads() << " threads, and " << omp_get_num_procs() << " processes \n";
        }
    }
}