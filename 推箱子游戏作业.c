#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
int h,x,y;
int step1,step2,step3,step4; 
	int i,j;
	int m[6][6]={0};
	int m3[9][10]={0};
	int m4[9][12]={0};
	int tu[6][6]={{1,1,0,1,1,1},{1,1,4,1,1,1},{1,1,3,4,3,0},{0,4,3,5,1,1},{1,1,1,3,1,1},{1,1,1,0,1,1}}; //0代表箱子应该到的地方@，1代表墙!，3代表箱子#，4代表路^，5代表人& ,
	//2代表箱子到了该到的位置 
	int tu2[6][6]={{1,0,1,1,1,1},{1,3,1,1,1,1},{0,3,5,1,4,1},{1,3,4,3,4,0},{1,4,1,1,4,1},{1,0,1,1,1,1}};
	int tu3[9][10]={{4,4,1,1,1,1,4,4,4,4},{4,1,1,0,1,1,4,4,4,4},{4,1,4,4,4,1,1,1,1,1},{1,1,4,4,4,4,3,4,4,1},{1,1,4,4,1,3,5,3,4,1},{1,0,4,4,1,4,3,4,4,1},{1,1,1,4,4,4,1,1,0,1},
	{4,4,1,0,1,1,1,1,1,1},{4,4,1,1,1,4,4,4,4,4}};
	int tu4[9][12]={{4,4,1,1,1,1,4,1,1,1,1,4},{1,1,1,4,4,1,1,1,4,4,1,4},{1,0,1,4,4,3,4,3,4,4,1,1},{1,4,4,3,4,3,5,1,1,4,1,1},{1,4,1,0,1,4,3,4,4,4,0,1},{1,4,1,4,4,4,4,4,4,1,1,1},
	{1,4,4,4,1,4,1,4,4,4,0,1},{1,1,1,4,1,0,1,1,1,1,1,1},{4,4,1,1,1,1,1,4,4,4,4,4}};
	int map()
	{
		for(i=0;i<6;i++)
		{
		for(j=0;j<6;j++)
		{
		  	if (tu[i][j]==0)
			  printf("★");
			if(tu[i][j]==1)
			  printf("■");
			if(tu[i][j]==3)
			  printf("□");
			if(tu[i][j]==4)
			  printf("  ");
			if(tu[i][j]==5)
			  printf("♀");   
			if(tu[i][j]==2)
			  printf("★");                                                      
		}
		printf("\n");
	   }
		return 0;
	}
	int map2()
	{
		for(i=0;i<6;i++)
		{
		for(j=0;j<6;j++)
		{
		  	if (tu2[i][j]==0)
			  printf("★");
			if(tu2[i][j]==1)
			  printf("■");
			if(tu2[i][j]==3)
			  printf("□");
			if(tu2[i][j]==4)
			  printf("  ");
			if(tu2[i][j]==5)
			  printf("♀");   
			if(tu2[i][j]==2)
			  printf("★");                                                      
		}
		printf("\n");
	   }
		return 0;
	}
	int map3()
	{
		for(i=0;i<9;i++)
		{
		for(j=0;j<10;j++)
		{
		  	if (tu3[i][j]==0)
			  printf("★");
			if(tu3[i][j]==1)
			  printf("■");
			if(tu3[i][j]==3)
			  printf("□");
			if(tu3[i][j]==4)
			  printf("  ");
			if(tu3[i][j]==5)
			  printf("♀");   
			if(tu3[i][j]==2)
			  printf("★");                                                      
		}
		printf("\n");
	   }
		return 0;
	}
	int map4()
	{
		for(i=0;i<9;i++)
		{
		for(j=0;j<12;j++)
		{
		  	if (tu4[i][j]==0)
			  printf("★");
			if(tu4[i][j]==1)
			  printf("■");
			if(tu4[i][j]==3)
			  printf("□");
			if(tu4[i][j]==4)
			  printf("  ");
			if(tu4[i][j]==5)
			  printf("♀");   
			if(tu4[i][j]==2)
			  printf("★");                                                      
		}
		printf("\n");
	   }
		return 0;
	}
	int local()
	{
	
		for(x=0;x<6;x++)
		 for(y=0;y<6;y++)
		 {
		 	if(tu[x][y]==5)
		 	{
		 	return 0; 
			 }
		 }
		 return 0;
	}
	 int count1()
 {
     int n=0;
     for(x=0;x<6;x++)
         for(y=0;y<6;y++)
         {
             if(tu[x][y]==0)
                 n++;
         }
    return n;
 }
 //箱子到了位置的个数
 int count2()
 {
     int t=0;
     for(x=0;x<6;x++)
         for(y=0;y<6;y++)
         {
             if(tu[x][y]==2)
                 t++;
         }
         return t;
     }
	int up()
	 	{
		
	       if(tu[x][y]==5)
	       {
	 		if((tu[x-1][y]==3)&&(tu[x-2][y]==4))
	 		{
	 			tu[x-2][y]=3;                          //0代表箱子应该到的地方@，1代表墙!，3代表箱子#，4代表路^，5代表人&
	 			tu[x-1][y]=5;
	 			tu[x][y]=4;
			 }  
		 if(tu[x-1][y]==3&&tu[x-2][y]==0)
		{
		    tu[x-2][y]=2;
			tu[x-1][y]=5;
			tu[x][y]=4;
		}                                                                
			 if(tu[x-1][y]==4) 
			 {
			 	tu[x-1][y]=5;
			 	tu[x][y]=4;
			 }
		   }
		 return 0;
	}
	int down()
	{
	  
	    if(tu[x][y]==5)
	    {
		 	if(tu[x+1][y]==3&&tu[x+2][y]==4)
		 	{
		 		tu[x+2][y]=3;
		 		tu[x+1][y]=5;
		 		tu[x][y]=4;
			 }
		    	if(tu[x+1][y]==3&&tu[x+2][y]==0)
		    	{
		        tu[x+2][y]=2;
		 		tu[x+1][y]=5;
		 		tu[x][y]=4;	
				}
			 if(tu[x+1][y]==4)
			 {
			 	tu[x+1][y]=5;
			 	tu[x][y]=4;
			 } 
		    }                                        //0代表箱子应该到的地方@，1代表墙!，3代表箱子#，4代表路^，5代表人& 
		 return 0;
		 }
	int left()
	{   
	 
	      if(tu[x][y]==5)
	      {
		 	if(tu[x][y-1]==3&&tu[x][y-2]==4)
		 	{
		 		tu[x][y-2]=3;
		 		tu[x][y-1]=5;
		 		tu[x][y]=4;
			 }
			if(tu[x][y-1]==3&&tu[x][y-2]==0)
			{
			    tu[x][y-2]=2;
		 		tu[x][y-1]=5;
		 		tu[x][y]=4;
			}
			 if(tu[x][y-1]==4)
		     {
			 	tu[x][y-1]=5;
			 	tu[x][y]=4;
			 } 
		   }
		 return 0;
	}
	int right()
	{
	
	      if(tu[x][y]==5)
	      {
		 	if(tu[x][y+1]==3&&tu[x][y+2]==4)
		 	{
		 		tu[x][y+2]=3;
		 		tu[x][y+1]=5;
		 		tu[x][y]=4;
			 }
		   	if(tu[x][y+1]==3&&tu[x][y+2]==0)
            {
                tu[x][y+2]=2;
		 		tu[x][y+1]=5;
		 		tu[x][y]=4;	
            }
			 if(tu[x][y+1]==4)
		     {
			 	tu[x][y+1]=5;
			 	tu[x][y]=4;
			 } 
	    	}
		  return 0;
	 }
	 	int up2()
	 	{
		
	       if(tu2[x][y]==5)
	       {
	 		if((tu2[x-1][y]==3)&&(tu2[x-2][y]==4))
	 		{
	 			tu2[x-2][y]=3;                          //0代表箱子应该到的地方@，1代表墙!，3代表箱子#，4代表路^，5代表人&
	 			tu2[x-1][y]=5;
	 			tu2[x][y]=4;
			 }  
		 if(tu2[x-1][y]==3&&tu2[x-2][y]==0)
		{
		    tu2[x-2][y]=2;
			tu2[x-1][y]=5;
			tu2[x][y]=4;
		}                                                                
			 if(tu2[x-1][y]==4) 
			 {
			 	tu2[x-1][y]=5;
			 	tu2[x][y]=4;
			 }
		   }
		 return 0;
	}
	int down2()
	{
	  
	    if(tu2[x][y]==5)
	    {
		 	if(tu2[x+1][y]==3&&tu2[x+2][y]==4)
		 	{
		 		tu2[x+2][y]=3;
		 		tu2[x+1][y]=5;
		 		tu2[x][y]=4;
			 }
		    	if(tu2[x+1][y]==3&&tu2[x+2][y]==0)
		    	{
		        tu2[x+2][y]=2;
		 		tu2[x+1][y]=5;
		 		tu2[x][y]=4;	
				}
			 if(tu2[x+1][y]==4)
			 {
			 	tu2[x+1][y]=5;
			 	tu2[x][y]=4;
			 } 
		    }                                        //0代表箱子应该到的地方@，1代表墙!，3代表箱子#，4代表路^，5代表人& 
		 return 0;
		 }
	int left2()
	{   
	 
	      if(tu2[x][y]==5)
	      {
		 	if(tu2[x][y-1]==3&&tu2[x][y-2]==4)
		 	{
		 		tu2[x][y-2]=3;
		 		tu2[x][y-1]=5;
		 		tu2[x][y]=4;
			 }
			if(tu2[x][y-1]==3&&tu2[x][y-2]==0)
			{
			    tu2[x][y-2]=2;
		 		tu2[x][y-1]=5;
		 		tu2[x][y]=4;
			}
			 if(tu2[x][y-1]==4)
		     {
			 	tu2[x][y-1]=5;
			 	tu2[x][y]=4;
			 } 
		   }
		 return 0;
	}
	int right2()
	{
	
	      if(tu2[x][y]==5)
	      {
		 	if(tu2[x][y+1]==3&&tu2[x][y+2]==4)
		 	{
		 		tu2[x][y+2]=3;
		 		tu2[x][y+1]=5;
		 		tu2[x][y]=4;
			 }
		   	if(tu2[x][y+1]==3&&tu2[x][y+2]==0)
            {
                tu2[x][y+2]=2;
		 		tu2[x][y+1]=5;
		 		tu2[x][y]=4;	
            }
			 if(tu2[x][y+1]==4)
		     {
			 	tu2[x][y+1]=5;
			 	tu2[x][y]=4;
			 } 
	    	}
		  return 0;
	 }
	 	int up3()
	 	{
		
	       if(tu3[x][y]==5)
	       {
	 		if((tu3[x-1][y]==3)&&(tu3[x-2][y]==4))
	 		{
	 			tu3[x-2][y]=3;                          //0代表箱子应该到的地方@，1代表墙!，3代表箱子#，4代表路^，5代表人&
	 			tu3[x-1][y]=5;
	 			tu3[x][y]=4;
			 }  
		 if(tu3[x-1][y]==3&&tu3[x-2][y]==0)
		{
		    tu3[x-2][y]=2;
			tu3[x-1][y]=5;
			tu3[x][y]=4;
		}                                                                
			 if(tu3[x-1][y]==4) 
			 {
			 	tu3[x-1][y]=5;
			 	tu3[x][y]=4;
			 }
		   }
		 return 0;
	}
	int down3()
	{
	  
	    if(tu3[x][y]==5)
	    {
		 	if(tu3[x+1][y]==3&&tu3[x+2][y]==4)
		 	{
		 		tu3[x+2][y]=3;
		 		tu3[x+1][y]=5;
		 		tu3[x][y]=4;
			 }
		    	if(tu3[x+1][y]==3&&tu3[x+2][y]==0)
		    	{
		        tu3[x+2][y]=2;
		 		tu3[x+1][y]=5;
		 		tu3[x][y]=4;	
				}
			 if(tu3[x+1][y]==4)
			 {
			 	tu3[x+1][y]=5;
			 	tu3[x][y]=4;
			 } 
		    }                                        //0代表箱子应该到的地方@，1代表墙!，3代表箱子#，4代表路^，5代表人& 
		 return 0;
		 }
	int left3()
	{   
	 
	      if(tu3[x][y]==5)
	      {
		 	if(tu3[x][y-1]==3&&tu3[x][y-2]==4)
		 	{
		 		tu3[x][y-2]=3;
		 		tu3[x][y-1]=5;
		 		tu3[x][y]=4;
			 }
			if(tu3[x][y-1]==3&&tu3[x][y-2]==0)
			{
			    tu3[x][y-2]=2;
		 		tu3[x][y-1]=5;
		 		tu3[x][y]=4;
			}
			 if(tu3[x][y-1]==4)
		     {
			 	tu3[x][y-1]=5;
			 	tu3[x][y]=4;
			 } 
		   }
		 return 0;
	}
	int right3()
	{
	
	      if(tu3[x][y]==5)
	      {
		 	if(tu3[x][y+1]==3&&tu3[x][y+2]==4)
		 	{
		 		tu3[x][y+2]=3;
		 		tu3[x][y+1]=5;
		 		tu3[x][y]=4;
			 }
		   	if(tu3[x][y+1]==3&&tu3[x][y+2]==0)
            {
                tu3[x][y+2]=2;
		 		tu3[x][y+1]=5;
		 		tu3[x][y]=4;	
            }
			 if(tu3[x][y+1]==4)
		     {
			 	tu3[x][y+1]=5;
			 	tu3[x][y]=4;
			 } 
	    	}
		  return 0;
	 }
	 int up4()
	 	{
		
	       if(tu4[x][y]==5)
	       {
	 		if((tu4[x-1][y]==3)&&(tu4[x-2][y]==4))
	 		{
	 			tu4[x-2][y]=3;                          //0代表箱子应该到的地方@，1代表墙!，3代表箱子#，4代表路^，5代表人&
	 			tu4[x-1][y]=5;
	 			tu4[x][y]=4;
			 }  
		 if(tu4[x-1][y]==3&&tu4[x-2][y]==0)
		{
		    tu4[x-2][y]=2;
			tu4[x-1][y]=5;
			tu4[x][y]=4;
		}                                                                
			 if(tu4[x-1][y]==4) 
			 {
			 	tu4[x-1][y]=5;
			 	tu4[x][y]=4;
			 }
		   }
		 return 0;
	}
	int down4()
	{
	  
	    if(tu4[x][y]==5)
	    {
		 	if(tu4[x+1][y]==3&&tu4[x+2][y]==4)
		 	{
		 		tu4[x+2][y]=3;
		 		tu4[x+1][y]=5;
		 		tu4[x][y]=4;
			 }
		    	if(tu4[x+1][y]==3&&tu4[x+2][y]==0)
		    	{
		        tu4[x+2][y]=2;
		 		tu4[x+1][y]=5;
		 		tu4[x][y]=4;	
				}
			 if(tu4[x+1][y]==4)
			 {
			 	tu4[x+1][y]=5;
			 	tu4[x][y]=4;
			 } 
		    }                                        //0代表箱子应该到的地方@，1代表墙!，3代表箱子#，4代表路^，5代表人& 
		 return 0;
		 }
	int left4()
	{   
	 
	      if(tu4[x][y]==5)
	      {
		 	if(tu4[x][y-1]==3&&tu4[x][y-2]==4)
		 	{
		 		tu4[x][y-2]=3;
		 		tu4[x][y-1]=5;
		 		tu4[x][y]=4;
			 }
			if(tu4[x][y-1]==3&&tu4[x][y-2]==0)
			{
			    tu4[x][y-2]=2;
		 		tu4[x][y-1]=5;
		 		tu4[x][y]=4;
			}
			 if(tu4[x][y-1]==4)
		     {
			 	tu4[x][y-1]=5;
			 	tu4[x][y]=4;
			 } 
		   }
		 return 0;
	}
	int right4()
	{
	      if(tu4[x][y]==5)
	      {
		 	if(tu4[x][y+1]==3&&tu4[x][y+2]==4)
		 	{
		 		tu4[x][y+2]=3;
		 		tu4[x][y+1]=5;
		 		tu4[x][y]=4;
			 }
		   	if(tu4[x][y+1]==3&&tu4[x][y+2]==0)
            {
                tu4[x][y+2]=2;
		 		tu4[x][y+1]=5;
		 		tu4[x][y]=4;	
            }
			 if(tu4[x][y+1]==4)
		     {
			 	tu4[x][y+1]=5;
			 	tu4[x][y]=4;
			 } 
	    	}
		  return 0;
	 }
 int count3()
 {
     int b=0;
     for(x=0;x<6;x++)
         for(y=0;y<6;y++)
         {
             if(tu2[x][y]==0)
                 b++;
         }
    return b;
 }
 //箱子到了位置的个数
 int count4()
 {
     int c=0;
     for(x=0;x<6;x++)
         for(y=0;y<6;y++)
         {
             if(tu2[x][y]==2)
                 c++;
         }
         return c;
     }
 int count5()
 {
     int d=0;
     for(x=0;x<9;x++)
         for(y=0;y<10;y++)
         {
             if(tu3[x][y]==0)
                 d++;
         }
    return d;
 }
 //箱子到了位置的个数
 int count6()
 {
     int e=0;
     for(x=0;x<9;x++)
         for(y=0;y<10;y++)
         {
             if(tu3[x][y]==2)
                 e++;
         }
         return e;
     }
  int count7()
 {
     int s=0;
     for(x=0;x<9;x++)
         for(y=0;y<12;y++)
         {
             if(tu4[x][y]==0)
                 s++;
         }
    return s;
 }
 //箱子到了位置的个数
 int count8()
 {
     int l=0;
     for(x=0;x<9;x++)
         for(y=0;y<12;y++)
         {
             if(tu4[x][y]==2)
                 l++;
         }
         return l;
     }   
