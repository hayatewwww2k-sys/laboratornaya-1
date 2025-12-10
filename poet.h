// poet.h
#ifndef POET_H
#define POET_H

#include "base.h"

class Poet : public Base {
private:
    std::string fio;
    int birth;
    int death;
    std::string* works;
    int num_works;

public:
    Poet();
    Poet(const std::string& f, int b, int d, const std::string* w, int n);
    Poet(const Poet& other);
    ~Poet();

    Poet& operator=(const Poet& other);

    void setFio(const std::string& f);
    std::string getFio() const;
    void setBirth(int b);
    int getBirth() const;
    void setDeath(int d);
    int getDeath() const;
    void setNumWorks(int n);
    int getNumWorks() const;
    void setWork(int index, const std::string& w);

    std::string getType() const override;
    void saveData(std::ofstream& out) const override;
    void loadData(std::ifstream& in) override;
    void edit() override;
    void print() const override;
    Base* clone() const override;
};

#endif