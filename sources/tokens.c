/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:15:46 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/07 23:23:16 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/minishell.h"


//Define a struct to represent a token

// Function to create a new token
struct token *createToken(const char *value) {
    struct token *token = malloc(sizeof(struct token));
    if (token == NULL) {
        perror("Malloc error");
        exit(EXIT_FAILURE);
    }
    token->value = strdup(value); // Duplicate the string
    token->next = NULL;
    return token;
}

// Function to add a token to the end of the list
void addToken(struct token **head, const char *value) 
{
    struct token *newToken = createToken(value);
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
void freeTokens(struct token *head) 
{
    while (head != NULL) {
        struct token *temp = head;
        head = head->next;
        free(temp->value);
        free(temp);
    }
}

int main() 
{
    struct token *tokenList = NULL; // Initialize an empty list of tokens

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
