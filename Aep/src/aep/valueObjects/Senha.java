package aep.valueObjects;

public class Senha {
    
    private String valor;


    public Senha(String valor) {

        validaSenha(valor);
        setValor(valor);
            
    }

    public static void validaSenha(String valor) {
        if(valor == null || valor.trim().split(" ").length != 1) {
            throw new RuntimeException("Senha deve ser composta por apenas uma palavra");
        }
    }

    public void setValor(String valor) {
        this.valor = valor;
    }

    public String getValor() {
        return valor;
    }
}
