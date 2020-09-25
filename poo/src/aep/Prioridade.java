package aep;

import aep.valueObjects.Descricao;

public class Prioridade {
    
    private Descricao descricao;
    private int nivel;
    private int idPrioridade;

    public Prioridade(String descricao, int nivel, int idPrioridade) {
        this.descricao = new Descricao(descricao);
        setNivel(nivel);
        setIdPrioridade(idPrioridade);
    }
   

    public int getNivel() {
        return nivel;
    }

    public void setNivel(int nivel) {
        this.nivel = nivel;
    }

    public int getIdPrioridade() {
        return idPrioridade;
    }

    public void setIdPrioridade(int idPrioridade) {
        this.idPrioridade = idPrioridade;
    }


    

}
