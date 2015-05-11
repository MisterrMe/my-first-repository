// Copyright 2015 <Mikhail Shturov>
#pragma once

class House{
 private:
    int HomeNumber;
    int NumberOfPeople;
 public:
    House();
    ~House();
    House(const House &src);
    const int getHomeNumber() const;
    void setHomeNumber(int a);
    const int getNumberOfPeople() const;
    void setNumberOfPeople(int a);
    House &operator=(const House &src);
    bool operator==(const House &src) const;
};
