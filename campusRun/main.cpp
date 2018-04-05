#include <gl/glut.h>
#include <stdio.h>
#include <math.h>

char timer[7];
extern GLfloat X=10;
 extern GLfloat Y=380;

extern GLfloat p=0;
 extern GLfloat q=0;

char W[2];
 int track=1;

 int turnX,turnY;

int turnpoint=0;
float speed=10;
int screen=1;

int coinlift=0;

int tmillisec=300;

double critical;


void drawString (void *font, float x, float y, char *str)
 {
/* Draws string ’str’ in font ’font’, at world (x,y,0) */
char *ch;
glRasterPos3f(x, y, 0.0);
for (ch= str; *ch; ch++)
glutBitmapCharacter(font, (int)*ch);
 }


 void displayscreen3()
{
   glClearColor(0.0,0.0,1.0,0.0);



   glColor3f(1.0, 0.0, 0.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 175, 300,"The END!!!!!");

 glColor3f(1.0, 0.0, 0.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 150, 270,"Your Score");

 glColor3f(1.0, 0.0, 0.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 270, 270,W);



glColor3f(0.0, 0.0, 1.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 100, 100,"Press P to PLAY AGAIN");


   glColor3f(0.0, 0.0, 1.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 500, 100,"Press Esc to Exit");













}

