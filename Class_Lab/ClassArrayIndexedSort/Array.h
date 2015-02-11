/* 
 * File:   Array.h
 * Author:Haolan Ye(Benjamin)
 * Created on February 9, 2015, 8:45 AM
 * Purpose: Create an Array ADT
 */

#ifndef ARRAY_H
#define	ARRAY_H

class Array{
    private:
        int *data;
        int *index;
        int size;
    public:
        void filAray(int);
        void prntAry(int);
        void destroy();
        void mrkSort();
};
void Array::mrkSort() {
    //Sort with index
    for(int pos=0;pos<size-1;pos++) {
        for(int lst=pos+1;lst<size;lst++) {
            if(data[index[pos]] >data[index[lst]]) {
                //Swap the indexes
                int temp=index[pos];
                index[pos]=index[lst];
                index[lst]=temp;
            }
        }
    }
}

void Array::filAray(int n) {
    
    //Fill the array ADT
    if(n<=0) size=0;
    else size=n;
    //Now declare and allocate memory for the data
    data=new int[size];
    index=new int[size];
    //Fill data with 2 digit numbers
    for(int i=0;i<size;i++) {
        data[i]=rand()%90+10;
        index[i]=i;
    }
}
void Array::prntAry(int perLine) {
    cout<<endl;
    for(int i=0;i<size;i++) {
        cout<<data[index[i]]<<" ";
        if(i%perLine==(perLine-1)) cout<<endl;
    }
}
void Array::destroy() {
    delete [] index;
    delete [] data;
}

#endif	/* ARRAY_H */

