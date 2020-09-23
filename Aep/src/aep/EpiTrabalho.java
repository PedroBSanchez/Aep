package aep;

import java.util.ArrayList;
import java.util.List;

import aep.valueObjects.Descricao;

public class EpiTrabalho {
    
    private String funcao;
    private Descricao descricao;
    private int idEquipamento;

    //Relações
    private Prioridade prioridade;
    private List<Trabalho> trabalhos = new ArrayList<>(); //São adicionados trabalhos a lista quando um trabalho em específico adiciona um Epi


    public EpiTrabalho(String funcao, String descricao, int idEquipamento, Prioridade prioridade) {
        setFuncao(funcao);
        this.descricao = new Descricao(descricao);
        setIdEquipamento(idEquipamento);
        setPrioridade(prioridade);

    }


    public List<Trabalho> getTrabalhos() {
        return trabalhos;
    }

    


    public String getFuncao() {
        return funcao;
    }

    public void setFuncao(String funcao) {
        this.funcao = funcao;
    }


    public int getIdEquipamento() {
        return idEquipamento;
    }

    public void setIdEquipamento(int idEquipamento) {
        this.idEquipamento = idEquipamento;
    }

    public void setPrioridade(Prioridade prioridade) {
        this.prioridade = prioridade;
    }
    public Prioridade getPrioridade() {
        return prioridade;
    }

    

}
