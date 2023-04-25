#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Friend {
    string surname;
    string firstname;
    string zodiac;
    int birthday[3];
};

void addFriend(ofstream& fout, Friend& friendData) {
    cout << "Enter surname and firstname: ";
    cin >> friendData.surname >> friendData.firstname;
    cout << "Enter zodiac sign: ";
    cin >> friendData.zodiac;
    cout << "Enter birthday day, month and year: ";
    cin >> friendData.birthday[0] >> friendData.birthday[1] >> friendData.birthday[2];
    fout << friendData.surname << " " << friendData.firstname << ";" << friendData.zodiac << ";"
        << friendData.birthday[0] << " " << friendData.birthday[1] << " " << friendData.birthday[2] << endl;
}

void printFriend(const Friend& friendData) {
    cout << "Name: " << friendData.surname << " " << friendData.firstname << endl;
    cout << "Zodiac sign: " << friendData.zodiac << endl;
    cout << "Birthday: " << friendData.birthday[0] << "/" << friendData.birthday[1] << "/"
        << friendData.birthday[2] << endl;
}

void displayFriends(const string& filename) {
    ifstream fin(filename);
    Friend friendData;

    while (fin >> friendData.surname >> friendData.firstname >> friendData.zodiac >>
        friendData.birthday[0] >> friendData.birthday[1] >> friendData.birthday[2]) {
        printFriend(friendData);
        cout << endl;
    }

    fin.close();
}

void findFriendsByMonth(const string& filename, int month) {
    ifstream fin(filename);
    Friend friendData;
    bool found = false;

    while (fin >> friendData.surname >> friendData.firstname >> friendData.zodiac >>
        friendData.birthday[0] >> friendData.birthday[1] >> friendData.birthday[2]) {
        if (friendData.birthday[1] == month) {
            printFriend(friendData);
            cout << endl;
            found = true;
        }
    }

    fin.close();

    if (!found) {
        cout << "No friends born in this month" << endl;
    }
}

int main() {
    string filename = "friends.txt";
    int option, month;
    Friend friendData;
    ofstream fout;

    fout.open(filename, ios::app);

    do {
        cout << "Enter option: ";
        cin >> option;
        switch (option) {
        case 1:
            addFriend(fout, friendData);
            break;
        case 2:
            displayFriends(filename);
            break;
        case 3:
            cout << "Enter month: ";
            cin >> month;
            findFriendsByMonth(filename, month);
            break;
        case 4:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    } while (option != 4);

    fout.close();

    return 0;
}