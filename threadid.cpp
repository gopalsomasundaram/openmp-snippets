#include<bits/stdc++.h>
#include<omp.h>
using namespace std;

int main(){
 int thread_NUM = 0;
omp_set_num_threads(4);

 #pragma omp parallel
 {
    int omp_threads = omp_get_num_threads();
    int uniqueID = omp_get_thread_num();
    thread_NUM = uniqueID;

    // if(uniqueID==0){
    // }

  cout<<"thread id: "<<uniqueID<<"\t total threads"<<omp_threads<<endl;
 }
 cout <<"thread NUM :"<<thread_NUM;

}
