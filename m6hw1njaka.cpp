// csc 134
// m6hw1 gold
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

// constants for rooms
enum Room {
    MAIN_ENTRANCE = 0,
    FOOD_COURT = 1,
    ARCADE = 2,
    DEPARTMENT_STORE = 3,
    PARKING_GARAGE = 4,
    OUTSIDE = 5,
    NUM_ROOMS = 6
};

// direction names for output
const string DIRECTION_NAMES[NUM_DIRECTIONS] = {
    "north", "east", "south", "west"
};

// room names
const string ROOM_NAMES[NUM_ROOMS] = {
    "main entrance",
    "food court",
    "arcade",
    "department store",
    "parking garage",
    "outside"
};

// room descriptions
const string ROOM_DESCRIPTIONS[NUM_ROOMS] = {
    "broken glass doors and a dead fountain full of old pennies\nthe front doors are chained shut but there is a sign by the fountain",
    "empty tables and faded menus and a pretzel sign that still flickers",
    "rows of dark game machines and one claw machine that is still humming\nan old security guard is sitting on a stool by the prize counter",
    "mannequins in old clothes stand between knocked over racks",
    "a dark concrete garage that drips water and echoes every step\nthe exit gate to the south has a keycard reader",
    "fresh air and street lights"
};

// the item sitting in each room or "" if there is nothing
string roomItems[NUM_ROOMS] = {"", "keycard", "", "flashlight", "", ""};

// connections[from room][direction] = to room or -1 if there is no way through
int connections[NUM_ROOMS][NUM_DIRECTIONS];

// game state
int currentRoom = MAIN_ENTRANCE;
bool gameRunning = true;
bool hasKeycard = false;
bool hasFlashlight = false;

// function prototypes
void setupConnections();
void showIntro();
void showRoom();
void showHelp();
void readSign();
void talk();
void takeItem();
void showInventory();
void tryMove(int dir);
void showEnding();

int main() {
    setupConnections();
    showIntro();

    string command;

    // game loop runs until the player escapes or quits
    while (gameRunning) {
        showRoom();

        cout << endl << "what do you want to do ";
        cin >> command;

        // if input ends stop the game so it does not loop forever
        if (cin.fail()) {
            gameRunning = false;
        } else if (command == "north" || command == "n") {
            tryMove(NORTH);
        } else if (command == "east" || command == "e") {
            tryMove(EAST);
        } else if (command == "south" || command == "s") {
            tryMove(SOUTH);
        } else if (command == "west" || command == "w") {
            tryMove(WEST);
        } else if (command == "take" || command == "t") {
            takeItem();
        } else if (command == "talk") {
            talk();
        } else if (command == "read" || command == "r") {
            readSign();
        } else if (command == "inventory" || command == "i") {
            showInventory();
        } else if (command == "help" || command == "h") {
            showHelp();
        } else if (command == "quit" || command == "q") {
            gameRunning = false;
            cout << "you give up and stay lost in the mall" << endl;
        } else {
            cout << "i do not understand that command so type help" << endl;
        }
    }

    cout << "thanks for playing" << endl;
    return 0;
}

// set up which rooms connect to which
void setupConnections() {
    // start with no connections
    for (int i = 0; i < NUM_ROOMS; i++) {
        for (int j = 0; j < NUM_DIRECTIONS; j++) {
            connections[i][j] = -1;
        }
    }

    connections[MAIN_ENTRANCE][NORTH] = FOOD_COURT;
    connections[MAIN_ENTRANCE][EAST] = ARCADE;
    connections[MAIN_ENTRANCE][WEST] = DEPARTMENT_STORE;

    connections[FOOD_COURT][SOUTH] = MAIN_ENTRANCE;

    connections[ARCADE][SOUTH] = PARKING_GARAGE;
    connections[ARCADE][WEST] = MAIN_ENTRANCE;

    connections[DEPARTMENT_STORE][EAST] = MAIN_ENTRANCE;

    connections[PARKING_GARAGE][NORTH] = ARCADE;
    connections[PARKING_GARAGE][SOUTH] = OUTSIDE;
}

