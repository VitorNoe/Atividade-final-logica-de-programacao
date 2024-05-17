#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Task{   // Definem tipos de dados que agrupam variáveis sob um mesmo tipo de dado.
    int id;
    string title;
    string description;
    string dueDate;
    string status;
};

void addTask(vector<Task>&tasks, int& nextld) {
    Task newTask;
    newTask.id = nextld++;
    cout << "Título da tarefa: ";
    cin  >> newTask.title;
    cout << "Descrição da tarefa: ";
    cin >> newTask.description;
    cout << "Data de vencimento (DD/MM/AAAA): ";
    cin >> newTask.dueDate;
    cout << "Status da tarefa (Pendente, Em Progresso, Concluída): ";
    cin >> newTask.status;
    tasks.push_back(newTask);
    cout << "Tarefa adicionada com sucesso!\n";
}

void viewTasks(const vector<Task>& tasks) {
    cout << "Lista de Tarefas:\n";
    for(const Task& task : tasks) {
        cout << "ID: " << task.id << "\n";
        cout << "Título: " << task.title << "\n";
        cout << "Descrição: " << task.description << "\n";
        cout << "Data de Vencimento: " << task.dueDate << "\n";
        cout << "Status: " << task.status << "\n\n";
    }
}
void editTask(vector<Task>& tasks) {
    int taskld;
    cout << "Digite o ID da tarefa que deseja editar: ";
    cin >> taskld;
    for (Task& task : tasks) {
        if (task.id == taskld) {
            cout << "Novo título da tarefa: ";
            cin >> task.title;
            cout << "Nova descrição da tarefa: ";
            cin >> task.description;
            cout << "Nova data de vencimento (DD/MM/AAAA): ";
            cin >> task.dueDate;
            cout << "Novo status da tarefa (Pendente, Em Progresso, Concluída): ";
            cin >> task.status;
            cout << "Tarefa editada com sucesso!\n";
            return;
        }
    }
    cout << "Tarefa não encontrada!\n";
}

void removeTask(vector<Task>& tasks) {
    int taskld;
    cout << "Digite o ID da tarefa que deseja remover: ";
    cin >> taskld;
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->id == taskld) {
            it = tasks.erase(it);
            cout << "Tarefa removida com sucesso!\n";
            return;
        }
    }
    cout << "Tarefa não encontrada!\n";
}

int main() {
    vector<Task> tasks;
    int nextld = 1;
    char choice;

    do {
        cout << "1. Adicionar Tarefa\n";
        cout << "2. Visualizar Tarefas\n";
        cout << "3. Editar Tarefa\n";
        cout << "4. Remover Tarefa\n";
        cout << "5. Sair\n";
        cout << "Escolher uma opção: ";
        cin >> choice;

        switch (choice) {
            case '1':
            addTask(tasks, nextld);
            break;
            case '2':
            viewTasks(tasks);
            break;
            case '3':
            editTask(tasks);
            break;
            case '4':
            removeTask(tasks);
            break;
            case '5':
            cout << "Saindo do programa...\n";
            break;
            default:
            cout << "Opção inválida! Tente novament.\n";
        }
    } while (choice != '5');

    return 0;
}