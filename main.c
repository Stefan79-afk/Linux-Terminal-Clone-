#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

//Macros
#define INPUT_SIZE 512
#define ARG_SIZE 20
#define COMM_SIZE 10


//This is a data structure I made to organize the command information better.
struct command{
    char *args[INPUT_SIZE];
    char *arguments[ARG_SIZE];
    char *flags[ARG_SIZE];
    char inputFile[50];
    char outputFile[50];

    int argumentSize;
    int flagSize;
    int commandSize;
    int inputDescriptor;
    int outputDescriptor;
};

//I give it its own name to simplify the syntax.
typedef struct command comm;

//Global variables

//Function Declarations
void readCommand(char*);
void getPath(const char*);
comm* interpretCommand(char*, comm*);
void parseCommand(comm*);
int getSize();
void printCommands();
int executeCommand();
int executeCommandNoPipe();
int executeCommandPipe();
void changeDirectory(const char* newPath);
void printHelp();


int main() {

    while(1){
        //First, I create the command string that will take the input from the user.
        char *command = malloc(sizeof(char) * INPUT_SIZE);
        readCommand(command);
        //Then, create a custom-defined-type array that will hold at most 10 commands and interpret the input 'command'.
        comm *commands = malloc(sizeof(comm) * COMM_SIZE);

        //interpretCommand(command, commands);
        //printCommands(commands);

        //After the interpreting is done, each command in the 'commands' array will be executed. The function 'executeCommand' will return a number, and if it returns 0, the loop ends and the program finishes.
        int returnSignal = 0;
        if(returnSignal == 0){
            break;
        }
    }
    return 0;
}

void readCommand(char* command){
    //Before prompting the user, get the path and write it
    const char path[INPUT_SIZE];
    getPath(path);
    write(STDOUT_FILENO, path, strlen(path));

    //Then, let the user know they can enter a command
    write(STDOUT_FILENO, "$", 1);

    //Make sure that 'command' is not end of line char.
    do{
        read(STDIN_FILENO, command, INPUT_SIZE);
    }while(strcmp(command, "\n") == 0);

    //Eliminate end of line char from command. 'strchr' returns the pointer where \n is. By subtracting the pointer 'command', I get \n's position.
    command[strchr(command, '\n') - command] = '\0';

}

void getPath(const char* path){
    getcwd(path, INPUT_SIZE);
}

void changeDirectory(const char* newPath){
    //The function chdir does all the work. Apparently cd is better implemented like this than creating a process for it
    chdir(newPath);
}

void printHelp(){
    //Just prints the commands I had to implement manually
    printf("Manually implemented commands:\n");
    printf("rm:  -r, -i, -v\n");
    printf("mv: -i -b -S -t\n");
    printf("dir\n");
    printf("exit\n");
    printf("cd\n");
}

