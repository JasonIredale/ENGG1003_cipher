/*
ENNG1003 Assessment 1 "Cipher Programming in C":
This program reads text from an input file, does an operation on the characters, then prints the tranformed string into an output file and the terminal.
The four operations this program can compute are:
    (1) Rotation Encryption
    (2) Rotation Decryption with or without a key (given that the input text has some key words like "the" or "if")
    (3) Substitution Encryption
    (4) Substitution Decryption only with a key.
    Note that it would be nonsensical to ask to attempt to encrypt a text without a key.
    
The program consists of int main and a single self-written function "rotf" (rotation function), the function definition is at the bottom of the program.
Int main consists of variable declarations, a "friendly user interface" and a switch statement to determine which operation will be executed.
I decided to not repeat my comments, or at least repeat them scarecly. There is quite a substancial amount of similarities between operations and it seems pointless to explain how lines work when it has already been discussed prior.
WARNING: a "goto" function is used in operation (2) because I could not figure out a functional way to break out of two loops instantaneoulsy.
*/



#include <stdio.h>

char rotf(char i, int k);                   //The rotation function takes a letter in the english alphabet (i) and rotates it by "k" places.

int main() {
    FILE *inp;
    FILE *outp;
    FILE *sub;
    inp = fopen("input", "r");                  // "inp" reads the file, "input". Where the initial text is entered into.
    outp = fopen("output", "w");                //"outp" wipes the contents then writes in the file, "output". Where the transformed text is sent to.
    sub = fopen("Substitution_Key", "r");       //"sub" reads the file, "Substitution_key". The substitution key is entered IN ALHPABETICAL ORDER.
    char text[1024];                            // The string of characters in file "input" that we shall transform through operation.
    char index = &text;                         // A pointer to the text string beginning at the 0th character. the ordered place of the character being read increments automatically after every reading.
    char substitution_key_str[26];              // The string of characters in the file "Substitution_key".
    char subkey = &substitution_key_str;        // A pointer to the string. It functions simialarly to "index"
    int key = 0;                                // The value for which the rotation cipher will rotate. Used in rotation operations.
    int choice = 0;                             // the variable to disern the operations via a switch statement.
    int j = 0;                                  // An arbitrary variable used for incrementing in substitution operations.

    //Below are immediate instructions on how to interact with the program and execute a cipher operation.
    printf("\nPlease enter your message in file 'input' and choose a cipher operation:\n");
    printf("\n(1) Rotation Encryption\n(2) Rotation Decryption\n(3) Substitution Encryption\n(4) Substitution Decryption\n");
    printf("\nNOTE: If you want to use a substitution operation, please make sure yout key is entered in alphabetical order with no space nor new lines\n");
    scanf("%d", &choice);                       // Reads an integer from stdin and compares it the the operation "cases" in the "switch" block.
    
    
    switch (choice) {
        
        //Rotation Encryption
        case 1:
        printf("\nPlease enter a cipher key.\n");
        scanf("%d", &key);                          // Reads an integer from stdin as the rotation key.
        fscanf(inp, "%c", &index);                  // Reads the 0th character in file "input"
        while (feof(inp)==0) {                      //"while (there is still text to read from input)"...
            fprintf(outp, "%c", rotf(index, key));      //prints the text character rotated by "key" turns. *for white space, numbers and punctuation, read comments in the "rotf" function definition at the bottom of the program.
            printf("%c", rotf(index, key));             //"All output should be sent to BOTH the file and stdout"- 3.1.2 Outputs
            fscanf(inp, "%c", &index);                  //Reads the next text character, as said in the varable declaration section, this acts as a sort of increment feature on the ordered place of the character in the file "input".
        }
        printf("\n\n");
        fprintf(outp, "\n\n");
        break;
            
        //Caesar Decryption  
        case 2:
        printf("\nPlease choose choose a cipher key. If you do not have one, enter <0>.\n");//Rotating a cipher 0 places in nonsenical so I assigned it for when the user does not have the key. It will print the correct case regardlees.
        scanf("%d", &key);
        if(key==0) {                                // "If (the user does not know the key and we must deduce it from analysing the text(ACTIVATE SPELL-CHECKER))"...
            for (key=0;key<=25;key++) {                 //"for (every possible rotation key from 0 to 25)". Tests for the existance of " THE " in every transformation of the text.
                fprintf(outp, "(%d)\n", key);               // Writes the key number above the transformed text.
                fscanf(inp, "%c", &index);                  // Reads the 0th character in file "input"
                while (feof(inp)==0) {                      // "while (there is still text to read from input)"...
                    fprintf(outp, "%c", rotf(index, -key));     //writes the first transfomed character, NOTE that "key" is negative in order to invert the inbedded encryption in the initial text. ie, decrypting an encryption ~ +key -key == 0 (additive inverse).
                    if (rotf(index, -key)==32) {                //"if(transformed character is <space>)"...
                        fscanf(inp, "%c", &index);
                        fprintf(outp, "%c", rotf(index, -key));
                        if (rotf(index, -key)==84) {                //"if(transformed character is "T")" thus the ordered subset of text[] has (<space>, T)...
                            fscanf(inp, "%c", &index); 
                            fprintf(outp, "%c", rotf(index, -key));
                            if (rotf(index, -key)==72) {                //the ordered subset of text[] has (<space>, T, H)...
                                fscanf(inp, "%c", &index);
                                fprintf(outp, "%c", rotf(index, -key));
                                if (rotf(index, -key)==69) {                //the ordered subset of text[] has (<space>, T, H, E)...
                                    fscanf(inp, "%c", &index);
                                    fprintf(outp, "%c", rotf(index, -key));
                                    if(rotf(index, -key)==32) {                 //the ordered subset of text[] has (<space>, T, H, E, <space>)...
                                        rewind (inp);                               //hard reset: start from the beginning of file ""input" and 
                                        fclose(outp);
                                        outp = fopen("output", "w");                //reopen file "output", thus clearing it's contents. NOTE the last vlaue for "key" has not been changed.
                                        goto line_123;                              // Exit out of these daisy chained loop blocks and goto line 123.
                                    }
                                }
                            }
                        }
                    }
                    fscanf(inp, "%c", &index);                  //" THE " wasn't found. Read the next character and run back to the "while" loop on line 69.        
                }
                fprintf(outp, "\n\n");
                rewind(inp);                                //There was no " THE " in any transformed variations of the text. Start from the beginning of the text and test for a new word
            }
            for (key=0;key<=25;key++) {                 //Tests for the existance of " IF "" IT "" IS " or " IN " in that order.
                fscanf(inp, "%c", &index);
                while (feof(inp)==0) {
                    if (rotf(index, -key)==32) {                //the ordered subset of text[] has (<space>)...
                        fscanf(inp, "%c", &index);
                        if (rotf(index, -key)==73) {            //the ordered subset of text[] has (<space>, I)...
                            fscanf(inp, "%c", &index);
                            if (rotf(index, -key)==70 || rotf(index, -key)==78 || rotf(index, -key)==83 || rotf(index, -key)==84) { // IF, IT, IS or IN
                                fscanf(inp, "%c", &index);
                                if(rotf(index, -key)==32) {             //the ordered subset of text[] has (<space>, T, H, E, <space>)...
                                    rewind (inp);
                                    fclose(outp);             
                                    outp = fopen("output", "w");
                                    goto line_123;
                                }
                            }
                        } 
                    }
                    fscanf(inp, "%c", &index);
                }
                rewind(inp);
            }
            printf("Could not deduce decryption. All possible decryptions sent to file'output'\n"); // Words {THE, IF, IT, IS, IN} could not be found in any rotation of the the key for text[].
        }
        else {                                      // else if (user knew the key) or ("goto line_123" was activated, thus a word in [text] was found for a certain key that is still stored in the memory.)...
            line_123:
            fprintf(outp, "(%d)\n", key);
            printf("\n(%d)\n", key);                    //Informs the user of what roatiaon key the text was decrypted under.
            fscanf(inp, "%c", &index);
            while (feof(inp)==0) {
                fprintf(outp, "%c", rotf(index, -key));
                printf("%c", rotf(index, -key));
                fscanf(inp, "%c", &index);
            }
            printf("\n\n");
        }
        break;
        
        //Substitution Encryption 
        case 3:
        fscanf(inp, "%c", &index);
        while (feof(inp)==0) {
            index = rotf(index, 0);                     //Transforms the character into an uppercase letter or does nothing. *refer to function definition for more details
            if (index<65 || 90<index) {                 //"if (it isn't a letter)" Thus it is whitespace, punctiuation or a number.
                fprintf(outp, "%c", index);
                printf("%c", index);
                fscanf(inp, "%c", &index);
                continue;                                   //read the sequential character in the string text[] and go back to the beginning of the while loop.
            }
            for(j = 0; j<26; j++) {                     //"for (an arbitrary number at 0, until it equals 26, increment it" Also used for running along the alphabet in ascii form. ie incrementing 65 (A) to Z (90).
                fscanf(sub, "%c", &subkey);
                subkey = rotf(subkey, 0);                   //Transform the key character into an uppercase.
                if(subkey<65 || subkey>90) {                // "if (it isn't a letter)" Consider they key bogus and ask the user to enter it properly.
                    printf("\nSubstitution Key was entered incorrectly, Please only enter letters in the english alphabet with no spaces or new lines.\n");
                }
                if (index == subkey) {
                    index = 65 + j;
                    fprintf(outp, "%c", index);
                    printf("%c", index);
                    fscanf(inp, "%c", &index);
                    break;
                }
            }
        rewind(sub);
        }
        printf("\n\n");
        break;

        case 4:                                     //Substitution Decryption  
        fscanf(inp, "%c", &index);
        while (feof(inp)==0) {
            index = rotf(index, 0);
            if(subkey<65 || subkey>90) {
                    printf("\nSubstitution Key was entered incorrectly, Please only enter letters in the english alphabet with no spaces or new lines.\n");
                }
            if (index<65 || 90<index) {
                fprintf(outp, "%c", index);
                printf("%c", index);
                fscanf(inp, "%c", &index);
                continue;
            }
            for(j = 0; j<26; j++) {
                fscanf(sub, "%c", &subkey);
                subkey = rotf(subkey, 0);
                if (index == 65 + j) {
                    index = subkey;
                    fprintf(outp, "%c", index);
                    printf("%c", index);
                    fscanf(inp, "%c", &index);
                    break;
                }
            }
        rewind(sub);
        }
        printf("\n\n");
        break;
        
        default:
        printf("\nYou did not choose a given operation.\nGoodbye.\n");
    }
    fclose(inp);
    fclose(outp);    
    fclose(sub);
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