int local2()
	{
	
		for(x=0;x<6;x++)
		 for(y=0;y<6;y++)
		 {
		 	if(tu2[x][y]==5)
		 	{
		 	return 0; 
			 }
		 }
		 return 0;
	}
	int local3()
	{
	
		for(x=0;x<9;x++)
		 for(y=0;y<10;y++)
		 {
		 	if(tu3[x][y]==5)
		 	{
		 	return 0; 
			 }
		 }
		 return 0;
	}
	int local4()
	{
	
		for(x=0;x<9;x++)
		 for(y=0;y<12;y++)
		 {
		 	if(tu4[x][y]==5)
		 	{
		 	return 0; 
			 }
		 }
		 return 0;
	}
	int game4()
	{
	    int s,l;
	    system("cls");
	    int m4[9][12]={0};
	    map4();
	    s=count7();
	    step4=0;
	    while(1)
	 {  
	    system("cls");
	    map4();
	    printf("你已经走过的步数：");
		printf("%d\n",step4);
	    h=count8();
	    local4();
	 	switch(getch())
	 	{
	 		case'W':
	 		case'w':up4();step4++;break;
	 		case'S':
	 		case's':down4();step4++;break;
	 		case'A':
	 		case'a':left4();step4++;break;
	 		case'D':
	 		case'd':right4();step4++;break;
	 		default:printf("enter data error!\n");
	    }
	 if(s==l)
	 {
	 printf("亲，恭喜你闯关成功,游戏结束\n");
	}
	} 
		return 0;    
	}	
	int game3()
	{
		int d,e;
		system("cls");
		int m3[9][10]={0};
		map3();
        d=count5();
        step3=0;
         while(1)
	 {  
	    system("cls");
	    map3();
	    printf("你已经走过的步数：");
		printf("%d\n",step3);
	    e=count6();
	    local3();
	 	switch(getch())
	 	{
	 		case'W':
	 		case'w':up3();step3++;break;
	 		case'S':
	 		case's':down3();step3++;break;
	 		case'A':
	 		case'a':left3();step3++;break;
	 		case'D':
	 		case'd':right3();step3++;break;
	 		default:printf("enter data error!\n");
	    }
	 if(d==e)
	 {
	 printf("亲，恭喜你闯关成功，是否进入下一关？按y或n\n");
	 switch(getch())
	 {
	 	case'Y':
	 	case'y':game4();break;
	 	case'N':
		case'n':printf("游戏结束");break; 
	 }
	}
	} 
		return 0;
	}
	 	 int game2()
	 {
	 	int b,c;
	 	system("cls");
	 	int m2[6][6]={0};
	 	int tu2[6][6]={{1,0,1,1,1,1},{1,3,1,1,1,1},{0,3,5,4,4,1},{1,3,4,3,4,0},{1,4,4,1,4,1},{1,0,1,1,1,1}};
        map2();
        b=count3();
        step2=0;
         while(1)
	 {  
	    system("cls");
	    map2();
	    printf("你已经走过的步数：");
		printf("%d\n",step2);
	    c=count4();
	    local2();
	 	switch(getch())
	 	{
	 		case'W':
	 		case'w':up2();step2++;break;
	 		case'S':
	 		case's':down2();step2++;break;
	 		case'A':
	 		case'a':left2();step2++;break;
	 		case'D':
	 		case'd':right2();step2++;break;
	 		default:printf("enter data error!\n");
	    }
	 if(b==c)
	 {
	 printf("亲，恭喜你闯关成功，是否进入下一关？按y或n\n");
	 switch(getch())
	 {
	 	case'Y':
	 	case'y':game3();break;
	 	case'N':
		case'n':printf("游戏结束");break; 
	 }
	}
	} 
		return 0;
	}
	int game1()
{
	int n,t;
	map();
	n=count1(); 
	step1=0; 

	 while(1)
	 {
	    system("cls");
	    map();
	    printf("你已经走过的步数：");
		printf("%d\n",step1);
	    t=count2();
	    local();
	 	switch(getch())
	 	{
	 		case'W':
	 		case'w':up();step1=step1+1;break;
	 		case'S':
	 		case's':down();step1=step1+1;break;
	 		case'A':
	 		case'a':left();step1=step1+1;break;
	 		case'D':
	 		case'd':right();step1=step1+1;break;
	 		default:printf("enter data error!\n");
	    }

	 if(n==t)
	 {
	 printf("亲，恭喜你闯关成功，是否进入下一关？按y或n\n");
	 switch(getch())
	 {
	 	case'Y':
	 	case'y':game2();break;
	 	case'N':
		case'n':printf("游戏结束");break;
    	default:printf("enter data error!\n");
	 }
	 return 0;
     }
     }
	 }	 
	
	
	
