#include<GL/glut.h>
#include<stdlib.h>
#include<string.h>

int flag = -1,ind=0;
char dir[] = "right";
int tx=0,ty=420,i,p=0,k;
GLint ww=1440,wh=900;
GLubyte labell[5]={'S','T','A','R','T'};
GLubyte label[7]={'B','E','E','H','I','V','E'};
GLubyte lose[8]={'O','H',' ','D','E','A','R','!'};
GLubyte lose1[16] = {'B','E','E',' ','H','I','T',' ','I','T','S',' ','H','E','A','D'};
GLubyte win[17]={'R','E','A','C','H','E','D',' ','T','H','E',' ','H','I','V','E','!'};


void init()
{
     glClearColor(0.0,0.0,0.8,0.0);
     glClear(GL_COLOR_BUFFER_BIT);
     glMatrixMode(GL_PROJECTION);
     gluOrtho2D(0.0,ww,0.0,wh);
}

void bee()
{
     glClear(GL_COLOR_BUFFER_BIT);
     
     GLint i,j;
     glColor3f(0.0,1.0,0.0);
     glRasterPos2i(1150,600);
     for(i=0;i<7;i++)
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,label[i]);
     glColor3f(1.0,0.8,0.0);
     glRasterPos2i(30,220);
     for(j=0;j<5;j++)
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,labell[j]);
     glColor3f(1.0,0.8,0.0);
     if(flag==1)
     {  glRasterPos2i(375,330);
        for(j=0;j<17;j++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,win[j]);	
	 }
	 if(flag==0)
     {  glRasterPos2i(375,370);
        for(j=0;j<8;j++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,lose[j]);
        glRasterPos2i(375,330);
		for(j=0;j<16;j++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,lose1[j]);		
	 }
     
     //tri
	 glColor3f(1,1,0);
     glBegin(GL_POLYGON);
     glVertex2f(40.0+tx, 10.0+ty);
     glVertex2f(10.0+tx, 40.0+ty);
     glVertex2f(90.0+tx, 40.0+ty);
     glEnd();
	 
	 //face
     glEnable(GL_POINT_SMOOTH);
     glColor3f(1,0,0);
     glPointSize(50.0f);
     glBegin(GL_POINTS);
     glVertex2i(90+tx,40+ty);
     glEnd();
     
     //flower
     glColor3f(0.6,1,0);
     glBegin(GL_POLYGON);
     glVertex2i(0,90);
     glVertex2i(60,45+90);
     glVertex2i(20,80+90);
     glVertex2i(120,210);
     glEnd();
     
     //beehive
     int a=1050,b=350;
     glColor3f(1,1,0);
     int p1[]={100+a,50+b};
	 int p2[]={200+a,50+b};
	 int p3[]={275+a,150+b};
	 int p4[]={200+a,240+b};
	 int p5[]={100+a,240+b};
	 int p6[]={25+a,150+b};
	
	
	 glBegin (GL_POLYGON);
	 glVertex2iv (p1);
	 glVertex2iv (p2);
	 glVertex2iv (p3);
	 glVertex2iv (p4);
	 glVertex2iv (p5);
	 glVertex2iv (p6);
	 glEnd ( );
	 
	 glColor3f(0,0,0);
     glPointSize(20.0f);
     glBegin(GL_POINTS);
     glVertex2i(1120,450);
     glVertex2i(1220,470);
     glVertex2i(1140,470);
     glVertex2i(1280,490);
     glVertex2i(1300,500);
     glVertex2i(1150,520);
     glVertex2i(1170,520);
     glVertex2i(1250,520);
     glVertex2i(1270,520);
     glVertex2i(1230,450);
     glVertex2i(1210,440);
     glEnd();
     
     
     //eye
	 glColor3f(0,0,0);
     glPointSize(5.0f);
     glBegin(GL_POINTS);
     glVertex2i(90+tx,40+ty);
     glEnd();
     
     //strips
     glColor3f(0,0,0);
     glLineWidth(5.0f);
     glBegin(GL_LINES);
     glVertex2i(40+tx,40+ty);
     glVertex2i(40+tx,10+ty);
     glVertex2i(20+tx,40+ty);
     glVertex2i(20+tx,20+ty);
     glVertex2i(60+tx,40+ty);
     glVertex2i(60+tx,20+ty);
     glVertex2i(10+tx,38+ty);
     glVertex2i(-10+tx,38+ty);
     glEnd();
     
     //wings
     if(ind>20)
     ind = 0;
     ind = ind+1;
     glColor3f(1,0,0);
     glBegin(GL_POLYGON);
     glVertex2f(30.0+tx, 40.0+ty);
     glVertex2f(60.0+tx, 40.0+ty);
     if(ind<=10)
     {
     	glVertex2f(30.0+tx, 70.0+ty);
     	
	 }
     else
     glVertex2f(30.0+tx, 10.0+ty);
     glEnd();
     
     
	  glColor3f(1.0,0.0,0.0);
     glRecti(0,550,200,900);
     glRecti(200,0,350,400);
     glRecti(400,0,650,300);
     glRecti(800,170,1000,900);
     glRecti(1150,0,1440,200);
     glRecti(300,500,700,700);
     glRecti(500,400,700,500);
	 
	 
     
     
     glFlush();
}
//Timer function
void timer(int n)
{
     glutPostRedisplay();
     glutTimerFunc(1000/60,timer,0);
     if((tx>=1340 || ty>=850) || (ty<50 || tx<0) || (tx>100 && tx<350 && ty<=400) || (ty>490 &&ty<900 && tx<200) || (tx>230 && tx<700 && ty<700 && ty>450) || (tx>400 && tx<700 && ty<500 && ty>350) || (tx>350 && tx<650 && ty<300) || (tx>735 && tx<1000 && ty<900 && ty>120) || (tx>1060 && ty<200))
     {
     	flag = 0;
     	
     }
	 else if(tx>1000 && tx<1350 && ty>350 && ty<590)
      {
      	flag = 1;
   	  }
     else
     {
     	if(strcmp("up",dir)==0)
     	ty+=3;
     	if(strcmp("down",dir)==0)
     	ty-=3;
     	if(strcmp("left",dir)==0)
     	tx-=3;
     	if(strcmp("right",dir)==0)
     	tx+=3;
     	
	
 }
 
}


//Keyboard func
void keypress(GLint key,GLint x,GLint y)
{
     if(key==GLUT_KEY_UP)
     strcpy(dir,"up");
     if(key==GLUT_KEY_DOWN)
     strcpy(dir,"down");
     if(key==GLUT_KEY_LEFT)
     strcpy(dir,"left");
     if(key==GLUT_KEY_RIGHT)
     strcpy(dir,"right");
}
//Reshape func
void reshape(GLint w,GLint h)
{
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0,w,0.0,h);
     glClear(GL_COLOR_BUFFER_BIT);
}
//main function
int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutInitWindowSize(ww,wh);
    glutInitWindowPosition(40,50);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutCreateWindow("Flappy Bee");
    init();
    glutDisplayFunc(bee);
    
    glutTimerFunc(0,timer,0);
    glutSpecialFunc(keypress);  
    glutReshapeFunc(reshape);
    glutMainLoop();
}
