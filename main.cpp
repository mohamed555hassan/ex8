 #include<vector>
#include<iostream>

using namespace std;

//The following function is a helper function. It was solved in page 502, proj 9
void sortByInsertion(vector<int>& myVector){

    size_t size = myVector.size();
    int temp;//will be used for swaping.

    for(size_t i =1 ; i<size;++i){//this for loop will go through all of the \
                        elements starting from 1 to size-1. At every element\
                        it makes another internal for loop to put ith element\
                        n the appropriate position in the sorted vector. \
                        The sorted vector is the vector from 0 to i-1.
        for(size_t j = i ; j > 0; --j){//This for loop put the ith element in \
                                the main myVector or 1th element in the \
                                unsorted Vector in the appropriate position in \
                                the sorted one.Sorted one here starts from 0 to\
                                j-1. Its work: the for loop goes through \
                                elements and check if the\
                                myVector[j]<myVector[j-1] or not. If\
                                yes, it swaps the values, the continues the \
                                comparison if not, it breaks, and the new \
                                sorted myVector is from 0 to i

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

    vector<int> gradesVector;//will be filled up by the input values

    //A prompt
    cout<<"Enter the grades and separate them by spaces, enter -1, and finally"
    " press enter:\n";

    //temp is a temporary var to check if the input value is <0 (here, we \
    accept the value) or >0 (here we terminate accepting the rest values)
    int temp = 0;
    cin>>temp;
    while(temp > -1){
        gradesVector.push_back(temp);//accepting  the value
        cin>>temp;
    };

    //making a dynamic array to store the histogram . It is one-D array of\
    vectors. It can be considered as 2d one. The first element will be a\
    vector of unrepeated grades and the second one will be a vector of the\
    frequency of the corresponding grade in the first element.
    vector<int> * array = new vector<int>[2];

     /*
    The algorithm we will use to store the histogram in array.
    firstly, sorting the grades.
    After that, we will go through grades, by index, and check if  the element
    is new or is repeated.
    If it is a new one we will store the grade in the first array element, by
    push_back(gradesVector[index]) and making array[1].push_back(1).
    If not, we will increment the last element in the second element of array
     */

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





