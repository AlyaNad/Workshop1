#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <conio.h>
// advanced
// include our custom class
#include "Admin.h"
#include "Staff.h"
#include "Customer.h"
#include "Account.h" 
#include "Menu.h"
#include "Cat.h"
#include "Hotelroom.h"
#include "Inventory.h"
#include "Reservation.h"
#include "Payment.h"
using namespace std;

void inv(Admin user);
void homepage(Staff user); 
void home(Customer user);
void hoteldetails();
void registerStaff();
void registerCust();
void loginAdmin();
void loginStaff();
void loginCust();
void inventory(Admin user);
void addProduct(Admin user);
char ch;
void displayRoomInfo(int roomType);
void book(Customer user);
int listStaff();
Staff removeStaff(Staff user); 
Cat booking(Customer customer, Cat cat);
void reservation(Customer user, Cat cat, Reservation reserve, Hotelroom room, Payment pay);
void payment(Customer user, Cat cat, Reservation reserve, Hotelroom room, Payment pay);
void logout();

Account profile(Account user);

int main() {

	Menu mainmenu;
	mainmenu.header = "\t------------------------------------------------------\n\t-       Welcome to Cat Hotel Management System       -\n\t------------------------------------------------------"; 
	mainmenu.addOption("\tLogin Admin");
	mainmenu.addOption("\tLogin Staff");
	mainmenu.addOption("\tLogin Customer");
	mainmenu.addOption("\tRegister Staff");
	mainmenu.addOption("\tRegister Customer");
	mainmenu.addOption("\tExit");

	while (1) {
		switch (mainmenu.prompt())
		{
		case 1:
			loginAdmin();
			break;
		case 2:
			loginStaff();
			break;
		case 3:
			loginCust();
			break;
		case 4:
			registerStaff(); 
			break;
		case 5:
			registerCust(); 
			break;
		case 6:
			return 0;
		default:
			break;
		}
	}
}
void loginAdmin() {
	Menu loginMenu;
	loginMenu.header = "\t-----------------------------------------\n\t-\t      LOGIN ADMIN      \t-\n\t-----------------------------------------";
	loginMenu.addOption("username");
	loginMenu.addOption("password");
	loginMenu.addOption("Login");
	loginMenu.addOption("Back");

	Admin user;

	while (1) {
		switch (loginMenu.prompt())
		{
		case 1:
			std :: cout << "Insert Username:";
			std:: cin >> user.username;
			loginMenu.setValue(0, user.username);
			break;
		case 2:
			std:: cout << "Insert Password: ";
			user.password = Admin::getMaskedInput(""); 
			loginMenu.setValue(1, std::string(user.password.length(), '*'));
			break;
		case 3:
			if (user.login()) {
				inv(user);   
			}
			else {
				std::cout << "Invalid Login";
				_getch();
			}
			break;
		case 4:
			return;
			break;
		default:
			break;
		}
	}
}
void registerStaff() {
	Staff newstaff; 

	Menu rgMenu;
	rgMenu.header = "\t-----------------------------------------\n\t-\t    STAFF REGISTRATION      \t-\n\t-----------------------------------------";
	rgMenu.addOption("Email");
	rgMenu.addOption("Phone Number");
	rgMenu.addOption("Create Username");
	rgMenu.addOption("Create Password");
	rgMenu.addOption("Register");
	rgMenu.addOption("Back");


	string tmpinput;
	bool valid = true;
	while (1) {

		switch (rgMenu.prompt()) {
		case 1:
			std::cout << "Insert Email:";
			std::cin >> newstaff.email;
			rgMenu.setValue(0, newstaff.email);
			break;
		case 2:
			std::cout << "Insert Phone Number:";
			std::cin >> newstaff.phoneNo;
			rgMenu.setValue(1, newstaff.phoneNo);
			break;
		case 3:
			std::cout << "Insert Username:";
			std::cin >> newstaff.username;
			rgMenu.setValue(2, newstaff.username);
			break; 
		case 4:
			std::cout << "Insert password:";
			std::cin >> tmpinput;
			if (tmpinput.length() < 7) {
				std::cout << "Password must be at least 7 character long";
				_getch();
			}
			else {
				newstaff.password = tmpinput;
				rgMenu.setValue(3, newstaff.password);
			}
			break;
		case 5:
			newstaff.insert();
			std::cout << "Registered successfully";
			_getch();
			break;
		case 6:
			return;
		default:
			break;
		}
	}

}
void registerCust() {
	Customer newcust; 

	Menu rgMenu;
	rgMenu.header = "- Customer Registration -";
	rgMenu.addOption("Email");
	rgMenu.addOption("Phone Number");
	rgMenu.addOption("Create Username");
	rgMenu.addOption("Create Password");
	rgMenu.addOption("Register");
	rgMenu.addOption("Back");


	string tmpinput;
	bool valid = true;
	while (1) {

		switch (rgMenu.prompt()) {
		case 1:
			std::cout << "Insert Email:";
			std::cin >> newcust.email;
			rgMenu.setValue(0, newcust.email);
			break;
		case 2:
			std::cout << "Insert Phone Number:";
			std::cin >> newcust.phoneNum;
			rgMenu.setValue(1, newcust.phoneNum);
			break;
		case 3:
			std::cout << "Insert Username:";
			std::cin >> newcust.username;
			rgMenu.setValue(2, newcust.username);
			break;
		case 4:
			std::cout << "Insert password:";
			std::cin >> tmpinput;
			if (tmpinput.length() < 7) {
				std::cout << "Password must be at least 7 character long";
				_getch();
			}
			else {
				newcust.password = tmpinput;
				rgMenu.setValue(3, newcust.password);
			}
			break;
		case 5:
			newcust.insert();
			std::cout << "Registered successfully";
			_getch();
			break;
		case 6:
			return;
		default:
			break;
		}
	}

}
void loginStaff() {
	Staff newstaff; 
	Menu loginMenu;
	loginMenu.header = "\t-----------------------------------------\n\t-\t      LOGIN STAFF      \t-\n\t-----------------------------------------";
	loginMenu.addOption("username");
	loginMenu.addOption("password");
	loginMenu.addOption("Login");
	loginMenu.addOption("Back");

	Staff user;
	string tmpinput; 
	while (1) {
		switch (loginMenu.prompt())
		{
		case 1:
			std::cout << "Insert Username:";
			std::cin >> user.username;
			loginMenu.setValue(0, user.username);
			_getch();
			break;
		case 2:
			std::cout << "Insert Password:";
			user.password = Staff::getMaskedInput(""); 
			loginMenu.setValue(1, std::string(user.password.length(), '*')); 
			break;
		case 3:
			if (user.login()) {
				homepage(user); 
			}
			else {
				std::cout << "Invalid Login";
				_getch();
			}
			break;
		case 4:
			return;
			break;
		default:
			break;
		}
	}
}
void loginCust() {
	Menu loginMenu;
	loginMenu.header = "\t-----------------------------------------\n\t-\t      LOGIN CUSTOMER      \t-\n\t-----------------------------------------";
	loginMenu.addOption("username");
	loginMenu.addOption("password");
	loginMenu.addOption("Login");
	loginMenu.addOption("Back");

	Customer user; 

	while (1) {
		switch (loginMenu.prompt())
		{
		case 1:
			std::cout << "Insert Username:";
			std::cin >> user.username;
			loginMenu.setValue(0, user.username);
			break;
		case 2:
			std::cout << "Insert Password:";
			user.password = Customer::getMaskedInput("");
			loginMenu.setValue(1, std::string(user.password.length(), '*'));
			break;
		case 3:
			if (user.login()) {
				home(user);
			}
			else {
				std::cout << "Invalid Login";
				_getch();
			}
			break;
		case 4:
			return;
			break;
		default:
			break;
		}
	}
}
void inv(Admin user) {
	Menu adminpage;
	adminpage.addOption("Inventory");
	adminpage.addOption("List of staff");
	adminpage.addOption("Add product");
	adminpage.addOption("Logout");

	while (true) {
		adminpage.header = "\t*************************************************\n\t*\t\t\t\t\t\t*\n\t*\t      WELCOME, ADMIN      \t\t*\n\t*\t\t\t\t\t\t*\n\t*************************************************";
		switch (adminpage.prompt()) {
		case 1:
			inventory(user);
			break;
		case 2:
			listStaff();
			break;
		case 3:
			addProduct(user);
			break;
		case 4:
			logout();
			return; // Exit the function after logout
		default:
			break;
		}
	}
}
void inventory(Admin user) {
	// view inv from database
	vector<Inventory> inventoryList;
	Inventory searchI;
	string displayI = "";

	int InventoryID = 0;
	string productname = "", quantity = " ", category = " ";
	bool asc = true;

	Menu searchIM;
	searchIM.header = "\n\n\t\tInventory\n";
	searchIM.addOption(" 1 > View By Product Name");
	searchIM.addOption(" 2 > View By Category");
	searchIM.addOption(" 3 > View All Product: ");
	searchIM.addOption(" 4 > Update Product's Quantity: ");
	searchIM.addOption(" 5 > Delete Product");
	searchIM.addOption(" 6 > Back");

	while (true) {
		if (asc) {
			searchIM.setValue(2, "Ascending");
		}
		else {
			searchIM.setValue(2, "Descending");
		}

		if (displayI.empty()) {
			displayI = "\n\tResult:\n\n";
			stringstream tmpS;

			tmpS << setw(10) << "\tInventory ID  | " << setw(36) << "\tProduct Name    | " << setw(16) << "\tQuantity  | " << setw(26) << "\tCategory      | " << "\n " << endl;

			for (const auto& item : inventoryList) {
				tmpS << setw(10) << item.inventoryId << "\t  |" << setw(35) << item.productname << "\t  |" << setw(16) << item.quantity << "\t|" << setw(25) << item.catogory << "\t |" << endl;
			}
			displayI += tmpS.str();

			ofstream outputFile("inventory.txt");
			if (outputFile.is_open()) {
				outputFile << displayI;
				outputFile.close();
			}
			else {
				cerr << "Unable to open file for writing." << endl;
			}
		}
		searchIM.footer = displayI;

		switch (searchIM.prompt()) {
		case 1:
			cout << "Insert Product Name: ";
			cin.ignore(); // Ignore newline character in the buffer
			getline(cin, productname);
			searchIM.setValue(0, productname);
			inventoryList = Inventory::searchInventory(productname, quantity, category, asc);
			displayI = "";
			break;
		case 2:
			cout << "Insert Category: ";
			cin.ignore(); // Ignore newline character in the buffer
			getline(cin, category);
			searchIM.setValue(1, category);
			inventoryList = Inventory::searchInventory(productname, quantity, category, asc);
			displayI = "";
			break;
		case 3:
			asc = !asc;
			inventoryList = Inventory::searchInventory("", "", "", asc);
			displayI = "";
			break;
		case 4:
			cout << "Insert Inventory ID: ";
			cin.ignore(); // Ignore newline character in the buffer 
			cin >> searchI.inventoryId;
			searchIM.setValue(3, to_string(searchI.inventoryId));
			displayI = "";
			cout << "Insert new Quantity: ";
			cin.ignore(); // Ignore newline character in the buffer 
			cin >> searchI.quantity;
			searchIM.setValue(3, searchI.quantity);
			searchI.update();
			break;
		case 5:
			cout << "Insert Inventory ID to delete account: ";
			cin >> InventoryID;
			searchIM.setValue(4, to_string(InventoryID));
			for (auto it = inventoryList.begin(); it != inventoryList.end(); ++it) {
				if (it->inventoryId == InventoryID) {
					// Remove the item from inventoryList or perform the delete operation
					inventoryList.erase(it);
					searchI.remove(); 
					break;
				}
			}
			displayI = "";
			break;
		case 6:
			return; // Exit the function
		default:
			break;
		}
	}
}

