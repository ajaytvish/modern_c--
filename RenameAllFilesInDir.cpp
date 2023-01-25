#include<iostream>
#include<string>
#include<vector>
#include<filesystem>
#include<algorithm>
#include <cstring>
#include <fstream>
#include <map>
namespace filesys = std::filesystem;
using namespace std;

/*
 * Get the list of all files in given directory and its sub directories.
 *
 * Arguments
 *     dirPath : Path of directory to be traversed
 *     dirSkipList : List of folder names to be skipped
 *
 * Returns:
 *     vector containing paths of all the files in given directory and its sub directories
 *
 */

std::vector<std::string> getAllFilesInDir(const std::string &dirPath, const std::vector<std::string> dirSkipList = { })
{
    map<string,int> m = { {"Jan",1}, {"Feb",2}, {"Mar",3}, {"Apr",4}, {"May",5}, {"Jun",6}, {"Jul",7}, {"Aug",8}, {"Sep",9}, {"Oct",10}, {"Nov",11}, {"Dec",12} };



    //output filename to file
    fstream file;
    file.open("D:\\bank_statements\\filenameslist.txt", ios::app);

    //append string appendStr(below) to the file before filename
    char appendStr[] = "icici_";
    int appSize = strlen(appendStr);
    int dirPathize = dirPath.size();
    char *appendedPath = new char[appSize + dirPathize];
    sprintf(appendedPath, "%s\\\\%s", dirPath, appendStr);
    int appendedPathSize = strlen(appendedPath);
    // Create a vector of string
    std::vector<std::string> listOfFiles;
    try {
        // Check if given path exists and points to a directory
        if (filesys::exists(dirPath) && filesys::is_directory(dirPath))
        {
            // Create a Recursive Directory Iterator object and points to the starting of directory
            filesys::recursive_directory_iterator iter(dirPath);
            // Create a Recursive Directory Iterator object pointing to end.
            filesys::recursive_directory_iterator end;
            // Iterate till end
            while (iter != end)
            {
                // Check if current entry is a directory and if exists in skip list
                if (filesys::is_directory(iter->path()) &&
                        (std::find(dirSkipList.begin(), dirSkipList.end(), iter->path().filename()) != dirSkipList.end()))
                {
                    // Skip the iteration of current directory pointed by iterator
#ifdef USING_BOOST
                    // Boost Fileystsem  API to skip current directory iteration
                    iter.no_push();
#else
                    // c++17 Filesystem API to skip current directory iteration
                    iter.disable_recursion_pending();
#endif
                }
                else
                {
                    string tempName;
                    string currentFilename = iter->path().filename().string();
                    int currize = currentFilename.size();

                    if(file.is_open()) {
                        file << currentFilename << std::endl;
                     }

                    // Appending year_month in start of filename. Year is mentioned at end currently. if filename eg. "533386049_Apr2016.pdf"
                    size_t last_index = currentFilename.find_first_of("_"); //"0123456789"
                    string month = currentFilename.substr(last_index + 1, 3);
                    string year = currentFilename.substr(last_index + 4, 4);
                    auto it = m.find(month);
                    tempName = year + "_" + to_string(it->second) + "_" + "icici_" + currentFilename;

                    int oSize = dirPath.size();
                    char *oldFilepath = new char[oSize+3+currize];
                    sprintf(oldFilepath, "%s\\%s", dirPath.c_str(), currentFilename.c_str());

                    char *newFilePath = new char[appendedPathSize+currize+2]; //int size = currentFilename.size();
                    //sprintf(newFilePath, "%s\\%s%s", dirPath.c_str(), appendStr, tempName.c_str());
                    sprintf(newFilePath, "%s\\%s", dirPath.c_str(), tempName.c_str());

                    int res = rename(oldFilepath, newFilePath);
                    cout<<res<<endl;

                    delete []oldFilepath;
                    delete []newFilePath;
                }
                error_code ec;
                // Increment the iterator to point to next entry in recursive iteration
                iter.increment(ec);
                if (ec) {
                    std::cerr << "Error While Accessing : " << iter->path().string() << " :: " << ec.message() << '\n';
                }
            }
        }
    }
    catch (std::system_error & e)
    {
        std::cerr << "Exception :: " << e.what();
    }
    delete []appendedPath;
    file.close();
    return listOfFiles;
}
int main()
{
    getAllFilesInDir("D:\\bank_statements\\renameThruCode"); //This dir should have pdf files
return 0;
}
