#include <iostream>
#include <vector>
using namespace std;


//////////////////////////////////
///////////quicksort///////////
//////////////////////////////////
int partition(int a[], int start, int end)
{
  int pv = a[end];
  int pvindex = start;
  for(int i=start; i<end; ++i)
  {
    if(a[i] <= pv)
    {
      swap(a[i], a[pvindex++]);
    }
  }
  swap(a[end], a[pvindex]);
  return pvindex;
}
void quicksort(int a[], int start, int end)
{
  if(start >= end) return;

  int pv = partition(a, start, end);
  quicksort(a, start, pv-1);
  quicksort(a, pv+1, end);
}
//////////////////////////////////
//////////////mergesor///////////
//////////////////////////////////
void merge(int a[], const int start, const int mid, const int end)
{
  int n1 = mid-start+1;
  int n2 = end-mid;
  int left[n1];
  int right[n2];

  for(int i=0; i<n1; ++i) left[i] = a[start+i];
  for(int i=0; i<n2; ++i) right[i] = a[mid+1+i];
  int i=0;
  int j=0;
  int index = start;
  while(i<n1 && j<n2)
  {
    if(left[i]>right[j])
    {
      a[index++] = right[j++];
    }
    else
      a[index++] = left[i++];
  }
  while(i<n1) a[index++] = left[i++];
  while(j<n2) a[index++] = right[j++];
}
void mergesort(int a[], int start, int end)
{
  if(start>=end) return;
  int mid = start + (end-start)/2;
  mergesort(a, start, mid);
  mergesort(a, mid+1, end);
  merge(a, start, mid, end);
}

//////////////////////////////////
////////void selectionsort/////////
//////////////////////////////////
void selectionsort(int b[], int n)
{
  vector<int> a (b, b+n);
  for(int i=0; i<n-1; ++i){
    int index = i;
    for(int j=i+1; j<n; ++j)
      if(a[index]>a[j])
        index = j;
    swap(a[index], a[i]);
  }

  for(int i=0; i<n; ++i)
    cout << a[i] << ",";
  cout << endl;
}
//////////////////////////////////
//////////bubblesort///////////////
//////////////////////////////////
void bubblesort(int b[], int n)
{
  vector<int> a (b, b+n);
  for(int i=0; i<n-1; ++i)
  {
    int inorder = true;
    for(int j=0; j<n-i-1; ++j)
    {
      if(a[j]>a[j+1])
      {
        swap(a[j], a[j+1]);
        inorder = false;
      }
    }
    if(inorder) break;
  }
  for(int i=0; i<n; ++i)
    cout << a[i] << ",";
  cout << endl;
}
//////////////////////////////////
//////////insertionsort///////////////
//////////////////////////////////
void insertionsort(int b[], int n)
{
  vector<int> a(b, b+n);

  for(int i=0; i<n; ++i)
  {
    int index = i;
    while(index>0 && a[index-1]>a[index])
    {
      swap(a[index], a[index-1]);
      index--;
    }
  }
  
  for(int i=0; i<n; ++i)
  cout << a[i] << ",";
  cout << endl;
}

void printarray(const int a[], int n)
{
  for(int i=0; i<n; ++i) cout << a[i] << ",";
  cout << endl;
}

int main() {
  int a[] = {6,34,623,432,66,43,432,156,23,664,343,2,32,23,223, 1000, 2000};
  int n = sizeof(a)/(sizeof(a[0]));
  selectionsort(a, n);
  bubblesort(a, n);
  insertionsort(a, n);

  
  mergesort(a, 0, n-1);
  printarray(a, n);

  int b[] = {6,34,623,432,66,43,432,156,23,664,343,2,32,23,223, 1000, 2000};
  printarray(b, n);
  quicksort(b, 0, n-1);
  printarray(b, n);
  cout << "END" << endl;
}
