#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

struct Hospede {
    string nome;
    string cpf;
    string telefone;
};

struct Quarto {
    int numero;
    int andar;
    string tipo;
    bool ocupado;
    Hospede hospede;
    int dias;
    double precoDiaria;
};

Quarto quartos[20];
double faturamento = 0;
int totalReservas = 0;

void inicializarQuartos() {
    // Quartos Simples (1-10)
    for(int i = 0; i < 10; i++) {
        quartos[i].numero = i + 1;
        quartos[i].andar = (i / 5) + 1;
        quartos[i].tipo = "Simples";
        quartos[i].ocupado = false;
        quartos[i].dias = 0;
        quartos[i].precoDiaria = 150.00;
        quartos[i].hospede.nome = "";
        quartos[i].hospede.cpf = "";
        quartos[i].hospede.telefone = "";
    }
    
    // Quartos Duplos (11-15)
    for(int i = 10; i < 15; i++) {
        quartos[i].numero = i + 1;
        quartos[i].andar = (i / 5) + 1;
        quartos[i].tipo = "Duplo";
        quartos[i].ocupado = false;
        quartos[i].dias = 0;
        quartos[i].precoDiaria = 250.00;
        quartos[i].hospede.nome = "";
        quartos[i].hospede.cpf = "";
        quartos[i].hospede.telefone = "";
    }
    
    // Suítes (16-20)
    for(int i = 15; i < 20; i++) {
        quartos[i].numero = i + 1;
        quartos[i].andar = (i / 5) + 1;
        quartos[i].tipo = "Suite";
        quartos[i].ocupado = false;
        quartos[i].dias = 0;
        quartos[i].precoDiaria = 450.00;
        quartos[i].hospede.nome = "";
        quartos[i].hospede.cpf = "";
        quartos[i].hospede.telefone = "";
    }
}

void mostrarMapaQuartos() {
    cout << "\n=== MAPA DE QUARTOS ===\n\n";
    
    for(int andar = 1; andar <= 4; andar++) {
        cout << "Andar " << andar << ":\n";
        cout << "----------------------------\n";
        
        for(int i = 0; i < 20; i++) {
            if(quartos[i].andar == andar) {
                cout << "Quarto " << quartos[i].numero << " [" << quartos[i].tipo << "] ";
                cout << (quartos[i].ocupado ? "[OCUPADO]" : "[LIVRE]") << "\n";
            }
        }
        cout << "----------------------------\n\n";
    }
}

void mostrarQuartosDisponiveis() {
    cout << "\n=== QUARTOS DISPONIVEIS ===\n";
    bool temDisponivel = false;
    
    for(int i = 0; i < 20; i++) {
        if(!quartos[i].ocupado) {
            cout << "Quarto " << quartos[i].numero << " [" << quartos[i].tipo 
                 << "] - R$ " << fixed << setprecision(2) << quartos[i].precoDiaria << "/diaria\n";
            temDisponivel = true;
        }
    }
    
    if(!temDisponivel) {
        cout << "Nenhum quarto disponivel!\n";
    }
}

bool validarCPF(string cpf) {
    if(cpf.length() != 11) return false;
    for(int i = 0; i < (int)cpf.length(); i++) {
        if(!isdigit(cpf[i])) return false;
    }
    return true;
}

void fazerCheckIn() {
    int numero;
    
    mostrarQuartosDisponiveis();
    
    cout << "\nDigite o numero do quarto: ";
    cin >> numero;
    
    if(numero < 1 || numero > 20) {
        cout << "Quarto invalido!\n";
        return;
    }
    
    int index = numero - 1;
    
    if(quartos[index].ocupado) {
        cout << "Quarto ja esta ocupado!\n";
        return;
    }
    
    cout << "\n=== DADOS DO HOSPEDE ===\n";
    cin.ignore();
    
    cout << "Nome completo: ";
    getline(cin, quartos[index].hospede.nome);
    
    cout << "CPF (apenas numeros): ";
    getline(cin, quartos[index].hospede.cpf);
    
    if(!validarCPF(quartos[index].hospede.cpf)) {
        cout << "CPF invalido! Usando CPF generico.\n";
        quartos[index].hospede.cpf = "00000000000";
    }
    
    cout << "Telefone: ";
    getline(cin, quartos[index].hospede.telefone);
    
    cout << "Quantidade de dias: ";
    cin >> quartos[index].dias;
    
    if(quartos[index].dias <= 0) {
        cout << "Numero de dias invalido! Usando 1 dia.\n";
        quartos[index].dias = 1;
    }
    
    double total = quartos[index].dias * quartos[index].precoDiaria;
    quartos[index].ocupado = true;
    faturamento += total;
    totalReservas++;
    
    cout << "\n=== CHECK-IN REALIZADO COM SUCESSO ===\n";
    cout << "Quarto: " << quartos[index].numero << "\n";
    cout << "Tipo: " << quartos[index].tipo << "\n";
    cout << "Hospede: " << quartos[index].hospede.nome << "\n";
    cout << "Total a pagar: R$ " << fixed << setprecision(2) << total << "\n";
    cout << "Valor da diaria: R$ " << quartos[index].precoDiaria << "\n";
}

