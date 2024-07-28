Purpose:
The program is a simple command-line application for managing a yogurt shop. It allows users to display a menu, serve customers, and check stock levels for flavors, fruits, and toppings. It also handles customer orders, including saving and loading stock information from files.

Features:

Menu Display:
The displayMenu() function shows available yogurt flavors, fruits, and toppings.

Serving Customers:
The serveCustomer() function handles customer orders by:
Asking for the customer's name (validates that the name contains only letters).
Asking for the phone number (validates that it contains exactly 10 digits).
Selecting a yogurt flavor, fruit, and topping.
Calculating and displaying the total cost of the order.
Updating stock levels and saving order details to a file.

Checking Stock Levels:
The checkFlavourStock(), checkFruitStock(), and checkToppingsStock() functions display current stock levels for yogurt flavors, fruits, and toppings, respectively.

File Handling:
Reading Stock Information:
readStockFromFile() reads initial stock levels from stock.txt when the program starts.
Writing Orders:
writeOrderToFile() appends customer order details to orders.txt.

Input Validation:
Validates that the name contains only letters.
Ensures the phone number is exactly 10 digits.
Checks for valid selections and quantities for yogurt flavors, fruits, and toppings.

Utility Functions:
clearInputBuffer() clears the input buffer to handle invalid input.
isAlphaString() checks if a string contains only letters.
isDigitString() checks if a string contains only digits and is of a specific length.

Execution Flow:
The program starts by loading stock data from a file.
It displays a menu and continuously prompts the user for actions.
Depending on the user's choice, it performs the corresponding action (e.g., display menu, serve a customer, check stock).
On exiting, it saves the updated stock data to the file.

Files Used:
stock.txt: Contains stock levels for flavors, fruits, and toppings.
orders.txt: Stores details of customer orders.
The program ensures that only valid inputs are accepted and maintains a record of stock and customer orders through file operations.