void displayscreen1()
{
   glClearColor(0.0,0.0,1.0,0.0);

   glColor3f(0.0,0.0,0.0);

   glBegin(GL_POLYGON);

      glVertex3f(200,150,0);
      glVertex3f(300,200,0);
      glVertex3f(200,250,0);
     glEnd();


   glColor3f(1.0, 0.0, 0.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 200, 350,"NITH");


 glColor3f(1.0, 0.0, 0.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 175, 300,"Campus RUN!!!!");


 glColor3f(1.0, 0.0, 0.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 155, 260,"A 30 sec Challenge");






     glColor3f(0.0, 0.0, 1.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 100, 100,"Press P to PLAY");


   glColor3f(0.0, 0.0, 1.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 300, 100,"Press Esc to Exit");


glutPostRedisplay();



}

  void printcoins()
  {       char ch4;
      char *p=W;

  int temp=coinlift;

     switch(temp/10)
    {
        case 0:  ch4='0';  break;
        case 1:  ch4='1';  break;
        case 2:  ch4='2';  break;
        case 3:  ch4='3';  break;
        case 4:  ch4='4';  break;
        case 5:  ch4='5';  break;
        case 6:  ch4='6';  break;
        case 7:  ch4='7';  break;
        case 8:  ch4='8';  break;
        case 9:  ch4='9';  break;


    }

     *p=ch4;   p++;




      switch(coinlift%10)
    {
        case 0:  ch4='0';  break;
        case 1:  ch4='1';  break;
        case 2:  ch4='2';  break;
        case 3:  ch4='3';  break;
        case 4:  ch4='4';  break;
        case 5:  ch4='5';  break;
        case 6:  ch4='6';  break;
        case 7:  ch4='7';  break;
        case 8:  ch4='8';  break;
        case 9:  ch4='9';  break;


    }
        *p=ch4;

        glColor3f(0.0, 0.0, 1.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 100, 130,"Coins");


         glColor3f(0.0, 0.0, 1.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 100, 100,W);


  }







 int TrackCode[72][5]={
                       {1,10,380,50,250},
                       {2,50,250,10,380},
                       {3,50,250,110,250},
                       {4,110,250,50,250},
                       {5,110,250,130,220},
                       {6,130,220,110,250},
                       {7,130,220,120,180},
                       {8,120,180,130,220},
                       {9,120,180,150,160},
                       {10,150,160,120,180},
                       {11,150,160,170,160},
                       {12,170,160,150,160},
                       {13,170,160,360,20},
                       {14,360,20,170,160},
                       {15,360,20,410,20},
                       {16,410,20,360,20},
                       {17,360,20,380,70},
                       {18,380,70,360,20},
                       {19,410,20,470,80},
                       {20,470,80,410,20},
                       {21,380,70,440,110},
                       {22,440,110,380,70},
                       {23,440,110,470,80},
                       {24,470,80,440,110},
                       {25,470,80,510,120},
                       {26,510,120,470,80},
                       {27,510,120,550,100},
                       {28,550,100,510,120},
                       {29,550,100,640,160},
                       {30,640,160,550,100},
                       {31,640,160,680,170},
                       {32,680,170,640,160},
                       {33,680,170,700,190},
                       {34,300,190,680,170},
                       {35,700,190,680,240},
                       {36,680,240,700,190},
                       {37,380,70,310,130},
                       {38,310,130,380,70},
                       {39,310,130,340,190},
                       {40,340,190,310,130},
                       {41,340,190,440,210},
                       {42,440,210,340,190},
                       {43,440,210,470,250},
                       {44,470,250,440,210},
                       {45,470,250,540,220},
                       {46,540,220,470,250},
                       {47,540,220,680,240},
                       {48,680,240,540,220},
                       {49,680,240,680,290},
                       {50,680,290,680,240},
                       {51,680,240,760,230},
                       {52,760,230,680,240},
                       {53,760,230,760,250},
                       {54,760,250,760,230},
                       {55,760,250,750,270},
                       {56,750,270,760,250},
                       {57,750,270,680,290},
                       {58,680,290,750,270},
                       {59,680,290,670,320},
                       {60,670,320,680,290},
                       {61,670,320,690,340},
                       {62,690,340,670,320},
                       {63,690,340,600,390},
                       {64,600,390,690,340},
                       {65,600,390,450,390},
                       {66,450,390,600,390},
                       {67,450,390,340,340},
                       {68,340,340,450,390},
                       {69,340,340,180,380},
                       {70,180,380,340,340},
                       {71,180,380,10,380},
                       {72,10,380,180,380}

                          };


   int NewTrack[72][5]={
                          {1,0,3,0,2},
                          {2,0,72,0,1},
                          {3,0,5,5,4},
                          {4,0,0,0,3},
                          {5,0,0,7,6},
                          {6,4,0,0,5},
                          {7,0,0,9,8},
                          {8,0,0,6,7},
                          {9,0,0,11,10},
                          {10,0,0,8,9},
                          {11,0,0,13,12},
                          {12,0,0,10,11},
                          {13,17,0,15,14},
                          {14,0,0,12,13},
                          {15,0,0,19,16},
                          {16,0,17,14,15},
                          {17,37,21,0,18},
                          {18,14,15,0,17},
                          {19,24,0,25,20},
                          {20,0,0,16,19},
                          {21,0,23,0,22},
                          {22,37,0,18,21},
                          {23,20,25,0,24},
                          {24,22,0,0,23},
                          {25,0,0,27,26},
                          {26,24,0,20,25},
                          {27,0,0,29,28},
                          {28,0,0,26,27},
                          {29,0,0,31,30},
                          {30,0,0,28,29},
                          {31,0,0,33,32},
                          {32,0,0,30,31},
                          {33,0,0,35,34},
                          {34,0,0,32,33},
                          {35,48,51,49,36},
                          {36,0,0,34,35},
                          {37,0,0,39,38},
                          {38,18,21,0,37},
                          {39,0,41,0,40},
                          {40,0,0,38,39},
                          {41,0,0,43,42},
                          {42,40,0,0,41},
                          {43,0,0,45,44},
                          {44,0,0,42,43},
                          {45,0,0,47,46},
                          {46,0,0,44,45},
                          {47,49,36,51,48},
                          {48,0,0,46,47},
                          {49,59,58,0,50},
                          {50,48,51,36,49},
                          {51,53,0,0,52},
                          {52,36,49,48,51},
                          {53,0,0,55,54},
                          {54,52,0,0,53},
                          {55,0,0,57,56},
                          {56,0,0,54,55},
                          {57,50,59,0,58},
                          {58,0,0,56,57},
                          {59,0,0,61,60},
                          {60,0,58,50,61},
                          {61,0,0,63,62},
                          {62,0,0,60,61},
                          {63,0,0,65,64},
                          {64,0,0,62,63},
                          {65,0,0,67,66},
                          {66,0,0,64,65},
                          {67,0,0,69,68},
                          {68,0,0,66,67},
                          {69,0,0,71,70},
                          {70,0,0,68,69},
                          {71,1,0,0,72},
                          {72,0,0,70,71}
                                           };


   float Coins[92][3]={
                       { 0, 15.881717 , 360.884430 },

{ 0, 27.645149 , 322.653290 },

{ 0, 39.408585 , 284.422150 },

{ 0, 51.172020 , 246.190994 },

{ 0, 90.000000 , 250.000000 },

{ 0, 110.000000 , 250.000000 },

{ 0, 122.723938 , 190.895706 },

{ 0, 144.961487 , 163.359009 },

{ 0, 202.202209 , 136.272034 },

{ 0, 218.303314 , 124.408051 },

{ 0, 234.404419 , 112.544067 },

{ 0, 250.505524 , 100.680084 },

{ 0, 266.606659 , 88.816101 },

{ 0, 282.707794 , 76.952118 },

{ 0, 298.808929 , 65.088135 },

{ 0, 314.910065 , 53.224152 },

{ 0, 331.011200 , 41.360168 },

{ 0, 347.112335 , 29.496185 },

{ 0, 370.000000 , 20.000000 },

{ 0, 390.000000 , 20.000000 },

{ 0, 410.000000 , 20.000000 },

{ 0, 438.284302 , 48.284271 },

{ 0, 452.426453 , 62.426407 },

{ 0, 466.568604 , 76.568542 },

{ 0, 498.284302 , 108.284271 },

{ 0, 536.832825 , 106.583588 },

{ 0, 574.961487 , 116.641014 },

{ 0, 591.602478 , 127.735023 },

{ 0, 608.243469 , 138.829025 },

{ 0, 624.884460 , 149.923019 },

{ 0, 669.104248 , 167.276062 },

{ 0, 688.858215 , 217.854279 },

{ 0, 372.407440 , 76.507912 },

{ 0, 357.222321 , 89.523735 },

{ 0, 342.037201 , 102.539558 },

{ 0, 326.852081 , 115.555382 },

{ 0, 323.416412 , 156.832825 },

{ 0, 332.360687 , 174.721375 },

{ 0, 369.417450 , 195.883499 },

{ 0, 398.834900 , 201.766998 },

{ 0, 418.446533 , 205.689331 },

{ 0, 438.058167 , 209.611664 },

{ 0, 464.000000 , 242.000000 },

{ 0, 506.765747 , 234.243225 },

{ 0, 525.148682 , 226.364838 },

{ 0, 569.698425 , 224.242645 },

{ 0, 589.497375 , 227.071075 },

{ 0, 609.296326 , 229.899506 },

{ 0, 629.095276 , 232.727936 },

{ 0, 658.793701 , 236.970581 },

{ 0, 678.592651 , 239.799011 },

{ 0, 413.281982 , 92.188019 },

{ 0, 421.602478 , 97.735023 },

{ 0, 429.922974 , 103.282028 },

{ 0, 438.243469 , 108.829033 },

{ 0, 676.837708 , 299.486847 },

{ 0, 670.513123 , 318.460541 },

{ 0, 655.033691 , 359.425659 },

{ 0, 637.550537 , 369.138489 },

{ 0, 620.067383 , 378.851318 },

{ 0, 602.584229 , 388.564148 },

{ 0, 560.000000 , 390.000000 },

{ 0, 540.000000 , 390.000000 },

{ 0, 520.000000 , 390.000000 },

{ 0, 500.000000 , 390.000000 },

{ 0, 480.000000 , 390.000000 },

{ 0, 460.000000 , 390.000000 },

{ 0, 422.688995 , 377.585907 },

{ 0, 404.481659 , 369.309845 },

{ 0, 386.274323 , 361.033783 },

{ 0, 368.066986 , 352.757721 },

{ 0, 349.859650 , 344.481659 },

{ 0, 301.194336 , 349.701416 },

{ 0, 281.791504 , 354.552124 },

{ 0, 262.388672 , 359.402832 },

{ 0, 242.985809 , 364.253540 },

{ 0, 223.582947 , 369.104248 },

{ 0, 204.180084 , 373.954956 },

{ 0, 184.777222 , 378.805664 },

{ 0, 140.000000 , 380.000000 },

{ 0, 120.000000 , 380.000000 },

{ 0, 100.000000 , 380.000000 },

{ 0, 80.000000 , 380.000000 },

{ 0, 60.000000 , 380.000000 },

{ 0, 40.000000 , 380.000000 },

{ 0, 20.000000 , 380.000000 },

{ 0, 689.922791 , 238.759659 },

{ 0, 709.768372 , 236.278976 },

{ 0, 729.613953 , 233.798294 },

{ 0, 749.459534 , 231.317612 },

{ 0, 721.154297 , 278.241669 },

{ 0, 701.923828 , 283.736115 }








                                  };


   /*float TurnPoints[32][2]={
                       { 50,250},
                       { 360, 20},
                       { 380, 70},
                       { 440, 110},
                       { 470, 80},
                       { 680,240},
                       { 680, 290},
                       { 760, 230},
                       { 340,190 },
                       { 10,380},
                       { 110, 250},
                       { 130, 220},
                       { 150, 160},
                       { 170, 160},
                       { 410,20},
                       { 310, 130},
                       { 440, 210},
                       { 470,250 },
                       { 540,220},
                       { 510, 120},
                       { 550, 100},
                       { 640, 160},
                       { 680, 170},
                       { 700,190},
                       { 760, 250},
                       { 750, 270},
                       { 670,320 },
                       { 690,340},
                       { 600, 390},
                       { 450, 390},
                       { 340, 340},
                       { 180, 380}


                                      };   */







