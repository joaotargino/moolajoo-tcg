package entity;

public class Hero {
	
	private int id;
	private int classId;
	private String name;
	
	private int hp;
	private int mp;
	
	public int getId() {
		return id;
	}
	
	public void setId(int id) {
		this.id = id;
	}
	
	public int getClassId() {
		return classId;
	}
	
	public void setClassId(int classId) {
		this.classId = classId;
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public int getHp() {
		return hp;
	}
	
	public void setHp(int hp) {
		this.hp = hp;
	}
	
	public int getMp() {
		return mp;
	}
	
	public void setMp(int mp) {
		this.mp = mp;
	}
	
	@Override
	public String toString() {
		return "Hero ID: " + getId() + ", Name: " + getName() + 
				", Class ID: " + classId + ", HP: " + hp + ", MP: " + mp;
	}
}