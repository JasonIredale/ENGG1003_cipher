#include <stdio.h>

int main() {
    
FILE *inp;
FILE *outp;
char array_counter;
char text[1024];
int key = 1;
char index = &text;    
inp = fopen("enc.txt", "r");
outp = fopen("dec.txt", "w");
array_counter = fscanf(inp, "%c", &index);


    while (feof(inp)==0) {      //while the text isn't at the end of the file
        if (65<=index && index<=90) {
            index=index-key;
            fprintf(outp, "%c", index);
            printf("%c", index);        //"All output should be sent to BOTH the file and stdout"- 3.1.2 Outputs
            array_counter = fscanf(inp, "%c", &index);
        }
        else if (97<=index && index<=122) {//"If a lowercase letter is found... convert it to uppercase" - 3.2 Message text specification
        //for (index=0; text[index] != 0; index++){
            index=(index-19+key) % 26 + 65;
            fprintf(outp, "%c", index);
            printf("%c", index);        //"All output should be sent to BOTH the file and stdout"- 3.1.2 Outputs
            array_counter = fscanf(inp, "%c", &index);
       //}
        }
        else {//"Do not encrypt white space, punctuation or numerals" - 3.2 Message text specification
            fprintf(outp, "%c", index);
            printf("%c", index);        //"All output should be sent to BOTH the file and stdout"- 3.1.2 Outputs
            array_counter = fscanf(inp, "%c", &index);
        }        
    }
    
fclose(inp);
fclose(outp);    
return 0;
}