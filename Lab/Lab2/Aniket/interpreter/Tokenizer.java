import java.io.*;
import java.util.regex.*;

//Regex patterns used by the tokenizer
class TokenPattern {
    static Pattern WHITESPACE = Pattern.compile("[\\s]+");
    static Pattern NUMBER = Pattern.compile("[\\d]+");
    static Pattern ID = Pattern.compile("[A-Z]+[0-9]*");
}

public class Tokenizer {
    //fr1, reader1 --> Core program file, fr2,reader2 --> input data file
    private FileReader fr1,fr2;
    private BufferedReader reader1,reader2; 
    private String[] tokensInLine;
    private String[] inputsInLine;
    private int index1, index2;
    private static Tokenizer inst = null; //for singleton pattern
    
    //private constructor for singleton pattern
    private Tokenizer(String progFile, String inputFile) throws FileNotFoundException, IOException {
        index1 = index2 = 0;
        fr1 = new FileReader(progFile);
        reader1 = new BufferedReader(fr1);
        skipToken();
        fr2 = new FileReader(inputFile);
        reader2 = new BufferedReader(fr2);
    }

    public static Tokenizer instance() {
        assert inst != null : "Tokenizer not connected to core program/input file";
        return inst;
    }

    public static void connectToInputStream(String progFile, String inputFile) throws FileNotFoundException, IOException {
        inst = new Tokenizer(progFile,inputFile);
    }   

    public int getToken() {
 
        if(tokensInLine[index1].equals("program")) {return 1;}
        if(tokensInLine[index1].equals("begin")) {return 2;}
        if(tokensInLine[index1].equals("end")) {return 3;}
	if(tokensInLine[index1].equals("int")) {return 4;}
	if(tokensInLine[index1].equals("if")) {return 5;}
        if(tokensInLine[index1].equals("then")) {return 6;}
        if(tokensInLine[index1].equals("else")) {return 7;}
        if(tokensInLine[index1].equals("while")) {return 8;}
        if(tokensInLine[index1].equals("loop")) {return 9;}
        if(tokensInLine[index1].equals("read")) {return 10;}
        if(tokensInLine[index1].equals("write")) {return 11;}

	if(tokensInLine[index1].equals("EOF")) {return 33;}

        if(tokensInLine[index1].equals(";")) {return 12;}
        if(tokensInLine[index1].equals(",")) {return 13;}
        if(tokensInLine[index1].equals("=")) {return 14;}
        if(tokensInLine[index1].equals("!")) {return 15;}
        if(tokensInLine[index1].equals("[")) {return 16;}
        if(tokensInLine[index1].equals("]")) {return 17;}
        if(tokensInLine[index1].equals("&&")) {return 18;}
        if(tokensInLine[index1].equals("||")) {return 19;}
        if(tokensInLine[index1].equals("(")) {return 20;}
        if(tokensInLine[index1].equals(")")) {return 21;}
        if(tokensInLine[index1].equals("+")) {return 22;}
        if(tokensInLine[index1].equals("-")) {return 23;}
        if(tokensInLine[index1].equals("*")) {return 24;}
        if(tokensInLine[index1].equals("!=")) {return 25;}
        if(tokensInLine[index1].equals("==")) {return 26;}
        if(tokensInLine[index1].equals("<")) {return 27;}
        if(tokensInLine[index1].equals(">")) {return 28;}
        if(tokensInLine[index1].equals("<=")) {return 29;}
        if(tokensInLine[index1].equals(">=")) {return 30;}


        if(TokenPattern.NUMBER.matcher(tokensInLine[index1]).matches()) {return 31;}
        if(TokenPattern.ID.matcher(tokensInLine[index1]).matches() &&
            tokensInLine[index1].length() <= 10) {
            return 32;
        }
        
        System.out.println("Invalid token ::"+tokensInLine[index1]);
        System.exit(0);
        return -1; 
    }

    //reads a line from core program file
    //inserts space forcefully between every pair of tokens
    //splits the line on space
    //stores the strings after splitting in tokensInLine array
    //increments index1 to move to next token
    public void skipToken() throws FileNotFoundException, IOException {
        if(null == tokensInLine || tokensInLine.length-1 == index1) {
            String line = reader1.readLine();
            if(null == line) {
                tokensInLine = new String[1];
                tokensInLine[0] = "EOF";
            } else {
                while(TokenPattern.WHITESPACE.matcher(line).matches() || 0 == line.length()) {
                    line = reader1.readLine();
                }
                line = line.trim();
                line = line.replaceAll("[,]"," , ");
                line = line.replaceAll("[;]"," ; ");
                line = line.replaceAll("[=][=]"," == ");
                line = line.replaceAll("[>][=]"," >= ");
                line = line.replaceAll("[<][=]"," <= ");
                line = line.replaceAll("[+]"," + ");
                line = line.replaceAll("[-]"," - ");
		line = line.replaceAll("[*]"," * ");
                line = line.replaceAll("[\\[]"," [ ");
                line = line.replaceAll("[\\]]"," ] ");
		line = line.replaceAll("[!][=]"," != ");
		line = line.replaceAll("([>])([^=])"," > $2");
                line = line.replaceAll("([<])([^=])"," < $2");
		line = line.replaceAll("([!])([^=])"," ! $2");
                line = line.replaceAll("[&][&]"," && ");
                line = line.replaceAll("[|][|]"," || ");
                line = line.replaceAll("[(]"," ( ");
                line = line.replaceAll("[)]"," ) ");
                line = line.replaceAll("([^=><!])([=])([^=])","$1 = $3");
		line = line.trim();
                tokensInLine = TokenPattern.WHITESPACE.split(line);
            }
            index1 = 0;
        } else {
            index1++;
        }
    }

    //uses same logic as skipToken, but forcefully injecting space
    //between every pair of tokens is not necessary as it is assumed
    //input data will be delimited by spaces
    public int getNextInput() throws FileNotFoundException, IOException {
        if(null == inputsInLine || inputsInLine.length-1 == index2) {
            String line = reader2.readLine();
            if(null == line) {
                System.out.println("Not enough inputs in the input file to read");
                System.exit(0);
            } else {
                while(TokenPattern.WHITESPACE.matcher(line).matches() || 0 == line.length()) {
                    line = reader2.readLine();
                }
                inputsInLine = TokenPattern.WHITESPACE.split(line);
            }
            index2 = 0;
        } else {
            index2++;
        }
        try {
            return Integer.parseInt(inputsInLine[index2]);
        } catch(Exception e) {
            System.out.println("Invalid input data ::"+inputsInLine[index2]);
            System.exit(0);
        }
        return 0;
    }

    public int intVal() {
        return Integer.parseInt(tokensInLine[index1]);
    }

    public String idName() {
        return tokensInLine[index1];
    }
}
