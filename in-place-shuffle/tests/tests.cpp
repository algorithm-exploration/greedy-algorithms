void printVector(const char* title, const vector<int>& theVector)
{
    cout << title << ": [";
    bool isFirst = true;
    for (int value: theVector) {
        if (isFirst) {
            isFirst = false;
        } else {
            cout << ", ";
        }
        cout << value;
    }
    cout << ']' << endl;
}

int main(int argc, char** argv)
{
    const vector<int> initial {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> shuffled(initial);
    shuffle(shuffled);
    printVector("initial vector", initial);
    printVector("shuffled vector", shuffled);
    return 0;
}
