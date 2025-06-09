package httpRequest;


import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URI;
import java.net.URISyntaxException;
import java.net.URL;


public class httpRequester {
	
	public InputStream getFeed(String urlFeed, String param) throws IOException {
		
		try {
			URL url 		 			 = new URI(String.format(urlFeed, param)).toURL();
			HttpURLConnection connection = (HttpURLConnection) url.openConnection();
			
			
			connection.setRequestMethod("GET");
			connection.setRequestProperty("Accept", "application/xml");
			connection.setConnectTimeout(5000);
			connection.setReadTimeout(5000);

			int responseCode = connection.getResponseCode();
            if (responseCode != HttpURLConnection.HTTP_OK) {
                throw new IOException("Error HTTP: " + responseCode);
            }
			
			return connection.getInputStream();
		}
		catch(URISyntaxException e){
			e.printStackTrace();
			return null;
		}
	} 
}
