package aep;

import aep.valueObjects.*;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Trabalho {
    
    
    private Descricao descricao;
    private String exercicio;
    private String risco;
    private int idTrabalho;

    //Relações
    private Set<EpiTrabalho> epis = new HashSet<>();   
    private Set<Postagem> postagens = new HashSet<>(); //Postagens existentes sobre cada trabalho, são adicionadas pelo usuário
    private List<Ambiente> ambientes = new ArrayList<>(); //Ambientes de cada trabalho (1..*)
    private NivelDeRisco nivelDeRisco;
    

    public Trabalho(String descricao, String exercicio, String risco, int idTrabalho, NivelDeRisco nivelDeRisco, Ambiente ambiente) {
            this.descricao = new Descricao(descricao);
            setExercicio(exercicio);
            setRisco(risco);
            setIdTrabalho(idTrabalho);
            setNivelDeRisco(nivelDeRisco);
            ambientes.add(ambiente);
    }

    public void addEpiTrabalho(EpiTrabalho equipamento) {
        if (this.epis.contains(equipamento)) {
            return;
        }
        this.epis.add(equipamento);
    }

    public void addPostagem(Postagem postagem) {
        if (this.postagens.contains(postagem)) {
            return;
        }
        this.postagens.add(postagem);
    }



    public void addAmbiente(Ambiente ambiente) {
        ambientes.add(ambiente);
    }




    public Set<Postagem> getPostagens() {
        return postagens;
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


    public void setNivelDeRisco(NivelDeRisco nivelDeRisco) {
        this.nivelDeRisco = nivelDeRisco;
    }
    public NivelDeRisco getNivelDeRisco() {
        return nivelDeRisco;
    }
    

}