//void removeInventory(inventory) {

//}
void addProduct(Admin user) {
	Inventory inv;

	Menu invMenu;
	invMenu.header = "- Insert new product -";
	invMenu.addOption("Product Name");
	invMenu.addOption("Quantity");
	invMenu.addOption("Category");
	invMenu.addOption("Save");
	invMenu.addOption("Back");


	string tmpinput;
	while (1) {

		switch (invMenu.prompt()) {
		case 1:
			cout << "Insert product name:";
			cin.ignore(); // Ignore newline character in the buffer
			getline(cin, inv.productname); 
			invMenu.setValue(0, inv.productname);
			break;
		case 2:
			cout << "Insert Quantity:";
			cin >> inv.quantity;
			invMenu.setValue(1, inv.quantity);
			break;
		case 3:
			cout << "Insert Product's Category:";
			cin >> inv.catogory;
			invMenu.setValue(2, inv.catogory);
			break;
		case 4:
			inv.insert();
			cout << "Registered successfully";
			_getch();
			break;
		case 5:
			return;
		default:
			break;
		}
	}
}
void product(Admin user) {
	//insert product
}
void homepage(Staff user) {
	Menu staffpage;
	staffpage.addOption("Hotel Room Details"); 
	staffpage.addOption("View reservation"); 
	staffpage.addOption("Logout"); 
	while (1) {
		staffpage.header = "\t*************************************************\n\t*\t\t\t\t\t\t*\n\t*\t\t      WELCOME      \t\t*\n\t*\t\t\t\t\t\t*\n\t*************************************************"; 
		switch (staffpage.prompt()) 
		{
		case 1:
			hoteldetails();
			break;
		case 2:
			Reservation::viewReservations(); 
			_getch();
			break;
		case 3:
			logout();
			break;
		default:
			break;
		}
	}
}
void hoteldetails() {
	Menu mainmenu;
	mainmenu.header = "-  Hotel Details  -";
	mainmenu.addOption("Hotel room type");
	mainmenu.addOption("Back");

	while (1) {
		switch (mainmenu.prompt())
		{
		case 1:
			std::cout << "\n\n1. Standard Room\n";
			std::cout << "3 Feet(L) X 2.5 Feet(W)\n";
			std::cout << "RM30/Night\n";
			std::cout << "Max 2 cat\n\n";

			std::cout << "2. Deluxe Room\n";
			std::cout << "RM40/Night\n";
			std::cout << "2-6 cat\n";
			std::cout << "6 Feet(L) X 2.5 Feet(W)\n\n";

			std::cout << "-> Food and Litter provided\n";
			std::cout << "-> Additional RM15 for second cat\n";
			_getch();
			break;
		case 2:
			return;
		default:
			break;
		}
	}
}
void updatehotel() {

}
void home(Customer user) { 
	Menu homeMenu; 
	Cat cat; 
	homeMenu.addOption("Add new Cat"); 
	homeMenu.addOption("booking"); 
	homeMenu.addOption("Hotel room details");
	homeMenu.addOption("Logout"); 
	while (1) {
		homeMenu.header = "\t*************************************************\n\t*\t\t\t\t\t\t*\n\t*\t\t      WELCOME      \t\t*\n\t*\t\t\t\t\t\t*\n\t*************************************************\n\t Hello," + user.username; 
		switch (homeMenu.prompt()) 
		{
		case 1:
			booking(user, cat);    
			break;
		case 2:
			book(user);
			break;
		case 3:
			hoteldetails();
			break;
		case 4:
			logout();
			break;
		default:
			break;
		}
	}
}
Cat booking(Customer user, Cat cat) {
	Cat newcat = cat;
	newcat.customerId = user.customerId;
	Menu homeMenu;
	homeMenu.header = "Insert Details";
	homeMenu.addOption("Cat name");
	homeMenu.addOption("Cat species/colour");
	homeMenu.addOption("Cat age (year)");
	homeMenu.addOption("Save details");
	homeMenu.addOption("back");
	while (1) {
		switch (homeMenu.prompt())
		{
		case 1:
			cout << "Write your cat's name:";
			getline(cin, newcat.catName);
			homeMenu.setValue(0, newcat.catName);
			break;
		case 2:
			cout << "Cat's species or color:";
			getline(cin, newcat.catSpecies);
			homeMenu.setValue(1, newcat.catSpecies);
			break;
		case 3:
			cout << "Cat's Age:";
			cin >> newcat.catAge;
			homeMenu.setValue(2, newcat.catAge);
			break;
		case 4:
			newcat.insertcat();
			cout << "saved";
			_getch();
			break;
		case 5:
			return cat;
			break;
		default:
			break;
		}
	}
}
/*void reservation(Customer user, Cat cat, Reservation reserve, Hotelroom room, Payment pay)
{
	Reservation temp = reserve;
	Menu reserveMenu;
	reserveMenu.header = "\n\n\t\t\t\tMake a booking\n\t---------------------------------------------- \n\n\t 1. Standard Room (S): \n\t\t 3 Feet(L) x 2.5 Feet(W) \n\t\t RM30 / night \n\t\t Max 2 cat \n\n\t 2. Deluxe Room (D): \n\t\t 6 Feet(L) x 2.5 Feet(W) \n\t\t RM40 / night \n\t\t Max 2 - 6 Cat  \n\n";
	reserveMenu.addOption(" 1 > Enter Room Type: ");
	reserveMenu.addOption(" 2 > Enter your Cat Name: ");
	reserveMenu.addOption(" 3 > Enter Check In Date: ");
	reserveMenu.addOption(" 4 > Enter duration: ");
	reserveMenu.addOption(" 5 > Book");
	reserveMenu.addOption(" 6 > Proceed to Payment");
	reserveMenu.addOption(" 7 > Back");
	bool valid = true;
	char confirm;
	char roomType;

	while (1)
	{
		switch (reserveMenu.prompt())
		{
		case 1:
			cout << "Enter Room Type ( S / D ): ";
			cin >> reserve.roomType;
			reserveMenu.setValue(0, reserve.roomType);
			break;

		case 2:
			cout << "Enter your cat name: ";
			cin >> reserve.catName;
			reserveMenu.setValue(1, reserve.catName);
			break;

		case 3:
			cout << "Enter Check In Date (yyyy/mm/dd): ";
			cin >> reserve.reserve_date;
			reserveMenu.setValue(2,reserve.reserve_date);
			break;

		case 4:
			cout << "Enter Check In Date (yyyy/mm/dd): ";
			cin >> reserve.duration;
			reserveMenu.setValue(2, reserve.duration);
			break;

		case 5:
			cout << "Proceed the booking? (y/n): ";
			confirm = _getch();
			if (confirm == 'Y' || confirm == 'y')
			{
				reserve.insertReservation();
				cout << "\n Booking Successful.";
				_getch();
			}
			else
				cout << "\nBooking Cancelled.";
			_getch();
			break;

		case 6:
			//payment(user, cat, reserve, room, pay); 
			break;

		case 7:
			home(user);
			break;
		default:
			break;
		}
	}
}*/

