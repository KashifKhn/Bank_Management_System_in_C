# Bank Management System

This is a simple bank management system implemented in C.
This code implements a basic console-based banking application with functionalities for user authentication, account management, and an admin panel for administrative tasks. It utilizes file handling to store user and admin data and offers features like balance management, account creation, and admin credential updates.

## Description

The Bank Management System allows users to perform various operations related to managing bank accounts. It provides the following features:

- Store a formatted text file of accounts for printing.
- Add a new account.
- Update an existing account.
- Delete an account.
- View all account records.

## Prerequisites

To compile and run this code, you need to have a C compiler installed on your system. The code is written in C and uses standard C libraries.

## Getting Started

1. Clone the repository or download the source code files.
2. Open a terminal or command prompt and navigate to the project directory.
3. Compile the code using a C compiler. For example, using GCC:
4. Run the executable:

## Usage

Upon running the program, you will be presented with a welcome screen and a menu. Follow the on-screen instructions to perform different operations.

### User Panel:

To access the user panel, choose option 1 and enter the account number and pin code.

- To deposit money, choose option 1 and enter the account number and amount to deposit.
- To withdraw money, choose option 2 and enter the account number and amount to withdraw.
- To update an account, choose option 3 and follow the prompts to update the first name, last name, or pin code.
- To delete an account, choose option 4 and enter the account number.
- To go back to the main menu, choose option 9.
- To exit the program, choose option 0.

### Admin Panel:

To access the admin panel, choose option 2 and enter the admin username and password.

- To update admin credentials, choose option 1 and enter the new username and password.
- To view all admin credentials, choose option 2.
- To add a new user account, choose option 3 and follow the prompts to enter account details.
- To delete a user account, choose option 4 and enter the account number.
- To view all user account records, choose option 5.
- To upload user details for printing, choose option 6.
- To go back to the main menu, choose option 9.
- To exit the program, choose option 0.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

## License

This project is licensed under the MIT License.
