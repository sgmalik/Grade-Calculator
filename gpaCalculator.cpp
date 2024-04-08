//
// Created by Surya Malik on 2/21/24.
//

#include "gpaCalculator.h"
using namespace std;

// Default constructor
gpaCalculator::gpaCalculator() : fNumCourses(0) {}

gpaCalculator::gpaCalculator(int numCourses){
    this->fNumCourses = numCourses;
}

// Setters
void gpaCalculator::setNumCourses(int numCourses){
    fNumCourses = numCourses;
}


// Getters
int gpaCalculator::getNumCourses(){
    return fNumCourses;
}


// GPA function that takes a variable number of letter grades
float gpaCalculator::calculateGPA(vector<pair<double,int>> classGrades){
    int totalCredits = 0;
    double sum = 0;
    for (auto classGrade : classGrades){
        if (100 >= classGrade.first && classGrade.first >= 93){
            sum += (4.0 * classGrade.second);
            totalCredits += classGrade.second;
        } else if (93 > classGrade.first && classGrade.first >= 90){
            sum += (3.67 * classGrade.second);
            totalCredits += classGrade.second;
        } else if (90 > classGrade.first && classGrade.first >= 87){
            sum += (3.33 * classGrade.second);
            totalCredits += classGrade.second;
        } else if (87 > classGrade.first && classGrade.first >= 83){
            sum += (3.0 * classGrade.second);
            totalCredits += classGrade.second;
        } else if (83 > classGrade.first && classGrade.first >= 80){
            sum += (2.67 * classGrade.second);
            totalCredits += classGrade.second;
        } else if (80 > classGrade.first && classGrade.first >= 77){
            sum += (2.33 * classGrade.second);
            totalCredits += classGrade.second;
        } else if (77 > classGrade.first && classGrade.first >= 73){
            sum += (2.0 * classGrade.second);
            totalCredits += classGrade.second;
        } else if (73 > classGrade.first && classGrade.first >= 70){
            sum += (1.67 * classGrade.second);
            totalCredits += classGrade.second;
        } else if (70 > classGrade.first && classGrade.first >= 67){
            sum += (1.33 * classGrade.second);
            totalCredits += classGrade.second;
        } else if (67 > classGrade.first && classGrade.first >= 63){
            sum += (1.0 * classGrade.second);
            totalCredits += classGrade.second;
        } else if (63 > classGrade.first && classGrade.first >= 60){
            sum += (0.67 * classGrade.second);
            totalCredits += classGrade.second;
        } else if (60 > classGrade.first){
            totalCredits += classGrade.second;
        } else {
            //User has entered an invalid grade
            return -1;
        }
    }
    return sum / totalCredits;
}