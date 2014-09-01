#ifndef GRADHIST_H
#define GRADHIST_H

#include "opencv.hpp"
#include "sse.hpp"
#include "utils.h"

#define PI 3.14159265f

class QuantizedGradientChannel
{
public:
	int enabled; //if true enable gradient histogram channels
	int binSize; //spatial bin size (defaults to shrink)
	int orientationChannels; //number of orientation channels
	int useSoftBinning; //if true use "soft" bilinear spatial binning
	int useHogNormalization; //if true perform 4-way hog normalization/clipping
	double clipHog; //value at which to clip hog histogram bins
	int nChannels;
	cv::String padWith;

	int gradHist_hb;
	int gradHist_wb;
	int gradHist_nChns;


	void readGradientHistogram(cv::FileNode);
	//comes from gradientMex.cpp, the return still needs a type
	cv::Mat mGradHist(cv::Mat, cv::Mat, int);
	void gradHist(float*,float*,float*,int,int,int,int,int,int);
	void gradQuantize(float*,float*,int*,int*,float*,float*,int, int,float,int,int,bool);
	void hog(float*,float*,float*,int,int,int,int,int,int,float);
	void fhog(float*,float*,float*,int,int,int,int,int,float);
	float* hogNormMatrix(float*,int,int,int,int);
	void hogChannels(float*,const float*,const float*,int,int, int, float, int);
};

#endif
