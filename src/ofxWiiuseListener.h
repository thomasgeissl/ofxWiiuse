#pragma once
#include "ofxWiiuseEventArgs.h"
class ofxWiiuseListener
{
public:
    virtual void onWiiuseControlEvent(ofxWiiuseControlEventArgs& args) = 0;
    virtual void onWiiuseButtonEvent(ofxWiiuseButtonEventArgs& args) = 0;
    virtual void onWiiuseMotionEvent(ofxWiiuseMotionEventArgs& args) = 0;
    virtual void onWiiuseIRTrackingEvent(ofxWiiuseIRTrackingEventArgs& args) = 0;
protected:
private:
};
