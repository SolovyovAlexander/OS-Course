#include <dirent.h>
#include <w32api/rpc.h>
#include <fakesu/sys/stat.h>
#include <stdio.h>

int main() {
    char* folder_loc = "C:\\Users\\solo1\\Desktop\\week10\\tmp";
    DIR* root_dir = opendir("C:\\Users\\solo1\\Desktop\\week10\\tmp");
    if (root_dir == NULL) return (ERROR);

    struct dirent* dir;
    struct stat* st;
    struct stat* array_st[10];
    int i=0;
    while ((dir = readdir(root_dir)) != NULL) {
        char* entry_name = dir->d_name;
        char* entry_address;
        entry_address = malloc(strlen(folder_loc)+strlen(entry_name)+1);
        strcpy(entry_address, folder_loc);
        strcat(entry_address, entry_name);
        stat(entry_address, st);


        nlink_t node_count = st->st_nlink;
        if (node_count >= 2) {
            array_st[i]=st;
            i++;
        }
    }
    for (int j = 0; j <=i ; ++j) {
        printf("%s", (char *) array_st[j]->st_ino);
        for (int k = 0; k <=i; ++k){
            if(array_st[j]==array_st[k]){
            printf("%s", (char *) array_st[j]->st_ino);
            }
            else{
                printf(".....\n");
                printf("%s", (char *) array_st[j]->st_ino);
            }
        }
    }

}