# Word-Composition-Problem
## Step to Execute code
**Step 1: Prerequisites**

Ensure you have a C++ development environment set up on your system. You'll need a C++ compiler such as g++.

**Step 2: Clone the Repository**

Clone the repository that contains the C++ code to your local machine using Git. Open a terminal or command prompt and run:
```bash
   git clone https://github.com/anshshori2002/Word-Composition-Problem.git
```
**Step 3: Compile the Program**
Navigate to the directory where the code is located:
```bash
   cd Word-Composition-Problem
```
Compile the C++ program using your C++ compiler. For example, if you have g++ installed:
```bash
   g++ -o Solution_word_Composition.exe Solution_word_Composition.cpp
```
This command compiles the code and creates an executable file named Solution_word_Composition.exe

**Step 4: Execute the Program**
Run the compiled program using the following command:
```bash
   ./Solution_word_Composition.exe
```
The program will prompt you to choose an input file. Enter 1 to process "Input_01.txt" or 2 to process "Input_02.txt."

**Step 5: View Results**

The program will process the selected input file, identify compound words, and display the longest and second-longest compound words found, along with the time taken for processing. If no compound words are found, it will indicate that.

## Overview 
 -  In this problem, we need to find longer words constructed from smaller words present in the file. These are commonly known as compound words, which are formed by concatenating shorter words also found in the same file.
 -  The program reads words from two input files, allowing users to choose between them, and reports the longest and second-longest compound words found in the input.
   
## Approach

The Solution_word_Composition.cpp program is designed to identify compound words within a list of input words. Compound words, in this context, refer to words that can be constructed by combining (concatenating) shorter words that are also present in the same input file. The program follows a structured approach to achieve this:

1. **Input Files**:
   - The program reads input words from two text files, "Input_01.txt" and "Input_02.txt," allowing users to choose between the two input sources.

2. **Data Structure for Efficient Lookups**:
   - To facilitate efficient word lookups and management, the program uses an unordered set, implemented as a hash set. This data structure allows for rapid checking of word existence within the input set.

3. **Compound Word Identification**:
   - The heart of the program is the `isCompoundWord` function, which determines if a word is a compound word. It follows this recursive logic:
     - For each word in the set, the program checks if it can be divided into two parts by splitting it at different positions.
     - If such division results in two or more valid words (i.e., words that are also present in the input set), the word is considered a compound word.
     - The recursive function continues this process for the second part of the divided word, and this is repeated until a compound word is identified or until all possible splits are tested.

4. **Longest and Second-Longest Compound Words**:
   - The program tracks the longest and second-longest compound words found in the input during the process. These words are updated as compound words are identified.

5. **Output Display**:
   - After processing the input, the program reports the results. If no compound words are found, it displays "No Compound Word Present."
   - If compound words are identified, the program displays the longest and second-longest compound words, along with the time taken for processing.

6. **Efficiency and Performance**:
   - The program employs time measurement to determine the processing time for the input files, providing insights into the efficiency of the compound word identification process.

This structured approach ensures that the "Compound Word Identifier" program efficiently identifies compound words within the input data and provides users with clear, informative results.
