package aplicacion;

import java.io.BufferedReader;
import java.io.PrintStream;
import java.io.InputStreamReader;
import java.io.IOException;

/**
 * Clase AplCuenta_P1 – Primera Parte
 * 
 * En esta versión se implementa la estructura base del laboratorio, donde se incluyen:
 * - Declaración de variables estáticas (arreglos para nombres, cédulas, saldos, idCuentas)
 * - Configuración de entrada/salida
 * - Implementación de los métodos requeridos (mostrarMenu, leerOpcion, registrarCliente, etc.)
 * 
 * NOTA: Los métodos retirar() y verSaldo() solo tienen su encabezado y deben ser completados en la Segunda Parte.
 */
public class AplCuenta_P1 {
    static String[] nombres;
    static String[] cedulas;
    static double[] saldos;
    static String[] idCuentas;
    static int numCuentas = 0;

    static BufferedReader in;
    static PrintStream out;

    public static void main(String[] args) throws IOException {
        nombres = new String[10];
        cedulas = new String[10];
        saldos = new double[10];
        idCuentas = new String[10];

        in = new BufferedReader(new InputStreamReader(System.in));
        out = System.out;

        boolean noSalir = true;
        int opcion;

        do {
            mostrarMenu();
            opcion = leerOpcion();
            noSalir = ejecutarAccion(opcion);
        } while (noSalir);
    }

    static void mostrarMenu() {
        out.println("1. Registrar Cliente");
        out.println("2. Abrir una Cuenta");
        out.println("3. Realizar Transacción");
        out.println("4. Consultar Información");
        out.println("5. Salir");
    }

    static int leerOpcion() throws IOException {
        out.print("Seleccione su opción: ");
        int opcion = Integer.parseInt(in.readLine());
        out.println();
        return opcion;
    }

    static boolean ejecutarAccion(int opcion) throws IOException {
        boolean noSalir = true;
        int opc = 0;
        switch (opcion) {
            case 1:
                registrarCliente();
                break;
            case 2:
                abrirCuenta();
                break;
            case 3:
                realizarTransacciones();
                break;
            case 4:
                mostrarMenuConsultas();
                opc = leerOpcion();
                ejecutarConsultas(opc);
                break;
            case 5:
                noSalir = false;
                break;
            default:
                out.println("Opción no válida");
                break;
        }
        out.println();
        return noSalir;
    }

    static void registrarCliente() throws IOException {
        out.print("Ingrese el número de cédula: ");
        String cedula = in.readLine();
        out.println();
        int indice = buscarCliente(cedula);
        if (numCuentas < 10) {
            if (indice == -1) {
                cedulas[numCuentas] = cedula;
                out.print("Ingrese el nombre y el apellido: ");
                nombres[numCuentas] = in.readLine();
                numCuentas++;
                out.println("\nEl cliente ha sido registrado!!!\n");
            } else {
                out.println("\nEl cliente ya existe");
            }
        } else {
            out.println("\nNo se pueden registrar más clientes");
        }
    }

    static void abrirCuenta() throws IOException {
        out.print("Ingrese el número de cédula del cliente que será dueño de la cuenta: ");
        String cedula = in.readLine();
        out.println();
        boolean noSalir = true;
        String continuar = "";
        do {
            int indice = buscarCliente(cedula);
            if (indice != -1) {
                if (buscarCuenta("" + cedula.charAt(0) + indice) == -1) {
                    double monto;
                    do {
                        out.print("Ingrese el monto (>= 1000) con el que desea abrir la cuenta: ");
                        monto = Double.parseDouble(in.readLine());
                        out.println();
                    } while (monto < 1000);
                    saldos[indice] = monto;
                    idCuentas[indice] = "" + cedula.charAt(0) + indice;
                    out.println("Cuenta abierta exitosamente. Número de cuenta: " + idCuentas[indice]);
                } else {
                    out.println("Cuenta ya fue abierta");
                }
                noSalir = false;
            } else {
                out.println("Cliente no registrado");
                out.print("Desea buscar otro (s/n): ");
                continuar = in.readLine();
                if (continuar.charAt(0) == 's' || continuar.charAt(0) == 'S') {
                    out.print("Ingrese el número de cédula: ");
                    cedula = in.readLine();
                    out.println();
                } else {
                    noSalir = false;
                }
            }
            out.println();
        } while (noSalir);
    }

