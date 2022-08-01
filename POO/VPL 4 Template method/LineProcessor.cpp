#include <regex>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

#include "LineProcessor.hpp"

void LinePrinter::processaLinha(const std::string &str) {
  std::cout << str << std::endl;
}

bool ContadorPopRural::linhaValida(const std::string &str) const {
  // Neste exemplo usaremos expressoes regulares para verificar se uma linha
  // eh valida ou nao.
  //
  // Esta expressao regular eh formada por cinco partes. Cada uma dessas
  // partes eh um dos tres tipos de padrao regular abaixo:
  //
  // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
  // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
  // \\d+ eh qualquer sequencia de um ou mais digitos
  std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");

  // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
  // a expressao regular que acabamos de criar:
  return std::regex_match(str, regularExpr);
}

void ContadorPopRural::processaLinha(const std::string &str) {
  //
  // Em geral eh mais facil ler dados de uma string se a string eh transformada
  // em um objeto do tipo stringstream:
  std::stringstream ss(str);
  //
  // Iremos ler os dados da string nestas tres variaveis abaixo:
  std::string nomePais;
  unsigned populacao, percUrbana;
  //
  // Como sabemos que a linha contem string int int, podemos fazer a leitura
  // facilmente usando o operador de streaming:
  ss >> nomePais >> populacao >> percUrbana;
  //
  // Note que precisamos arredondar o valor que serah impresso. O arredondamento
  // serah feito via a funcao floor. Ou seja, decimais serao sempre
  // arredondados para baixo:
  unsigned popRural = floor(populacao - (populacao * (percUrbana/100.0)));
  //
  // Uma vez encontrados os valores que precisam ser impressos, seguimos o
  // modelo do enunciado do exercicio:
  std::cout << popRural << " pessoas vivem no campo no " << nomePais <<
    std::endl;
}

bool ContadorNumNaturais::linhaValida(const std::string &str) const {
  // TODO: Implemente este metodo
  std::regex integer("[[:digit:]]+");
  std::string number;
  bool isValid = true;

  for (auto c : str){
    number = c;
    if(!(std::regex_match(number, integer) || number == " ")){
      return false;
    }
  }
  
  return true;
}

void ContadorNumNaturais::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  int sum = 0;
  std::string number = "";
  for (auto c: str){
    if(isdigit(c))
      number += c;
    else{
      sum += std::stoi(number);
      number = "";
    }
  }

  sum += std::stoi(number);
  
  std::cout << sum << std::endl;
}

bool LeitorDeFutebol::linhaValida(const std::string &str) const {
  // TODO: Implemente este metodo

  std::string time1 = "";
  std::string gols1 = "";
  std::string time2 = "";
  std::string gols2 = "";
  int count = 1;
  int i = 0;

  std::string number = "";
  for (auto c: str){
    if(isalpha(c) || isdigit(c)){
      switch(count){
        case 1:
          time1 += c;
          break;

        case 2:
          gols1 += c;
          break;
        
        case 3:
          time2 += c;
          break;

        case 4:
          gols2 += c;
          break;
      }
    } else if (isalpha(str[i-1]) || isdigit(str[i-1])){
      count += 1;
    }
    i++;
  }

  std::regex integer("[[:digit:]]+");
  if(!(std::regex_match(gols1, integer) && std::regex_match(gols2, integer))){
    return false;
  }

  i = 0;
  while(time1[i]){
    if(!(isalpha(time1[i]) || time1[i] == ' '))
      return false;
    i++;
  }

  i=0;
  while(time2[i]){
    if(!(isalpha(time2[i]) || time2[i] == ' '))
      return false;
    i++;
  }

  return true;
}

void LeitorDeFutebol::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:

  std::string time1 = "";
  std::string gols1 = "";
  std::string time2 = "";
  std::string gols2 = "";
  int count = 1;
  int i = 0;


  std::string number = "";
  for (auto c: str){
    if(isalpha(c) || isdigit(c)){
      switch(count){
        case 1:
          time1 += c;
          break;

        case 2:
          gols1 += c;
          break;
        
        case 3:
          time2 += c;
          break;

        case 4:
          gols2 += c;
          break;
      }
    } else if (isalpha(str[i-1]) || isdigit(str[i-1])){
      count += 1;
    }
    i++;
  }

  if (stoi(gols1) > stoi(gols2))
    std::cout << "Vencedor: " << time1 << std::endl;
  else if (stoi(gols2) > stoi(gols1))
    std::cout << "Vencedor: " << time2 << std::endl;
  else
    std::cout << "Empate" << std::endl;
}

void ContadorDePalavras::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:

  int contWords = 0;
  bool isWord = 0;

  for(auto c : str){
    if(c != ' '){
      isWord = 1;
    } else if (isWord){
      contWords++;
      isWord = 0;
    }
  }
  contWords++;

  std::cout << contWords << std::endl;
}

bool InversorDeFrases::linhaValida(const std::string &str) const {
  // TODO: Implemente este metodo
  for(auto c: str){
    if(!(isalpha(c) || c == ' '))
      return false;
  }

  return true;
}

std::string invertWord(std::string str){
  std::reverse(str.begin(),str.end());
  return str;
}

void InversorDeFrases::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  
  std::string wordInverted = "";
  std::string strInverted = "";
  int i = str.size() - 1;

  while (i >= 0){
    if(str[i] != ' '){
      wordInverted += str[i];
    } else{
      strInverted += invertWord(wordInverted);
      strInverted += " ";
      wordInverted = "";
    }

    i--;
  }
  strInverted += invertWord(wordInverted);

  std::cout << strInverted << std::endl;
}

bool EscritorDeDatas::linhaValida(const std::string &str) const {
  std::string dateFormat = "\\s*\\d\\d?/\\d\\d?/\\d{4}";
  // TODO: Implemente este metodo
  // Note que você pode usar uma expressao regular como:
  // "\\s*\\d\\d?/\\d\\d?/\\d{4}" para saber se a linha eh valida:
  std::regex integer(dateFormat);
  if(std::regex_match(str, integer))
    return true;

  return false;
}

void EscritorDeDatas::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  // Lembre-se que as iniciais dos meses sao:
  // "Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out",
  // "Nov", e "Dez".
  std::string monthString = "";
  int monthNumber = 0;
  int i = 0;

  while(str[i] == ' '){
    i++;
  }
  while (str[i] != '/'){
    i++;
  }
  i++;
  while(str[i]){
    if (isdigit(str[i]))
      monthString += str[i];
    else
      break;
    i++;
  }
  
  monthNumber = stoi(monthString);

  switch (monthNumber)
  {
  case 1:
    std::cout << "Jan" << std::endl;
    break;
  
  case 2:
    std::cout << "Fev" << std::endl;
    break;
    
  case 3:
    std::cout << "Mar" << std::endl;
    break;
    
  case 4:
    std::cout << "Abr" << std::endl;
    break;
    
  case 5:
    std::cout << "Mai" << std::endl;
    break;
    
  case 6:
    std::cout << "Jun" << std::endl;
    break;
  
  case 7:
    std::cout << "Jul" << std::endl;
    break;
      
  case 8:
    std::cout << "Ago" << std::endl;
    break;
      
  case 9:
    std::cout << "Set" << std::endl;
    break;
      
  case 10:
    std::cout << "Out" << std::endl;
    break;
      
  case 11:
    std::cout << "Nov" << std::endl;
    break;
      
  case 12:
    std::cout << "Dez" << std::endl;
    break;
  }
}