#include <stdio.h>
#include <locale.h>

float salarioBruto(float n1, float n2){
    float salario = n1*n2;
    printf("Salário Bruto: (R$%.2f/h * %.2fh)    :R$%.2f\n", n1, n2, salario);
    return salario;
}

float impostoRenda(float salario)
{
    float valor = 0;
    if(salario > 1000){
        valor = salario * 0.1;
    }
    printf("(-) IR (10%%): R$%.2f", valor);
    return valor;
}

void quebraLinha(){
    printf("-=-=-=-=-=-=-=- Sistema de cálculo de Impostos  -=-=-=-=-=-=-=-\n");
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");
    float valor_hora;
    float hora_trabalhada;
    float salario_bruto, ir;
    quebraLinha();
    printf(" - Sistema destinado para cálculos de INSS, FGTS E Imposto de Renda (IR) - \n");
    quebraLinha();
    printf("Informe o Valor da Hora Trabalhada: ");
    scanf("%f", &valor_hora);
    printf("Informe a quantidade de Horas Trabalhadas: ");
    scanf("%f", &hora_trabalhada);

    quebraLinha();
    printf("\n-=-=-=-=-=-=-=-  Calculando...  -=-=-=-=-=-=-=-\n");
    salario_bruto = salarioBruto(valor_hora, hora_trabalhada);
    ir = impostoRenda(salario_bruto);
    return 0;
}
