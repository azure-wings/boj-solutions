import sys
from typing import Dict, Tuple

def input_function() -> Dict[str, Tuple[str, str]]:
    num_nodes: int = int(sys.stdin.readline())
    tree: Dict[str, Tuple[str, str]] = dict()

    for _ in range(num_nodes):
        node: str; left: str; right: str
        node, left, right = sys.stdin.readline().split()
        tree[node] = (left, right)

    return tree

def preorder(tree: Dict[str, Tuple[str, str]]) -> str:
    curr_node: str = "A"

    def _preorder(node: str) -> str:
        if node != ".":
            return node + _preorder(tree[node][0]) + _preorder(tree[node][1])
        else:
            return ""

    return _preorder(curr_node)

def inorder(tree: Dict[str, Tuple[str, str]]) -> str:
    curr_node: str = "A"

    def _inorder(node: str) -> str:
        if node != ".":
            return _inorder(tree[node][0]) + node + _inorder(tree[node][1])
        else:
            return ""

    return _inorder(curr_node)

def postorder(tree: Dict[str, Tuple[str, str]]) -> str:
    curr_node: str = "A"

    def _postorder(node: str) -> str:
        if node != ".":
            return _postorder(tree[node][0]) + _postorder(tree[node][1]) + node
        else:
            return ""

    return _postorder(curr_node)

if __name__ == "__main__":
    tree: Dict[str, Tuple[str, str]] = input_function()

    print(preorder(tree))
    print(inorder(tree))
    print(postorder(tree))