//
// Created by Surya Malik on 2/11/24.
//

#include "category.h"

category::category() : fTotalPoints(0), fNumAssignments(0), fNumDropped(0), fWeight(0){}

category::category(int numAssignment, int numDropped, float weight, float totalPoints){
    fNumAssignments = numAssignment;
    fNumDropped = numDropped;
    fWeight = weight;
    fTotalPoints = totalPoints;

}

void category::setNumAssignments(int pVal) {
    this->fNumAssignments = pVal;
}

void category::setNumDropped(int pVal) {
    this->fNumDropped = pVal;
}

void category::setWeight (float pVal) {
    this->fWeight = pVal;
}

void category::setTotalPoints(float pVal) {
    this->fTotalPoints = pVal;
}

int category::getNumAssignments() {
    return fNumAssignments;
}

int category::getNumDropped() {
    return fNumDropped;
}

float category::getWeight() {
    return fWeight;
}

float category::getTotalPoints() {
    return fTotalPoints;
}

void category::addAssignment(float pScore) {
    fAssignments.push_back(pScore);
    fTotalPoints += pScore;
}

void category::dropLowestGrade() {
    float lowestValue = fAssignments[0];
    auto lowestIndex = fAssignments.begin();
    for (int i = 0; i < fAssignments.size(); i++) {
        if (lowestValue > fAssignments[i]) {
            lowestValue = fAssignments[i];
            lowestIndex + i;
        }
    }
    fAssignments.erase(lowestIndex);
    fTotalPoints -= lowestValue;
    fNumAssignments--;
}

float category::getCategoryAverage() {
    float ratio = fTotalPoints / fNumAssignments;
    return ratio;
}

float category::getWeightedAverage(float pAverage, float pWeight) {
    float ratio = pAverage * pWeight;
    return ratio;
}