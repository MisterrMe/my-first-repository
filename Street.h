// Copyright 2015 <Mikhail Shturov>
#pragma once

#include <list>
#include <string>
#include "house.h"

class Street{
 private:
    int NumberOfHouses;
    std::string NameStreet;
 public:
    std::list<House> list;
    std::list<House>::iterator iter;
    Street();
    ~Street();
    const int GetNumberOfHouses() const;
    const std::string GetNameStreet() const;
    void SetStreet(const std::string NameStreet, const int NumberOfHouses);
    void SetHouses(int *Value);
    void AddHouse(const int n, const int p);
    void DeleteHouse(int n);
    void GetHouseData(int n);
    void Print();
};
