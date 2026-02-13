#include<iostream>
#include<vector>
#include<cmath>

struct vehicleStates{
    double x;
    double y;
    double vx;
    double vy;
    double theta;
};


void updateState(vehicleStates& v, double dt){
    v.x +=v.vx*dt;
    v.y += v.vy*dt;
}

bool checkCollision(std::pair<double, double> point1, std::pair<double, double> point2, double radius){
    double dist = std::hypot((point1.first - point2.first), (point1.second - point2.second));
    return dist<=2*radius;
}

std::vector<std::pair<double,double>> pathGenerator2(std::pair<double, double> start, std::pair<double, double> goal, std::vector<std::pair<double,double>> obstacle, double num_steps){
    std::vector<std::pair<double,double>> path = {start};
    double dx = (goal.first - start.first)/num_steps;
    double dy = (goal.second - start.second)/num_steps;

    std::pair<double, double> curr_point = start;

    for (double i = 0; i<num_steps; i+=1.00){
        curr_point.first+=dx;
        curr_point.second+=dy;

        bool collide = false;
        for (auto val : obstacle){
            if(checkCollision(curr_point, val, 0.5)){
                collide = true;
                break;
            }
        }

        if (collide){
            if ((std::hypot((goal.first - curr_point.first), (goal.second - (curr_point.second+4.00)))
                            <(std::hypot((goal.first - curr_point.first), (goal.second - (curr_point.second-4.00)))))){
                curr_point.second+=4.00;
            }else {
                curr_point.second-=4.00;
            }
            bool offset_collide = false; 
            for (auto val : obstacle){
                if(checkCollision(curr_point, val, 0.5)){
                    offset_collide = true;
                    break;
                }
            }
            if(!offset_collide){
                path.push_back(curr_point);
            }

        }else {
            path.push_back(curr_point);
        }
    }
    return path;
}




int main(){

    std::pair<double, double> start = {0.00,0.00};
    std::pair<double, double> goal = {10.00,0.00};

    std::vector<std::pair<double, double>> ob = {{5.00,0.00}, {8.00,-4.00}, {9.00, 0.00}};

    std::vector<std::pair<double, double>> path = pathGenerator2(start, goal, ob, 10.00);

    for (auto val : path){
        std::cout<<"("<<val.first<<" "<<val.second<<")"<<std::endl;

    }



    return 0;
}








