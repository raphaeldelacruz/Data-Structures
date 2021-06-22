/*
 * hashNode.cpp
 *
 *  Created on: Nov 12, 2018
 *  	Author: rapha
 */
#include "hashNode.hpp"
#include<time.h>
using namespace std;
hashNode::hashNode(){
 keyword = "";
 values = NULL;
 valuesSize = 0;
 currSize = 0;
}
hashNode::hashNode(string s){
 keyword = s;
 valuesSize = 100;
 currSize = 0;
 values = new string[valuesSize];
}
hashNode::hashNode(string s, string v){
 keyword = s;
 valuesSize = 100;
 currSize = 1 ;
 values = new string[valuesSize];
 values[0] = v;
}
void hashNode::addValue(string v){
 values[currSize] = v;
 currSize++;
 if(currSize == valuesSize){
  dblArray();
 }
}
void hashNode::dblArray(){
 string *doubledArray = new string[valuesSize*2];
 for(int i=0;i<valuesSize;i++){
  doubledArray[i] = values[i];
 }
 valuesSize*=2;
 values = doubledArray;
}
string hashNode::getRandValue(){
 if(currSize==0){
  return "";
 }
 else{
  return values[rand()%currSize];
 }
}

