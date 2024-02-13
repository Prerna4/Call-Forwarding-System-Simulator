# Call Forwarding System Simulator

## Description
This repository contains a simple simulator for a call forwarding system implemented in C programming language. The simulator allows forwarding calls to a given number based on predefined rules. It includes source code files, a makefile for easy compilation, and necessary header files.

## Structure

```
project_folder/
│
├── data/
│   └── user.txt
│
├── inc/
│   └── library.h
│
├── src/
│   ├── admin.c
│   ├── cfss.c
│   ├── main.c
│   └── user.c
│
├── Makefile
└── README.md
```

- `data/`: Contains the user data file where forwarding rules are defined.
- `inc/`: Includes the header file(s) necessary for the project.
- `src/`: Contains the source code files.
- `Makefile`: Automates the build process for compiling the project.

## Usage

1. Clone or download the repository to your local machine.
2. Navigate to the project directory.
3. Modify the `user.txt` file in the `data/` directory to define call forwarding rules.
4. Use the Makefile to compile the project:

    ```bash
    make
    ```

5. Execute the compiled program:

    ```bash
    ./executable_name
    ```

## Example user.txt
```plaintext
# user.txt
# Format: <original_number> <forwarding_number><user_name> <user_pin>

9579741221|8605211043|Prerna|1234
```
This example rule forwards calls from the number `9579741221` to `8605211043`.

## Contributing
Contributions are welcome! Please feel free to fork the repository and submit pull requests with improvements or additional features.

