#include<stdio.h>
#include<conio.h>
#include "functions.h"


int main()
{
    int edge;
    int iterator1;
    int iterator2;
    int no_nodes;

    printf("Enter the number of nodes in a graph\n");
    scanf("%d", &no_nodes);

    printf("Enter the value of the nodes\n");

    nodes_array = (int*)calloc( no_nodes, sizeof(int) );

    for ( iterator1 = 0; iterator1 < no_nodes ; iterator1++ )
        scanf( "%d", &nodes_array[iterator1] );


    printf("Enter the value in adjancency matrix like so\n");
    printf("\nIf there is an edge between the two nodes enter '1' else '0'\n");


    adjacency_matrix = (int**)calloc( no_nodes, sizeof(int) );

    for ( iterator1 = 0; iterator1 < no_nodes; iterator1++ )
        adjacency_matrix[iterator1] = (int**)calloc( no_nodes, sizeof(int) );

    for( iterator1 = 0; iterator1 < no_nodes; iterator1++){
        for( iterator2 = 0; iterator2 < no_nodes; iterator2++ ){
            printf( "%d ", edge = scanf("%d", &edge) );
            if ( iterator1 == iterator2 )
                adjacency_matrix[iterator1][iterator2] = 0;
            else
                adjacency_matrix[iterator1][iterator2] = edge;
        }
        printf("\n\n");
    }


    int root;

    if ( test_for_cycle() == 1 ){
        root = nodes_array[0];
        printf("The eulerian cycle is: \n");

        eulerian_cycle_array = (int*)calloc( no_nodes + 1, sizeof(int) );
        cycle_lenght = 0;

        eulerian_cycle_array[0] = root;
        cycle_lenght++;

        find_cycle( root );
        print_cycle();
    }else
        printf("No cycle available!");

    return 0;
}
