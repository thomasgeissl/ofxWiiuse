#pragma once

class circle
{
public:
    circle()
    {
        _xFParameter.set("x", ofGetWidth()/2, 0,ofGetWidth());
        _yFParameter.set("y", ofGetHeight()/2, 0,ofGetHeight());
        _sizeIParameter.set("size", ofGetHeight()/20, 0,ofGetHeight()/2);
        _fillColorParameter.set("Fill color", ofColor(0));
        _parameters.add(_xFParameter);
        _parameters.add(_yFParameter);
        _parameters.add(_sizeIParameter);
        _parameters.add(_fillColorParameter);
        setup();
    }
    void setup()
    {
        _xFParameter = ofGetWidth()/2;
        _yFParameter = ofGetHeight()/2;
        _sizeIParameter = ofGetHeight()/20;
        _color = ofColor(0);
    }
    void draw()
    {
        ofSetColor(_fillColorParameter);
        ofDrawCircle(_xFParameter, _yFParameter, _sizeIParameter);
    }
    void left()
    {
        _xFParameter -= 10;
    }
    void right()
    {
        _xFParameter += 10;
    }
    void up()
    {
        _yFParameter -= 10;
    }
    void down()
    {
        _yFParameter += 10;
    }
    void zoom(int value = 1)
    {
        _sizeIParameter += value;
    }
    void randomColor()
    {
        _fillColorParameter = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    }
private:
    ofParameterGroup _parameters;
    ofParameter<float> _xFParameter;
    ofParameter<float> _yFParameter;
    ofParameter<int> _sizeIParameter;
    ofParameter<ofColor> _fillColorParameter;
    ofColor _color;
};
