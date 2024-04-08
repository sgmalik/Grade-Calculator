//
// Created by Surya Malik on 2/11/24.
//

#ifndef M3OEP_SGMALIK_CLASS_H
#define M3OEP_SGMALIK_CLASS_H
#include <vector>
#include "category.h"
using namespace std;

class course {
private:
    // fields
    int fCatNumber;
    vector<category> fCategories; // vector to hold categories in a class
public:

    course();

    /*
     * course: default constructor
     * @param: int pCategories is the amount of categories in the course used to resize vector fCategories
     */
    explicit course(int pCategories);

    /*
     * getCategory: Member function to get a reference to a category
     * @param: int index is the index desired to be retrieved
     * @return: reference to a category object
     */
    category& getCategory(int index);

    /*
     * getCatNumber: function to get how many categories in the course
     * @return: integer for the number of categories (fCatNumber)
     */
    int getCatNumber();

    /*
     * setCatNumber: function to set the number of categories
     * @param int catNumber is the number of categories
     */
    void setCatNumber(int catNumber);

};


#endif //M1OEP_SGMALIK_CLASS_H
