#include<iostream>
#include<cmath>


double stoppingTime(double deaccelearation, double velocity){
    double a = deaccelearation;
    double v = velocity;

    return v/a;

}


struct states
{
    double x;
    double y;
    double vx;
    double vy;
    double ax;
    double ay;
    double theta;
    double omega;
};

void updateState(states& s, double dt){
    // double x = s.x;
    // double y = s.y;
    // double vx = s.vx;
    // double vy = s.vy;

    s.x += s.vx*dt;
    s.y += s.vy*dt;

}

bool checkCollision(states v1, states v2, double radius){
    double dist = std::hypot((v1.x - v2.x), (v1.y - v2.y));
    return dist <= 2*radius;
}



int main(){

    // std::cout<<stoppingTime(2,10)<<" sec";

    states s1 = {0.00,0.00,10.00,0.00};
    states s2 = {3.00,0.00,5.00,0.00};

    // for (double dt = 0; dt<1.00; dt+=0.01){
    //     updateState(s, dt);
    //     std::cout<<s.x<<" "<<s.y<<std::endl;
    // }
    updateState(s1, 1.00);
    updateState(s2, 2.00);

    std::cout<<std::boolalpha<<checkCollision(s1,s2,3.00)<<std::endl;
    

    return 0;
}