#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

class dm {
public:
  int no_of_lines;
  int no_of_dta_inALine;
  dm() {
    no_of_lines = 0;
    no_of_dta_inALine = 0;
    getDms();
  }
  void getDms() {
    std::vector<long double> dim;
    std::ifstream file("dms.txt");

    // read the input
    copy(std::istream_iterator<long double>(file),
         std::istream_iterator<long double>(), std::back_inserter(dim));
    no_of_lines = dim[0];
    no_of_dta_inALine = dim[1];
    //     cout << no_of_lines << " " << no_of_dta_inALine << endl;
  }
};

vector<vector<long double>> getTwoD_RepresentationMatrix() {

  dm *D = new dm();
  //   cout << D->no_of_lines << D->no_of_dta_inALine << endl;
  int i = D->no_of_lines;
  int j = D->no_of_dta_inALine;

  vector<long double> values;
  ifstream file("image-output.txt");
  // read the input
  copy(istream_iterator<long double>(file), istream_iterator<long double>(),
       back_inserter(values));

  // cout << "Size of the vector is : " << values.size() << endl;

  vector<vector<long double> > image(i, vector<long double>(j, 0));
  cout << image[0].size() << endl;
  cout << image.size() << endl;

  int count = 0;
  for (int m = 0; m < i; m++) {
    for (int n = 0; n < j; n++) {
	image[m][n] = values[count];
      count++;
    }
  }
  return image;
}

int main() { getTwoD_RepresentationMatrix(); }