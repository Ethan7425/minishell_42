#include <stdio.h>
#include <stdlib.h>

// Define enumeration types for redirion
typedef enum e_redir_in {
    NO_R_IN,
    INPUT_redir,
    HEREDOC_redir
} t_redir_in;

typedef enum e_redir_out {
    NO_R_OUT,
    OUTPUT_redir,
    APPEND_redir
} t_redir_out;

// Define the structure for redirion settings
typedef struct s_redirt {
    char *infile;
    char *outfile;
    int infile_fd;
    int outfile_fd;
    int is_valid_infile;
    int *heredoc_pipe;
    t_redir_in r_in_type;
    t_redir_out r_out_type;
} t_redir;

// Define the structure for a command token
typedef struct s_token {
    char **cmd_arr;
    int is_valid_cmd;
    int is_builtin;
    t_redir redir;
    int pid;
    int id;
    struct s_token *next;
} t_token;















int main() {
    // Create a sample t_redir struct
    t_redir redir = {
        .infile = "input.txt",
        .outfile = "output.txt",
        .infile_fd = 3,
        .outfile_fd = 4,
        .is_valid_infile = 1,
        .heredoc_pipe = NULL,
        .r_in_type = INPUT_redir,
        .r_out_type = OUTPUT_redir,
    };

    // Create a sample t_token struct
    t_token token = {
        .cmd_arr = NULL,  // Placeholder for the command arguments
        .is_valid_cmd = 1,
        .is_builtin = 0,
        .redir = redir,  // Assign the redirion settings
        .pid = 123,
        .id = 1,
        .next = NULL,
    };

    // Display the contents of the t_token struct
    printf("Token ID: %d\n", token.id);
    printf("Is Valid Command: %d\n", token.is_valid_cmd);
    printf("Is Builtin: %d\n", token.is_builtin);
    printf("PID: %d\n", token.pid);

    // Display the redirion settings within the t_token struct
    printf("redirion Settings:\n");
    printf("Input File: %s\n", token.redir.infile);
    printf("Output File: %s\n", token.redir.outfile);
    printf("Input File Descriptor: %d\n", token.redir.infile_fd);
    printf("Output File Descriptor: %d\n", token.redir.outfile_fd);
    printf("Is Valid Input File: %d\n", token.redir.is_valid_infile);
    printf("Input redirion Type: %d\n", token.redir.r_in_type);
    printf("Output redirion Type: %d\n", token.redir.r_out_type);

    return 0;
}
