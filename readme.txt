#################################################################
# PROJECT - CLASSIFICATION OF FRUITS USING FEED FORWARD NETWORK #
#################################################################


EXPLANATION OF CONCEPTS INVOLVED IN DESIGNING THE APPLICATION

#############################################################################################################################################################################################################
#  -Fruits considered for classification are apple,papaya,orange,kiwi,pear,lemon,mango and strawberry (8 fruits in total).No other fruits can be detected by this application.
#  -The image processing algorithm works by using the concept of feature scaling. Features such as shape and color which are extracted from the image processing algorithm are given as initial input to  #   the neural network for both training and testing algorithm.
#  -Feature extraction is faster and flexible compared to traditional pixel matching method and can be applied on image of any number of pixels and also doesn't require a huge dataset. 
#  -The training algorithm uses only these 8 images (named 1.jpg to 8.jpg) to train the algorithm(activating input units). Features of these images are already extracted and given in the form of numbers #   to the training algorithm.No other set of images can be given as training dataset.
#  -Whereas , image input to testing algorithm can be any fruit which has similar features to one of the image used for training or one among the 8 images itself.
#  -Feed forward model is less accurate compared to the later models such as back propogation model. Therefore , a slight change or deviation from the expected color and shape may yield bad results.
#############################################################################################################################################################################################################


PLATFORM INFORMATION and PROGRAM EXECUTION INFORMATION

#############################################################################################################################################################################################################
#  -This application has been tested on ubuntu 18.04 LTS terminal with cc compiler(for running c program) and python 2.7.17 version installed. Python version 2.7.17 must be installed to support all       #   in-built libraries used.  
#  -It also requires the python libraries - numpy , cv2 , subprocess , PIL , imageTk , Tkinter and tkFileDialog to be pre-installed in the terminal to handle both front-end and back-end operations.
#  -Run train.py for training the algorithm by using the features of 8 fruits and classifying them. Number of epoch and learning rate can be set through the user interface after running train.py
#  -Run test.py to identify the fruit by giving the fruit image as input.for accurate results , use one of the fruit image used for training the data.
#  -Both train.py and test.py runs c programs 'feature.c' , 'color.c' and 'testing.c' implicitly.Therefore , it is necessary for all 5 program files (train.py , test.py , color.c , feature.c and          #   testing.c) to be present in the same folder.
#  -Image used for testing can be anywhere in the system.
#  -Image can be of any size , dimension and format.The image processing algorithm automatically reduces the image to required format. As long as the testing image is similar to one of the trained       #   images , it gives a positive result.
#  -The application creates 'train.txt' , 'training.txt' and 'info.txt' log files automatically to store the trained weights and input units related to the neural network.
#############################################################################################################################################################################################################


TERMINAL COMMANDS TO RUN THE PROGRAMS - 

1.'python train.py'
2.'python test.py'
