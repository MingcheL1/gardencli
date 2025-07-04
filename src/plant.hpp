#ifndef PLANT_HPP
#define PLANT_HPP

#include <string>
#include <vector>

using namespace std;
class Plant {
private:
    string name;
    int growthTime;
    int countdown;
    int stage;
    bool watered;
    int sellPrice;

public:
    Plant(string name, int growthTime, int sellPrice);
    void water();
    void fertilize();
    void update();
    int getStage() const;
    bool needsWater() const;
    int getSellPrice() const;
    vector<string> display() const;
};

#endif // PLANT_HPP