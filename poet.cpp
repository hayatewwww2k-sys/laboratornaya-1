// poet.cpp
#include "poet.h"

Poet::Poet() : fio(""), birth(0), death(0), works(nullptr), num_works(0) {
    std::cout << "Poet default constructor called" << std::endl;
}

Poet::Poet(const std::string& f, int b, int d, const std::string* w, int n)
    : fio(f), birth(b), death(d), num_works(n) {
    if (n < 0) throw std::invalid_argument("Negative number of works");
    works = new std::string[n];
    for (int i = 0; i < n; ++i) {
        works[i] = w[i];
    }
    std::cout << "Poet parameterized constructor called" << std::endl;
}

Poet::Poet(const Poet& other)
    : fio(other.fio), birth(other.birth), death(other.death), num_works(other.num_works) {
    works = new std::string[num_works];
    for (int i = 0; i < num_works; ++i) {
        works[i] = other.works[i];
    }
    std::cout << "Poet copy constructor called" << std::endl;
}

Poet::~Poet() {
    delete[] works;
    std::cout << "Poet destructor called" << std::endl;
}

Poet& Poet::operator=(const Poet& other) {
    if (this == &other) return *this;
    delete[] works;
    fio = other.fio;
    birth = other.birth;
    death = other.death;
    num_works = other.num_works;
    works = new std::string[num_works];
    for (int i = 0; i < num_works; ++i) {
        works[i] = other.works[i];
    }
    return *this;
}

void Poet::setFio(const std::string& f) { fio = f; }
std::string Poet::getFio() const { return fio; }
void Poet::setBirth(int b) { birth = b; }
int Poet::getBirth() const { return birth; }
void Poet::setDeath(int d) { death = d; }
int Poet::getDeath() const { return death; }
void Poet::setNumWorks(int n) {
    if (n < 0) throw std::invalid_argument("Negative number of works");
    num_works = n;
}
int Poet::getNumWorks() const { return num_works; }
void Poet::setWork(int index, const std::string& w) {
    if (index < 0 || index >= num_works) throw std::out_of_range("Invalid work index");
    works[index] = w;
}

std::string Poet::getType() const { return "Poet"; }

void Poet::saveData(std::ofstream& out) const {
    out << fio << std::endl;
    out << birth << " " << death << std::endl;
    out << num_works << std::endl;
    for (int i = 0; i < num_works; ++i) {
        out << works[i] << std::endl;
    }
}

void Poet::loadData(std::ifstream& in) {
    std::getline(in, fio);
    in >> birth >> death;
    in >> num_works;
    in.ignore();
    if (num_works < 0) throw std::invalid_argument("Negative number of works from file");
    delete[] works;
    works = new std::string[num_works];
    for (int i = 0; i < num_works; ++i) {
        std::getline(in, works[i]);
    }
}

void Poet::edit() {
    std::cout << "Editing Poet:" << std::endl;
    print();
    std::cout << "Enter new FIO: ";
    std::getline(std::cin, fio);
    std::cout << "Enter new birth year: ";
    std::cin >> birth;
    std::cout << "Enter new death year: ";
    std::cin >> death;
    std::cin.ignore();
    std::cout << "Enter new number of works: ";
    int new_num;
    std::cin >> new_num;
    std::cin.ignore();
    if (new_num < 0) throw std::invalid_argument("Negative number of works");
    delete[] works;
    num_works = new_num;
    works = new std::string[num_works];
    for (int i = 0; i < num_works; ++i) {
        std::cout << "Enter work " << (i + 1) << ": ";
        std::getline(std::cin, works[i]);
    }
}

void Poet::print() const {
    std::cout << "Poet - FIO: " << fio << ", Years: " << birth << "-" << death << std::endl;
    std::cout << "Works: ";
    for (int i = 0; i < num_works; ++i) {
        std::cout << works[i] << (i < num_works - 1 ? ", " : "");
    }
    std::cout << std::endl;
}

Base* Poet::clone() const {
    return new Poet(*this);
}