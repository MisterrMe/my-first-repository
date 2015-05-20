// Copyright 2015 <Mikhail Shturov>
#include <iostream>
#include <string>
#include <list>
#include "./street.h"

Street::Street() {
    this->NameStreet = "";
}

Street::~Street() {
}

const int Street::GetNumberOfHouses() const {
    return houses.size();
}

const std::string Street::GetNameStreet() const {
    return this->NameStreet;
}

void Street::SetNameStreet(const std::string & NameStreet) {
    this->NameStreet = NameStreet;
}

void Street::SetLenStreet(const int & length) {
    this->Length = length;
}

void Street::SetHouses(const int *Value, const int & Number) {
    for (int i = 0; i < Number; i++) {
        House src;
        src.setHomeNumber(i + 1);
        src.setNumberOfPeople(Value[i]);
        houses.push_back(src);
    }
}

void Street::AddHouse(const int & n, const int & p) {
    std::list<House>::iterator iter;
    House *src;
    src = new House();
    src->setHomeNumber(n);
    src->setNumberOfPeople(p);
    iter = houses.begin();
    std::advance(iter, n - 1);
    houses.insert(iter, *src);
    for (double i = n; i < houses.size(); i++) {
        iter->setHomeNumber(iter->getHomeNumber() + 1);
        ++iter;
    }
    delete src;
}

void Street::DeleteHouse(const int n) {
    std::list<House>::iterator iter;
    iter = houses.begin();
    std::advance(iter, n-1);
    iter = houses.erase(iter);
    for (double i = n; i < houses.size() + 1; i++) {
        iter->setHomeNumber(iter->getHomeNumber() - 1);
        ++iter;
    }
}

const int Street::GetHouseData(const int n) {
    std::list<House>::iterator iter;
    iter = houses.begin();
    std::advance(iter, n - 1);
    return iter->getNumberOfPeople();
}

const int Street::GetNumberOfHouses() {
    return houses.size();
}

House& Street::Get(const int & n) {
    std::list<House>::iterator iter;
    iter = houses.begin();
    std::advance(iter, n - 1);
    return *iter;
}

void Street::Print() {
    std::list<House>::iterator iter;
    int num = 0;
    std::cout << this->NameStreet << " street\n";
    iter = houses.begin();
    for (double i = 0; i < houses.size(); i++) {
        int a = iter->getNumberOfPeople();
        num = num + a;
        std::cout << "House number ";
        std::cout << iter->getHomeNumber() << ". ";
        std::cout << "Number of residents is ";
        std::cout << iter->getNumberOfPeople() << "\n";
        ++iter;
    }
    std::cout << "The total length of street is ";
    std::cout << this->Length << "\n";
    std::cout << "The total number of residents is ";
    std::cout << num << "\n";
    std::cout << "The totel number of houses is ";
    std::cout << houses.size() << "\n";
}

Street & Street ::operator=(const Street &src) {
    if (this != &src) {
        this->NameStreet = src.NameStreet;
    }
    return *this;
}

bool Street::operator==(const Street &src) const {
    return (this->NameStreet == src.NameStreet);
}
