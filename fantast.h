// fantast.h
#ifndef FANTAST_H
#define FANTAST_H

#include "base.h"

class Fantast : public Base {
private:
    std::string fio;
    std::string* works;
    int num_works;
    bool films;

public:
    Fantast();
    Fantast(const std::string& f, const std::string* w, int n, bool fi);
    Fantast(const Fantast& other);
    ~Fantast();

    Fantast& operator=(const Fantast& other);

    void setFio(const std::string& f);
    std::string getFio() const;
    void setNumWorks(int n);
    int getNumWorks() const;
    void setWork(int index, const std::string& w);
    void setFilms(bool fi);
    bool getFilms() const;

    std::string getType() const override;
    void saveData(std::ofstream& out) const override;
    void loadData(std::ifstream& in) override;
    void edit() override;
    void print() const override;
    Base* clone() const override;
};

#endif