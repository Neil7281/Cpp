#include<iostream>
#include<vector>
#include<cmath>

std::vector<std::pair<std::pair<int, int>,double>> getTheNeigbours(std::vector<std::vector<int>> occupancy_map,  std::pair<int,int> position){
    std::vector<std::pair<int, int>> dir_x = {{1,0}, {-1,0}};
    std::vector<std::pair<int, int>> dir_y = {{0,1}, {0,-1}};
    // std::vector<std::pair<int, int>> dir_diag = {{std::sqrt(2),1}, {-std::sqrt(2),1}};

    std::vector<std::pair<std::pair<int, int>,double>> neigbours ={};

    for (auto val : dir_x){
        std::pair<int, int> curr_check = {position.first+val.first, position.second+val.second};

            if(curr_check.first < occupancy_map.size() && curr_check.second < occupancy_map[0].size() && occupancy_map[curr_check.first][curr_check.second]==0){
                neigbours.push_back({curr_check,1});
            }
    }
     for (auto val : dir_y){
        std::pair<int, int> curr_check = {position.first+val.first, position.second+val.second};

            if(curr_check.first < occupancy_map.size() && curr_check.first > 0 && curr_check.second < occupancy_map[0].size() && curr_check.second > 0 && occupancy_map[curr_check.first][curr_check.second]==0){
                neigbours.push_back({curr_check,1.5});
            }
    }

    return neigbours;
}






int main(){

    std::vector<std::vector<int>> occupancy_map = {
        {0, 1, 0, 0, 0},  // Lane 0: obstacle at col1
        {0, 0, 0, 1, 0},  // Lane 1: obstacle at col3
        {0, 0, 0, 0, 0}   // Lane 2: clear
    }; 

    std::pair<int,int> position = {1,1};

    std::vector<std::pair<std::pair<int, int>,double>> points = getTheNeigbours(occupancy_map,position);
    for (auto val : points){
        std::cout<<val.first.first<<" "<<val.first.second<<" "<<val.second<<std::endl;
    };
    return 0;
}