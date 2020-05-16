#include <stdio.h> 
#include <GL/glut.h> 
#include <math.h>
#define pi 3.14159265358979323846264338

GLboolean rojo=GL_TRUE;

struct abc {
	 char palabra [6];
	 char letra [8][8];
	 GLfloat rgb [0][3];
	 };

typedef struct abc ABC;

ABC letrasm[2];

 void guarda_letra(){

 }


void circulos(){
  int x=150;
  int y=200,k,j;
  int seg =20;
  int radio=15;
  int i=0;
  glColor3f(0,0,0);
  for (j = 8; j >= 0; j--)
  {
  for ( k = 8; k>= 0; k--)
  {
    if (letrasm[0].letra[j][k]==1)
    {
      glColor3f(255,0,0);
    }
    else{
      glColor3f(0,0,0);
    }
    
    glBegin(GL_POLYGON);
    for(i=0; i<=360;  i+=360/seg)         
    glVertex2i(x+radio*cos(i*pi/180),y+radio*sin(i*pi/180));
    x=x+30;  
    glEnd();
  }
  x=150;
  y=y+30;
  }
  
  
 }

void cuadros(){
  glColor3f(255,0,0);
  glPointSize(100);
  glBegin(GL_POINTS);
  glVertex2i(150, 200);
  glEnd();
 }
 
 void ajusta(int ancho, int alto){    
	 glClearColor(1.0,1.0,1.0,0.0);    
	 glMatrixMode(GL_PROJECTION);    
	 glLoadIdentity();    
	 gluOrtho2D(0,640,0,480);}
	 
void dibuja(void) {
  const GLubyte color[3]={0,255,0};
	glClear(GL_COLOR_BUFFER_BIT);
  circulos();
	glFlush(); }

 int convierte(char palabra){
     int conversion;
     switch (palabra)
     {
     case 'A':
        conversion=0;
         break;
     case 'B':
        conversion=1;
        break;
     default:
         break;
     }

return conversion;

 }
 
int main(int argc, char** argv)
{	
	int i,j,k,l;
  char palabra[6];
  int palabral[6];
	FILE *fp;
	fp=fopen("letras.txt","r");
	  if(fp == NULL) 
   {
      fprintf(stderr,"Error opening file");
      return(-1);
   }


fscanf (fp, "%d", &i);    
while (!feof (fp)){
    {  
    for ( l = 0; l < 2; l++)
    {
      for ( j = 0; j < 8; j++)
      {
          for ( k = 0; k < 8; k++)
          {
            letrasm[l].letra[j][k]=i;
            fscanf (fp, "%d", &i);
          }
        }
      }
   }
}

fclose(fp);

printf("Introduce una plabara \n");
scanf("%s",palabra);

for (i = 0; i < 6; i++)
{
    palabral[i]=convierte(palabra[i]);
}


/*
 *for ( l = 0; l < 6; l++)
{
for ( k = 0; k < 8; k++)
{
    for ( j = 0; j < 8; j++){
    printf("%i ",letrasm[palabral[l]].letra[k][j]);
}
printf("\n");
}
}




*/

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(640,480);    
glutInitWindowPosition(100, 150);    
glutCreateWindow("Palabra");
glutReshapeFunc(ajusta);
glutDisplayFunc(dibuja); 
glutMainLoop();




 return 0;
}


