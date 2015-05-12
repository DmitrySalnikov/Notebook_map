#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <map>

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::map;

class Notebook {
public:
    Notebook() = default;

    virtual ~Notebook() {}    

    void add(string const & name, string const & phone) { notes_.erase(name); notes_.insert({name, phone}); }

    string const * find(string const & name) { 
        auto it = notes_.find(name);
        if (it == notes_.end())
            return nullptr;
        else
            return &(it -> second);
    }

    void remove(string const & name) { notes_.erase(name); }

    void show_all() const {
        if (!notes_.empty())
            for (auto i = notes_.begin(); i != notes_.end(); ++i)
                cout << i -> first << ": " << i -> second << endl;
        else
            cout << "Notebook is empty" << endl;
    }

    void export_notes(string const & filename) {
         ifstream fin(filename);
         string name;
         string phone;
         getline(fin, name);
         getline(fin, phone);
         while (fin) {
             add(name, phone);
             getline(fin, name);
             getline(fin, phone);
         } 
         fin.close();
    }

    void import_notes(string const & filename) {
        ofstream fout(filename);
        string name;
        string phone;
        for (auto i = notes_.begin(); i != notes_.end(); ++i)
            fout << i -> first << endl << i -> second << endl;
        fout.close();
    }

private:
    map<string, string> notes_;
};
