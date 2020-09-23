package aep;

import java.util.Date;
import java.util.ArrayList;
import java.util.List;

import aep.valueObjects.*;

public class Usuario {
    
    private Nome nome;
    private Email email;
    private Senha senha;
    private int idUsuario;
    
    //Relações
    private List<Postagem> postagens = new ArrayList<>();


    public Usuario(String nome, String email, String senha, int idUsuario) {
        this.nome = new Nome(nome);
        this.email = new Email(email);
        this.senha = new Senha(senha);
        this.idUsuario = idUsuario;
    }
   
    public void realizarPostagem(String descricao, Date data, int idPostagem, Trabalho trabalho) {
        Postagem auxPostagem = new Postagem(descricao, data, idPostagem, this, trabalho);
        postagens.add(auxPostagem);
        trabalho.getPostagens().add(auxPostagem);
    }


    public Nome getNome() {
        return nome;
    }

    public void setNome(Nome nome) {
        this.nome = nome;
    }

    public Email getEmail() {
        return email;
    }

    public void setEmail(Email email) {
        this.email = email;
    }

    public Senha getSenha() {
        return senha;
    }

    public void setSenha(Senha senha) {
        this.senha = senha;
    }

    public int getIdUsuario() {
        return idUsuario;
    }

    public void setIdUsuario(int idUsuario) {
        this.idUsuario = idUsuario;
    }


    


}
