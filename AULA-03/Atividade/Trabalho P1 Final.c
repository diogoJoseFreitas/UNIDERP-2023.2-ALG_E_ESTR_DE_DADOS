#include <stdio.h>
#include <locale.h>

float salario(float n1, float n2) // função para calculo do salario bruto
{
	float resultado = n1 * n2;
	return (resultado);
}
float inss(float n1) // função para calculo do inss
{
	float resultadoi = n1 * 0.1;
	return (resultadoi);
}
float fgts(float n1) // função para calculo do fgts
{
	float resultadof = n1 * 0.11;
	return (resultadof);
}
float ir(float n1) // função para calculo do imposto de renda
{
	float imposto = n1 * 0.1;
	return (imposto);
}
float descontos(float n1, float n2) // função para calculo dos descontos
{
	float desconto = n1 + n2; 
	return (desconto);
}
float liquido(float n1, float n2) // função para calculo do salario liquido
{
	float resultadol = n1 - n2;
	return (resultadol);
}
int main(){
	setlocale(LC_ALL, "");
	float a, b, resultado, imposto=0, resultadoi, resultadol, desconto, resultadof;

	printf("Informe a quantidade de horas trabalhadas: \n");
	scanf("%f", &a);
	
	printf("Informe o valor por hora trabalhada: \n");
	scanf("%f", &b);	
	
	resultado = salario(a, b); // função onde é calculado o salario do trabalhador, horas trabalhadas x valor da hora
	
	
	if(resultado>1000){ // aqui ele vai testar se o resultado do salario é maior que mil, se for ele vai calcular o imposto de renda
		imposto = ir(resultado); // função onde é calculado o imposto de renda (10%) a ser descontado se o salário bruto passar dos mil reais
	}
	else{
		printf("\n Não é nescessário descontar o imposto de renda:"); //caso o valor seja abaixo de mil reais, não é calculado o imposto de renda
	}
	
	resultadoi = inss(resultado); // função onde é calculado o valor do INSS(10%) a ser descontado do salário bruto
	resultadof = fgts(resultado); // função onde é calculado o valor do FGTS(11%) a ser descontado do salário bruto
	desconto = descontos(imposto, resultadoi); //função onde é calculado o total de descontos
	resultadol = liquido(resultado, desconto); //função onde é calculado o salário liquido, realizando a subtração entre o salário bruto e os descontos
	
	printf("\n O salario bruto é: R$ %.2f", resultado); //imprime o salario bruto
	printf("\n (-) IR (10%%): R$ %.2f", imposto); //imprime o valor do imposto de renda a ser descontado
	printf("\n (-) INSS (10%%): R$ %.2f", resultadoi);  //imprime o valor do inss a ser descontado
	printf("\n FGTS (11%%): R$ %.2f", resultadof); //imprime o valor do fgts a ser descontado
	printf("\n Total de descontos: R$ %.2f", desconto);  //imprime o total de descontos
	printf("\n Salário liquido: R$ %.2f", resultadol);  //imprime o salario liquido
	
	return 0;
}
