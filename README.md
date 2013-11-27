MC504-Projeto2
==============

Projeto feito por Hélder Lima da Rocha e Lucas Mageste de Almeida, graduandos em Engenharia Elétrica pela UNICAMP para a disciplina de MC504 (Sistemas Operacionais).


/*Objetivo*/

O obejetivo do projeto é realizar uma chamada de sistema que
trabalhe com algum elemento do sistema operacional(trabalhamos com
processos).

/*Descrição da chamada*/

Para tal criamos uma chamada de sistema e a utilizamos em uma
chamada de usuário. O objetivo da chamada de sistema é testar
sinais que finalizam processos. A chamada manda um sinal SIGTERM 
e espera a resposta por no máximo 5 segundos, caso o processo
não tenha parado de executar é enviado um sinal SIGKILL.

/*Descrição do teste*/

Para testar a chamada de sistema é necessário executar o arquivo
chamadaUsuario.c. Este recebe dois parâmetros, o Pid do processo 
que deve ser morto e o tempo de espera de resposta do SIGTERM(em milisegundos).
Um exemplo de execução seria ./chamadaUsuario 702 5000.
Foram utilizados dois códigos auxiliares, bobo.c e malandro.c, ambos
devem ser executados em background e devem ter seu Pid enviado na
chamada de usuario. O processo referente a bobo.c deve ser morto
pelo SIGTERM, já malandro.c tem um tratador para este sinal e será
finalizado apenas quando o SIGKILL for enviado.

/*Instalação dos arquivos*/

O arquivo chamadaSistema.c deve ser adicionado às chamadas padrão de sistema do linux no kernel com índice 351.
Caso já exista uma chamada com tal índice, ou deseja-se adicionar a chamada em outro índice, deve-se modificar o arquivo chamadaUsuario.c na linha 17 para que a chamada de sistema 'X' seja chamada ao invés da 351.
Após adicionado nossa chamada de sistema, deve-se executar o arquivo chamadaUsuario.c conforme supracitado para o funcionamento correto.
Os arquivos bobo.c e malandro.c, como já foi previamente dito, são apenas auxiliares para testar a chamada de sistema.

