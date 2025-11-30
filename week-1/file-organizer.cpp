#include <iostream>
#include <filesystem>
#include <string>
namespace fs = std::filesystem;

void organizeFiles(const std::string& folderPath){
    if(!fs::exists(folderPath)){ std::cout<<"The folder does not exist.\n"; return; }

    for(const auto& entry: fs::directory_iterator(folderPath)){
        if(entry.is_regular_file()){
            std::string filePath=entry.path().string();
            std::string extension=entry.path().extension().string();
            if(extension.empty()) continue;

            std::string subfolder=folderPath+"/"+extension.substr(1);
            if(!fs::exists(subfolder)) fs::create_directory(subfolder);

            std::string newFilePath=subfolder+"/"+entry.path().filename().string();
            fs::rename(filePath,newFilePath);
        }
    }
    std::cout<<"Files organized successfully.\n";
}

int main(){
    std::string folderPath;
    std::cout<<"Enter the folder path: ";
    std::cin>>folderPath;
    organizeFiles(folderPath);
    return 0;
}
