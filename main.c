#include <stdio.h>

int main()
{
    FILE *inp;
    FILE *outp;
    char array_counter;
    char text[1024];
    
    int key = 5;
    int index = &text;
    
    inp = fopen("enc.txt", "r");
    outp = fopen("dec.txt", "w");
    array_counter = fscanf(inp, "%c", &index);
    
    
    while (feof(inp)==0) {
        //for (index=0; text[index] != 0; index++){
        index=index-key;   
       //}
        
        fprintf(outp, "%c", index);
        array_counter = fscanf(inp, "%c", &index);
    }
    

    fclose(inp);
    fclose(outp);
    
    return 0;
}