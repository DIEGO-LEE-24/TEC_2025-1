public class Radio {
    // Atributos de instancia (privados)
    private String marca;
    private boolean estaEncendida;
    private double frecuencia;
    private String banda;
    private int volumen;
    private Disco disco;  // Objeto de tipo Disco

    // Atributos de clase (estáticos)
    private static int cantidadRadios;  // Contador de radios creadas
    private static final double[] RANGOS_FRECUENCIA = {80.1, 107.5};  // Frecuencia mínima y máxima
    private static final String[] BANDAS_DISPONIBLES = {"AM", "PM1", "FM"};  // Bandas permitidas

    // Constructor: inicializa los atributos de la radio
    public Radio(String marca) {
        this.marca = marca;
        this.estaEncendida = false;  // La radio arranca apagada
        this.frecuencia = RANGOS_FRECUENCIA[0];  // Frecuencia inicial
        this.banda = "AM";  // Banda inicial
        this.volumen = 0;   // Volumen en 0
        this.disco = null;  // No hay disco insertado

        cantidadRadios++;  // Incrementa el contador de radios
    }

    // Métodos públicos

    // Enciende la radio y retorna true si se enciende correctamente
    public boolean encender() {
        estaEncendida = true;
        return estaEncendida;
    }

    // Apaga la radio y retorna false al apagarse
    public boolean apagar() {
        estaEncendida = false;
        return estaEncendida;
    }

    // Cambia la frecuencia a un valor dado, si la radio está encendida y la frecuencia es válida
    public void cambiarFrecuencia(double nuevaFrecuencia) {
        if (estaEncendida && verificarFrecuencia(nuevaFrecuencia)) {
            frecuencia = nuevaFrecuencia;
        }
    }

    // Sobrecarga: cambia la frecuencia a un valor aleatorio dentro del rango permitido
    public void cambiarFrecuencia() {
        if (estaEncendida) {
            double min = RANGOS_FRECUENCIA[0];
            double max = RANGOS_FRECUENCIA[1];
            java.util.Random rand = new java.util.Random();
            double freqAleatoria = min + rand.nextDouble() * (max - min);
            frecuencia = freqAleatoria;
        }
    }

    // Cambia la banda (AM, PM1, FM) si la radio está encendida y la banda es válida
    public void cambiarBanda(String nuevaBanda) {
        if (estaEncendida && verificarBanda(nuevaBanda)) {
            banda = nuevaBanda;
        }
    }

    // Sube el volumen en 1 unidad (si la radio está encendida)
    public boolean subirVolumen() {
        if (estaEncendida) {
            volumen++;
            return true;
        }
        return false;
    }

    // Baja el volumen en 1 unidad (si la radio está encendida)
    public boolean bajarVolumen() {
        if (estaEncendida) {
            volumen--;
            return true;
        }
        return false;
    }

    // Reproduce la pista por defecto si la radio está encendida y hay un disco insertado
    public String reproducir() {
        if (estaEncendida && tieneDisco()) {
            return "Reproduciendo: [Pista inicial del disco]";
        }
        return "No se puede reproducir: radio apagada o disco no insertado.";
    }

    // Reproduce una pista específica, comprobando que el número de pista sea válido
    public String reproducir(int pista) {
        if (estaEncendida && tieneDisco() && disco.getCantidadCanciones() >= pista) {
            return "Reproduciendo pista #" + pista;
        }
        return "No se puede reproducir la pista. Verifica que la radio esté encendida, que haya un disco y que la pista exista.";
    }

    // Inserta un disco en la radio (si está encendida) y retorna la información del disco
    public String insertarDisco(Disco nuevoDisco) {
        if (estaEncendida) {
            disco = nuevoDisco;
            return disco.toString();
        }
        return "La radio está apagada. No se puede insertar el disco.";
    }

    // Método estático para ver cuántas radios se han creado
    public static int verCantidadRadios() {
        return cantidadRadios;
    }

    // Métodos privados de verificación

    // Verifica que la frecuencia esté dentro del rango permitido
    private boolean verificarFrecuencia(double valor) {
        return (valor >= RANGOS_FRECUENCIA[0] && valor <= RANGOS_FRECUENCIA[1]);
    }

    // Verifica que la banda esté entre las opciones válidas
    private boolean verificarBanda(String valorBanda) {
        for (String b : BANDAS_DISPONIBLES) {
            if (b.equals(valorBanda)) {
                return true;
            }
        }
        return false;
    }

    // Verifica si hay un disco insertado
    private boolean tieneDisco() {
        return disco != null;
    }
}
