//
// Created by Surya Malik on 2/11/24.
//

#include "course.h"

course::course() : fCatNumber(0) {}

course::course(int pCategories) : fCatNumber(pCategories) {
    fCategories.resize(fCatNumber);
}

category& course::getCategory(int index) {
    return fCategories[index];
}

int course::getCatNumber() {
    return fCatNumber;
}

void course::setCatNumber(int catNumber) {
    this->fCatNumber = catNumber;
    fCategories.resize(fCatNumber);
}
