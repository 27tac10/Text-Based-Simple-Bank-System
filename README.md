# Text-Based-Simple-Bank-System
This documentation outlines a structural plan for your Banking System project. It is designed to be portfolio-ready, suitable for an undergraduate Computer Science profile, and tailored for a C++ environment using VS Code on macOS.
Project Name: C++ Banking Management System (Console Application)

1. Project Overview
A command-line based application that simulates core banking operations. This project demonstrates proficiency in C++ Object-Oriented Programming (OOP), file handling for data persistence, and memory management.
Target Environment:
- OS: macOS (Unix-based file paths)
- IDE/Editor: Visual Studio Code
- Compiler: clang++ or g++ (via C++17 standard)
1. Functional Requirements
The system will allow users (clients) and administrators to perform the following actions:
    - Account Creation: Generate a unique Account ID and capture user details (Name, Initial Balance, Account Type).
    - Transactions:
        - Deposit: Add funds to a specific account.
        - Withdraw: Deduct funds (with validation for insufficient balance).
    - Inquiry:
        - Balance Check: Display current balance for a specific Account ID.
        - Account Details: Show full account holder information.
    - Data Persistence: Automatically save account data to a file (.txt or .csv) upon exit and load it upon startup.
    - Account Modification: Allow updating the account holder's name or closing (deleting) the account.
2. Technical Architecture
Data Structures
Given the need for efficient lookups by Account ID, a std::map or std::unordered_map is recommended over a standard vector or linked list for the main data storage.
    - Class Account:
        - Attributes
            - account_name: string
            - account_number: string
            - balance: double
            - password: string
        - Methods
            - deposit: void
            - withdraw: bool
            - get_balance: double
            - get_account_name: string
            - get_account_number: string
            - get_password: string
    - Class BankManager (or System)
        - Attributes
        - Methods
    - Class Bank_System
        - Attributes
            - accounts[100]: Account class
            - account_count: int
            - current_account_index: int
            - last_account_number: string
        - Methods
            - Add_Account: bool
            - run: void
            - login: void
            - create_account: void
            - verify_account: bool
    -
