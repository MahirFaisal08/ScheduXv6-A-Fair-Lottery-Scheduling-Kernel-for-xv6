
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int

main(void)

{

    int pid1, pid2, pid3;


    printf("Starting lottery scheduling test...\n");


    pid1 = fork();

    if(pid1 == 0){

        settickets(5);

        for(int i = 0; i < 100000000; i++);
        printf("Process 1 finished (5 tickets)\n");

        exit(0);

    }

    pid2 = fork();

    if(pid2 == 0){
        settickets(15);

        for(int i = 0; i < 100000000; i++);

        printf("Process 2 finished (15 tickets)\n");




        exit(0);

    }

    pid3 = fork();

    if(pid3 == 0){

        settickets(30);

        for(int i = 0; i < 100000000; i++);


        printf("Process 3 finished (30 tickets)\n");

        exit(0);


    }



    wait(0);

    wait(0);

    wait(0);


    printf("Lottery scheduling test complete!\n");

    exit(0);


}




