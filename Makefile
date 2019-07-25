#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := filled_rectangle.cpp rectangle.cpp adxl345.cpp application.cpp snowman.cpp train.cpp house.cpp

# header files in this project
HEADERS := filled_rectangle.hpp rectangle.hpp images.hpp adxl345.hpp application.hpp snowman.hpp train.hpp house.hpp
# other places to look for files for this project
SEARCH  := 

# set RELATIVE to the next higher directory 
# and defer to the Makefile.* there
RELATIVE := ..
include $(RELATIVE)/Makefile.due