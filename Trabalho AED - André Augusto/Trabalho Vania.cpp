#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <unistd.h>
#include <cstring>
#include <fstream>

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!VÂNIA: RODAR PROGRAMA NO DEV C++!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!VÂNIA: RODAR PROGRAMA NO DEV C++!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!VÂNIA: RODAR PROGRAMA NO DEV C++!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!VÂNIA: RODAR PROGRAMA NO DEV C++!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!VÂNIA: RODAR PROGRAMA NO DEV C++!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!VÂNIA: RODAR PROGRAMA NO DEV C++!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!VÂNIA: RODAR PROGRAMA NO DEV C++!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

using namespace std;

struct Cadastro
{
	string codigo;
	string ano;
	string km;
	string motor;
	string preco;
	string marca;
	string modelo;
	string categoria;
	string status;
};

struct Locacao
{
	string codigo;
	string nomeloc;
};


void RegLoc(Cadastro *cad, Locacao *loc)
{
  system("CLS");
	string cod;
	int j = 1;
	for(int i=0; i<50; i++)
	{
		if(cad[i].codigo != "")
		{
				cout << "Veículo: " << j << endl;
				cout << "Código.: " << cad[i].codigo << endl;
				cout << "Marca..: " << cad[i].marca << endl;
				cout << "Modelo.: " << cad[i].modelo << endl;
				cout << "------------------------------" << endl;
				j++;
  		}
	}
	cout << "Digite o código do veículo que deseja locar: ";
	cin >> cod;
  for(int i=0; i<50; i++)
  {
      if(cad[i].codigo == cod)
	  {
		     for(int j=0; j<50; j++)
		{
          if(loc[j].codigo == "")
		  {
            cout <<"Digite o nome do locatário: ";
            cin >> loc[j].nomeloc;
            cad[i].status = "Locado";
            loc[j].codigo = cod;
            cout << "Locação concluída!!!" << endl;
          }
        }
      }
  }
}

void RegDev(Cadastro *cad, Locacao  *loc){
  string cod;
  for(int i=0; i<50; i++)
  {
    if(loc[i].codigo != "")
	{
      cout << "Código do veículo: " << loc[i].codigo << endl;
      cout << "Nome do locatário: " << loc[i].nomeloc << endl;
      cout << "----------------------------------" << endl;
    }
  }
  cout << "Digite o código do veículo devolvido: ";
  cin >> cod;
  for(int i=0; i<50; i++)
  {
    if(loc[i].codigo == cod)
	{
      loc[i].codigo = "";
      loc[i].nomeloc = "";
      for(int j=0; j<50; j++)
	  {
        if(cad[i].codigo == cod)
		{
        	cad[i].status = "Disponível";
        }
      }
    	cout << "Devolução Concluída!";
    }
  }
}

void ConsLoc(Locacao *loc)
{
  for(int i=0; i<50; i++)
  {
        if(loc[i].codigo != "")
		{
        	cout << "Código: " << loc[i].codigo << endl;
			cout << "Nome..: "  << loc[i].nomeloc << endl;
        	cout << "------------------------------------"<<endl;
        }
  }
}

