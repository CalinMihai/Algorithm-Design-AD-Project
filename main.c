#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct g_node{
    int info;
    struct g_node *next;
};

void push_element_end(struct g_node *head ,int new_element_value){
    struct g_node *new_element = malloc(sizeof(struct g_node));
    struct g_node *iterator = head;
    struct g_node *last_element;

    while (iterator->next != NULL) {
        iterator = iterator->next;
    }
    last_element = iterator;

    last_element->next = new_element;
    new_element->info = new_element_value;
    new_element->next = NULL;
}

int pop_element_end(struct g_node *head){
    struct g_node *poped_element;
    struct g_node *iterator = head;
    int aux;

    while (  iterator -> next -> next != NULL) {
        iterator = iterator->next;
    }

    poped_element = iterator->next;
    aux = poped_element->info;
    iterator->next = poped_element->next;

    free(poped_element);

    return aux;
}

void print_list(struct g_node *head){
    struct g_node *iterator = head;

    while (iterator->next != NULL) {
        printf("%d ", iterator->next->info);
        iterator = iterator->next;
    }
    printf("\n");
}

int return_no_elements(struct g_node *head){
    int no_elements ;
    struct g_node *iterator;
    iterator = head;
    no_elements = 0;

    while (iterator->next != NULL) {
        iterator = iterator->next;
        ++no_elements;
    }
    return no_elements;
}

void rosenstiehl(int n, int ma[6][6], int u, struct g_node *head, struct g_node *head2) {
    int v;
    push_element_end(head, u);
    while (return_no_elements(head)) {
        u = pop_element_end(head);
        v = 0;
        while (v < n) {
            if (ma[u][v] == 1) {
                ma[u][v] = 0;
                ma[v][u] = 0;
                push_element_end(head, u);
                u = v;
                v = 0;
            }
            else v++;
        }
        push_element_end(head2, u);
    }
}


int main(){
    struct g_node *head = malloc(sizeof(struct g_node));
    head->next = NULL;
    struct g_node *head2 = malloc(sizeof(struct g_node));
    head2->next = NULL;


    int aux, aux2;
    int i, j;
    int ma[6][6] = {0, 1, 1, 1, 1, 0,
                    1, 0, 1, 1, 1, 0,
                    1, 1, 0, 1, 0, 1,
                    1, 1, 1, 0, 0, 1,
                    1, 1, 0, 0, 0, 0,
                    0, 0, 1, 1, 0, 0};

    for(i = 0; i < 6; i++){
        for(j = 0; j < 6; j++){
               printf("%5d ",ma[i][j]);
        }
        printf("\n");
    }
    rosenstiehl(6, ma, 0, head, head2);
    print_list(head2);

    free(head);
    free(head2);

    return 0;
}
