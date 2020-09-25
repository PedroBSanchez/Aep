package aep.valueObjects;

public class Nome {
    
    private String valor;


    public Nome(String valor) {
        validaNome(valor);
        setValor(valor);
    }

    public static void validaNome(String valor) {
        
        if (valor == null || valor.trim().split(" ").length < 2) {
            throw new RuntimeException("Nome deve ser composto por mais de uma palavra");
        }
    }

    public void setValor(String valor) {
        this.valor = valor;
    }

    public String getValor() {
        return valor;
    }

}
