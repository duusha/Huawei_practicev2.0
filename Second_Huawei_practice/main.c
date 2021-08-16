#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct tagRawData {

    unsigned int uwTag;
    unsigned int uwGroup;
    unsigned int uwReg2;
    unsigned int uwReg3;
    unsigned int uwReg4;
    unsigned int uwReg5;
    unsigned int uwReg6;
    unsigned int uwReg7;
} TagData;
TagData * Data;
int Randoms(int lower, int upper)
{
    int num = (rand() %
            (upper - lower + 1)) + lower;
    return(num);
}

int comp (const void * elem1, const void * elem2){
    TagData el1 = *(TagData *) elem1;
    TagData el2 = *(TagData *) elem2;
    if (el1.uwGroup < el2.uwGroup)
        return -1;
    else
        return 1;
}


void create_tags(int cou) {
    for (int i = 0; i < cou; ++i) {
        TagData new_data = {Randoms(1, 65536), Randoms(1, 8), 1, 1, 1, 1, 1, 1};
        Data[i] = new_data;
    }
}

//TagData PreviousPoeRawCmd;
//unsigned int GetFromDrv(TagData *pstPoeRawCmd){
//    if(pstPoeRawCmd ++)
//        return 0;
//    return -1;
//
//
//};
unsigned int ProcessPacket(TagData *pstPoeRawCmd) {
    return  pstPoeRawCmd->uwReg2 * pstPoeRawCmd->uwReg5 + pstPoeRawCmd->uwReg4;
};

void * thread_func_1 (void * ptr) {
    unsigned int res = ProcessPacket((TagData *) ptr);
    int fd_in = open("input_1.txt", O_WRONLY, 0666);
    dprintf(fd_in,"%d\n", res);
}

void * thread_func_2 (void * ptr) {
    unsigned int res = ProcessPacket((TagData *) ptr);
    int fd_in = open("input_2.txt", O_WRONLY, 0666);
    dprintf(fd_in,"%d\n", res);
}

void * thread_func_3 (void * ptr) {
    unsigned int res = ProcessPacket((TagData *) ptr);
    int fd_in = open("input_3.txt", O_WRONLY, 0666);
    dprintf(fd_in,"%d\n", res);
}

void * thread_func_4 (void * ptr) {
    unsigned int res = ProcessPacket((TagData *) ptr);
    int fd_in = open("input_4.txt", O_WRONLY, 0666);
    dprintf(fd_in,"%d\n", res);
}

void * thread_func_5 (void * ptr) {
    unsigned int res = ProcessPacket((TagData *) ptr);
    int fd_in = open("input_5.txt", O_WRONLY, 0666);
    dprintf(fd_in,"%d\n", res);
}

void * thread_func_6 (void * ptr) {
    unsigned int res = ProcessPacket((TagData *) ptr);
    int fd_in = open("input_6.txt", O_WRONLY, 0666);
    dprintf(fd_in,"%d\n", res);
}

void * thread_func_7 (void * ptr) {
    unsigned int res = ProcessPacket((TagData *) ptr);
    int fd_in = open("input_7.txt", O_WRONLY, 0666);
    dprintf(fd_in,"%d\n", res);
}

void * thread_func_8 (void * ptr) {
    unsigned int res = ProcessPacket((TagData *) ptr);
    int fd_in = open("input_8.txt", O_WRONLY, 0666);
    dprintf(fd_in,"%d\n", res);
}




void* thread_func(void* ptr) {
    int num = *(int *) ptr;
    int self = pthread_self();
    printf("self: %d num: %d\n", self, num);
    if (num % 2 == 0){
//        char str[16];
//        sprintf(str, "%s_%d","input", num);
//
//        printf("%s",str);
//        int fd_in = open(str, O_RDWR | O_CREAT | O_TRUNC, 0666);
//        dprintf(fd_in, "SOS!");
//        TagData pstPoeRawCmd = PreviousPoeRawCmd;
//        while (pstPoeRawCmd.uwGroup == PreviousPoeRawCmd.uwGroup) {
//            if (GetFromDrv(&pstPoeRawCmd) != 0)
//                fprintf(stderr, "end of data");
//            PreviousPoeRawCmd = pstPoeRawCmd;
//            printf("%d", pstPoeRawCmd.uwTag);
    }
    else {
//        char str[16];
//        sprintf(str, "%s_%d", "output", num);
//        int fd_out = open(str, O_RDWR | O_CREAT | O_TRUNC, 0666);
//        dprintf(fd_out, "OUT!");
    }
}




unsigned int UnlockGroup(void) {

};



unsigned int add_core(){

};
unsigned int remove_core(int num){

};

void process(int cou) {
    pthread_t ids[cou];
    int nums[cou];
    for (int i = 0; i < cou; ++i) {
        nums[i] = i + 1;
        pthread_create(&ids[i], NULL, thread_func, &nums[i]);
    }
    for (int i = 0; i < cou; ++i) {
        pthread_join(ids[i], NULL);
    }
};

int main() {

//Создание и сортировка пакетов по группам.
    Data = malloc(2000 * sizeof(TagData));
    create_tags(2000);
    for (int i = 0; i < 2000; ++ i){
        qsort(Data, 2000, sizeof(TagData), comp);
        //printf("%d ", Data[i].uwGroup);
    }
    TagData PreviousPoeRawCmd = Data[0];


    FILE* f;
    int cpu_cou = 0;
    f = fopen("CPU.txt", "r+");
    if (f == NULL) {
        printf("Укажите количество ядер в процессоре: ");
        scanf("%d", &cpu_cou);
        printf("\n");
    }
    else {
        int c = fgetc(f);
        while (c != ' ') {
            cpu_cou *= 10;
            cpu_cou += c - 48;
            c = fgetc(f);
        }
    }
    if (cpu_cou == 0){
        printf("Укажите количесвто ядер в процессоре: ");
        scanf("%d", &cpu_cou);

    }
    else{
        printf("Количесвто ядер: %d\n", cpu_cou);
        for ( int i = 0 ; i < cpu_cou; ++i ) {
            char str[16];
            sprintf(str, "%s_%d.txt","input", i + 1);

            //printf("%s",str);
            int fd_in = open(str, O_RDWR | O_CREAT | O_TRUNC, 0666);
        }
        pthread_t pthreads[cpu_cou];
        for (int i = 0; i  < 2048; ++i) {
            if (Data[i].uwGroup == 1) {
                pthread_create(&pthreads[0],NULL, thread_func_1, &Data[i]);
            }
            if (Data[i].uwGroup == 2) {
                pthread_create(&pthreads[1],NULL, thread_func_2, &Data[i]);
            }
            if (Data[i].uwGroup == 3) {
                pthread_create(&pthreads[2],NULL, thread_func_3, &Data[i]);
            }
            if (Data[i].uwGroup == 4) {
                pthread_create(&pthreads[3],NULL, thread_func_4, &Data[i]);
            }
            if (Data[i].uwGroup == 5) {
                pthread_create(&pthreads[4],NULL, thread_func_5, &Data[i]);
            }
            if (Data[i].uwGroup == 6) {
                pthread_create(&pthreads[5],NULL, thread_func_6, &Data[i]);
            }
            if (Data[i].uwGroup == 7) {
                pthread_create(&pthreads[6],NULL, thread_func_7, &Data[i]);
            }
            if (Data[i].uwGroup == 8) {
                pthread_create(&pthreads[7],NULL, thread_func_8, &Data[i]);
            }
        }
        process (cpu_cou);
    }

}