// process of payment
/*void payment(Customer user, Cat cat, Reservation reserve, Hotelroom room, Payment pay)
{
	system("cls");
	//Reservation reserve;
	//Payment pay;
	char confirm;
	double total;
	reserve.roomType == "S" || reserve.roomType == "s" == 30.0;
	reserve.roomType == "D" || reserve.roomType == "d" == 40.0;

	// Prompt the user to enter the room type
	std::cout << "Insert Room Type (S for Standard, D for Deluxe): ";
	std::cin >> reserve.roomType;
	// Check if the user input is valid
	/*if (reserve.roomType != "S" && reserve.roomType != "s" && reserve.roomType != "D" && reserve.roomType != "d") {
		std::cerr << "Invalid room type. Please enter 'S' or 'D'.\n";
		return 1;  // Exit the program with an error code
	}*/

	// Prompt the user to enter the duration
	//std::cout << "Insert Duration (in days): ";  
	//std::cin >> reserve.duration;
	// Check if the user input is valid
	/*if (reserve.duration <= 0) {
		std::cerr << "Invalid duration. Please enter a positive number.\n";
		return 1;  // Exit the program with an error code
	}*/

	// Calculate the total cost based on room type and duration
	/*if (reserve.roomType == "S" || reserve.roomType == "s") {
		double total = reserve.roomType * reserve.duration;
		std::cout << "\n\t Total: RM " << std::to_string(pay.total) << std::endl;
	}
	else if (reserve.roomType == "D" || reserve.roomType == "d") {
		pay.total = 40.0 * reserve.duration;
		std::cout << "\n\t Total: RM " << std::to_string(pay.total) << std::endl;
	}*/

	// Ask the user for confirmation
	/*std::cout << "\n\n************\n";
	std::cout << "Proceed with the payment? (y/n)\n\n";
	std::cout << "Once you enter the confirmation details,\n";
	std::cout << "you will automatically go to transaction.\n";
	std::cout << "You are unable to cancel the booking process once confirmed.\n";
	std::cin >> confirm;

	if (confirm == 'Y' || confirm == 'y') {
		std::cout << "\nRe-enter Your room type for confirmation: ";
		std::cin >> reserve.roomType;
		// Add the rest of the confirmation process here...
	}
	else {
		std::cout << "Booking process canceled.\n";
	}

	/*system("cls");
	char confirm;
	double Total;
	string roomType;
	Payment temp = pay;
	cout << " \n\t\t Your reservation details: \n\n\tRoom Type: " + reserve.roomType + " \n\tCat Name : " + reserve.catName
		+ " \n\tReservation Date: " + reserve.reserve_date + " \n\tDuration / night: " + reserve.duration;
	_getch();

	if (reserve.roomType == "S" || reserve.roomType == "s")
	{
		temp.total = 30 * reserve.duration;
		cout << "\n\t Total: RM " + to_string(pay.total);
		break;
	}
	else if (reserve.roomType == 'D' || reserve.roomType == 'd')
	{
		temp.total = 40 * reserve.duration;
		cout << "\n\t Total: RM " + to_string(pay.total);
		break;
	}

	cout << "\n\n**********************\n";
	cout << "\n\nProceed the payment? (y/n)\n\n Once you enter the confirmation details,\n you will automatically go to transaction.\n You are enable to cancel the booking after the transaction process.\n";
	confirm = _getch();
	if (confirm == 'Y' || confirm == 'y')
	{
		cout << "\nRe-enter Your room type for confirmation: ";
		cin >> pay.roomType;
		cout << "\nRe-enter Your cat name for confirmation: ";
		cin >> pay.catName;

		time_t now = time(0); // get current dat/time with respect to system  
		char* dt = ctime(&now); // convert it into string  
		cout << "\nPayment successful. ";
		system("cls");
		cout << "\n\n\t ****** YOUR RECEIPT ****** \n\n\t Your booking for room type " + to_string(pay.roomType) + " has been assigned. \n\n\t Date: " + reserve.reserve_date
			+ "\n\n\t Duration per night: " + reserve.duration;
		+"\n\n\t Treatment price: RM " + to_string(temp.total)
			+ "\n\n\t *************** ";


		// calculate total payment ( price + tax & service )
		pay.total = temp.total + 30;

		cout << "\n\n\t Total Payment: RM " + to_string(pay.total);
		pay.insertPayment();

		cout << "\n\n\t *************** \n\n\t The payment was made on " << dt << endl;
		cout << "\n\n\t\t Thank You :) ";
	}
	else
		cout << "\nPayment cancelled.";
	reserve.removeReservation();
	_getch();*/
