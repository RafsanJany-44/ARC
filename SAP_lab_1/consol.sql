DROP DATABASE kids_shop;
create database kids_shop;
use kids_shop;

create table category (
    id int not null auto_increment primary key,
    name varchar(100)
);

create table product (
    id int not null auto_increment primary key,
    name varchar(100),
    category_id int not null,
    votes int not null default 0
);

create table vote (
    id int not null auto_increment primary key,
    product_id int not null,
    is_up_vote bit
);

delimiter //
create procedure recalculate_product_votes()
begin
    update product p
        set votes =
            (select count(*) from vote where product_id = p.id and is_up_vote = true)
            - (select count(*) from vote where product_id = p.id and is_up_vote = false)
    where 1 = 1;
end;//
delimiter ;

use kids_shop;

insert into category (name) values
    ('toys'),
    ('cloths'),
    ('diaper');

insert into product (name, category_id) values
    ('light ball', 1),
    ('blocks', 1),
    ('cool red shirt', 2),
    ('long blue skirt', 2),
    ('nice green pants', 2),
    ('kids comfi', 3);

insert into vote(product_id, is_up_vote) values
    (1, true),
    (1, true),
    (1, false),
    (2, false),
    (2, false),
    (3, true),
    (3, true),
    (5, false),
    (5, true),
    (5, true),
    (5, true);

call recalculate_product_votes();


#--------------------------Task Starts------------------------


ALTER TABLE vote RENAME TO rating;
ALTER TABLE product RENAME COLUMN  votes TO average_rating;



ALTER TABLE rating
ADD COLUMN ratings int(1) AFTER is_up_vote;

UPDATE rating
SET ratings = 1
WHERE is_up_vote = false;

UPDATE rating
SET ratings = 5
WHERE is_up_vote = true;

ALTER TABLE rating DROP COLUMN is_up_vote;


SELECT AVG (ratings) from rating where product_id = 3;


delimiter //
CREATE PROCEDURE calculate_avg_rating()
BEGIN 
    DECLARE avaragr_rate INT;
    DECLARE i INT;
    SET i = 1;
    WHILE i<=6
    DO
    SELECT AVG (ratings) from rating where product_id = i into avaragr_rate;
    IF avaragr_rate IS NULL THEN
        UPDATE product SET average_rating = 0 WHERE id=i;
    ELSE
        UPDATE product SET average_rating = avaragr_rate WHERE id=i;
    END IF ;
    SET i=i+1;
    END WHILE;
END;//
delimiter ;

CALL calculate_avg_rating();