#include <iostream>
#include <vector>

using namespace std;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;

  if (right <= left )
    return number_of_inversions;

  int mid = (right + left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, mid);
  number_of_inversions += get_number_of_inversions(a, b, mid+1, right);

  int iLeft = left;
  int imid = mid;
  int iSorted = left;

  while ( iLeft < mid && imid <= right ) {
    /*if ( a[ iLeft ] > a[ imid ] ) {
      b[ iSorted++ ] = a[ imid++ ];
      number_of_inversions += mid - iLeft;
    } else {
      b[ iSorted++ ] = a[ iLeft++ ];
    }*/

    if ( a[ iLeft ] < a[ imid ] ) {
        b[ iSorted] = a[ iLeft ];
        iLeft++;
    }else{
        b[ iSorted] = a[ imid ];
        imid++;
        number_of_inversions += (mid - iLeft-1);
    }
  }

  while (iLeft < mid ){
    b[iSorted++] = a[iLeft++];
    iSorted++;
    iLeft++;
  }


  while (imid <= right){
    b[iSorted++] = a[imid++];
    iSorted++;
    imid++;
  }

  for (int i = left; i <= right; i++)
    a[i] = b[i];

  return number_of_inversions;
}

long long get_number_of_inversions22(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  if (right <= left + 1) {
    return 0;
  }

  size_t ave = (right + left) / 2;
  long long number_of_inversions = 0;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);

  size_t iLeft = left;
  size_t iAve = ave;
  size_t iReal = left;

  while ( iLeft < ave && iAve < right ) {
    if ( a[ iLeft ] > a[ iAve ] ) {
      b[ iReal ] = a[ iAve++ ];
      number_of_inversions += ave - iLeft;
    } else {
      b[ iReal ] = a[ iLeft++ ];
    }

    iReal++;
  }

  while ( iLeft < ave ) {
    b[ iReal++ ] = a[ iLeft++ ];
  }

  while ( iAve < right ) {
    b[ iReal++ ] = a[ iAve++ ];
  }

  for ( iLeft = left; iLeft < right; iLeft++ ) {
    a[ iLeft ] = b[ iLeft ];
  }

  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(n);
  std::cout << get_number_of_inversions(a, b, 0, n-1) << '\n';


  std::cout << "Sorted Array: "; // TODO: remove
  for (int i=0;i< b.size();i++) {
    std::cout << b[i] << " ";
  }
  std::cout << std::endl;
}
