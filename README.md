# find-largest-subsquare
Implementation of the algorithm to find the largest square area in a 2D array full of obstacles

Input should be in a text file. The first line has four items:
[number of lines on the map][symbol for an empty space][symbol for an obstacle][symbol for the output square]
Each line afterward should be of width [number of lines] and only include obstacle or empty-space symbols.

Use the "perl map generator" to generate example maps. 

* make
* call ./create_map.pl [width][height][density] > map
    here, density should be a number between 0 and widht x height.
* ./bsq map

Created with help from Alex Sosnov in October 2016
