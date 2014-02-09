import java.io.*;

class TestTokenizer {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        Tokenizer t = new Tokenizer(args[0]);
        int currentToken = t.getToken();
        while(33 != currentToken && -1 != currentToken) {
            System.out.println(currentToken);
            t.skipToken();
            currentToken = t.getToken();
        }
        if(-1 == currentToken) {
            System.out.println("Invalid token found");
        } else {
            System.out.println(currentToken);
        }
    }
}

