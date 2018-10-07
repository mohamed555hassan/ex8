 #include<vector>
#include<iostream>

using namespace std;

void sortByInsertion(vector<int>& myVector){

    size_t size = myVector.size();
    int temp;//will be used for swaping.

    for(size_t i =1 ; i<size;++i){
        for(size_t j = i ; j > 0; --j){ 

            if(myVector[j] < myVector[j-1]){
                temp = myVector[j];
                myVector[j] = myVector[j-1];
                myVector[j-1] = temp;
            }
            else break;
        };
    };
};



int main(){

    vector<int> gradesVector;//will be filled up by the input value
 
    cout<<"Enter the grades and separate them by spaces, enter -1, and finally"
    " press enter:\n";
 
    int temp = 0;
    cin>>temp;
    while(temp > -1){
        gradesVector.push_back(temp);//accepting  the value
        cin>>temp;
    };

    //making a dynamic array to store the histogram . 
    vector<int> * array = new vector<int>[2];

    
    sortByInsertion(gradesVector);

    for(size_t i = 0; i<gradesVector.size();++i){

        if(i==0 ||gradesVector[i-1] != gradesVector[i]){
            array[0].push_back(gradesVector[i]);
            array[1].push_back(1);
        }
        else ++array[1][array[1].size()-1];
    };

    //Displaying the results as in the book
    cout<<"\nThe output\n";
    for(size_t i = 0; i < array[0].size(); ++i)
        cout<<"Number of "<<array[0][i]<<"'s:\t"<<array[1][i] <<"\n";

    return 0;

};