//}

void book(Customer user) {
	Reservation newres; 
	Menu shopMenu;
	shopMenu.footer = "Enter Booking details";
	shopMenu.header = "\n\n\t\t\tMake a booking\n\t---------------------------------------------- \n\n\t 1. Standard Room (S): \n\t\t 3 Feet(L) x 2.5 Feet(W) \n\t\t RM30 / night \n\t\t Max 2 cat \n\n\t 2. Deluxe Room (D): \n\t\t 6 Feet(L) x 2.5 Feet(W) \n\t\t RM40 / night \n\t\t Max 2 - 6 Cat  \n\n";
	shopMenu.addOption("Room");
	shopMenu.addOption("Cat Name");
	shopMenu.addOption("Check-in Date");
	shopMenu.addOption("Duration");
	shopMenu.addOption("Total");
	shopMenu.addOption("Save");
	shopMenu.addOption("Back");

	std::string catName;
	int roomType = 0; 
	int duration = 0;
	std::vector<std::string> additionalCats;
	std::string checkInDate;
	std::string checkOutDate;

	auto calculateCheckOutDate = [](const std::string& checkIn, int duration) -> std::string {
		std::tm tm = {};
		std::stringstream ss(checkIn);
		ss >> std::get_time(&tm, "%Y-%m-%d");
		tm.tm_mday += duration;
		std::mktime(&tm);
		std::ostringstream oss;
		oss << std::put_time(&tm, "%Y-%m-%d");
		return oss.str();
		};

	while (true) {
		switch (shopMenu.prompt()) {
		case 1: {
			std::cout << "\nSelect Room Type:\n";
			std::cout << "1. Standard Room\n";
			std::cout << "2. Deluxe Room\n";
			int choice;
			std::cin >> choice;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (choice == 1 || choice == 2) {
				roomType = choice;
				newres.roomType = (roomType == 1 ? "Standard Room" : "Deluxe Room");
				std::cout << "Room type set to " << newres.roomType << "\n";
				shopMenu.setValue(0, newres.roomType);
			}
			else {
				std::cout << "Invalid selection. Please try again.\n";
			}
			break;
		}
		case 2: {
			std::cout << "Enter Cat Name: ";
			std::getline(std::cin, catName);
			newres.catName = catName;
			std::cout << "Cat name set to " << catName << "\n";
			shopMenu.setValue(1, catName); 
			break;
		}
		case 3: {
			std::cout << "Enter Check-in Date (YYYY-MM-DD): ";
			std::getline(std::cin, checkInDate);
			newres.reserve_date = checkInDate;
			std::cout << "Check-in date set to " << checkInDate << "\n";
			checkOutDate = calculateCheckOutDate(checkInDate, duration);
			std::cout << "Calculated Check-out Date: " << checkOutDate << "\n";
			shopMenu.setValue(2, checkInDate);
			break;
		}
		case 4: {
			std::cout << "Enter Duration (in nights): ";
			std::cin >> duration;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			newres.duration = std::to_string(duration);
			std::cout << "Duration set to " << duration << " nights\n";
			shopMenu.setValue(3, newres.duration);
			checkOutDate = calculateCheckOutDate(checkInDate, duration);
			std::cout << "Calculated Check-out Date: " << checkOutDate << "\n";
			_getch();
			break;
		}
		case 5: {
			double amount = newres.calculateAmount();
			std::cout << "Total amount: RM" << std::fixed << std::setprecision(2) << amount << "\n"; 
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Please pay the amount when check in at the counter";
			_getch();
			shopMenu.setValue(4, to_string(amount));
			break;
		}
		case 6: {
			/*newres.insertReservation();
			std::cout << "Registered successfully";
			_getch();
			break;*/
			if (newres.isDateReserved(newres.reserve_date, newres.roomType)) {
				std::cout << "Failed to save booking: Check-in date for this room type is already reserved.\n";
			}
			else {
				try {
					newres.insertReservation();
					std::cout << "Booking saved successfully!\n";
				}
				catch (const std::exception& e) {
					std::cout << "Failed to save booking: " << e.what() << "\n";
				}
			}
			_getch(); // wait for a key press
			return;
		}
		case 7: {
			return;
		default:
			std::cout << "Invalid selection. Please try again.\n";
			break;
		}
		}
	}
}

