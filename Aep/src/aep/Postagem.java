package aep;

import java.util.Date;

import aep.valueObjects.Descricao;

public class Postagem {
    
    private Descricao descricao;
    private Date data;
    private int idPostagem;

    //Relações
    private Usuario usuario;    //Quem fez a postagem
    private Trabalho trabalho;  //Sobre qual trabalho

    public Postagem(String descricao, Date data, int idPostagem, Usuario usuario, Trabalho trabalho) {
        this.descricao = new Descricao(descricao);
        setData(data);
        setIdPostagem(idPostagem);
        setUsuario(usuario);
        setTrabalho(trabalho);
    }



    public void setTrabalho(Trabalho trabalho) {
        this.trabalho = trabalho;
    }
    public Trabalho getTrabalho() {
        return trabalho;
    }
    public void setUsuario(Usuario usuario) {
        this.usuario = usuario;
    }
    public Usuario getUsuario() {
        return usuario;
    }


    public Date getData() {
        return data;
    }

    public void setData(Date data) {
        this.data = data;
    }

    public int getIdPostagem() {
        return idPostagem;
    }

    public void setIdPostagem(int idPostagem) {
        this.idPostagem = idPostagem;
    }


    


}
