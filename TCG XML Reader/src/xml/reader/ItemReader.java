package xml.reader;

import java.util.ArrayList;
import java.util.List;

import org.jdom.Element;

import entity.Item;

public class ItemReader extends XmlReader {

	public ItemReader(String path) {
		super(path);
	}
	
	public List<Item> getItems() {
		Element root = getRootElement();
		
		List<Item> entities = new ArrayList<Item>();
		List<Element> listEntities = root.getChildren();
		
		for (Element e : listEntities) {
			Item actual = new Item();
			
			actual.setId(Integer.parseInt(e.getAttributeValue("id")));
			actual.setName(e.getChild("name").getValue());
			
			entities.add(actual);
		}
		
		return entities;
	}
	
	public Item getItem(int id) {
		List<Item> entities = getItems();
		
		for (Item e : entities)
			if (e.getId() == id)
				return e;
		
		return null;
	}
	
	public static void main(String[] args) {
		String LINE_SEPARATOR = System.getProperty("file.separator");
		String xml = System.getProperty("user.dir") + LINE_SEPARATOR + "resources" + LINE_SEPARATOR + "items.xml";
		
		ItemReader r = new ItemReader(xml);
		List<Item> entities = r.getItems();
		
		for (Item e : entities)
			System.out.println(e);
	}

}
