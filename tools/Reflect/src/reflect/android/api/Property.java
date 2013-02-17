package reflect.android.api;

public class Property extends NamedArtifact {
	
	private boolean m_static;

	public Property(String name) {
		this(1, name);
	}

	public Property(int since, String name) {
		super(since, "Ljava.lang.Object;", name);
		m_static = false;
	}

	public boolean equals(Object o) {
		if (o == null || !(o instanceof Property))
			return false;
		Property p = (Property)o;
		return getName().equals(p.getName()) &&
				getSignature().equals(p.getSignature());
	}

	public boolean isStatic() { return m_static; }
	public void setIsStatic(boolean is_static) { m_static = is_static; }
}
