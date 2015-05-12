#include <iostream>
#include <map>
#include <cctype>
#include "Notebook.h"

using std::cin;
using std::cout;
using std::endl;
using std::tolower;

int main() {
    Notebook my;

    my.export_notes("notebook");

    cout << "------------------\n"
        << "Select action:\n"
        << "1) Add note\n"
        << "2) Find note\n"
        << "3) Remove note\n"
        << "4) Show all notes\n"
        << "q) Close notebook\n"
        << "------------------\n";    


    char ans;
    
    ans = cin.get();
    while (((ans < '1') || (ans > '4')) && (ans != 'q')) {
        if (ans != '\n')
            while (cin.get() != '\n');
        cout << "Please, enter correct command: ";
        ans = cin.get();
    }
    while (cin.get() != '\n');
    
    while (tolower(ans) != 'q') {
        switch (ans) {
            case '1' : {
                string name;
                cout << "Enter name: ";
                getline(cin, name);
                string phone;
                cout << "Enter phone: ";
                getline(cin, phone);
                if (!my.find(name))
                    my.add(name, phone);
                else {
                    cout << "Note " << name << " is already exist, replace? [y/n]: ";
                    char ch;
                    ch = cin.get();
                    ch = tolower(ch);
                    if (ch != '\n')
                        while (cin.get() != '\n');
                    while (ch != 'y' && ch != 'n') {
                        cout << "Enter y or n: ";
                        ch = cin.get();
                        ch = tolower(ch);
                        if (ch != '\n')
                            while (cin.get() != '\n');
                    }

                    if (tolower(ch) == 'y')
                        my.add(name, phone);
                }
                break;
            }
            case '2' : {
                string name;
                cout << "Enter name: ";
                getline(cin, name);
                auto res = my.find(name);
                if (!res)
                    cout << name << " not found\n";
                else
                    cout << name << ": " << *res << endl;
                break;
            }
            case '3' : {
                string name;
                cout << "Enter name: ";
                getline(cin, name);
                if (!my.find(name))
                    cout << name << " not found\n";
                else {
                    cout << "Confirm removal " << name << " [y/n]: ";
                    char ch;
                    ch = cin.get();
                    ch = tolower(ch);
                    if (ch != '\n')
                        while (cin.get() != '\n');
                    while (ch != 'y' && ch != 'n') {
                        cout << "Enter y or n: ";
                        ch = cin.get();
                        ch = tolower(ch);
                        if (ch != '\n')
                            while (cin.get() != '\n');
                    }

                    if (tolower(ch) == 'y')
                        my.remove(name);
                    cout << "Removal " << name << " complete\n";
                }
                break;
            }
            case '4' :
                my.show_all();
        }

        cout << "\n------------------\n"
            << "Select action:\n"
            << "1) Add note\n"
            << "2) Find note\n"
            << "3) Remove note\n"
            << "4) Show all notes\n"
            << "q) Close notebook\n"
            << "------------------\n";

        ans = cin.get();
        while (((ans < '1') || (ans > '4')) && (ans != 'q')) {
            if (ans != '\n')
                while (cin.get() != '\n');
            cout << "Please, enter correct command: ";
            ans = cin.get();
        }
        while (cin.get() != '\n');
    }

    my.import_notes("notebook");

    return 0;
}
