## Writeup Template

### You can use this file as a template for your writeup if you want to submit it as a markdown file, but feel free to use some other method and submit a pdf if you prefer.

---

**Advanced Lane Finding Project**

The goals / steps of this project are the following:

* Compute the camera calibration matrix and distortion coefficients given a set of chessboard images.
* Apply a distortion correction to raw images.
* Use color transforms, gradients, etc., to create a thresholded binary image.
* Apply a perspective transform to rectify binary image ("birds-eye view").
* Detect lane pixels and fit to find the lane boundary.
* Determine the curvature of the lane and vehicle position with respect to center.
* Warp the detected lane boundaries back onto the original image.
* Output visual display of the lane boundaries and numerical estimation of lane curvature and vehicle position.

[//]: # (Image References)

[image1]: ./image_outputs/undistorted_image.png "Undistorted"
[image7]: ./image_outputs/undistorted_image1.png "Undistorted"
[image2]: ./image_outputs/Perspective_transformed.jpg "Road Transformed"
[image3]: ./image_outputs/combined_thresholds.jpg "Binary threshold Example"
[image4]: ./image_outputs/Perspective_transformed.jpg "Warp Example"
[image5]: ./image_outputs/filled_poly.jpg "Fit lane line Visual"
[image6]: ./image_outputs/final_output.jpg "Output"
[video1]: ./project_video.mp4 "Video"


[video2]: ./project_video_ouput.mp4 "Video output"
[video3]: ./challenge_video_ouput.mp4 "challenge output"

## [Rubric](https://review.udacity.com/#!/rubrics/571/view) Points

### Here I will consider the rubric points individually and describe how I addressed each point in my implementation.  

---


### Camera Calibration

#### 1. Briefly state how you computed the camera matrix and distortion coefficients. Provide an example of a distortion corrected calibration image.

Camera calibration was done using the get_calib_objects function to get a set of object and image points, then these are passed to cv2 calibrateCamera.after getting camera metrix & distortion coefficient applied this distortion correction to the test image using the cv2.undistort() function and obtained this result:.  

![alt text][image1]

### Pipeline (single images)

#### 1. Provide an example of a distortion-corrected image.

applied the distortion correction to one of the test images like this one:
![alt text][image7]

#### 2. Describe how (and identify where in your code) you used color transforms, gradients or other methods to create a thresholded binary image.  Provide an example of a binary image result.

Converted the warped image to different color spaces and created binary thresholded images which highlight only lane lines and ignore everything else.

![alt text][image3]

#### 3. Describe how (and identify where in your code) you performed a perspective transform and provide an example of a transformed image.

It uses the CV2's getPerspectiveTransform() and warpPerspective() fns and undistort() 
perspective_transform will undistorted image to a "birds eye view" of the road which focuses only on the lane lines and displays them in such a way that they appear to be relatively parallel to each other.

![alt text][image2]

#### 4. Describe how (and identify where in your code) you identified lane-line pixels and fit their positions with a polynomial?

Starting with the combined binary image to isolate only the pixels belonging to lane lines,
Identified peaks in a histogram of the image to determine location of lane lines.
Identified all non-zero pixels around histogram peaks using the numpy function numpy.nonzero().
Fitted polynomial to each lane using the numpy's fn. numpy.polyfit().
Calculate the vehicle position.
Calculated distance from center by taking the abs value of the vehicle's position and subtracting the halfway point along the horizontal axis distance from center.
If horizontal position of the car was > image_width/2, then car was considered to be on left of center, else right of center.
Finally, the center distance was converted from pixels to meters by multiplying the number of pixels by 3.7/700.


![alt text][image5]

#### 5. Describe how (and identify where in your code) you calculated the radius of curvature of the lane and the position of the vehicle with respect to center.
below code snippet for radius of curvature & position of vehicle.

    # Measure Radius of Curvature for each lane line
    ym_per_pix = 30./720 # meters per pixel in y dimension
    xm_per_pix = 3.7/700 # meteres per pixel in x dimension
    left_fit_cr = np.polyfit(lefty*ym_per_pix, leftx*xm_per_pix, 2)
    right_fit_cr = np.polyfit(righty*ym_per_pix, rightx*xm_per_pix, 2)
    
    left_curverad = ((1 + (2*left_fit_cr[0]*np.max(lefty) + left_fit_cr[1])**2)**1.5) \
                                 /np.absolute(2*left_fit_cr[0])
    right_curverad = ((1 + (2*right_fit_cr[0]*np.max(lefty) + right_fit_cr[1])**2)**1.5) \
                                    /np.absolute(2*right_fit_cr[0])
    
    # Calculate the position of the vehicle
    center = abs(640 - ((rightx_int+leftx_int)/2))
    

#### 6. Provide an example image of your result plotted back down onto the road such that the lane area is identified clearly.
by using get_fit_window() poly will be identified clrealy & plotted back down on test image.

![alt text][image6]

---

### Pipeline (video)

#### 1. Provide a link to your final video output.  Your pipeline should perform reasonably well on the entire project video (wobbly lines are ok but no catastrophic failures that would cause the car to drive off the road!).


- Output for : **project_video.mp4**


[![Watch the video](output_videos_folder/project_output.png )](https://youtu.be/WMvepVfnb-o)

- Output for : **challenge_video.mp4**

[![Watch the video](output_videos_folder/Challenge_output.png )](https://youtu.be/JaH0FYGosZY)

---

---

### Discussion

#### 1. Briefly discuss any problems / issues you faced in your implementation of this project.  Where will your pipeline likely fail?  What could you do to make it more robust?

From trying the challenge video, my current pipeline, the result is not so robust and it fail in some frames. I think that would be improved by refining my choices for thresholding functions and limits used.

 it would be a good idea to test in different conditions, such as in snow, rain and at night. which will give even more results to check the accuracy and do more improvments.