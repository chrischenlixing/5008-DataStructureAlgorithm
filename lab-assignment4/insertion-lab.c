//enter your name here Chris Chen
//enter your email here chen.lixin@northeastern.edu
//To perform insertion sort of integers stored in a file and display the output and store it in another file.
#include <stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    int arr[10],temp;
    int count=0,i,j;
    /*count will have the total number of elements in the array*/

    /*read the file*/
    fp=fopen("Input.txt","r");
    if(fp==NULL){
        //if file returns NULL then can't open the file
        printf("\n Cannot open the file \n");
        exit(0);
    }
    
    //insert your code here
    
    count = sizeof(arr)/sizeof(int);

    for (i=0;i<count;i++){
        fscanf (fp,"%d",&arr[i]);
    }

    int key;
  
    for (i=1;i<count;i++){
      key = arr[i];
      for (j=i-1; j>=0 && arr[j]>key;j--){
        arr[j+1] = arr[j];
      }
      arr[j+1] = key;
    }
    
 
    FILE *newfp;
    newfp = fopen("sorted.txt", "w");

    for (i=0;i<count-1;i++){
        fprintf(newfp,"%d\n",arr[i]);
    }
    fprintf(newfp,"%d",arr[count-1]);
  
  
    fclose(fp);
  
    fclose(newfp);
    
    
    return 0;
}
