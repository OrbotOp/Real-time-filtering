//Program for creating diffrent filters(functions)
//Author: HRITHIK KANOJE
//CLASS: CS5330 Pattern Recog & computer vision
//Prof: Bruce maxwell
//Project 1:Real-time filtering

#include "opencv2/highgui/highgui.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include<cstdio>
#include<cmath>


using namespace cv;
using namespace std;


int greyscale(cv::Mat &src, cv::Mat &dst){
         //dst = cv::Mat::zeros(src.size(), src.type());        
                
          for(int i=0; i<src.cols ; i++){
          for(int j=0; j<src.rows ; j++)
          {
           Vec3b color1= src.at<Vec3b>(Point(i,j));
           Vec3b color2=(color1.val[0]+color1.val[1]+color1.val[2])/3;     //taking the average of R G B      
           dst.at<uchar>(Point(i,j)) =  color2[0];                         
           }
           }
           
        
        return (0);
}


int blur5x5(cv::Mat& src, cv::Mat& dst)
{
    dst = cv::Mat::zeros(src.size(), src.type());

    cv::Mat temp = cv::Mat::zeros(src.size(), src.type());

    // multiplying pixels with kernel [1 2 4 2 1] horizontally 
    
    for (int i = 0; i < src.rows; i++) {
        for (int j = 0; j < src.cols; j++) {
            for (int k = 0; k < src.channels(); k++) {                            
                int val = 0;                 
                val += src.at<cv::Vec3b>(i, j)[k] * 1;                         
                val += src.at<cv::Vec3b>(i, std::max(j-1,0))[k] * 2;
                val += src.at<cv::Vec3b>(i, std::max(j-2,0))[k] * 4;
                val += src.at<cv::Vec3b>(i, std::min(j+1,src.cols-1))[k] * 2;
                val += src.at<cv::Vec3b>(i, std::min(j+2,src.cols-1))[k] * 1;
                temp.at<cv::Vec3b>(i, j)[k] = cv::saturate_cast<uchar>(val/10);
            }
        }
    }

    // multiplying pixels with kernel [1 2 4 2 1] vertically
    
    for (int i = 0; i < src.rows; i++) {
        for (int j = 0; j < src.cols; j++) {
            for (int k = 0; k < src.channels(); k++) {
                int val = 0;
                val += temp.at<cv::Vec3b>(i, j)[k] * 1;
                val += temp.at<cv::Vec3b>(std::max(i-1,0), j)[k] * 2;     // multiplying pixels with kernel [1 2 4 2 1]
                val += temp.at<cv::Vec3b>(std::max(i-2,0), j)[k] * 4;
                val += temp.at<cv::Vec3b>(std::min(i+1,src.rows-1), j)[k] * 2;
                val += temp.at<cv::Vec3b>(std::min(i+2,src.rows-1), j)[k] * 1;
                dst.at<cv::Vec3b>(i, j)[k] = cv::saturate_cast<uchar>(val/10);
            }
        }
    }

    return(0);
}
    
int sobelX3x3(cv::Mat &src, cv::Mat &dst){

    dst = cv::Mat::zeros(src.size(), CV_16SC3);

    for(int i=1;i<src.rows-1;i++) {
   
    // src pointer
   
    cv::Vec3b *rptrm1 = src.ptr<cv::Vec3b>(i-1);
    cv::Vec3b *rptr = src.ptr<cv::Vec3b>(i);
    cv::Vec3b *rptrp1 = src.ptr<cv::Vec3b>(i+1);
   
    // destination pointer
   
    cv::Vec3s *dptr = dst.ptr<cv::Vec3s>(i);
   
    // for each column
    for(int j=1;j<src.cols-1;j++) {
    
       // for each color channel
      for(int c=0;c<3;c++) {
       dptr[j][c] = (-1 * rptrm1[j-1][c] + 1 * rptrm1[j+1][c] +
                     -2*rptr[j-1][c] + 2*rptr[j+1][c] +
                     -1 * rptrp1[j-1][c] + 1*rptrp1[j+1][c]) / 4;
      
    
      }
    }
  }
   
    return(0);
}

