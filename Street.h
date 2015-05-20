// Copyright 2015 <Mikhail Shturov>
#pragma once

#include <list>
#include <string>
#include "./house.h"

class Street{
 private:
    int Length;
    std::string NameStreet;
    std::list<House> houses;
 public:
    Street();
    ~Street();
    const int GetNumberOfHouses() const;
    const std::string GetNameStreet() const;
    void SetNameStreet(const std::string & NameStreet);
    void SetLenStreet(const int & NumberOfHouses);
    void SetHouses(const int *Value, const int & Number);
    void AddHouse(const int & n, const int & p);
    void DeleteHouse(const int n);
    const int GetHouseData(const int n);
    const int GetNumberOfHouses();
    House& Get(const int & n);
    void Print();
    Street &operator=(const Street &src);
    bool operator==(const Street &src) const;
};
