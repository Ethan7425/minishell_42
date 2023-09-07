/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:15:46 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/07 12:14:23 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "../includes/minishell.h"


//Define a struct to represent a token
struct Token 
{
    char *value;
    struct Token *next;
};

// Function to create a new token
struct Token *createToken(const char *value) {
    struct Token *token = malloc(sizeof(struct Token));
    if (token == NULL) {
        perror("Malloc error");
        exit(EXIT_FAILURE);
    }
    token->value = strdup(value); // Duplicate the string
    token->next = NULL;
    return token;
}

// Function to add a token to the end of the list
void addToken(struct Token **head, const char *value) 
{
    struct Token *newToken = createToken(value);
    if (*head == NULL) {
        *head = newToken;
    } else {
        struct Token *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newToken;
    }
}

// Function to free the memory used by the list of tokens
void freeTokens(struct Token *head) 
{
    while (head != NULL) {
        struct Token *temp = head;
        head = head->next;
        free(temp->value);
        free(temp);
    }
}

int main() 
{
    struct Token *tokenList = NULL; // Initialize an empty list of tokens

    // Adding tokens to the list
    // addToken(&tokenList, "echo");
    // addToken(&tokenList, "Hello");
    // addToken(&tokenList, "world");

    // Printing the tokens
    struct Token *current = tokenList;
    while (current != NULL) 
	{
        printf("%s-", current->value);
        current = current->next;
    }
    printf("\n");

    // Freeing memory
    freeTokens(tokenList);

    return 0;
}
