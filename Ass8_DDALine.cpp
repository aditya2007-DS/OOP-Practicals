//8.DDA Line
#include<GL/glut.h>
#include<cmath>
using namespace std;

int ch=0;

void init(void){
    glClearColor(1.0,1.0,1.0,1.0);  //sets background color white
    glColor3f(0.0,0.0,0.0);         //sets drawing color black
    glPointSize(2.0);               //sets point size
    glMatrixMode(GL_PROJECTION);    
    glLoadIdentity();               //replaces current matrix with unit matrix
    gluOrtho2D(-320,320,-240,240);  //define left ,right, bottom ,top(2 dimensional) parameter of window
}

//DDA Line Drawing Algorithm
void dda(int x1, int y1, int x2, int y2){
    int dx=x2-x1;
    int dy=y2-y1;
    int length;
    if(abs(dx)>abs(dy)){
       length=dx;
    }else{
       length=dy;
    }
    
    float DX=dx/float(length);
    float DY=dy/float(length);
    float x=x1;
    float y=y1;
    
     
    for(int i=0;i<=length;i++){
    glBegin(GL_POINTS);                //function to plot points
       glVertex2f(round(x),round(y));  //plot points
       x+=DX;
       y+=DY;
       glEnd();                       //end the plotting
       
    }
    glFlush();                        //Flushes all the opengl functions and immediately displays on screen
    
    
}

void axisPlot(){
     for(int i=-320;i<320;i++){   //x-axis
        glBegin(GL_POINTS);
        glVertex2f(i,0);
        glEnd();
     }
     for(int i=-240;i<240;i++){   //y-axis
        glBegin(GL_POINTS);
        glVertex2f(0,i);
        glEnd();
     }
     
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    axisPlot();
    switch(ch){
    case 1:
       dda(-300,50,-100,100);  //simple line
       break;
       
       case 2:
       
       dda(20,40,70,40); //Square wave
       dda(70,40,70,90);
       dda(70,90,120,90);
       dda(120,40,120,90);
       dda(120,40,170,40);
       dda(170,40,170,90);
       dda(170,90,220,90);
       dda(220,40,220,90);
       dda(220,40,270,40);
       break;
       
       case 3:
       
       dda(20,-100,50,-10); //Triangular wave 1
       dda(80,-100,50,-10);
       dda(80,-100,110,-10);
       dda(140,-100,110,-10);
       dda(140,-100,170,-10);
       dda(200,-100,170,-10);
       break;
       
       case 4:
       
       dda(-200,-100,-200,-50);  //Traingular wave 2
       dda(-200,-50,-140,-100);
       dda(-140,-100,-140,-50);
       dda(-140,-50,-80,-100);
       dda(-80,-100,-80,-50);
       dda(-80,-50,-20,-100);
       break;
    }
    glFlush();
    glutSwapBuffers();          //swap the buffers back to front
}

void menu(int option){
   switch(option){
     case 1:
     ch=1;
     break;
     
     case 2:
     ch=2;
     break;
     
     case 3:
     ch=3;
     break;
     
     case 4:
     ch=4;
     break;
   }
   glutPostRedisplay();     //to again display the window
 }
 

int main(int argc, char** argv){
   glutInit(&argc,argv);      //initialize opengl utility toolkit
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  //double buffer and rgb color model is used
   glutInitWindowSize(640,480);                  //length and width of window
   glutInitWindowPosition(100,100);              //sets position of window on screen
   glutCreateWindow("DDA Line Drawing Algorithm");  //creation of window with name
   init();                                         //call init function
   glutCreateMenu(menu);                         //create the menu
   glutAddMenuEntry("Simple line",1);            //Add simple line to first position of menu
   glutAddMenuEntry("Square Wave",2);            //Add square wave to second position of menu
   glutAddMenuEntry("Triangular wave 1",3);      //Add triangular wave 1 to third position of menu
   glutAddMenuEntry("Triangular wave 2",4);      //Add triangular wave 2 to fourth position of menu
   glutAttachMenu(GLUT_RIGHT_BUTTON);            //attach the menu to right button of mouse
   glutDisplayFunc(display);                    //call the display function
   glutMainLoop();                              //display in the loop
   return 0;
}
