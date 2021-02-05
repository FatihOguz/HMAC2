#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>





int main(int argc, char *argv[]){

	FILE *file;
    if ((file = fopen(argv[1], "r")) == NULL){
        printf("Error! opening file");
        exit(1);
    }

	FILE *fp=fopen(argv[2],"w");

   char c[10000];
    while(fscanf(file, "%s", c)!=EOF){
        
    	//printf("%s\n",c );

  unsigned int val = ntohs(*(u_int8_t*)c);
	 fprintf(fp,"%02x ",val/1000);



	//printf("\n");

}





fclose(fp);
fclose(file);
}