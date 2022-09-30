#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void do_ls(char[]);
void dostat(char*);
void show_file_info(char*, struct stat*);
void mode_to_letters(int, char[]);
char* uid_to_name(uid_t);
char* gid_to_name(gid_t);
void do_ls_time();
void do_ls_size();

int cnt;

struct temp{
    char modestr[20];
    int link;
    char name1[20];
    char name2[20];
    long int size;
    time_t time;
    char filename[20];
};

struct temp* t;

int main(int argc, char* argv[]){
    char* ctime();

    t = (struct temp*)malloc(sizeof(struct temp)*100);

    if(argc == 1){
        do_ls(".");
    }
    else{
        while(--argc){
            printf("%s:\n", *++argv);
            do_ls(*argv);
        }

    }


    do_ls_size();

    printf("size로 정렬 \n");
    for(int i = 0; i < cnt; i++){
        printf("%s", t[i].modestr);
        printf("%4d ", t[i].link);
        printf("%-8s ", t[i].name1);
        printf("%-8s ", t[i].name2);
        printf("%-8ld ", t[i].size);
        printf("%.12s ", 4+ctime(&t[i].time));
        printf("%s \n", t[i].filename);
    }

    do_ls_time();

    printf("time으로 정렬 \n");
    for(int i = 0; i < cnt; i++){
        printf("%s", t[i].modestr);
        printf("%4d ", t[i].link);
        printf("%-8s ", t[i].name1);
        printf("%-8s ", t[i].name2);
        printf("%-8ld ", t[i].size);
        printf("%.12s ", 4+ctime(&t[i].time));
        printf("%s \n", t[i].filename);
    }

}
void do_ls(char dirname[]){
    DIR* dir_ptr;
    struct dirent* direntp;
    if((dir_ptr = opendir(dirname)) == NULL)
        fprintf(stderr, "ls2: cannot open %s\n", dirname);
    else{
        while( (direntp = readdir(dir_ptr)) != NULL)
            dostat(direntp->d_name);
        closedir(dir_ptr);
    }
}
void dostat(char* filename){
    struct stat info;
    if(stat(filename, &info) == -1)
        perror(filename);
    else
        show_file_info(filename, &info);
}
void show_file_info(char* filename, struct stat* info_p){
    char *uid_to_name(), *ctime(), *gid_to_name(), *filemode();
    void mode_to_letters();
    char modestr[20];

    mode_to_letters(info_p->st_mode, modestr);
    printf("%s", modestr);
    printf("%4d ", (int) info_p->st_nlink);
    printf("%-8s ", uid_to_name(info_p->st_uid));
    printf("%-8s ", gid_to_name(info_p->st_gid));
    printf("%-8ld ", (long) info_p->st_size);
    printf("%.12s ", 4+ctime(&info_p->st_mtime));
    printf("%s \n", filename);


    strcpy(t[cnt].modestr, modestr);
    t[cnt].link = (int) info_p->st_nlink;
    strcpy(t[cnt].name1, uid_to_name(info_p->st_uid));
    strcpy(t[cnt].name2, gid_to_name(info_p->st_gid));
    t[cnt].size = (long) info_p->st_size;
    t[cnt].time = info_p->st_mtime;
    strcpy(t[cnt].filename, filename);

    cnt++;

}

void mode_to_letters(int mode, char str[]){
    strcpy(str, "----------");

    if(S_ISDIR(mode)) str[0] = 'd';
    if(S_ISCHR(mode)) str[0] = 'c';
    if(S_ISBLK(mode)) str[0] = 'b';

    if(mode & S_IRUSR) str[1] = 'r';
    if(mode & S_IRUSR) str[2] = 'w';
    if(mode & S_IRUSR) str[3] = 'x';

    if(mode & S_IRGRP) str[4] = 'r';
    if(mode & S_IWGRP) str[5] = 'w';
    if(mode & S_IXGRP) str[6] = 'x';

    if(mode & S_IROTH) str[7] = 'r';
    if(mode & S_IWOTH) str[8] = 'w';
    if(mode & S_IXOTH) str[9] = 'x';
}
char* uid_to_name(uid_t uid){

    struct passwd *getpwuid(), *pw_ptr;
    static char numstr[10];

    if((pw_ptr = getpwuid(uid)) == NULL){
        sprintf(numstr, "%d", uid);
        return numstr;
    }
    else
        return pw_ptr->pw_name;
}
char* gid_to_name(gid_t gid){
    struct group *getgrid(), *grp_ptr;
    static char numstr[10];
    if((grp_ptr = getgrgid(gid)) == NULL){
        sprintf(numstr, "%d", gid);
        return numstr;
    }
    else
        return grp_ptr->gr_name;
    
}
void do_ls_time(){

    struct temp tt;

    for(int i = 0; i < cnt-1; i++){
        for(int j = i + 1; j < cnt; j++){
            if(t[i].time<t[j].time){
                tt = t[i];
                t[i] = t[j];
                t[j] = tt;
            }
        }
    }

}
void do_ls_size(){

    struct temp tt;

    for(int i =0; i < cnt -1; i++){
        for(int j = i; j < cnt; j++){
            if(t[i].size<t[j].size){
                tt = t[i];
                t[i] = t[j];
                t[j] = tt;
            }
        }
    }

}