# Real-time-filtering
//Program for creating diffrent filters(functions)
//Author: HRITHIK KANOJE

I worked on UBUNTU os with Make,terminal and subline editor.

-------------------------------------------------------------------------------------------

I have created two cpp file imgDisplay and vidDisplay with diffrent rule file in order to run the code first place imgDisplay and CMake file in same folder and run following comand

~ cmake .
~ make

by doing this it will create executable file which can be executed by typing following comand

~ ./imgDisplay image.jpg(file path) 


after executing the vidDisplay program follwing are the keypressed i assigned
(if these keys are pressed second time it destroy the filter and keeps the live video)

press 'q' to terminate the program
press 'r' to rotate the image
press 'd' to get dimentions

-----------------------------------------------------------------------------------------------

KEEP THE FILTER.CPP AND VIDDISPLAY.CPP FILE IN THE SAME FOLDER

and run same command for creating executable file (vidDisplay) and to execute executable file run follwing command

save below line to makefile in #target to generate assembly for a file#

vid: vidDisplay.o filters.o
	$(CC) $^ -o $(BINDIR)/$@ $(LDFLAGS) $(LDLIBS)

after that run following command
~ make

~ ./vidDisplay

after executing the vidDisplay program follwing are the keypressed i assigned
(if these keys are pressed second time it destroy the filter and keeps the live video)

press 'q' for to terminate the program
press 's' for saving the image
press 'g' for greyscale
press 'h' for alternative greyscale filter
press 'b' for blur filter
press 'x' for sobel x
press 'y' for sobel y
press 'm' for gradiant magnitude
press 'l' for blur/quantize filter
press 'c' for cartoon filter
press 'f' for negative filter 
