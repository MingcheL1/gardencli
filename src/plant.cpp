#include "plant.hpp"
#include <vector>
#include <string>

using namespace std;
Plant::Plant(string name, int growthTime, int sellPrice)
    : name(name), growthTime(growthTime), countdown(growthTime), stage(0), watered(false), sellPrice(sellPrice) {}

void Plant::water() {
    watered = true;
}

void Plant::fertilize() {
    countdown -= 30;
}

void Plant::update() {
    if (watered) {
        countdown--;
        if (countdown <= 0) {
            stage++;
        }
    } else {
        watered = false;
    }
}

int Plant::getStage() const {
    return stage;
}

bool Plant::needsWater() const {
    return !watered;
}

int Plant::getSellPrice() const {
    return sellPrice;
}

std::vector<std::string> Plant::display() const {
   
    if (stage == 0) {
        return watered ? vector<string>{"Baby Plant"} : vector<string>{"Dry Baby Plant"};
    } else if (stage == 1) {
        return watered ? vector<string>{"Growing Plant"} : vector<string>{"Dry Growing Plant"};
    } else {
        return vector<string>{"Fully Grown Plant"};
    }
}