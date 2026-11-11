
#include <stdio.h>
#include <windows.h>
#include <GL/gl.h>	
#include "glut.h"	   


typedef struct {
    int width;
	int height;
	char* title;

	float field_of_view_angle;
	float z_near;
	float z_far;
} glutWindow;

glutWindow win;

float g_rotation = 0;
float g_rotation_speed = 0.05f;

void display() 
{
	// Clear Screen and Depth Buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		     
	glLoadIdentity();
 
	// Define a viewing transformation
	gluLookAt( 0,1,4, 0,0,0, 0,1,0);					  
 
	glPushMatrix();										
	glRotatef(g_rotation,0,1,0);
	glutSolidSphere(1.0,20,20);

      glTranslatef(2.0,0,0);						
	glutSolidSphere(0.2,20,20);

	glPopMatrix();										  

	g_rotation += g_rotation_speed;
	glutSwapBuffers();
}


void initialize () 
{
   // select projection matrix
    glMatrixMode(GL_PROJECTION);												
 
	// set the viewport
    glViewport(0, 0, win.width, win.height);									
 
	// set matrix mode
    glMatrixMode(GL_PROJECTION);												
 
	// reset projection matrix
    glLoadIdentity();															
    GLfloat aspect = (GLfloat) win.width / win.height;
 
	// set up a perspective projection matrix
	gluPerspective(win.field_of_view_angle, aspect, win.z_near, win.z_far);		
 
	// specify which matrix is the current matrix
	glMatrixMode(GL_MODELVIEW);													
    glShadeModel( GL_SMOOTH );
 
	// specify the clear value for the depth buffer
	glClearDepth( 1.0f );														
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
 
	// specify implementation-specific hints
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );						
 
    GLfloat amb_light[] = { 0.1, 0.1, 0.1, 1.0 };
    glLightModelfv( GL_LIGHT_MODEL_AMBIENT, amb_light );


    GLfloat diffuse[] = { 1.0, 0.0, 0.0, 1 };
    GLfloat specular[] = { 1.0, 0.0, 0.0, 1 };
    GLfloat light_position[]={-1.0, -1.0, 1.0, 0.0};
    glLightfv( GL_LIGHT0, GL_POSITION, light_position);
    glLightfv( GL_LIGHT0, GL_DIFFUSE, diffuse );
    glLightfv( GL_LIGHT0, GL_SPECULAR, specular );
    glEnable( GL_LIGHT0 );

    GLfloat diffuse1[] = { 0.0, 0.0, 1.0, 1 };
    GLfloat specular1[] = { 0.0, 0.0, 1.0, 1 };
    GLfloat light_position1[]={1.0, -1.0, 1.0, 0.0};
    glLightfv( GL_LIGHT1, GL_POSITION, light_position1);
    glLightfv( GL_LIGHT1, GL_DIFFUSE, diffuse1 );
    glLightfv( GL_LIGHT1, GL_SPECULAR, specular1 );
    glEnable( GL_LIGHT1 );


    glEnable( GL_COLOR_MATERIAL );
    glShadeModel( GL_SMOOTH );
    glLightModeli( GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE );
    glDepthFunc( GL_LEQUAL );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
	glClearColor(0.0, 0.0, 0.0, 1.0);
}


void keyboard ( unsigned char key, int mousePositionX, int mousePositionY )		
{ 
  switch ( key ) 
  {
    case 27:        
      exit ( 0 );   
      break;      

    default:      
      break;
  }
}

int main(int argc, char **argv) 
{
	// set window values
	win.width = 640;
	win.height = 480;
	win.title = "Test Lightening";
	win.field_of_view_angle = 45;
	win.z_near = 1.0f;
	win.z_far = 500.0f;

	// initialize and run program
	glutInit(&argc, argv);                                      // GLUT initialization
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );  // Display Mode
	glutInitWindowSize(win.width,win.height);				// set window size
	glutCreateWindow(win.title);					// create Window
	glutDisplayFunc(display);						// register Display Function
	glutIdleFunc( display );						// register Idle Function
    glutKeyboardFunc( keyboard );						// register Keyboard Handler
	initialize();
	glutMainLoop();							// run GLUT mainloop
	return 0;
}