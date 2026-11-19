# Plan: The Old House

## Story
its late at night and you are standing outside an old house
the front door is locked but there might be another way in
if you look around the kitchen you might find a way to hide until morning
or you can just give up and go home

## Story map
main_menu
  1 -> choice_front_door
         1 -> choice_back_door
         2 -> choice_go_home
  2 -> choice_back_door
         1 -> search_the_kitchen
                1 -> hide_in_the_pantry
                2 -> choice_go_home
         2 -> choice_go_home
  3 -> choice_go_home
  4 -> quit

## Functions
- choice_front_door    (starter, already done)
- choice_back_door     (starter, I fill it in)
- choice_go_home       (starter, ending 1)
- search_the_kitchen   (new)
- hide_in_the_pantry   (new, ending 2)