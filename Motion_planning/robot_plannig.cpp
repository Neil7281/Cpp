#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

struct Cell {
    int x, y;
    bool operator==(const Cell& other) const {
        return x == other.x && y == other.y;
    }
};

class GridMap {
public:
    GridMap(int w, int h) : width(w), height(h), occ(h, std::vector<int>(w, 0)) {}

    bool inBounds(int x, int y) const {
        return x >= 0 && x < width && y >= 0 && y < height;
    }

    bool isFree(int x, int y) const {
        return inBounds(x, y) && occ[y][x] == 0;
    }

    void setObstacle(int x, int y) {
        if (inBounds(x, y)) occ[y][x] = 1;
    }

    int W() const { return width; }
    int H() const { return height; }

private:
    int width, height;
    std::vector<std::vector<int>> occ; // 0 free, 1 obstacle
};

// TODO (you will implement next): neighbor generation
std::vector<Cell> getNeighbors4(const GridMap& map, const Cell& c) {
    std::vector<Cell> nbrs;
    // Hint: try (x+1,y), (x-1,y), (x,y+1), (x,y-1)
    // Only push if map.isFree(nx, ny)
    int nx1 = c.x + 1;
    int nx2 = c.x - 1;
    int ny1 = c.y + 1;
    int ny2 = c.y - 1;

    Cell c1{nx1, ny1};Cell c2{nx1, ny2};Cell c3{nx2, ny2};Cell c4{nx2, ny1};
    // std::vector<Cell> cells = {c1, c2, c3, c4};
    nbrs = {c1,c2,c3,c4};
    for (int i = 0; i < 4; i++){
        if(!map.isFree(nbrs[i].x, nbrs[i].y)){
            nbrs.erase(nbrs.begin()+i);
        }
    }
    return nbrs;
}

int main() {
    GridMap map(10, 8);

    // Add a simple wall obstacle
    for (int x = 2; x <= 7; x++) map.setObstacle(x, 4);

    Cell start{2, 4};
    Cell goal{8, 6};

    std::cout << "Grid ready. Start=(" << start.x << "," << start.y << ") "
              << "Goal=(" << goal.x << "," << goal.y << ")\n";

    // Quick check: start/goal must be free
    std::cout << "Start free? " << map.isFree(start.x, start.y) << "\n";
    std::cout << "Goal free? " << map.isFree(goal.x, goal.y) << "\n";

    return 0;
}
