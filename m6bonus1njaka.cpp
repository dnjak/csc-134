// csc 134
// m6bonus1
// daniel njaka
// 11/23/2026

#include <iostream>
#include <string>
using namespace std;

// constants for directions
enum Direction {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3,
    NUM_DIRECTIONS = 4
};

// direction names for output
const string DIRECTION_NAMES[NUM_DIRECTIONS] = {
    "north", "east", "south", "west"
};

// constants for rooms
enum Room {
    MAIN_ENTRANCE = 0,
    FOOD_COURT = 1,
    ARCADE = 2,
    DEPARTMENT_STORE = 3,
    PARKING_GARAGE = 4,
    NUM_ROOMS = 5
};

int main() {
    // room names
    string roomNames[NUM_ROOMS] = {
        "main entrance",
        "food court",
        "arcade",
        "department store",
        "parking garage"
    };

    // room descriptions
    string roomDescriptions[NUM_ROOMS] = {
        "broken glass doors and a dead fountain full of old pennies",
        "empty tables and faded menus and a pretzel sign that still flickers",
        "rows of dark game machines and one claw machine that is still humming",
        "mannequins in old clothes stand between knocked over racks",
        "a dark concrete garage that drips water and echoes every step"
    };

    // connections[from room][direction] = to room or -1 if there is no way through
    int connections[NUM_ROOMS][NUM_DIRECTIONS];

    // start with no connections
    for (int i = 0; i < NUM_ROOMS; i++) {
        for (int j = 0; j < NUM_DIRECTIONS; j++) {
            connections[i][j] = -1;
        }
    }

    // main entrance connections
    connections[MAIN_ENTRANCE][NORTH] = FOOD_COURT;
    connections[MAIN_ENTRANCE][EAST] = ARCADE;
    connections[MAIN_ENTRANCE][WEST] = DEPARTMENT_STORE;

    // food court connections
    connections[FOOD_COURT][SOUTH] = MAIN_ENTRANCE;

    // arcade connections
    connections[ARCADE][SOUTH] = PARKING_GARAGE;
    connections[ARCADE][WEST] = MAIN_ENTRANCE;

    // department store connections
    connections[DEPARTMENT_STORE][EAST] = MAIN_ENTRANCE;

    // parking garage connections
    connections[PARKING_GARAGE][NORTH] = ARCADE;

    // game state
    int currentRoom = MAIN_ENTRANCE;
    bool gameRunning = true;

    // game loop runs until the player quits
    while (gameRunning) {
        // show where the player is
        cout << endl << "you are in the " << roomNames[currentRoom] << endl;
        cout << roomDescriptions[currentRoom] << endl;

        // show the exits
        cout << "exits ";
        bool hasExits = false;
        for (int dir = 0; dir < NUM_DIRECTIONS; dir++) {
            if (connections[currentRoom][dir] != -1) {
                cout << DIRECTION_NAMES[dir] << " ";
                hasExits = true;
            }
        }
        if (!hasExits) {
            cout << "none";
        }
        cout << endl;

        // get the command
        string command;
        cout << endl << "what do you want to do ";
        cin >> command;

        // if input ends stop the game so it does not loop forever
        if (cin.fail()) {
            gameRunning = false;
        }
        // movement commands
        else if (command == "north" || command == "n") {
            if (connections[currentRoom][NORTH] != -1) {
                currentRoom = connections[currentRoom][NORTH];
            } else {
                cout << "you can not go that way" << endl;
            }
        } else if (command == "east" || command == "e") {
            if (connections[currentRoom][EAST] != -1) {
                currentRoom = connections[currentRoom][EAST];
            } else {
                cout << "you can not go that way" << endl;
            }
        } else if (command == "south" || command == "s") {
            if (connections[currentRoom][SOUTH] != -1) {
                currentRoom = connections[currentRoom][SOUTH];
            } else {
                cout << "you can not go that way" << endl;
            }
        } else if (command == "west" || command == "w") {
            if (connections[currentRoom][WEST] != -1) {
                currentRoom = connections[currentRoom][WEST];
            } else {
                cout << "you can not go that way" << endl;
            }
        } else if (command == "quit" || command == "q") {
            gameRunning = false;
        } else {
            cout << "i do not understand that command" << endl;
        }
    }

    cout << "thanks for playing" << endl;
    return 0;
}