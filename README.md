# Real-time-filtering

This project contains two C++ programs, imgDisplay and vidDisplay, that implement different image and video filters.

# Getting Started

To run the imgDisplay program, place the imgDisplay.cpp and CMakeLists.txt files in the same folder and run the following commands:

     cmake .
     make
    ./imgDisplay <img path>
    


 
# Usage

# imgDisplay

To use the imgDisplay program, provide the path to an image file as a command line argument:

    ./imgDisplay image.jpg
  
after executing the vidDisplay program follwing are the keypressed i assigned
(if these keys are pressed second time it destroy the filter and keeps the live video)

    press 'q' to terminate the program
    press 'r' to rotate the image
    press 'd' to get dimentions

 
# vidDisplay

To run the vidDisplay program, place the vidDisplay.cpp, filters.cpp, and CMakeLists.txt files in the same folder and run the following commands:

    cmake .

KEEP THE FILTER.CPP AND VIDDISPLAY.CPP FILE IN THE SAME FOLDER


save below line to makefile in #target to generate assembly for a file#

     vid: vidDisplay.o filters.o
	$(CC) $^ -o $(BINDIR)/$@ $(LDFLAGS) $(LDLIBS)

after that run following command:

     make
    ./vidDisplay
   
When you run the vidDisplay program, a live video stream will be displayed. You can use the following keys to apply different filters:

    q: Terminate the program
    s: Save the current frame as an image file
    g: Apply a greyscale filter
    h: Apply an alternative greyscale filter
    b: Apply a blur filter
    x: Apply a Sobel x filter
    y: Apply a Sobel y filter
    m: Apply a gradient magnitude filter
    l: Apply a blur/quantize filter
    c: Apply a cartoon filter
    f: Apply a negative filter
    
  If you press any of these keys again, the filter will be removed and the live video stream will continue.
