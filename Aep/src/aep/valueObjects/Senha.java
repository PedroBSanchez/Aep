package aep.valueObjects;

public class Senha {
    
    private String valor;


    public Senha(String valor) {

        validaSenha(valor);
        setValor(valor);
            
    }

    public static void validaSenha(String valor) {
        
    }

    public void setValor(String valor) {
        this.valor = valor;
    }

    public String getValor() {
        return valor;
    }
}
