#include<iostream>
#include <vector>
#include <string>
using namespace std;

class TodoList{
    private:
    struct Task{
        string task;
        bool complete;
    };

    vector<Task> Tasks;

    public:
    void addTask(string task){
        Task newTask={task,false};
        Tasks.push_back(newTask);
        cout<<"Tasks Added : "<<task<<endl;
    }
    void displayTask(){
        if(Tasks.empty())
        cout<<"The TodoList is Empty!";
        else{
            for(int i=0;i<Tasks.size();i++){
                cout<<Tasks[i].task<<"-"<<(Tasks[i].complete?" Done":" Not Done")<<endl;
            }
        }
    }
    void deleteTask(int taskIndex){
        if(taskIndex>=0 && taskIndex<Tasks.size()){
            cout<<"Task deleted!.. "<<Tasks[taskIndex].task<<endl;
            Tasks.erase(Tasks.begin()+taskIndex);
        }
        else{
            cout<<"Nothing in the Todo list\n"<<endl;
        }
    }
    void markAsComplete(int taskIndex){
        if(taskIndex>=0 && taskIndex<Tasks.size()){
            (Tasks[taskIndex].complete=true);
            cout <<"Marked task as complete: "<< Tasks[taskIndex].task<<endl; 
        }
        else{
            cout<<"Nothing in the Todo list in that Index\n"<<endl;
        }
    }
};
int main(){
    TodoList todo;
    string task;
    int index,choice;
    do{
        cout << "\n1. Add task\n";
        cout << "2. Delete task\n";
        cout << "3. Mark task as complete\n";
        cout << "4. Display tasks\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch(choice){
            case 1:
            cout<<"Add task\n"<<endl;
            cin.ignore();
            getline(cin,task);
            todo.addTask(task);
            break;

            case 2:
            cout <<"Delete task\nEnter the index want to delete\n";
            cin>>index;
            todo.deleteTask(index);
            break;

            case 3:
            cout <<"Mark as Complete task\nEnter the index want to mark\n";
            cin>>index;
            todo.markAsComplete(index);
            break;

            case 4:
            cout <<"Display tasks\n";
            todo.displayTask();
            break;

            case 5:
            cout <<"Exiting the To-Do List application." << endl;
            break;

            case 6:
            cout<<"Invalid Choice!"<<endl;
            break;
        }
    }while (choice!=5);
    return 0;
}