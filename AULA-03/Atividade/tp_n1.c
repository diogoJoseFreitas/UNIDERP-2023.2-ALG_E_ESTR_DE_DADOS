#include <stdio.h>
#include <locale.h>

struct Funcionario{
    // Estrutura base de dados do funcionário para facilitar implementação.
    float valor_hora;
    float hora_trabalhada;
};
typedef struct Funcionario Funcionario;


float calcSalarioBruto(float n1, float n2) // Função destinada ao cálculo do salário bruto
{
    float salario = n1*n2;
    printf("Salário Bruto (R$%.2f/h * %.2fh): R$%.2f\n", n1, n2, salario);
    return salario;
}

float calcImpostoRenda(float salario) // Função destinada ao cálculo do Imposto de Renda
{
    float valor = 0;
    if(salario > 1000){
        valor = salario * 0.1;
        printf("(-) IR (10%%): R$%.2f\n", valor);
    }
    else{
        printf("(-) IR (isento):   -\n");
    }
    return valor;
}

float calcINSS(float salario) // Função destinada ao cálculo do Imposto de INSS
{
    float valor;
    valor = salario * 0.1;
    printf("(-) INSS (10%%): R$%.2f\n", valor);
    return valor;
}

void calcFGTS(float salario) // Função destinada ao cálculo do FGTS
{
    float valor;
    valor = salario * 0.11;
    printf("FGTS (11%%): R$%.2f\n", valor);
}

float calcTotalDesconto(float ir, float inss) // Função destinada ao cálculo do Desconto Total do salário
{
    float valor;
    valor = ir + inss;
    printf("Total de descontos: R$%.2f\n", valor);
    return valor;
}

void calcSalarioLiquido(float salario, float desconto) // Função destinada ao cálculo do Salário Líquido, isto é, com os impostos abatidos.
{
    float valor;
    valor = salario - desconto;
    printf("Salário Líquido: R$%.2f\n", valor);
    return valor;

}

void quebraLinha() // Função que, apenas por fins estéticos pula algumas linhas e adiciona o separador horizontal
{
    printf("\n\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-\n");
    printf("\n\n");
}

void calcImpostos(Funcionario* func) 
// Função responsável pela manipulação das funções superioires para responder as perguntas de negócio. 
// Foi desvinculado da função main para que a mesma permaneça apenas com implementações de acesso necessário para o restante do código.
{
    float salario_bruto, ir, inss, total_desconto;

    quebraLinha();
    printf("-=-=-=-=-=-=-=-=-=-=- Sistema de Cálculo de Impostos -=-=-=-=-=-=-=-=-=-\n");
    printf("- Sistema destinado para cálculos de INSS, FGTS E Imposto de Renda(IR) -\n");
    quebraLinha();
    printf("Informe o Valor da Hora Trabalhada: ");
    scanf("%f", &func->valor_hora);
    printf("Informe a quantidade de Horas Trabalhadas: ");
    scanf("%f", &func->hora_trabalhada);

    quebraLinha();
    quebraLinha();
    printf("                               Calculando...                            ");
    quebraLinha();
    salario_bruto = calcSalarioBruto(func->valor_hora, func->hora_trabalhada);
    ir = calcImpostoRenda(salario_bruto);
    inss = calcINSS(salario_bruto);
    calcFGTS(salario_bruto);
    total_desconto = calcTotalDesconto(ir, inss);
    calcSalarioLiquido(salario_bruto, total_desconto);
    quebraLinha();
    
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");
    Funcionario func;

    calcImpostos(&func);
    return 0;
}
