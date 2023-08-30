#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "ScaffoldReadMapPlugin.h"

void ScaffoldReadMapPlugin::input(std::string file) {
  inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 std::cout << file << std::endl;
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   if (key.length() == 0) break;
   ifile >> value;
   if (value.length() == 0) break;
   parameters[key] = value;
 }


}

void ScaffoldReadMapPlugin::run() {}

void ScaffoldReadMapPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
 myCommand += "for var in \`cat "+std::string(PluginManager::prefix())+"/"+parameters["scaffolds"]+"\`; do grep \"$var\" "+std::string(PluginManager::prefix())+"/"+parameters["reads"]+" >> "+file+"; done";
std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<ScaffoldReadMapPlugin> ScaffoldReadMapPluginProxy = PluginProxy<ScaffoldReadMapPlugin>("ScaffoldReadMap", PluginManager::getInstance());

