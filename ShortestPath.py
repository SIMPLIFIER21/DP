# Python program to find the shortest path between the given vertices
# Here, Floyd Warshall algorithm is used to find the shortest path

INF = 1000000000

def floyd_warshall(vertex, adjacency_matrix):
	# calculating all pair shortest path
	for k in range(0, vertex):
		for i in range(0, vertex):
			for j in range(0, vertex):
				# consider which one is better, going through vertex k or the previous value
				adjacency_matrix[i][j] = min(adjacency_matrix[i][j], adjacency_matrix[i][k] + adjacency_matrix[k][j])
	# print the graph
	# o/d means the leftmost column is the origin vertex and the topmost row is destination vertex
	print("o/d", end='')
	for i in range(0, vertex):
		print("\t{:d}".format(i+1), end='')
	print();
	for i in range(0, vertex):
		print("{:d}".format(i+1), end='')
		for j in range(0,vertex):
			print("\t{:d}".format(adjacency_matrix[i][j]), end='')
		print();

# Question that can be considered as a driver code
"""
input is given as adjacency matrix,
input represents this undirected graph
 A--1--B
 |    /
 3   /
 |  4
 | /
 C
Tip: set infinite value for each pair of vertex that has no edge

 """
adjacency_matrix = [
					
                    [  0,   1, 3],
					[  1,   0, 4],
					[  3,   4, 0]

					]
floyd_warshall(3, adjacency_matrix);
