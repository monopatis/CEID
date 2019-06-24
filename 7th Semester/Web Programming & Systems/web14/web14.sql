-- phpMyAdmin SQL Dump
-- version 3.3.7deb7
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Jun 28, 2014 at 08:28 PM
-- Server version: 5.1.73
-- PHP Version: 5.3.3-7+squeeze19

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `web14`
--

-- --------------------------------------------------------

--
-- Table structure for table `categories`
--

CREATE TABLE IF NOT EXISTS `categories` (
  `name` varchar(50) CHARACTER SET greek NOT NULL,
  PRIMARY KEY (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `categories`
--

INSERT INTO `categories` (`name`) VALUES
('Ακρίδες'),
('Βατράχια'),
('Κατεδάφιση'),
('Μετεωρίτης'),
('Πετρελαιοκυλίδα'),
('Πλημμύρα'),
('Σεισμός'),
('Τσουνάμι'),
('Φωτιά'),
('Χαλάζι');

-- --------------------------------------------------------

--
-- Table structure for table `comments`
--

CREATE TABLE IF NOT EXISTS `comments` (
  `comment` text COLLATE utf8_bin NOT NULL,
  `report_id` int(20) NOT NULL,
  `comment_id` int(30) NOT NULL AUTO_INCREMENT,
  `timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `user_id` int(10) NOT NULL,
  `user_email` varchar(80) COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`comment_id`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 COLLATE=utf8_bin AUTO_INCREMENT=14 ;

--
-- Dumping data for table `comments`
--

INSERT INTO `comments` (`comment`, `report_id`, `comment_id`, `timestamp`, `user_id`, `user_email`) VALUES
('εχει σταλει γερανός', 22, 1, '2014-05-22 16:44:30', 4, 'dimitris@mono.gr'),
('εχει σταλεί όχημα κατάσβεσης', 58, 6, '2014-05-22 17:13:32', 7, 'eirini@ceid.com'),
('ele', 22, 5, '2014-05-22 17:08:59', 7, 'eirini@ceid.com'),
('μεγάλες ρωγμές ', 55, 7, '2014-05-22 17:52:48', 7, 'eirini@ceid.com'),
('τεστ', 66, 8, '2014-06-11 21:28:09', 0, ''),
('hjfv', 76, 9, '2014-06-13 21:30:07', 0, ''),
('χαχα', 0, 10, '2014-06-19 15:55:04', 7, 'eirini@ceid.com'),
('τρέχω!!', 79, 11, '2014-06-19 15:55:29', 7, 'eirini@ceid.com'),
('είναι οκ', 79, 12, '2014-06-19 15:59:17', 3, 'petros@ceid.com'),
('4 μετρα', 84, 13, '2014-06-28 14:38:30', 13, 'patata@ceid.com');

-- --------------------------------------------------------

--
-- Table structure for table `reports`
--

CREATE TABLE IF NOT EXISTS `reports` (
  `report_id` int(10) NOT NULL AUTO_INCREMENT,
  `category` varchar(50) COLLATE utf8_bin NOT NULL,
  `geolocation` varchar(80) COLLATE utf8_bin NOT NULL,
  `description` text COLLATE utf8_bin NOT NULL,
  `foto_1` varchar(80) COLLATE utf8_bin NOT NULL,
  `foto_2` varchar(80) COLLATE utf8_bin NOT NULL,
  `foto_3` varchar(80) COLLATE utf8_bin NOT NULL,
  `foto_4` varchar(80) COLLATE utf8_bin NOT NULL,
  `situation` varchar(50) COLLATE utf8_bin NOT NULL,
  `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `timefix` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `username` varchar(50) COLLATE utf8_bin NOT NULL,
  `sit_username` varchar(50) COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`report_id`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 COLLATE=utf8_bin AUTO_INCREMENT=95 ;

--
-- Dumping data for table `reports`
--

INSERT INTO `reports` (`report_id`, `category`, `geolocation`, `description`, `foto_1`, `foto_2`, `foto_3`, `foto_4`, `situation`, `time`, `timefix`, `username`, `sit_username`) VALUES
(94, 'Ακρίδες', '37.994, 23.75519', '', '', '', '', 'larisa.jpg', '1', '2014-06-28 20:10:20', '0000-00-00 00:00:00', 'eirini@ceid.com', ''),
(93, 'Βατράχια', '39.54747, 21.76117', 'πολλά πρασινα', '', '', '', '', '1', '2014-06-28 20:06:23', '0000-00-00 00:00:00', 'eirini@ceid.com', ''),
(92, 'Ακρίδες', '39.55488, 21.78589', 'πολλα πράσινα', '', '', '', '', '1', '2014-06-28 20:04:42', '0000-00-00 00:00:00', 'eirini@ceid.com', ''),
(91, 'Τσουνάμι', '39.2918, 23.97217', '7 καταστροφες', '1403956256386.jpg', '1403956294550.jpg', '', '', '0', '2014-06-28 14:52:24', '2014-06-28 19:21:02', 'patata@ceid.com', 'eirini'),
(90, 'Χαλάζι', '39.72831, 20.93994', '', '', '', '', '', '1', '2014-06-28 14:33:19', '0000-00-00 00:00:00', 'patata@ceid.com', ''),
(89, 'Τσουνάμι', '40.63063, 22.90649', '', '', '', '', '', '0', '2014-06-28 14:15:04', '2014-06-28 14:29:18', 'eirini@ceid.com', 'eirini'),
(78, 'Κατεδάφιση', '38.25557, 21.74551', 'Pire fwtia mia kardia', '1402681673989.jpg', '', '', '', '0', '2014-06-13 20:49:36', '2014-06-28 14:28:50', '', 'eirini'),
(81, 'Κατεδάφιση', '39.28329, 21.55518', '', '', '', '', '', '0', '2014-06-20 15:50:57', '2014-06-20 15:51:02', 'dimitris@mono.gr', 'dimitris'),
(77, 'Σεισμός', '38.23818, 22.11136', '4 ρίχτερ', '', '', '', '', '0', '2014-06-11 21:18:42', '2014-06-20 15:49:01', '', 'dimitris'),
(82, 'Φωτιά', '39.69926, 22.25555', 'μεγάλη φωτια', 'larisa.jpg', '', '', '', '1', '2014-06-26 18:06:49', '0000-00-00 00:00:00', 'eirini@ceid.com', ''),
(74, 'Φωτιές', '38.53098, 22.53662', '', '', '', '', '', '1', '2014-05-25 00:19:10', '0000-00-00 00:00:00', 'dimitris@mono.gr', ''),
(73, 'Πλημμύρα', '36.36822, 25.41504', '', '', '', '', '', '0', '2014-05-25 00:18:55', '2014-06-20 15:17:48', 'dimitris@mono.gr', 'dimitris'),
(72, 'Φωτιές', '40.01079, 23.52539', 'σε ξεναδοχεία', '', '', '', '', '1', '2014-05-25 00:18:24', '0000-00-00 00:00:00', 'dimitris@mono.gr', ''),
(87, 'Σεισμός', '36.8906, 27.29828', '', '', '', '', '', '0', '2014-06-28 13:57:56', '2014-06-28 14:38:21', 'maria@ceid.gr', 'patatas'),
(88, 'Πλημμύρα', '40.49083, 21.33545', '', '', '', '', '', '1', '2014-06-28 14:14:45', '0000-00-00 00:00:00', 'eirini@ceid.com', ''),
(70, 'Πετρελαιοκυλίδα', '39.48708, 24.82178', '3000 λίτρα', '', '', '', '', '0', '2014-05-25 00:17:26', '2014-06-28 17:16:20', 'dimitris@mono.gr', 'eirini'),
(69, 'Φωτιές', '36.82687, 21.74561', '43 στρέμματα ', '', '', '', '', '1', '2014-05-25 00:16:49', '0000-00-00 00:00:00', 'dimitris@mono.gr', ''),
(86, 'Φωτιά', '39.04479, 26.44409', '', '', '', '', '', '1', '2014-06-28 13:57:32', '0000-00-00 00:00:00', 'maria@ceid.gr', ''),
(67, 'Πλημμύρα', '40.63063, 21.57715', '2 μέτρα ύψος', '', '', '', '', '1', '2014-05-24 21:17:19', '0000-00-00 00:00:00', 'dimitris@mono.gr', ''),
(54, 'Φωτιές', '35.75181, 27.19357', '5 μποφόρ', '', '', '', '', '1', '2014-04-26 17:29:52', '0000-00-00 00:00:00', 'dimitris@mono.gr', ''),
(85, 'Τσουνάμι', '38.32011, 26.0321', '', '', '', '', '', '1', '2014-06-28 13:57:12', '0000-00-00 00:00:00', 'maria@ceid.gr', ''),
(84, 'Πετρελαιοκυλίδα', '37.07271, 26.09253', '', '', '', '', '', '0', '2014-06-28 13:56:46', '2014-06-28 14:38:18', 'maria@ceid.gr', 'patatas'),
(58, 'Φωτιές', '38.12159, 24.53522', 'aa', 'fire-02.jpg', '', '', '', '1', '2014-05-12 16:08:31', '0000-00-00 00:00:00', 'eirini', ''),
(59, 'Κατεδάφιση', '37.89721, 23.72858', 'στο αεροδρόμιο', '', '', '', '', '1', '2014-05-21 22:16:01', '2014-06-20 15:16:59', '', ''),
(60, 'Τσουνάμι', '36.96745, 22.69775', '5 μέτρα', '', '', '', '', '1', '2014-05-22 17:53:30', '0000-00-00 00:00:00', 'eirini', ''),
(83, 'Κατεδάφιση', '39.90974, 21.44531', '', '', '', '', '', '1', '2014-06-28 13:56:29', '0000-00-00 00:00:00', 'maria@ceid.gr', ''),
(61, 'Σεισμός', '39.36828, 20.63232', '3 ρίχτερ', '', '', '', '', '1', '2014-05-22 18:01:13', '0000-00-00 00:00:00', 'eirini@ceid.com', ''),
(80, 'Τσουνάμι', '39.98554, 25.40863', '3 μετρα', '', '', '', '', '0', '2014-06-20 15:42:27', '2014-06-20 15:42:40', 'dimitris@mono.gr', 'dimitris'),
(62, 'Φωτιές', '37.25194, 22.17243', 'έχει πολύ αέρα', '', '', '', '', '1', '2014-05-22 18:13:48', '0000-00-00 00:00:00', 'eirini@ceid.com', ''),
(63, 'Σεισμός', '40.16208, 25.15869', '6.5 ρίχτερ', 'seismos.jpg', '', '', '', '1', '2014-05-24 20:15:57', '0000-00-00 00:00:00', '', ''),
(64, 'Σεισμός', '38.1459, 21.51999', '7.3 ρίχτερ', 'seismos.jpg', '', '', '', '1', '2014-05-24 20:18:20', '0000-00-00 00:00:00', '', ''),
(65, 'Σεισμός', '39.52099, 19.9292', '6 ρίχτερ', 'seismos2.jpg', '', '', '', '1', '2014-05-24 20:19:31', '0000-00-00 00:00:00', '', ''),
(66, 'Τσουνάμι', '35.19177, 26.08154', '10 μέτρα', 'tsunami-japan.jpg', '', '', '', '0', '2014-05-24 20:21:50', '2014-06-28 14:12:48', '', 'eirini');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE IF NOT EXISTS `users` (
  `user_id` int(9) NOT NULL AUTO_INCREMENT,
  `username` varchar(20) COLLATE utf8_bin NOT NULL,
  `name` varchar(40) COLLATE utf8_bin NOT NULL,
  `email` varchar(80) COLLATE utf8_bin NOT NULL,
  `password` varchar(40) COLLATE utf8_bin NOT NULL,
  `telephone` bigint(20) NOT NULL,
  `is_admin` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`user_id`),
  UNIQUE KEY `email` (`email`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 COLLATE=utf8_bin AUTO_INCREMENT=15 ;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`user_id`, `username`, `name`, `email`, `password`, `telephone`, `is_admin`) VALUES
(1, '', 'Dimitris', 'dimi@d.gr', '1', 199, 0),
(2, '', 'Eirini', 'eiris@yahoo.ge', '1', 2132423233, 0),
(4, 'dimitris', 'Δημήτρης Μονοπάτης', 'dimitris@mono.gr', '1', 2100909801, 1),
(6, '', 'Tasos', 'tasos2@www.gr', '1', 2310123123, 0),
(8, '', 'Κυριάκος', 'kiriakos@ceid.gr', '1', 2093212948, 0),
(7, 'eirini', 'Ειρήνη ', 'eirini@ceid.com', '1', 2109000123, 1),
(3, '', 'Πέτρος', 'petros@ceid.com', '1', 2310776202, 0),
(9, '', 'Μαρία', 'maria@ceid.gr', '1', 2610123456, 0),
(10, '', 'Κώστας K', 'kostas@ceid.gr', '1', 2110145435, 0),
(13, 'patatas', 'Πατάτας', 'patata@ceid.com', '1', 2291089892, 1),
(14, '', 'jim', 'jim@hotmail.com', '1', 2693022456, 0);
