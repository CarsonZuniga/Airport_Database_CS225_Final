#include "dataset.h"

int main(int argc, char *argv[]){
    std::string cmd_file = argv[1];
    dataset my_data(cmd_file);
    //my_sheet.printData();
    
    my_data.printData();
    
    return 0;
}