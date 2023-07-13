# Financial Analyzer 

## Basic Overview
Have you ever wanted to automate your quantitative stock assessments? **Val** is an AI-powered program that analyses historical data to 
quickly calculate quantitative scores for your favorite stock symbols. **Val** is currently in production for version 1.0, which will provide both an overall score 
and category scores for each stock you enter.

> Version 1.0 of **Val** uses value investing metrics and scoring inspired by the book "Warren Buffett and the Interpretation of Financial Statements" by 
David Clark and Mary Buffett. 

> Version 2.0 of **Val** will use artificial intelligence (AI) and historical data analysis to further improve its ability to analyze companies. 

## Demonstration of Financial Analyzer 


## How to get started
1. Download the latest release [here](https://github.com/Berttwm/Financial-analyzer/releases).
2. To run the program, user must navigate to the "\Financial-analyzer\Release" folder and 
run ```.\main.exe STOCK [PARAMS]```

## Features
- Get all information regarding a specific stock

```
.\main.exe STOCK --all
```

- Get the information of a specified category of a stock
```
.\main.exe STOCK --c
```

- Get the information of a specific metric score of a stock
```
.\main.exe STOCK --i [METRIC]
```

For detailed explanation of each feature and more, refer to the [UserGuide](https://github.com/Berttwm/Financial-analyzer/blob/main/USERGUIDE.md).

## Iterations
The following segment dictates the rough timeline this project will follow. 

## Version 1.0 - Grading Simulator 
### Iteration 1 - MVP (TODO by September 31)
1. [X] Gather few Metrics (3-5 metrics) - **9 Metrics completed**
2. [X] Grading by total score and by categories - **5 categories, every metric individual metric score, completed**
3. [X] Simple CLI - `./program [Stock Ticker]` - **Works with TSLA**

### Iteration 2 - Complete (TODO by October 31)
1. [ ] Full Metrics
2. [ ] CLI Full with options
3. [ ] Partial Testing

### Iteration 3 - Graphical UI (TODO by September 31)
1. [ ] Complete testing
2. [ ] Multi platform integration
3. [ ] Code Cleanup

## Version 2.0 - AI Powered Grading (To be discussed)
