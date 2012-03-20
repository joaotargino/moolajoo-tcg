package entity;

import java.util.List;

public class Offensive {
	
	private int id;
	private String name;
	
	private List<Integer> classesId;

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
	
	public List<Integer> getClassesId() {
		return classesId;
	}
	
	public void setClassesId(List<Integer> classesId) {
		this.classesId = classesId;
	}
	
	@Override
	public String toString() {
		return "Offensive ID: " + getId() + ", Name: " + getName() + ", classes ID: " + getClassesId();
	}
}