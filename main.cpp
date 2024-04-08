//
// Created by Surya Malik on 2/11/24.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <utility>
#include <fstream>
#include "course.h"
#include "gpaCalculator.h"

using namespace std;

/*
 * get_int_from_user: From applied project, handles validation when getting number of categories, assignments,
 * and assignments dropped
 * @return: integer from user
 */

static int get_int_from_user();

/*
 * get_int_0_from_user: From applied project, handles validation when getting number of assignments dropped
 * @return: integer from user greater than 0
 */
static int get_int_0_from_user();

/*
 * get_float_from_user: From applied project, handles validation when getting assignment scores
 * @return: double from user
 */
double get_float_from_user();


double calculate_final_grade();



int main() {

    vector<pair<double, int>> courses;
    bool status = false;
    int totalCredits = 0;
    cout << "Welcome to the GPA Calculator!" << endl;
    cout << "Are there any courses you need to calculate the final grades of? (y/n): ";
    while (!status) {
        string choice;
        getline(cin, choice);
        if (choice == "y" || choice == "Y") {
            cout << "How many final grades would you like to calculate? ";
            int numCourses = get_int_from_user();
            for (int i = 0; i < numCourses; i++) {
                //Get number of credits for this course
                int courseCredit = 0; // declare course credit variable
                do { // input validation to ensure that the credits are a valid number
                    cout << "How many credits does course " << i + 1 << " have? ";
                    courseCredit = get_int_from_user(); // input validation
                    if (courseCredit > 19) {
                        cout << "Error, credit hours can not be more than 19. "; // makes sure credit hours are not above 19
                    } else if ((totalCredits + courseCredit) > 19) { // makes sure adding these credits will not exceed the maximum of 19
                        cout << "Error, credit hours cannot exceed the total of 19 without Dean approval. ";
                    } // conditions check, repeats if credit hours is greater than 19 or if the total credit hours exceeds the available credit hours remaining
                } while ((courseCredit > 19) || ((19 - totalCredits) < courseCredit));
                totalCredits += courseCredit; // increments totalCredits to represent a students overall credits
                double finalGrade = calculate_final_grade();
                //Push course to vector
                courses.push_back({finalGrade, courseCredit});
            }
            status = true;
        } else if (choice == "n" || choice == "N") {
            // break
            status = true;
        } else {
            cout << "Invalid input. Please choose (y)es or (n)o: ";
        }
    }

    // Add courses that you know final grades of, validate and push back, call method, file output
    cout << "Are there any courses you know the grade of? (y/n): ";
    while (status) {
        string response;
        getline(cin, response);
        if (response == "y" || response == "Y") {
            cout << "How many courses would you like to add? ";
            int additionalCourses = get_int_from_user();
            for (int i = 0; i < additionalCourses; i++) {
                int courseCredit = 0;
                do { // input validation to ensure that the credits are a valid number
                    cout << "How many credits does course " << i + 1 << " have? ";
                    courseCredit = get_int_from_user(); // input validation
                    if (courseCredit > 19) {
                        cout << "Error, credit hours can not be more than 19. "; // makes sure credit hours are not above 19
                    } else if ((totalCredits + courseCredit) > 19) { // makes sure adding these credits will not exceed the maximum of 19
                        cout << "Error, credit hours cannot exceed the total of 19 without Dean approval. ";
                    } // conditions check, repeats if credit hours is greater than 19 or if the total credit hours exceeds the available credit hours remaining
                } while ((courseCredit > 19) || ((19 - totalCredits) < courseCredit));
                totalCredits += courseCredit; // increments totalCredits to represent a students overall credits
                double finalGrade = 0.0;
                do { // input validation to ensure that final grade is a valid number
                    cout << "What was your final grade (percent)? ";
                    finalGrade = get_float_from_user(); // input validation
                    if (finalGrade > 100.0) {
                        cout << "Error, grade can not exceed 100%."; // makes sure grade is less than or equal to 100
                    } else if (finalGrade < 0) {
                        cout << "Error, grade can not be less than 100%."; // makes sure grade is greater than 100
                    }
                    // conditions check, repeats if finalGrade exceeds 100 or is less than 100
                } while ((finalGrade > 100) || (finalGrade < 0));
                // push to vector
                courses.push_back({finalGrade, courseCredit});
            }
            status = false;
        } else if (response == "n" || response == "N") {
            status = false;
        } else {
            cout << "Invalid input. Please choose (y)es or (n)o: ";
        }
    }
    gpaCalculator g;
    float GPA = g.calculateGPA(courses);
    if (courses.size() == 0) {
        cout << "GPA N/A" << endl;
    } else {
        cout << "Your final GPA is: " << GPA << endl;
    }

    ofstream outFile;
    outFile.open("gpaSummary.txt");
    for (auto course: courses){
        outFile << "You received a " << course.first << " in a course worth " << course.second << " credits. ";
        if (course.first > 80){
            outFile << "Nice!" << endl;
        } else if (course.first < 60){
            outFile << "Ouch!" << endl;
        } else{
            outFile << "Solid!" << endl;
        }
    }
    outFile << "Your GPA for this semester was a " << GPA << "." << endl;
    if (GPA > 3.5){
        outFile << "Great job this semester!" << endl;
    } else if (GPA < 2.0) {
        outFile << "It looks like you had a rough semester!" << endl;
    } else {
        outFile << "Not too bad!" << endl;
    }

    outFile.close();


    return 0;
}

