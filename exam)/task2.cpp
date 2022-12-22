#include <iostream>
#include <cmath>

using namespace std;

double sum,mem,acc,y,x;
double prikol,ss;

double tailorSin(double x) 
{ 
    double sum = x; 
    int i = 2; 
    double mem = x; 
    while (fabs(mem) < acc) {
        mem = x / i; 
        i++; 
        mem= x / i; 
        mem *= -1; 
        sum += mem;
        i++; 
    }
    return sum;
}

int task()
{
    y=sin(x/2)+sin(x-1);
    prikol=tailorSin(x/2)+tailorSin(x-1);
    ss=prikol-y;

    cout<<"Enter accuracy: ";
    cin>>acc;
    cout<<"Biblioteka: "<< y <<endl;
    cout<<"Tailor: "<< prikol <<endl;
    cout<<"Porivniannya: "<<ss<<endl;
}

int main() 
{
    cout<<"Bezrukov Andrii. IPZ-14. number 4. Task 2"<<endl;
    task();
}