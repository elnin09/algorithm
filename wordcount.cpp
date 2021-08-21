#include "iostream"
#include "fstream"
using namespace std;
#define WORDS 50000


//Define a structure to store words and count
struct wordMap
{
  char* word;
  int count;
};


//custom function to find if a word is already present in the Map structure
int find(char *data , wordMap array[],int size)
{
  for(int i=0;i<size;i++)
  {
    if(strcmp(array[i].word,data)==0)
    {
      return i;
    }
  }
  return -1;
}
int main()
{
  
  char fileName[500] = "sample-long.txt";
  char fileData[500000];
  FILE *fp = fopen(fileName,"r");
  if(fp == NULL)return -1;
  char cin;
  int count=0;

  /*Read the entire contents of the file in this fileData*/
  while((cin =fgetc(fp))!=EOF)
  {
       fileData[count] = tolower(cin);
       count++;
  }

  //Fetch words from our fileData and populate words and count container"
  wordMap wordcontainer[50000];
  int currentIndex=0;
  int start=0;
  for(int i=0;i<strlen(fileData);i++)
  { 
    if(!isalnum(fileData[i]))
    {
       char* substr1 = (char *)malloc(i-start);
       strncpy(substr1,fileData+start,i-start);
       start=i+1;
       if(strlen(substr1)==0)continue;
       int index = find(substr1,wordcontainer,currentIndex);
       if(index==-1){wordcontainer[currentIndex].word = substr1; wordcontainer[currentIndex].count=1;currentIndex++;}
       else{wordcontainer[index].count++;}
    }
  }

  for(int i=0;i<currentIndex;i++)
  {
    for(int j=i+1;j<currentIndex;j++)
    {
      if(wordcontainer[i].count < wordcontainer[j].count)
      {
        wordMap temp = wordcontainer[i];
        wordcontainer[i]=wordcontainer[j];
        wordcontainer[j]=temp;
      }
    } 
  }

  cout<<"Top 15 words on the basis of frequency"<<endl<<endl;
  for(int i=0;i<15&&i<currentIndex;i++)
  {
     cout<<wordcontainer[i].word<<endl<<wordcontainer[i].count<<endl<<endl;
  } 


  cout<<endl<<endl<<"Bottom 15 words on the basis of frequency"<<endl<<endl;
  for(int i=currentIndex-1;i>=0&&i>=currentIndex-15;i--)
  {
     cout<<wordcontainer[i].word<<endl<<wordcontainer[i].count<<endl<<endl;
  } 

}

