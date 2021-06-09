 #include<stdio.h>
 #include<conio.h>
 #include<stdlib.h>
 #include<unistd.h>
 #include<windows.h>
 int i,j,height=30;
 int width=30,gameover,score;
 int x,y,fruitx,fruity,flag;

 //Function to draw a boundary

 void draw()
 {
     system("cls");

     for(int i=0;i<height;i++)
     {
         for(int j=0;j<width; j++)
         {
             if(i==0||i==width-1||j==0||j==height-1)
             {
                 printf("#");
             }

             else{
                 if(i==x &&j==y)
                 printf("0");

                 else if(i==fruitx && j==fruity)
                 printf("*");
             
             else
                 printf(" ");                
             }
         }

         printf("\n");

          
     }
     //print the score after the game end
         printf("score = %d",score);
         printf("\n");
         printf("press 'x' to quit the game");
 }

 void setup()
 {
     gameover =0;
    x=height/2;
    y= width/2;
    label1:
    fruitx = rand()%30;
    if(fruitx==0)
    {
        goto label1;
    }

    label2:
    fruity = rand()%30;
    if(fruity==0)
    {
        goto label2;
    }
    score = 0;
 }

 void input()
 {
     if(kbhit())
     {
         switch(getch())
         {
             case 'a':
             flag=1;
             break;

             case 's':
             flag =2;
             break;

             case 'd':
             flag = 3;
             break;

             case 'w':
             flag = 4;
             break;

             case 'x':
             break;

         }
     }
 }

 void logic()
 {
     sleep(0.01);
     switch(flag)
     {
         case 1 :
         y--;
         break;

         case 2:
         x++;
         break;

         case 3:
         y++;
         break;

         case 4:
         x--;
         break;

         default:
         break;
     }

     if(x<0||x>height||y<0||y>width)
     {
          gameover=1;
     }

     if(x==fruitx && y==fruity)
     {
         label3:
         fruitx = rand()%30;
         if(fruitx==0)
         {
             goto label3;
         }
         label4:
         fruity=rand()%30;
         if(fruity==0)
         {
             goto label4;
         }
         score += 10;
     }
 }

 int main()
 {
     int m,n;
     //function call
    
     setup();

     while(!gameover)
     {
         draw();
         input();
         logic();
     }
     return 0;
 }