# Real-time-filtering
## Project Description
This project focuses on utilizing C++ and OpenCV to read, display, manipulate, and write images and videos. The main objectives include implementing functions to:
- Read images from a local file or video streams from a live camera.
- Display live video.
- Apply various filters and effects to the live video.
- Save images or videos.
- The project also involves getting familiar with OpenCV's built-in functions and understanding how to access and modify images by directly accessing pixels.

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

## Reflection
This project provided an opportunity to become familiar with C++ and OpenCV while gaining practical experience in image and video manipulation. It involved implementing various filters and effects, understanding pixel-level operations, and handling different image frame types. Additionally, it allowed for experimentation with different techniques to achieve desired results, such as adjusting brightness, applying filters, and saving video sequences with proper frame replication. Overall, the project enhanced understanding of computer vision concepts and improved proficiency in C++ programming and OpenCV usage.

### Acknowledgments
- OpenCV Tutorials: https://docs.opencv.org/4.5.1/index.html
- Learn OpenCV: https://learnopencv.com/read-write-and-display-a-video-using-opencv-cpp-python/
- How to use Chrono library: https://www.techiedelight.com/measure-elapsed-time-program-chrono-library/
- Change brightness using OpenCV: https://www.opencv-srf.com/2018/02/change-brightness-of-images-and-videos.html
