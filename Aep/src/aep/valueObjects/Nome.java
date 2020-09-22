package aep.valueObjects;

public class Nome {
    
    private String valor;


    public Nome(String valor) {
        validaNome(valor);
        setValor(valor);
    }

    public static void validaNome(String valor) {
        
    }

    public void setValor(String valor) {
        this.valor = valor;
    }

    public String getValor() {
        return valor;
    }

}
