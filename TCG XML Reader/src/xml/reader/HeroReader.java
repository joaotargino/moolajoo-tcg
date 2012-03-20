package xml.reader;

import java.util.ArrayList;
import java.util.List;

import org.jdom.Element;

import entity.Hero;

public class HeroReader extends XmlReader {

	public HeroReader(String path) {
		super(path);
	}
	
	public List<Hero> getHeroes() {
		Element root = getRootElement();
		
		List<Hero> entities = new ArrayList<Hero>();
		List<Element> listEntities = root.getChildren();
		
		for (Element e : listEntities) {
			Hero actual = new Hero();
			
			actual.setId(Integer.parseInt(e.getAttributeValue("id")));
			actual.setName(e.getChild("name").getValue());
			actual.setClassId(Integer.parseInt(e.getChild("class").getAttributeValue("id")));
			actual.setHp(Integer.parseInt(e.getChild("hp").getValue()));
			actual.setMp(Integer.parseInt(e.getChild("mp").getValue()));
			
			entities.add(actual);
		}
		
		return entities;
	}
	
	public Hero getHero(int id) {
		List<Hero> entities = getHeroes();
		
		for (Hero e : entities)
			if (e.getId() == id)
				return e;
		
		return null;
	}
	
	public static void main(String[] args) {
		String LINE_SEPARATOR = System.getProperty("file.separator");
		String xml = System.getProperty("user.dir") + LINE_SEPARATOR + "resources" + LINE_SEPARATOR + "heroes.xml";
		
		HeroReader r = new HeroReader(xml);
		List<Hero> entities = r.getHeroes();
		
		for (Hero e : entities)
			System.out.println(e);
	}

}
