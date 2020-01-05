#include <iostream>
#include <fstream>

using namespace std;

void sort(int *, int);
int binsearch(int, int *, int, int);

int main(int argc, char *argv[]){
  int target;
  if(argc < 2){
    cout << "Provide a filename of the data to be searched" << endl;
    return 1;
  }
  ifstream datfile(argv[1], ios::in);
  if( datfile.fail() ){
    cout << "Unable to open file: " << argv[1] << endl;
    return 1;
  }
  int count = 0;
  // Count how many integers are in the file
  while(! datfile.fail()){
    int temp;
    datfile >> temp;
    if(!datfile.fail()){
      count++;
    }
  }
  // When we reach the end of the file, the EOF flag is set
  // To be able to read through the file again we need to clear that flag
  datfile.clear();
  //  We also need to set our internal position in the file back to 0
  datfile.seekg(0,ios::beg);

  // Now allocate an array to store the file data and read in the data
  int *data = new int[count];
  for(int i=0; i < count; i++){
    datfile >> data[i];
  }

  datfile.close();

  cout << "Read " << count << " integers from the data file.\n" << endl;
  cout << "Enter the target positive integer to search for: ";
  cin >> target;

  // Part 2 
  sort(data, count);

  // Part 1
  int retval = binsearch(target,data,0,count);

  // Check if it exists and return
  if(retval == -1){
    cout << target << " does not appear in the data." << endl;
  }
    
  else {
    cout << target << " appears at index " << retval << " in the data." << endl;
  }

  // Delete unallocated memory
  delete [] data;
  return 0;
    
}


// Returns the index in the data array where target is located
//  or -1 if the target value is not in the list
int binsearch(int target, int *data, int start, int end)
{
    //if target is at front
	if (data[start] == target)
	{
		return start;
	}
    
    //if target is at back
	else if (data[end] == target)
	{
		return end;
	}
    
    //if too little items exists
	else if (start >= end || (end - start) < 2)
	{
		return -1;
	}
    
    //find which number it is in the list
	int num = (end + start) / 2 ;
    
    //if data is target return number
	if (data[num] == target)
	{
		return num;
	}
    
    //if it is less than target go through list but start at the index
	else if(data[num] < target)
	{
		return binsearch(target, data, num, end);
	}
    
    //if it is less than target go through list but end at the index
	else if(data[num] > target)
	{
		return binsearch(target, data, start, num);
	}
    
    //in case there is failure
	else
	{
		return -1;
	}
    
}

// implements a selection sort algorithm to sort
//  the integer values in the 'data' array of size 'len'
// You aren't allowed to change the prototype of this function
void sort(int *data, int len)
{
    int max=0;
	int index;
	int temp;

	for (int i = 0; i < len-1; i++)
	{
        
		if (data[i] > max)
		{
			index = i;
            max = data[i];
		}
        
	}
    
    temp = data[len-1];
    data[len-1] = max;
    data[index] = temp;
    
    if (len>1) {
	sort(data, len -1);
    }

}
