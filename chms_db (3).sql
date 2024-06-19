-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 19, 2024 at 07:15 PM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.1.25

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `chms_db`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE `admin` (
  `adminId` int(255) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`adminId`, `username`, `password`) VALUES
(1, 'admin1', '11111111');

-- --------------------------------------------------------

--
-- Table structure for table `cat`
--

CREATE TABLE `cat` (
  `catId` int(255) NOT NULL,
  `catName` varchar(255) NOT NULL,
  `catSpecies` varchar(255) NOT NULL,
  `catAge` int(255) NOT NULL,
  `customerId` int(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `cat`
--

INSERT INTO `cat` (`catId`, `catName`, `catSpecies`, `catAge`, `customerId`) VALUES
(1, 'Comel', 'Calico', 3, 2),
(2, 'Comel', '2Calco', 2, 2),
(3, 'Oyen', 'Orange', 2, 2),
(4, 'Minah', 'British', 1, 2),
(5, 'Baby Layla', 'British Short Hair', 1, 2),
(6, 'Joyah', 'White', 2, 2),
(7, '', 'black', 1, 2);

-- --------------------------------------------------------

--
-- Table structure for table `customer`
--

CREATE TABLE `customer` (
  `customerId` int(255) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `phoneNum` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `customer`
--

INSERT INTO `customer` (`customerId`, `username`, `password`, `email`, `phoneNum`) VALUES
(1, 'asasa', 'sdssd', 'sdss', 'scs'),
(2, 'Aman', 'aman123', 'aman@gmail.com', ''),
(3, 'Mail', 'mail111', 'mail@gmail.com', ''),
(4, 'nurul', '2222222', 'nurul@gmail.com', ''),
(5, 'Yaya', 'yayayaya', 'yaya@gmail.com', '0119992710');

-- --------------------------------------------------------

--
-- Table structure for table `hotelroom`
--

CREATE TABLE `hotelroom` (
  `roomId` int(255) NOT NULL,
  `roomName` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `hotelroom`
--

INSERT INTO `hotelroom` (`roomId`, `roomName`) VALUES
(1, 'Standard'),
(2, 'Deluxe');

-- --------------------------------------------------------

--
-- Table structure for table `inventory`
--

CREATE TABLE `inventory` (
  `inventoryId` int(255) NOT NULL,
  `productname` varchar(255) NOT NULL,
  `quantity` int(255) NOT NULL,
  `catogory` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `inventory`
--

INSERT INTO `inventory` (`inventoryId`, `productname`, `quantity`, `catogory`) VALUES
(1, 'Wet food', 20, 'Food'),
(2, 'Fresh Step', 40, 'Litter'),
(3, 'Royal Canin', 50, 'Food'),
(4, 'Fake Fish', 70, 'Toys'),
(5, 'Cat Tofu', 40, 'Litter'),
(6, ' Whiskas', 60, 'food'),
(9, 'booster', 70, 'food'),
(10, 'can food', 30, 'food');

-- --------------------------------------------------------

--
-- Table structure for table `payment`
--

CREATE TABLE `payment` (
  `paymentId` int(255) NOT NULL,
  `reservationId` int(255) NOT NULL,
  `amount` double(4,2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `resesrvation`
--

CREATE TABLE `resesrvation` (
  `reservationId` int(255) NOT NULL,
  `roomType` varchar(255) NOT NULL,
  `catName` varchar(255) NOT NULL,
  `reserve_date` varchar(255) NOT NULL,
  `duration` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `resesrvation`
--

INSERT INTO `resesrvation` (`reservationId`, `roomType`, `catName`, `reserve_date`, `duration`) VALUES
(1, 'Standard Room', 'Oyen', '2024-08-22', '2'),
(2, 'Standard Room', 'Minah', '2024-08-19', '3'),
(3, 'Standard Room', 'Mok', '2024-08-22', '2'),
(4, 'Deluxe Room', 'Comel', '2024-08-22', '4'),
(5, 'Standard Room', 'Opet', '2024-10-10', '4'),
(6, 'Deluxe Room', 'Opet', '2024-10-20', '3'),
(7, 'Deluxe Room', 'Opet', '2024-11-01', '4'),
(8, 'Deluxe Room', 'Snow', '2024-12-01', '4'),
(9, 'Standard Room', 'Udin', '2024-09-17', '2'),
(10, 'Standard Room', 'Adik', '2024-05-07', '5'),
(11, 'Standard Room', 'Putih', '2024-10-12', '2'),
(12, 'Deluxe Room', 'Ochi', '2024-09-09', '10');

-- --------------------------------------------------------

--
-- Table structure for table `staff`
--

CREATE TABLE `staff` (
  `staffId` int(255) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `phoneNo` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `staff`
--

INSERT INTO `staff` (`staffId`, `username`, `password`, `email`, `phoneNo`) VALUES
(1, 'alya22', '22222222', 'alya@gmail.com', '011892100'),
(3, 'Ucop', '1234567', 'ucop@yahoo.com', '011927801'),
(6, 'qis', 'qis1111', 'qis@gmail.com', '0198821760');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admin`
--
ALTER TABLE `admin`
  ADD PRIMARY KEY (`adminId`);

--
-- Indexes for table `cat`
--
ALTER TABLE `cat`
  ADD PRIMARY KEY (`catId`),
  ADD KEY `customer` (`customerId`);

--
-- Indexes for table `customer`
--
ALTER TABLE `customer`
  ADD PRIMARY KEY (`customerId`);

--
-- Indexes for table `hotelroom`
--
ALTER TABLE `hotelroom`
  ADD PRIMARY KEY (`roomId`);

--
-- Indexes for table `inventory`
--
ALTER TABLE `inventory`
  ADD PRIMARY KEY (`inventoryId`);

--
-- Indexes for table `payment`
--
ALTER TABLE `payment`
  ADD PRIMARY KEY (`paymentId`),
  ADD KEY `reservationId` (`reservationId`);

--
-- Indexes for table `resesrvation`
--
ALTER TABLE `resesrvation`
  ADD PRIMARY KEY (`reservationId`);

--
-- Indexes for table `staff`
--
ALTER TABLE `staff`
  ADD PRIMARY KEY (`staffId`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `admin`
--
ALTER TABLE `admin`
  MODIFY `adminId` int(255) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `cat`
--
ALTER TABLE `cat`
  MODIFY `catId` int(255) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT for table `customer`
--
ALTER TABLE `customer`
  MODIFY `customerId` int(255) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `hotelroom`
--
ALTER TABLE `hotelroom`
  MODIFY `roomId` int(255) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `inventory`
--
ALTER TABLE `inventory`
  MODIFY `inventoryId` int(255) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `payment`
--
ALTER TABLE `payment`
  MODIFY `paymentId` int(255) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `resesrvation`
--
ALTER TABLE `resesrvation`
  MODIFY `reservationId` int(255) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;

--
-- AUTO_INCREMENT for table `staff`
--
ALTER TABLE `staff`
  MODIFY `staffId` int(255) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `cat`
--
ALTER TABLE `cat`
  ADD CONSTRAINT `customer` FOREIGN KEY (`customerId`) REFERENCES `customer` (`customerId`);

--
-- Constraints for table `payment`
--
ALTER TABLE `payment`
  ADD CONSTRAINT `reservationId` FOREIGN KEY (`reservationId`) REFERENCES `resesrvation` (`reservationId`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
