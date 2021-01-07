// Name:      Breadth-First Search implemented in C
// Topics:    breadth-first search (BFS); adjacency matrix; recursion
// Testing:
//   in:      4
//            0 1 1 0
//            0 0 0 0
//            0 1 0 0
//            0 1 0 0             
//            0
//   out:     1 2

# include<stdio.h>

int a[20][20],    // 2-dimensional array
    q[20],        // queue
    visited[20],  // store
    n,            // number of elements in graph
    i,            // index
    j,            // index
    f=0,          // front of queue, initialized to first position
    r=-1;         // rear of queue, initialized to last position

// define reachable nodes using BFS
void bfs(int v)
{
  // enqueue
  for (i=0; i<n; i++)
  {
    // starting from the 0th element, if element is non-zero (non-visited), push into `q`
    if (a[v][i] && !visited[i]) {
      q[++r]=i;
    }
  }
  
  // dequeue if queue is not empty
  if (f<=r) {
    visited[q[f]] = 1;
    // recursive
    bfs(q[++f]);
  }
}

int main()
{
  /** @global */
  int v;

  // request number of vertices
  printf("enter the number of vertices:");

  // store number of vertices
  scanf("%d", &n);

  // set status of all elements in queue and visited arrays = 0
  // 0 = unprocessed; 1 = processed
  for(i=0; i<n; i++)
  {
    q[i] = 0;
    visited[i] = 0;
  }

  printf("enter the adjacency matrix:");

  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) {
      // store each element of input in 2D array
      scanf("%d", &a[i][j]);
    }
  }

  // request starting vertex to find all reachable nodes from that vertex
  // with a starting vertex only, you can find all remaining nodes
  printf("enter the starting vertex:");

  // store vertex value
  scanf("%d", &v);

  bfs(v);

  printf("The reachable nodes are:");

  for(i=0; i<n; i++) {
    // if visited[i] != 0, the node is processed and is reachable from given vertex
    if(visited[i]) {
      printf("%d\t",i);
    }
  }

  return 0;
}