int main()
{
	system("color E2");
	int t,g,n,f=0;
	printf("                                  欢迎来到游戏世界\n");
	printf("                              ----------推箱子------------\n");
	char choose;
	printf("                              a.进入游戏\n");
	printf("                              b.退出游戏\n"); 
	printf("                              说明：按wsad控制上下左右\n");
	printf("                              说明：游戏共四关"); 
    switch(getch())
	{
    case 'A':
	case 'a':f=1;break;
	case 'B':
	case 'b':f=2;break;
	default:printf("enter data error!\n");
	}
	if(f==2)
	return 0;
	if(f==1)
	{
	system("cls");
	printf("请选择关卡：");
	scanf("%d",&g); 
	if(g==2)
	game2();
	if(g==3)
	game3();
	if(g==4)
	game4();
	 if(g==1)
	 {	
	map(); 
	
	n=count1(); 
	step1=0;    
	 while(1)
	 { 
	    system("cls");
	    map();
	    printf("你已经走过的步数：");
		printf("%d\n",step1);
	    t=count2();
	    local();
	 	switch(getch())
	 	{
	 		case'W':
	 		case'w':up();step1=step1+1;break;
	 		case'S':
	 		case's':down();step1=step1+1;break;
	 		case'A':
	 		case'a':left();step1=step1+1;break;
	 		case'D':
	 		case'd':right();step1=step1+1;break;
	 		case'R':
	 	    case'r':game1();break;
	 		default:printf("enter data error!\n");
	    }
	  
	 if(n==t)
	 {
	 printf("亲，恭喜你闯关成功，是否进入下一关？按y或n\n");
	 switch(getch())
	 {
	 	case'Y':
	 	case'y':game2();break;
	 	case'N':
		case'n':printf("游戏结束");break;
    	default:printf("enter data error!\n");
	 }
	 return 0;
     }
	 }
}
}
}

