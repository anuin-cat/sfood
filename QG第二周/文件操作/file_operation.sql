/*
SQLyog Trial v13.1.5  (64 bit)
MySQL - 5.6.43-log : Database - file_operation
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
CREATE DATABASE /*!32312 IF NOT EXISTS*/`file_operation` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci */;

USE `file_operation`;

/*Table structure for table `instruct` */

DROP TABLE IF EXISTS `instruct`;

CREATE TABLE `instruct` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `content` varchar(64) COLLATE utf8mb4_unicode_ci NOT NULL,
  `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  KEY `id` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=508 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

/*Data for the table `instruct` */

insert  into `instruct`(`id`,`content`,`time`) values 
(31,'D:s.txt','2020-04-07 14:10:37'),
(32,'1','2020-04-07 14:10:37'),
(33,'吃饱就溜','2020-04-07 14:10:37'),
(34,'D:s.txt','2020-04-07 14:11:11'),
(35,'1','2020-04-07 14:11:11'),
(36,'吃饱就溜','2020-04-07 14:11:11'),
(496,'D:s.txt','2020-04-07 14:14:05'),
(497,'100','2020-04-07 14:14:05'),
(498,'吃饱就溜名么','2020-04-07 14:14:05'),
(499,'D:s.txt','2020-04-07 14:14:28'),
(500,'100','2020-04-07 14:14:28'),
(501,'吃饱就溜名么','2020-04-07 14:14:28'),
(502,'D:s.txt','2020-04-07 14:14:34'),
(503,'100','2020-04-07 14:14:34'),
(504,'吃饱就溜名么','2020-04-07 14:14:34'),
(505,'D:s.txt','2020-04-07 14:15:11'),
(506,'1','2020-04-07 14:15:11'),
(507,'吃饱就溜','2020-04-07 14:15:11');

/*Table structure for table `time` */

DROP TABLE IF EXISTS `time`;

CREATE TABLE `time` (
  `id` int(11) NOT NULL,
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

/*Data for the table `time` */

insert  into `time`(`id`,`date`) values 
(1,'2020-04-07 00:00:00'),
(2,'2020-04-07 13:53:53');

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
