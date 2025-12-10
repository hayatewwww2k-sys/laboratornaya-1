// base.h
#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
#include <fstream>
#include <exception>

class Base {
public:
    virtual ~Base() {}
    virtual std::string getType() const = 0;
    virtual void saveData(std::ofstream& out) const = 0;
    virtual void loadData(std::ifstream& in) = 0;
    virtual void edit() = 0;
    virtual void print() const = 0;
    virtual Base* clone() const = 0;
};

#endif