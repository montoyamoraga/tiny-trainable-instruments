////////
// about
////////

// tiny-trainable-instruments
// a project by @montoyamoraga
// github.com/montoyamoraga/tiny-trainable-instruments

// tiny_trainable_banner.pde
// this is a Processing sketch for banner
// started in December 2020
// v0.0.1

///////
// code
///////

// global variable for storing font
PFont myFont;

void setup() {

  size(1280, 640);

  // load font from data/folder
  // VCR OSD Mono by mrmanet
  // available at https://www.1001freefonts.com/vcr-osd-mono.font
  // font license: free
  myFont = createFont("VCR_OSD_MONO.ttf", 32);
  
  // set the font for text
  textFont(myFont);

  // text options
  // align to center
  textAlign(CENTER);
  // text size
  textSize(64);

  // drawing options
  // no border
  noStroke();
  // green fill
  fill(0, 255, 0);

  // set background color black
  background(0);

  // draw text at the center of canvas
  text("tiny trainable instruments", width/2, height/2);

  // save resulting file
  save("output.jpg");
}
