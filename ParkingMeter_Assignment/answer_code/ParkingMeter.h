// ParkingMeter.h
// Header file for ParkingMeter class
// Contains class interface (declaration)

#ifndef PARKINGMETER_H
#define PARKINGMETER_H

#include <string>

class ParkingMeter {
private:
    std::string meterID_;
    double ratePerHour_;
    int timeRemaining_;
    double totalCollected_;
    bool isActive_;

public:
    // Constructor
    ParkingMeter(const std::string& meterID, double ratePerHour);

    // Getters (accessors)
    std::string getMeterID() const;
    double getRatePerHour() const;
    int getTimeRemaining() const;
    double getTotalCollected() const;
    bool isActive() const;

    // Behaviors (mutators)
    bool insertCoin(double amount);
    bool addTime(int minutes);
    void expire();
    bool postPayment(double amount);
};

#endif
