n, m = map(int, input().split())


def postDfs(postOrder, graph, minChildren):
    counter = 0
    stack = [1]
    tempStack = []

    while stack:
        node = stack.pop()
        tempStack.append(node)

        if node in graph:
            for child in graph[node]:
                stack.append(child)

    # Postorder processing
    while tempStack:
        node = tempStack.pop()
        postOrder[node] = counter
        counter += 1

        if node in graph:
            minChildren[node] = minChildren[graph[node][0]]
        else:
            minChildren[node] = postOrder[node]


def main():
    postOrder = {}
    graph = {}
    minChildren = {}
    block = -1

    # Construct the graph
    for _ in range(n - 1):
        u, v = map(int, input().split())
        if u in graph:
            graph[u].append(v)
        else:
            graph[u] = [v]

    # Sort children before traversal
    for u in graph:
        graph[u].sort()

    postDfs(postOrder, graph, minChildren)

    cnt = 0
    for _ in range(m):
        node = int(input())
        if postOrder[node] < block:
            break

        # in case minChild has been blocked off
        block = max(minChildren[node], block)
        cnt += 1

    return cnt


print(main())
