import unittest
from collections import defaultdict

# n número total de perfiles. 
# m número total de amistades
def count_double_profiles(n, m, friendships):
    friendships_mapped_by_friend = {}

    for a, b in friendships:
        friendships_mapped_by_friend.setdefault(a, []).append(b)
        friendships_mapped_by_friend.setdefault(b, []).append(a)
        

    friendship_sets_count = {}

    for friends_list in friendships_mapped_by_friend.values():
        friend_set = frozenset(friends_list)
        friendship_sets_count[friend_set] = friendship_sets_count.get(friend_set, 0) + 1

    double_profiles = 0
    for count in friendship_sets_count.values():
        if count > 1:
            double_profiles += count - 1  

    return double_profiles


class TestDoubleProfiles(unittest.TestCase):

    def test_no_friendships(self):
        self.assertEqual(count_double_profiles(5, 0, []), 0)

    def test_simple_case(self):
        self.assertEqual(count_double_profiles(4, 2, [(1 ,2), (3, 4)]), 0)

    def test_all_connected_to_one(self):
        friendships = [(1, 2), (1, 3), (1, 4), (1, 5)]
        self.assertEqual(count_double_profiles(5, 4, friendships), 3)

    def test_unique_friendsets(self):
        friendships = [(1, 2), (2, 3), (3, 4), (4, 5)]
        self.assertEqual(count_double_profiles(5, 4, friendships), 0)

    def test_all_friends(self):
        n = 4
        friendships = [(1, 2), (1, 3), (1, 4),
                       (2, 3), (2, 4),
                       (3, 4)]
        self.assertEqual(count_double_profiles(n, len(friendships), friendships), 0)


if __name__ == '__main__':
    unittest.main()
