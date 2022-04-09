var dados = [];
var posv =0;

function OpcoesJogo(){
	dados[posv]= new Object();
	dados[posv].grid = document.forms["formulario"].elements["grid"].value;
	dados[posv].nbombas = document.forms["formulario"].elements["nbombas"].value;
	dados[posv].modo = document.forms["formulario"].elements["modo"].value;

}


