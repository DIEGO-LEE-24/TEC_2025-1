import java.util.ArrayList;

public class Disco {
    private String autor;
    private ArrayList<String> canciones;  // Guarda los títulos de las canciones

    public Disco(String autor) {
        this.autor = autor;
        this.canciones = new ArrayList<>();
    }

    public void agregarCancion(String nombreCancion) {
        canciones.add(nombreCancion);
    }

    public String getAutor() {
        return autor;
    }

    public int getCantidadCanciones() {
        return canciones.size();
    }

    public String getCancion(int indice) {
        return canciones.get(indice);
    }

    // Formato "profesor": Autor y lista de canciones
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Autor: ").append(autor).append("\n");
        sb.append("**** Lista de canciones ****\n");
        for (String c : canciones) {
            sb.append(c).append("\n");
        }
        return sb.toString();
    }
}