/*void reservation(Customer user, Cat cat) {
	char confirmCat; 
	Cat newroom = cat; 
	//Cat = cat;
	//newcat.customerId = user.customerId;
	Menu homeMenu; 
	homeMenu.header = "\n\nInsert Details To Book Hotel"; 
	homeMenu.addOption("Cat name");
	homeMenu.addOption("Hotel Room");
	homeMenu.addOption("Duration");
	homeMenu.addOption("Save booking");
	homeMenu.addOption("back");
	while (1) {
		switch (homeMenu.prompt())
		{
		case 1:
			cout << "Write your cat's name:";
			confirmCat = _getch();  
			if (confirmCat == catName) {
				homeMenu.setValue(0, catName); 
			}
			else {
				cout << "\n\n\t Please register your cat first. \n\n\t Press any key to continue. ";
				_getch();
				return;
			}
			homeMenu.setValue(0, newcat.catName);
			break;
		case 2:
			cout << "Choose a hotel room:"; 
			getline(cin, newroom.room);
			homeMenu.setValue(1, newroom.catRoom); 
			break;
		case 3:
			cout << "Enter Duration (Night):";
			cin >> newroom.duration;
			homeMenu.setValue(2, newroom.duration);
			break;
		case 4:
			newroom.insertcat();
			cout << "reservation successful";
			_getch();
			break;
		case 5:
			return;
			break;
		default:
			break;
		}
	}*/

