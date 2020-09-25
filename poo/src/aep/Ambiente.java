package aep;

import aep.valueObjects.Descricao;

public class Ambiente {
    
    private String zona;
    private Descricao descricao;
    private int idAmbiente;


    public Ambiente(String zona, String descricao, int idAmbiente) {
        setZona(zona);
        this.descricao = new Descricao(descricao);
        setIdAmbiente(idAmbiente);
    }



    public String getZona() {
        return zona;
    }

    public void setZona(String zona) {
        this.zona = zona;
    }

   

    public int getIdAmbiente() {
        return idAmbiente;
    }

    public void setIdAmbiente(int idAmbiente) {
        this.idAmbiente = idAmbiente;
    }

    

}
