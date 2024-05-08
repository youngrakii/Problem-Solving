#include <iostream>
#include <vector>
using namespace std;

// Function to check if all elements in the given sub-image are the same
bool allSame(const vector<string>& image, int x, int y, int size, char value) {
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (image[i][j] != value) {
                return false;
            }
        }
    }
    return true;
}

// Function to recursively compress the quad tree
string compressQuadTree(const vector<string>& image, int x, int y, int size) {
    // Base case: if the sub-image size is 1x1, return the pixel value
    if (size == 1) {
        return string(1, image[x][y]);
    }

    // Check if all pixels in the sub-image are the same
    char pixelValue = image[x][y];
    if (allSame(image, x, y, size, pixelValue)) {
        return string(1, pixelValue);
    }

    // Divide the sub-image into 4 quadrants
    int halfSize = size / 2;
    string upperLeft = compressQuadTree(image, x, y, halfSize);
    string upperRight = compressQuadTree(image, x, y + halfSize, halfSize);
    string lowerLeft = compressQuadTree(image, x + halfSize, y, halfSize);
    string lowerRight = compressQuadTree(image, x + halfSize, y + halfSize, halfSize);

    // Combine the compressed results
    return "(" + upperLeft + upperRight + lowerLeft + lowerRight + ")";
}

int main() {
    int N;
    cin >> N;

    // Input image
    vector<string> image(N);
    for (int i = 0; i < N; ++i) {
        cin >> image[i];
    }

    // Compress the quad tree
    string compressedResult = compressQuadTree(image, 0, 0, N);

    // Output the compressed result
    cout << compressedResult << endl;

    return 0;
}