
def moddedexplore(vertice):
    # inside explore, we would add each vertice's weight to cycle if it reaches vertL
    pass

g = [[1,2,3], [5], [4], [7], [], [6], [9], [0], [3]]



def smallest(g):
    smallest_size = 2000000
    visited = [False] * g.size()
    for vertL in g:
        for vert in vertL:
            cycle = vert.weight
            cycle += moddedexplore(vert, vertL)
            if visited[vertL.index()] and cycle < smallest_size:
                smallest_size = cycle
            visited = [False] * g.size()

