#include <GL/glut.h>
#include <sys/time.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<SOIL/SOIL.h>
#include<string.h>
#include <math.h>
GLuint tex_2d;

int menuin=0;


int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1)
{
    long int diff = (t2->tv_usec + 1000000 * t2->tv_sec) - (t1->tv_usec + 1000000 * t1->tv_sec);
    result->tv_sec = diff / 1000000;
    result->tv_usec = diff % 1000000;

    return (diff<0);
}



float count2=0.03f;


int count1=0,count3=40,count5=0;
int i=0;
float count=0.0f;

bool c=true;


float xlocation=0.0f;
float yLocation = -1.0f; // Keep track of our position on the y axis.
bool movedown = true;



float j[]={-1.0,-0.5,0.5,1.5,2.0,2.5,-1.5,-2.0,-3.0,-3.5,-4.5,-5.5,-6.5,-1.0,-0.5,0.5,1.5,2.0,2.5,-1.5,-2.0,-3.0,-3.5,-4.5,-5.5,-6.5,-7.5,-8.5,-9.5,-10.5,-11.5,-12.5,-13.5,-14.5,-15.5,-16.5,-17.5,-18.5,-19.5,-20.5,-21.5,-22.5,-23.5,-24.5,-25.5,-26.5,-27.5,-28.5,-29.5,-30.5,-31.5,-32.5,-33.5,-34.5,-35.5,-36.5,-37.5,-38.5,-39.5,-40.5,
-41.5,-42.5,-43.5,-44.5,-45.5,-46.5,-47.5,-48.5,-49.5,-50.5};




GLuint tex_2d;



void drawstring( int x, int y,int c,const char *st) //this function will print the character
{
    int m,l,i;
    char str[50];
    sprintf(str,"%d",c);


	l=strlen( st ); // see how many characters are in text string.
	m=strlen( str ); // see how many characters are in text string.


	glColor3f(0.0f,1.0f,1.0f);
	glRasterPos2i( x, y); // location to start printing text


	for( i=0; i < l; i++)  // loop until i is greater then l
	{

		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);// Print a character on the screen


	}

if(menuin==1)
{

        glRasterPos2f( x, y-20); // location to start printing text
		for( i=0; i < m; i++)  // loop until i is greater then l
	{

		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);// Print a character on the screen

	}
}
}

void menudisplay(void)
{
    GLint w=1200;
    GLint h=1000;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glScalef(1, -1, 1);
    glTranslatef(0, -h, 0);
    glMatrixMode(GL_MODELVIEW);

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    drawstring(550, 300,0, "GRAVITY FALL");
    drawstring(450, 360,0, "Press 1 to play the Game.");
    drawstring(450, 420, 0,"Press 2 to Exit ");

    drawstring(450, 540,0, "Rules for the Game : ");
    //drawstring(450, 600,0, "Controls : Press S to kick the ball straight");
    drawstring(600, 600,0, "CONTROLS");
    drawstring(450, 640,0, "            Press A to move ball to the left");
    drawstring(450, 680,0, "            Press D to move the ball to the right");
    drawstring(450, 720,0, "            *Try to stay in the screen");

    glFlush();
}



void nextp()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,1000.0,0.0,700.0);


    glEnable(GL_TEXTURE_2D);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    tex_2d = SOIL_load_OGL_texture
         (	 "ome.jpg",
             SOIL_LOAD_AUTO,
             SOIL_CREATE_NEW_ID,
             SOIL_FLAG_COMPRESS_TO_DXT
         );
    glBindTexture(GL_TEXTURE_2D, tex_2d);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBegin(GL_POLYGON);
        glTexCoord2f(1.0, 0.0);
        glVertex2f(1000,700);
        glTexCoord2f(0.0, 0.0);
        glVertex2f(0,700);
        glTexCoord2f(0.0, 1.0);
        glVertex2f(0,0);
        glTexCoord2f(1.0, 1.0);
        glVertex2f(1000,0);
    glEnd();
    glDisable(GL_TEXTURE_2D);


drawstring(900,600, count ,"SCORE:");

    //glutSwapBuffers();
 //   glFlush();



}

void gameover()
{

//a:
while(1)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,400.0,0.0,300.0);




    glEnable(GL_TEXTURE_2D);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    tex_2d = SOIL_load_OGL_texture
         (	 "game.jpg",
             SOIL_LOAD_AUTO,
             SOIL_CREATE_NEW_ID,
             SOIL_FLAG_COMPRESS_TO_DXT
         );
    glBindTexture(GL_TEXTURE_2D, tex_2d);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBegin(GL_POLYGON);

        glTexCoord2f(0.0, 0.0);
        glVertex2f(0.0,300.0);

        glTexCoord2f(1.0, 0.0);
        glVertex2f(400.0,300.0);

        glTexCoord2f(1.0, 1.0);
        glVertex2f(400.0,0.0);


        glTexCoord2f(0.0, 1.0);
        glVertex2f(0.0,0.0);

    glEnd();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();

    drawstring(300,280, count ,"YOUR FINAL SCORE IS:");

    glFlush();
}

//goto a;
}





