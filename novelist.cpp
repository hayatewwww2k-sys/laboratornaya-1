// novelist.cpp
#include "novelist.h"

Novelist::Novelist() : fio(""), birth(0), death(0), works(nullptr), num_works(0), bio("") {
    std::cout << "Novelist default constructor called" << std::endl;
}

Novelist::Novelist(const std::string& f, int b, int d, const std::string* w, int n, const std::string& bi)
    : fio(f), birth(b), death(d), num_works(n), bio(bi) {
    if (n < 0) throw std::invalid_argument("Negative number of works");
    works = new std::string[n];
    for (int i = 0; i < n; ++i) {
        works[i] = w[i];
    }
    std::cout << "Novelist parameterized constructor called" << std::endl;
}

Novelist::Novelist(const Novelist& other)
    : fio(other.fio), birth(other.birth), death(other.death), num_works(other.num_works), bio(other.bio) {
    works = new std::string[num_works];
    for (int i = 0; i < num_works; ++i) {
        works[i] = other.works[i];
    }
    std::cout << "Novelist copy constructor called" << std::endl;
}

Novelist::~Novelist() {
    delete[] works;
    std::cout << "Novelist destructor called" << std::endl;
}

Novelist& Novelist::operator=(const Novelist& other) {
    if (this == &other) return *this;
    delete[] works;
    fio = other.fio;
    birth = other.birth;
    death = other.death;
    num_works = other.num_works;
    bio = other.bio;
    works = new std::string[num_works];
    for (int i = 0; i < num_works; ++i) {
        works[i] = other.works[i];
    }
    return *this;
}

void Novelist::setFio(const std::string& f) { fio = f; }
std::string Novelist::getFio() const { return fio; }
void Novelist::setBirth(int b) { birth = b; }
int Novelist::getBirth() const { return birth; }
void Novelist::setDeath(int d) { death = d; }
int Novelist::getDeath() const { return death; }
void Novelist::setNumWorks(int n) {
    if (n < 0) throw std::invalid_argument("Negative number of works");
    num_works = n;
}
int Novelist::getNumWorks() const { return num_works; }
void Novelist::setWork(int index, const std::string& w) {
    if (index < 0 || index >= num_works) throw std::out_of_range("Invalid work index");
    works[index] = w;
}
void Novelist::setBio(const std::string& bi) { bio = bi; }
std::string Novelist::getBio() const { return bio; }

std::string Novelist::getType() const { return "Novelist"; }

void Novelist::saveData(std::ofstream& out) const {
    out << fio << std::endl;
    out << birth << " " << death << std::endl;
    out << num_works << std::endl;
    for (int i = 0; i < num_works; ++i) {
        out << works[i] << std::endl;
    }
    out << bio << std::endl;
}

void Novelist::loadData(std::ifstream& in) {
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
    std::getline(in, bio);
}

void Novelist::edit() {
    std::cout << "Editing Novelist:" << std::endl;
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
    std::cout << "Enter new bio: ";
    std::getline(std::cin, bio);
}

void Novelist::print() const {
    std::cout << "Novelist - FIO: " << fio << ", Years: " << birth << "-" << death << std::endl;
    std::cout << "Works: ";
    for (int i = 0; i < num_works; ++i) {
        std::cout << works[i] << (i < num_works - 1 ? ", " : "");
    }
    std::cout << std::endl;
    std::cout << "Bio: " << bio << std::endl;
}

Base* Novelist::clone() const {
    return new Novelist(*this);
}