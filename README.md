# filler

Filler is a game, where two players / algorithm are fighting on a map.

A virtual machine organizes the game :

  * calls the players alternatively
  * give each a random piece
  
On each turn, the current player have to put his piece on the map, and try to bother the ennemy. To put a piece, the player have to write its coordinates in the "Y X\n" format on the standard input (stdin).

The game appears on the standard input.

The aim of the game is to put more pieces on the map than the ennemy.

# Usage

```
git clone https://github.com/kmieshko/filler.git
cd filler
make
./resources/filler_vm -f ./resources/maps/map0[0-2] -p1 ./resources/players/kmieshko.filler -p2 ./resources/players/[bot].filler | ./visual/visual 
```
*Notice*:
 * `bot` this is a bot, that given by 42 school. You can choose any bot.
 * `kmieshko.filler` this is my player. You can put any bot on this place, and see how battling two bots.
 * `-p1` and `-p2` this is flags, that show what player start the game (`p1` start first, `p2` start second).
 * `map0[0-2]` this is size of map (small -> `map00`, middle -> `map01`, big -> `map02`).

# Bonus

1. A visualizer made with the *MinilibX* helps us to understand what's happening.
2. Music in start of the game.
3. Color switching
4. Button `L` on keyboard run system command `leaks` and show memory leaks in program.
5. You can pause the game (press button `Space` on keyboard)

# Some Examples

<p align="center">
<img src="https://github.com/kmieshko/filler/blob/master/examples/filler_small.gif" width=600>
<img src="https://github.com/kmieshko/filler/raw/master/examples/filler.gif" width=600>
</p>

# Disclaimer

This project is written according to 42's "The Norm" which specifies special rules for code like less then 25 lines in each function, 85 symbols in line, forbidden most of libraries and functions that wasn't written by you, also "for", "switch case" and others are forbidden (you can read more at https://ncoden.fr/datas/42/norm.pdf)
