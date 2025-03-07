
#include<stdio.h>
#include<iostream>
#include<omp.h>
using namespace std;

void hello(){

int team_size=omp_get_num_threads();
int tid=omp_get_thread_num();
	
cout<<"thread num"<<tid<< "in the team size of "<<team_size<<endl;

}
int main(int argc, char *argv[]){

    int thread_count=1;
    if(argc == 2 ){
       thread_count=	strtol(argv[1],NULL,10);
  

    }
    else{
   
      cout<<"Please enter the second argument to command line argument \n";
      return 0;


    }
    #pragma omp parallel  num_threads(thread_count)
   {
 
     hello();
   }
  return 0;



}
