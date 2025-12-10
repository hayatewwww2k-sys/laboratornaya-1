// fantast.cpp
#include "fantast.h"

Fantast::Fantast() : fio(""), works(nullptr), num_works(0), films(false) {
    std::cout << "Fantast default constructor called" << std::endl;
}

Fantast::Fantast(const std::string& f, const std::string* w, int n, bool fi)
    : fio(f), num_works(n), films(fi) {
    if (n < 0) throw std::invalid_argument("Negative number of works");
    works = new std::string[n];
    for (int i = 0; i < n; ++i) {
        works[i] = w[i];
    }
    std::cout << "Fantast parameterized constructor called" << std::endl;
}

Fantast::Fantast(const Fantast& other)
    : fio(other.fio), num_works(other.num_works), films(other.films) {
    works = new std::string[num_works];
    for (int i = 0; i < num_works; ++i) {
        works[i] = other.works[i];
    }
    std::cout << "Fantast copy constructor called" << std::endl;
}

Fantast::~Fantast() {
    delete[] works;
    std::cout << "Fantast destructor called" << std::endl;
}

Fantast& Fantast::operator=(const Fantast& other) {
    if (this == &other) return *this;
    delete[] works;
    fio = other.fio;
    num_works = other.num_works;
    films = other.films;
    works = new std::string[num_works];
    for (int i = 0; i < num_works; ++i) {
        works[i] = other.works[i];
    }
    return *this;
}

void Fantast::setFio(const std::string& f) { fio = f; }
std::string Fantast::getFio() const { return fio; }
void Fantast::setNumWorks(int n) {
    if (n < 0) throw std::invalid_argument("Negative number of works");
    num_works = n;
}
int Fantast::getNumWorks() const { return num_works; }
void Fantast::setWork(int index, const std::string& w) {
    if (index < 0 || index >= num_works) throw std::out_of_range("Invalid work index");
    works[index] = w;
}
void Fantast::setFilms(bool fi) { films = fi; }
bool Fantast::getFilms() const { return films; }

std::string Fantast::getType() const { return "Fantast"; }

void Fantast::saveData(std::ofstream& out) const {
    out << fio << std::endl;
    out << num_works << std::endl;
    for (int i = 0; i < num_works; ++i) {
        out << works[i] << std::endl;
    }
    out << films << std::endl;
}

void Fantast::loadData(std::ifstream& in) {
    std::getline(in, fio);
    in >> num_works;
    in.ignore();
    if (num_works < 0) throw std::invalid_argument("Negative number of works from file");
    delete[] works;
    works = new std::string[num_works];
    for (int i = 0; i < num_works; ++i) {
        std::getline(in, works[i]);
    }
    in >> films;
    in.ignore();
}

void Fantast::edit() {
    std::cout << "Editing Fantast:" << std::endl;
    print();
    std::cout << "Enter new FIO: ";
    std::getline(std::cin, fio);
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
    std::cout << "Films made (1/0): ";
    std::cin >> films;
    std::cin.ignore();
}

void Fantast::print() const {
    std::cout << "Fantast - FIO: " << fio << std::endl;
    std::cout << "Works: ";
    for (int i = 0; i < num_works; ++i) {
        std::cout << works[i] << (i < num_works - 1 ? ", " : "");
    }
    std::cout << std::endl;
    std::cout << "Films made: " << (films ? "Yes" : "No") << std::endl;
}

Base* Fantast::clone() const {
    return new Fantast(*this);
}