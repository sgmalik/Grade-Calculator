//
// Created by Surya Malik on 2/21/24.
//

#ifndef M3OEP_SGMALIK_GPACALCULATOR_H
#define M3OEP_SGMALIK_GPACALCULATOR_H
#include <vector>
#include <string>
#include <utility>
#include "course.h"
using namespace std;

class gpaCalculator {
private:
    vector<course> fCourses;
    int fNumCourses;

    // Add Letter Grade Conversion to course class
    // Add credit category to course class
public:

    // Default constructor
    gpaCalculator();

    gpaCalculator(int numCourses);

    // Setters
    void setNumCourses(int numCourses);


    // Getters
    int getNumCourses();


    // GPA function that takes a variable number of letter grades
    static float calculateGPA(vector<pair<double, int> > classGrades);

};


#endif //M2OEP_SGMALIK_GPACALCULATOR_H