// list of staff
int listStaff()
{
	Admin user; 
	//Appointment book;
	//Payment pay;
	vector<Staff> staff;
	Staff searchS;
	string displayS = "";

	int StaffID = 0;
	string username = "", email = " ", phoneNo = " ";
	bool asc = true;

	ofstream outputFile("view.txt");

	Menu searchSM;
	searchSM.header = "\n\n\t\tList of Staff \n";
	searchSM.addOption(" 1 > View By Name");
	searchSM.addOption(" 2 > View By Email");
	searchSM.addOption(" 3 > View All Staff: ");
	searchSM.addOption(" 4 > Update Staff's Phone Number: ");
	searchSM.addOption(" 5 > Delete Staff Account");
	searchSM.addOption(" 6 > Back");

	while (1)
	{
		if (asc)
		{
			searchSM.setValue(2, "Ascending");
		}
		else
		{
			searchSM.setValue(2, "Descending");
		}
		if (displayS == "")
		{
			displayS = "\n\tResult:\n\n";
			stringstream tmpS;

			tmpS << setw(10) << "\tStaff ID  | " << setw(36) << "\tStaff Username    | " << setw(16) << "\tStaff Email  | " << setw(26) << "\tStaff Phone Number      | " << "\n "
				<< endl;

			for (int i = 0; i < staff.size(); i++)
			{
				tmpS << setw(10) << staff[i].staffId << "\t  |" << setw(35) << staff[i].username << "\t  |" << setw(16) << staff[i].email << "\t|" << setw(25) << staff[i].phoneNo << "\t |" << endl;
				//outputFile << staff[i].staffId << " " << staff[i].username << " " << staff[i].email << " " << staff[i].phoneNo;
			
			}
			displayS += tmpS.str();

			ofstream outputFile("view.txt");
			if (outputFile.is_open()) {
				outputFile << displayS;
				outputFile.close();
			}
			else {
				cerr << "Unable to open file for writing." << endl;
			}
		}
		searchSM.footer = displayS;

		switch (searchSM.prompt())
		{
		case 1:
			cout << " Insert Staff Userame: ";
			//cin.ignore(); // Ignore newline character in the buffer
			getline(cin, username);
			searchSM.setValue(0, username);
			staff = Staff::searchStaff(username, email, asc);
			displayS = "";
			break;
		case 2:
			cout << " Insert Email: ";
			//cin.ignore(); // Ignore newline character in the buffer
			getline(cin, email);
			searchSM.setValue(1, email);
			staff = Staff::searchStaff(username, email, asc);
			displayS = "";
			break;
		case 3:
			asc = !asc;
			staff = Staff::searchStaff("", "", asc); // View all staff, no criteria
			displayS = "";
			break;
		case 4:
			cout << " Insert Staff ID: ";
			cin.ignore(); // Ignore newline character in the buffer 
			cin >> searchS.staffId; 
			searchSM.setValue(3, to_string(searchS.staffId)); 
			displayS = ""; 
			cout << " Insert new Phone Number: ";
			cin.ignore(); // Ignore newline character in the buffer 
			cin >> searchS.phoneNo;
			searchSM.setValue(3, searchS.phoneNo);
			searchS.update(); 
			break;
		case 5:
			cout << " Insert Staff ID to delete account: ";
			cin >> StaffID;
			searchSM.setValue(5, to_string(StaffID));
			for (Staff& staff : staff) {
				if (staff.staffId == StaffID) {
					removeStaff(staff);
				}
			}
			break;
		case 6:
			inv(user);
			break;
		}
	}
}
Staff removeStaff(Staff user)
{
	//Staff temp = user;
	Menu deleteCM;
	char confirm;

	cout << "\n\tAre you sure want to delete your account? (y/n)\n";
	confirm = _getch();
	if (confirm == 'Y' || confirm == 'y')
	{
		//user = temp; 
		user.remove();
		cout << "\n\t Staff account deleted.";
		_getch();
		listStaff();
	}
	else
	{
		cout << "\n\n\t Account saved. \n\n\t Press any key to continue. ";
		_getch();
		listStaff();
	}
	return user;
}
void logout() {
	char confirm; 
	
	std::cout << "Are you sure you want to logout? (y/n)" << std::endl; 
	confirm = _getch();
	if (confirm == 'Y' || confirm == 'y'){
		std::cout << "You have been logged out." << std::endl;
		_getch();
		main();
	}
	else {
		cout << "\n\n\t Failed to logout. \n\n\t Press any key to continue. ";
		_getch();
		return;
	}
}
/*void reservation() {
	Menu rsvMenu;
	rsvMenu.header = "- Insert new booking -";
	rsvMenu.addOption("Choose hotel room");
	rsvMenu.addOption("How long");
	rsvMenu.addOption("How many cat?");
	rsvMenu.addOption("Save");
	rsvMenu.addOption("Back");


	string tmpinput;
	while (1) {

		switch (rsvMenu.prompt()) {
		case 1:
			cout << "Insert room type (Standard/Deluxe):";
			cin.ignore(); // Ignore newline character in the buffer
			cin >> rsv.roomtype;
			rsvMenu.setValue(0, rsv.roomtype);
			break;
		case 2:
			cout << "Insert how many night your cat will stay:";
			cin >> rsv.duration;
			rsvMenu.setValue(1, rsv.duration);
			break;
		case 3:
			cout << "Insert cat's quantity:";
			cin >> rsv.cat;
			rsvMenu.setValue(2, rsv.cat);
			break;
		case 4:
			//inv.insert();
			cout << "Registered successfully";
			_getch();
			break;
		case 5:
			return;
		default:
			break;
		}
	}
}
}*/
/*void hotel(Customer user) {
	//Transaction cart; //initialize a transaction to hold product values
	//cart.user = user.customerId; // put currently logge in user id into the transaction

	Menu rsvMenu;
	rsvMenu.footer = "Select Hotel Room Category";
	rsvMenu.addOption("Standard");
	rsvMenu.addOption("Deluxe");
	rsvMenu.addOption("View Cart");
	rsvMenu.addOption("Back");
	while (1) {
		rsvMenu.header = "HOTEL ROOM\nItems in reservation:" + to_string(reservation.count()) + "  \nTotal Price: " + to_string(reservation.total());
		switch (rsvMenu.prompt())
		{
		case 1:
			reservation = rooms(user, 1, reservation);
			break;
		case 2:
			reservation = rooms(user, 2, reservation);
			break;
		case 3:
			reservation = roomMenu(user, reservation);
			break;
		case 4:
			return;
			break;
		}
	}
}

/Transaction products(Account user, int category, Transaction cart) {
	vector<Product> products;
	string displayString = "";

	string keyWord = "", sortColumn = "price";
	bool ascending = true;
	double minPrice = 0, maxPrice = 999999;


	Menu productMenu;
	productMenu.header = "Search Option";
	productMenu.addOption("Key Word");
	productMenu.addOption("Minimum Price");
	productMenu.addOption("Maximum Price");
	productMenu.addOption("Sort By");
	productMenu.addOption("Ordering");
	productMenu.addOption("Search");
	productMenu.addOption("Select");
	productMenu.addOption("Back");

	Menu sortingSubMenu;
	sortingSubMenu.header = "Select Sort category";
	sortingSubMenu.addOption("Price");
	sortingSubMenu.addOption("Name");

	while (1)
	{
		productMenu.setValue(3, sortColumn);
		if (ascending) {
			productMenu.setValue(4, "Ascending");
		}
		else {
			productMenu.setValue(4, "Descending");
		}

		if (displayString == "") {
			displayString = "\nSearch Result:\n";
			stringstream tmpString;
			tmpString << fixed << setprecision(2) << setw(5) << "ID" << "|" << setw(20) << "Name"
				<< "|" << setw(10) << "Price" << "|" << setw(20) << "Description" << "|" << endl;

			for (int i = 0; i < products.size(); i++) {
				tmpString << setw(5) << products[i].productId << "|" << setw(20) << products[i].name
					<< "|" << setw(10) << products[i].price << "|" << setw(20) << products[i].description << "|" << endl;
			}
			displayString += tmpString.str();
		}
		productMenu.footer = displayString;

		switch (productMenu.prompt()) {

			/// the case will modify the variable used as parameter to call the search method
		case 1:
			cout << "Insert Key Word: ";
			getline(cin, keyWord);
			productMenu.setValue(0, keyWord);
			break;
		case 2:
			cout << "Insert Min Price: ";
			cin >> minPrice;
			productMenu.setValue(1, to_string(minPrice));
			break;
		case 3:
			cout << "Insert Max Price: ";
			cin >> maxPrice;
			productMenu.setValue(2, to_string(maxPrice));
			break;
		case 4:
			switch (sortingSubMenu.prompt())
			{
			case 1:
				sortColumn = "price";
				break;
			case 2:
				sortColumn = "name";
				break;
			}
			break;
		case 5:
			ascending = !ascending;
			break;
		case 6:

			products = Product::findProduct(category, keyWord, minPrice, maxPrice, sortColumn, ascending);
			displayString = "";
			break;
		case 7:
			cout << "Insert Product Id to Select:";
			int productId;
			cin >> productId;
			cart = productDetail(user, productId, cart);
			break;
		case 8:
			return cart;
			break;

		}
	};

}

/Transaction productDetail(Account user, int productId, Transaction cart) {
	Product product = Product::findProduct(productId);
	if (product.productId == 0) {
		// default id, which mean product doesn't exist since no 0 id in database
		cout << "Product not found";
		_getch();
		return cart;
	}

	Menu productMenu;
	productMenu.header = "Action:";
	productMenu.addOption("Add to cart");
	productMenu.addOption("Back");
	productMenu.footer = "Product Details:\n"
		"\nName\t: " + product.name
		+ "\nDescription\t: " + product.description
		+ "\nPrice\t: " + to_string(product.price);
	while (1) {
		switch (productMenu.prompt())
		{
		case 1:
			cout << "Insert Quantity :";
			int qty;
			cin >> qty;
			if (qty > 0) {
				cart.addProduct(product, qty);
			}
			cout << endl << "Product Added into cart";
			_getch();
			break;
		case 2:
			return cart;
			break;
		}
	}

}

/Transaction cartMenu(Account user, Transaction cart) {
	Menu cartM;
	cartM.header = "Actions";
	cartM.addOption("Checkout");
	cartM.addOption("Empty Cart");
	cartM.addOption("Back");
	stringstream ss;
	ss << fixed << setprecision(2) << setw(20) << "Product|" << setw(20) << "Price|" << setw(20)
		<< "Quantity|" << setw(20) << "Subtotal|" << endl;
	for (int i = 0; i < cart.items.size(); i++) {
		ss << setw(20) << cart.items[i].first.name << setw(20) << cart.items[i].first.price << setw(20)
			<< cart.items[i].second << setw(20) << (cart.items[i].first.price * cart.items[i].second) << endl;
	}
	ss << setw(20) << "SUM" << setw(20) << "" << setw(20) << cart.count() << setw(20) << cart.total();
	cartM.footer = "Cart Items\n" + ss.str();
	char confirm;
	while (1)
	{
		switch (cartM.prompt())
		{
		case 1:
			cout << "Check out? (y/n)";
			confirm = _getch();
			if (confirm == 'Y' || confirm == 'y') {
				cart.insert();
				cout << "Transaction saved";
				_getch();
				shop(user); // go back to shop with empty cart
			}
			break;
		case 2:
			cout << "Clear your cart? (y/n)";
			confirm = _getch();
			if (confirm == 'Y' || confirm == 'y') {
				shop(user); // go back to shop with empty cart
			}
			break;
		case 3:
			return cart;
		}

	}
}*/
