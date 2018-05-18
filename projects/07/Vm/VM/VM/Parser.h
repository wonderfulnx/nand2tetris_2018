//
//  Parser.h
//  VM
//
//  Created by NaXin on 2018/4/16.
//  Copyright © 2018年 NaXin. All rights reserved.
//

#ifndef Parser_h
#define Parser_h
#include <string>
#include <regex>

using namespace std;

class Parser {
public:
    int type;//commad type 0:no argue, 1:1 argue, 2:2 argue
    string cmd;
    string arg1;
    string arg2;
    
public:
    void removeComment(string &cmd){
        if (cmd.find("//") != string::npos)
            cmd = cmd.substr(0,cmd.find("//"));
        return;
    }
    
    void readCommand(string s){
        int currentSeg = 0;
        
        for (long long i = 0; i < s.size();)
        {
            if (s[i] != ' '){
                switch (currentSeg) {
                    case 0:
                        cmd.push_back(s[i]);
                        break;
                    case 1:
                        arg1.push_back(s[i]);
                        break;
                    case 2:
                        arg2.push_back(s[i]);
                        break;
                    default:
                        throw runtime_error("the max argument number is 2.");
                        break;
                }
                i++;
            }
            else {
                while (s[i] == ' ' && i < s.size()) i++;
                if (i != s.size())
                    currentSeg++;
            }
        }
        
        type = currentSeg;
        return;
    }
};

#endif /* Parser_h */
