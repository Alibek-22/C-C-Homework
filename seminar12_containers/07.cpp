#include "image.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;


struct PixelInfo {
    int x, y;
    int dist;
    PixelInfo* prev;
    
    PixelInfo(int x = -1, int y = -1, int dist = -1, PixelInfo* prev = nullptr) 
        : x(x), y(y), dist(dist), prev(prev) {}
};


struct Point {
    int x, y;
    Point(int x = -1, int y = -1) : x(x), y(y) {}
};

// Функция для проверки, является ли пиксель проходимым
bool isWalkable(const Image::Color& color) {
    // Белый пиксель (255, 255, 255) - можно ходить
    if (color.r == 255 && color.g == 255 && color.b == 255)
        return true;
    // Зеленый пиксель (0, 255, 0) - начало
    if (color.r == 0 && color.g == 255 && color.b == 0)
        return true;
    // Красный пиксель (255, 0, 0) - конец
    if (color.r == 255 && color.g == 0 && color.b == 0)
        return true;
    return false;
}


bool isStart(const Image::Color& color) {
    return (color.r == 0 && color.g == 255 && color.b == 0);
}

bool isEnd(const Image::Color& color) {
    return (color.r == 255 && color.g == 0 && color.b == 0);
}

Point findPointByColor(const Image& img, Image::Color targetColor) {
    for (int y = 0; y < img.getHeight(); ++y) {
        for (int x = 0; x < img.getWidth(); ++x) {
            if (img.getPixel(x, y) == targetColor) {
                return Point(x, y);
            }
        }
    }
    return Point(-1, -1); 
}

vector<Point> findPath(Image& img) {
    int width = img.getWidth();
    int height = img.getHeight();
    
    Point start = findPointByColor(img, Image::Color{0, 255, 0});
    Point end = findPointByColor(img, Image::Color{255, 0, 0});
    
    if (start.x == -1 || start.y == -1) {
        cerr << "Start point not found!" << endl;
        return {};
    }
    if (end.x == -1 || end.y == -1) {
        cerr << "End point not found!" << endl;
        return {};
    }
    
    vector<vector<PixelInfo>> grid(height, vector<PixelInfo>(width));
    
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x] = PixelInfo(x, y, -1, nullptr);
        }
    }
    
    queue<Point> q;
    
    grid[start.y][start.x].dist = 0;
    q.push(start);
    
    int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    
    bool found = false;
    
    while (!q.empty() && !found) {
        Point current = q.front();
        q.pop();
        
        if (current.x == end.x && current.y == end.y) {
            found = true;
            break;
        }
        
        for (int i = 0; i < 8; ++i) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            
            // Проверяем границы
            if (nx < 0 || nx >= width || ny < 0 || ny >= height)
                continue;
            Image::Color color = img.getPixel(nx, ny);
            if (!isWalkable(color) && !isEnd(color))
                continue;
            
            if (grid[ny][nx].dist == -1) {
                grid[ny][nx].dist = grid[current.y][current.x].dist + 1;
                grid[ny][nx].prev = &grid[current.y][current.x];
                q.push(Point(nx, ny));
            }
        }
    }
    
    vector<Point> path;
    if (found) {
        PixelInfo* current = &grid[end.y][end.x];
        stack<Point> tempPath;
        
        while (current != nullptr) {
            tempPath.push(Point(current->x, current->y));
            current = current->prev;
        }
        
        while (!tempPath.empty()) {
            path.push_back(tempPath.top());
            tempPath.pop();
        }
    }
    
    return path;
}

void drawPath(Image& img, const vector<Point>& path) {
    // Синий цвет для пути
    Image::Color pathColor{0, 0, 255};
    
    for (size_t i = 1; i + 1 < path.size(); ++i) {
        int x = path[i].x;
        int y = path[i].y;
        img.setPixel(x, y, pathColor);
        
        for (int dy = -1; dy <= 1; ++dy) {
            for (int dx = -1; dx <= 1; ++dx) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < img.getWidth() && 
                    ny >= 0 && ny < img.getHeight()) {
                    Image::Color currentColor = img.getPixel(nx, ny);
                    if (currentColor.r == 255 && currentColor.g == 255 && currentColor.b == 255) {
                        img.setPixel(nx, ny, pathColor);
                    }
                }
            }
        }
    }
}

int main() {
    try {
      
        Image img("input.ppm");
        
        vector<Point> path = findPath(img);
        
        if (path.empty()) {
            cout << "Path not found!" << endl;
            return 1;
        }
        
        cout << "Path found! Length: " << path.size() << " points" << endl;
        cout << "Start: (" << path[0].x << ", " << path[0].y << ")" << endl;
        cout << "End: (" << path.back().x << ", " << path.back().y << ")" << endl;
        
        drawPath(img, path);
        
        img.savePPMText("output.ppm");
        cout << "Result saved to output.ppm" << endl;
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
