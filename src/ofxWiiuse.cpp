#include "ofxWiiuse.h"

string ofxWiiuse::getVersionString()
{
    string versionS = "";
    versionS += ofToString(OFXWIIUSE_MAJOR_VERSION);
    versionS += ".";
    versionS += ofToString(OFXWIIUSE_MINOR_VERSION);
    versionS += ".";
    versionS += ofToString(OFXWIIUSE_PATCH_VERSION);
    return versionS;
}
ofxWiiuse::ofxWiiuse()
{
    //_motionSensingBParameter = false;
	_wiimotes =  wiiuse_init(OFXWIIUSE_MAX_WIIMOTES);
	_numberOfFoundWiimotes = wiiuse_find(_wiimotes, OFXWIIUSE_MAX_WIIMOTES, 5);
    ofLogNotice("ofxWiiuse")<<"found "<<_numberOfFoundWiimotes<<" wiimote(s)";
    if(_numberOfFoundWiimotes)
    {
        connect(); 
    }
}
ofxWiiuse::~ofxWiiuse()
{
	wiiuse_cleanup(_wiimotes, OFXWIIUSE_MAX_WIIMOTES);
}

void ofxWiiuse::setup()
{
}
void ofxWiiuse::update()
{
    if(getNumberOfConnectedWiimotes() > 0) {
        if (wiiuse_poll(_wiimotes, OFXWIIUSE_MAX_WIIMOTES)) {
            for (int i = 0; i < OFXWIIUSE_MAX_WIIMOTES; ++i) {
                switch (_wiimotes[i]->event) {
                    case WIIUSE_DISCONNECT:
					case WIIUSE_UNEXPECTED_DISCONNECT:
                        {
                            notifyControlEvent(_wiimotes[i]->unid, OFXWIIUSE_DISCONNECTED);
                        }
                    case WIIUSE_EVENT:
                        /* a generic event occurred */
                        handle_event(_wiimotes[i]);
                        break;
                }
            }
        }
    }
}
/*
void ofxWiiuse::start(bool blockingB)
{
    startThread(blockingB);
}
void ofxWiiuse::stop()
{
    stopThread();
}
void ofxWiiuse::threadedFunction()
{
    while(isThreadRunning())
    {
        update();
    }
}
*/
void ofxWiiuse::connect()
{
	wiiuse_connect(_wiimotes, OFXWIIUSE_MAX_WIIMOTES);
#ifndef WIIUSE_WIN32
	usleep(200000);
#else
	Sleep(200);
#endif
}
void ofxWiiuse::addListener(ofxWiiuseListener* listenerPtr)
{
    ofAddListener(_buttonEvent, listenerPtr, &ofxWiiuseListener::onWiiuseButtonEvent);
    ofAddListener(_motionEvent, listenerPtr, &ofxWiiuseListener::onWiiuseMotionEvent);
    ofAddListener(_controlEvent, listenerPtr, &ofxWiiuseListener::onWiiuseControlEvent);
}
void ofxWiiuse::removeListener(ofxWiiuseListener* listenerPtr)
{
    ofRemoveListener(_buttonEvent, listenerPtr, &ofxWiiuseListener::onWiiuseButtonEvent);
    ofRemoveListener(_motionEvent, listenerPtr, &ofxWiiuseListener::onWiiuseMotionEvent);
    ofRemoveListener(_controlEvent, listenerPtr, &ofxWiiuseListener::onWiiuseControlEvent);
}