int sobelY3x3(cv::Mat &src, cv::Mat &dst){

    dst = cv::Mat::zeros(src.size(), CV_16SC3);
   
    for(int i=1;i<src.rows-1;i++) {
    
    // src pointer
    
    cv::Vec3b *rptrm1 = src.ptr<cv::Vec3b>(i-1);
    cv::Vec3b *rptr = src.ptr<cv::Vec3b>(i);
    cv::Vec3b *rptrp1 = src.ptr<cv::Vec3b>(i+1);
    
    // destination pointer
    
    cv::Vec3s *dptr = dst.ptr<cv::Vec3s>(i);
    
     // for each column
    
     for(int j=1;j<src.cols-1;j++) {
     
  // for each color channel
 
      for(int c=0;c<3;c++) {
       dptr[j][c] = (1 * rptrm1[j-1][c] +2 * rptrm1[j+1][c]+ 1 * rptrm1[j+1][c] +
                    -1 * rptrp1[j-1][c] + -2*rptrp1[j+1][c] + -1*rptrp1[j+1][c]) / 4;
      
       }
    }
  }
    
    return(0);
}

int magnitude(cv::Mat &sx,cv::Mat &sy, cv::Mat &dst){
    
    dst = cv::Mat::zeros(sx.size(), CV_16SC3);

    for(int i=0;i<sx.rows;i++){
        cv::Vec3s *ptr1 = sx.ptr<cv::Vec3s>(i);
        cv::Vec3s *ptr2 = sy.ptr<cv::Vec3s>(i);

        cv::Vec3s *fptr = dst.ptr<cv::Vec3s>(i);
        for(int j=0;j<sx.rows;j++){
            for(int c=0;c<3;c++){
                fptr[j][c] = sqrt(pow(ptr1[j][c],2)+pow(ptr2[j][c],2));  //Applying Eucliden distance for magnitude 
            }
         }   
    }
  

  return(0);
}

int blurQuantize(cv::Mat &src, cv::Mat &dst, int levels){
   
   dst = cv::Mat::zeros(src.size(),src.type());

   int b = 255/levels;                                    //bucket list for level 

   
   for(int i=0;i<src.rows;i++){
    for(int j=0;j<src.cols;j++){
        for(int k=0;k<3;k++){
            int x = src.at<Vec3b>(i,j)[k];              //storing values in x and further
            int xt = x/b;
            int xf = xt*b;

            dst.at<Vec3b>(i,j)[k] = saturate_cast<uchar>(xf);
        }

        
    }        
    
    }

    return(0);
}

int cartoon(cv::Mat &src, cv::Mat &dst, int levels, int magThreshold){
    
    dst = cv::Mat::zeros(src.size(),src.type());
    cv::Mat frame,sobelx,sobely;
    cv:: Mat mag;
    cv:: Mat b1,quant;


    sobelX3x3(src,sobelx);
    sobelY3x3(src,sobely);
    magnitude(sobelx,sobely,mag);
    convertScaleAbs(mag,mag);
    blur5x5(src,b1);
    blurQuantize(b1,quant,10);

    for(int i=0;i<src.rows;i++){
      for(int j=0;j<src.cols;j++){
                for(int k=0; k<3;k++){

                                                  
                if(mag.at<Vec3b>(i,j)[k] > magThreshold){   //comparing magnitude value to threshold and changing value in blurquantize to generate cartoon
                   quant.at<Vec3b>(i,j)[k] =0;
               }
                
        }
        
        }
        
        }
     
    dst = quant;
    return(0);
}

int invert(cv::Mat &src, cv::Mat &dst){ 
    dst = cv::Mat::zeros(src.size(),src.type());
    for (int i = 0; i < src.rows; i++) {
        for (int j = 0; j < src.cols; j++) {
            for(int k=0;k<3;k++){


            dst.at<cv::Vec3b>(i, j)[k] = 255 - src.at<cv::Vec3b>(i, j)[k]; //by subtracting each pixel values from 255 give the nagative of the img
            }
        }
    }    
    

    return (0);
}

