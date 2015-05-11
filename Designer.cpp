// Copyright 2015 <Mikhail Shturov>
#include <iostream>
#include <string>
#include "street.h"

void DialogWithTheUser(Street *Str) {
    std::string Name;
    int Number, ch;
    while (1) {
        std::cout << "\nPress:";
        std::cout << "\n1 - to add new house, ";
        std::cout << "\n2 - to remove house, ";
        std::cout << "\n3 - to get house data, ";
        std::cout << "\n4 - to get street data, ";
        std::cout << "\n5 - to rename street, ";
        std::cout << "\n0 - to exit\n";
        std::cin >> ch;
        if (ch != 0 && ch != 1 && ch != 2 && ch != 3 && ch != 4 && ch != 5) {
            std::cout << "Invalid input data. Re-enter.\n";
            continue;
        }
        if (ch == 1) {
            std::cout << "Enter the number of house ";
            std::cout << "in front of which will be new.\n";
            std::cout << "If you add the last house - ";
            std::cout << "enter a number one greater ";
            std::cout << "than the number of homes\n";
            std::cout << "(if the house is not the last, ";
            std::cout << "the numbering of the remaining will be shifted)\n";
            while (1) {
                std::cin >> Number;
                if (Number > Str->GetNumberOfHouses() + 1 || Number < 1) {
                    std::cout << "There is no such home. Re-enter.\n";
                    continue;
                }

                std::cout << "Enter the number of residents in ";
                std::cout << Number;
                std::cout << "house.";
                int people;
                while (1) {
                    std::cin >> people;
                    if (people < 0) {
                        std::cout << "Number of people in ";
                        std::cout << Number + 1;
                        std::cout << " house can not be negative. Re-enter. ";
                        continue;
                    }
                    break;
                }
                Str->AddHouse(Number, people);
                break;
            }
        }
        if (ch == 2) {
            while (1) {
                std::cout << "Enter the number of house to remove.";
                std::cin >> Number;
                if (Number > Str->GetNumberOfHouses() || Number < 0) {
                    std::cout << "There is no such home. Re-enter.\n";
                    continue;
                }
                Str->DeleteHouse(Number);
                break;
            }
        }
        if (ch == 3) {
            while (1) {
                std::cout << "Enter the number of house to get data.";
                std::cin >> Number;
                if (Number > Str->GetNumberOfHouses() || Number < 0) {
                    std::cout << "There is no such home. Re-enter.\n";
                    continue;
                }
                Str->GetHouseData(Number);
                break;
            }
        }
        if (ch == 4)
            Str->Print();
        if (ch == 5) {
            std::cout << "Enter the new name of the street - ";
            std::cin >> Name;
            Str->SetStreet(Name, Str->GetNumberOfHouses());
        }
        if (ch == 0)
            break;
    }
}

void Create(Street *Str) {
    std::string Name;
    int Number;
    std::cout << "Welcome to the design of streets\n";
    std::cout << "To start, enter the name of the street - ";
    std::cin >> Name;
    std::cout << "Very good. Now enter the number of houses - ";
    while (1) {
        std::cin >> Number;
        if (Number < 0) {
            std::cout << "Number of houses can not be negative. Re-enter. ";
            continue;
        }
        if (Number == 0) {
            int a;
            while (1) {
                std::cout << "You create an empty street.";
                std::cout << "Confirm this ? 1 - Yes, 0 - No";
                std::cin >> a;
                if (a != 0 && a != 1) {
                    std::cout << "Invalid input data. Re-enter.\n";
                    continue;
                }
                if (a == 1 || a == 0)
                    break;
            }
            if (a == 0) {
                std::cout << "Enter the new number of houses.";
                continue;
            }
            if (a == 1)
                break;
        }
        if (Number > 0) {
            break;
        }
        continue;
    }
    int *value = new int[Number];
    for (int i = 0; i < Number; i++) {
        std::cout << "Enter the number of residents in ";
        std::cout << i + 1;
        std::cout << " house.";
        while (1) {
            std::cin >> value[i];
            if (value[i] < 0) {
                std::cout << "Number of people in ";
                std::cout << i + 1;
                std::cout << " house can not be negative. Re-enter. ";
                continue;
            }
            break;
        }
    }
    Str->SetStreet(Name, Number);
    Str->SetHouses(value);
    std::cout << "The street was successfully created.";
    std::cout << "\nNow you can control your street\n";
    delete[] value;
}

int main() {
    Street *Str = new Street;
    Create(Str);
    DialogWithTheUser(Str);
    return 0;
}
