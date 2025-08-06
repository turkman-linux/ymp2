# Compilation Projects Using libymp

This document provides detailed instructions on how to compile source code that utilizes the **libymp** library. It covers the necessary steps, compiler flags, and linking requirements to ensure successful compilation.

## Prerequisites
Before compiling your source code with **libymp**, ensure that you have:
- The **libymp** library installed on your system (refer to the building documentation for installation steps).
- A compatible C compiler (e.g., **GCC**, **Clang**).
- The development headers for **libymp** available in your include path.

## Compilation Steps
Follow these steps to compile your source code that uses the **libymp** library:

1. **Include the libymp Header**:  
   At the beginning of your source file, include the **libymp** header:
   ```c
   #include <ymp.h>
   ```

2. **Compile the Source Code**:  
   Use the following command to compile your source code. Replace `your_source_file.c` with the name of your source file:
   ```bash
   gcc -o your_program your_source_file.c $(pkg-config --cflags --libs libymp)
   ```
   Here, `$(pkg-config --cflags --libs libymp)` automatically retrieves the necessary compiler flags and linking options for the **libymp** library.

3. **Run the Compiled Program**:  
   After successful compilation, you can run your program:
   ```bash
   ./your_program
   ```

## Example Compilation
Here’s a complete example of compiling a simple program that uses **libymp**:

- **Source Code (example.c)**:
   ```c
   #include <stdio.h>
   #include <ymp.h>

   int main() {
       Ymp *ymp = ymp_new();
       ymp_add(ymp, "print", "Hello from libymp!\n");
       return ymp_run(ymp);
   }
   ```

- **Compilation Command**:
   ```bash
   gcc -o example example.c $(pkg-config --cflags --libs libymp)
   ```

- **Running the Program**:
   ```bash
   ./example
   ```

## Troubleshooting Compilation Issues
If you encounter issues during compilation, consider the following:
- Ensure that the **libymp** library is correctly installed and accessible.
- Check for any missing header files or libraries.
- Verify that you are using the correct compiler flags.
- Review any error messages for clues about what went wrong.

## Conclusion
Compiling source code with the **libymp** library is straightforward if you follow the outlined steps. By ensuring that the library is properly installed and using the correct compiler flags, you can successfully build applications that leverage the functionalities provided by **libymp**.