void displaytracks()
{

   glLineStipple(1, 0x3F07);
   glEnable(GL_LINE_STIPPLE);

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);      //A
    glVertex3f(10,380,0.0);
    glVertex3f(50,250,0.0);
    glVertex3f(110,250,0.0);
    glVertex3f(130,220,0.0);
    glVertex3f(120,180,0.0);
    glVertex3f(150,160,0.0);
    glVertex3f(170,160,0.0);
    glVertex3f(360,20,0.0);
    glEnd();

    glColor3f(0.0,0.0,0.0);
     glBegin(GL_LINE_STRIP);   //C
    glVertex3f(360,20,0.0);
    glVertex3f(380,70,0.0);
    glVertex3f(440,110,0.0);
    glVertex3f(470,80,0.0);
    glEnd();

    glColor3f(0.0,0.0,0.0);
     glBegin(GL_LINE_STRIP);    //B
    glVertex3f(360,20,0.0);
    glVertex3f(410,20,0.0);
    glVertex3f(470,80,0.0);
    glVertex3f(510,120,0.0);
    glVertex3f(550,100,0.0);
    glVertex3f(640,160,0.0);
    glVertex3f(680,170,0.0);
    glVertex3f(700,190,0.0);
    glVertex3f(680,240,0.0);
    glEnd();

    glColor3f(0.0,0.0,0.0);
     glBegin(GL_LINE_STRIP);    //D
    glVertex3f(380,70,0.0);
    glVertex3f(310,130,0.0);
    glVertex3f(340,190,0.0);
    glVertex3f(440,210,0.0);
    glVertex3f(470,250,0.0);
    glVertex3f(540,220,0.0);
    glVertex3f(680,240,0.0);

    glEnd();


    glColor3f(0.0,0.0,0.0);
     glBegin(GL_LINE_STRIP);    //F
    glVertex3f(680,240,0.0);
    glVertex3f(680,290,0.0);
    glVertex3f(670,320,0.0);
    glVertex3f(690,340,0.0);
    glVertex3f(600,390,0.0);
    glVertex3f(450,390,0.0);
    glVertex3f(340,340,0.0);
    glVertex3f(180,380,0.0);
    glVertex3f(10,380,0.0);

    glEnd();


     glColor3f(0.0,0.0,0.0);
     glBegin(GL_LINE_STRIP);   //E
    glVertex3f(680,240,0.0);
    glVertex3f(760,230,0.0);
    glVertex3f(760,250,0.0);
    glVertex3f(750,270,0.0);
    glVertex3f(680,290,0.0);
    glEnd();


    glFlush();





}
void displayBuildings()
{





     glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);                    //  NITH GROUND
       glVertex3f (275,275 ,0.0);
       glVertex3f (325,325, 0.0);
       glVertex3f (400,275, 0.0);
       glVertex3f (350,225, 0.0);
    glEnd();

    glColor3f(0.8, 0.2, 0.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 330, 250,"Ground");
    glColor3f(1.0,0.5,0.0);


     glColor3f(1.0,0.5,0.0);


    glBegin(GL_POLYGON);                    //  ADMIN block
       glVertex3f (500,100 ,0.0);
       glVertex3f (510,90, 0.0);
       glVertex3f (460,40, 0.0);
       glVertex3f (445,45, 0.0);
    glEnd();

