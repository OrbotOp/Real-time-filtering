// Main Program for displaying diffrent filters(functions) when user presses diffrent keys.
//Author: HRITHIK KANOJE
//CLASS: CS5330 Pattern Recog & computer vision
//Prof: Bruce maxwell
//Project 1:Real-time filtering

#include "opencv2/highgui/highgui.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <stdio.h>
#include "filters.cpp"



using namespace cv;
using namespace std;
int main(int argc, char *argv[]) {
        cv::VideoCapture *capdev;

        // open the video device for video capture
        capdev = new cv::VideoCapture(0);
        if( !capdev->isOpened() ) {
                printf("Unable to open video device\n");
                return(-1);
        }

        // get some height and width  of the image
        cv::Size refS( (int) capdev->get(cv::CAP_PROP_FRAME_WIDTH ),
                       (int) capdev->get(cv::CAP_PROP_FRAME_HEIGHT));
        printf("Expected size: %d %d\n", refS.width, refS.height);

        cv::namedWindow("Video", 1); // identifies a window
        cv::Mat frame,temp;               
        cv::Mat grey;
        cv::Mat blur;                 
        cv::Mat sobelx;               //creating empty matrices
        cv::Mat sobely;
        cv::Mat mag;
        cv::Mat quant;
        cv::Mat b1;
        cv::Mat car;
        cv::Mat ig,f1;

        
        for(;;) {
                *capdev >> frame; // get a new frame from the camera and run it as a stream
                  if( frame.empty() ) {         //checking if frame is empty or not
                  printf("frame is empty\n");
                  break;
                 }  
                
                
                cv::imshow("Video", frame);

                char key = cv::waitKey(10); // see if there is a waiting keystroke
                if( key == 'q') 
                    break;
   
                if(key == 'g'){
                  for(;;){
                  *capdev >> frame;
                  cvtColor(frame,grey,COLOR_RGB2GRAY,1);  //converting to greyscale using in-built function
                  
                  namedWindow("Gray scale", 1); 
                  imshow("Gray scale",grey);
                  char dk1 = waitKey(10);
                  if (dk1 == 'g'){                       //destroy key to destroy all windows and return back to main stream
                    destroyAllWindows();
                  	break; 
                 }
                 }

                }

                if (key =='s'){
                     *capdev >> frame; 
                      
                      cv::imwrite( "Image.jpg", frame);
                      std::cout<<"Image saved.!";
    
                      namedWindow("saved image",1);
                      imshow("saved image",frame);
                  char ddk=waitKey(0);
                  if(ddk=='s'){
                    destroyAllWindows();
                    break;
                  }
                }
                Mat alt_grey = cv::Mat::zeros(frame.rows,frame.cols, CV_8UC1);
                if(key == 'h'){
                    for(;;){
                            *capdev>>frame;
                             greyscale(frame, alt_grey);              //converting to greyscale with self-created function
                             namedWindow("Alternative Grayscale", 1); 
                             imshow("Alternative Grayscale", alt_grey); 
                            
                            char dk2 = waitKey(10);             
                            if (dk2 == 'h'){
                                 destroyAllWindows();
                                 break;
                                }       
                        }          

                }
               
              
              if( key == 'b'){
               
                 for(;;){
                 *capdev>> frame;
               
                blur5x5(frame,blur);                  //bluring the image 
                namedWindow("Blur",1);
                imshow("Blur",blur);                
                char dk3= waitKey(10);
                if (dk3=='b'){
                    destroyAllWindows();
                    break;
                }
                
                
                }
              }

              if( key == 'x'){
               
               for(;;){
               *capdev>> frame;
               
                sobelX3x3(frame,sobelx);
                convertScaleAbs(sobelx,sobelx);      //sobelx
                namedWindow("Sobel_X img",1);
                imshow("Sobel_X img",sobelx);
                
                 
                char dk4= waitKey(10);
                if (dk4=='x'){
                    destroyAllWindows();
                    break;
                }
                
                
                }
              }

              if( key == 'y'){
               
                for(;;){
                *capdev>> frame;
               
                sobelY3x3(frame,sobely);              //sobely
                convertScaleAbs(sobely,sobely);
                namedWindow("Sobel_Y img",1);
                imshow("Sobel_Y img",sobely);
                
                 
                char dk5= waitKey(10);
                if (dk5=='y'){
                    destroyAllWindows();
                    break;
                }
                
                 }
              }
              
              if( key == 'm'){
               
                for(;;){
                *capdev>> frame;
                
                sobelX3x3(frame,sobelx);
                sobelY3x3(frame,sobely);
                magnitude(sobelx,sobely,mag);   //magnitude 
                convertScaleAbs(mag,mag);
                namedWindow("mag img",1);
                imshow("mag img",mag);
                
                 
                char dk6= waitKey(10);
                if (dk6=='m'){
                    destroyAllWindows();
                    break;
                }
                
                 }
              }

              if( key == 'l'){
               
                for(;;){
                *capdev>> frame;
                
                blur5x5(frame,b1);
                blurQuantize(b1,quant,10);       //blur quantize with level=10
                namedWindow("quant img",1);
                imshow("quant img",quant);
                
                 
                char dk7= waitKey(10);
                if (dk7=='l'){
                    destroyAllWindows();
                    break;
                }
                
                  }
               }

               if( key == 'c'){
               
                for(;;){
                *capdev>> frame;
                
                                
                cartoon(frame,car,10,15);      // catroonization with level = 10, threshold = 15
                namedWindow("cartoon img",1);
                imshow("cartoon img",car);
                
                 
                char dk8= waitKey(10);
                if (dk8=='c'){
                   destroyAllWindows();
                   break;
                }
                }
                
               }
                
                if( key == 'f'){
               
                for(;;){
                *capdev>> frame;
                
                invert(frame,ig);                // negative filter (not in-built)
                
                namedWindow("inverted img",1);
                imshow("inverted img",ig);
                 
                char dk9= waitKey(10);
                if (dk9=='f'){
                   destroyAllWindows();
                   break;
                }
                }
                
               }
}
        delete capdev;
        return(0);

}
