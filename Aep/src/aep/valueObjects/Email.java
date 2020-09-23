package aep.valueObjects;

public class Email {
    
    private String valor;

    public Email(String valor) {
        validaEmail(valor);
        setValor(valor);
    }

    public static void validaEmail(String valor) {
        if (valor == null || !valor.contains("@") || valor.trim().split("@").length < 2) {
            throw new RuntimeException("Email deve possui um domínio e uma extensão");
        }
    }


    public void setValor(String valor) {
        this.valor = valor;
    }
    public String getValor() {
        return valor;
    }


}
