#include <windows.h> //for Code::Blocks user
#include "glut.h"
#include <stdio.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <stdlib.h>

GLuint texture[6];

double rotate_y=0; 
double rotate_x=0;

void specialKeys();
 
struct Image {
    unsigned long sizeX;
    unsigned long sizeY;
    char *data;
};

typedef struct Image Image;

int ImageLoad(char *filename, Image *image) {

    FILE *file;
    unsigned long size; // size of the image in bytes.
    unsigned long i; // standard counter.
    unsigned short int planes; // number of planes in image (must be 1)
    unsigned short int bpp; // number of bits per pixel (must be 24)
    char temp; // temporary color storage for bgr-rgb conversion.
    // make sure the file is there.
    if ((file = fopen(filename, "rb"))==NULL){
        printf("File Not Found : %s\n",filename);
        return 0;
    }
    // seek through the bmp header, up to the width/height:
    fseek(file, 18, SEEK_CUR);
    // read the width
    if ((i = fread(&image->sizeX, 4, 1, file)) != 1) {
        printf("Error reading width from %s.\n", filename);
        return 0;
    }
    //printf("Width of %s: %lu\n", filename, image->sizeX);
    // read the height
    if ((i = fread(&image->sizeY, 4, 1, file)) != 1) {
        printf("Error reading height from %s.\n", filename);
        return 0;
    }
    //printf("Height of %s: %lu\n", filename, image->sizeY);
    // calculate the size (assuming 24 bits or 3 bytes per pixel).
    size = image->sizeX * image->sizeY * 3;
    // read the planes
    if ((fread(&planes, 2, 1, file)) != 1) {
        printf("Error reading planes from %s.\n", filename);
        return 0;
    }
    if (planes != 1) {
        printf("Planes from %s is not 1: %u\n", filename, planes);
        return 0;
    }
    // read the bitsperpixel
    if ((i = fread(&bpp, 2, 1, file)) != 1) {
        printf("Error reading bpp from %s.\n", filename);
        return 0;
    }
    if (bpp != 24) {
        printf("Bpp from %s is not 24: %u\n", filename, bpp);
        return 0;
    }
    // seek past the rest of the bitmap header.
    fseek(file, 24, SEEK_CUR);
    // read the data.
    image->data = (char *) malloc(size);
    if (image->data == NULL) {
        printf("Error allocating memory for color-corrected image data");
        return 0;
    }
    if ((i = fread(image->data, size, 1, file)) != 1) {
        printf("Error reading image data from %s.\n", filename);
        return 0;
    }
    for (i=0;i<size;i+=3) { // reverse all of the colors. (bgr -> rgb)
        temp = image->data[i];
        image->data[i] = image->data[i+2];
        image->data[i+2] = temp;
    }
    // we're done.
    return 1;
}

Image * loadTexture(char* picture_file){
    Image *image1;
    // allocate space for texture
    image1 = (Image *) malloc(sizeof(Image));
    if (image1 == NULL) {
        printf("Error allocating space for image");
        exit(0);
    }
    if (!ImageLoad(picture_file, image1)) {
        exit(1);
    }
    return image1;
}

void myinit(void)
{
    glClearColor (0.5, 0.5, 0.5, 0.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    Image *image1 = loadTexture("p1.bmp");
    if(image1 == NULL){
        printf("Image1 was not returned from loadTexture\n");
        exit(0);
    }

    Image *image2 = loadTexture("p2.bmp");
    if(image2 == NULL){
        printf("Image2 was not returned from loadTexture\n");
        exit(0);
    }

    Image *image3 = loadTexture("p3.bmp");
    if(image3 == NULL){
        printf("Image3 was not returned from loadTexture\n");
        exit(0);
    }

    Image *image4 = loadTexture("p4.bmp");
    if(image4 == NULL){
        printf("Image4 was not returned from loadTexture\n");
        exit(0);
    }

    Image *image5 = loadTexture("p5.bmp");
    if(image5 == NULL){
        printf("Image5 was not returned from loadTexture\n");
        exit(0);
    }

    Image *image6 = loadTexture("p6.bmp");
    if(image6 == NULL){
        printf("Image6 was not returned from loadTexture\n");
        exit(0);
    }

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    // Create Texture
    glGenTextures(6, texture);

    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //scale linearly when image smalled than texture
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY, 0,
    GL_RGB, GL_UNSIGNED_BYTE, image1->data);

    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //scale linearly when image smalled than texture
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image2->sizeX, image2->sizeY, 0,
    GL_RGB, GL_UNSIGNED_BYTE, image2->data);


    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //scale linearly when image smalled than texture
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image3->sizeX, image3->sizeY, 0,
    GL_RGB, GL_UNSIGNED_BYTE, image3->data);

    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //scale linearly when image smalled than texture
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image4->sizeX, image4->sizeY, 0,
    GL_RGB, GL_UNSIGNED_BYTE, image4->data);

    glBindTexture(GL_TEXTURE_2D, texture[4]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //scale linearly when image smalled than texture
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image5->sizeX, image5->sizeY, 0,
    GL_RGB, GL_UNSIGNED_BYTE, image5->data);

    glBindTexture(GL_TEXTURE_2D, texture[5]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //scale linearly when image smalled than texture
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image6->sizeX, image6->sizeY, 0,
    GL_RGB, GL_UNSIGNED_BYTE, image6->data);

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_FLAT);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );

//------------FRONT------------------
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-0.5, -0.5, -0.5);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(0.5, 0.5, -0.5);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-0.5, 0.5, -0.5);
    glEnd();

//-----------------BOTTOM-------------
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-0.5, -0.5, -0.5);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(0.5, -0.5, 0.5);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-0.5, -0.5, 0.5);
    glEnd();

//-----------------LEFT-------------
    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-0.5, -0.5, -0.5);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-0.5, -0.5, 0.5);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-0.5, 0.5, 0.5);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-0.5, 0.5, -0.5);
    glEnd();

//-----------------BACK-------------
    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-0.5, -0.5, 0.5);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-0.5, 0.5, 0.5);
    glTexCoord2f(1.0, 1.0);   
    glVertex3f(0.5, 0.5, 0.5);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(0.5, -0.5, 0.5);
    glEnd();

//-----------------RIGHT-------------
    glBindTexture(GL_TEXTURE_2D, texture[4]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.5, -0.5, 0.5);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(0.5, 0.5, 0.5);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(0.5, 0.5, -0.5);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(0.5, -0.5, -0.5);
    glEnd();

//-----------------TOP-------------
    glBindTexture(GL_TEXTURE_2D, texture[5]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-0.5, 0.5, 0.5);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-0.5, 0.5, -0.5);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(0.5, 0.5, -0.5);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(0.5, 0.5, 0.5);
    glEnd();
    glutSwapBuffers();
}

void myReshape(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0*(GLfloat)w/(GLfloat)h, 1.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -3.6);
}


// ----------------------------------------------------------
// specialKeys() Callback Function
// ----------------------------------------------------------
void specialKeys( int key, int x, int y ) {
  //  Right arrow - increase rotation by 5 degree
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;
  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;
  else if (key == GLUT_KEY_UP)
    rotate_x += 5;
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;
  //  Request display update
  glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640,480);
    glutCreateWindow("Texture Mapping - Programming Techniques");
    myinit();
    glutReshapeFunc (myReshape);
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}