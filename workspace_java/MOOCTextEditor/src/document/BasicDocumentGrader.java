package document;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;

import document.BasicDocument;

public class BasicDocumentGrader {
    public static void main(String[] args) {
        try
        {
            System.out.println("Sentences, words, and syllables:");
            BufferedReader br = new BufferedReader(new FileReader("test_cases/mod1TestCases.txt"));
            String line;
            PrintWriter out = new PrintWriter("grader_output/module1.part1.out", "utf-8");
            while ((line = br.readLine()) != null)
            {
                BasicDocument doc = new BasicDocument(line);
                String result = doc.getNumSentences() + " " + doc.getNumWords() + " " + doc.getNumSyllables() + " ";
                System.out.print(result);
                System.out.println("");
                out.print(result);
            }
            out.print("\n");
            out.close();
            System.out.println("\nFlesch scores:");
            br.close();

            br = new BufferedReader(new FileReader("test_cases/mod1TestCases.txt"));
            out = new PrintWriter("grader_output/module1.part2.out", "utf-8");
            while ((line = br.readLine()) != null)
            {
                BasicDocument doc = new BasicDocument(line);
                String result = doc.getFleschScore() + " ";
                System.out.print(result);
                System.out.println("");
                out.print(result);
            }
            out.print("\n");
            out.close();
            System.out.print('\n');
            br.close();
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }
}
//Sentences, words, and syllables:
//1 4 5 
//3 12 18 
//2 13 16 
//3 4 7 
//2 7 8 
//115 1000 2008 
//
//Flesch scores:
//118.17500000000001 
//118.17500000000001 
//116.14500000000001 
//121.22000000000003 
//119.19000000000003 
//29.515000000000015 
