#include <stdio.h> 
#include <GL/glut.h> 
#include <math.h>
#define pi 3.14159265358979323846264338

int pos_x;
int pos_y;

struct mi_letra {
	 char letra;
	 GLboolean mat [8][8];
	 GLfloat rgb[3];
	 };

typedef struct mi_letra LETRA;

LETRA letrasm[6];

struct abc
{
  int letra_g [8][8];
};

typedef struct abc ABC;

ABC abc_letras[24];




 void guarda_letra(){

 }

int x=150;
int palabral[6];

void circulos(int xt,int num){
  int y=200,k,j;
  int seg =20;
  int radio=15;
  int i=0;
  glColor3f(0,0,0);
  for (j = 8; j >= 0; j--)
  {
  for ( k = 8; k>= 0; k--)
  {
    if (letrasm[num].mat[j][k]==1)
    {
      glColor3f(letrasm[num].rgb[0],letrasm[num].rgb[1],letrasm[num].rgb[2]);
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
  x=xt;
  y=y+30;
  }
 }
void dibuja(void) {
  int i,xt=150;
	glClear(GL_COLOR_BUFFER_BIT);
  for ( i = 0; i < 6; i++)
  {
   circulos(xt,i);
   xt=x+30*8; 
  }
	glFlush(); }

void opciones(int opcion){
  int letra;
  if (pos_x>=150 && pos_x<=390 )
  {
    letra=0;
  }

  switch (opcion)
  {
  case 1:
    letrasm[palabral[letra]].rgb[0]=0;
    letrasm[palabral[letra]].rgb[1]=255;
    letrasm[palabral[letra]].rgb[2]=0;
    break;
  
  default:
    break;
  }

  glutPostRedisplay();
  



}
void rastrea(int button, int state, int xpos, int ypos){
  pos_x=xpos;
  pos_y=ypos;
  glutCreateMenu(opciones);
  glutAddMenuEntry("Verde",1);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
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
	 gluOrtho2D(0,1920,0,1080);}
	 


 void convierte(char palabra,int num){
     int conversion;
     int i,j;
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

  letrasm[num].letra=palabra;
  for (i = 0; i < 8; i++)
    {
      for (j = 0; j < 8; j++)
     {
        if (abc_letras[conversion].letra_g[i][j]==1)
        {
         letrasm[num].mat[i][j]=GL_TRUE;
        }
        else{
         letrasm[num].mat[i][j]=GL_FALSE;
        }

        
      }
      
  }

  letrasm[num].rgb[0]=255;
  letrasm[num].rgb[1]=0;
  letrasm[num].rgb[2]=0;


 }
 
int main(int argc, char** argv)
{	
	int i,j,k,l;
  char palabra[6];
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
            abc_letras[l].letra_g[j][k]=i;
            fscanf (fp, "%d", &i);
          }
        }
        letrasm[l].rgb[0]=255;
      }
   }
}

fclose(fp);

printf("Introduce una plabara \n");
scanf("%s",palabra);

for ( i = 0; i < 6; i++)
{
 convierte(palabra[i],i);
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
glutInitWindowSize(1920,1080);    
glutInitWindowPosition(100, 150);    
glutCreateWindow("Palabra");
glutReshapeFunc(ajusta);
glutMouseFunc(rastrea);
glutDisplayFunc(dibuja);
glutMainLoop();




 return 0;
}


