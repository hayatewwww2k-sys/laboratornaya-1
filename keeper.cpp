// keeper.cpp
#include "keeper.h"
#include "poet.h"
#include "novelist.h"
#include "fantast.h"

Keeper::Keeper() : size(0), capacity(10), objs(new Base* [10]) {
    std::cout << "Keeper default constructor called" << std::endl;
}

Keeper::Keeper(const Keeper& other) : size(other.size), capacity(other.capacity) {
    objs = new Base * [capacity];
    for (int i = 0; i < size; ++i) {
        objs[i] = other.objs[i]->clone();
    }
    std::cout << "Keeper copy constructor called" << std::endl;
}

Keeper::~Keeper() {
    for (int i = 0; i < size; ++i) {
        delete objs[i];
    }
    delete[] objs;
    std::cout << "Keeper destructor called" << std::endl;
}

Keeper& Keeper::operator=(const Keeper& other) {
    if (this == &other) return *this;
    for (int i = 0; i < size; ++i) {
        delete objs[i];
    }
    delete[] objs;
    size = other.size;
    capacity = other.capacity;
    objs = new Base * [capacity];
    for (int i = 0; i < size; ++i) {
        objs[i] = other.objs[i]->clone();
    }
    return *this;
}

void Keeper::add(Base* obj) {
    if (obj == nullptr) throw std::invalid_argument("Cannot add null object");
    if (size == capacity) {
        capacity *= 2;
        Base** new_objs = new Base * [capacity];
        for (int i = 0; i < size; ++i) {
            new_objs[i] = objs[i];
        }
        delete[] objs;
        objs = new_objs;
    }
    objs[size++] = obj;
}

void Keeper::remove(int index) {
    if (index < 0 || index >= size) throw std::out_of_range("Invalid index");
    delete objs[index];
    for (int i = index; i < size - 1; ++i) {
        objs[i] = objs[i + 1];
    }
    --size;
}

void Keeper::save(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) throw std::runtime_error("Cannot open file for saving");
    out << size << std::endl;
    for (int i = 0; i < size; ++i) {
        out << objs[i]->getType() << std::endl;
        objs[i]->saveData(out);
    }
    out.close();
}

void Keeper::load(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) throw std::runtime_error("Cannot open file for loading");
    for (int i = 0; i < size; ++i) {
        delete objs[i];
    }
    size = 0;
    int n;
    in >> n;
    in.ignore();
    for (int i = 0; i < n; ++i) {
        std::string type;
        std::getline(in, type);
        Base* obj = nullptr;
        if (type == "Poet") {
            obj = new Poet();
        }
        else if (type == "Novelist") {
            obj = new Novelist();
        }
        else if (type == "Fantast") {
            obj = new Fantast();
        }
        else {
            throw std::runtime_error("Unknown type in file: " + type);
        }
        obj->loadData(in);
        add(obj);
    }
    in.close();
}

void Keeper::printAll() const {
    for (int i = 0; i < size; ++i) {
        std::cout << "Index " << i << ":" << std::endl;
        objs[i]->print();
    }
}

int Keeper::getSize() const {
    return size;
}

Base* Keeper::operator[](int index) {
    if (index < 0 || index >= size) throw std::out_of_range("Invalid index");
    return objs[index];
}

const Base* Keeper::operator[](int index) const {
    if (index < 0 || index >= size) throw std::out_of_range("Invalid index");
    return objs[index];
}