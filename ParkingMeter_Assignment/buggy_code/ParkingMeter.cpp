// ParkingMeter.cpp (INTENTIONALLY BUGGY VERSION)
// This version contains common student mistakes and will fail several tests

#include "ParkingMeter.h"
#include <cmath>

// BUG #1: Constructor starts meter as inactive
ParkingMeter::ParkingMeter(const std::string& meterID, double ratePerHour)
    : meterID_{meterID},
      ratePerHour_{ratePerHour},
      timeRemaining_{0},
      totalCollected_{0.0},
      isActive_{false} {}  // WRONG: should be true

// Getters (these are correct)
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

// Behaviors (with bugs)

bool ParkingMeter::insertCoin(double amount) {
    // BUG #2: Accepts any positive amount, doesn't validate denominations
    if (amount <= 0.0) {
        return false;
    }
    
    totalCollected_ += amount;
    
    // BUG #3: Incorrect time calculation - uses floating point instead of truncating
    double minutesToAdd = (amount / ratePerHour_) * 60.0;
    timeRemaining_ += static_cast<int>(minutesToAdd + 0.5);  // WRONG: rounds up instead of down
    
    isActive_ = true;
    return true;
}

bool ParkingMeter::addTime(int minutes) {
    // BUG #4: Doesn't check if meter is active
    if (minutes <= 0) {
        return false;
    }
    
    timeRemaining_ += minutes;
    return true;  // WRONG: should return false if not active
}

void ParkingMeter::expire() {
    // BUG #5: Doesn't set time to 0
    isActive_ = false;
    // WRONG: timeRemaining_ not reset
}

bool ParkingMeter::postPayment(double amount) {
    // BUG #6: Doesn't validate minimum payment amount
    if (amount <= 0.0) {
        return false;
    }
    // WRONG: should check amount >= ratePerHour_
    
    totalCollected_ += amount;
    
    // BUG #7: Adds time instead of replacing it
    int minutes = static_cast<int>((amount / ratePerHour_) * 60.0);
    timeRemaining_ += minutes;  // WRONG: should use = not +=
    
    isActive_ = true;
    return true;
}
