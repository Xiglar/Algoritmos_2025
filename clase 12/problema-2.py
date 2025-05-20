from collections import defaultdict
import unittest

def max_palindrome_beauty(k, n, presents):
    palindromo = {}
    for pal,beauty in presents:
        if pal not in palindromo.keys():
            palindromo[pal] = beauty
        else:
            if palindromo[pal] < beauty:
                palindromo[pal] = beauty
    palindromocomplementario = {}
    palindromos = {}
    for clave, valor in palindromo.items():
        for pal,bel in palindromocomplementario.items():
            if clave not in palindromocomplementario.keys() and palindromocomplementario[pal] == clave[::-1]:
                palindromocomplementario[clave] = valor
        if clave == clave[::-1]:
            palindromos[clave] = valor
    belleza_max = 0
    for clave, valor in palindromocomplementario.items():
        belleza_max += valor
    for clave, valor in palindromos.items():
        belleza_max += valor
    return belleza_max


class TestMaxPalindromeBeauty(unittest.TestCase):
    def test_case_1(self):
        presents = [("abc", 3), ("cba", 4), ("aba", 2), ("def", -5)]
        self.assertEqual(max_palindrome_beauty(4, 3, presents), 9)  # 7 + 2 = 9

    def test_case_2(self):
        presents = [("abc", -3), ("cba", -2), ("aba", 1)]
        self.assertEqual(max_palindrome_beauty(3, 3, presents), 1)  # Solo el palíndromo "aba"

    def test_case_3(self):
        presents = [("abc", 2), ("cba", 3), ("abd", -2), ("def", -1)]
        self.assertEqual(max_palindrome_beauty(4, 3, presents), 5)  # 2 + 3 = 5

    def test_case_4(self):
        presents = [("madam", 3), ("madam", 5), ("hello", -10)]
        self.assertEqual(max_palindrome_beauty(3, 5, presents), 8)  # "madam" tiene belleza 5

    def test_case_5(self):
        presents = [("a", 10), ("a", -3)]
        self.assertEqual(max_palindrome_beauty(2, 1, presents), 10)  # La cadena "a" con belleza 10

if __name__ == '__main__':
    unittest.main()