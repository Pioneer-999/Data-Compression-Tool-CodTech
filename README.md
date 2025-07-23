# Data-Compression-Tool-CodTech

*COMPANY*: CODTECH IT SOLUTIONS

*NAME*: SHASHWAT SHUBHAM

*INTERN ID*: CT04DG3340

*DOMAIN*: C LANGUAGE

*DURATION*: 4 WEEKS

*MENTOR*: NEELA SANTOSH


*About File Handling Program in C*

#Overview
Run-Length Encoding is a simple and effective algorithm for compressing sequences of repeated characters. It replaces consecutive occurrences of the same character with a single character followed by its count.

For example:

Original: aaabbbcccc

Compressed: a3b3c4

##This program allows the user to:
Compress the content of a file using RLE.
Decompress an RLE-compressed file back to its original content.

##How It Works
Compression Logic
Read the input text from a file character by character.
Count consecutive repeated characters.
Replace them with the character followed by the count.
Store the compressed output in a new file.

##Decompression Logic
Read the compressed file.
Extract characters and their respective counts.
Reconstruct the original string by repeating characters as per their count.
Write the decompressed output to a file.

##Program Flow
Display a menu to the user:
1. Compress a file
2. Decompress a file
3. Exit

##Take the file name as input.
Perform the selected operation and show success messages.

##Concepts & Tools Used
C File Handling (fopen(), fgetc(), fputc(), fprintf())
Run-Length Encoding algorithm
Command-line input/output
Character manipulation and buffering
Error handling for file operations

##Learning Outcomes
Gained hands-on experience with lossless compression algorithms.
Practiced string processing, buffering, and loop design in C.
Improved understanding of file I/O, error-checking, and user-driven interfaces.
Learned how to structure a modular C program with multiple operations.
