// reservation.h
#ifndef RESERVATION_H
#define RESERVATION_H

#include "Reservation.h"
#include <string>
#include <vector>
#include "DBConnection.h"

class Reservation {
public:
    int reservationId;
    std::string roomType, catName, reserve_date, duration;

    Reservation();
    Reservation(int reservationId, std::string roomType, std::string catName, std::string reserve_date, std::string duration);
    Reservation(sql::ResultSet* data);

    ~Reservation();
    std::vector<std::pair<Reservation, int >> HotelRoom;

    void insertReservation();
    void removeReservation();
    bool isDateReserved(const std::string& date, const std::string& roomType);
    double calculateAmount(); // Add method to calculate amount
    static void viewReservations(); // Method to view reservations

private:
    static void displayResult(sql::ResultSet* res); // Helper function to display results



};
#endif