glColor3f(1.0, 0.0, 0.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 460, 30,"Admin block");
    glColor3f(1.0,0.5,0.0);




    glBegin(GL_POLYGON);                    //  CENTRAL block
       glVertex3f (440,100,0.0);
       glVertex3f (450,90, 0.0);
       glVertex3f (430,70, 0.0);
       glVertex3f (420,80, 0.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 420, 70,"Central Block");
    glColor3f(1.0,0.5,0.0);


    glBegin(GL_POLYGON);                    //  Electrical
       glVertex3f (450,150,0.0);
       glVertex3f (490,120, 0.0);
       glVertex3f (470,100, 0.0);
       glVertex3f (430,130, 0.0);
    glEnd();

                     glColor3f(1.0, 0.0, 0.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 420, 120,"EE");
    glColor3f(1.0,0.5,0.0);


    glBegin(GL_POLYGON);                    //  Library
       glVertex3f (390,150,0.0);
       glVertex3f (410,130, 0.0);
       glVertex3f (400,120, 0.0);
       glVertex3f (380,140, 0.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 360, 130,"library");
    glColor3f(1.0,0.5,0.0);


  glBegin(GL_POLYGON);                    //  Auditorium
       glVertex3f (360,110,0.0);
       glVertex3f (380,120, 0.0);
       glVertex3f (400,90, 0.0);
       glVertex3f (380,80, 0.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 350, 100,"Audi");
    glColor3f(1.0,0.5,0.0);



    glBegin(GL_POLYGON);                    //  lecture hall
       glVertex3f (440,180,0.0);
       glVertex3f (440,160, 0.0);
       glVertex3f (400,160, 0.0);
       glVertex3f (400,180, 0.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 380, 190,"lecture hall");
    glColor3f(1.0,0.5,0.0);


    glBegin(GL_POLYGON);                    //  Electronics
       glVertex3f (480,190,0.0);
       glVertex3f (500,170, 0.0);
       glVertex3f (480,140, 0.0);
       glVertex3f (460,160, 0.0);
    glEnd();

