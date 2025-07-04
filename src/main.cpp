#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<string> flower = {
    "     █     ",
    "   █████   ",
    " ███ █ ███ ",
    "   █████   ",
    "     █     ",
    "     █     ",
    "  ███████  ",
    " █████████ ",
    "███████████",
    " █████████ ",
    "  ███████  "
};

void render() {
    const int rows = 3;
    const int cols = 3;
    const int flowerHeight = flower.size();
    const string horizontalGap = "       "; 
    const string verticalGap = "\n\n";      

    for (int row = 0; row < rows; ++row) {
        for (int line = 0; line < flowerHeight; ++line) {
            for (int col = 0; col < cols; ++col) {
                cout << flower[line];
                if (col < cols - 1) cout << horizontalGap;
            }
            cout << '\n';
        }
        if (row < rows - 1) cout << verticalGap;
    }
}


void printGradientBar(int width) {
    int rStart = 0, gStart = 0, bStart = 255;     // Blue
    int rEnd = 255, gEnd = 0, bEnd = 127;         // Pink

    for (int i = 0; i < width; ++i) {
        float t = static_cast<float>(i) / (width - 1);
        int r = rStart + t * (rEnd - rStart);
        int g = gStart + t * (gEnd - gStart);
        int b = bStart + t * (bEnd - bStart);

        std::cout << "\033[38;2;" << r << ";" << g << ";" << b << "m█";
    }
    std::cout << "\033[0m" << std::endl;
}

int main() {
    printGradientBar(60);  // You can adjust the width
    return 0;
}


