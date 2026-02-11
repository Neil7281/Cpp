#include<iostream>


double stoppingTime(double deaccelearation, double velocity){
    double a = deaccelearation;
    double v = velocity;

    return v/a;

}



int main(){

    std::cout<<stoppingTime(2,10)<<" sec";


    return 0;
}