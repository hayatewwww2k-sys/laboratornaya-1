// keeper.h
#ifndef KEEPER_H
#define KEEPER_H

#include "base.h"

class Keeper {
private:
    Base** objs;
    int size;
    int capacity;

public:
    Keeper();
    Keeper(const Keeper& other);
    ~Keeper();

    Keeper& operator=(const Keeper& other);

    void add(Base* obj);
    void remove(int index);
    void save(const std::string& filename) const;
    void load(const std::string& filename);
    void printAll() const;
    int getSize() const;
    Base* operator[](int index);
    const Base* operator[](int index) const;
};

#endif