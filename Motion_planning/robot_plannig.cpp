#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

struct Cell {
    double x, y;
    bool operator==(const Cell& other) const {
        return x == other.x && y == other.y;
    }
};

class GridMap {
public:
    GridMap(double w, double h) : width(w), height(h), occ(h, std::vector<int>(w, 0)) {}

    bool inBounds(double x, double y) const {
        return x >= 0 && x < width && y >= 0 && y < height;
    }

    bool isFree(double x, double y) const {
        return inBounds(x, y) && occ[y][x] == 0;
    }

    void setObstacle(double x, double y) {
        if (inBounds(x, y)) occ[y][x] = 1;
    }

    int W() const { return width; }
    int H() const { return height; }

private:
    double width, height;
    std::vector<std::vector<int>> occ; // 0 free, 1 obstacle
};

// TODO (you will implement next): neighbor generation
std::vector<Cell> getNeighbors4(const GridMap& map, const Cell& c) {
    std::vector<Cell> nbrs;
    // Hint: try (x+1,y), (x-1,y), (x,y+1), (x,y-1)
    // Only push if map.isFree(nx, ny)
    double dx[4] = {0,0,1.00,-1.00};
    double dy[4] = {1.00,-1.00,0,0};

    for (int i = 0; i<4; i++){
        double nx = c.x + dx[i];
        double ny = c.y + dy[i];
        if(map.isFree(nx, ny)){
            nbrs.push_back(Cell{nx, ny});
        }
    }
    return nbrs;
}

std::vector<Cell> getNeighbors8(const GridMap& map, const Cell& c){
    std::vector<Cell> nbrs8;
    double dx[8] = {0,0,1.00,-1.00,0,0,sqrt(2), -sqrt(2)};
    double dy[8] = {1.00,-1.00,0,0,sqrt(2), -sqrt(2), 0,0};

    for (int i = 0; i<8; i++){
        double nx = c.x + dx[i];
        double ny = c.y + dy[i];
        if(map.isFree(nx,ny)){
            nbrs8.push_back(Cell{nx,ny});
        }
    }
    return nbrs8;
} 

int main() {
    GridMap map(10, 8);

    // Add a simple wall obstacle
    for (int x = 2; x <= 7; x++) map.setObstacle(x, 4);

    Cell start{2, 4};
    Cell goal{8, 6};

    std::vector<Cell> n1 = getNeighbors8(map, goal);

    std::cout << "Grid ready. Start=(" << start.x << "," << start.y << ") "
              << "Goal=(" << goal.x << "," << goal.y << ")\n";

    // Quick check: start/goal must be free
    std::cout << "Start free? " << map.isFree(start.x, start.y) << "\n";
    std::cout << "Goal free? " << map.isFree(goal.x, goal.y) << "\n";

    for (auto val : n1){
        std::cout<<val.x<<" ";
    }

    return 0;
}
