#include "Payment.h"
#include "DBConnection.h"
#include <iostream>

Payment::Payment() : paymentId(0), reservationId(0), amount(0.0) {}

Payment::Payment(int paymentId, int reservationId, double amount)
    : paymentId(paymentId), reservationId(reservationId), amount(amount) {}

Payment::~Payment() {}

void Payment::processPayment() {
    DBConnection db;
    db.prepareStatement("INSERT INTO payment (reservationId, amount) VALUES (?, ?)");
    db.stmt->setInt(1, reservationId);
    db.stmt->setDouble(2, amount);
    db.QueryStatement();
    std::cout << "Payment processed successfully.\n";
}