glColor3f(1.0, 0.0, 0.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 470, 170,"ECE");
    glColor3f(1.0,0.5,0.0);


    glBegin(GL_POLYGON);                    //  Chemical
       glVertex3f (450,220,0.0);
       glVertex3f (460,230, 0.0);
       glVertex3f (490,210, 0.0);
       glVertex3f (480,200, 0.0);
    glEnd();


glColor3f(1.0, 0.0, 0.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 500, 210,"CE");
    glColor3f(1.0,0.5,0.0);


        glBegin(GL_POLYGON);                    //  CSE
       glVertex3f (490,140,0.0);
       glVertex3f (500,160, 0.0);
       glVertex3f (520,150, 0.0);
       glVertex3f (510,130, 0.0);
    glEnd();

glColor3f(1.0, 0.0, 0.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 480, 150,"CSD");
    glColor3f(1.0,0.5,0.0);

     glBegin(GL_POLYGON);                    //  CC
       glVertex3f (520,140,0.0);
       glVertex3f (525,150, 0.0);
       glVertex3f (540,145, 0.0);
       glVertex3f (535,135, 0.0);
    glEnd();

glColor3f(1.0, 0.0, 0.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 520, 130,"CC");
    glColor3f(1.0,0.5,0.0);



 glBegin(GL_POLYGON);                    //  civil
       glVertex3f (490,200,0.0);
       glVertex3f (500,210, 0.0);
       glVertex3f (560,180, 0.0);
       glVertex3f (550,160, 0.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 550, 180,"CED");
    glColor3f(1.0,0.5,0.0);


    glBegin(GL_POLYGON);                    //  Bank
       glVertex3f (540,130,0.0);
       glVertex3f (570,180, 0.0);
       glVertex3f (590,170, 0.0);
       glVertex3f (550,120, 0.0);
    glEnd();


    glColor3f(0.0, 0.0, 1.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 560, 120,"Bank");
    glColor3f(1.0,0.5,0.0);



    glBegin(GL_POLYGON);                    //  Bank
       glVertex3f (540,130,0.0);
       glVertex3f (570,180, 0.0);
       glVertex3f (590,170, 0.0);
       glVertex3f (550,120, 0.0);
    glEnd();

    glBegin(GL_POLYGON);                    //  KBH
       glVertex3f (640,170,0.0);
       glVertex3f (620,180, 0.0);
       glVertex3f (622,187, 0.0);
       glVertex3f (610,195, 0.0);
       glVertex3f (620,205,0.0);
       glVertex3f (610,215, 0.0);
       glVertex3f (630,230, 0.0);
       glVertex3f (635,220, 0.0);
       glVertex3f (645,225,0.0);
       glVertex3f (655,215, 0.0);
       glVertex3f (650,205, 0.0);
       glVertex3f (665,195, 0.0);
       glVertex3f (658,183,0.0);
       glVertex3f (650,190, 0.0);
       glVertex3f (640,180, 0.0);
       glVertex3f (645,175, 0.0);
    glEnd();

    glColor3f(0.4, 0.2, 0.6); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 640, 200,"KBH");
    glColor3f(1.0,0.5,0.0);



     glBegin(GL_POLYGON);                    //  Bank
       glVertex3f (180,225,0.0);
       glVertex3f (200,220, 0.0);
       glVertex3f (195,200, 0.0);
       glVertex3f (175,205, 0.0);
    glEnd();


     glBegin(GL_POLYGON);                    //  MEGA1
       glVertex3f (440,330,0.0);
       glVertex3f (460,350, 0.0);
       glVertex3f (485,330, 0.0);
       glVertex3f (460,310, 0.0);
    glEnd();

    glBegin(GL_POLYGON);                    //  MEGA2
       glVertex3f (485,340,0.0);
       glVertex3f (510,360, 0.0);
       glVertex3f (535,340, 0.0);
       glVertex3f (510,320, 0.0);
    glEnd();

     glColor3f(0.4, 0.2, 0.6); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 500, 350,"MBH");
    glColor3f(1.0,0.5,0.0);


    glBegin(GL_POLYGON);                    //  Girls hostel2
       glVertex3f (160,280,0.0);
       glVertex3f (190,280, 0.0);
       glVertex3f (190,245, 0.0);
       glVertex3f (160,245, 0.0);
    glEnd();

     glColor3f(0.4, 0.2, 0.6); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 200, 270,"AGH");
    glColor3f(1.0,0.5,0.0);


    glBegin(GL_POLYGON);                    //  L hostel
       glVertex3f (590,360,0.0);
       glVertex3f (600,380, 0.0);
       glVertex3f (670,340, 0.0);
       glVertex3f (650,310, 0.0);
        glVertex3f (640,315,0.0);
       glVertex3f (650,330, 0.0);

    glEnd();

 glColor3f(0.4, 0.2, 0.6); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 640, 320,"NBH");
    glColor3f(1.0,0.5,0.0);


     glBegin(GL_POLYGON);                    //  curve hostel
       glVertex3f (760,280,0.0);
       glVertex3f (790,270, 0.0);
       glVertex3f (780,225, 0.0);
       glVertex3f (770,230, 0.0);
        glVertex3f (770,240,0.0);
       glVertex3f (770,255, 0.0);
       glVertex3f (760,270, 0.0);

    glEnd();

 glColor3f(0.4, 0.2, 0.6); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 760, 250,"KBH");
    glColor3f(1.0,0.5,0.0);


    glFlush();







}


