// main.cpp
// Driver program to demonstrate ParkingMeter class functionality

#include <iostream>
#include <iomanip>
#include "ParkingMeter.h"

void printMeterStatus(const ParkingMeter& meter) {
    std::cout << "====================================\n";
    std::cout << "Meter ID: " << meter.getMeterID() << "\n";
    std::cout << "Rate: $" << std::fixed << std::setprecision(2) 
              << meter.getRatePerHour() << "/hour\n";
    std::cout << "Time Remaining: " << meter.getTimeRemaining() << " minutes\n";
    std::cout << "Total Collected: $" << meter.getTotalCollected() << "\n";
    std::cout << "Status: " << (meter.isActive() ? "ACTIVE" : "EXPIRED") << "\n";
    std::cout << "====================================\n\n";
}

int main() {
    std::cout << "=== Parking Meter Simulation ===\n\n";
    
    // Create two meters with different rates
    ParkingMeter downtown("DOWNTOWN-12", 4.00);  // Expensive downtown parking
    ParkingMeter suburban("SUBURB-45", 2.00);    // Cheaper suburban parking
    
    std::cout << "Initial State:\n";
    printMeterStatus(downtown);
    printMeterStatus(suburban);
    
    // Scenario 1: Downtown meter usage
    std::cout << "--- Scenario 1: Downtown Meter ---\n";
    std::cout << "Customer inserts $1.00 coin...\n";
    if (downtown.insertCoin(1.00)) {
        std::cout << "✓ Coin accepted!\n";
    }
    printMeterStatus(downtown);
    
    std::cout << "Customer adds 15 more minutes manually...\n";
    if (downtown.addTime(15)) {
        std::cout << "✓ Time added!\n";
    }
    printMeterStatus(downtown);
    
    std::cout << "Attempting to insert invalid coin (penny = $0.01)...\n";
    if (!downtown.insertCoin(0.01)) {
        std::cout << "✗ Coin rejected (invalid denomination)\n";
    }
    printMeterStatus(downtown);
    
    // Scenario 2: Meter expiration and reactivation
    std::cout << "\n--- Scenario 2: Suburban Meter Expiration ---\n";
    std::cout << "Adding some initial time with quarters...\n";
    suburban.insertCoin(0.25);
    suburban.insertCoin(0.25);
    printMeterStatus(suburban);
    
    std::cout << "Time runs out... meter expires!\n";
    suburban.expire();
    printMeterStatus(suburban);
    
    std::cout << "Attempting to add time to expired meter...\n";
    if (!suburban.addTime(10)) {
        std::cout << "✗ Cannot add time - meter is expired!\n";
    }
    
    std::cout << "\nCustomer returns and makes post-payment of $2.00...\n";
    if (suburban.postPayment(2.00)) {
        std::cout << "✓ Payment accepted - meter reactivated!\n";
    }
    printMeterStatus(suburban);
    
    std::cout << "Attempting insufficient post-payment of $1.00...\n";
    suburban.expire();  // Expire it again
    if (!suburban.postPayment(1.00)) {
        std::cout << "✗ Payment rejected - must pay at least the hourly rate!\n";
    }
    printMeterStatus(suburban);
    
    // Final summary
    std::cout << "\n=== Final Status ===\n";
    std::cout << "Downtown meter collected: $" << std::fixed << std::setprecision(2)
              << downtown.getTotalCollected() << "\n";
    std::cout << "Suburban meter collected: $" << suburban.getTotalCollected() << "\n";
    std::cout << "Total revenue: $" 
              << (downtown.getTotalCollected() + suburban.getTotalCollected()) << "\n";
    
    return 0;
}
