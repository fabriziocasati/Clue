# Clue Solver

**NOTA BENE. This project is a work in progress: the following description refers to how the program will work once completed.**

## Overview ##

*Clue Solver* is an is intended to be used during a Clue play to help the user play in the best way. More precisely, the user, by means of a GUI, is supposed to continously insert into *Clue Solver* the inquiries that are made during the inquiry phases of a play (i.e., insert which cards are searched by another player, which player shows him a card, etc.), so that *Clue Solver* can use this knowledge to continuously make deductions about the current play (e.g.: understand which cards are held by a certain adversary player, etc.); the results of these deduction are shown to the user, so that he can use this knowledge to play better during his turns (e.g.: make better inquiries, decide which room is more convient for him to reach, etc.).

*Clue Solver* does not allow to directly play Clue with a computer (or any other device): it only provides reasoning support to the user, therefore the players still need the board game to play.

A sketch of the game rules can be found on Wikipedia: <https://en.wikipedia.org/wiki/Cluedo>. It is assumed that the players use the rules of the classical version of the game, since at the moment *Clue Solver* does not support game variants.


## Reasons for creating *Clue Solver*##

There are already plenty of programs on the web with the same functionalities of *Clue Solver* for several devices (computers, tablets and smartphones), and some cases of homonymy may possibly exist. My *Clue Solver* doesn't have the aim of being an innovative program or a better version of an already esisting one, it is just meant as a free time activity to make some practice with the C++ language, the Qt framework, and so on.


## Notes ##

The official name of the software is *Clue Solver*, however, to avoid problems with the space character in the name during computations, the Qt project and the GitHub repository are named *Clue_Solver* (i.e., an underscore replaces the space).
