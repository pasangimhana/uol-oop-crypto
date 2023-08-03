Objective:

### Step 01
The goal is to clean up the main CPP file and organize the code better.
Encapsulate menu-related functions into a separate class to make the main function lean and easier to read.

### Step 02 - Creating the MerkelMain Class:

Two new files are created: "MerkelMain.h" (header) and "MerkelMain.cpp" (implementation).
In "MerkelMain.h," a class named "MerkelMain" is defined, and all the menu-related function names are listed as function prototypes (e.g., void printMenu();).
Implementing the Functions:

### Step 03 - Implementing the Functions:
In "MerkelMain.cpp," the function bodies for each menu-related function are defined using the class name as a prefix (e.g., void MerkelMain::printMenu() { /* implementation */ }).

### Step 04 - Main Function:
The main function in the original CPP file is modified to be simpler.
It includes the "MerkelMain.h" header to access the class and its functions.
An instance of the "MerkelMain" class is created (e.g., MerkelMain app;).
Initialization (Optional):

### Step 05 - Initialization (Optional):
The presenter suggests moving the logic to start the application into an explicit function, such as an "init" function within the "MerkelMain" class. However, this is optional and can be done differently.
Running the Application:

The main function can then call functions from the "MerkelMain" class to perform menu operations (e.g., app.printMenu();).
When the program runs, it prints the menu (as shown in the video).