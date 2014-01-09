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
		ranges[0] = hranges;
		ranges[1] = hranges; 
		ranges[2] = hranges; 
	}

    // Sets the reference histogram
    void setHistogram(const cv::MatND& h) {
        histogram= h;
        cv::normalize(histogram,histogram,1.0);
    }

	// Finds the pixels belonging to the histogram
    cv::Mat find(const cv::Mat& image) {
		cv::Mat result;
		hranges[0]  = 0.0;
		hranges[1]  = 255.0;
		channels[0] = 0;
		channels[1] = 1; 
		channels[2] = 2; 
        cv::calcBackProject(&image,1,channels,histogram,result,ranges,255.0);
        if (threshold>0.0)
			cv::threshold(result, result, 255*threshold, 255, cv::THRESH_BINARY);
		return result;
	}
};


#endif
