package aep.valueObjects;

public class Descricao {
    
    private String valor;

    public Descricao(String valor) {
        validaDescricao(valor);
        setValor(valor);
    }

    public static void validaDescricao(String valor) {
        if (valor == null || valor.trim().split(" ").length <= 1) {
            throw new RuntimeException("Descrição deve ser composta por mais de uma palavra");
        }
    }


    public void setValor(String valor) {
        this.valor = valor;
    }
    public String getValor() {
        return valor;
    }
}