package aep;

import aep.valueObjects.*;

import java.util.ArrayList;
import java.util.List;

public class Trabalho {
    
    
    private Descricao descricao;
    private String exercicio;
    private String risco;
    private int idTrabalho;

    //Relações
    private List<EpiTrabalho> Epis = new ArrayList<>();   
    private List<Postagem> postagens = new ArrayList<>(); //Postagens existentes sobre cada trabalho, são adicionadas pelo usuário
    private List<Ambiente> ambientes = new ArrayList<>(); //Ambientes de cada trabalho (1..*)
    private NivelDeRisco nivelDeRisco;
    

    public Trabalho(String descricao, String exercicio, String risco, int idTrabalho) {
            this.descricao = new Descricao(descricao);
            setExercicio(exercicio);
            setRisco(risco);
            setIdTrabalho(idTrabalho);
    }





   

    public String getExercicio() {
        return exercicio;
    }

    public void setExercicio(String exercicio) {
        this.exercicio = exercicio;
    }

    public String getRisco() {
        return risco;
    }

    public void setRisco(String riscos) {
        this.risco = riscos;
    }

    public int getIdTrabalho() {
        return idTrabalho;
    }

    public void setIdTrabalho(int idTrabalho) {
        this.idTrabalho = idTrabalho;
    }

    

}
