#include<stdio.h>
#include<string.h>
typedef struct Q
{
    char player[500];
    char mark[2];
}S;
char pos[3][4]={{' ',' ',' ','\0'},{' ',' ',' ','\0'},{' ',' ',' ','\0'}};
int i,j;

//checkin function
int check()
{
    int i,c[8]={0,0,0,0,0,0,0,0},k=0,j,n=0;
    char y1,y2,y3;

    //diagonal checking
    for(i=0;i<3;i++)
    {
        if(pos[0][0]!=' ')
        {
            y1=pos[0][0];
            if(pos[i][i]==y1)
               c[6]++;
        }
        if(pos[0][2]!=' ')
        {
            y2=pos[0][2];
            if(pos[i][2-i]==y2)
               c[7]++;
        }
    }
    
    //horizontal checking
    for(i=0;i<3;i++)
    {
        if(pos[0][0]!=' ')
        {
            y1=pos[0][0];
            if(pos[0][i]==y1)
               c[0]++;
        }
        if(pos[1][0]!=' ')
        {
            y2=pos[1][0];
            if(pos[1][i]==y2)
               c[1]++;
        }
        if(pos[2][0]!=' ')
        {
            y3=pos[2][0];
            if(pos[2][i]==y3)
               c[2]++;
        }
    }
   //vertical checking
   for(i=0;i<3;i++)
   {
       if(pos[0][0]!=' ')
       {
           y1=pos[0][0];
           if(pos[i][0]==y1)
              c[3]++;
       }
       if(pos[0][1]!=' ')
       {
           y2=pos[0][1];
           if(pos[i][1]==y2)
              c[4]++;
       }
       if(pos[0][2]!=' ')
       {
           y3=pos[0][2];
           if(pos[i][2]==y3)
              c[5]++;
       }
   }

   for(i=0;i<8;i++)
   {
        if(c[i]==3)
        {
           n=1;
           break;
        }
        else
            n=0;
   }

   if(n) return 1;
   else return 0;
}

//displaying the grid
void display_grid()
{
    printf("\n\t %c  | %c  |%c\n\t____|____|____\n\t %c  | %c  |%c\n\t____|____|____\n\t %c  | %c  |%c\n\t    |    |\n\t",pos[0][0],pos[0][1],pos[0][2],pos[1][0],pos[1][1],pos[1][2],pos[2][0],pos[2][1],pos[2][2]);
}

