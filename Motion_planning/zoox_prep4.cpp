#include<iostream>
#include<vector>

std::vector<std::pair<int, int>> getTheNeigbours(std::vector<std::vector<int>> occupancy_map,  std::pair<int,int> position){
    std::vector<std::pair<int, int>> check = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    std::vector<std::pair<int, int>> neigbours ={};

    for (auto val : check){
        std::pair<int, int> curr_check = {position.first+val.first, position.second+val.second};

            if(curr_check.first < occupancy_map.size() && curr_check.second < occupancy_map[0].size() && occupancy_map[curr_check.first][curr_check.second]==0){
                neigbours.push_back(curr_check);
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

    std::pair<int,int> position = {1,2};

    std::vector<std::pair<int, int>> points = getTheNeigbours(occupancy_map,position);
    for (auto val : points){
        std::cout<<val.first<<" "<<val.second<<std::endl;
    };
    return 0;
}