void displaycar()
 {
      glColor3f(1.0,0.0,0.0);


     glBegin(GL_POLYGON);
     glVertex3f(X,Y,0.0);
     glVertex3f((X+(8*(q-p))),(Y-(8*(p+q))),0.0);
     glVertex3f((X+(10*p)),(Y+(10*q)),0.0);
     glVertex3f((X-(8*(p+q))),(Y+(8*(p-q))),0.0);
     glEnd();

     glFlush();

     glutPostRedisplay();
 }





void displayCoins()
{
    int i=0;

    for(i=0;i<91;i++)
     {
        if(Coins[i][0]==0)
        {
             glColor3f(0.0,0.0,1.0);
             glPointSize(5);

            glBegin(GL_POINTS);
            glVertex3f(Coins[i][1],Coins[i][2],0.0);
            glEnd();

            glFlush();

            glutPostRedisplay();
        }

    }
}







void unitVector()
{
     float S;
    float x1=TrackCode[track-1][1];
    float y1=TrackCode[track-1][2];
    float x2=TrackCode[track-1][3];
    float y2=TrackCode[track-1][4];
    S=sqrt(pow((x2-x1),2)+pow((y2-y1),2));

    p=(x2-x1)/S;
    q=(y2-y1)/S;
}


void checkCoins()
{

int i;

   for(i=0;i<91;i++)
   {
       if(Coins[i][0]==1)
        continue;

       else
      {
          if(((X-5)<Coins[i][1])&&((X+5)>Coins[i][1])&&((Y-5)<Coins[i][2])&&((Y+5)>Coins[i][2]))
          {    Coins[i][0]=1;
               Beep(1500,200);

               coinlift++;

               if(coinlift>90)
               {
                   screen=3;   glutPostRedisplay();
               }

             glutPostRedisplay();
             break;
          }
      }


    }

}

