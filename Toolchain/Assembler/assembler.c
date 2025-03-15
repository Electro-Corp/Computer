/*
    Lightweight assembler for Titanium Assembly
*/
#include <stdio.h>
#include <stdlib.h>

void usage();

int main(int args, char* argv[]){
    if(args < 2){
        usage();
        exit(-1);
    }

    // Load input file
    FILE* fp = fopen(argv[1], "r");
    if(!fp){
        printf("File %s not found!\n", argv[1]);
        exit(-1);
    }

    // Create input buffer
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    char buffer[size];
    rewind(fp);
    // Read
	fread(buffer, sizeof(buffer), 1, fp);

    // Create output hex buffer
    unsigned char output[2046]; 

    
}

void usage(){
    printf("Titanium Assembler\n");
    printf("./TASM inputFile.tasm outputfile\n");
}