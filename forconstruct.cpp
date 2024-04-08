#include<omp.h>
int main()
{
    int N = 24;
    int a[6], b[6], c[6];
    #pragma omp parallel
    {
        int id,i,Nthrds, istart, iend;
        id = omp_get_thread_num();
        Nthrds = omp_get_num_threads();

        istart = id * N / Nthrds;
        iend = (id+1) * N / Nthrds;
        if(id== Nthrds-1)
            iend = N;
        for(i=istart;i<iend;i++){
            a[i] = b[i] + c[i];
        }
    }
}