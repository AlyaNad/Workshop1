#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>

class Payment {
public:
    int paymentId;
    int reservationId;
    double amount;

    Payment();
    Payment(int paymentId, int reservationId, double amount);
    ~Payment();

    void processPayment();
};

#endif
