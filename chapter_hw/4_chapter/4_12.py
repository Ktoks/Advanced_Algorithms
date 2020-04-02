
infinity = 2147483647

def find_shortest_path(graph):
    distance = []
    previous = []
    
    for v in graph:
        distance[v] = infinity
        previous[v] = None

    total = 0
    for vertice in graph:
        distance[vertice] = 0
        for edge in vertice.edges:
            if edge + distance[vertice] < distance[edge]:
                distance[edge] = distance[vertice] + edge
                previous[edge.destination] = vertice

    for d in distance:
        total += d

    return distance, total


            

def main():
    graph_file = open("graph.txt", 'r')
    graph = graph_file.getGraph()
    least_distance = infinity
    least_path = []
    least_current_distance, least_current_path = find_shortest_path(graph)
    if least_current_distance < least_distance:
        least_distance = least_current_distance
        least_path = least_current_path