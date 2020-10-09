alter table rating rename column  is_up_vote to ratings;

alter table rating modify ratings int(11);