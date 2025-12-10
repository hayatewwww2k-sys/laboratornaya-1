// main.cpp
#include <iostream>
#include <string>
#include "keeper.h"
#include "poet.h"
#include "novelist.h"
#include "fantast.h"

Base* createPoet() {
    std::string fio;
    int birth, death, num_works;
    std::cout << "Enter FIO: ";
    std::getline(std::cin, fio);
    std::cout << "Enter birth year: ";
    std::cin >> birth;
    std::cout << "Enter death year: ";
    std::cin >> death;
    std::cin.ignore();
    std::cout << "Enter number of works: ";
    std::cin >> num_works;
    std::cin.ignore();
    std::string* works = new std::string[num_works];
    for (int i = 0; i < num_works; ++i) {
        std::cout << "Enter work " << (i + 1) << ": ";
        std::getline(std::cin, works[i]);
    }
    Base* obj = new Poet(fio, birth, death, works, num_works);
    delete[] works;
    return obj;
}

Base* createNovelist() {
    std::string fio, bio;
    int birth, death, num_works;
    std::cout << "Enter FIO: ";
    std::getline(std::cin, fio);
    std::cout << "Enter birth year: ";
    std::cin >> birth;
    std::cout << "Enter death year: ";
    std::cin >> death;
    std::cin.ignore();
    std::cout << "Enter number of works: ";
    std::cin >> num_works;
    std::cin.ignore();
    std::string* works = new std::string[num_works];
    for (int i = 0; i < num_works; ++i) {
        std::cout << "Enter work " << (i + 1) << ": ";
        std::getline(std::cin, works[i]);
    }
    std::cout << "Enter bio: ";
    std::getline(std::cin, bio);
    Base* obj = new Novelist(fio, birth, death, works, num_works, bio);
    delete[] works;
    return obj;
}

Base* createFantast() {
    std::string fio;
    int num_works;
    bool films;
    std::cout << "Enter FIO: ";
    std::getline(std::cin, fio);
    std::cout << "Enter number of works: ";
    std::cin >> num_works;
    std::cin.ignore();
    std::string* works = new std::string[num_works];
    for (int i = 0; i < num_works; ++i) {
        std::cout << "Enter work " << (i + 1) << ": ";
        std::getline(std::cin, works[i]);
    }
    std::cout << "Films made (1/0): ";
    std::cin >> films;
    std::cin.ignore();
    Base* obj = new Fantast(fio, works, num_works, films);
    delete[] works;
    return obj;
}

int main() {
    Keeper keeper;
    int choice = -1;
    while (choice != 0) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Poet\n";
        std::cout << "2. Add Novelist\n";
        std::cout << "3. Add Fantast\n";
        std::cout << "4. Remove object\n";
        std::cout << "5. Display all\n";
        std::cout << "6. Edit object\n";
        std::cout << "7. Save to file\n";
        std::cout << "8. Load from file\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore();

        try {
            switch (choice) {
            case 1: {
                Base* obj = createPoet();
                keeper.add(obj);
                break;
            }
            case 2: {
                Base* obj = createNovelist();
                keeper.add(obj);
                break;
            }
            case 3: {
                Base* obj = createFantast();
                keeper.add(obj);
                break;
            }
            case 4: {
                int index;
                std::cout << "Enter index to remove: ";
                std::cin >> index;
                std::cin.ignore();
                keeper.remove(index);
                break;
            }
            case 5: {
                keeper.printAll();
                break;
            }
            case 6: {
                int index;
                std::cout << "Enter index to edit: ";
                std::cin >> index;
                std::cin.ignore();
                if (index >= 0 && index < keeper.getSize()) {
                    keeper[index]->edit();
                }
                else {
                    std::cout << "Invalid index" << std::endl;
                }
                break;
            }
            case 7: {
                std::string filename;
                std::cout << "Enter filename to save: ";
                std::getline(std::cin, filename);
                keeper.save(filename);
                break;
            }
            case 8: {
                std::string filename;
                std::cout << "Enter filename to load: ";
                std::getline(std::cin, filename);
                keeper.load(filename);
                break;
            }
            case 0:
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
            }
        }
        catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    return 0;
}