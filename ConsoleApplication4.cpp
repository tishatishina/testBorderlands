#include <iostream>
#include <string>
#include <windows.h>
#include <vector>



    using namespace std;

  

    struct player_ {

        int current_loc = 0;

        int emotion[6]{};

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

    location_ room[6];
    player_ user;

    void InitGame() {

        user.emotion[0] = { 50 };
        user.emotion[1] = { 50 };
        user.emotion[2] = { 50 };
        user.emotion[3] = { 50 };   
        user.emotion[4] = { 50 };    
        user.emotion[5] = { 50 };


        room[0].name = "sadness";
        room[0].portal.push_back({ "green", 0, true });
        room[0].portal.push_back({ "red", 2, true });
        room[0].portal.push_back({ "yellow", 3, true });
        room[0].portal.push_back({ "pink", 4, true });
        room[0].portal.push_back({ "brown", 5, true });

        room[1].name = "calmness";
        room[1].portal.push_back({ "blue", 1, true });
        room[1].portal.push_back({ "red", 2, true });
        room[1].portal.push_back({ "yellow", 3, true });
        room[1].portal.push_back({ "pink", 4, true });
        room[1].portal.push_back({ "brown", 5, true });

        room[2].name = "rage";
        room[2].portal.push_back({ "green", 0, true });
        room[2].portal.push_back({ "blue", 1, true });
        room[2].portal.push_back({ "yellow", 3, true });
        room[2].portal.push_back({ "pink", 4, true });
        room[2].portal.push_back({ "brown", 5, true });

        room[3].name = "power";
        room[3].portal.push_back({ "green", 0, true });
        room[3].portal.push_back({ "blue", 1, true });
        room[3].portal.push_back({ "red", 2, true });
        room[3].portal.push_back({ "pink", 4, true });
        room[3].portal.push_back({ "brown", 5, true });

        room[4].name = "joy";
        room[4].portal.push_back({ "blue", 1, true });
        room[4].portal.push_back({ "red", 2, true });
        room[4].portal.push_back({ "yellow", 3, true });
        room[4].portal.push_back({ "green", 0, true });
        room[4].portal.push_back({ "brown", 5, true });

        room[5].name = "fear";
        room[5].portal.push_back({ "blue", 1, true });
        room[5].portal.push_back({ "red", 2, true });
        room[5].portal.push_back({ "yellow", 3, true });
        room[5].portal.push_back({ "green", 0, true });
        room[5].portal.push_back({ "pink", 4, true });
    }

        void scan_emotion(){


            for (int i = 0; i < 6; i++) {

                switch (i)
                {

                case 0: {

                    if (user.emotion[i] >= 100 || user.emotion[i] <= 0) {

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

                            if (room[user.current_loc].portal[j].name == "green") {

                                room[user.current_loc].portal[j].activ = false;

                            }

                        }

                    }
                    break;
                }

                case 2: {
                    if (user.emotion[i] >= 100 || user.emotion[i] <= 0) {

                        for (int j = 0; j < room[user.current_loc].portal.size(); j++) {
                            if (room[user.current_loc].portal[j].name == "red") {
                                room[user.current_loc].portal[j].activ = false;

                            }
                        }
                    }
                }


                      break;

                case 3: {
                    if (user.emotion[i] >= 100 || user.emotion[i] <= 0) {

                        for (int j = 0; j < room[user.current_loc].portal.size(); j++) {
                            if (room[user.current_loc].portal[j].name == "yellow") {
                                room[user.current_loc].portal[j].activ = false;

                            }
                        }
                    }
                }
                      break;
                case 4: {
                    if (user.emotion[i] >= 100 || user.emotion[i] <= 0) {

                        for (int j = 0; j < room[user.current_loc].portal.size(); j++) {
                            if (room[user.current_loc].portal[j].name == "pink") {
                                room[user.current_loc].portal[j].activ = false;

                            }
                        }
                    }
                }
                      break;
                case 5: {
                    if (user.emotion[i] >= 100 || user.emotion[i] <= 0) {

                        for (int j = 0; j < room[user.current_loc].portal.size(); j++) {
                            if (room[user.current_loc].portal[j].name == "brown") {
                                room[user.current_loc].portal[j].activ = false;

                            }
                        }
                    }
                }
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

            if (chouse == "c") {

                user.emotion[1] = 100;

            }

            if (chouse == "r") {

                user.emotion[2] = 100;

            }
            
            if (chouse == "p") {

                user.emotion[3] = 100;

            }

            if (chouse == "j") {

                user.emotion[4] = 100;

            }

            if (chouse == "f") {

                user.emotion[5] = 100;

            }
        }
    }
