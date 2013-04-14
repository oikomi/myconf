/*
 * File Name : http_server.c 
 * Author : Hong Miao
 * Creation Date : 17-01-2013
 * Description :
 *
 */
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>          
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include "myconf.h"
#include "tokenize.h"
#include "fileparser.h"
#define BUFFSIZE (4*1024)
#define MAX_FILENAME 512

int main(int argc, char *argv[])
{
        struct my_config cfg ;
        memset(&cfg, 0, sizeof(cfg));
        char filename[MAX_FILENAME];
        if(argc == 2)
        {
                if(strlen(argv[1]) < MAX_FILENAME)
                        strcpy(filename, argv[1]);
        }
        else
                strcpy(filename, "config.txt");

        if(file_parser(filename, cfg_reader, &cfg)== -1)
        {
                LOG(stdout, "Configuration Error.Exiting...\n");
                exit(1);     
        }

        printf("%d\n", cfg.listen_port);

        printf("%s\n", cfg.document_root);


        return 0;
}
