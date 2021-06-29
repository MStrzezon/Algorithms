cmake_minimum_required(VERSION 3.19)
project(Classes C)

set(CMAKE_C_STANDARD 99)

add_executable(Classes main.c Merge_Sort/mergesort.c Heap_Sort/heapsort.c Quicksort/quicksort.c
        Bucket_Sort/bucketsort.c Counting_Sort/countingsort.c Insertion_Sort/insertionsort.c Bubble_Sort/bubblesort.c
        Queue/queue.c Priority_Queue/priority_queue.c Binary_Search/binarysearch.c Trees/binarytree.c
        Trees/showtree.c Trees/avl_tree.c Graphs/graph_search.c Graphs/mst_prim.c Graphs/shortest_path.c
        Graphs/queue_edges.c)