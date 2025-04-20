#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0); 
    ofSetFrameRate(60); 
	int maxBoxes = 5500;

	for(int i = 0; i < maxBoxes; i++){
		box newBox;
		boxes.push_back(newBox);
	}

}

//--------------------------------------------------------------
void ofApp::update(){
    // Update logic for smooth animation
}

//--------------------------------------------------------------
void ofApp::draw(){

	for(int i = 0; i < boxes.size(); i++){
		boxes[i].draw();
	}
}
//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

} 

box::box(){
	width = 20; 
	height = 20;
	x = ofRandom(ofGetWidth());
	y = ofRandom(ofGetWidth());
	color.set(ofRandom(255),ofRandom(255),ofRandom(255));
}

box::~box(){

}

void box::draw(){
	ofSetColor(color);
	ofDrawRectangle(x, y, width, height);
}