void fazerCheckOut() {
    int numero;
    
    cout << "\n=== QUARTOS OCUPADOS ===\n";
    bool temOcupado = false;
    
    for(int i = 0; i < 20; i++) {
        if(quartos[i].ocupado) {
            cout << "Quarto " << quartos[i].numero << " - Hospede: " << quartos[i].hospede.nome << "\n";
            temOcupado = true;
        }
    }
    
    if(!temOcupado) {
        cout << "Nenhum quarto ocupado!\n";
        return;
    }
    
    cout << "\nDigite o numero do quarto para check-out: ";
    cin >> numero;
    
    if(numero < 1 || numero > 20) {
        cout << "Quarto invalido!\n";
        return;
    }
    
    int index = numero - 1;
    
    if(!quartos[index].ocupado) {
        cout << "Quarto nao esta ocupado!\n";
        return;
    }
    
    cout << "\n=== DETALHES DA ESTADIA ===\n";
    cout << "Hospede: " << quartos[index].hospede.nome << "\n";
    cout << "CPF: " << quartos[index].hospede.cpf << "\n";
    cout << "Telefone: " << quartos[index].hospede.telefone << "\n";
    cout << "Dias: " << quartos[index].dias << "\n";
    cout << "Valor pago: R$ " << fixed << setprecision(2) << (quartos[index].dias * quartos[index].precoDiaria) << "\n";
    
    char confirmar;
    cout << "\nConfirmar check-out? (s/n): ";
    cin >> confirmar;
    
    if(confirmar == 's' || confirmar == 'S') {
        quartos[index].ocupado = false;
        quartos[index].dias = 0;
        quartos[index].hospede.nome = "";
        quartos[index].hospede.cpf = "";
        quartos[index].hospede.telefone = "";
        cout << "Check-out realizado com sucesso!\n";
    } else {
        cout << "Check-out cancelado!\n";
    }
}

void mostrarRelatorio() {
    int ocupados = 0;
    int porTipo[3] = {0}; // 0:Simples, 1:Duplo, 2:Suite
    double faturamentoPorTipo[3] = {0};
    
    for(int i = 0; i < 20; i++) {
        if(quartos[i].ocupado) {
            ocupados++;
            
            if(quartos[i].tipo == "Simples") {
                porTipo[0]++;
                faturamentoPorTipo[0] += quartos[i].dias * quartos[i].precoDiaria;
            } else if(quartos[i].tipo == "Duplo") {
                porTipo[1]++;
                faturamentoPorTipo[1] += quartos[i].dias * quartos[i].precoDiaria;
            } else {
                porTipo[2]++;
                faturamentoPorTipo[2] += quartos[i].dias * quartos[i].precoDiaria;
            }
        }
    }
    
    cout << "\n=== RELATORIO GERAL DO HOTEL ===\n";
    cout << "================================\n";
    cout << "RESERVAS:\n";
    cout << "Total de reservas realizadas: " << totalReservas << "\n\n";
    
    cout << "OCUPACAO ATUAL:\n";
    cout << "Quartos ocupados: " << ocupados << "/20\n";
    cout << "Taxa de ocupacao: " << fixed << setprecision(1) << (ocupados * 100.0 / 20) << "%\n\n";
    
    cout << "DETALHAMENTO POR TIPO:\n";
    cout << "Simples: " << porTipo[0] << " ocupados - Faturamento: R$ " << fixed << setprecision(2) << faturamentoPorTipo[0] << "\n";
    cout << "Duplo: " << porTipo[1] << " ocupados - Faturamento: R$ " << faturamentoPorTipo[1] << "\n";
    cout << "Suite: " << porTipo[2] << " ocupados - Faturamento: R$ " << faturamentoPorTipo[2] << "\n\n";
    
    cout << "FATURAMENTO TOTAL: R$ " << faturamento << "\n";
    cout << "================================\n";
}

void listarHospedesAtuais() {
    cout << "\n=== HOSPEDES ATUAIS ===\n";
    bool temHospede = false;
    
    for(int i = 0; i < 20; i++) {
        if(quartos[i].ocupado) {
            cout << "Quarto " << quartos[i].numero << " - " << quartos[i].hospede.nome 
                 << " (CPF: " << quartos[i].hospede.cpf << ")\n";
            temHospede = true;
        }
    }
    
    if(!temHospede) {
        cout << "Nenhum hospede no momento.\n";
    }
}

int main() {
    inicializarQuartos();
    
    int opcao;
    
    do {
        cout << "\n====== SISTEMA DE HOTEL ======\n";
        cout << "1. Mapa de quartos\n";
        cout << "2. Fazer check-in\n";
        cout << "3. Fazer check-out\n";
        cout << "4. Listar hospedes atuais\n";
        cout << "5. Relatorio completo\n";
        cout << "6. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        
        switch(opcao) {
            case 1:
                mostrarMapaQuartos();
                break;
            case 2:
                fazerCheckIn();
                break;
            case 3:
                fazerCheckOut();
                break;
            case 4:
                listarHospedesAtuais();
                break;
            case 5:
                mostrarRelatorio();
                break;
            case 6:
                cout << "\nSistema encerrado. Volte sempre!\n";
                break;
            default:
                cout << "Opcao invalida! Tente novamente.\n";
        }
        
    } while(opcao != 6);
    
    return 0;
}
