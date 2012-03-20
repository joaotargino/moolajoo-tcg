package xml.reader;

import java.io.File;
import java.io.IOException;

import org.jdom.Document;
import org.jdom.Element;
import org.jdom.JDOMException;
import org.jdom.input.SAXBuilder;

public class XmlReader {
	
	private String path;
	
	public XmlReader(String path) {
		this.path = path;
	}
	
	protected Element getRootElement() {
		File xmlfile = new File(path);
		
		Document d = null;
		try {
			d = new SAXBuilder().build(xmlfile);
		} catch (JDOMException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return d.getRootElement();
	}
}