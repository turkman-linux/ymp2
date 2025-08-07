// Main entry point
public void main() {
    // Initialize Ymp structure
    var ymp = Ymp.init();

    // Add the operation to Ymp
    string[] args = {"Hello World"};
    ymp.add("print", (void*)args);

    // Run the operation
    int result = ymp.run();
    if (result != 0) {
        print("Error running HelloWorld operation.\n");
    }
}

