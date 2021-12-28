# Cinis-Inquisitio

Cinis Inquisitio is a simple Conway's Game of Life ash cleaning/analyzing program that works with Golly, written in C++ by Wish Lin

- This program can analyze the ash left behind by a soup or reaction, erase the 8 most common ash objects (block,blinker,beehive,loaf,boat,ship,tub and pond), and output a cleaned ash for further inspection.
- Besides cleaning ashes, the program also documents how many times those 8 objects appear, alongside some other data such as population and density.

**After downloading, please read "Usermanual.txt" for details on how to use this program**


# v0.9.1 note: 

This version of the program can deal with ashes with the size of about 5000x5000 without any problems. The theoretical upper limit is 63245x63245.

**Bug: For stable objects that consists of smaller still lives mentioned above, the still lives will be counted and deleted. Example: Any "xxx on dock" will have its still life part removed and only the dock left. 2 of the 3 states of pulsar contains blinkers and ships respectively, making the same bug occur.**

Depending on your computer's efficiency, the program may take a while to finish analyzing.

v0.9.1 Release date: 2021/12/28
