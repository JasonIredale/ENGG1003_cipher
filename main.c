#include <stdio.h>
int main() {
    {}
    {}
    {}
    {}
    FILE *inp;
    FILE *outp;

    char text[512];
    char index = &text;    
    inp = fopen("Caesar Input", "r");
    outp = fopen("Caesar Decryption", "w");
    fscanf(inp, "%c", &index);
    int key = index-22;         //Enter cipher key in the 1st text space of enc.txt
    fscanf(inp, "%c", &index);  //This removes the cipher key from dec.out and keeps it uniform to stdout

    while (feof(inp)==0) {      //while (there is still text to read from enc.txt) 
        
        if (65<=index && index<=90) {
            index = (index - 13 - key) % 26 + 65;
            fprintf(outp, "%c", index);
            printf("%c", index);        //"All output should be sent to BOTH the file and stdout"- 3.1.2 Outputs
            fscanf(inp, "%c", &index);
        }
        
        else if (97<=index && index<=122) {//"If a lowercase letter is found... convert it to uppercase" - 3.2 Message text specification
            index = (index - 19 - key) % 26 + 65;
            fprintf(outp, "%c", index);
            printf("%c", index);        //"All output should be sent to BOTH the file and stdout"- 3.1.2 Outputs
            fscanf(inp, "%c", &index);
        }
        
        else {//"Do not encrypt white space, punctuation or numerals" - 3.2 Message text specification
            fprintf(outp, "%c", index);
            printf("%c", index);        //"All output should be sent to BOTH the file and stdout"- 3.1.2 Outputs
            fscanf(inp, "%c", &index);
        }  
    

    }
    
    fclose(inp);
    fclose(outp);    
    return 0;
}