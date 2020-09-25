package aep;

import aep.valueObjects.Descricao;

public class NivelDeRisco {
    
    private Descricao descricao;
    private int nivel;
    private int idNivelDeRisco;


    public NivelDeRisco(String descricao, int nivel, int idNivelDeRisco) {
        this.descricao = new Descricao(descricao);
        setNivel(nivel);
        setIdNivelDeRisco(idNivelDeRisco);
    }


    public int getNivel() {
        return nivel;
    }

    public void setNivel(int nivel) {
        this.nivel = nivel;
    }

    public int getIdNivelDeRisco() {
        return idNivelDeRisco;
    }

    public void setIdNivelDeRisco(int idNivelDeRisco) {
        this.idNivelDeRisco = idNivelDeRisco;
    }

    


}
