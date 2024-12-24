#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

std::map<std::string, int> values;

int main() {
	std::string line;
	while (std::getline(std::cin, line)) {
	  if (line == "") {
	    break;
	  }
	  std::stringstream ss(line);
	  std::string name;
	  std::getline(ss, name, ':');
	  long value;
	  ss >> value;
	  values[name] = value;
	}
	std::vector<std::string> lines;
	while (std::getline(std::cin, line)) {
	  lines.push_back(line);
	}
	std::map<std::string, std::string> mapping = {
	  {"rhk", "+00"},
	  
	  {"thm", "!08"},
	  {"z08", "z08"},
	  
	  {"wrm", "&14"},
	  {"wss", "^14"},
	  
	  {"z22", "z22"},
	  {"hwq", "&22"},
	  
	  {"gbs", "+29"},
	  {"z29", "z29"},
	  
	};
	
	for (auto p:mapping){
	  std::cout <<p.first<<",";
	}
	for (int i = 0; i < 100; i++) {
	  for (auto line : lines) {
	    std::stringstream ss(line);
	    std::string o1, op, o2, res, arr;
	    ss >> o1;
	    ss >> op;
	    ss >> o2;
	    ss >> arr;
	    ss >> res;
	    if (op == "AND") {
  	    values[res] = values[o1] & values[o2];
	    } else if (op == "OR") {
	      values[res] = values[o1] | values[o2];
	    } else if (op == "XOR") {
	      values[res] = values[o1] ^ values[o2];
	    }
	    if (mapping[o1]!="")
	    o1 = mapping[o1];
	    if (mapping[o2]!="")
	    o2=mapping[o2];
	    if (mapping[res]=="") {
	    if ((o1[0] == 'x' && o2[0] == 'y') || (o1[0] == 'y' && o2[0] == 'x')) {
	      if (o1[1]!=o2[1] || o1[2]!=o2[2]){
	        std::cout << "err" <<o1<<op<<o2;
	        return -1;
	      }
	      if (op=="AND") {
	        mapping[res]="&"+o1.substr(1,2);
	      }
	      if (op=="XOR") {
	        mapping[res]="^"+o1.substr(1,2);
	      }
	   }
	   if (o1[0] == '^' && o2[0] == '+'){
	     std::string temp = o1;
	     o1 = o2;
	     o2 = temp;
	   }
	   if (o1[0] == '+' && o2[0] == '^'){
	     if (std::stoi(o1.substr(1,2)) + 1 != std::stoi(o2.substr(1,2))){
	        std::cout << "err";
	        return -1;
	      }
	      if (op=="AND") {
	        mapping[res]="!"+o2.substr(1,2);
	      }
	      if (op=="XOR") {
	        mapping[res]="z"+o2.substr(1,2);
	      }
	   }
	   if  (o1[0] == '!' && o2[0] == '&'){
	     std::string temp = o1;
	     o1 = o2;
	     o2 = temp;
	   }
	   if (o1[0] == '&' && o2[0] == '!'){
	     if (std::stoi(o1.substr(1,2)) != std::stoi(o2.substr(1,2))){
	        std::cout << "err3:";
	        return -1;
	      }
	      if (op=="OR") {
	        mapping[res]="+"+o2.substr(1,2);
	      }
	     	 
	    }
	   }
	  }
	}
	for (auto p : mapping) {
	  std::cout << "mapping:" << p.first << ":" << p.second << std::endl;
	}
	std::string result;
	for (auto p : values) {
	  if (p.first[0] =='z' | false) {
	    result = std::to_string(p.second) + result;
	  }
	}
	std::cout << std::endl << result;
}
// not formatted because it's typed on phone
