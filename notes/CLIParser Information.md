# CLI Parser Information 
Information on how to use the CLI Parser

General: To run the program, user must navigate to the "\Financial-analyzer\Release" folder and run '.\main.exe STOCK [PARAMS]'
Things to take note: 
- Words in uppercase e.g STOCK/PARAMS means that it is a user input
- Words in [] means that this parameter can be omitted


## To get all the information regarding a specific stock
Input: 'STOCK'
Expected Output: 
- Output current score of stock
- Output all category scores of stock
- Output maximum category scores
- Output all metric performances 
- Output all metric scores of stock
- Output maximum metric scores


## To get the information of a specified category of a stock
Input: 'STOCK -i' OR 'STOCK -c'
Expected Output:
If input == 'STOCK -c'
- Output all category scores of stock

If input == 'STOCK -i'
- Output all metric scores of stock


## To get te information of a specific metric score of a stock
Input: 'STOCK -i [METRIC]' OR 'STOCK -c [CATEGORY]'
Expected Output:
If input == 'STOCK -c [CATEGORY]'
- Output the specified category score of the stock

If input == 'STOCK -i [METRIC]'
- Output the specified metric score of the stock


## To get help or more information
Input: '--help'
Expected Output:
- Program will output help instructions