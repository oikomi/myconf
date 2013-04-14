#ifndef __HTTPCONF__
#define __HTTPCONF__

#define MAX_BUF 1024
#define PENDING_CONN 64

#include "log.h"

/* various config element types parsed from config file*/
enum cfg_elements_t {
        FILE_TYPE,                      /*type of file*/
        DOCUMENT_ROOT,  
        DIR_INDEX,
        LISTEN_PORT,
        FILE_TYPE_EXT,                  /*Extension for the file type*/
        DEFAULT         
};
struct valid_file_types {
        char extension[MAX_BUF];            /*extension of file*/
        char type[MAX_BUF];                 /*type of the file contents*/
};
struct directory_index_file {
        char filename[MAX_BUF];             /*default file name used when only directory is
                                        specified*/
};
struct my_config {
        int listen_port;                /*server listens on this port*/
        char document_root[MAX_BUF];        /*root directory */
        struct valid_file_types filetypes[MAX_BUF];         /*supported file types */
        int f_type_cnt;                                 /* total number of supported
                                                        file types*/
        struct directory_index_file dir_index[2];       /*default index file*/ 

};



/*Function declarations */

int cfg_reader(void *c, char *line);

#endif