int main()
{
    //initialization
    S q1,q2;display_grid();
    char p1[500],p2[500];
    int ti,i,x,y,choice=1,ch=0,over;
    printf("\nWelcome...\n\tplayers\n");
    printf("\nKindly,give your names please\n");
    printf("(please tap space tab after each name)\n");
    scanf("%s",p1);
    scanf("%s",p2);//printf("\n%d\t",p1);printf("%s\d",p2);
    while(choice)
    {
        printf("\nSo,\n%s and %s ...Its time for toss\n",p1,p2);
        printf("\nAnd the person who have won the toss is\n");
    //pause if you want to
        ti=toss();
    //toss
        if(ti==1)
        {
           printf("\n%s\n",p1);
           strcpy(q1.player,p1);
           strcpy(q2.player,p2);
        }
        else
        {
           printf("\n%s\n",p2);
           strcpy(q1.player,p2);
           strcpy(q2.player,p1);
        }
    //toss over
        printf("\n\n\tSo %s which mark you gonna choose\n\t'X' or 'O'\n",q1.player);
        scanf("%s",q1.mark);
    //selection
        strcpy(q2.mark,((strcmp(q1.mark,"x")==0)||(strcmp(q1.mark,"X")==0))?"O":"X");
        printf("\nSo, %s you have %s mark\n",q2.player,q2.mark);
    //the game begins
        printf("\nLets begin...\nOkay the grid with its co ordinates have been given\n");
        printf("\n\t0,0 |0,1 |0,2\n\t____|____|____\n\t1,0 |1,1 |1,2\n\t____|____|____\n\t2,0 |2,1 |2,2\n\t    |    |\n\t");
        printf("\nBoth players are required to give their positions to mark their position in the grid\n");
        printf("\nPositions to be given as ......X<space(atleast 1 tap)>Y  where (X,Y) are x and y coordinates\n");
    //first
        printf("\nSo,lets begin...\n\n\n");
        over=0;
        for(i=1;i<=5;i++)
        {
           if(i%2!=0)
           {
              printf("%s give your co ordinates\n(maintain space between the co ordinates)\n",q1.player);
              while(1)
              {
                 scanf("%d%d",&x,&y);
                 if((x>2)||(y>2)||(x<0)||(y<0)) printf("\nyeah funny!!\tgive properly again\n");
                 else if(pos[x][y]!=' ') printf("\nThe specified position is filled\nGive the co ordinates again\n");
                 else break;
              }
              pos[x][y]=q1.mark[0];
              printf("\nSo..,\n");
              display_grid();
           }
           else if(i%2==0)
           {
              printf("%s give your co ordinates\n(maintain space between the co ordinates)\n",q2.player);
              while(1)
              {
                 scanf("%d%d",&x,&y);
                 if((x>2)||(y>2)||(x<0)||(y<0)) printf("\nyeah funny!!\tgive properly again\n");
                 else if(pos[x][y]!=' ') printf("\nThe specified position is filled\nGive the co ordinates again\n");
                 else break;
              }
              pos[x][y]=q2.mark[0];
              printf("\nSo..,\n");
              display_grid();
          }
       }
       ch=check();i=0;
       if(ch==1)
       {
          printf("\nWoohhooo!! winner is %s\n",q1.player);
          over=1;
       }
    //if the game is not over by 5 fillings
      for(i=1;(i<=4)&&(over==0);i++)
      {
         if(i%2!=0)
         {
             printf("%s give your co ordinates\n(maintain space between the co ordinates)\n",q2.player);
             while(1)
              {
                 scanf("%d%d",&x,&y);
                 if((x>2)||(y>2)||(x<0)||(y<0)) printf("\nyeah funny!!\tgive properly again\n");
                 else if(pos[x][y]!=' ') printf("\nThe specified position is filled\nGive the co ordinates again\n");
                 else break;
              }
            pos[x][y]=q2.mark[0];
            printf("\nSo..,\n");
            display_grid();
            ch=check();
            if(ch==1)
            {
               printf("\nWoohhooo!! winner is %s\n",q2.player);
               over=1;break;
            }
        }
        else
        {
            printf("%s give your co ordinates\n(maintain space between the co ordinates)\n",q1.player);
             while(1)
              {
                 scanf("%d%d",&x,&y);
                 if((x>2)||(y>2)||(x<0)||(y<0)) printf("\nyeah funny!!\tgive properly again\n");
                 else if(pos[x][y]!=' ') printf("\nThe specified position is filled\nGive the co ordinates again\n");
                 else break;
              }
            pos[x][y]=q1.mark[0];
            printf("\nSo..,\n");
            display_grid();
            ch=check();
            if(ch==1)
            {
               printf("\nWoohhooo!! winner is %s\n",q1.player);
               over=1;break;
            }
       }
     }
     if(over==0){ printf("\nSorry.. its a tie\n");over=1;}
    //retry
      if(over==1)
      {
         printf("\nWanna try again?...\n(yes->1/no->0)\n");
         scanf("%d",&choice);
         if(choice==1)
         {pos[0][0]=' ';pos[0][1]=' ';pos[0][2]=' ';pos[0][3]='\0';pos[1][0]=' ';pos[1][1]=' ';pos[1][2]=' ';pos[1][3]='\0';pos[2][0]=' ';pos[2][1]=' ';pos[2][2]=' ';pos[2][3]='\0';}
      }
  }
      return 0;
}

//toss function
int toss()
{
    int *tos,jar;
    tos = (int *)malloc(sizeof(int));
    jar = tos;
    jar/=10;
    free(tos);
    return (jar%2);
}
