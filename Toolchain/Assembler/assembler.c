/*
    Lightweight assembler for Titanium Assembly
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    // Read in lines
    char lines[256][256]; // make this dynamic in the future
    // How many lines we read
    int lineCount = 0;
    int curCount = 0;
    for(int i = 0; i < size; i++){
        if(buffer[i] != '\n')
            lines[lineCount][curCount++] = buffer[i];
        else{
            curCount = 0;
            lineCount++;
        }
    }

    // Ight start working
    for(int i = 0; i < lineCount; i++){
        // break it up at spaces
        char keys[256][256];
        int keysCount = 0;
        curCount = 0;
        for(int g = 0; g < strlen(lines[i]); g++){
            if(lines[i][g] != ' ')
                keys[keysCount][curCount++] = lines[i][g];
            else{
                curCount = 0;
                keysCount++;
            }
        }
        
        // Ight parse that
        for(int g = 0; g < keysCount; g++){
            if(strcmp(";", keys[g]) == 0){
                // Give up lmao
                break;
            }
            // ughhhhh ight compile this stuff
            if(strcmp("mov", keys[g]) == 0){
                // Ight calculate some things....
            }
        }
    }

    return 0;
}

void usage(){
    printf("Titanium Assembler\n");
    printf("./TASM inputFile.tasm outputfile\n");
}