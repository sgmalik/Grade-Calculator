//
// Created by Surya Malik on 2/11/24.
//

#ifndef M3OEP_SGMALIK_CATEGORY_H
#define M3OEP_SGMALIK_CATEGORY_H
#include <vector>
using namespace std;


class category {
private:

    // fields
    int fNumAssignments;
    int fNumDropped;
    float fWeight;
    float fTotalPoints;
    vector<float> fAssignments; // vector for assignments in each category

public:

    // Default constructor
    category();

    // Constructor
    category(int NumAssignment, int NumDropped, float Weight, float TotalPoints);

    /*
     * setNumAssignments: sets the number of assignments in the category
     * @param: int pVal is the value that will be set to fNumAssignments
     */
    void setNumAssignments(int pVal);

    /*
     * setNumDropped: sets the number of assignments dropped in the category
     * @param: int pVal is the value that will be set to fNumDropped
     */
    void setNumDropped(int pVal);

    /*
     * setWeight: sets the weight of the category
     * @param: float pVal is the value that will be set to fWeight
     */
    void setWeight (float pVal);

    /*
     * setTotalPoints: sets the total amount of points for the category
     * @param: float pVal is the value that will be set to fTotalPoints
     */
    void setTotalPoints (float pVal);

    /*
     * getNumAssignments: gets the number of assignments in the category
     * @return: returns fNumAssignments
     */
    int getNumAssignments();

    /*
     * getNumAssignments: gets the number of assignments dropped in the category
     * @return: returns fNumDropped
     */
    int getNumDropped();

    /*
     * getNumAssignments: gets the weight of the category
     * @return: returns fWeight
     */
    float getWeight();

    /*
     * getNumAssignments: gets the total points in the category
     * @return: returns fTotalPoints
     */
    float getTotalPoints();

    /*
     * addAssignment: adds a user inputted assignment to the vector of assignments and increments the total points
     * @param: float pScore is the score of the assignment to be added
     */
    void addAssignment(float pScore);

    /*
     * dropLowestGrade: drops the lowest grade in the category by saving the first index in the assignment vector as
     * the lowest value and looping through the vector, comparing this value to the others, overwriting it if the
     * comparable value is less than the current lowest value.
     */
    void dropLowestGrade();

    /*
     * getCategoryAverage: gets the category average dividing the total points by the number of assignments
     * @return: returns the average of the category in the form of a float
     */
    float getCategoryAverage();

    /*
     * getWeightedAverage: gets the category average based on the weight of the category by multiplication, so if a
     * category is worth 25% of a course's grade, then the values possible for this function are 0 - 25.
     * @param: float pAverage is the unweighted average of the category and float pWeight is the weight of the category
     * @return: returns the weighted average of the course
     */
    float getWeightedAverage(float pAverage, float pWeight);
};


#endif //M1OEP_SGMALIK_CATEGORY_H
