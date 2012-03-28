/**
 * Simple Read
 * 
 * Read data from the serial port and change the color of a rectangle
 * when a switch connected to a Wiring or Arduino board is pressed and released.
 * This example works with the Wiring / Arduino program that follows below.
 */


import processing.serial.*;

int LF = 10;    // Linefeed in ASCII
boolean test = false;
Serial port;  // Create object from Serial class

void setup() 
{
  size(1024, 300);

  port = new Serial(this, "COM5", 9600);
  port.clear();

  String temp = port.readStringUntil(LF);

  stroke(0);
  ellipseMode(CENTER);
  textAlign(CENTER, CENTER);
  fill(0);
  text("waiting for serial port...", width/2, height/2);
}

void draw()
{
  String[] tokens = null;
  if(!test)
  {
    if(port.available() == 0)
      return;
    
    String input = port.readStringUntil(LF);
    if(input == null)
      return;
  
    tokens = split(input.trim(), " ");
    if(tokens.length != 16)
      return;
  }
  
  int nx = 4;
  
  background(255, 0, 255);
  
  colorMode(HSB, 255, 255, 255);
  
  for(float x = nx; x > 0; x--)
  {
    int idx = int((x-1) * nx);
    
    int px  = int(x / (nx + 1) * width);
    int py  = 150;
    int r = test ? idx*15+15 : int(tokens[idx]);
    
    fill(int(tokens[idx+1]), int(tokens[idx+2]), int(tokens[idx+3]));
    ellipse(px, py, r, r);
  }
}