int get_int_from_user() {
    string response;
    int value;
    bool loopControl = true;
    while (loopControl) {
        cout << "Enter a number 1 or greater: ";
        stringstream ss;
        ss.clear();
        ss.str("");
        response.clear();
        getline(cin, response);
        ss << response;
        if (response.length() == 0) {
            cout << "No input. ";
        }
        else if (!(ss >> value) || !ss.eof()) { // while response does not start with valid int and ss not at end of file
            cout << "Invalid input. ";
        }
        else if (value < 1) {
            cout << "Invalid value. ";
        }
        else { // accept case, exits control loop
            loopControl = false;
        }
    }
    return value;
}

int get_int_0_from_user() {
    string response;
    int value;
    bool loopControl = true;
    while (loopControl) {
        cout << "Enter a number: ";
        stringstream ss;
        ss.clear();
        ss.str("");
        response.clear();
        getline(cin, response);
        ss << response;
        if (response.length() == 0) {
            cout << "No input. ";
        }
        else if (!(ss >> value) || !ss.eof()) { // while response does not start with valid int and ss not at end of file
            cout << "Invalid input. ";
        }
        else { // accept case, exits control loop
            loopControl = false;
        }
    }
    return value;
}

double get_float_from_user() {
    // NOTE: a float does not need to have a decimal part (meaning an integer is a valid float)
    string response;
    float value = 0;
    bool loopControl = true;
    while (loopControl) {
        cout << "Enter a decimal: ";
        stringstream ss;
        ss.clear();
        ss.str("");
        response.clear();
        getline(cin, response);
        ss << response;
        if (response.length() == 0) {
            cout << "No input. ";
        }
        else if (!(ss >> value) || !ss.eof()) { // same as int
            cout << "Invalid input. ";
        }
        else if (value < 0) {
            cout << "Invalid value. ";
        }
        else {
            loopControl = false;
        }
    }
    return value;
}

double calculate_final_grade(){
    cout << "How many categories does your class have? ";
    int categories = get_int_from_user();
    course sample(categories); // Create course object
    float totalWeightedAverage = 0; // Variable to track the total weighted average in the course
    float totalWeight = 0; // variable to track the total weight of a class
    for (int i = 0; i < sample.getCatNumber(); i++) { // loops based on how many categories in a given class
        float catWeight; // declare category weight variable
        do { // input validation to ensure that the weight is a valid number
            cout << "What is the Weight of Category " << i + 1 << "? ";
            catWeight = get_float_from_user(); // input validation
            if (catWeight > 1.0) {
                cout << "Error, category weight cannot be more than 1.0. "; // makes sure individual weight is not greater than 1 (accepts decimal weights)
            }
            else if ((totalWeight + catWeight) > 1.0) { // makes sure this weight will not exceed the maximum weight of 1 (100% = 1)
                cout << "Error, category weight cannot exceed the total weight of 1.0. ";
            } // conditions check, repeats if individual weight is greater than 1 or if the weight exceeds the available weight remaining
        } while ((catWeight > 1.0) || ((1 - totalWeight) < catWeight));
        totalWeight += catWeight; // increments totalWeight to represent the classes overall weight
        sample.getCategory(i).setWeight(catWeight); // set weight of category in course
        cout << "How many Assignments in Category " << i + 1 << "? ";
        int assignments = get_int_from_user(); // input validation
        sample.getCategory(i).setNumAssignments(assignments); // set numAssignments per category in course
        for (int count = 0; count < sample.getCategory(i).getNumAssignments(); count++) { // loops based on how many assignmenrts in category
            float score;
            do { // input validation to make sure score is a valid number
                cout << "Add assignment score. ";
                score = get_float_from_user(); // input validation
                if (score < 0) {
                    cout << "Error, assignment score must be greater than or equal to 0. ";
                } // makes sure score is abpve 0, negative scores not feasible
            } while (score < 0);
            sample.getCategory(i).addAssignment(score); // adds score to assignment vector using method
        }
        int dropped;
        do { // input validation to make sure number of assignments dropped is valid
            cout << "How many assignments dropped? ";
            dropped = get_int_0_from_user(); // input validation
            if (dropped > sample.getCategory(i).getNumAssignments()) {
                cout << "Error, number of assignments dropped greater than total amount of assignments. ";
            } // ensures the number of assignments dropped is not greater than the number of assignments total
        } while (dropped > sample.getCategory(i).getNumAssignments());

        sample.getCategory(i).setNumDropped(dropped);
        for (int count2 = 0; count2 < sample.getCategory(i).getNumDropped(); count2++) { // loops based on number of dropped assignments
            sample.getCategory(i).dropLowestGrade(); // drops lowest grade(s)
        }
        float average = sample.getCategory(i).getCategoryAverage(); // average of each category
        cout << "Category " << i + 1 << " average is: " << fixed << setprecision(2) << average << endl; // decimal manipulation
        float weightedAverage = sample.getCategory(i).getWeightedAverage(average, sample.getCategory(i).getWeight());
        // shows amount earned in relation tp weight (ex. if a class is 25% of the grade, number will be 0 - 25)
        cout << "Category " << i + 1 << " weighted average is: " << fixed << setprecision(2) << weightedAverage << endl;
        // decimal manipulation
        totalWeightedAverage += weightedAverage;
    }

    return totalWeightedAverage;
    // decimal manipulation

};