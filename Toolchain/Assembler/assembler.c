/*
    Lightweight assembler for Titanium Assembly
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    ADDRESS = 0,
    POINTER = 1,
    VALUE = 2,
    REGISTER_AX = 3,
    REGISTER_BX = 4,
    REGISTER_CX = 5,
    REGISTER_DX = 6,
    VALUE_W_OFFSET = 7,
} OperandType;

void usage();

int getHexFromValue(char* value);
int getRegisterFromOperandType(OperandType register);

OperandType getOpType(char* op);

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
    FILE* fo = fopen(argv[2], "wb");
    int written = 0;

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

    printf("Assembling %s\n", argv[1]);

    // Ight start working
    for(int i = 0; i < lineCount; i++){
        // break it up at spaces
        char keys[256][256];
        int keysCount = 0;
        curCount = 0;
        if(lines[i][0] == ';') continue;
        char *token = strtok(lines[i], " \t");
        while (token != NULL) {
            strcpy(keys[keysCount], token);
            keysCount++;
            token = strtok(NULL, " \t");
        }
        
        int origin = 0x00;

        // Ight parse that
        for(int g = 0; g < keysCount; g++){
            if(strcmp(";", keys[g]) == 0){
                // Give up lmao
                break;
            }
            if(strcmp("origin", keys[g]) == 0){
                if(getHexFromValue(keys[g+1]) != -1){
                    origin = getHexFromValue(keys[g+1]);
                    printf("%x set as program origin!\n", getHexFromValue(keys[g+1]));
                }else{
                    printf("ERROR - Origin address invalid!\n");
                    exit(-1);
                }
            }
            // ughhhhh ight compile this stuff
            if(strcmp("mov", keys[g]) == 0){
                // Ight calculate some things....
                // First we gotta figure out what kinda mov operation it is
                OperandType op1 = getOpType(keys[g + 1]);
                OperandType op2 = getOpType(keys[g + 2]);

                int op1isRegister = op1 >= 3 && op1 <= 6;
                int op2isRegister = op2 >= 3 && op2 <= 6;

                unsigned char command = 0x00, oper1 = 0x00, oper2 = 0x00, operO = 0x00;
                int fatten1Or2 = 0;
                // ight
                if(op1isRegister){
                    // figure out what register specifcally   
                    oper1 = getRegisterFromOperandType(op1);
                }else{
                    switch(op1){
                        case VALUE: 
                        {
                            // Check for hex
                            if(getHexFromValue(keys[g+1]) != -1){
                                oper1 = getHexFromValue(keys[g+1]);
                            }else{
                                if(keys[g+1][0] == '\''){
                                    oper1 = (char)keys[g+1][1];
                                }
                            }
                            break;
                        }
                        case POINTER:
                        {
                            // We gotta remove the '&'
                            char toBeSent[strlen(keys[g+1]) - 1];
                            strcpy(toBeSent, &keys[g+1][1]);
                            int locPoint = getHexFromValue(toBeSent);
                            if(locPoint > 0xFF){
                                // Split it
                                fatten1Or2 = 1;
                                oper1 = locPoint & 0xFF; // Low
                                operO = (locPoint >> 8) /*& 0xFF*/; // High 
                            }else{
                                oper1 = locPoint;
                            }
                            break;
                        }
                        case VALUE_W_OFFSET:
                        {
                            char toBeSent[strlen(keys[g+1]) - 1];
                            strcpy(toBeSent, &keys[g+1][1]);
                            if(getHexFromValue(toBeSent) != -1){
                                oper1 = getHexFromValue(toBeSent) + origin;
                            }else{
                                printf("ERROR - %s - What am I supposed to do with this?\n", toBeSent);
                            }
                            break;
                        }
                    }
                }
                if(op2isRegister){
                    oper2 = getRegisterFromOperandType(op2);
                }else{
                    switch(op2){
                        case VALUE: 
                        {
                            // Check for hex
                            if(getHexFromValue(keys[g+2]) != -1){
                                oper2 = getHexFromValue(keys[g+2]);
                            }else{
                                if(keys[g+2][0] == '\''){
                                    oper2 = (char)keys[g+2][1];
                                }
                            }
                            break;
                        }
                        case POINTER:
                        {
                            // We gotta remove the '&'
                            char toBeSent[strlen(keys[g+2]) - 1];
                            strcpy(toBeSent, &keys[g+2][1]);
                            int locPoint = getHexFromValue(toBeSent);
                            if(locPoint > 0xFF){
                                // Split it
                                fatten1Or2 = 2;
                                oper2 = locPoint & 0xFF; // Low
                                operO = (locPoint >> 8) /*& 0xFF*/; // High 
                            }else{
                                oper2 = locPoint;
                            }
                            break;
                        }
                        case VALUE_W_OFFSET:
                        {
                            char toBeSent[strlen(keys[g+2]) - 1];
                            strcpy(toBeSent, &keys[g+2][1]);
                            if(getHexFromValue(toBeSent) != -1){
                                oper2 = getHexFromValue(toBeSent) + origin;
                            }else{
                                printf("ERROR - %s - What am I supposed to do with this?\n", toBeSent);
                            }
                            break;
                        }
                    }
                }

                // Figure out the command
                if(op1isRegister && op2isRegister){
                    command = 0xA0;
                }
                if(op1isRegister && (op2 == VALUE || op2 == VALUE_W_OFFSET)){
                    command = 0xA1;
                }
                if(op1 == POINTER && op2isRegister){
                    command = 0xA2;
                }
                if(op1 == POINTER && (op2 == VALUE || op2 == VALUE_W_OFFSET)){
                    command = 0xA3;
                }

                printf("Writing to disk: %x %x %x (%x)\n", command, oper1, oper2, operO);

                // Write individual bits in
                output[written++] = command;
                output[written++] = oper1;
                if(fatten1Or2 == 1) output[written++] = operO;
                output[written++] = oper2;
                if(fatten1Or2 == 2) output[written++] = operO;
            }
        }
    }

    fwrite(output, sizeof(unsigned char), written, fo);

    return 0;
}


OperandType getOpType(char* op){
    if(op[0] == '&'){
        return POINTER;
    }
    if(op[0] == '*'){
        return VALUE_W_OFFSET;
    }
    // Goddamn it compare it to all the registers 
    if(strcmp("ax", op) == 0){
        return REGISTER_AX;
    }
    if(strcmp("bx", op) == 0){
        return REGISTER_BX;
    }
    if(strcmp("cx", op) == 0){
        return REGISTER_CX;
    }
    if(strcmp("dx", op) == 0){
        return REGISTER_DX;
    }
    return VALUE;
}

void usage(){
    printf("Titanium Assembler\n");
    printf("./TASM inputFile.tasm outputfile\n");
}

int getHexFromValue(char* value){
    if(strncmp(value, "0x", 2) == 0){
        // WAOW
        return (int)strtol(value, NULL, 0);
    }
    // return -1 if nah
    return -1;
}

int getRegisterFromOperandType(OperandType reg){
    switch(reg){
        case REGISTER_AX:
            return 0xAA;
        case REGISTER_BX:
            return 0xAB;
        case REGISTER_CX:
            return 0xAC;
        case REGISTER_DX:
            return 0xAD;
            break;
    }
    return 0x00;
}