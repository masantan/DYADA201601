import java.io.*;
import java.util.*;
import java.lang.*;

public class Crypt{
	public static ArrayList<Integer> z_algorithm(
		ArrayList<Integer> P, ArrayList< Integer > T)
	{
		ArrayList<Integer> z,matches,S=new ArrayList<Integer>(P);
		int m = P.size();
		S.add(-1); S.addAll(T);
		
		int L = 0, R = 0, n = S.size();
		z = new ArrayList<Integer>( S );
		matches = new ArrayList<Integer>();

		for (int i = 1; i<n; i++) {
			if (i > R) {
				L = R = i;
				while ( R < n && S.get(R-L) == S.get(R) ) {
					R++;
				}
				z.set(i,R-L);
				R--;
			} else {
				int k = i-L;
				if (z.get(k) < R-i+1) z.set(i,z.get(k));
				else {
					L = i;
					while (R < n && S.get(R-L) == S.get(R)) R++;
					z.set(i,R-L);
					R--;
				}
			}
			if( z.get(i) == m )
			{
				matches.add(i-m-1);
			}
		}
		return matches;
	}
	public static void main(String[] args) {
		BufferedReader in = null, in2 = null;
	try {
		// Files which we will work with
		File km_dir = new File("known_message.txt");
		File fm_dir = new File("stdin");
		
		// Some Utils variables
		String line;
		ArrayList<Integer> sizes_known=new ArrayList<Integer>();

		// First process the known message	
		in = new BufferedReader( new InputStreamReader(
               	new FileInputStream(km_dir), "UTF8"));
		while ((line = in.readLine()) != null)
		{
			
		   String[] splited = line.split("\\s+");
        	for (String word : splited) {
            	//System.out.println(word + " " + word.length());
            	sizes_known.add(word.length());
        	}
		}
		// First process the known message
		in2 = new BufferedReader( new InputStreamReader(
                new FileInputStream(fm_dir), "UTF8"));
		int testCases = Integer.parseInt(in2.readLine());
		line = in2.readLine();
		while( testCases-- > 0 )
		{
			ArrayList<Integer> sizes_msg = new ArrayList<Integer>();
			ArrayList<String> new_msg = new ArrayList<String>();
			while ((line = in2.readLine()) != null )
			{
				if(line.length() == 0) break;
			    String[] splited = line.split("\\s+");
	        	for (String word : splited) {
	            	sizes_msg.add(word.length());
	            	new_msg.add(word);
	        	}
			}
			// We get the message and split it in words, now we have to look for
			// posibles matches at least in size words
			ArrayList<Integer> matches = z_algorithm(sizes_known,sizes_msg);
			for(int i=0; i<matches.size(); i++)
			{
				// We have an occurrence, lets propose it as a candidate
				System.out.println("Occurence at " + matches.get(i) );
				System.out.println("start in " + new_msg.get(matches.get(i)));
			}
		}	
    } catch (UnsupportedEncodingException e) {
		System.out.println(e.getMessage());
    } catch (IOException e) {
		System.out.println(e.getMessage());
    } catch (Exception e) {
		System.out.println(e.getMessage());
    } finally {
    	try{
    		in.close();
    		in2.close();
    	}catch (Exception e)
    	{
			System.out.println(e.getMessage());
    	}
    }
	}
}