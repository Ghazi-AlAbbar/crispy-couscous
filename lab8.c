#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct{

        int __W;
        int __D;
}t_args;

int Balance;

void Error(const char* msg){
        printf("Error: %s\n", msg);
        exit(1);
}

int str2d(const char* str){

        int result = 0;
        int i = 0;
        while (*(str + i) != '\0'){

                if (!(*(str + i) >= '0' && *(str + i) <= '9')) return -1;

                result *= 10;
                result += *(str + i) - '0';

                i++;
        }

        return result;
}

void *_Withdraw_(void* W_arg){}
void *_Deposit_(void* D_arg){}

int main(int argc, char** argv){

        if (argc != 3) Error("Expected 3 arguments in the form of \"./prog withdraw deposit\" where withdraw and deposit are positive non-zero integers.");

        int Withdraws = str2d(argv[1]);
        int Deposits = str2d(argv[2]);

        if (Withdraw == -1 || Deposit == -1) Error("Withdraw and Deposit should be ONLY integers!");

        Balance = 1500;

        t_args *Wargs = (t_args)malloc(sizeof(t_args));
        t_args *Dargs = (t_args)malloc(sizeof(t_args));

        Wargs->__W = Withdraw;
        Dargs->__D = Deposit;

        pthread_t Wtid, Dtid;

        pthread_create(&Wtid, NULL, _Withdraw_, (void*)Wargs);
        pthread_create(&Dtid, NULL, _Deposit_, (void*) Dargs);

        pthread_join(Wargs);
}