int main()
{
    setlocale(LC_ALL,"portuguese");
    
    Cadastro cad[50];
    Locacao loc[50];
    int menu, cat, stat, quantv=0, pvetor = -1, consulta, x=0, codloc, a=0, b=0;
	char res, cadastradnv;
	string marca, categoria, status, alteracad;
	string motor;
	fstream arq;
    fstream arq2;
    
     //##############LABEL PARA VOLTAR AO MENU##################
     
	arq.open("cadastro.txt",ios_base::in);
    if(!arq)
	{
        cout << "O arquivo esta sendo criado!";
        arq.open("cadastro.txt",ios_base::out);
        arq.close();
        system("CLS");
    }
    else
	{
        while(!arq.eof())
		{
            getline(arq,cad[a].marca);
            getline(arq,cad[a].modelo);
            getline(arq,cad[a].categoria);
            getline(arq,cad[a].status);
            getline(arq,cad[a].codigo);
            getline(arq,cad[a].motor);
            getline(arq,cad[a].ano);
            getline(arq,cad[a].km);
            getline(arq,cad[a].preco);
            a++;
        }
        arq.close();
    }
    arq2.open("locacoes.txt",ios_base::in);
    if(!arq2)
	{
        cout << "O arquivo está sendo criado!";
        arq2.open("locacoes.txt",ios_base::out);
        arq2.close();
        system("CLS");
    }
    else{
        while(!arq2.eof())
		{
            getline(arq2,loc[b].nomeloc);
            /*getline(arq2,loc[b].codigo);*/
            b++;
        }
        arq2.close();
    }
	
	restart:
	system("cls");

    //##############MENU PRINCIPAL##################
	cout << "#######LOCADORA DE CARROS#######\n" << endl;
    cout << "O que você deseja fazer?\n" << endl;
    cout << "1. Cadastrar veículo." << endl;
    cout << "2. Editar cadastro." << endl;
    cout << "3. Registrar locação." << endl;
    cout << "4. Registrar devolução." << endl;
    cout << "5. Consultar veículos." << endl;
    cout << "6. Consultar locações em andamento." << endl;
    cout << "7. Sair do programa.\n" << endl;
    cin >> menu;

    switch (menu){
case 1:
    inicio:
    system("cls");

	int cont;
	
	 //##############LABEL PARA CADASTRAR OUTRO VEICULO##################
	voltacont:
	cout << "#######CADASTRO DE VEÍCULOS#######\n" << endl;
	cout << "Quantos veículos você deseja cadastrar?";
	cin >> cont;
		 //##############TESTA O VALOR DIGITADO##################
		if (cont<=0)
		{
			cout << "Valor inválido.";
			goto voltacont;
		}else if(cont == 0){	
			goto restart;
		}
		
	 //##############SALVA OS DADOS DIGITADOS NO CADASTRO##################
	for(int i=0; i<cont; i++)
	{
	cout << "Agora você irá digitar os dados do veículo que deseja cadastrar: \n" << endl;
    cout << "Codigo do veículo (Apenas números): ";
	cin.ignore();
	cin >> cad[quantv+1].codigo;
    cout << "Marca do veículo: ";
    cin.ignore();
	getline(cin, cad[quantv+1].marca);
    cout << "Modelo do veículo: ";
	getline(cin, cad[quantv+1].modelo);
    cout << "Motor do veículo (Exemplo: 1.0 / 1.6): ";
	cin >> cad[quantv+1].motor;
    cout << "Ano do veículo (Exemplo: 2019 / 1990): ";
    cin.ignore();
	cin >> cad[quantv+1].ano;
    cout << "Quilometragem do veículo: ";
    cin.ignore();
	cin >> cad[quantv+1].km;
    cout << "Categoria do veículo:\n[1]Econômico\n[2]Intermediário\n[3]Luxuoso\n";
    catres: //<<<<<<<<<<<<<<<<<LABEL PARA DIGITAR DNV##################
    cin >> cat;
        switch (cat)
        {
        case 1:
        cad[quantv+1].categoria = "Econômico";
        break;

        case 2:
        cad[quantv+1].categoria = "Intermediário";
        break;

        case 3:
        cad[quantv+1].categoria = "Luxuoso";
        break;

        default:
            cout << "Opção inválida, digite a categoria novamente.\n";
            goto catres;

        } //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<FIM DO CASE DE CATEGORIA##################

        cout << "Preço de locação: ";
        cin.ignore();
		cin >> cad[quantv+1].preco;
        cout << "Status do veículo:\n[1]Disponível\n[2]Locado\n[3]Manutenção\n"; //<<<<<<<<<<<<<<<<<<<CASE DE STATUS DO VEICULO##################
		statres: //<<<<<<<<<<<<<<<<<<<<<<<LABEL PARA DIGITAR DNV##################
        cin >> stat;
        switch (stat)
        {
        case 1:
        cad[quantv+1].status = "Disponível";
        break;

        case 2:
        cad[quantv+1].status = "Locado";
        break;

        case 3:
        cad[quantv+1].status = "Manutenção";
        break;

        default:
            cout << "Opção inválida, digite a categoria novamente.\n";
            goto statres;
            break;
        }
        quantv++; //<<<<<<<<<<<<<<<<INCREMENTA O VETOR PARA NAO SALVAR POR CIMA##################
        
        arq.open("cadastro.txt",ios_base::in);
    	if(!arq)
		{
        cout << "O arquivo esta sendo criado!";
        arq.open("cadastro.txt",ios_base::out);
        arq.close();
        system("CLS");
		}
		
		for(int z=0; z<50; z++)
		{
        	
		}
}

        cout << "Veículo cadastrado com sucesso!!!\n" << endl;
        cout << "Digite qualquer tecla para voltar ao menu." << endl;
        cin >> cadastradnv;
            if (cadastradnv == 's' or cadastradnv == 'S'){
                goto restart;
            }else {
               goto restart;
            }

case 2:
     //##############LABEL VOLTA PARA A PESQUISA DE EDITAR CADASTRO##################
	voltapesquisa:
	system("cls");
    	
		cout << "#######EDITOR DE CADASTRO#######\n" << endl;
		cout << "Digite o código do veículo que deseja editar: ";
		cin >> alteracad;
		
		
		 //##############ACHA POSIÇÃO DO CÓDIGO QUE VAI SER ALTERADO##################
		for(int i=0; i<50; i++)
		{
			if(cad[i].codigo == alteracad)
			{
				pvetor = i;
			}		
		}
		
			if(pvetor != -1)
			{
				int trocacod, alteradados, novacat, novostatus;
				
				cout << "Qual dado você gostaria de alterar?" << endl;
				cout << "[1]Marca" << endl;
				cout << "[2]Modelo" << endl;
				cout << "[3]Motor" << endl;
				cout << "[4]Ano" << endl;
				cout << "[5]Quilometragem" << endl;
				cout << "[6]Categoria" << endl;
				cout << "[7]Preço" << endl;
				cout << "[8]Status" << endl;
				cin >> alteradados;
				
				switch (alteradados)
			    {
			        //##############ALTERA MARCA##################
				    case 1:
				        cout << "Marca atual do veículo: " << cad[pvetor].marca << endl;
						cout << "Digite a nova marca: ";
						cin.ignore();
						getline(cin, cad[pvetor].marca);
						cout << "A marca foi alterada com sucesso!" << endl;
						cout << "Você será redirecionado para o menu em 5 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 4 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 3 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 2 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 1 segundo..." << endl;
						sleep(1);
					goto restart;
			        break;
			
			         //##############ALTERA MODELO##################
					case 2:
			       		cin.ignore();
						cout << "Modelo atual do veículo: " << cad[pvetor].modelo << endl;
						cout << "Digite o novo modelo: ";
						getline(cin, cad[pvetor].modelo);
						cout << "O modelo foi alterado com sucesso!" << endl;
						cout << "Você será redirecionado para o menu em 5 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 4 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 3 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 2 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 1 segundo..." << endl;
						sleep(1);
					goto restart;
			        break;
			
			         //##############ALTERA MOTOR##################
					case 3:
			        	cout << "Motor atual do veículo: " << cad[pvetor].motor << endl;
						cout << "Digite o novo motor: ";
						cin.ignore();
						cin >> cad[pvetor].motor;
						cout << "O motor foi alterado com sucesso!" << endl;
						cout << "Você será redirecionado para o menu em 5 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 4 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 3 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 2 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 1 segundo..." << endl;
						sleep(1);
					goto restart;
			        break;
			        
			         //##############ALTERA ANO##################
					case 4:
			        	cout << "Ano atual do veículo: " << cad[pvetor].ano << endl;
						cout << "Digite o novo ano: ";
						cin >> cad[pvetor].ano;
						cout << "O ano foi alterado com sucesso!" << endl;
						cout << "Você será redirecionado para o menu em 5 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 4 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 3 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 2 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 1 segundo..." << endl;
						sleep(1);
					goto restart;
			        break;
			        
			        //##############ALTERA QUILOMETRAGEM##################
					case 5:
			        	cout << "Quilometragem atual do veículo: " << cad[pvetor].km << endl;
						cout << "Digite a nova quilometragem: ";
						cin >> cad[pvetor].km;
						cout << "A quilometragem foi alterada com sucesso!" << endl;
						cout << "Você será redirecionado para o menu em 5 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 4 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 3 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 2 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 1 segundo..." << endl;
						sleep(1);
					goto restart;
			        break;
			        
			        //##############ALTERA CATEGORIA##################
				    case 6:
			        	cout << "Categoria atual do veículo: " << cad[pvetor].categoria << endl;
						cout << "Qual a nova categoria que você deseja colocar?" << endl;
						cout << "[1]Econômico" << endl;
						cout << "[2]Intermediário" << endl;
						cout << "[3]Luxuoso" << endl;
						cin >> novacat;
							
							switch (novacat)
						    {
						        case 1:
							    	cad[pvetor].categoria = "Econômico";	
						        break;
						        
						        case 2:
							    	cad[pvetor].categoria = "Intermediário";	
						        break;
						        
						        case 3:
							    	cad[pvetor].categoria = "Luxuoso";	
						        break;
							}
						
						cout << "A categoria foi alterada com sucesso!" << endl;
						cout << "Você será redirecionado para o menu em 5 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 4 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 3 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 2 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 1 segundo..." << endl;
						sleep(1);
					goto restart;
			        break;
			        
			         //##############ALTERA PREÇO##################
					case 7:
			        	cout << "Preço atual do veículo: " << cad[pvetor].preco << endl;
						cout << "Digite o novo preço: ";
						cin >> cad[pvetor].preco;
						cout << "O preco foi alterado com sucesso!" << endl;
						cout << "Você será redirecionado para o menu em 5 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 4 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 3 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 2 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 1 segundo..." << endl;
						sleep(1);
					goto restart;
			        break;
			        
			         //##############ALTERA STATUS##################
					case 8:
			        	cout << "Status atual do veículo: " << cad[pvetor].status << endl;
						cout << "Qual o novo status que você deseja colocar?" << endl;
						cout << "[1]Disponível" << endl;
						cout << "[2]Locado" << endl;
						cout << "[3]Manutenção" << endl;
						cin >> novostatus;
							
							switch (novostatus)
						    {
						        case 1:
							    	cad[pvetor].status = "Disponível";	
						        break;
						        
						        case 2:
							    	cad[pvetor].status = "Locado";	
						        break;
						        
						        case 3:
							    	cad[pvetor].status = "Manutenção";	
						        break;
							}
						
						cout << "O status foi alterado com sucesso!" << endl;
						cout << "Você será redirecionado para o menu em 5 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 4 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 3 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 2 segundos..." << endl;
						sleep(1);
						cout << "Você será redirecionado para o menu em 1 segundo..." << endl;
						sleep(1);
					goto restart;
			        break;
			    }
				
			}
			else  //##############CASO O CÓDIGO DIGITADO FOR INVÁLIDO##################
			{
				cout << "Código não encontrado." << endl;
				cout << "Você poderá pesquisar novamente em 5 segundos..." << endl;
				cout << "Você será redirecionado em 5 segundos..." << endl;
				sleep(1);
				cout << "Você será redirecionado em 4 segundos..." << endl;
				sleep(1);
				cout << "Você será redirecionado em 3 segundos..." << endl;
				sleep(1);
				cout << "Você será redirecionado em 2 segundos..." << endl;
				sleep(1);
				cout << "Você será redirecionado em 1 segundo..." << endl;
				sleep(1);
				goto voltapesquisa;
				break;
			}

case 3:	
	{
    RegLoc(cad, loc);
    goto restart;
	break;
	}
    
case 4:
    {
	    RegDev(cad, loc);
	    goto restart;
	    break;
	}

case 5:
    voltaconsulta:
	system("cls");
    cout << "#######CONSULTAR VEÍCULOS#######" << endl;
	cout << "Como você deseja fazer a consulta?" << endl;
    cout << "[1]Todos" << endl;
    cout << "[2]Marca" << endl;
    cout << "[3]Motor" << endl;
    cout << "[4]Categoria" << endl;
    cout << "[5]Status" << endl;
	cin >> consulta;
	
switch(consulta)
{
    cadastradnv = 0;
	case 1:
      
	  system("cls");
      cout << "#######LISTA DE TODOS OS VEÍCULOS CADASTRADOS#######" << endl;
	  
	  for(int i=1; i<quantv+1; i++)
		{
		if(cad[i].codigo != "")
		{	
        	cout << "Código.......: " << cad[i].codigo << endl;
			cout << "Marca........: " << cad[i].marca << endl;
			cout << "Modelo.......: " << cad[i].modelo << endl;
			cout << "Motor........: " << cad[i].motor << endl;
			cout << "Ano..........: " << cad[i].ano << endl;
			cout << "Quilometragem: " << cad[i].km << endl;
       		cout << "Categoria....: " << cad[i].categoria << endl;
			cout << "Preço........: " << cad[i].preco << endl;
			cout << "Status.......: " << cad[i].status << endl;
        	cout << "------------------------------------" << endl;
    	}
      }
      cout << "Digite qualquer tecla para voltar ao menu." << endl;
        cin >> cadastradnv;
            if (cadastradnv == 's' or cadastradnv == 'S'){
                goto restart;
            }else {
               goto restart;
            }
    break;
    
    case 2:
    
	system("cls");
	cout << "Digite a marca que deseja consultar: " << endl;
	cout << "OBS: DEVE SER DIGITADO EXATAMENTE IGUAL AO CADASTRO!!!";
    cin >> marca;
    for(int i=1; i<quantv+1; i++)
	{
		if(cad[i].marca == marca)
		{	
        	cout << "Código.......: " << cad[i].codigo << endl;
			cout << "Marca........: " << cad[i].marca << endl;
			cout << "Modelo.......: " << cad[i].modelo << endl;
			cout << "Motor........: " << cad[i].motor << endl;
			cout << "Ano..........: " << cad[i].ano << endl;
			cout << "Quilometragem: " << cad[i].km << endl;
       		cout << "Categoria....: " << cad[i].categoria << endl;
			cout << "Preço........: " << cad[i].preco << endl;
			cout << "Status.......: " << cad[i].status << endl;
        	cout << "------------------------------------" << endl;
    	}
      }
	    cout << "Digite qualquer tecla para voltar ao menu." << endl;
        cin >> cadastradnv;
            if (cadastradnv == 's' or cadastradnv == 'S'){
                goto restart;
            }else {
               goto restart;
            }
		break;
    
    case 3:
    system("cls");
    cout << "Digite o motor que deseja consultar: " << endl;
	cout << "OBS: DEVE SER DIGITADO EXATAMENTE IGUAL AO CADASTRO!!!" << endl;
    cin >> motor;
    for(int i=1; i<quantv+1; i++)
	{
		if(cad[i].motor == motor)
		{	
        	cout << "Código.......: " << cad[i].codigo << endl;
			cout << "Marca........: " << cad[i].marca << endl;
			cout << "Modelo.......: " << cad[i].modelo << endl;
			cout << "Motor........: " << cad[i].motor << endl;
			cout << "Ano..........: " << cad[i].ano << endl;
			cout << "Quilometragem: " << cad[i].km << endl;
       		cout << "Categoria....: " << cad[i].categoria << endl;
			cout << "Preço........: " << cad[i].preco << endl;
			cout << "Status.......: " << cad[i].status << endl;
        	cout << "------------------------------------" << endl;
    	}
      }
	    cout << "Digite qualquer tecla para voltar ao menu." << endl;
        cin >> cadastradnv;
            if (cadastradnv == 's' or cadastradnv == 'S'){
                goto restart;
            }else {
               goto restart;
            }
		break;
    
    case 4:
    system("cls");
    cout << "Digite a categoria que deseja consultar:" << endl;
    cout << "Opções: Econômico, Intermediário e Luxuoso" << endl;
	cout << "OBS: DEVE SER DIGITADO EXATAMENTE IGUAL AO EXEMPLO ACIMA(com acentos)!!!" << endl;
    cin >> categoria;
    for(int i=1; i<quantv+1; i++)
	{
		if(cad[i].categoria == categoria)
		{	
        	cout << "Código.......: " << cad[i].codigo << endl;
			cout << "Marca........: " << cad[i].marca << endl;
			cout << "Modelo.......: " << cad[i].modelo << endl;
			cout << "Motor........: " << cad[i].motor << endl;
			cout << "Ano..........: " << cad[i].ano << endl;
			cout << "Quilometragem: " << cad[i].km << endl;
       		cout << "Categoria....: " << cad[i].categoria << endl;
			cout << "Preço........: " << cad[i].preco << endl;
			cout << "Status.......: " << cad[i].status << endl;
        	cout << "------------------------------------" << endl;
    	}
      }
	    cout << "Digite qualquer tecla para voltar ao menu." << endl;
        cin >> cadastradnv;
            if (cadastradnv == 's' or cadastradnv == 'S'){
                goto restart;
            }else {
               goto restart;
            }
		break;
    
    case 5:
    system("cls");
    cout << "Digite o status que deseja consultar:" << endl;
    cout << "Opções: Disponível, Locado e Manutenção" << endl;
	cout << "OBS: DEVE SER DIGITADO EXATAMENTE IGUAL AO EXEMPLO ACIMA(com acentos)!!!" << endl;
    cin >> status;
    for(int i=1; i<quantv+1; i++)
	{
		if(cad[i].status == status)
		{	
        	cout << "Código.......: " << cad[i].codigo << endl;
			cout << "Marca........: " << cad[i].marca << endl;
			cout << "Modelo.......: " << cad[i].modelo << endl;
			cout << "Motor........: " << cad[i].motor << endl;
			cout << "Ano..........: " << cad[i].ano << endl;
			cout << "Quilometragem: " << cad[i].km << endl;
       		cout << "Categoria....: " << cad[i].categoria << endl;
			cout << "Preço........: " << cad[i].preco << endl;
			cout << "Status.......: " << cad[i].status << endl;
        	cout << "------------------------------------" << endl;
    	}
      }
	    cout << "Digite qualquer tecla para voltar ao menu." << endl;
        cin >> cadastradnv;
            if (cadastradnv == 's' or cadastradnv == 'S'){
                goto restart;
            }else {
               goto restart;
            }
		break;
		
		default:
			cout << "Opção não encontrada." << endl;
				cout << "Você poderá pesquisar novamente em 5 segundos..." << endl;
				cout << "Você será redirecionado em 5 segundos..." << endl;
				sleep(1);
				cout << "Você será redirecionado em 4 segundos..." << endl;
				sleep(1);
				cout << "Você será redirecionado em 3 segundos..." << endl;
				sleep(1);
				cout << "Você será redirecionado em 2 segundos..." << endl;
				sleep(1);
				cout << "Você será redirecionado em 1 segundo..." << endl;
				sleep(1);
				goto voltaconsulta;
				break;
}

case 6:
    {
    ConsLoc(loc);
    goto restart;
	break;
	}

case 7:
    
	arq.open("cadastro.txt", ios_base::out);
                for(int i = 0; i < 50; i++)
				{
                    if(cad[i].marca != "")
					{
                        arq << cad[i].marca << endl;
                        arq << cad[i].modelo << endl;
                        arq << cad[i].categoria << endl;
                        arq << cad[i].status << endl;
                        arq << cad[i].codigo << endl;
                        arq << cad[i].motor << endl;
                        arq << cad[i].ano << endl;
                        arq << cad[i].km << endl;
                        arq << cad[i].preco << endl;
                    }
                }
                arq.close();

                arq2.open("locacoes.txt", ios_base::out);
                for(int i = 0; i < 50; i++)
				{
                    if(loc[i].nomeloc != "")
					{
                        arq2 << loc[i].nomeloc << endl;
                        arq2 << loc[i].codigo << endl;
                    }
                }
                arq2.close();
	system("exit");
    break;

default:
	system("cls");
	cout << "Opção inválida\n";
	cout << "Deseja voltar ao menu? [s]/[n]\n";
    cin >> res;

    if (res == 's' or res == 'S'){
        goto restart;
    }else {
       system("pause");
    }
}
	return 0; 
}
     
