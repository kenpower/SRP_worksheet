# Single Responsibility Worksheet

This worksheet has two parts.

## Part 1 BankAccount

### Understand the problem

Examine the code of the **BankAccount** class (feel free to run to code to see what is output).
There will be some code that you may not understand. That is OK, you do not need to understand all the details, but you do 
need to understand roughly what it is doing.

- What are the class's responsibilities? 
- What **should** be the class's responsibilities?
- What responsibilities should be moved to other classes?

Write the answers to these questions as a comment as the first line(s) in the BankAccount class.

### Fix the problem

Move the "extraneous" responsibilities to new classes. You will need to add some *getter* methods 
to the BankAccount class in order to facilitate this. **For this exercise, put the new classes in to the same file as BankAccount.**

Check that the code still works, commit and push.

## Part 2 Player

### Understand the problem

Examine the code of the *Player* class (feel free to run to code to see what is output, right-click on project and select "Set as startup project").
The Player class has a number of responsibilities.

- What are the class's responsibilities? 
- What should be the class's responsibilities?
- What responsibilities should be moved to other classes?

Write the answers to these questions as a comment as the first line(s) in the Player class.

### Fix the problem

Move the "extraneous" responsibilities to new classes. You will need to add some *getter* methods 
to the Player class in order to facilitate this. **For this exercise, put the new classes in to the same file as Player.**
You will also need to pass the Player object to other functions or classes (in the constructor), depending on how you implement the solution.

Check that the code still works, commit and push.
