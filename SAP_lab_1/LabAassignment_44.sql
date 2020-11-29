-----------------------Task A1-------------------------
create table customer (
    id int not null auto_increment primary key,
    name varchar(50)
);

insert into customer (name) values
    ('Leo Nardo'),
    ('Rafael'),
    ('Dona Telo'),
    ('Michel Angelo');

alter table rating add column customer_id int;
alter table rating add column timestamp datetime;


------------------------Task A2--------------------
create table employee (
    id int not null auto_increment primary key,
    name varchar(10)
);
insert into employee (name) values
    ('Albert Einstein'),
    ('Newton'),
    ('Tesla'),
    ('Farade');

create table invoice (
    id int not null auto_increment primary key,
    customer_id int,
    employee_id int,
    time datetime
);

create table sale (
    id int not null auto_increment primary key,
    invoice_id int,
    product_id int,
    unit_price int,
    count int
);


------------------------Task B1------------------------
select name
from product
order by product.average_rating desc
limit 3;


------------------------Task B1a and B2a------------------------
alter table category add column AverageRating float;
alter table category add column TotalSale int;
alter table product add column TotalSale int;
alter table sale add column DateTime datetime;
alter table sale add column SellerId int;
alter table sale add column CategoryId int;
alter table invoice add column TotalPrice float;
alter table employee add column TotalSale int;


------------------------Task B1b------------------------
drop procedure if exists add_rating;
delimiter //
create procedure add_rating(in product_id int, in rating_value int, in customer_id int)
begin
    insert into rating(product_id, value, customer_id, timestamp) values (product_id, rating_value, customer_id, NOW());
end;//
delimiter ;


------------------------Task B1c------------------------
drop procedure if exists calculate_product_average_rating;
delimiter //
create procedure calculate_product_average_rating(in product_id int)
begin
    select average_rating
    from product
    where product.id=product_id;
end;//
delimiter ;



------------------------Task B2------------------------
select category.name, count(count) as TotalSale
from sale join category
where sale.SellerId=1
and sale.CategoryId=category.id
group by sale.CategoryId;


------------------------Task B2b------------------------
drop procedure if exists get_sale_per_category;
delimiter //
create procedure get_sale_per_category(in employee_id int)
begin
    select *
    from sale
    where sale.SellerId=employee_id;
end;//
delimiter ;



------------------------Task B2c------------------------
drop procedure if exists set_product_category;
delimiter //
create procedure set_product_category(in product_id int, in category_id int)
begin
    update product
    set product.category_id= category_id
    where product.id=product_id;
end;//
delimiter ;



------------------------Task C1a------------------------
create table reporting_database_customer(
    id int auto_increment primary key ,
    name varchar(50)
);

create table reporting_database_category(
    id int auto_increment primary key ,
    name varchar(50)
);

create table reporting_database_product(
    id int auto_increment primary key,
    name varchar(50),
    reporting_database_category_id int
);

create table reporting_database_rating(
    id int auto_increment primary key,
    reporting_database_product_id int,
    reporting_database_rater_id int,
    value int,
    datetime datetime
);


------------------------Task C1b------------------------
drop procedure if exists get_top_3_products;
delimiter  //
create procedure get_top_3_products()
begin
    select name
    from
    (select reporting_database_product.name, avg(value) as averageRating
    from reporting_database_rating join reporting_database_product
    where reporting_database_rating.reporting_database_product_id= reporting_database_product.id
    group by reporting_database_product_id
    order by averageRating desc
    limit 3) as T;
end; //
delimiter ;



------------------------Task C1c------------------------
drop procedure if exists get_top_2_categories;
delimiter  //
create procedure get_top_2_categories()
begin
    select name from
    (select reporting_database_category.name, avg(value) as averageRating
    from reporting_database_rating join reporting_database_product join reporting_database_category
    where reporting_database_rating.reporting_database_product_id= reporting_database_product.id
    and reporting_database_product.reporting_database_category_id= reporting_database_category.id
    group by reporting_database_category_id
    order by averageRating desc
    limit 2) as T;
end; //
delimiter ;



------------------------Task C1d------------------------
drop procedure if exists get_frequent_rater;
delimiter  //
create procedure get_frequent_rater()
begin
    select name from
    (select reporting_database_customer.name, count(reporting_database_rater_id) as totalRate
    from reporting_database_customer join reporting_database_rating
    where reporting_database_customer.id= reporting_database_rating.reporting_database_rater_id
    group by reporting_database_rater_id
    order by totalRate desc
    limit 1)as T;
end; //
delimiter ;



------------------------Task C1e------------------------
drop procedure if exists get_top_product_by_duration;
delimiter  //
create procedure get_top_product_by_duration(in start_date date, in end_date date)
begin
    select name from
    (select reporting_database_product.name, avg(reporting_database_rating.value) as averageRating
    from reporting_database_product join reporting_database_rating
    where reporting_database_product_id= reporting_database_product.id
    and date(datetime) between start_date and end_date
    group by reporting_database_product_id
    order by averageRating desc
    limit 1) as T;
end; //
delimiter ;



------------------------Task C1f------------------------
drop procedure if exists get_top_product_by_category;
delimiter  //
create procedure get_top_product_by_category(in category_id int)
begin
    select name from
    (select reporting_database_product.name, avg(reporting_database_rating.value) as averageValue
    from reporting_database_product join reporting_database_rating join reporting_database_category
    where reporting_database_product_id=reporting_database_product.id
    and reporting_database_category.id= reporting_database_category_id
    and reporting_database_category_id= category_id
    group by reporting_database_product_id
    order by averageValue desc
    limit 1) as T;
end; //
delimiter ;



------------------------Task C1g------------------------
drop procedure if exists populate_reporting_db;
delimiter  //
create procedure populate_reporting_db()
begin
    insert ignore into reporting_database_product(name, reporting_database_category_id)
    select name,category_id
    from product;
    insert ignore into reporting_database_category(name)
    select name
    from category;
    insert ignore into reporting_database_customer(name)
    select name
    from customer;
    insert ignore into reporting_database_rating(reporting_database_product_id, reporting_database_rater_id, value, datetime)
    select product_id, customer_id, value, timestamp
    from rating;
end; //
delimiter ;
call populate_reporting_db();