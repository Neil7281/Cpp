#include<iostream>
#include<cmath>
#include<vector>
#include<utility>
#include<algorithm>


std::pair<double, double> closetToLane( const std::vector<std::pair<double, double>> &lane_pints,
                                        const std::pair<double,double> query_point){
        double temp = INT_MAX;
        int n = lane_pints.size();
        std::pair<double, double> closest_point;

        for (int i = 0; i<n; i++){
            double curr_point_dist = std::hypot(lane_pints[i].first - query_point.first, lane_pints[i].second - query_point.second);
            if (std::min(curr_point_dist, temp)==curr_point_dist){
                closest_point = lane_pints[i];
            }
            temp = std::min(curr_point_dist, temp);
        }
        return closest_point;
}




int main(){

    const std::vector<std::pair<double, double>> car_lane_points = {{0,0}, {2,0}, {4,1}, {6,2}, {8,2}};
    const std::pair<double,double> query_point = {3,2};
    
     const std::pair<double,double> closest_point = closetToLane(car_lane_points, query_point);
    std::cout<<closest_point.first<<" "<<closest_point.second;
    

    return 0;
}
