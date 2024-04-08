#include<bits/stdc++.h>
#include<omp.h>
using namespace std;

int main(){
//  int thread_counter = 0;
 #pragma omp parallel
 {
  cout<<"hi open mp"<<endl;
 }
}
