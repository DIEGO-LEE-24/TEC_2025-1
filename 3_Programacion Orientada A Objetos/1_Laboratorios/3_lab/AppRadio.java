public class AppRadio {
    public static void main(String[] args) {
        // 1. Crear discos y agregar canciones
        Disco disco1 = new Disco("Bon Jovi");
        disco1.agregarCancion("Livin' on a Prayer");
        disco1.agregarCancion("It's My Life");

        Disco disco2 = new Disco("La Banda X");
        disco2.agregarCancion("Primera Canción");

        // 2. Imprimir cada disco con el formato "profesor"
        System.out.println("** DISCO 1 **");
        System.out.println(disco1); // Llama a disco1.toString()
        
        System.out.println("** DISCO 2 **");
        System.out.println(disco2); // Llama a disco2.toString()

        // 3. Crear una radio (NO imprimimos el contador, ni mensajes extra)
        Radio radio1 = new Radio("Sony");

        // 4. Encender la radio e insertar el disco, 
        //    pero NO imprimimos el resultado devuelto por insertarDisco()
        radio1.encender();
        radio1.insertarDisco(disco1); // Se hace la acción, pero no se muestra en pantalla

        // 5. Reproducir la pista por defecto y la pista #2 
        //    (Nuevamente, NO imprimimos los mensajes que retornan)
        radio1.reproducir();
        radio1.reproducir(2);

        // 6. Cambiar frecuencia y banda (sin mostrar nada)
        radio1.cambiarFrecuencia(100.5);
        radio1.cambiarBanda("FM");

        // 7. Subir el volumen (sin imprimir nada)
        radio1.subirVolumen();

        // 8. Crear otra radio, sin mostrar el contador
        Radio radio2 = new Radio("Panasonic");

    }
}
