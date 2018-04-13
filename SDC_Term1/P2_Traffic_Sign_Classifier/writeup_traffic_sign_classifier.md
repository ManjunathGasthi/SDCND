# **Traffic Sign Recognition** 

## Writeup

### This write up explain about the work I did for project 2 of Udacity’s self-driving car project, classifying German traffic signs using deep learning. It is very important for a self-driving car to read traffic signs and interpret them to understand the traffic rules. Deep learning neural networks or convolutional neural networks have emerged as powerful image classifiers in the past decade. Primarily due to advances in GPU technology for fast computing.

---

**Build a Traffic Sign Recognition Project**

The goals / steps of this project are the following:
* Load the data set (see below for links to the project data set)
* Explore, summarize and visualize the data set
* Design, train and test a model architecture
* Use the model to make predictions on new images
* Analyze the softmax probabilities of the new images
* Summarize the results with a written report

[//]: # (Image References)

[image1]: ./net_images/2_50kms.jpg "2_50kms"
[image2]: ./net_images/12_priority_road.jpg  "12_priority_road"
[image3]: ./net_images/23_slippery-road.jpg "23_slippery-road"
[image4]: ./net_images/25_roadwork.jpg "25_roadwork"
[image5]: ./net_images/14_Stop_Sign.jpg "14_Stop_Sign"
[image6]: ./examples/grayscale.jpg "Grayscaling"
[image7]: ./examples/image11.jpg "dataset"

---
### Writeup / README

#### 1. Provide a Writeup / README that includes all the rubric points and how you addressed each one. You can submit your writeup as markdown or pdf. You can use this template as a guide for writing the report. The submission includes the project code.

You're reading it! and here is a link to my [project code](https://github.com/udacity/CarND-Traffic-Sign-Classifier-Project/blob/master/Traffic_Sign_Classifier.ipynb)

### Data Set Summary & Exploration

#### 1. Provide a basic summary of the data set. In the code, the analysis should be done using python, numpy and/or pandas methods rather than hardcoding results manually.

I used the pandas library to calculate summary statistics of the traffic
signs data set:

* The size of training set is 34799
* The size of the validation set is 4410
* The size of test set is 12630
* The shape of a traffic sign image is (32, 32, 3)
* The number of unique classes/labels in the data set is 43

#### 2. Include an exploratory visualization of the dataset.

Here is an exploratory visualization of the data set. listed one random image for one group in dataset.

![alt text][image1]

### Design and Test a Model Architecture

#### 1. Describe how you preprocessed the image data. What techniques were chosen and why did you choose these techniques? Consider including images showing the output of each preprocessing technique. Pre-processing refers to techniques such as converting to grayscale, normalization, etc. (OPTIONAL: As described in the "Stand Out Suggestions" part of the rubric, if you generated additional data for training, describe why you decided to generate additional data, how you generated the data, and provide example images of the additional data. Then describe the characteristics of the augmented training set like number of images in the set, number of images for each class, etc.)

As a first step, I decided to convert the images to grayscale because as suggested in the sessions there will be no add-ons 
by using RGB image and it will be easy to normalize.

Here is an example of a traffic sign image before and after grayscaling.

![alt text][image6]


#### 2. Describe what your final model architecture looks like including model type, layers, layer sizes, connectivity, etc.) Consider including a diagram and/or table describing the final model.

My final model consisted of the following layers:

| Layer         		|     Description	        					| 
|:---------------------:|:---------------------------------------------:| 
| Input         		| 32x32x1 Gray image   							| 
| Convolution 5x5     	| 1x1 stride, valid padding, outputs 28x28x6 	|
| RELU					|												|
| Max Pool K 2x2   		| 2x2 stride, valid padding, outputs 14x14x6	|
| Convolution 5x5	    | 1x1 stride, valid padding, outputs 10x10x16  	|
| RELU					|												|
| Max Pool K 2x2   		| 2x2 stride, valid padding, outputs 5x5x16	|
| Fully connected		| Input: 400, Output: 120        				|
| RELU					|												|
| Fully connected		| Input: 120, Output: 84        				|
| RELU					|												|
| Fully connected		| Input: 84, Output: 43        				|
 


#### 3. Describe how you trained your model. The discussion can include the type of optimizer, the batch size, number of epochs and any hyperparameters such as learning rate.

To train the model, I used a learning rate of 0.001, batch size of 100, 25 Epochs, an Entropy loss function, and an Adam optimizer.

#### 4. Describe the approach taken for finding a solution and getting the validation set accuracy to be at least 0.93. Include in the discussion the results on the training, validation and test sets and where in the code these were calculated. Your approach may have been an iterative process, in which case, outline the steps you took to get to the final solution and why you chose those steps. Perhaps your solution involved an already well known implementation or architecture. In this case, discuss why you think the architecture is suitable for the current problem.

My final model results were:
* training set accuracy of 0.990
* validation set accuracy of 0.941  
* test set accuracy of 0.928

I started with straightforwad LeNet from the example and i only changed the final output to 43 instead of 10; 
this gave validation accuracy of <85% before any preprocessing; 
after grayscaling and normalization the results improved to 97%. 
i have tried with diffirent models and decided to get better result with present model by fine tuning the each parameter.
The first issue was lack of data for some images and the last was lack of knowledge of all the parameters. After I fixed those issues the LeNet model given worked pretty well with the defaults. 

i have added the Dropouts and observed there is better output in diffirent cases after trying out with regular architecture of LeNet.

Epoch, learning rate, batch size, and drop out probability were all parameters tuned. 
For Epoch the main reason I tuned this was after I started to get better accuracy early on I lowered the number once I had confidence I could reach my accuracy goals. 
The batch size I increased only slightly since starting once I increased the dataset size.
The learning rate I think could of been left at .001 which is significently ok for the model.

If a well known architecture was chosen:

* I used LeNet as a base model.
The final accuracy of the model scored 99% on validation; it also reached 93% on testing; which indicated that it wasn't overfitting in this context. Still on external data; it performed significantly and able to achieve 100% accuracy.


### Test a Model on New Images

#### 1. Choose five German traffic signs found on the web and provide them in the report. For each image, discuss what quality or qualities might be difficult to classify.

Here are five German traffic signs that I found on the web:

![alt text][image1]
![alt text][image2]
![alt text][image3]
![alt text][image4]
![alt text][image5]

and all the images was classifed correctly 

#### 2. Discuss the model's predictions on these new traffic signs and compare the results to predicting on the test set. At a minimum, discuss what the predictions were, the accuracy on these new predictions, and compare the accuracy to the accuracy on the test set (OPTIONAL: Discuss the results in more detail as described in the "Stand Out Suggestions" part of the rubric).

Here are the results of the prediction:
* predicted values :  [ 2 14 25 12 23]
* actual values :  [2, 14, 25, 12, 23]

-----------
new data accuracy:
fail 0
match 5
-----------
successful matches 100.00%


| Image			        |     Prediction	        					| 
|:---------------------:|:---------------------------------------------:| 
| Stop Sign      		| Stop sign   									| 
| priority road     			| priority road 										|
| roadwork					| roadwork											|
| 50 km/h	      		| 50 km/h						 				|
| Slippery Road			| Slippery Road      							|


The model was able to correctly guess 5 of the 5 traffic signs, which gives an accuracy of 100%. when compared to the test accuracy, predictions on net images working very well.

#### 3. Describe how certain the model is when predicting on each of the five new images by looking at the softmax probabilities for each prediction. Provide the top 5 softmax probabilities for each image along with the sign type of each probability. (OPTIONAL: as described in the "Stand Out Suggestions" part of the rubric, visualizations can also be provided such as bar charts)

The code for making predictions on my final model is located in the 16th cell of the Ipython notebook.

For the first image, the model is relatively sure that this is a 50 km sign.
as all 5 images were correcty classified 
The top five soft max probabilities were

[[9.82692e-01 8.82133e-03 4.20828e-03 2.39887e-03 1.72330e-03]
 [9.59869e-01 1.77639e-02 8.52597e-03 7.65811e-03 3.38877e-03]
 [7.83899e-01 1.04636e-01 2.93637e-02 2.06891e-02 1.69446e-02]
 [9.98965e-01 2.84062e-04 2.43942e-04 1.90317e-04 8.77580e-05]
 [8.90700e-01 3.47507e-02 2.82695e-02 2.45680e-02 1.88539e-02]] 
