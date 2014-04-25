#clipb#

clipb is a clip board application meant to be used in a terminal eviornment.

It is currently only working on linux.

##Usage##
Save text to the clip board by piping to clipb with `clip -i`.
Example: `ls ~ | clip -i`

To read the data simply call the program `clipb`
Example: `clipb | grep "bash"`

###Install###
First compile the source with `g++ clipb.cpp -o clipb`

Then you can move the `clipb` file to a folder in the path such as `/usr/bin` to run it anywhere