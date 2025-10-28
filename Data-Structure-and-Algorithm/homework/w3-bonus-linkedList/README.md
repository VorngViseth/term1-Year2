[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/uTDiEyvp)
# Implementing a Library Book Borrowing System Using Linked Lists

## Senario
You are tasked with designing a simple book borrowing system for a small community library. The library needs to keep track of books borrowed by each member. Since members frequently borrow and return books, a linked list a a great way to manage this data due to its dynamic nature.

## Objective
- Implement a linked list to prepresent the borrowing history of each library member.

## Requirements
1. **Node structure**: Create  a `BookNode` class that stores:
    - `title` (string): Title of the borrowed book.
    - `boorowDate` (string): Date when the book was borrowed.
    - next (pointer to the next `bookNode`).
2. **Member Class**: Create a `Member` class that has:
    - `name` (string): Name of the member.
    - `firstBook` (pointer to the first `BookNode`): Head of the linked list of books.
    - Methods for managing book
3. **Methods**:
    - Borrow Book: Adds a BookNode to the end of the member's list.
    - Return Book: Removes a BookNode based on the title.
    - Display Borrowed Books: Shows all books currently borrowed by the member.

4. **System Class**: Create `LibrarySystem` class with:
    - `addMember`: Adds a new member to the system.
    - `findMember`: Finds and returns a member by name.
    - `displayMemberBooks`: Displays books borrowed by a particular member.

## Example
1. Member John Doe borrows "The Great Gatsby" on "2024-11-10".
2. John borrows "1984" on "2024-11-11".
3. John returns "The Great Gatsby."
4. Display John’s current borrowed books.

## Happy Coding!