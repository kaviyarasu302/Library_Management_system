📚 Library Management System in C

A Library Management System developed using the C programming language to manage books, track issued books, handle returns, and maintain user authentication. The project uses a menu-driven interface to provide an easy way to perform library operations through the terminal.

📌 Project Overview

The Library Management System is a console-based application designed to simplify basic library operations. It allows users to add new books, update book details, remove books, search for books, and manage book issuing and returning.

The application also provides authentication and file handling to help manage access and preserve library data.

✨ Features

The application provides the following features:

Add New Book: Add new books to the library.
Update Book Details: Modify the details of existing books.
Remove Book: Remove books from the library records.
Search Book: Search for books in the library.
View All Books: Display the available book records.
Issue Book: Issue books to registered users.
Return Book: Process the return of issued books.
List Issued Books: Display the books that have been issued.
Save Data: Save library and user data to files.
User Authentication: Authenticate users before accessing the system.
Change Username or Password: Update authentication credentials.
🛠️ Technologies Used
Programming Language: C
Data Structures: Linked Lists
File Handling: C file I/O operations
User Interface: Console-based menu
Development Environment: GCC compiler and a terminal
📂 Project Structure

The project is organized around the main program, header files, supporting C source files, and data files.

text
Library_Management_system/
│
├── Library_management_system/
│   ├── header.h
│   ├── main.c
│   ├── Other source files (.c)
│   └── Data files
│
└── README.md


Note: This is an illustrative structure. The actual filenames and data files depend on the contents of the repository.

⚙️ Prerequisites

Before running the project, make sure you have:

A C compiler, such as GCC.
A terminal or command-line interface.
Git installed if you want to clone the repository.
🚀 Installation and Execution
1. Clone the Repository

Clone the project from GitHub:

bash
git clone https://github.com/kaviyarasu302/Library_Management_system.git

2. Navigate to the Project Directory
bash
cd Library_Management_system


If the source files are inside the Library_management_system subdirectory, navigate into it:

bash
cd Library_management_system

3. Compile the Program

If all the C source files are in the current directory, compile them using GCC:

bash
gcc *.c -o library_management


If the project contains source files in other directories, adjust the compilation command accordingly.

4. Run the Application

On Linux:

bash
./library_management


On Windows, if compiled using GCC:

bash
library_management.exe


Note: The program uses system("clear") in the main function, which is intended for Unix-like terminals. Windows users may need to replace it with system("cls").

📋 Application Menu

When the program starts, users are presented with a menu similar to the following:

text
+---------------------------------------------------+
|             Book Management Menu                  |
|---------------------------------------------------|
|  1. Add New Book                                  |
|  2. Update Book Details                           |
|  3. Remove Book                                   |
|  4. Search Book                                   |
|  5. View All Books                                |
|  6. Issue Book                                    |
|  7. Return Book                                   |
|  8. List Issued Books                             |
|  9. Save                                          |
| 10. Exit                                          |
| 11. User name or password change                  |
+---------------------------------------------------+


Enter the corresponding menu number to perform an operation.

🧠 Concepts Implemented

This project demonstrates several fundamental concepts of C programming:

Structures: Organizing book and user information.
Pointers: Accessing and manipulating dynamically linked records.
Linked Lists: Managing collections of books and users.
Functions: Separating operations into reusable modules.
File Handling: Loading and saving application data.
Conditional Statements: Implementing menu selection and decision-making.
Loops: Repeatedly displaying the menu until the user exits.
Authentication: Checking user credentials before granting access.
💾 Data Management

The application uses file handling to load and save library information.

Existing records can be loaded when the application starts.
Changes to book and user records can be saved using the Save option.
Saved records can be reused in subsequent sessions, depending on the file-handling implementation.

Important: Save your changes before exiting if the application does not automatically save them.

🎯 Project Objectives

The main objectives of this project are to:

Simplify basic library management operations.
Maintain book and user records.
Track issued and returned books.
Practice linked-list operations and pointer manipulation.
Understand file handling in C.
Implement a menu-driven console application.
🔮 Future Enhancements

The project could be extended with the following features:

Fine calculation for overdue books.
Book availability and quantity tracking.
Improved input validation and error handling.
Separate administrator and librarian accounts.
Book issue dates and return deadlines.
More secure password storage.
Improved search options by title, author, or book ID.
A graphical user interface.
A database for storing and managing library records.
🎓 Learning Outcomes

Working on this project helps develop practical knowledge of C programming, data structures, file handling, modular programming, and basic record management.

It is suitable as a learning project for students exploring data structures and system development using C.

👨‍💻 Author

Kaviyarasu

GitHub Repository:
https://github.com/kaviyarasu302/Library_Management_system

📄 License

No license has been specified here. If you intend to make the project available for reuse, consider adding an appropriate open-source license to the repository.
