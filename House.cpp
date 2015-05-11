// Copyright 2015 <Mikhail Shturov>
#include "house.h"

House::House() {
    HomeNumber = 0;
    NumberOfPeople = 0;
}

House::~House() {
}

House::House(const House &src) {
    HomeNumber = src.HomeNumber;
    NumberOfPeople = src.NumberOfPeople;
}

const int House::getHomeNumber() const {
    return this->HomeNumber;
}

void House::setHomeNumber(int a) {
    this->HomeNumber = a;
}

const int House::getNumberOfPeople() const {
    return this->NumberOfPeople;
}

void House::setNumberOfPeople(int a) {
    this->NumberOfPeople = a;
}

House & House ::operator=(const House &src) {
    this->HomeNumber = src.HomeNumber;
    this->NumberOfPeople = src.NumberOfPeople;
    return *this;
}

bool House::operator==(const House &src) const {
    if (this->HomeNumber != src.HomeNumber) return 0;
    if (this->NumberOfPeople != src.NumberOfPeople) return 0;
    return 1;
}