void keyboard (unsigned char key, int x, int y)
{
	switch (key)
	{

	case 27:
        exit(0);

 if(menuin==1)
{

	case 'a':
		if(xlocation>-1.5f) //to check that ball stays within the screen coordinates in horizontal direction
		{
		xlocation=xlocation-0.15f;
		glutPostRedisplay();              /*  a key moves the ball in -ve x direction */
		}
		break;

	case 'd':
		if(xlocation<1.5f)	//to check that ball stays within the screen coordinates in horizontal direction
		{
		xlocation=xlocation+0.15f;		/*  d key moves the ball in -ve x direction */
		glutPostRedisplay();
		}
		break;
}

    case '1' : menuin=1;
                        glutPostRedisplay();
                        break;
    case '2' : exit(0);

	default:
		break;
	}
}






void display(void)
{


struct timeval tvBegin, tvEnd, tvDiff;
    gettimeofday(&tvBegin, NULL);


if(menuin==0)
    menudisplay();



if(menuin==1)
{

    nextp();

    if(count1==1)
    {
        gameover();


    }



    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    double winHt = 2.5; //half-height of window
    glOrtho (-winHt * 64/48.0, winHt*64/48.0, -winHt, winHt, 0.1, 100.0);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();









	if(movedown)
	{

	glPushMatrix();
	glLoadIdentity();// Load the Identity Matrix to reset our drawing locations
	glColor3f(1.0f,0.0f,0.0f);
	glTranslatef(0.0f, 3.5f ,-5.0f); // Push eveything 5 units back into the scene, otherwise we won't see the primitive
	glTranslatef(xlocation, yLocation,0.0f); // Translate our object along the y axis
	glutSolidSphere(.15,50,50);
	glPopMatrix();



	}


	for(i=0;i<count3;i++)  //to create platforms on +ve x direction
	{
    glPushMatrix();
	glLoadIdentity();
	glColor3f(1.0f,1.0f,1.0f);
	glTranslatef(1.5f, j[i] ,-5.0f);
	glScalef(4.0,0.2,0.0);
	glutSolidCube(.15);
    glPopMatrix();
	}


	for(i=0;i<count3;i++)//to create platforms on -ve x direction
	{

	    glPushMatrix();
		glLoadIdentity();
		glColor3f(1.0f,1.0f,1.0f);
		glTranslatef(-1.5f, j[i] ,-5.0f);
		glScalef(4.0,0.2,0.0);




        j[i]=j[i]+0.008f;

		if(tvDiff.tv_sec>=2.0)
		j[i]=j[i]+count2;



        //count5++;
        //printf("%d\n",count5);
		glutSolidCube(.15);
        glPopMatrix();
	}





    drawstring(1.0f,3.0f, count ,"SCORE:");


	glFlush();	// Flush the OpenGL buffers to the window



    if(xlocation>=-1.0f && xlocation<=1.0f)
        {
        //movedown=true;
       yLocation -= 0.01f; // Move down along our yLocation
       count+=0.04f;
        }

else

        {
           // movedown=false;
            if(xlocation!=-1.0f || xlocation!=1.0f)
                {

                    if(j[1]>yLocation)
                        {
                            if(j[2]>yLocation)
                            {
                                nextp();





                            glMatrixMode (GL_PROJECTION);
                            glLoadIdentity();
                            double winHt = 2.5; //half-height of window
                            glOrtho (-winHt * 64/48.0, winHt*64/48.0, -winHt, winHt, 0.1, 100.0);
                            glMatrixMode (GL_MODELVIEW);
                            glLoadIdentity();





                                yLocation+=0.008f;

                                if(tvDiff.tv_sec>=2.0)
                                yLocation=yLocation+count2;

                                glPushMatrix();
                                glLoadIdentity();// Load the Identity Matrix to reset our drawing locations
                                glColor3f(1.0f,0.0f,0.0f);
                                glTranslatef(xlocation,yLocation,-5.0f);
                                glutSolidSphere(.15,50,50);
                                glPopMatrix();


                                count+=0.009f;


                                glutPostRedisplay();

                            }
                        }
                    }


            }

 gettimeofday(&tvEnd, NULL);
 timeval_subtract(&tvDiff, &tvEnd, &tvBegin);




    if(yLocation>-0.5f)
    gameover();



	if (yLocation < -6.5f) // Else if we have gone down too far
	{
		yLocation=-1.0f;	//starting location of ball in y axis
		xlocation=0.0f;		//start the ball from centre of display
		count1++;
        glutPostRedisplay();
	}

}

}







void mouse(int btn, int state, int x, int y)
{
    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
      {
         printf("%d %d\n" , x,y);
         display();
      }

}






void reshape(int width, int height) {
	glViewport(0, 0, (GLsizei)width, (GLsizei)height); // Set our viewport to the size of our window
	glMatrixMode(GL_PROJECTION); // Switch to the projection matrix so that we can manipulate how our scene is viewed
	glLoadIdentity(); // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)
	gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0); // Set the Field of view angle (in degrees), the aspect ratio of our window, and the new and far planes
	glMatrixMode(GL_MODELVIEW); // Switch back to the model view matrix, so that we can start drawing shapes correctly
}



int main(int argc, char **argv) {
	glutInit(&argc, argv); // Initialize GLUT
	glutInitDisplayMode(GLUT_SINGLE); // Set up a basic display buffer (only single buffered for now)
	glutInitWindowSize(1200, 700); // Set the width and height of the window
	glutInitWindowPosition(0, 0); // Set the position of the window
	glutCreateWindow("Gravity FALL"); // Set the title for the window
	glutDisplayFunc(display); // Tell GLUT to use the method "display" for rendering
	glutIdleFunc(display); // Tell GLUT to use the method "display" as our idle method as well
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape); // Tell GLUT to use the method "reshape" for reshaping
	glutMainLoop(); // Enter GLUT's main loop
}
