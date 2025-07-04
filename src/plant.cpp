#include <string>
#include <vector>

using namespace std;
class Plant{
    private:
        int time;
        bool watered;
        int buyPrice;
        int sellPrice;
        string name;
        int stage;
        bool empty;

    public:
        vector<string> display(){
            if(empty){
                return {

                    "  ███████  ",
                    " █████████ ",
                    "███████████",
                    " █████████ ",
                    "  ███████  "
                };
            }
            else if(stage == 0){
                return {

                    "     █     ",
                    "     █     ",
                    "  ███████  ",
                    " █████████ ",
                    "███████████",
                    " █████████ ",
                    "  ███████  "
                };
            }
            else if(stage==1){
                if(name==""){
                    
                }
            }
        }
        int update(){
            //countdown, pause if watered is false. update stage if time is 0. return stage.
            if(watered){
                time--;
                if(time <= 0){
                    stage++;
                }
            }
            return stage;
        }
        int getStage() {
            return stage;
        }
        void fertilize(){
            time-=15;
        }

};