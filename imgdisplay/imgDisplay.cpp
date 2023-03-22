#include <opencv2/opencv.hpp>
#include <stdio.h>

using namespace cv;

int main(int argc, char** argv)
{
    if(argc !=2)
    {
    	printf("usage: DisplayImage.out <Image_path>\n");
    	return -1;
    }
Mat image;
image = imread(argv[1],1);
if(!image.data)                                       //To check if given input is image or not
{
	printf("No image data \n");
	return -1;
}


while(true){
namedWindow("Display Image", 1);
imshow("Display Image", image);
char key = cv::waitKey(); 
 if (key == 'd')                                      //To Get the Dimentions of the images
 {
      cv::Size sz = image.size();
      int imageWidth = sz.width;
      int imageHeight = sz.height;
      
     std::cout<<"Width: "<<imageWidth;
     std::cout<<" Height: "<<imageHeight;
     std::cout<<" Key Pressed : "<<key<<std::endl;
  }
 if (key == 'r')
  {
     cv::rotate(image, image,cv::ROTATE_90_CLOCKWISE); //To Rotate the image
     std::cout<<"Key pressed : "<<key<<std::endl;
     
  }
  if (key == 'q')                                     //To Quit the image
  {
    std::cout<<"Key Pressed: "<<key<<std::endl;
    break; 
  }
 
}

return 0;
}

