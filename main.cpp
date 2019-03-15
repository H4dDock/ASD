#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "MyList.h"

int main(int argc, char* argv[]) {
    /*MyList<int> exampleInt;
    exampleInt.PushBack(1);
    exampleInt.PushBack(2);
    exampleInt.PushBack(3);
    cout << "After entered list: ";
    exampleInt.Show();
    exampleInt.Remove(0);
    exampleInt.PopBack();
    cout << "After removed 0, PopBack: ";
    exampleInt.Show();
    exampleInt.Set(10,0);
    cout << "After set(10,0): ";
    cout << exampleInt << endl;*/

    /*MyList<char> exampleInt;
    exampleInt.PushBack('a');
    exampleInt.PushBack('b');
    exampleInt.PushBack('c');
    exampleInt.Remove(0);
    exampleInt.PopBack();
    exampleInt.Set('z',0);
    cout << exampleInt << endl;*/

    /*MyList<string> exampleInt;
    exampleInt.PushBack("aaa");
    exampleInt.PushBack("bbb");
    exampleInt.PushBack("ccc");
    exampleInt.Remove(0);
    exampleInt.PopBack();
    exampleInt.Set("zzz",0);
    cout << exampleInt << endl;*/

    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}