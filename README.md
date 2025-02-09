# COMPILER-DESIGN-BASICS
COMPANY : CODTECH IT SOLUTIONS

NAME : SHREYAA

INTERN ID : CT6WMCN

DOMAIN : C PROGRAMMING

BATCH DURATION : FEBRUARY 5TH 2025 TO MARCH 20TH 2025

MENTOR NAME : NEELA SANTHOSH
### **Lexical Analyzer in C with File Handling**  

#### **Description of the Program:**  
This C program demonstrates **lexical analysis** by reading a file, identifying different tokens like **keywords, identifiers, numbers, and operators**, and displaying them. The program also allows the user to **write content** to a file before analyzing it.  

#### **How It Works:**  
1. The user enters a filename.  
2. The program allows the user to enter content into the file.  
3. After writing, the file is opened for reading, and **lexical analysis** is performed.  
4. The program identifies **keywords, identifiers, numbers, and operators** and displays them.  

---

### **Libraries Used in the Program:**  
```c
#include <stdio.h>   // Standard Input-Output Library for file operations
#include <stdlib.h>  // Standard Library for memory management and program control
#include <string.h>  // String handling functions (strcmp, strcspn)
#include <ctype.h>   // Character type functions (isalnum, isdigit, isalpha, ispunct, etc.)
```

---

### **Key Features of the Program:**  
✅ **Lexical Analysis:** Identifies keywords, identifiers, numbers, and operators.  
✅ **File Handling:** Reads and writes text files using `fopen()`, `fclose()`, and `fgetc()`.  
✅ **Interactive Input:** Users can enter content into the file before performing analysis.  
✅ **Error Handling:** Checks if the file exists before reading.  
✅ **Efficient Processing:** Uses functions like `ungetc()` to handle input parsing properly.  

---

### **Token Classification in Lexical Analysis:**  
- **Keywords:** Recognizes predefined C language keywords such as `int`, `float`, `if`, `else`, `while`, and `return`.  
- **Identifiers:** Variables and function names that start with a letter and contain only alphanumeric characters.  
- **Numbers:** Numeric values detected using `isdigit()`.  
- **Operators:** Recognizes operators such as `+`, `-`, `*`, `/`, `=`, `>`, `<`, `==`.  

---

### **Functions Used in the Program:**  

#### **1. `is_keyword(char* str)`**  
- Checks if the given string is a keyword by comparing it with a list of predefined keywords.

#### **2. `is_operator(char* str)`**  
- Checks if the given character sequence matches a known operator.

#### **3. `is_identifier(char* str)`**  
- Determines if a string follows the rules of an identifier (should not start with a digit and must be alphanumeric).

#### **4. `lexical_analysis(FILE* file)`**  
- Reads the file **character by character** and classifies the tokens into keywords, identifiers, numbers, and operators.

#### **5. `write_to_file(char* filename)`**  
- Allows the user to enter content into a file.
- Stops taking input when the user types `"exit"`.  

---

### **Possible Enhancements:**  
🚀 **Support for Multi-character Operators:** Extend recognition to include `>=`, `<=`, `!=`, and `&&`.  
🚀 **String and Character Literals:** Detect and classify string literals (inside `""`) and character literals (inside `''`).  
🚀 **Comment Handling:** Ignore comments (`// single-line` and `/* multi-line */`).  
🚀 **Symbol Table Implementation:** Store identifiers and keywords in a structured symbol table.  

---

### **Conclusion:**  
This program provides a **simple yet effective** way to perform **lexical analysis** on a given file. It demonstrates **basic file handling, input parsing, and token classification**. Understanding this program is **crucial for building a compiler or interpreter**, making it a foundational topic in **compiler design** and **systems programming**.
