package xml.reader;

import java.util.ArrayList;
import java.util.List;

import org.jdom.Element;

public class ClassReader extends XmlReader {

	public ClassReader(String path) {
		super(path);
	}
	
	public List<entity.Class> getClasses() {
		Element root = getRootElement();
		
		List<entity.Class> entities = new ArrayList<entity.Class>();
		List<Element> listEntities = root.getChildren();
		
		for (Element e : listEntities) {
			entity.Class actual = new entity.Class();
			
			actual.setId(Integer.parseInt(e.getAttributeValue("id")));
			actual.setName(e.getChild("name").getValue());
			
			entities.add(actual);
		}
		
		return entities;
	}
	
	public entity.Class getClass(int id) {
		List<entity.Class> entities = getClasses();
		
		for (entity.Class e : entities)
			if (e.getId() == id)
				return e;
		
		return null;
	}
	
	public static void main(String[] args) {
		String LINE_SEPARATOR = System.getProperty("file.separator");
		String xml = System.getProperty("user.dir") + LINE_SEPARATOR + "resources" + LINE_SEPARATOR + "classes.xml";
		
		ClassReader r = new ClassReader(xml);
		List<entity.Class> entities = r.getClasses();
		
		for (entity.Class e : entities)
			System.out.println(e);
	}
}