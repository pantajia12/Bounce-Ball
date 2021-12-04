#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#define SLEEP_TIME 80
int Box_x, Box_y;
int i, j;
int **Box;

void LeftUp(int x,int y);
void RightUp(int x,int y);
void LeftDown(int x,int y);
void RightDown(int x,int y);
void Tail(int value);
void Reset_Box();
void Print_Box();
int main(){
    printf("이동 반경 입력\n");
    scanf("%d %d",&Box_x,&Box_y);
    
    //2차원 메모리 할당
    Box = (int**)calloc(Box_x, sizeof(int*));
    for(i=0;i<Box_x;i++){
        Box[i] = (int*)calloc(Box_y, sizeof(int));
    }
    
    for(i=1;i<Box_x-1;i++){
        Box[i][0] = 1;
        Box[i][Box_y-1] = 3;
    }
    for (j=1;j<Box_y-1;j++){
        Box[0][j] = 2;
        Box[Box_x-1][j] = 4;
    }
    Box[0][0] = 5, Box[Box_x-1][0] = 5, Box[0][Box_y-1] = 5, Box[Box_x-1][Box_y-1] = 5;



    
    for(i=0;i<Box_x;i++){
        for (j=0;j<Box_y;j++){
            printf("0 ");
        }
        printf("\n");
    }
    Sleep(SLEEP_TIME);
    
    system("cls");
    RightDown(0, 0);
    return 0;
}

void LeftUp(int x, int y){
    for(int m=1;m<Box_x+Box_y;m++){
        int value = Box[x-m][y-m];
        if(Box[x-m][y-m] == 0) {
            Box[x-m][y-m] = 6;
            Print_Box();
            Tail(value);
        } else if(Box[x-m][y-m] == 1) {
            Box[x-m][y-m] = 6;
            Print_Box();
            Tail(value);
            RightUp(x-m,y-m);
            break;
        } else if(Box[x-m][y-m] == 2) {
            Box[x-m][y-m] = 6;
            Print_Box();
            Tail(value);
            LeftDown(x-m,y-m);
            break;
        } else if(Box[x-m][y-m] == 5) {
            Box[x-m][y-m] = 6;
            Print_Box();
            Tail(value);
            RightDown(x-m,y-m);
            break;
        }
    }
}

void RightUp(int x, int y){
    for(int m=1;m<Box_x+Box_y;m++){
        int value = Box[x-m][y+m];
        if(Box[x-m][y+m] == 0) {
            Box[x-m][y+m] = 6;
            Print_Box();
            Tail(value);
        } else if(Box[x-m][y+m] == 2) {
            Box[x-m][y+m] = 6;
            Print_Box();
            Tail(value);
            RightDown(x-m,y+m);
            break;
        } else if(Box[x-m][y+m] == 3) {
            Box[x-m][y+m] = 6;
            Print_Box();
            Tail(value);
            LeftUp(x-m,y+m);
            break;
        }
        else if(Box[x-m][y+m] == 5) {
            Box[x-m][y+m] = 6;
            Print_Box();
            Tail(value);
            LeftDown(x-m,y+m);
            break;
        }
    }
}

void LeftDown(int x, int y){
    for(int m=1;m<Box_x+Box_y;m++){
        int value = Box[x+m][y-m];
        if(Box[x+m][y-m] == 0) {
            Box[x+m][y-m] = 6;
            Print_Box();
            Tail(value);
        } else if(Box[x+m][y-m] == 1) {
            Box[x+m][y-m] = 6;
            Print_Box();
            Tail(value);
            RightDown(x+m,y-m);
            break;
        } else if(Box[x+m][y-m] == 4) {
            Box[x+m][y-m] = 6;
            Print_Box();
            Tail(value);
            LeftUp(x+m,y-m);
            break;
        } else if(Box[x+m][y-m] == 5) {
            Box[x+m][y-m] = 6;
            Print_Box();
            Tail(value);
            RightUp(x+m,y-m);
            break;
        }
    }
}

void RightDown(int x, int y){
    for(int m=1;m<Box_x+Box_y;m++){
        int value = Box[x+m][y+m];
        if(Box[x+m][y+m] == 0) {
            Box[x+m][y+m] = 6;
            Print_Box();
            Tail(value);
        } else if(Box[x+m][y+m] == 3) {
            Box[x+m][y+m] = 6;
            Print_Box();
            Tail(value);
            LeftDown(x+m,y+m);
            break;
        } else if(Box[x+m][y+m] == 4) {
            Box[x+m][y+m] = 6;
            Print_Box();
            Tail(value);
            RightUp(x+m,y+m);
            break;
        } else if(Box[x+m][y+m] == 5) {
            Box[x+m][y+m] = 6;
            Print_Box();
            Tail(value);
            LeftUp(x+m,y+m);
            break;
        }
    }
}

void Tail(int value){
	for(i=0;i<Box_x;i++){
        for (j=0;j<Box_y;j++){
        	if(Box[i][j] == 8)
            	Box[i][j] = 0;
            	
            if(Box[i][j] == 7)
            	Box[i][j] = 8;
            	
            if(Box[i][j] == 6)
                Box[i][j] = 7;
        }
    }
    Reset_Box();
}

void Reset_Box(){
	for(i=1;i<Box_x-1;i++){
		if(Box[i][0] == 0) 
			Box[i][0] = 1;
		
        if(Box[i][Box_y-1] == 0)
        	Box[i][Box_y-1] = 3;
    }
    for (j=1;j<Box_y-1;j++){
    	if(Box[0][j] == 0)
        	Box[0][j] = 2;
        
        if(Box[Box_x-1][j] == 0)
        	Box[Box_x-1][j] = 4;
    }
    if(Box[0][0] == 0)
    	Box[0][0] = 5;
    if(Box[Box_x-1][0] == 0)
    	Box[Box_x-1][0] = 5;
    if(Box[0][Box_y-1] == 0)
		Box[0][Box_y-1] = 5;
	if(Box[Box_x-1][Box_y-1] == 0) 
		Box[Box_x-1][Box_y-1] = 5;
}

void Print_Box(){
    for(i=0;i<Box_x;i++){
        for (j=0;j<Box_y;j++){
            if(Box[i][j] < 6) {
                printf("  ");
            } 
			if(Box[i][j] == 6){
                printf("O");
            } 
			if(Box[i][j] == 7){
                printf("o ");
            } 
			if(Box[i][j] == 8){
                printf("* ");
            }
//            printf("%d ",Box[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    Sleep(SLEEP_TIME);
    system("cls");
}