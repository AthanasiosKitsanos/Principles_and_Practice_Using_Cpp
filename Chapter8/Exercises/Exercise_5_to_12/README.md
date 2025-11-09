**When I started doing `exercise 5`, I started adding stuff on my own,**  
**whithout realizing I was doing the next exercise upon the next**  
**and that is why this folder contains code from `exercise 5` to `exercise 12`**

### Commands 
- **`Main Menu`**
    - `library` -> goes to the library menu
    - `patrons` -> goes to the patrons menu
    - `transactions` -> goes to transaction menu

- **`While in Library`**
    - `find 'title'` -> finds the book with the title given if it exists
    - `remove 'title'` -> removes the book with the title given if it exists
    - `add` -> starts a step by step proccess to add a new book to the library
    - `list` -> prints a list of all books the library has
    - `back` -> goes back to the `Main Menu`
    - `clear` -> clears the console

- **`While in Patrons`**
    - `find 'name'` -> finds the patron with the name given if he/she exists
    - `remove 'name'` -> removes the patron with the name given if he/she exists
    - `add` -> starts a step by step proccess to add a new book to the library
    - `list` -> prints a list of all patrons
    - `back` -> goes back to the `Main Menu`
    - `clear` -> clears the console

- **`While in Transactions`**
    - `find 'name'` -> finds the patron and the books he/she rented and the date of when each book was rented
    - `checkout 'title'` -> checks out the book and then it asks to who the book is rented while adding a fee
    - `checkin 'name'` -> finds the patron how is checking in and then asks which title he/she returns, while removeing the fee
    - `list` -> prints a list of all rented books
    - `back` -> goes back to the `Main Menu`
    - `clear` -> clears the console

## Note:
The commands that say `name` or `title`, you must write them as they are exactly, e.g if we have a title like The Hobbit  
you must write `find The Hobbit`.  
The same goes for the `name`. If the `name` is Jason, write `find Jason`.