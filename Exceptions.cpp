// Copyright 2015 <Mikhail Shturov>

#include "./Exceptions.h"
#include <string>

InvalidInputData::InvalidInputData() {
    str = "Invalid input data. The program returns to the menu..\n";
}

const char* InvalidInputData::what() const throw() {
    return str.c_str();
}

NoSuchHome::NoSuchHome() {
    str = "There is no such home. The program returns to the menu..\n";
}

const char* NoSuchHome::what() const throw() {
    return str.c_str();
}
