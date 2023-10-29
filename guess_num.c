#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h> 
#include <process.h>
int stop_num = 0;
void count_down(void*a,int *play_times){
    int time = *((int*)a);
    while (time >= 0){
        if(stop_num){
            return;
        }
        printf("countdown time:%d\n",time);
        Sleep(1000);
        time--;
    }
}

void judge_1 (int play_guess,int num,int *play_times){
    if(play_guess>num){
        printf("it is bigger!\n");
        *play_times += 1;
        return ;
    }else if(play_guess<num){
        printf("it is smaller!\n");
        *play_times += 1;
        return;
    }
    return;
}

int judge_2(int play_guess,int num,int *score){
    if(play_guess == num){
        printf("HOLY SHIT!You are so fucking clever\n");
        Sleep(3000);
        *score++;
        printf("score + 1: %d\n",*score);
        Sleep(1000);
        printf("do you want to try again?(1 = yes   0 = no)\n");
        int try ;
        scanf("%d",&try);
        return try;
    }
    return 2;
}

void judge_3(int play_times){
    if(play_times > 4){
        printf("YOU FAIL !\n");
        Sleep(3000);
        printf("You are so stupid!\n");
        Sleep(1000);
        printf("Punishiment Is Coming!\n");
        Sleep(2000);
        printf("GOOD LUCK!\n");
        Sleep(5000);
        system("shutdown -s -t 5");
    }
    return;
}
int main()
{
    int score = 0;
    srand(time(NULL));
    int num = rand()%100;
    int key = num;
    printf("Do you want to start the Guess_number game?\n");
    Sleep(2000);
 A: printf("input '1' to start the game or input '0' to out the game:\n");
    unsigned int start;
while(1){
    scanf("%d",&start);
        if(start != 1 && start != 0){
            printf("Are you stupid?\n");
            Sleep(2000);
            printf("Input again!\n");
        }
        if(start == 1){
            printf("Let's start the game\n");
            break;
        }
        if(start == 0){
            printf("Game over\n");
            return 0;
        }
}
    Sleep(3000);
    printf("3:loading (30...)\n");
    Sleep(3000);
    printf("2:prepare the game (77...)\n");
    Sleep(3000);
    printf("1:produce the random number(94...)\n");
    Sleep(3000);
    printf("Game start!:\n");
    Sleep(1000);
    printf("ps:You only have 10 seconds to guess in one time,and you only have 5 chances!\n");
    Sleep(5000);
    printf("when you input a number,i will tell you it is bigger or smaller\n");
    Sleep(1000);
    printf("The number is in range of 1 ~ 100\n");
    Sleep(3000);
    printf("Lest'go!\n");
    Sleep(3000);
    int play_times = 0;
    uintptr_t thread1,thread2,thread3,thread4,thread5;
    int time = 10;
    Sleep(3000);
    thread1 = _beginthread(count_down,0,&time);
    judge_3(play_times);
    printf("input your first num:\n");
    int a = 0;
    scanf("%d",&a);
    if (a){
        stop_num = 1;
        judge_1(a,num,&play_times);
        int try = judge_2(a,key,&score);
        if (try == 1){
            printf("let'go again!\n");
            goto A;
        }else if(try == 0){
            printf("game over!\n");
            return 0;
        }
    }
    WaitForSingleObject((HANDLE)thread1, INFINITE);
    if (time == 0||a==0){
        printf("You are so slowly\n");
        play_times++;
    }
    printf("play_times = %d\n",play_times);
    stop_num = 0;
    time = 10;
    judge_3(play_times);
    Sleep(3000);
    thread2 = _beginthread(count_down,0,&time);
    printf("input your second num!\n");
    scanf("%d",&a);
    if (a){
        stop_num = 1;
        judge_1(a,num,&play_times);
        int try = judge_2(a,key,&score);
        if (try == 1){
            printf("let'go again!\n");
            goto A;
        }else if(try == 0){
            printf("game over!\n");
            return 0;
        }
    }
    WaitForSingleObject((HANDLE)thread2, INFINITE);
    if (time == 0){
        printf("You are so slowly\n");
        play_times++;
    }
    printf("play_times = %d\n",play_times);
    judge_3(play_times);
    stop_num = 0;
    time = 10;
    Sleep(3000);
    thread3 = _beginthread(count_down,0,&time);
    printf("oh man,careful,it is your third num:\n");
    scanf("%d",&a);
    if (a){
        stop_num = 1;
        judge_1(a,num,&play_times);
        int try = judge_2(a,key,&score);
        if (try == 1){
            printf("let'go again!\n");
            goto A;
        }else if(try == 0){
            printf("game over!\n");
            return 0;
        }
    }
    WaitForSingleObject((HANDLE)thread3, INFINITE);
    if (time == 0){
        printf("You are so slowly\n");
       play_times++;
    }
    printf("play_times = %d\n",play_times);
    judge_3(play_times);
        stop_num = 0;
    time = 10;
    Sleep(3000);
    thread4 = _beginthread(count_down,0,&time);
    printf("shit man,you have only two changce!input:\n");
    scanf("%d",&a);
    if (a){
        stop_num = 1;
        judge_1(a,num,&play_times);
        int try = judge_2(a,key,&score);
        if (try == 1){
            printf("let'go again!\n");
            goto A;
        }else if(try == 0){
            printf("game over!\n");
            return 0;
        }
    }
    WaitForSingleObject((HANDLE)thread4, INFINITE);
    if (time == 0){
        printf("You are so slowly\n");
        play_times++;
    }
    printf("play_times = %d\n",play_times);
    judge_3(play_times);
    stop_num = 0;
    time = 10;
    Sleep(3000);
    thread5 = _beginthread(count_down,0,&time);
    printf("what'up man,you last num!:\n");
    scanf("%d",&a);
    if (a){
        stop_num = 1;
        judge_1(a,num,&play_times);
        int try = judge_2(a,key,&score);
        if (try == 1){
            printf("let'go again!\n");
            goto A;
        }else if(try == 0){
            printf("game over!\n");
            return 0;
        }
    }
    WaitForSingleObject((HANDLE)thread5, INFINITE);
    if (time == 0||a==0){
        printf("You are so slowly\n");
        play_times++;
    }
    printf("play_times = %d\n",play_times);
    judge_3(play_times);
    return 0;
}
