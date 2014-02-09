import java.io.*;

class Interpreter {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        Tokenizer.connectToInputStream(args[0],args[1]);
        Program p = new Program();
        p.parseProgram();
        p.printProgram();
	p.executeProgram();
    }
}
