alter table vote rename to rating;

alter table product rename column  votes to average_rating;

alter table rating rename column  is_up_vote to ratings;