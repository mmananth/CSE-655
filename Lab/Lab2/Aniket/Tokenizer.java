import java.io.*;
import java.util.regex.*;

class TokenPattern {
    static Pattern WHITESPACE = Pattern.compile("[\\s]+");
    static Pattern NUMBER = Pattern.compile("[\\d]+");
    static Pattern ID = Pattern.compile("[A-Z]+[0-9]*");
}

public class Tokenizer {
    private FileReader fr;
    private BufferedReader reader; 
    private String[] tokensInLine;
    private int index;
    
    public Tokenizer(String programFile) 
        throws FileNotFoundException,IOException {
        index = 0;
        fr = new FileReader(programFile);
	reader = new BufferedReader(fr);
	skipToken();
    }
   
    public int getToken() {
 
        if(tokensInLine[index].equals("program")) {return 1;}
        if(tokensInLine[index].equals("begin")) {return 2;}
        if(tokensInLine[index].equals("end")) {return 3;}
	if(tokensInLine[index].equals("int")) {return 4;}
	if(tokensInLine[index].equals("if")) {return 5;}
        if(tokensInLine[index].equals("then")) {return 6;}
        if(tokensInLine[index].equals("else")) {return 7;}
        if(tokensInLine[index].equals("while")) {return 8;}
        if(tokensInLine[index].equals("loop")) {return 9;}
        if(tokensInLine[index].equals("read")) {return 10;}
        if(tokensInLine[index].equals("write")) {return 11;}

	if(tokensInLine[index].equals("EOF")) {return 33;}

        if(tokensInLine[index].equals(";")) {return 12;}
        if(tokensInLine[index].equals(",")) {return 13;}
        if(tokensInLine[index].equals("=")) {return 14;}
        if(tokensInLine[index].equals("!")) {return 15;}
        if(tokensInLine[index].equals("[")) {return 16;}
        if(tokensInLine[index].equals("]")) {return 17;}
        if(tokensInLine[index].equals("&&")) {return 18;}
        if(tokensInLine[index].equals("||")) {return 19;}
        if(tokensInLine[index].equals("(")) {return 20;}
        if(tokensInLine[index].equals(")")) {return 21;}
        if(tokensInLine[index].equals("+")) {return 22;}
        if(tokensInLine[index].equals("-")) {return 23;}
        if(tokensInLine[index].equals("*")) {return 24;}
        if(tokensInLine[index].equals("!=")) {return 25;}
        if(tokensInLine[index].equals("==")) {return 26;}
        if(tokensInLine[index].equals("<")) {return 27;}
        if(tokensInLine[index].equals(">")) {return 28;}
        if(tokensInLine[index].equals("<=")) {return 29;}
        if(tokensInLine[index].equals(">=")) {return 30;}


        if(TokenPattern.NUMBER.matcher(tokensInLine[index]).matches()) {return 31;}
        if(TokenPattern.ID.matcher(tokensInLine[index]).matches() &&
            tokensInLine[index].length() <= 10) {
            return 32;
        }

        return -1; 
    }
    
    public void skipToken() throws IOException {
        if(null == tokensInLine || tokensInLine.length-1 == index) {
            String line = reader.readLine();
            if(null == line) {
                tokensInLine = new String[1];
                tokensInLine[0] = "EOF";
            } else {
                while(TokenPattern.WHITESPACE.matcher(line).matches() || 0 == line.length()) {
                    line = reader.readLine();
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
            index = 0;
        } else {
            index++;
        }
    }
}
