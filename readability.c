#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_spaces(string text);

// An array storing each of the text grade options - change 1,2,3 to the actual grade. Will do this later!
int GRADEarr[] = {1,2,3};

//main function gathers inoout text and outputs letters, words, and sentences. Will finally make it output the grade
int main(void) {
   
    // Get input text from user to be evaluated
    string text = get_string("Enter text: ");
    printf("%i\n", count_letters(text));
    printf("%i\n", count_spaces(text));
    
}
    
    // Print the number of letters
    int count_letters(string text) {
    int letters = 0;
    
    for (int i = 0; i < strlen(text); i++) {
        if (isupper(text[i])) {
            letters ++;
        } else if (islower(text[i])) {
            letters ++;
        }
    }
    return letters;
}
    
    // Print the number of words
    int count_spaces(string text) {
    int spaces = 0;
    
    for (int i = 0; i < strlen(text); i++) {
        if (isspace(text[i])) {
            spaces ++;
        }
    }
    return (spaces + 1);
}
    
    // Print the number of sentences
    int count_sentences(string text) {
    int sentences = 0;
    
    for (int i = 0; i < strlen(text); i++) {
        if ((text[i]) = '.' || '!' || '?') {
            sentences ++;
        }
    }
    return (sentences);
}
    
    // Calculate the average number of letters per 100 words in the text (= L)
    
    // Calculate the average number of sentences per 100 words in the text (= S)
    
    // Calculate the Coleman-Liau index
    