// the start of the game
void showIntro() {
    cout << "the abandoned mall" << endl;
    cout << "you snuck into the old mall to look around" << endl;
    cout << "but the door slammed behind you and now you are stuck inside" << endl;
    cout << "find a way out" << endl;
    showHelp();
}

// show the commands the player can use
void showHelp() {
    cout << endl << "commands" << endl;
    cout << "n e s w   move north east south or west" << endl;
    cout << "take      pick up an item" << endl;
    cout << "talk      talk to someone" << endl;
    cout << "read      read a sign" << endl;
    cout << "i         check your inventory" << endl;
    cout << "help      show this list" << endl;
    cout << "q         quit" << endl;
}

// show the room the player is in plus items and exits
void showRoom() {
    cout << endl << "you are in the " << ROOM_NAMES[currentRoom] << endl;
    cout << ROOM_DESCRIPTIONS[currentRoom] << endl;

    if (roomItems[currentRoom] != "") {
        cout << "you see a " << roomItems[currentRoom] << " here" << endl;
    }

    cout << "exits ";
    for (int dir = 0; dir < NUM_DIRECTIONS; dir++) {
        if (connections[currentRoom][dir] != -1) {
            cout << DIRECTION_NAMES[dir] << " ";
        }
    }
    cout << endl;
}

// the sign at the main entrance explains the point of the game
void readSign() {
    if (currentRoom == MAIN_ENTRANCE) {
        cout << "the sign says" << endl;
        cout << "mall closed for good" << endl;
        cout << "the only working exit is the parking garage gate" << endl;
        cout << "staff need a keycard to open it" << endl;
    } else {
        cout << "there is no sign here" << endl;
    }
}

// the security guard gives hints
void talk() {
    if (currentRoom == ARCADE) {
        cout << "the guard looks up from his stool" << endl;
        if (!hasFlashlight) {
            cout << "guard says the garage is pitch black so you will need a light" << endl;
            cout << "guard says try the department store they used to sell flashlights" << endl;
        } else if (!hasKeycard) {
            cout << "guard says good you found a light" << endl;
            cout << "guard says i dropped my keycard at the pretzel stand in the food court" << endl;
        } else {
            cout << "guard says you have everything so get out of here before it gets late" << endl;
        }
    } else {
        cout << "there is nobody here to talk to" << endl;
    }
}

// pick up the item in the room if there is one
void takeItem() {
    if (roomItems[currentRoom] == "") {
        cout << "there is nothing here to take" << endl;
    } else {
        cout << "you pick up the " << roomItems[currentRoom] << endl;
        if (roomItems[currentRoom] == "keycard") {
            hasKeycard = true;
        } else if (roomItems[currentRoom] == "flashlight") {
            hasFlashlight = true;
        }
        roomItems[currentRoom] = "";
    }
}

// list what the player is carrying
void showInventory() {
    cout << "you are carrying ";
    if (!hasKeycard && !hasFlashlight) {
        cout << "nothing";
    }
    if (hasFlashlight) {
        cout << "a flashlight ";
    }
    if (hasKeycard) {
        cout << "a keycard";
    }
    cout << endl;
}

// move the player if the way is open and not locked
void tryMove(int dir) {
    int nextRoom = connections[currentRoom][dir];

    if (nextRoom == -1) {
        cout << "you can not go that way" << endl;
    }
    // lock 1 the garage is too dark without the flashlight
    else if (nextRoom == PARKING_GARAGE && !hasFlashlight) {
        cout << "the garage is too dark to walk into without a light" << endl;
    }
    // lock 2 the exit gate needs the keycard
    else if (nextRoom == OUTSIDE && !hasKeycard) {
        cout << "you push the gate but it will not move" << endl;
        cout << "the keycard reader blinks red" << endl;
    } else {
        currentRoom = nextRoom;
        if (currentRoom == OUTSIDE) {
            showEnding();
        }
    }
}

// the ending when the player escapes
void showEnding() {
    cout << endl << "you swipe the keycard and the reader turns green" << endl;
    cout << "the gate rattles up and cold night air rushes in" << endl;
    cout << "you walk out into the parking lot and you are free" << endl;
    cout << "you escaped the abandoned mall" << endl;
    gameRunning = false;
}