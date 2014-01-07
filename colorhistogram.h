#ifndef COLHISTOGRAM
#define COLHISTOGRAM

#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>

class ColorHistogram {
  private:
    int histSize[3];
	float hranges[2];
    const float* ranges[3];
    int channels[3];
  public:
	ColorHistogram() {
		// Prepare arguments for a color histogram
		histSize[0]= histSize[1]= histSize[2]= 256;
		hranges[0]= 0.0;    // BRG range
		hranges[1]= 255.0;
		ranges[0]= hranges; // all channels have the same range 
		ranges[1]= hranges; 
		ranges[2]= hranges; 
		channels[0]= 0;		// the three channels 
		channels[1]= 1; 
		channels[2]= 2; 
	}
	// Computes the 1D Hue histogram with a mask.
	// BGR source image is converted to HSV
    cv::MatND getHueHistogram(const cv::Mat &image, int minSaturation=0) {
		cv::MatND hist;
        // Convert to Lab color space
        cv::Mat hsv;
        cv::cvtColor(image, hsv, CV_BGR2HSV);
        // Mask to be used (or not)
        cv::Mat mask;
        if (minSaturation>0) {
            // Splitting the 3 channels into 3 images
            std::vector<cv::Mat> v;
            cv::split(hsv,v);
            // Mask out the low saturated pixels
            cv::threshold(v[1],mask,minSaturation,255,
                          cv::THRESH_BINARY);
        }
		// Prepare arguments for a 1D hue histogram
		hranges[0]= 0.0;
		hranges[1]= 180.0;
		channels[0]= 0; // the hue channel 
		// Compute histogram
        cv::calcHist(&hsv,
			1,			// histogram of 1 image only
			channels,	// the channel used
			cv::Mat(),	// no mask is used
			hist,		// the resulting histogram
			1,			// it is a 1D histogram
			histSize,	// number of bins
			ranges		// pixel value range
		);
		return hist;
	}
};


#endif
