CREATE DATABASE newdb;
USE newdb;


CREATE TABLE allBooks_tb (
  m_id int(10) NOT NULL,
  m_category varchar(100) DEFAULT 0,
  m_type varchar(100) DEFAULT 0,
  m_name varchar(100) NOT NULL DEFAULT 0,
  m_author varchar(100) NOT NULL DEFAULT 0,
  m_price varchar(100) NOT NULL DEFAULT 0,
  m_quantity varchar(100) NOT NULL DEFAULT 0
); 




INSERT INTO allBooks_tb (m_id, m_category, m_type, m_name, m_author, m_price, m_quantity) 
VALUES(1, 'Educational' , 'Computer Science', 'Let us C', 'yashwant kanetkar', 2, 14),
(2, 'Fiction', 'Fantasy', 'Alice in Wonderland', 'Lewis Carroll', '7', '7'),
(3, 'Non Fiction', 'Indian History', 'The Discovery of India', 'Jawaharlal Nehru', '10', '2'),
(5, 'Fiction', 'Realistic Fiction', 'The Fault in Our Stars', '	John Green', '3', '10'),
(6, 'Non Fiction', 'History', 'India of my dreams', 'Mahatma Gandhi', '8', '4'),
(7, 'Educational', 'Computer Science', 'Data Communications and Networking', 'Behrouz A. Forouzan', '9', '9'),
(8, 'Non Fiction', 'Science', 'A Brief History of Time', 'Stephen Hawking', '4', '5'),
(9, 'Non Fiction', 'Self Help', 'The 7 Habits of Highly Effective People', 'Stephen R. Covey', '1', '4'),
(10, 'Fiction', 'Fantasy', 'Harry Potter and the Philosophers Stone', 'J. K. Rowling', '12', '3');

CREATE TABLE allBooks_tb2 (
  m_id int(10) NOT NULL,
  m_category varchar(100) DEFAULT 0,
  m_type varchar(100) DEFAULT 0,
  m_name varchar(100) NOT NULL DEFAULT 0,
  m_author varchar(100) NOT NULL DEFAULT 0,
  m_price varchar(100) NOT NULL DEFAULT 0,
  m_quantity varchar(100) NOT NULL DEFAULT 0
); 

INSERT INTO allBooks_tb2 (m_id, m_category, m_type, m_name, m_author, m_price, m_quantity) 
VALUES(1, 'Educational' , 'Computer Science', 'Let us C', 'yashwant kanetkar', 2, 14),
(2, 'Fiction', 'Fantasy', 'Alice in Wonderland', 'Lewis Carroll', '7', '7'),
(3, 'Non Fiction', 'Indian History', 'The Discovery of India', 'Jawaharlal Nehru', '10', '2'),
(5, 'Fiction', 'Realistic Fiction', 'The Fault in Our Stars', '	John Green', '3', '12'),
(6, 'Non Fiction', 'History', 'India of my dreams', 'Mahatma Gandhi', '8', '5'),
(7, 'Educational', 'Computer Science', 'Data Communications and Networking', 'Behrouz A. Forouzan', '9', '10'),
(8, 'Non Fiction', 'Science', 'A Brief History of Time', 'Stephen Hawking', '4', '5'),
(9, 'Non Fiction', 'Self Help', 'The 7 Habits of Highly Effective People', 'Stephen R. Covey', '1', '4'),
(10, 'Fiction', 'Fantasy', 'Harry Potter and the Philosophers Stone', 'J. K. Rowling', '12', '3');


CREATE TABLE solditem_tb (
  m_id int(11) NOT NULL,
  m_category varchar(100) DEFAULT '0',
  m_type varchar(100) DEFAULT '0',
  m_name varchar(100) NOT NULL DEFAULT '0',
  m_author varchar(100) NOT NULL DEFAULT '0',
  m_price varchar(100) NOT NULL DEFAULT '0',
  m_quantity varchar(100) NOT NULL DEFAULT '0',
  m_issuedate date DEFAULT '0-0-0',
  m_duedate date DEFAULT '0-0-0'
);

INSERT INTO solditem_tb (m_id, m_category, m_type, m_name, m_author, m_price, m_quantity,m_issuedate,m_duedate) VALUES
(1, 'Fiction', 'Realistic Fiction', 'The Fault in Our Stars', '	John Green', '3', '1','0-0-0','0-0-0'),
(2, 'Non Fiction', 'History', 'India of my dreams', 'Mahatma Gandhi', '8', '1','0-0-0','0-0-0'),
(3, 'Fiction', 'Realistic Fiction', 'The Fault in Our Stars', '	John Green', '3', '1','0-0-0','0-0-0'),
(4, 'Educational', 'Computer Science', 'Data Communications and Networking', 'Behrouz A. Forouzan', '9', '1','0-0-0','0-0-0');


CREATE TABLE reader_details (
    r_id VARCHAR(10) NOT NULL,
    r_name VARCHAR(100) NOT NULL,
    r_password VARCHAR(8) NOT NULL
);

ALTER TABLE allBooks_tb
  ADD PRIMARY KEY (`m_id`);
  
  ALTER TABLE allBooks_tb2
  ADD PRIMARY KEY (`m_id`);
  
  ALTER TABLE solditem_tb
  ADD PRIMARY KEY (`m_id`);
  
  ALTER TABLE allBooks_tb
  MODIFY m_id int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;
  
  ALTER TABLE allBooks_tb2
  MODIFY m_id int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;
  
  ALTER TABLE solditem_tb
  MODIFY m_id int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
  
  
  

  

