import java.io.*;

//class for <comp op> NT
class CompOp {
    int altNo=0; // six possible comparison operators
    public void parseCompOp() throws FileNotFoundException, IOException {
        int currentToken = Tokenizer.instance().getToken();
        if(25 == currentToken) {// !=
            altNo = 1;
        } else if(26 == currentToken) {// ==
            altNo = 2;
        } else if(27 == currentToken) {// <
            altNo = 3;
        } else if(28 == currentToken) {// >
            altNo = 4;
        } else if(29 == currentToken) {// <=
            altNo = 5;
        } else if(30 == currentToken) {// >=
            altNo = 6;
        } else {
            System.out.println("Parse error : Invalid comparison operator");
            System.exit(0);
        }
        Tokenizer.instance().skipToken();
    }

    public void printCompOp() throws IOException {
        if(1 == altNo) {
            System.out.print(" != ");
        } else if(2 == altNo) {
            System.out.print(" == ");
        }  else if(3 == altNo) {
            System.out.print(" < ");
        }  else if(4 == altNo) {
            System.out.print(" > ");
        }  else if(5 == altNo) {
            System.out.print(" <= ");
        } else {
            System.out.print(" >= ");
        }
    }

    //Since it is a comparison, it can only return
    //true or false
    public Boolean evalCompOp(int val1, int val2) {
        if(1 == altNo) {
            return (val1!=val2);
        } else if(2 == altNo) {
            return (val1==val2);
        }  else if(3 == altNo) {
            return (val1<val2);
        }  else if(4 == altNo) {
	    return (val1>val2);
        }  else if(5 == altNo) {
            return (val1<=val2);
        } else {
            return (val1>=val2);
        }
    } 
}
