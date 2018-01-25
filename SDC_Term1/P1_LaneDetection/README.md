# **Finding Lane Lines on the Road** 
[![Udacity - Self-Driving Car NanoDegree](https://s3.amazonaws.com/udacity-sdc/github/shield-carnd.svg)](http://www.udacity.com/drive)

<img src="examples/laneLines_thirdPass.jpg" width="480" alt="Combined Image" />

Overview
---

This project marks the Lanes on a road by using Canny Edge Detection, Hough Transforms, and linear regression. Naturally, one of the first things we would like to do in developing a self-driving car is to automatically detect lane lines using an algorithm.

In this project will detect lane lines in images using Python and OpenCV.  OpenCV means "Open-Source Computer Vision", which is a package that has many useful tools for analyzing images.  

Dependencies ( software & Libraries)
---

    ..*Python 3.5
    ..*NumPy
    ..*OpenCV
    ..*Matplotlib
    ..*MoviePy
	..*Math
	..*jupyter notebook

Steps to achieve ( Pipeline)
---
    1. Convert frame to grayscale
	2. Apply Gaussian smoothing 
	3. Apply Canny edges & identify ROI
	4. concluding the points using Hough transform
	5. Draw lines on each frame

Open Challenges 
---
	This we have only run on Highway road lanes captured video clips, need to test in different weather conditions, in tunnels and shadows to improve further.