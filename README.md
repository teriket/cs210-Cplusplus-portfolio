# cs210-Cplusplus-portfolio
project commit for cs210

    Summarize the project and what problem it was solving.
This project was for a grocery store who wanted to analyze the quantities of produce they were purchasing.  The name of the product is added to a file each time the grocery store purchases the produce.  The program then reads through the file to find the frequencies each product is purchased, and display the relevant information for each product purchased.

    What did you do particularly well?
My code was succinct, well documented, and has good structure.

    Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
Extending the code would require modification of existing code.  Better code would be open to extension, which could be done using interfaces.  It could also be argued that reading data from the file and printing data should be abstracted out to two different objects with different responsibilities.

    Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
The hardest part of this project was probably the unordered_map, which has some different syntax and method calls than other languages.  I used cppreference.com to get the function calls for the unordered_map correct and stackoverflow.com to look up how to iterate through an unordered_map in c++.

    What skills from this project will be particularly transferable to other projects or course work?
I could use a few of the skills from this project in future work.  Memory management using unique_ptr's is an important tool.  Writing highly modular code is another tool.  Segregation of duties also helps code be more maintainable in the long run.

    How did you make this program maintainable, readable, and adaptable?
The program is highly modularized with short functions, which makes it more maintainable and readable.  Each class also has a clear responsibility, which makes it easier to maintain and debug code.  Method and variable names also self-document their functions.  In-line comments also helps clarify segments of code.  The adaptability of this code could be improved using interfaces and inheritance to allow for reading different file types in the future, different printing formats, more menu options, etc..
