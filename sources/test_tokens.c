#include <stdio.h>
#include <stdlib.h>

// Define enumeration types for redirection
typedef enum e_redirect_in {
    NO_R_IN,
    INPUT_REDIRECT,
    HEREDOC_REDIRECT
} t_redirect_in;

typedef enum e_redirect_out {
    NO_R_OUT,
    OUTPUT_REDIRECT,
    APPEND_REDIRECT
} t_redirect_out;

// Define the structure for redirection settings
typedef struct s_redirect {
    char *infile;
    char *outfile;
    int infile_fd;
    int outfile_fd;
    int is_valid_infile;
    int *heredoc_pipe;
    t_redirect_in r_in_type;
    t_redirect_out r_out_type;
} t_redirect;

// Define the structure for a command token
typedef struct s_token {
    char **cmd_arr;
    int is_valid_cmd;
    int is_builtin;
    t_redirect redirect;
    int pid;
    int id;
    struct s_token *next;
} t_token;

int main() {
    // Create a sample t_redirect struct
    t_redirect redir = {
        .infile = "input.txt",
        .outfile = "output.txt",
        .infile_fd = 3,
        .outfile_fd = 4,
        .is_valid_infile = 1,
        .heredoc_pipe = NULL,
        .r_in_type = INPUT_REDIRECT,
        .r_out_type = OUTPUT_REDIRECT,
    };

    // Create a sample t_token struct
    t_token token = {
        .cmd_arr = NULL,  // Placeholder for the command arguments
        .is_valid_cmd = 1,
        .is_builtin = 0,
        .redirect = redir,  // Assign the redirection settings
        .pid = 123,
        .id = 1,
        .next = NULL,
    };

    // Display the contents of the t_token struct
    printf("Token ID: %d\n", token.id);
    printf("Is Valid Command: %d\n", token.is_valid_cmd);
    printf("Is Builtin: %d\n", token.is_builtin);
    printf("PID: %d\n", token.pid);

    // Display the redirection settings within the t_token struct
    printf("Redirection Settings:\n");
    printf("Input File: %s\n", token.redirect.infile);
    printf("Output File: %s\n", token.redirect.outfile);
    printf("Input File Descriptor: %d\n", token.redirect.infile_fd);
    printf("Output File Descriptor: %d\n", token.redirect.outfile_fd);
    printf("Is Valid Input File: %d\n", token.redirect.is_valid_infile);
    printf("Input Redirection Type: %d\n", token.redirect.r_in_type);
    printf("Output Redirection Type: %d\n", token.redirect.r_out_type);

    return 0;
}
