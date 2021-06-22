/*
 * hashMap.cpp
 *
 *  Created on: Nov 12, 2018
 *  	Author: rapha
 */
#include <math.h>
#include "HashMap.hpp"
using namespace std;
bool isPrime(int k);

hashMap::hashMap(bool hash1, bool coll1){
	first  = "";
	numKeys = 0;
	mapSize = 17;
	h1 = hash1;
	c1 = coll1;
	collisionct1 = 0;
	collisionct2 = 0;
	map = new hashNode*[mapSize];
	for(int i=0;i<mapSize;i++){
    	map[i] = NULL;
	}
}
void hashMap::addKeyValue(string k,string v){
	int index = getIndex(k);
	if(map[index] == NULL){
    	map[index] = new hashNode(k,v);
    	numKeys++;
	}
	else{
    	map[index]->addValue(v);
	}
	if(numKeys>=.7*mapSize){
        	reHash();
	}
}
int hashMap::getIndex(string k){
	int index;
	if(h1){
    	index = calcHash(k);
	}
	else{
    	index = calcHash2(k);
	}
	if(map[index] == NULL || map[index]->keyword == k){
    	return index;
	}
	else{
	 collisionct1+=1;
    	if(c1==true){
        	index = collHash1(index,k);
    	}
    	else{
        	index = collHash2(index,k);
    	}
	}
	return index;
}
int hashMap::calcHash(string k){ //Adds up integer values of characters
	int index = 0;
	int length = k.length();
	for(int i=0;i<length;i++){
    	index+=k[i];
	}
	return index%mapSize;
}
int hashMap::calcHash2(string k){ //Raises character value to i'th power
    int index = 0;
    for(int i=0;i<k.length();i++){
        index += (k[i]*k[i]);
    }
    return index%mapSize;
}
void hashMap::getClosestPrime(){
 int DoubleSize = mapSize*2, lp = 0, rp = 0;
  for (int i=DoubleSize-1; lp==0; i--) {
   if (isPrime(i) == true) {
    lp = i;
   }
  }
  for (int j=DoubleSize+1; rp==0; j++) {
   if (isPrime(j) == true) {
    rp = j;
   }
  }
  int range1 = DoubleSize-lp, range2 = rp-DoubleSize;
  if (range1 < range2) {
   mapSize = lp;
  }
  else {
   mapSize = rp;
  }
}
void hashMap::reHash(){
	int size = mapSize;
	int index;
	getClosestPrime();
	hashNode **placeholder = map;
	map = new hashNode*[mapSize];
	for(int i=0;i<mapSize;i++){
    	map[i] = NULL;
	}
	for(int j=0;j<size;j++){
    	if(placeholder[j]!=NULL){
        	index = getIndex(placeholder[j]->keyword);
        	map[index] = placeholder[j];
    	}
	}
}
int hashMap::collHash1(int h, string k){ //Linear probing
 int i = h;
  while (map[i] != NULL) {
   if (k == map[i]->keyword) {
    break;
   }
   else {
    collisionct2 += 1;
    if (i != mapSize-1) {
     i += 1;
    }
    else {
     i = 0;
    }
   }
  }
  return i;
 }
int hashMap::collHash2(int h, string k){ //Quadratic probing
	int hash = h;
	int i = 0;
	while(map[hash]!=NULL){
    	if(map[hash]->keyword == k || map[hash]==NULL){
        	break;
    	}
    	collisionct2++;
    	i++;
    	hash = (h+(i*i))%mapSize;
	}
	return hash;
}
int hashMap::findKey(string k) {
	int kIndex = getIndex(k);
	if(map[kIndex]->keyword == k){
    	return kIndex;
	}
	return -1;
}
void hashMap::printMap(){
	cout << "first = " << first << endl;
	cout << "numKeys = " << numKeys << endl;
	cout << "mapSize = " << mapSize << endl;
	cout << "h1 = " << h1 << endl;
	cout << "c1 = " << c1 << endl;
	cout << "collisionct1 = " << collisionct1 << endl;
	cout << "collisionct2 = " << collisionct2 << endl;
}
bool isPrime(int k){
 int divider = 2;
 bool is_prime = true;
 while (divider < k && k%divider==0) {
  is_prime = false;
  divider++;
 }
 if (k == 1)
  is_prime = false;
 return is_prime;
}



