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


    public EpiTrabalho(String funcao, String descricao, int idEquipamento, Prioridade prioridade) {
        setFuncao(funcao);
        this.descricao = new Descricao(descricao);
        setIdEquipamento(idEquipamento);
        setPrioridade(prioridade);

    }


    @Override
    public int hashCode() {
        return descricao.hashCode();
    }


    @Override
    public boolean equals(Object other) {
        if (other == null) {
            return false;
        }
        if (!(other instanceof EpiTrabalho)) {
            return false;
        }
        EpiTrabalho auxOther = (EpiTrabalho) other;
        if (this.descricao.equals(auxOther.descricao)) {
            return true;
        }
        return false;
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
