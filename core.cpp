#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

// Code for Graph visualization with Flood Fill ALgorithm( $4 directions -
// top,right,bottom,left )

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

  vector<vector<long double>> image(i, vector<long double>(j, 0));
  cout << "i : " << i << " j : " << j << endl;
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


void writeOutput(vector<vector<long double > > updated_Image){
  // PROCESSIING THE OUTPUT :
  dm *D = new dm();
  //   cout << D->no_of_lines << D->no_of_dta_inALine << endl;
  int M = D->no_of_lines;
  int N = D->no_of_dta_inALine;

  ofstream output_file("output.txt");
  ostream_iterator<int> output_iterator(output_file, " ");

  int count = 0;
  for (int i = 0; i < updated_Image.size(); i++) {
    copy(updated_Image.at(i).begin(), updated_Image.at(i).end(),
         output_iterator);
      output_file << '\n';
     
  }
}

string getPx(long double dt, long double flag) {
  if (flag == 1) {
    return to_string(dt);
  }
  if (dt == 0)
    return ".";
  else if (dt == 2)
    return "O";
  else
    return " ";
}

void printImage(vector<vector<long double>> img, long double flag) {
  cout << endl;
  for (auto list : img) {
    for (auto px : list) {

      cout << getPx(px, flag) << " ";
    }
    cout << endl;
  }

  cout << endl;
}

void color(long double row, long double col,
           vector<vector<long double>> &updated_image,
           vector<vector<long double>> image, long double newColor,
           long double delRow[], long double delCol[], long double iniC) {

  updated_image[row][col] = newColor;

  long double n = image.size();    // height
  long double m = image[0].size(); // width

  for (int i = 0; i < 4; i++) {
    long double new_row = row + delRow[i];
    long double new_col = col + delCol[i];
    if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m &&
        image[new_row][new_col] ==
            iniC && // if new polong double color is same as
                    // initial color then Re-Palong double it
        updated_image[new_row][new_col] !=
            newColor // if new polong double is not updated by any node
    ) {
      color(new_row, new_col, updated_image, image, newColor, delRow, delCol,
            iniC);
    }
  }
}

vector<vector<long double>> floodFill(vector<vector<long double>> image,
                                      long double start_row,
                                      long double start_col,
                                      long double newColor) {

  long double initial_color = image[start_row][start_col];
  vector<vector<long double>> updated_image = image;
  long double delRow[] = {-1, 0, +1, 0};
  long double delCol[] = {0, +1, 0, -1};

  color(start_row, start_col, updated_image, image, newColor, delRow, delCol,
        initial_color);

  return updated_image;
}

vector<vector<long double>> processWithOne(vector<vector<long double>> image,
                                           long double newColor) {
  // printImage(image, 0);

  vector<vector<long double>> updated_Image = floodFill(image, 0, 0, newColor);

  for (long double i = 0; i < image.size(); i++) {
    for (long double j = 0; j < image[0].size(); j++) {
      if (image[i][j] == 1) {
        updated_Image = floodFill(updated_Image, i, j, newColor);
      }
    }
  }
  // updated_Image = floodFill(updated_Image, 0, 9, 2);

  return updated_Image;
}

int main() {
  // x : 9 , y : 10
  vector<vector<long double>> image = getTwoD_RepresentationMatrix();
  long double newColor = 100;

  // call flood fill where 1 is the value
  //  vector<vector<long double>> updated_Image = processWithOne(image,
  //  newColor);
  //  // printImage(updated_Image, 0);
  //  printImage(updated_Image, 1);

  vector<vector<long double>> updated_Image = floodFill(image, 202, 0, newColor);

  writeOutput(updated_Image);

  return 0;
}