#include "Poco/MD5Engine.h"
#include "DigestStream.b"
#include <iostream>

int main(int argc, char** argv){
    Poco::MD5Engine md5;
    Poco::DigestOutputStream ds(md5);
    ds << "abcdefghijklmnoprstuqvwxyz";
    ds.close();
    std::cout <<Poco::DigestEnginer::digest::ToHex(md5.figest()) << std::endl;
    return 0;
    
}