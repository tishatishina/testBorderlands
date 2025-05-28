#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
    using namespace std;
    struct location_ {
        string name;
        vector<int> portal;


    };

    location_ room[4];
    
    void InitGame() {

        room[0].name = "room 1";
        room[0].portal.push_back(1);
        room[0].portal.push_back(2);

        room[1].name = "room 2";
        room[1].portal.push_back(0);
        room[1].portal.push_back(3);

        room[3].name = "room 3";
        room[3].portal.push_back(0);
        room[3].portal.push_back(1);

    }



    int main(){
      
        int current_loc = 0;

        InitGame();

        string x;

     
      
        while (true) {

            cout << "go\n";
            cin >> x;

            if (x == "go") {

                for (int i = 0; i < room[current_loc].portal.size(); i++) {
                    cout << room[current_loc].portal[i] << endl;
                }

                int dir;

                cin >> dir;

                current_loc = dir;
                cout << room[current_loc].name << endl;

            }
        }
    }
