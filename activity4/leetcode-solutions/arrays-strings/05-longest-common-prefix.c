#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }
    
    // Find the initial length of the first string
    int prefixLen = 0;
    while (strs[0][prefixLen] != '\0') {
        prefixLen++;
    }
    
    // Compare the prefix with each subsequent string
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        while (j < prefixLen && strs[i][j] != '\0' && strs[0][j] == strs[i][j]) {
            j++;
        }
        prefixLen = j; // Update the prefix length to the common length found
        
        if (prefixLen == 0) {
            break;
        }
    }
    
    // Allocate memory for the result string (+1 for the null terminator)
    char* result = (char*)malloc((prefixLen + 1) * sizeof(char));
    for (int i = 0; i < prefixLen; i++) {
        result[i] = strs[0][i];
    }
    result[prefixLen] = '\0';
    
    return result;
}
