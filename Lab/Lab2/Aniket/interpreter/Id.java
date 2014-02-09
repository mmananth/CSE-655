import java.io.*;

//class for <id> NT
class Id {
    private String name; 
    private int val; 
    private Boolean initialized;
    private static Id eIds[]; //static array of Ids tobe shared among the program statements
    private static int idCount = 0; //How many Ids have been declared

    static {
        eIds = new Id[20]; //Max of 20 Ids can be declared
    }

    private Id(String n) {
	name = n; 
        initialized = false; 
    }

    //search the static Id list to see whether this Id has been declared
    //if not, throw an error as any Id in a statement has tobe declared
    public static Id parseIdForSS() throws FileNotFoundException, IOException {
        String idName = Tokenizer.instance().idName();
        for(int i=0; i<idCount; i++) {
            if(idName.equals(eIds[i].name)){
	        Tokenizer.instance().skipToken();
	        return eIds[i];
            }
        }
        System.out.println("Parse error : undeclared variable used : "+idName);
        System.exit(0);
        return null;
    }
    //In declaration, if the Id is already present in the array, it implies, the
    //program is trying to redeclare the Id, hence error is thrown
    public static Id parseIdForDS() throws FileNotFoundException, IOException {
        String idName = Tokenizer.instance().idName();
        for(int i=0; i<idCount; i++) {
            if(idName.equals(eIds[i].name)){
	        System.out.println("Parse error : redeclared variable : "+idName);
	        System.exit(0);
	    }
        }
        Tokenizer.instance().skipToken();
        Id nId = new Id(idName);
        eIds[idCount++] = nId;
        return nId; 
    }

    public String getName() {
        return name;
    }

    public int getValue() {
        return val;
    }

    public void setValue(int value) {
        val = value;
        initialized = true; //setValue implies the Id is initialized
    }

    public Boolean getInitialized() {
        return initialized;
    }
}
