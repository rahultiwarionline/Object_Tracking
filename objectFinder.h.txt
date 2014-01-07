#ifndef OFINDER
#define OFINDER

#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>

class ObjectFinder {
  private:
	float hranges[2];
    const float* ranges[3];
    int channels[3];
	float threshold;
	cv::MatND histogram;
  public:
    ObjectFinder() : threshold(0.1f) {
		ranges[0]= hranges; // all channels have the same range 
		ranges[1]= hranges; 
		ranges[2]= hranges; 
	}

    // Sets the reference histogram
    void setHistogram(const cv::MatND& h) {
        histogram= h;
        cv::normalize(histogram,histogram,1.0);
    }

	// Finds the pixels belonging to the histogram
    cv::Mat find(const cv::Mat& image) {
		cv::Mat result;
		hranges[0]= 0.0;	// range [0,255]
		hranges[1]= 255.0;
		channels[0]= 0;		// the three channels 
		channels[1]= 1; 
		channels[2]= 2; 
        cv::calcBackProject(&image,
                  1,            // one image
                  channels,     // vector specifying what histogram dimensions
                                // belong to what image channels
                  histogram,    // the histogram we are using
                  result,       // the resulting back projection image
                  ranges,       // the range of values, for each dimension
                  255.0         // the scaling factor is chosen such that a histogram
                                // value of 1 maps to 255
       );
        // Threshold back projection to obtain a binary image
        if (threshold>0.0)
			cv::threshold(result, result, 255*threshold, 255, cv::THRESH_BINARY);
		return result;
	}
};


#endif
