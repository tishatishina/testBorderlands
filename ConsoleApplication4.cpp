#include <iostream>
#include <string>
#include <windows.h>
#include <vector>



    using namespace std;

  

    struct player_ {

        int current_loc = 0;

        int emotion[3]{};

    };


    struct portal_ {

        string name;
        int target;
        bool activ;
    };

    struct location_ {
        string name;
        vector<portal_> portal;


    };

    location_ room[4];
    player_ user;

    void InitGame() {

        user.emotion[0] = {15};     // грусть
        user.emotion[1] = { 5 };    // злость
        user.emotion[2] = { 10 };    // сила


        room[0].name = "calmness";
        room[0].portal.push_back({"blue", 1, true});
        room[0].portal.push_back({ "red", 2, true });
        room[0].portal.push_back({ "yellow", 3, true });

        room[1].name = "sadness";
        room[1].portal.push_back({"green", 0, true });
        room[1].portal.push_back({ "red", 2, true });
        room[1].portal.push_back({ "yellow", 3, true });

        room[2].name = "rage";
        room[2].portal.push_back({ "green", 0, true });
        room[2].portal.push_back({ "blue", 1, true });
        room[2].portal.push_back({ "yellow", 3, true });

        room[3].name = "power";
        room[3].portal.push_back({ "green", 0, true });
        room[3].portal.push_back({ "blue", 1, true });
        room[3].portal.push_back({ "red", 2, true });

    }

    void scan_emotion() {


        for (int i = 0; i < 3; i++) {

            switch (i)
            {

            case 0: {

                if (user.emotion[i] >= 100 || user.emotion[i] <=0) {

                    for (int j = 0; j < room[user.current_loc].portal.size(); j++) {

                        if (room[user.current_loc].portal[j].name == "blue") {

                            room[user.current_loc].portal[j].activ = false;

                        }

                    }


                }
                break;
            }
            
            case 1: {

                if (user.emotion[i] >= 100 || user.emotion[i] <= 0) {

                    for (int j = 0; j < room[user.current_loc].portal.size(); j++) {

                        if (room[user.current_loc].portal[j].name == "red") {

                            room[user.current_loc].portal[j].activ = false;
                            
                        }

                    }

                }
                break;
            }

            case 2: {
                if (user.emotion[i] >= 100 || user.emotion[i] <= 0) {
                    
                    for (int j = 0; j < room[user.current_loc].portal.size(); j++) {
                        if (room[user.current_loc].portal[j].name == "yellow") {
                            room[user.current_loc].portal[j].activ = false;

                        }
                    }
                }
            }

            default:
                break;
            }
        }


    }


    int main(){
      

        InitGame();

        string chouse;

     
      
        while (true) {

            scan_emotion();

            cout << "You in world :\t" << room[user.current_loc].name << endl;


            //cout << "go\n";
            cin >> chouse;

            if (chouse == "go") {

                for (int i = 0; i < room[user.current_loc].portal.size(); i++) {

                    auto p = room[user.current_loc].portal[i];
                    cout << p.name <<(p.activ ? " activ\n" : " NO activ\n") << endl;

                }

                

                cin >> chouse;

                for (int i = 0; i < room[user.current_loc].portal.size(); i++) {
                    auto p = room[user.current_loc].portal[i];

                    if (p.activ) {

                        if (chouse == p.name) {

                            user.current_loc = room[user.current_loc].portal[i].target;

                        }
                        /*else {
                            cout << "NO NAME ERROR\n";
                            break;
                        }*/

                    }
                    else {

                        cout << "You can't go. ERROR\n";
                        break;
                    }

                }

                cout << room[user.current_loc].name << endl;

            }

            if (chouse == "s") {

                user.emotion[0] = 100;

            }

            if (chouse == "r") {

                user.emotion[1] = 100;

            }


        }
    }