void checkTurnPoint()
{
   int i;

  /* for(i=0;i<6;i++)
   {

          if(((X-10)<TurnPoints[i][0])&&((X+10)>TurnPoints[i][0])&&((Y-10)<TurnPoints[i][1])&&((Y+10)>TurnPoints[i][1]))
          {    turnpoint=1;
               X=TurnPoints[i][0];
               Y=TurnPoints[i][1];
               break;

          }
      }
    */
    turnX=TrackCode[track-1][3];
    turnY=TrackCode[track-1][4];

    if(((X-10)<turnX)&&((X+10)>turnX)&&((Y-10)<turnY)&&((Y+10)>turnY))
    {
        turnpoint=1;
               X=turnX;
               Y=turnY;
    }

}








void displace()
{
    X=X+(speed*p);
    Y=Y+(speed*q);

    unitVector();
}


void display()
{
    glClearColor(0.5,0.7,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);

   if(screen==1)
    displayscreen1();


   else if(screen==2)
{

    printcoins();
    displayBuildings();
    displaytracks();
     displayCoins();
    displaycar();

      glColor3f(1.0,0.0,0.0);
    drawString (GLUT_BITMAP_TIMES_ROMAN_24, 100, 50,timer);


             glFlush ();


}

   else
    displayscreen3();




}

void keyboard(unsigned char key,int x,int y)
{

    int temp;  int i;

    if(key==27)   //  ESC key
        {   screen=3;   }

        else if((key==27)&&(screen==3))   //  ESC key
        {   exit(0);  }


        if((screen==1)&&((key=='P')||(key=='p')))
          {
              screen=2;

             critical = glutGet(GLUT_ELAPSED_TIME)/100;

              glutPostRedisplay();
          }


   if(screen==2)
  {

    if(key=='w'||key=='W')
    {
        if(turnpoint==0)
        {
            displace();
             glutPostRedisplay();
             checkCoins();

        }

        else
        {
           temp=NewTrack[track-1][3];

                   if(temp==0)
                   {  //speed=0;
                   }

                   else
                     {
                             speed=10;
                             track=temp;
                             unitVector();
                             displace();
                             displace();
                             turnpoint=0;
                            glutPostRedisplay();
                     }


        }



    }
unitVector();

  }



  if((screen==3)&&((key=='P')||(key=='p')))
          {
               X=10;
                Y=380;

            p=0;   q=0;   track=1;

            unitVector();

              screen=2;
              coinlift=0;


               for(i=0;i<=92;i++)
                Coins[i][0]=0;


             critical = glutGet(GLUT_ELAPSED_TIME)/100;

              glutPostRedisplay();
          }

}




    void special(int key,int x,int y)
    {
        float temp;

        if(turnpoint==0)
        {
            if(key==GLUT_KEY_DOWN)
             track=NewTrack[track-1][4];
        }

        else
         {
               switch(key)
               {
                   case GLUT_KEY_LEFT:    temp=NewTrack[track-1][1];  break;
                   case GLUT_KEY_RIGHT:    temp=NewTrack[track-1][2];  break;
                   case GLUT_KEY_UP:       temp=NewTrack[track-1][3];  break;
                   case GLUT_KEY_DOWN:       temp=NewTrack[track-1][4];  break;
               }

             if(temp==0)
               {
                   //speed=0;
               }



             else
             {   speed=10;
                 track=temp;
                 unitVector();
                 displace();
                 displace();
                 turnpoint=0;


             }

        }
    }

