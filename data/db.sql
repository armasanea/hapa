create database HATest;
use HATest;

create table if not exists Rooms(
RoomName nvarchar(20) not null,
Description nvarchar(255),
primary key (RoomName)
);

create table if not exists Temperature(
Id bigint not null auto_increment,
RoomName nvarchar(20) not null,
TempF int not null, # temperature in Fahrenheit degrees
DateTime datetime default null,
primary key (Id),
foreign key (RoomName) references Rooms(RoomName)
);

# need mysql 5.6 for default on datetime, for now use trigger
drop trigger if exists Temperature_DateTime_Default;
delimiter $$
CREATE TRIGGER Temperature_DateTime_Default
 BEFORE INSERT ON `Temperature` FOR EACH ROW
 BEGIN
    IF NEW.DateTime IS NULL THEN
       SET NEW.DateTime = NOW();
    END IF;
end $$

delimiter ;

# For now we don't need this index
# create index Temperature_DateTime ON Temperature (DateTime)
