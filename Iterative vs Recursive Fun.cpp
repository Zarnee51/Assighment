#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
//note : the code is work in online compiler
double fact(double x){
    double f = 1 ;
    for(int i = 1 ; i<=x ; i++)
        f *= i ;
    return f ;
}

double recfact(double x){
    if(x==0 || x==1 )
        return 1 ;
    return x * recfact(x-1) ;
}

int main()
{
    long int x = 100000000000;
    for(int i = 1 ; i<=x ; i= i*2){
        auto start = high_resolution_clock::now();
        double result1 = fact(i);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "The factorial of " << i << " is: " << result1 << " and the execution time is: " << duration.count() << " nanoseconds" << endl;
        if(result1 == 0)
            cout << "Error in factorial calculation" << endl;

        start = high_resolution_clock::now();
        double result2 = recfact(i);
        stop = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(stop - start);
        cout << "The recursive factorial of " << i << " is: " << result2 << " and the execution time is: " << duration.count() << " nanoseconds" << endl;
        if(result2 == 0)
            cout << "Error in recursive factorial calculation" << endl;

        cout << endl;
    }

    return 0;
}
