#include "ofApp.h"

void ofApp::setup()
{
    ofLog::setAutoSpace(true);
    ofSetFrameRate(60);
    _wiiuse.addListener(this);
}
void ofApp::update()
{
    _wiiuse.update();
}
void ofApp::draw()
{
    _circle.draw();
#ifdef OFAPP_TWO_WIIS
    _secondCircle.draw();
#endif
}
void ofApp::exit(){
    _wiiuse.removeListener(this);
}
void ofApp::keyPressed(int key){}
void ofApp::keyReleased(int key){
    switch(key){
    }
}
void ofApp::mouseMoved(int x, int y){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){}
void ofApp::onWiiuseControlEvent(ofxWiiuseControlEventArgs& args)
{
    //TODO
    switch(args.second)
    {
        case OFXWIIUSE_DISCONNECTED:
            {
                ofLogNotice("ofApp")<<"wii "<<args.first<<" disconnected";
                break;
            }
    }
}
void ofApp::onWiiuseButtonEvent(ofxWiiuseButtonEventArgs& args)
{
    circle* selectedCircle;
    if(args.first == 1)
    {
        selectedCircle = &_circle;
    }
#ifdef OFAPP_TWO_WIIS
    if(args.first == 2)
    {
        selectedCircle = &_secondCircle;
    }
#endif
    if(!selectedCircle)
    {
        return;
    }
    switch(args.second)
    {
        case OFXWIIUSE_BUTTON_UP_PRESSED:
            {
                selectedCircle->up();
                break;
            }
        case OFXWIIUSE_BUTTON_DOWN_PRESSED:
            {
                selectedCircle->down();
                break;
            }
        case OFXWIIUSE_BUTTON_LEFT_PRESSED:
            {
                selectedCircle->left();
                break;
            }
        case OFXWIIUSE_BUTTON_RIGHT_PRESSED:
            {
                selectedCircle->right();
                break;
            }
        case OFXWIIUSE_BUTTON_MINUS_PRESSED:
            {
                selectedCircle->zoom(-1);
                break;
            }
        case OFXWIIUSE_BUTTON_PLUS_PRESSED:
            {
                selectedCircle->zoom(1);
                break;
            }
        case OFXWIIUSE_BUTTON_ONE_PRESSED:
            {
                _wiiuse.setMotionSensing(args.first, true);
                break;
            }
        case OFXWIIUSE_BUTTON_TWO_PRESSED:
            {
                _wiiuse.setMotionSensing(args.first, false);
                break;
            }
        case OFXWIIUSE_BUTTON_HOME_PRESSED:
            {
                selectedCircle->setup();
                break;
            }
        case OFXWIIUSE_BUTTON_A_PRESSED:
            {
                _wiiuse.setRumble(args.first, true);
                break;
            }
        case OFXWIIUSE_BUTTON_A_RELEASED:
            {
                _wiiuse.setRumble(args.first, false);
                break;
            }
        case OFXWIIUSE_BUTTON_B_PRESSED:
            {
                selectedCircle->randomColor();
                break;
            }
    }
}
void ofApp::onWiiuseMotionEvent(ofxWiiuseMotionEventArgs& args)
{
    int id = args.first;
    ofBackground(args.second[0], args.second[1], args.second[2]);
}
