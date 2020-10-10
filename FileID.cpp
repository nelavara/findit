/*Names: Jaron Bialecki & Evan Perry
* Date:  09-20-2020
*/
#include "FileID.hpp"
//Constructor for FileID,takes a tuple, then parses it for the data items.
FileID::FileID(tuple <char*, char*, nlink_t, off_t, ino_t, bool, string> dataContainer) {
    filePath = new char [strlen(get<0>(dataContainer))];
    strcpy(filePath, get<0>(dataContainer));
    fileName = new char [strlen(get<1>(dataContainer))];
    strcpy(fileName, get<1>(dataContainer));
    numOfLinks = get<2>(dataContainer);
    sizeofFile = get<3>(dataContainer);
    iNodeNum = get<4> (dataContainer);
    verboseState = get<5>(dataContainer);
    fileType = get<6>(dataContainer);
    cout << "FilePath: " << filePath << endl;
}
//--------------------------------------------------------------------------
/*
 * This function will the vector of search words, and only add to it, if a found word does not match.
 */
void FileID::sniffWordmaker(string inComing) {
    if (sniffWords.empty()){
        sniffWords.push_back(inComing);
    }
    else{
        for (int k = 0; k < int(sniffWords.size()); k++){
            bool found = false;
            for (int j =0 ; j < int(sniffWords.size()); j ++){
                if (sniffWords[j]==inComing){
                    found = true;
                    break;
                }
            }
            if (!found){
                sniffWords.push_back(inComing);
            }
        }
        }
}

//---------------------------------------------------------------------------
/*
 * This function takes a vector, which is passed by the sniffer, it then reads the files for each
 * search term.
 */
bool FileID::readFile(vector<string>& tobeSniffed){
    cout << " FilePath: " << filePath << " ==== " << "Number of Links: " << numOfLinks << " === " << "Inode Num: " << iNodeNum << endl;
    string line;
    string test1= "\\b(";
    string test2 = ")([^ ]*)";
    ifstream readin;
    readin.open(filePath);
    bool foundone = false;
    bool anyWordfound = false;
    while(getline(readin, line)){
        foundone = false;
        istringstream iss (line);
        if(!iss) break;
        for (int k = 0; k < int(tobeSniffed.size()); k++){
            string regPattern = test1+tobeSniffed[k]+test2;
            smatch test;
            regex des (regPattern);
            while(regex_search(line,test,des)){
                for (string x:test) {
                    anyWordfound = true;
                    foundone = true;
                    sniffWordmaker(x);
                    break;
                }
                if (foundone) break;
            }
        }
    }
    readin.close();

    return anyWordfound;
}

//--------------------------------------------------------------------------
/*
 * Prints out the details of the file, if verbose is on, additional items are printed.
 */

ostream& FileID::print(ostream& out){
  if (verboseState){
      if (fileType == "File"){
          out << fileType << '\t' << '\t' << iNodeNum << '\t' << fileName;
      }
      else if (fileType == "Soft Link"){
          out << fileType << '\t' << iNodeNum << '\t' << fileName;
      }
      else{
          out << fileType << '\t' << iNodeNum << '\t' << fileName << '\t';
      }

  }
  out << '\t' << "iNode" << '\t' << iNodeNum << '\t' << "links" << '\t' << numOfLinks << '\n';
  out << "\t\t" << filePath << '\n';
    return out;
}
