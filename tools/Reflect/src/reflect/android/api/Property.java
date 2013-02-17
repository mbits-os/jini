package reflect.android.api;

public class Property extends NamedArtifact {
	
	private boolean m_static;

	public Property(String signature, String name) {
		this(1, signature, name);
	}

	public Property(int since, String signature, String name) {
		super(since, signature, name);
		m_static = false;
	}

	public boolean isStatic() { return m_static; }
	public void setIsStatic(boolean is_static) { m_static = is_static; }
}