    static int buscarCliente(String pcedula) {
        int indice = -1;
        boolean encontrado = false;
        int i = 0;
        while (i < cedulas.length && cedulas[i] != null && !encontrado) {
            if (cedulas[i].equals(pcedula)) {
                indice = i;
                encontrado = true;
            }
            i++;
        }
        return indice;
    }

    static void listarCuentasIds() {
        int i = 0;
        while (i < idCuentas.length) {
            if (idCuentas[i] != null) {
                out.println(idCuentas[i]);
            }
            i++;
        }
    }

    static void mostrarMenuTransacciones() {
        out.println("1. Depositar");
        out.println("2. Retirar");
        out.println("3. Ver Saldo");
        out.println("4. Salir");
        out.println();
    }

    static int verificarCuenta() throws IOException {
        out.print("Ingrese el número de cuenta: ");
        String numCuenta = in.readLine();
        out.println();
        return buscarCuenta(numCuenta);
    }

    static int buscarCuenta(String pnumero) {
        int indice = -1;
        int i = 0;
        while (i < idCuentas.length && indice == -1) {
            if (idCuentas[i] != null && idCuentas[i].equals(pnumero)) {
                indice = i;
            }
            i++;
        }
        return indice;
    }

    static void mostrarMenuConsultas() {
        out.println("1. Ver clientes por cédula");
        out.println("2. Ver clientes por nombre");
        out.println("3. Ver Cuentas por número");
        out.println();
    }

    static void ejecutarConsultas(int popcion) {
        switch (popcion) {
            case 1:
                listarInformacion(cedulas);
                break;
            case 2:
                listarInformacion(nombres);
                break;
            case 3:
                listarCuentasIds();
                break;
            default:
                out.println("Valor no válido");
                break;
        }
        out.println();
    }

    static void listarInformacion(String[] plista) {
        int i = 0;
        while (i < plista.length && plista[i] != null) {
            out.println(plista[i]);
            i++;
        }
    }

    static boolean ejecutarTransacciones(int popcion, int pindice) throws IOException {
        boolean seguir = true;
        switch (popcion) {
            case 1:
                depositar(pindice);
                break;
            case 2:
                retirar(pindice);
                break;
            case 3:
                verSaldo(pindice);
                break;
            case 4:
                seguir = false;
                break;
            default:
                out.println("Valor no válido");
                break;
        }
        out.println();
        return seguir;
    }

    static void realizarTransacciones() throws IOException {
        int indice = verificarCuenta();
        if (indice != -1) {
            out.println("Cédula: " + cedulas[indice]);
            out.println("Cliente: " + nombres[indice]);
            out.println();
            int opc;
            boolean seguir = true;
            do {
                mostrarMenuTransacciones();
                opc = leerOpcion();
                seguir = ejecutarTransacciones(opc, indice);
            } while (seguir);
        } else {
            out.println("Cuenta no existe");
        }
    }

    static void depositar(int pindice) throws IOException {
        out.print("Ingrese el monto del depósito: ");
        double monto = Double.parseDouble(in.readLine());
        out.println();
        saldos[pindice] += monto;
        out.println("Su depósito fue de " + monto + " colones");
    }

    // Método retirar() sin implementación – Por completar en la Segunda Parte
    static void retirar(int pindice) throws IOException {
        // Por implementar en la Segunda Parte
    }

    // Método verSaldo() sin implementación – Por completar en la Segunda Parte
    static void verSaldo(int pindice) throws IOException {
        // Por implementar en la Segunda Parte
    }
}
