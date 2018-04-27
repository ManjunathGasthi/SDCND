## Writeup Template
### You can use this file as a template for your writeup if you want to submit it as a markdown file, but feel free to use some other method and submit a pdf if you prefer.

---

**Vehicle Detection Project**

The goals / steps of this project are the following:

* Perform a Histogram of Oriented Gradients (HOG) feature extraction on a labeled training set of images and train a classifier Linear SVM classifier
* Optionally, you can also apply a color transform and append binned color features, as well as histograms of color, to your HOG feature vector. 
* Note: for those first two steps don't forget to normalize your features and randomize a selection for training and testing.
* Implement a sliding-window technique and use your trained classifier to search for vehicles in images.
* Run your pipeline on a video stream (start with the test_video.mp4 and later implement on full project_video.mp4) and create a heat map of recurring detections frame by frame to reject outliers and follow detected vehicles.
* Estimate a bounding box for vehicles detected.

[//]: # (Image References)
[image1]: ./examples/car_not_car.png
[image2]: ./examples/HOG_example.jpg
[image3]: ./examples/sliding_windows.jpg
[image4]: ./examples/sliding_window.jpg
[image5]: ./examples/bboxes_and_heat.png
[image6]: ./examples/labels_map.png
[image7]: ./examples/output_bboxes.png
[video1]: ./project_video.mp4


[image11]: ./output_images/bin_spatial1.png
[image22]: ./output_images/bin_spatial2.png
[image33]: ./output_images/bin_spatial3.png
[image44]: ./output_images/color_hist_vis.png
[image55]: ./output_images/data_visualization.png
[image66]: ./output_images/hog_visualization.png
[image77]: ./output_images/sliding_windows.png
[image88]: ./output_images/windows.png
[image89]: ./output_images/windows2.png
[image87]: ./output_images/windows3.png
[image91]: ./output_images/heatmap1.png
[image92]: ./output_images/heatmap2.png
[image93]: ./output_images/heatmap3.png
[image94]: ./output_images/heatmap4.png
[image95]: ./output_images/heatmap5.png
[image96]: ./output_images/heatmap6.png


[project_video.mp4]: ./test_videos/project_video.mp4
[test_output.mp4]: ./test_videos/test_output.mp4
  

---


### Histogram of Oriented Gradients (HOG)

#### 1. Explain how (and identify where in your code) you extracted HOG features from the training images.

The training images are loaded from the Dataset

8792          images of vehicles
8968         images of non-vehicles

![alt text][image55]

The feature extraction(spatial, color and HOG) contains a set of functions provided by Udacity's lectures to extract the features from an image. The function get_hog_features extracts the data and returns "features".


![alt text][image66]

#### 2. Explain how you settled on your final choice of HOG parameters.

The parameters were found by manually changing them and experimenting to try to maximize the model accuracy and minimize the fitting time. 
with the parameters used:
Test Accuracy of SVC: 97.21%

  Predictions: [1. 0. 0. 0. 1. 0. 0. 1. 1. 0.]
       Labels: [1. 0. 0. 0. 1. 0. 0. 1. 1. 0.]

### Sliding Window Search

#### 1. Describe how (and identify where in your code) you implemented a sliding window search.  How did you decide what scales to search and how much to overlap windows?

Implementingiding windows was first to calculate for all the windows and then apply the feature extraction to each one of them to find the one containing a car.  Steps as loading the test images, applying the classifier to the images and drawing boxes. The scales and overlap parameter where found by experimenting on them until a successful result was found. 

![alt text][image88]

#### 2. Show some examples of test images to demonstrate how your pipeline is working.  What did you do to optimize the performance of your classifier?

The performance of the method calculating HOG on each particular window was slow. To improve the processing performance, a HOG sub-sampling was implemented as suggested on Udacity's lectures.

![alt text][image89]
![alt text][image87]

![alt text][image87]
---

### Video Implementation

#### 1. Provide a link to your final video output.  Your pipeline should perform reasonably well on the entire project video (somewhat wobbly or unstable bounding boxes are ok as long as you are identifying the vehicles most of the time with minimal false positives.)

The video output could be found [project_video.mp4](/test_videos/project_video.mp4)


#### 2. Describe how (and identify where in your code) you implemented some kind of filter for false positives and some method for combining overlapping bounding boxes.

Some effort was done already to minimize false positives using a heatmap and threshold in the pipeline.

![alt text][image91]
![alt text][image92]
![alt text][image93]
![alt text][image94]
![alt text][image95]
![alt text][image96]

---

### Discussion

#### 1. Briefly discuss any problems / issues you faced in your implementation of this project.  Where will your pipeline likely fail?  What could you do to make it more robust?

The developed pipeline may possibly fail in varied lighting and illumination conditions. Also, the multi-window search may be optimized further for better speed and accuracy.

Dataset usage as Car & non Car should be nearly equal.

I think this is interesting approach for starting in this field. But it is not ready for production use. I think convolutional neural network approach may show more robustness and speed. As it could be easily accelerated via GPU. Also it may let to locate cars in just one try. For example we may ask CNN to calculate number of cars in the image. And by activated neurons locate positions of the cars.
