#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_spaces(string text);
int count_sentences(string text);
int index;

// An array storing each of the text grade options - change 1,2,3 to the actual grade. Will do this later!
int GRADEarr[] = {1,2,3};

//main function gathers inoout text and outputs letters, words, and sentences. Will finally make it output the grade
int main(void) {

    // Get input text from user to be evaluated
    string text = get_string("Enter text: ");
    printf("%i\n", count_letters(text));
    printf("%i\n", count_spaces(text));
    printf("%i\n", count_sentences(text));
    printf("%i\n", index);
    
    
    // Calculate the average number of letters per 100 words in the text (= L)
    float L = (float)(count_letters(text)) / (float)(count_spaces(text)) * 100;

    // Calculate the average number of sentences per 100 words in the text (= S)
    float S = (float)(count_sentences(text)) / (float)(count_spaces(text)) * 100;

    // Calculate the Coleman-Liau index
    index = round(0.0588 * L - 0.296 * S - 15.8);

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
        if ((text[i]) == '.' || (text[i]) == '!' || (text[i]) == '?') {
            sentences ++;
        }
    }
    return sentences;
}

