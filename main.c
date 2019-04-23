#include <stdio.h>

char rotf(char i, int k);

int main() {
    FILE *inp;
    FILE *outp;
    FILE *subf;
    inp = fopen("input", "r");
    outp = fopen("output", "w");
    subf = fopen("Substitution_Key", "r");
    char text[512];
    char index = &text;
    char substitution_key_alphabet[32];
    char subkey = &substitution_key_alphabet;
    int key = 0;
    int choice = 0;
    
    char A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
    int n;

    printf("\nPlease enter your message in 'input' and choose a cipher:\n\n(1) Rotation Encryption\n(2) Rotation Decryption\n");
    printf("(3) Substitution Encryption\n(4) Substitution Decryption\n");
    scanf("%d", &choice);
    
    
    switch (choice) {
        
        case 1:                                     //Rotation Encryption
        printf("\nPlease enter a cipher key.\n");
        scanf("%d", &key);
        fscanf(inp, "%c", &index);                  //This skips the cipher key and keeps Caesar Encryption uniform to stdout
        while (feof(inp)==0) {                      //while (there is still text to read from Input) 
            fprintf(outp, "%c", rotf(index, key));
            printf("%c", rotf(index, key));         //"All output should be sent to BOTH the file and stdout"- 3.1.2 Outputs
            fscanf(inp, "%c", &index);              //Reads the next text character, acts as a sort of increment feature
        }
        printf("\n\n");
        fprintf(outp, "\n\n");
        break;
            
        case 2:                                         //Caesar Decryption  
        printf("\nPlease choose choose a cipher key. If you do not have one, enter <0>.\n");
        scanf("%d", &key);
        if(key==0) {
            for (key=0;key<=25;key++) {
                fprintf(outp, "(%d)\n", key);
                fscanf(inp, "%c", &index);                  //This skips the cipher key and keeps Caesar Encryption uniform to stdout
                while (feof(inp)==0) {                      //while (there is still text to read from Input) 
                    fprintf(outp, "%c", rotf(index, -key));
                    if (rotf(index, -key)==32) {
                        fscanf(inp, "%c", &index);              //Reads the next text character, acts as a sort of increment feature
                        fprintf(outp, "%c", rotf(index, -key));
                        if (rotf(index, -key)==84) {            // "T"
                            fscanf(inp, "%c", &index);              //Reads the next text character, acts as a sort of increment feature
                            fprintf(outp, "%c", rotf(index, -key));
                            if (rotf(index, -key)==72) { //TH
                                fscanf(inp, "%c", &index);              //Reads the next text character, acts as a sort of increment feature
                                fprintf(outp, "%c", rotf(index, -key));
                                if (rotf(index, -key)==69) { //THE
                                    fscanf(inp, "%c", &index);              //Reads the next text character, acts as a sort of increment feature
                                    fprintf(outp, "%c", rotf(index, -key));
                                    if(rotf(index, -key)==32) {
                                        rewind (inp);
                                        fclose(outp);             
                                        outp = fopen("output", "w");
                                        goto line_97;
                                    }
                                }
                            }
                        }
                    }
                    fscanf(inp, "%c", &index);              //Reads the next text character, acts as a sort of increment feature
                }
                fprintf(outp, "\n\n");
                rewind(inp); 
            }
            for (key=0;key<=25;key++) {
                fscanf(inp, "%c", &index);                  //This skips the cipher key and keeps Caesar Encryption uniform to stdout
                while (feof(inp)==0) {                      //while (there is still text to read from Input) 
                    if (rotf(index, -key)==32) {
                        fscanf(inp, "%c", &index);              //Reads the next text character, acts as a sort of increment feature
                        if (rotf(index, -key)==73) {            // "I"
                            fscanf(inp, "%c", &index);              //Reads the next text character, acts as a sort of increment feature
                            if (rotf(index, -key)==70 || rotf(index, -key)==78 || rotf(index, -key)==83 || rotf(index, -key)==84) { //IF, IT, IS or IN
                                fscanf(inp, "%c", &index);              //Reads the next text character, acts as a sort of increment feature
                                if(rotf(index, -key)==32) {
                                    rewind (inp);
                                    fclose(outp);             
                                    outp = fopen("output", "w");
                                    goto line_97;
                                }
                            }
                        } 
                    }
                    fscanf(inp, "%c", &index);              //Reads the next text character, acts as a sort of increment feature
                }
                rewind(inp);
            }
            printf("Could not deduce decryption. All possible decryptions sent to file'output'\n");
        }
        else {
            line_97:
            fprintf(outp, "(%d)\n", key);
            printf("\n(%d)\n", key);
            fscanf(inp, "%c", &index);                  //This skips the cipher key and keeps Caesar Encryption uniform to stdout
            while (feof(inp)==0) {                      //while (there is still text to read from Input) 
                fprintf(outp, "%c", rotf(index, -key));
                printf("%c", rotf(index, -key));         //"All output should be sent to BOTH the file and stdout"- 3.1.2 Outputs
                fscanf(inp, "%c", &index);              //Reads the next text character, acts as a sort of increment feature
            }
            printf("\n\n");
        }
        break;
        
        
        
        case 3:                                     //Substitution Encryption 
        fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); A = subkey - 65;     fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); B = subkey - 65;
        fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); C = subkey - 65;     fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); D = subkey - 65;
        fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); E = subkey - 65;     fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); F = subkey - 65;
        fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); G = subkey - 65;     fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); H = subkey - 65;
        fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); I = subkey - 65;     fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); J = subkey - 65;
        fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); K = subkey - 65;     fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); L = subkey - 65;
        fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); M = subkey - 65;     fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); N = subkey - 65;
        fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); O = subkey - 65;     fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); P = subkey - 65;
        fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); Q = subkey - 65;     fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); R = subkey - 65;
        fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); S = subkey - 65;     fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); T = subkey - 65;
        fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); U = subkey - 65;     fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); V = subkey - 65;
        fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); W = subkey - 65;     fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); X = subkey - 65;
        fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); Y = subkey - 65;     fscanf(subf, "%c", &subkey); subkey = rotf(subkey, 0); Z = subkey - 65;
        
        fscanf(inp, "%c", &index);
        while (feof ==0) {
        index = rotf(index, 0);
        if (index == 65){
            index = index + A;
        }
        else if (index == 66) {
            index = index + B;
        } ...
            .
            .
            .
        fprintf(outp, "%c", index);
        fscanf(inp, "%c", index);
    }
    
        break;

        case 4:                                     //Substitution Decryption  
        break;
        
        default:
        return 0;
    }
    fclose(inp);
    fclose(outp);    
    fclose(subf);
    return 0;  
}


char rotf(char i, int k) {
    if (65<=i && i<=90) {
        i = (i - 13 + k) % 26 + 65;   //We add the key value for encryption
    }
    else if (97<=i && i<=122) {     //"If a lowercase letter is found... convert it to uppercase" - 3.2 Message text specification
        i = (i - 19 + k) % 26 + 65;
    }
    return i;
}