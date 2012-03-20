package xml.reader;

import java.util.ArrayList;
import java.util.List;

import org.jdom.Element;

import entity.Hero;
import entity.Offensive;

public class OffensiveReader extends XmlReader {

	public OffensiveReader(String path) {
		super(path);
	}
	
	public List<Offensive> getOffensives() {
		Element root = getRootElement();
		
		List<Offensive> entities = new ArrayList<Offensive>();
		List<Element> listEntities = root.getChildren();
		
		for (Element e : listEntities) {
			Offensive actual = new Offensive();
			
			actual.setId(Integer.parseInt(e.getAttributeValue("id")));
			actual.setName(e.getChild("name").getValue());
			
			List<Integer> classesId = new ArrayList<Integer>();
			List<Element> listChildren = e.getChild("classes").getChildren();
			
			for (Element el : listChildren)
				classesId.add(Integer.parseInt(el.getAttributeValue("id")));
			
			actual.setClassesId(classesId);
			
			entities.add(actual);
		}
		
		return entities;
	}
	
	public Offensive getOffensive(int id) {
		List<Offensive> entities = getOffensives();
		
		for (Offensive e : entities)
			if (e.getId() == id)
				return e;
		
		return null;
	}
	
	public static void main(String[] args) {
		String LINE_SEPARATOR = System.getProperty("file.separator");
		String xml = System.getProperty("user.dir") + LINE_SEPARATOR + "resources" + LINE_SEPARATOR + "offensives.xml";
		
		OffensiveReader r = new OffensiveReader(xml);
		List<Offensive> entities = r.getOffensives();
		
		for (Offensive e : entities)
			System.out.println(e);
	}

}
