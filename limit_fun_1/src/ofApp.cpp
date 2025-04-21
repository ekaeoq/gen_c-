#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(255);          
    ofSetFrameRate(60);         
    animationTime = 0.0f;
    minX = -2.0f;
    maxX = 2.0f;
    axisY = ofGetHeight() / 2;
}

//--------------------------------------------------------------
void ofApp::update() {
    animationTime += ofGetLastFrameTime(); 
}

//--------------------------------------------------------------
void ofApp::draw() {
    // (0 to 3 seconds)
    if (animationTime < 3.0f) {
        float alpha = (animationTime / 3.0f) * 255; 
        ofSetColor(0, 0, 0, alpha);
        float length = (animationTime / 3.0f) * ofGetWidth();
        ofDrawLine(0, axisY, length, axisY);
    } else {
        ofSetColor(0); 
        ofDrawLine(0, axisY, ofGetWidth(), axisY);

        // (3 to 5 seconds)
        float tickTime = animationTime - 3.0f;
        if (tickTime < 2.0f) {
            float alpha = (tickTime / 2.0f) * 255;
            ofSetColor(0, 0, 0, alpha);
            for (float xVal = -2.0f; xVal <= 2.0f; xVal += 1.0f) {
                float screenX = mathToScreenX(xVal);
                ofDrawLine(screenX, axisY - 10, screenX, axisY + 10);
            }
        } else {
            ofSetColor(0); 
            for (float xVal = -2.0f; xVal <= 2.0f; xVal += 1.0f) {
                float screenX = mathToScreenX(xVal);
                ofDrawLine(screenX, axisY - 10, screenX, axisY + 10);
            }

            float pointTime = animationTime - 5.0f;
            int numPoints = std::min(20, static_cast<int>(pointTime / 0.3f));
            for (int n = 1; n <= numPoints; ++n) {
                float x = 1.0f / n;
                float screenX = mathToScreenX(x);
                float pointAlpha = std::min(255.0f, (pointTime - (n - 1) * 0.3f) / 0.6f * 255); 
                ofSetColor(255, 0, 0, pointAlpha);
                ofDrawCircle(screenX, axisY - 15, 5);
            }

            if (animationTime >= 5.0f) {
                float formulaAlpha1 = std::min(255.0f, (animationTime - 5.0f) / 1.5f * 255);
                ofSetColor(0, 0, 0, formulaAlpha1);
                std::string formulaPart1 = "a = lim_{n->∞} a_n";
                ofDrawBitmapString(formulaPart1, 20, 20);
            }

            if (numPoints >= 5) {
                float epsilonTime = animationTime - 6.5f;
                float epsilon = 0.2f;
                float left = mathToScreenX(-epsilon);
                float right = mathToScreenX(epsilon);

                float epsilonAlpha = std::min(255.0f, epsilonTime / 1.5f * 255);
                ofSetColor(0, 0, 255, epsilonAlpha * 0.2f); 
                ofDrawRectangle(left, axisY - 20, right - left, 40);

                ofSetColor(0, 0, 255, epsilonAlpha); 
				ofNoFill();
                ofDrawRectangle(left, axisY - 20, right - left, 40);
				ofFill();

                float formulaAlpha2 = std::min(255.0f, epsilonTime / 1.5f * 255);
                ofSetColor(0, 0, 0, formulaAlpha2);
                std::string formulaPart2 = "a = lim_{n->∞} a_n ⇔ ∀ε>0";
                ofDrawBitmapString(formulaPart2, 20, 20);

                for (int n = 1; n <= numPoints; ++n) {
                    float x = 1.0f / n;
                    float screenX = mathToScreenX(x);
                    float pointAlpha = std::min(255.0f, (pointTime - (n - 1) * 0.3f) / 0.6f * 255);
                    if (x < epsilon) {
                        ofSetColor(0, 255, 0, pointAlpha); 
                    } else {
                        ofSetColor(255, 0, 0, pointAlpha); 
                    }
                    ofDrawCircle(screenX, axisY - 15, 5);
                }

                if (numPoints >= 10) {
                    float finalFormulaTime = animationTime - 8.0f;
                    float formulaAlpha3 = std::min(255.0f, finalFormulaTime / 1.5f * 255);
                    ofSetColor(0, 0, 0, formulaAlpha3);
                    std::string fullFormula = "a = lim_{n->∞} a_n ⇔ ∀ε>0, ∃n_0∈ℕ: (n>n_0 ⇒ |a_n - a| < ε)";
                    ofDrawBitmapString(fullFormula, 20, 20);
                }
            }
        }
    }
}

//--------------------------------------------------------------
float ofApp::mathToScreenX(float x) {
    return (x - minX) / (maxX - minX) * ofGetWidth();
}  

void ofApp::keyPressed(int key) {};
void ofApp::keyReleased(int key) {};
void ofApp::mouseMoved(int x, int y) {};
void ofApp::mouseDragged(int x, int y, int button) {};
void ofApp::mousePressed(int x, int y, int button) {};
void ofApp::mouseReleased(int x, int y, int button) {};
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY) {};
void ofApp::mouseEntered(int x, int y) {};
void ofApp::mouseExited(int x, int y) {};
void ofApp::windowResized(int w, int h) {};
void ofApp::dragEvent(ofDragInfo dragInfo) {};
void ofApp::gotMessage(ofMessage msg) {}; 
void ofApp::exit() {};

