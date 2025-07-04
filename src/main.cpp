#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <locale>
#include <chrono>
#include <thread>
#include <termios.h>
#include <unistd.h>

void delayCout(const std::string& text, int delay_ms = 50) {
    for (char ch : text) {
        std::cout << ch << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    }
}
enum Key {UP,DOWN,LEFT,RIGHT,ENTER,ESCAPE,OTHER};
char getChar(){
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    read(STDIN_FILENO, &ch, 1);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
Key getInput(){
    char ch=getChar();
    if(ch=='\033'){ //escape
        getChar();
        char arrow=getChar();
        if(arrow=='A'){
            return UP;
        }
        else if(arrow=='B'){
            return DOWN;
        }
        else if(arrow=='C'){
            return RIGHT;
        }
        else if(arrow=='D'){
            return LEFT;
        }
        else{
            return OTHER;
        }
    }
    else if(ch=='\n' || ch=='\r'){
        return ENTER;
    }
    return OTHER;
}
void clearScreen(){
    std::cout<<"\x1b[2J\x1b[H";
}
void drawMenu(const std::vector<std::string>& options, int selected,bool first) {
    clearScreen();
    if(first){
        delayCout("\n\nPlease choose your starter plant\n", 30);
    }
    else{
        std::cout << "\n\nPlease choose your starter plant\n";
    }
    std::cout << "\n";
    for (size_t i = 0; i < options.size(); ++i) {
        if (i == selected) {
            std::cout << "[\x1b[32mx\x1b[0m] " << options[i] << "\n"; 
        } else {
            std::cout << "[ ] " << options[i] << "\n";
        }
    }
}
int main() {

    std::vector<std::string> plants = { "marigold", "zinnias", "cosmos" };
    int selected = 0;
    bool first=true;
    while (true) {
        drawMenu(plants, selected,first);
        first=false;
        Key key = getInput();
        if (key == UP && selected > 0) selected--;
        else if (key == DOWN && selected < (int)plants.size() - 1) selected++;
        else if (key == ENTER) break;
    }

    clearScreen();
    std::cout << "🌱 You selected: \x1b[32m" << plants[selected] << "\x1b[0m 🌱\n";
    return 0;
}