(define (domain path_finidng)
  (:requirements :strips)
  (:types agent position)
  (:predicates 
    (inc ?a ?b - position)
    (dec ?a ?b - position)
    (at ?a - agent ?x ?y - position)
    (block ?x ?y)
    )