:- use_module(library(clpfd)).

not_member(_, []) :- !.
not_member(X, [Head | Tail]) :-
    X \= Head,
    not_member(X, Tail).

euler(Vars) :-
    Vars = [A, B, C, D, E, F, G, H, I, J],
    [A, B, C, D, E] ins 1..9,
    [F, G, H, I, J] ins 1..10,
    all_different(Vars),
    F + A + B #= G + B + C,
    F + A + B #= H + C + D,
    F + A + B #= I + D + E,
    F + A + B #= J + E + A,
    F #< G,
    F #< H,
    F #< I,
    F #< J,
    labeling([max(F), max(A), max(B), max(G), max(C), max(H), max(D), max(I), max(E), max(J)], Vars),
    write(F),
    write(A),
    write(B),
    write(G),
    write(B),
    write(C),
    write(H),
    write(C),
    write(D),
    write(I),
    write(D),
    write(E),
    write(J),
    write(E),
    write(A),
    !.

:- euler(_).
