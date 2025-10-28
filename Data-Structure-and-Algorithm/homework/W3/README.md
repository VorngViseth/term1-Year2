[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/gbehsFOI)
# Check if Numbers Are Ascending
A sentence is a list of tokens separated by a single space with no leading or trailing spaces. Every token is either a positive number consisting of digits 0-9 with no leading zeros, or a word consisting of lowercase English letters.

- For example, `"a puppy has 2 eyes 4 legs"` is a sentence with 7 tokens: `"2"` and `"4"` are numbers and the other tokens such as `"puppy"` are words.

Given a string `s` respresenting a sentence, you need to check if all the numbers in `s` are strictly increasing from left to right.

Return `true` if so, or `false` otherwise.

### Example:
- **Input:**  `s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles"`

- **Output:** `true`
- **Explaination:** The numbers in s are: `1, 3, 4, 6, 12`. They are strictly increasing from left to right: `1 < 3 < 4 < 6 < 12`.

### Helper Function:
- To check if a `char` is digit (number) use: `std::isdigit(char_)` return `true` if so, `false` otherwise.

- To convert a string number to `int` type use: `std::stoi(std::string_)`

## Task:
1. Complete the `Solution` in [utils/Exercise.cpp](utils/Exercise.hpp) by following the instructions above.

2. Implement your solution in [main.cpp](main.cpp) to see if your solution is correct.

3. Commit & submit your code before the `deadline`!

***NOTE***: You can submit as many times as you wish before the deadline.

## Happy Coding!