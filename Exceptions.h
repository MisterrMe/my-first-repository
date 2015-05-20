// Copyright 2015 <Mikhail Shturov>
#pragma once
#include <iostream>
#include <string>

class InvalidInputData : public std::exception{
 private:
     std::string str;
 public:
     InvalidInputData();
     const char *what() const throw();
};

class NoSuchHome : public std::exception{
 private:
    std::string str;
 public:
    NoSuchHome();
    const char *what() const throw();
};
