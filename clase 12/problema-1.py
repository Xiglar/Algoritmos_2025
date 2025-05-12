import unittest
from collections import defaultdict

# n número total de perfiles. 
# m número total de amistades
def count_double_profiles(n, m, friendships):
    # todo


class TestDoubleProfiles(unittest.TestCase):

    def test_no_friendships(self):
        self.assertEqual(count_double_profiles(5, 0, []), 10)
        # Todos tienen conjunto vacío de amigos → C(5, 2) = 10

    def test_simple_case(self):
        self.assertEqual(count_double_profiles(4, 2, [(1 ,2), (3, 4)]), 0)
        # (1,2) y (3,4) son dobles entre sí

    def test_all_connected_to_one(self):
        friendships = [(1, 2), (1, 3), (1, 4), (1, 5)]
        self.assertEqual(count_double_profiles(5, 4, friendships), 3)
        # Todos los nodos 2-5 tienen como único amigo al nodo 1 → C(4, 2) = 6

    def test_unique_friendsets(self):
        friendships = [(1, 2), (2, 3), (3, 4), (4, 5)]
        self.assertEqual(count_double_profiles(5, 4, friendships), 0)
        # Todos los conjuntos de amigos son distintos

    def test_all_friends(self):
        n = 4
        friendships = [(1, 2), (1, 3), (1, 4),
                       (2, 3), (2, 4), (2,1),
                       (3, 4)]
        self.assertEqual(count_double_profiles(n, len(friendships), friendships), 1)
        # Todos tienen a todos como amigos → C(4, 2) = 6

    def test_large_same_friends(self):
        n = 100
        friendships = [(i, 1) for i in range(2, n+1)]
        expected = (n - 1) * (n - 2) // 2
        self.assertEqual(count_double_profiles(n, n - 1, friendships), expected)


if __name__ == '__main__':
    unittest.main()
