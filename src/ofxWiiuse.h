#pragma once

#include "ofMain.h"
#include "ofxWiiuseDefines.h"
#include "ofxWiiuseEventArgs.h"
#include "ofxWiiuseListener.h"
#include "wiiuse.h"

class ofxWiiuse : 
    public ofThread{
public:
    static string getVersionString();
    ofxWiiuse();
    ~ofxWiiuse();

    void setup();
    void update();
    /*
    void start(bool blockingB = true);
    void stop();
    void threadedFunction();
    */

    void connect();
    void addListener(ofxWiiuseListener* listenerPtr);
    void removeListener(ofxWiiuseListener* listenerPtr);

    ofxWiiuse* setMotionSensing(int id, bool value = true);
    ofxWiiuse* toggleMotionSensing(int id);
    ofxWiiuse* setRumble(int id, bool value = true);
    ofxWiiuse* toggleRumble(int id);
    ofxWiiuse* setLeds(int id, bool led0 = true, bool led1 = true, bool led2 = true, bool led3 = true);
    ofxWiiuse* setLed(int id, bool value = true);

    bool isMotionSensing(int id);
    bool isRumbling(int id);

protected:
private:
    unsigned short int getNumberOfConnectedWiimotes();
    void handle_event(struct wiimote_t* wm);
    void handle_disconnect(struct wiimote_t* wm);
    void notifyControlEvent(int deviceId, ofxWiiuseControlEventType type);
    void notifyButtonEvent(int deviceId, ofxWiiuseButtonEventType type);
    void notifyMotionEvent(int deviceId, vector<float> values);
private:
	wiimote** _wiimotes;
    ofEvent<ofxWiiuseControlEventArgs> _controlEvent;
    ofEvent<ofxWiiuseButtonEventArgs> _buttonEvent;
    ofEvent<ofxWiiuseMotionEventArgs> _motionEvent;
    int _numberOfFoundWiimotes;
};
