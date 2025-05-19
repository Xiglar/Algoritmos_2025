import unittest
from heapq import heappush, heappop

def min_transfers(debt):




import unittest

class TestSimplifyDebtsGreedy(unittest.TestCase):
    def test_case_1(self):
        debt = [
            [0, 10, 0],
            [0, 0, 5],
            [7, 0, 0]
        ]
        result = min_transfers(debt)
        self.assertEqual(len(result), 2)
        self.assertEqual(result, [(0,1,3), (2,1,2)])


    def test_case_balanced(self):
        debt = [
            [0, 5],
            [5, 0]
        ]
        result = min_transfers(debt)
        self.assertEqual(len(result), 0)
        self.assertEqual(result, [])

    def test_no_debt(self):
        debt = [
            [0, 0],
            [0, 0]
        ]
        result = min_transfers(debt)
        self.assertEqual(result, [])

    def test_chain(self):
        debt = [
            [0, 5, 0],
            [0, 0, 5],
            [0, 0, 0]
        ]
        result = min_transfers(debt)
        self.assertEqual(len(result), 1)
        self.assertEqual(result, [(0,2,5)])


if __name__ == '__main__':
    unittest.main()
