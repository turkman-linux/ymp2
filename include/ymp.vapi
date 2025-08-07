[CCode (cheader_filename = "core/ymp.h")]
public class Ymp {
    // Initializes a Ymp structure.
    public static Ymp init();

    // Adds a new entry to the Ymp structure.
    public void add(string name, void* args);

    // Executes operations on items in the Ymp queue.
    public int run();
}

