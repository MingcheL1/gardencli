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

int main() {
    render();
    return 0;
}
