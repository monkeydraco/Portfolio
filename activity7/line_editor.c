#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LEN 256

char lines[MAX_LINES][MAX_LEN];
int line_count = 0;

// Undo tracking variables
int last_action = 0;        // 0: None, 1: Insert was done, 2: Delete was done
int undo_line_num = 0;      
char undo_text[MAX_LEN];    

void print_help() {
    printf("\n--- Advanced Line Editor Help ---\n");
    printf("  p                  - Display document state with line numbers\n");
    printf("  i <line> <text>    - Insert a line at a given number\n");
    printf("  d <line>           - Delete a line at a given number\n");
    printf("  u                  - Undo last insert or delete action (Bonus!)\n");
    printf("  f <keyword>        - Search for a word or phrase (Bonus!)\n");
    printf("  s <filename>       - Save document to text file\n");
    printf("  l <filename>       - Load document from text file\n");
    printf("  h                  - Show this help menu\n");
    printf("  q                  - Quit the editor\n");
    printf("----------------------------------\n");
}

void display_document() {
    if (line_count == 0) {
        printf("Document is empty.\n");
        return;
    }
    printf("\n--- Document State ---\n");
    for (int i = 0; i < line_count; i++) {
        printf("%3d: %s", i + 1, lines[i]);
    }
    printf("----------------------\n");
}

void insert_line(int line_num, const char *text, int record_undo) {
    if (line_num < 1 || line_num > line_count + 1) {
        printf("Error: Invalid line number.\n");
        return;
    }
    if (line_count >= MAX_LINES) {
        printf("Error: Document is full.\n");
        return;
    }

    // Shift lines down
    for (int i = line_count; i >= line_num; i--) {
        strcpy(lines[i], lines[i - 1]);
    }
    
    strcpy(lines[line_num - 1], text);
    if (strchr(lines[line_num - 1], '\n') == NULL) {
        strcat(lines[line_num - 1], "\n");
    }
    
    line_count++;

    if (record_undo) {
        last_action = 1; // 1 means last action was an insert
        undo_line_num = line_num;
    }
    printf("Line inserted successfully.\n");
}

void delete_line(int line_num, int record_undo) {
    if (line_num < 1 || line_num > line_count) {
        printf("Error: Invalid line number.\n");
        return;
    }

    if (record_undo) {
        last_action = 2; // 2 means last action was a delete
        undo_line_num = line_num;
        strcpy(undo_text, lines[line_num - 1]);
    }

    // Shift lines up
    for (int i = line_num - 1; i < line_count - 1; i++) {
        strcpy(lines[i], lines[i + 1]);
    }
    
    line_count--;
    printf("Line deleted successfully.\n");
}

void undo_last_action() {
    if (last_action == 0) {
        printf("Error: Nothing to undo.\n");
        return;
    }

    if (last_action == 1) {
        // Reverse of insert is deleting that line (without re-recording undo)
        delete_line(undo_line_num, 0);
        printf("Undo successful: Reversed last insert.\n");
    } else if (last_action == 2) {
        // Reverse of delete is inserting that line back (without re-recording undo)
        insert_line(undo_line_num, undo_text, 0);
        printf("Undo successful: Restored deleted line.\n");
    }
    last_action = 0; // Reset after undo
}

void search_keyword(const char *keyword) {
    int found = 0;
    printf("\n--- Search Results for '%s' ---\n", keyword);
    for (int i = 0; i < line_count; i++) {
        if (strstr(lines[i], keyword) != NULL) {
            printf("Line %d: %s", i + 1, lines[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Keyword not found in the document.\n");
    }
    printf("-------------------------------\n");
}

void save_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error: Could not open file for writing.\n");
        return;
    }
    for (int i = 0; i < line_count; i++) {
        fputs(lines[i], file);
    }
    fclose(file);
    printf("Document saved to %s successfully.\n", filename);
}

void load_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file for reading.\n");
        return;
    }
    line_count = 0;
    last_action = 0;
    while (fgets(lines[line_count], MAX_LEN, file) != NULL && line_count < MAX_LINES) {
        line_count++;
    }
    fclose(file);
    printf("Document loaded from %s successfully.\n", filename);
}

int main() {
    char cmd[10];
    char filename[50];
    char text[MAX_LEN];
    int line_num;

    printf("=== Advanced Command-Line Line Editor ===\n");
    printf("Type 'h' for help. Type 'q' to quit.\n");

    while (1) {
        printf("\ncmd> ");
        if (scanf("%s", cmd) != 1) break;

        if (strcmp(cmd, "q") == 0) {
            break;
        } else if (strcmp(cmd, "h") == 0) {
            print_help();
        } else if (strcmp(cmd, "p") == 0) {
            display_document();
        } else if (strcmp(cmd, "i") == 0) {
            scanf("%d", &line_num);
            getchar(); // clear newline buffer
            fgets(text, MAX_LEN, stdin);
            insert_line(line_num, text, 1);
        } else if (strcmp(cmd, "d") == 0) {
            scanf("%d", &line_num);
            delete_line(line_num, 1);
        } else if (strcmp(cmd, "u") == 0) {
            undo_last_action();
        } else if (strcmp(cmd, "f") == 0) {
            scanf("%s", text);
            search_keyword(text);
        } else if (strcmp(cmd, "s") == 0) {
            scanf("%s", filename);
            save_file(filename);
        } else if (strcmp(cmd, "l") == 0) {
            scanf("%s", filename);
            load_file(filename);
        } else {
            printf("Unknown command. Type 'h' for help.\n");
        }
    }
    return 0;
}
