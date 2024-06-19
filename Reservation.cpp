#include "Reservation.h"
#include <iostream>
#include <iomanip>

Reservation::Reservation()
{
	reservationId = 0;
	roomType = "";
	catName = "";
	reserve_date = "";
	duration = "";

}

Reservation::Reservation(int reservationId, std::string roomType, std::string catName, std::string reserve_date, std::string duration)
{
	this->reservationId = reservationId;
	this->roomType = roomType;
	this->catName = catName;
	this->reserve_date = reserve_date;
	this->duration = duration;
}

Reservation::Reservation(sql::ResultSet * data)
	{
		DBConnection db;
		db.prepareStatement("SELECT * FROM resesrvation");
		reservationId = data->getInt("reservationId");
		roomType = data->getString("roomType");
		catName = data->getString("catName");
		reserve_date = data->getString("reserve_date");
		duration = data->getString("duration");
	}

	Reservation::~Reservation()
	{
	}

	void Reservation::insertReservation()  
	{
		DBConnection db;
		db.prepareStatement("INSERT into resesrvation (roomType, catName, reserve_date, duration) VALUES (?,?,?,?)");
		db.stmt->setString(1, roomType);
		db.stmt->setString(2, catName);
		db.stmt->setString(3, reserve_date);
		db.stmt->setString(4, duration);
		db.QueryStatement();
		db.~DBConnection();

	}

	void Reservation::removeReservation()
	{
		DBConnection db;
		db.prepareStatement("DELETE FROM resesrvation WHERE resesrvationId=?");
		db.stmt->setInt(1, reservationId);
		db.QueryStatement();
		db.~DBConnection();
	}

	bool Reservation::isDateReserved(const std::string& date, const std::string& roomType)
	{
		DBConnection db;
		db.prepareStatement("SELECT COUNT(*) FROM resesrvation WHERE reserve_date = ? AND roomType = ?");
		db.stmt->setString(1, date);
		db.stmt->setString(2, roomType);
		std::unique_ptr<sql::ResultSet> res(db.stmt->executeQuery());
		if (res->next()) {
			int count = res->getInt(1);
			return count > 0;
		}
		return false;
	}

	double Reservation::calculateAmount() {
		double rate = 0.0;
		if (roomType == "Standard Room") {
			rate = 30.0;
		}
		else if (roomType == "Deluxe Room") {
			rate = 40.0;
		}
		return rate * std::stoi(duration);
	}

	void Reservation::viewReservations() {
		DBConnection db;
		db.prepareStatement("SELECT * FROM resesrvation");
		db.QueryResult();
		displayResult(db.res);
	}

	void Reservation::displayResult(sql::ResultSet* res) {
		try {
			std::cout << std::left << std::setw(12) << "Res ID"
				<< std::setw(12) << "Room Type"
				<< std::setw(12) << "Cat Name"
				<< std::setw(15) << "Reserve Date"
				<< std::setw(10) << "Duration" << "\n";
			std::cout << "-------------------------------------------------------------\n";

			while (res->next()) {
				std::cout << std::left << std::setw(12) << res->getInt("reservationId")
					<< std::setw(12) << res->getString("roomType")
					<< std::setw(12) << res->getString("catName")
					<< std::setw(15) << res->getString("reserve_date")
					<< std::setw(10) << res->getString("duration") << "\n";
			}
		}
		catch (sql::SQLException& e) {
			std::cerr << "SQLException: " << e.what() << std::endl;
		}
	}