unsigned short int ofxWiiuse::getNumberOfConnectedWiimotes(){
    unsigned short int numberOfConnectedWiimotesUSI = 0;
	for (int i = 0; i < OFXWIIUSE_MAX_WIIMOTES; i++) {
		if (_wiimotes[i] && WIIMOTE_IS_CONNECTED(_wiimotes[i])) {
			numberOfConnectedWiimotesUSI++;
		}
	}
	return numberOfConnectedWiimotesUSI;
}
void ofxWiiuse::handle_event(struct wiimote_t* wm)
{
	if (IS_JUST_PRESSED(wm, WIIMOTE_BUTTON_A)){
        notifyButtonEvent(wm->unid, OFXWIIUSE_BUTTON_A_PRESSED);
	}
	if (IS_RELEASED(wm, WIIMOTE_BUTTON_A)){
        notifyButtonEvent(wm->unid, OFXWIIUSE_BUTTON_A_RELEASED);
	}
	if (IS_JUST_PRESSED(wm, WIIMOTE_BUTTON_B)){
        notifyButtonEvent(wm->unid, OFXWIIUSE_BUTTON_B_PRESSED);
	}
	if (IS_RELEASED(wm, WIIMOTE_BUTTON_B)) {
        notifyButtonEvent(wm->unid, OFXWIIUSE_BUTTON_B_RELEASED);
	}
	if (IS_JUST_PRESSED(wm, WIIMOTE_BUTTON_MINUS)){
        notifyButtonEvent(wm->unid, OFXWIIUSE_BUTTON_MINUS_PRESSED);
	}
	if (IS_RELEASED(wm, WIIMOTE_BUTTON_MINUS)){
        notifyButtonEvent(wm->unid, OFXWIIUSE_BUTTON_MINUS_RELEASED);
	}
	if (IS_JUST_PRESSED(wm, WIIMOTE_BUTTON_PLUS)){
        notifyButtonEvent(wm->unid, OFXWIIUSE_BUTTON_PLUS_PRESSED);
	}
	if (IS_RELEASED(wm, WIIMOTE_BUTTON_PLUS)){
        notifyButtonEvent(wm->unid, OFXWIIUSE_BUTTON_PLUS_RELEASED);
	}
	if (IS_JUST_PRESSED(wm, WIIMOTE_BUTTON_UP)){
        notifyButtonEvent(wm->unid, OFXWIIUSE_BUTTON_UP_PRESSED);
	}
	if (IS_RELEASED(wm, WIIMOTE_BUTTON_UP)){
        notifyButtonEvent(wm->unid, OFXWIIUSE_BUTTON_UP_RELEASED);
	}
	if (IS_JUST_PRESSED(wm, WIIMOTE_BUTTON_RIGHT)){
        notifyButtonEvent(wm->unid, OFXWIIUSE_BUTTON_RIGHT_PRESSED);
	}
	if (IS_RELEASED(wm, WIIMOTE_BUTTON_RIGHT)){
        notifyButtonEvent(wm->unid, OFXWIIUSE_BUTTON_RIGHT_RELEASED);
	}
	if (IS_JUST_PRESSED(wm, WIIMOTE_BUTTON_DOWN)){
        notifyButtonEvent(wm->unid, OFXWIIUSE_BUTTON_DOWN_PRESSED);
	}
	if (IS_RELEASED(wm, WIIMOTE_BUTTON_DOWN)){
        notifyButtonEvent(wm->unid, OFXWIIUSE_BUTTON_DOWN_RELEASED);
	}
	if (IS_JUST_PRESSED(wm, WIIMOTE_BUTTON_LEFT)){
        notifyButtonEvent(wm->unid, OFXWIIUSE_BUTTON_LEFT_PRESSED);
	}
	if (IS_RELEASED(wm, WIIMOTE_BUTTON_LEFT)){
        notifyButtonEvent(wm->unid, OFXWIIUSE_BUTTON_LEFT_RELEASED);
	}
	if (IS_JUST_PRESSED(wm, WIIMOTE_BUTTON_ONE)) {
        notifyButtonEvent(wm->unid, OFXWIIUSE_BUTTON_ONE_PRESSED);
	}
	if (IS_RELEASED(wm, WIIMOTE_BUTTON_ONE)) {
        notifyButtonEvent(wm->unid, OFXWIIUSE_BUTTON_ONE_RELEASED);
	}
	if (IS_JUST_PRESSED(wm, WIIMOTE_BUTTON_TWO)) {
        notifyButtonEvent(wm->unid, OFXWIIUSE_BUTTON_TWO_PRESSED);
	}
	if (IS_RELEASED(wm, WIIMOTE_BUTTON_TWO)) {
        notifyButtonEvent(wm->unid, OFXWIIUSE_BUTTON_TWO_RELEASED);
	}
	if (IS_JUST_PRESSED(wm, WIIMOTE_BUTTON_HOME)){
        notifyButtonEvent(wm->unid, OFXWIIUSE_BUTTON_HOME_PRESSED);
	}
	if (IS_RELEASED(wm, WIIMOTE_BUTTON_HOME)){
        notifyButtonEvent(wm->unid, OFXWIIUSE_BUTTON_HOME_RELEASED);
	}
	if (WIIUSE_USING_ACC(wm)) {
        vector<float> values;
        values.push_back(wm->orient.roll);
        values.push_back(wm->orient.pitch);
        values.push_back(wm->orient.yaw);
        notifyMotionEvent(wm->unid, values);
		//printf("wiimote roll  = %f [%f]\n", wm->orient.roll, wm->orient.a_roll);
		//printf("wiimote pitch = %f [%f]\n", wm->orient.pitch, wm->orient.a_pitch);
		//printf("wiimote yaw   = %f\n", wm->orient.yaw);
	}
}
void ofxWiiuse::handle_disconnect(struct wiimote_t* wm)
{
    //TODO
}
ofxWiiuse* ofxWiiuse::setMotionSensing(int id, bool value)
{
    if(value == isMotionSensing(id))
    {
        return this;
    }
    if(value)
    {
	    wiiuse_motion_sensing(wiiuse_get_by_id(_wiimotes, OFXWIIUSE_MAX_WIIMOTES, id), 1);
    }
    else
    {
	    wiiuse_motion_sensing(wiiuse_get_by_id(_wiimotes, OFXWIIUSE_MAX_WIIMOTES, id), 0);
    }
    return this;
}
ofxWiiuse* ofxWiiuse::toggleMotionSensing(int id)
{
    if(WIIUSE_USING_ACC(wiiuse_get_by_id(_wiimotes, OFXWIIUSE_MAX_WIIMOTES, id)))
    {
	    wiiuse_motion_sensing(wiiuse_get_by_id(_wiimotes, OFXWIIUSE_MAX_WIIMOTES, id), 0);
    }
    else
    {
	    wiiuse_motion_sensing(wiiuse_get_by_id(_wiimotes, OFXWIIUSE_MAX_WIIMOTES, id), 1);
    }
    return this;
}
ofxWiiuse* ofxWiiuse::setRumble(int id, bool value)
{
    if(value)
    {
        wiiuse_rumble(wiiuse_get_by_id(_wiimotes, OFXWIIUSE_MAX_WIIMOTES, id),1);
    }
    else
    {
	    wiiuse_rumble(wiiuse_get_by_id(_wiimotes, OFXWIIUSE_MAX_WIIMOTES, id),0);
    }
    return this;
}
ofxWiiuse* ofxWiiuse::toggleRumble(int id)
{
    wiiuse_toggle_rumble(wiiuse_get_by_id(_wiimotes, OFXWIIUSE_MAX_WIIMOTES, id));
    return this;
}
ofxWiiuse* ofxWiiuse::setLeds(int id, bool led0, bool led1, bool led2, bool led3)
{
    wiimote* wiimote= wiiuse_get_by_id(_wiimotes, OFXWIIUSE_MAX_WIIMOTES, id);
	wiiuse_set_leds(wiimote, WIIMOTE_LED_NONE);
    if(led0)
    {
        wiiuse_set_leds(wiimote, 1);
    }
    if(led1)
    {
        wiiuse_set_leds(wiimote, 2);
    }
    if(led2)
    {
        wiiuse_set_leds(wiimote, 3);
    }
    if(led3)
    {
        wiiuse_set_leds(wiimote, 4);
    }
    return this;
}
ofxWiiuse* ofxWiiuse::setLed(int id, bool value)
{
    wiimote* wiimote= wiiuse_get_by_id(_wiimotes, OFXWIIUSE_MAX_WIIMOTES, id);
    int leds[4];

    leds[0] = WIIUSE_IS_LED_SET(wiiuse_get_by_id(_wiimotes, OFXWIIUSE_MAX_WIIMOTES, id), 1);
    leds[1] = WIIUSE_IS_LED_SET(wiiuse_get_by_id(_wiimotes, OFXWIIUSE_MAX_WIIMOTES, id), 2);
    leds[2] = WIIUSE_IS_LED_SET(wiiuse_get_by_id(_wiimotes, OFXWIIUSE_MAX_WIIMOTES, id), 3);
    leds[3] = WIIUSE_IS_LED_SET(wiiuse_get_by_id(_wiimotes, OFXWIIUSE_MAX_WIIMOTES, id), 4);

    if(value)
    {
        leds[id] = 1;
    }
    else
    {
        leds[id] = 0;
    }
	wiiuse_set_leds(wiimote, WIIMOTE_LED_NONE);
    if(leds[0])
    {
        wiiuse_set_leds(wiimote, 1);
    }
    if(leds[1])
    {
        wiiuse_set_leds(wiimote, 2);
    }
    if(leds[2])
    {
        wiiuse_set_leds(wiimote, 3);
    }
    if(leds[3])
    {
        wiiuse_set_leds(wiimote, 4);
    }
    return this;
}

bool ofxWiiuse::isMotionSensing(int id)
{
    if(WIIUSE_USING_ACC(wiiuse_get_by_id(_wiimotes, OFXWIIUSE_MAX_WIIMOTES, id)))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool ofxWiiuse::isRumbling(int id)
{
    return WIIMOTE_IS_SET(wiiuse_get_by_id(_wiimotes, OFXWIIUSE_MAX_WIIMOTES, id), WIIMOTE_STATE_RUMBLE);
}
void ofxWiiuse::notifyControlEvent(int deviceId, ofxWiiuseControlEventType type)
{
    ofxWiiuseControlEventArgs args;
    args.first = deviceId;
    args.second = type;
    ofNotifyEvent(_controlEvent, args, this);
}
void ofxWiiuse::notifyButtonEvent(int deviceId, ofxWiiuseButtonEventType type)
{
    ofxWiiuseButtonEventArgs args;
    args.first = deviceId;
    args.second = type;
    ofNotifyEvent(_buttonEvent, args, this);
}
void ofxWiiuse::notifyMotionEvent(int deviceId, vector<float> values)
{
    ofxWiiuseMotionEventArgs args;
    args.first = deviceId;
    args.second = values;
    ofNotifyEvent(_motionEvent, args, this);
}
