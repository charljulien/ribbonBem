import processing.serial.*;
import netP5.*;
import oscP5.*;

Serial myPort;
int val;  

//OSC
OscP5 oscP5;
NetAddress myRemoteLocation;
NetAddress mySelfLocation;

void setup() {
  
  size(200, 200);
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
 
  
  // OSC
  oscP5 = new OscP5(this,7000);
//  myRemoteLocation = new NetAddress("127.0.0.1",9013);
//  mySelfLocation = new NetAddress("127.0.0.1",9031);
}

void draw() {
  background(255);

}

void oscEvent(OscMessage theOscMessage) {
  
  
  println("### received an osc message. with address pattern "+
          theOscMessage.addrPattern()+" typetag "+ theOscMessage.typetag());


  // pushPad
  
  if(theOscMessage.checkAddrPattern("/2/push1")==true) {
    if(theOscMessage.checkTypetag("f")) {
      myPort.write(1);
      println("TEST: 0 _ "  + theOscMessage.get(0).floatValue());
      myPort.write("\n");
      return;
    }
  }
  
  if(theOscMessage.checkAddrPattern("/2/push2")==true) {
    if(theOscMessage.checkTypetag("f")) {
      myPort.write(2);
      println("TEST: 1 _ "  + theOscMessage.get(0).floatValue());
      myPort.write("\n");
      return;
    }
  }
  
  if(theOscMessage.checkAddrPattern("/2/push3")==true) {
    if(theOscMessage.checkTypetag("f")) {
      myPort.write(3);
      println("TEST: 2 _ "  + theOscMessage.get(0).floatValue());
      myPort.write("\n");
      return;
    }
  }
  
  if(theOscMessage.checkAddrPattern("/2/push4")==true) {
    if(theOscMessage.checkTypetag("f")) {
      myPort.write(4);
      println("TEST: 3 _ "  + theOscMessage.get(0).floatValue());
      myPort.write("\n");
      return;
    }
  }
    
  if(theOscMessage.checkAddrPattern("/2/push5")==true) {
    if(theOscMessage.checkTypetag("f")) {
      myPort.write(5);
      println("TEST: 3 _ "  + theOscMessage.get(0).floatValue());
      myPort.write("\n");
      return;
    }
  }
  
  if(theOscMessage.checkAddrPattern("/2/push6")==true) {
    if(theOscMessage.checkTypetag("f")) {
      myPort.write(6);
      println("TEST: 3 _ "  + theOscMessage.get(0).floatValue());
      myPort.write("\n");
      return;
    }
  }
  
  if(theOscMessage.checkAddrPattern("/2/push7")==true) {
    if(theOscMessage.checkTypetag("f")) {
      myPort.write(7);
      println("TEST: 3 _ "  + theOscMessage.get(0).floatValue());
      myPort.write("\n");
      return;
    }
  }
  
  if(theOscMessage.checkAddrPattern("/2/push8")==true) {
    if(theOscMessage.checkTypetag("f")) {
      myPort.write(8);
      println("TEST: 3 _ "  + theOscMessage.get(0).floatValue());
      myPort.write("\n");
      return;
    }
  }
  
  if(theOscMessage.checkAddrPattern("/2/push9")==true) {
    if(theOscMessage.checkTypetag("f")) {
      myPort.write(9);
      println("TEST: 3 _ "  + theOscMessage.get(0).floatValue());
      myPort.write("\n");
      return;
    }
  }
  
  if(theOscMessage.checkAddrPattern("/2/push10")==true) {
    if(theOscMessage.checkTypetag("f")) {
      myPort.write(10);
      println("TEST: 3 _ "  + theOscMessage.get(0).floatValue());
      myPort.write("\n");
      return;
    }
  }
  
  if(theOscMessage.checkAddrPattern("/2/push11")==true) {
    if(theOscMessage.checkTypetag("f")) {
      myPort.write(11);
      println("TEST: 3 _ "  + theOscMessage.get(0).floatValue());
      myPort.write("\n");
      return;
    }
  }
  
   if(theOscMessage.checkAddrPattern("/2/push12")==true) {
    if(theOscMessage.checkTypetag("f")) {
      myPort.write(12);
      println("TEST: 3 _ "  + theOscMessage.get(0).floatValue());
      myPort.write("\n");
      return;
    }
  }
  
  if(theOscMessage.checkAddrPattern("/2/push13")==true) {
    if(theOscMessage.checkTypetag("f")) {
      myPort.write(byte(13));
      println("TEST: 3 _ "  + theOscMessage.get(0).floatValue());
      myPort.write("\n");
      return;
    }
  }
  
  if(theOscMessage.checkAddrPattern("/2/push14")==true) {
    if(theOscMessage.checkTypetag("f")) {
      myPort.write(byte(14));
      println("TEST: 3 _ "  + theOscMessage.get(0).floatValue());
      myPort.write("\n");
      return;
    }
  }
  
  if(theOscMessage.checkAddrPattern("/2/push15")==true) {
    if(theOscMessage.checkTypetag("f")) {
      myPort.write(byte(15));
      println("TEST: 3 _ "  + theOscMessage.get(0).floatValue());
      myPort.write("\n");
      return;
    }
  }
  
  if(theOscMessage.checkAddrPattern("/2/push16")==true) {
    if(theOscMessage.checkTypetag("f")) {
      myPort.write(byte(16));
      println("TEST: 3 _ "  + theOscMessage.get(0).floatValue());
      myPort.write("\n");
      return;
    }
  }
  
  // Fader
    if(theOscMessage.checkAddrPattern("/1/fader5")==true) {
    if(theOscMessage.checkTypetag("f")) {
      myPort.write(9);
      int a = int(theOscMessage.get(0).floatValue()*100);
      println("TEST: 5 _ "  + a);
      myPort.write(  a );
      myPort.write("\n");
      return;
    }
  }
  
  /*test multilog*/
    if(theOscMessage.checkAddrPattern("/4/multitoggle/1/1")==true) {
    if(theOscMessage.checkTypetag("f")) {
      myPort.write(2);
      println("TEST: 1 _ "  + theOscMessage.get(0).floatValue());
      myPort.write("\n");
      return;
    }
  }
 
}