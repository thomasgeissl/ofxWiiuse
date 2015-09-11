#pragma once

#include "ofMain.h"
#include "ofxWiiuse.h"
#include "circle.h"

#include "ofAppDefines.h"

class ofApp : public ofBaseApp, public ofxWiiuseListener{
public:
    void setup();
    void update();
    void draw();
    void exit();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void onWiiuseControlEvent(ofxWiiuseControlEventArgs& args);
    void onWiiuseButtonEvent(ofxWiiuseButtonEventArgs& args);
    void onWiiuseMotionEvent(ofxWiiuseMotionEventArgs& args);
    void onWiiuseIRTrackingEvent(ofxWiiuseIRTrackingEventArgs& args);
protected:
private:
    ofxWiiuse _wiiuse;
    circle _circle;
#ifdef OFAPP_TWO_WIIS
    circle _secondCircle;
#endif
};
