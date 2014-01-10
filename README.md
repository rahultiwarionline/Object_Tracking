Object_Tracking
===============

OpenCV Mean-Shift Algorithm Object Tracking

This is basically an object-tracking program I made over the summer using OpenCV 2. I learned computer vision tracking
through the book "OpenCV 2 Computer Vision Application Programming Cookbook" by Robert Laganiere, and this project
is actually inspired by one of the recipes in the book, which introduced me to histograms and the mean-shift algorithm.
The book only dealt with individual images, though, so I decided to expand the object-tracking concept and apply it to
a live video from a webcam.

HOW IT WORKS: The user drags a box around the object they want to track (a rubik's cube, a fist, etc.), and the program
will display the object's pixel coordinates and continually redraw the box and update the coordinates to follow the
object around.

THE FILES:
- main.cpp contains the code that draws the boxes and updates pixel coordinates.
- colorhistogram.h is used to create and record the histogram of the targeted object.
- objectFinder.h is used to apply the mean-shift algorithm and track the object as it moves.