void time(int value)
{

}

void init (void)
{
/* select clearing (background) color */
glClearColor (0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 800.0, 0.0, 400.0,-1.0,1.0);
}

void stopwatch(double t)
{   register char ch,ch2,ch3,ch4,ch5;
    system("cls");
     tmillisec=(300)-(t-critical);
    int sec=tmillisec/10;
    sec=sec%60;
    int min=tmillisec/600;
    int millisec= tmillisec%10;

  //  printf("%d   :%d  :  %d",min,sec,millisec);


    char *p=timer;


    switch(min/10)
    {
        case 0:  ch='0';  break;
        case 1:  ch='1';  break;
        case 2:  ch='2';  break;
        case 3:  ch='3';  break;
        case 4:  ch='4';  break;
        case 5:  ch='5';  break;
        case 6:  ch='6';  break;
        case 7:  ch='7';  break;
        case 8:  ch='8';  break;
        case 9:  ch='9';  break;


    } *p=ch;  p++;


    switch(min%10)
    {
        case 0:  ch2='0';  break;
        case 1:  ch2='1';  break;
        case 2:  ch2='2';  break;
        case 3:  ch2='3';  break;
        case 4:  ch2='4';  break;
        case 5:  ch2='5';  break;
        case 6:  ch2='6';  break;
        case 7:  ch2='7';  break;
        case 8:  ch2='8';  break;
        case 9:  ch2='9';  break;


    } *p=ch2;  p++;   *p=':';  p++;


    switch(sec/10)
    {
        case 0:  ch3='0';  break;
        case 1:  ch3='1';  break;
        case 2:  ch3='2';  break;
        case 3:  ch3='3';  break;
        case 4:  ch3='4';  break;
        case 5:  ch3='5';  break;
        case 6:  ch3='6';  break;
        case 7:  ch3='7';  break;
        case 8:  ch3='8';  break;
        case 9:  ch3='9';  break;


    }    *p=ch3;  p++;


    switch(sec%10)
    {
        case 0:  ch4='0';  break;
        case 1:  ch4='1';  break;
        case 2:  ch4='2';  break;
        case 3:  ch4='3';  break;
        case 4:  ch4='4';  break;
        case 5:  ch4='5';  break;
        case 6:  ch4='6';  break;
        case 7:  ch4='7';  break;
        case 8:  ch4='8';  break;
        case 9:  ch4='9';  break;


    }    *p=ch4;   p++;   *p=':';  p++;


    switch(millisec)
    {
        case 0:  ch5='0';  break;
        case 1:  ch5='1';  break;
        case 2:  ch5='2';  break;
        case 3:  ch5='3';  break;
        case 4:  ch5='4';  break;
        case 5:  ch5='5';  break;
        case 6:  ch5='6';  break;
        case 7:  ch5='7';  break;
        case 8:  ch5='8';  break;
        case 9:  ch5='9';  break;


    }    *p=ch5;  p++;   *p='\0';


}





void idle()
{

    unitVector();
    checkTurnPoint();
   checkCoins();

   glutTimerFunc(10000,time,2);
   double t = glutGet(GLUT_ELAPSED_TIME)/100;
    stopwatch(t);


    if(tmillisec<0)
        screen=3;


    glutPostRedisplay();




  /* system("cls");
       printf("track= %d\n\n",track);
       printf("speed=%f\n",speed);
       printf("turnPoint=%d\n",turnpoint);

    printf("unit vector== %f  %f\n",p,q);
    printf("Position=  %f  %f",X,Y);        */


}





int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(800,400);
    glutInitWindowPosition(0,0);
    glutCreateWindow("HACKATHON");

     //glutPassiveMotionFunc(passive);
     init();


    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    glutIdleFunc(idle);



   glutMainLoop();
    return 0;

}




