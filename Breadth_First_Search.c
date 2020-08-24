#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct {
    int **mat;
    int number_of_vertex;
} GRAPH;


int visita_bfs(int v, int end, int colour[], GRAPH *grafo, int *predecessor_path, int *node_distance_to_target) {
    QUEUE *queue = queue_create();
    int error, i;

    colour[v] = GRAY;
    node_distance_to_target[v] = 0;
    queue_enqueue(queue, v);

    while (queue_size(queue)) {
        v = queue_dequeue(queue, &error);
        for (i = 0; i < grafo->number; i++) {
            if (colour[i] == WHITE && grafo->mat[i][v] == 1) {
                colour[i] = GRAY;
                node_distance_to_target[i] = node_distance_to_target[v] + 1; 
                predecessor_path[i] = v; 
                queue_enqueue(queue, i);
                if (i == fim) return 1;
            }
        }
        colour[v] = BLACK;
    }
    queue_free(queue);
    return 0;
}