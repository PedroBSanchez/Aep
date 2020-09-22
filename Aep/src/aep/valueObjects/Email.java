package aep.valueObjects;

public class Email {
    
    private String valor;

    public Email(String valor) {
        validaEmail(valor);
        setValor(valor);
    }

    public static void validaEmail(String valor) {
        
    }


    public void setValor(String valor) {
        this.valor = valor;
    }
    public String getValor() {
        return valor;
    }


}
