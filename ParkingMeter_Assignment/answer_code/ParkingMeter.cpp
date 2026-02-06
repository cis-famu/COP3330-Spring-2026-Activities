// ParkingMeter.cpp
// Implementation file for ParkingMeter class

#include "ParkingMeter.h"
#include <cmath>

// Constructor
ParkingMeter::ParkingMeter(const std::string& meterID, double ratePerHour)
    : meterID_{meterID},
      ratePerHour_{ratePerHour},
      timeRemaining_{0},
      totalCollected_{0.0},
      isActive_{true} {}

// Getters
std::string ParkingMeter::getMeterID() const {
    return meterID_;
}

double ParkingMeter::getRatePerHour() const {
    return ratePerHour_;
}

int ParkingMeter::getTimeRemaining() const {
    return timeRemaining_;
}

double ParkingMeter::getTotalCollected() const {
    return totalCollected_;
}

bool ParkingMeter::isActive() const {
    return isActive_;
}

// Behaviors

bool ParkingMeter::insertCoin(double amount) {
    // Validate coin denomination
    // Valid U.S. coins: nickel (0.05), dime (0.10), quarter (0.25), dollar (1.00)
    const double EPSILON = 0.001;
    bool isValidCoin = (std::fabs(amount - 0.05) < EPSILON) ||
                       (std::fabs(amount - 0.10) < EPSILON) ||
                       (std::fabs(amount - 0.25) < EPSILON) ||
                       (std::fabs(amount - 1.00) < EPSILON);
    
    if (!isValidCoin) {
        return false;
    }
    
    // Add to total collected
    totalCollected_ += amount;
    
    // Calculate minutes: (amount / ratePerHour) * 60
    // Use integer division to round down
    int minutesToAdd = static_cast<int>((amount / ratePerHour_) * 60.0);
    timeRemaining_ += minutesToAdd;
    
    // Reactivate meter if it was expired
    if (!isActive_) {
        isActive_ = true;
    }
    
    return true;
}

bool ParkingMeter::addTime(int minutes) {
    // Can only add time if meter is active
    if (!isActive_) {
        return false;
    }
    
    // Validate minutes
    if (minutes <= 0) {
        return false;
    }
    
    timeRemaining_ += minutes;
    return true;
}

void ParkingMeter::expire() {
    timeRemaining_ = 0;
    isActive_ = false;
}

bool ParkingMeter::postPayment(double amount) {
    // Validate amount is positive
    if (amount <= 0.0) {
        return false;
    }
    
    // Minimum payment must be at least one hour's rate
    if (amount < ratePerHour_) {
        return false;
    }
    
    // Add to total collected
    totalCollected_ += amount;
    
    // Calculate time: (amount / ratePerHour) * 60
    int minutes = static_cast<int>((amount / ratePerHour_) * 60.0);
    timeRemaining_ = minutes;  // Replace time, don't add
    
    // Reactivate meter
    isActive_ = true;
    
    return true;
}
