/* 
 Motion.h - Motion library
 Copyright (c) 2012 Copenhagen Institute of Interaction Design. 
 All right reserved.
 
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU Lesser Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser Public License for more details.
 
 You should have received a copy of the GNU Lesser Public License
 along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 + author: dviid
 + contact: dviid@labs.ciid.dk 
 */

#include <avr/io.h>

#define N 10

typedef float (*force_callback)(float position);

enum MOTION {
    MOTIONA = 0,
    MOTIONB = 1
};

enum INPUT {
    INPUTA0 = 0x00, // bits 0000
    INPUTA1 = 0x01, // bits 0001
    INPUTA2 = 0x02, // bits 0010
    INPUTA3 = 0x03, // bits 0011
    INPUTA4 = 0x04, // bits 0100
    INPUTA5 = 0x05, // bits 0101
    INPUTA6 = 0x06, // bits 0110
    INPUTA7 = 0x07	// bits 0111
};

enum PHY {
    POSITION = 0,
    VELOCITY = 1,
    ACCELERATION = 2
};


class Motion {
    
public:
    Motion(MOTION m);
    
    void init(INPUT sensor);
    
    void set_force_callback(force_callback fcb, PHY physics);  // NOT IMPLEMENTED
	
	int getX();
	
	float calculateFAVX(int);
    
    
    // raw position vector
    int _xv[N];	// NOT IMPLEMENTED
    int _ix;    
    
    float X, V, A, F;    // from model
    float m, k, d;		// constants from mass-spring-damper model
    int Xin;            // from the ADC channel specified in Motion constructor (e.g INPUTA0)


    MOTION _m;
    INPUT  _s;
    bool   _i;	// is it inititated
    
    force_callback _fcb;	// NOT IMPLEMENTED
    PHY            _fcb_phy; // NOT IMPLEMENTED
};

extern Motion MotionA;
extern Motion MotionB;