// novelist.h
#ifndef NOVELIST_H
#define NOVELIST_H

#include "base.h"

class Novelist : public Base {
private:
    std::string fio;
    int birth;
    int death;
    std::string* works;
    int num_works;
    std::string bio;

public:
    Novelist();
    Novelist(const std::string& f, int b, int d, const std::string* w, int n, const std::string& bi);
    Novelist(const Novelist& other);
    ~Novelist();

    Novelist& operator=(const Novelist& other);

    void setFio(const std::string& f);
    std::string getFio() const;
    void setBirth(int b);
    int getBirth() const;
    void setDeath(int d);
    int getDeath() const;
    void setNumWorks(int n);
    int getNumWorks() const;
    void setWork(int index, const std::string& w);
    void setBio(const std::string& bi);
    std::string getBio() const;

    std::string getType() const override;
    void saveData(std::ofstream& out) const override;
    void loadData(std::ifstream& in) override;
    void edit() override;
    void print() const override;
    Base* clone() const override;
};

#endif