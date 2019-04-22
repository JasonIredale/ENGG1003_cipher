#include <stdio.h>
int main() {
    FILE *inp;
    FILE *outp;
    char text[512];
    char index = &text;
    int key = 0;
    int choice = 0;
    
    printf("Enter a number in 'input' then the message you want to encrypt below it:\n(1) Rotation Encryption\n(2) Rotation Decryption\n\n(3) Substitution Encryption\n(4) Substitution Decryption\n");
    scanf("%d", &choice);
      
    switch (choice) {
        case 1:                     //Rotation Encryption
        
        inp = fopen("Caesar Input", "r");
        outp = fopen("Caesar Encryption", "w");
        
        fscanf(inp, "%c", &index);  //Reads the first text space in Ceasar Input
        key = index-48;             //Turns the ASCII number in input to the cipher number
        fscanf(inp, "%c", &index);  //This skips the cipher key and keeps Caesar Encryption uniform to stdout
        if (48<=index && index<=57)
            key =key*10 + index-48;        
        while (feof(inp)==0) {      //while (there is still text to read from Input) 
            if (65<=index && index<=90) {
                index = (index - 13 + key) % 26 + 65;   //We add the key value for encryption
            }
            else if (97<=index && index<=122) {     //"If a lowercase letter is found... convert it to uppercase" - 3.2 Message text specification
                index = (index - 19 + key) % 26 + 65;
            }
            else if (index==13) {
                printf("\n");
            } 
            fprintf(outp, "%c", index);
            printf("%c", index);        //"All output should be sent to BOTH the file and stdout"- 3.1.2 Outputs
            fscanf(inp, "%c", &index);  //Reads the next text character, acts as a sort of increment feature
        }
        break;
    
    case 2:                         //Caesar Decryption  
        printf("Caesar Decrytion:\n");
        inp = fopen("Caesar Input", "r");
        outp = fopen("Caesar Decryption", "w");
        
        fscanf(inp, "%c", &index);  //Reads the first text space in Ceasar Input
        key = index-48;          //Turns the ASCII number in input to the cipher number
        fscanf(inp, "%c", &index);  //This skips the cipher key and keeps Caesar Encryption uniform to stdout
        if (48<=index && index<=57)
            key =key*10 + index-48;
        key=-key;
        while (feof(inp)==0) {      //while (there is still text to read from Input) 
            if (65<=index && index<=90) {
                index = (index - 13 + key) % 26 + 65;   //We add the key value for encryption
            }
            else if (97<=index && index<=122) {     //"If a lowercase letter is found... convert it to uppercase" - 3.2 Message text specification
                index = (index - 19 + key) % 26 + 65;
            }
            else if (index==13) {
                printf("\n");
            } 
            fprintf(outp, "%c", index);
            printf("%c", index);        //"All output should be sent to BOTH the file and stdout"- 3.1.2 Outputs
            fscanf(inp, "%c", &index);  //Reads the next text character, acts as a sort of increment feature
        }
        break;

    
        case 3: //Substitution Encryption 
        printf("Substitution Encryption:\n");
        inp = fopen("Substitution Input", "r");
        outp = fopen("Substitution Encryption", "w");
        fscanf(inp, "%c", &index);  //Reads the first text space in Ceasar Input
        key = index-48;          //Turns the ASCII number in input to the cipher number
        fscanf(inp, "%c", &index);  //This skips the cipher key and keeps Caesar Encryption uniform to stdout
        if (48<=index && index<=57)
            key =key*10 + index-48;  
        while (feof(inp)==0) {      //while (there is still text to read from Input) 
            if (65<=index && index<=90) {
                index = (index - 13 + key) % 26 + 65;   //We add the key value for encryption
            }
            else if (97<=index && index<=122) {     //"If a lowercase letter is found... convert it to uppercase" - 3.2 Message text specification
                index = (index - 19 + key) % 26 + 65;
            }
            else if (index==13) {
                printf("\n");
            }
            fprintf(outp, "%c", index);
            printf("%c", index);        //"All output should be sent to BOTH the file and stdout"- 3.1.2 Outputs
            fscanf(inp, "%c", &index);  //Reads the next text character, acts as a sort of increment feature
        }
        break;

        case 4: //Substitution Decryption  
        printf("Substitution Decryption:\n");
        inp = fopen("Substitution Input", "r");
        outp = fopen("Substitution Decryption", "w");
        fscanf(inp, "%c", &index);  //Reads the first text space in Ceasar Input
        key = index-48;          //Turns the ASCII number in input to the cipher number
        fscanf(inp, "%c", &index);  //This skips the cipher key and keeps Caesar Encryption uniform to stdout
        if (48<=index && index<=57)
            key =key*10 + index-48;
        key=-key;
        while (feof(inp)==0) {      //while (there is still text to read from Input) 
            if (65<=index && index<=90) {
                index = (index - 13 + key) % 26 + 65;   //We add the key value for encryption
            }
            else if (97<=index && index<=122) {     //"If a lowercase letter is found... convert it to uppercase" - 3.2 Message text specification
                index = (index - 19 + key) % 26 + 65;
            }
            else if (index==13) {
                printf("\n");
            }            
            fprintf(outp, "%c", index);
            printf("%c", index);        //"All output should be sent to BOTH the file and stdout"- 3.1.2 Outputs
            fscanf(inp, "%c", &index);  //Reads the next text character, acts as a sort of increment feature
        }
        break;
        
        default:
        return 0;
    }
    fclose(inp);
    fclose(outp);    
    return 0;
}