/*********************
Name: Julian Cotto
Assignment 5 - Stacks
Purpose: source file for main.h total stack test
**********************/

#include "main.h"

int main(int argc, char **argv) {
    srand(time(NULL));

    int errorCode = 0;
    int* errorPtr = &errorCode;
    bool validInput = false;
    bool* validInputPtr = &validInput;

    verifyInput(argc, argv, errorPtr, validInputPtr);

    while (validInput) {
        cout << "Program has begun" << endl;

        string strTemp;
        int value;
        int stackSize = atoi(argv[1]);

        Stack stack(stackSize);
        Data d;

        /************************************************
        ******* EMPTY TESTS *****************************
        ************************************************/

        cout << "Beginning tests..." << endl << endl << "Testing empty operations." << endl;
        cout << "=====================================================" << endl;

        // testing isEmpty() on empty stack
        if (stack.isEmpty()) {
            cout << "stack is empty" << endl;
        } else {
            cout << "stack is NOT empty" << endl;
        }

        // testing peek() and pop() on empty stack
        if(stack.peek(&d, errorPtr)) {
            cout << "peeked" << endl;
        }errorCode = 0;

        if(stack.pop(&d, errorPtr)){
            cout << "popped" << endl;
        }errorCode = 0;

        /************************************************
        ******** FILLING AND FULL TESTS *****************
        ************************************************/

        cout << "Testing full operations." << endl;
        cout << "=====================================================" << endl;

        // testing filling the stack and overflow
        cout << "Filling stack..." << endl;
        for (int i = 0; i <= stackSize*MULTIPLIER; i++) {
            rand_string(&strTemp);
            value = rand()%2 ? -(i + 1) : i+1; // 50/50 negative or positive number
            if (strTemp.empty()) {
                *errorPtr = 8;
                errorCases(errorCode);
            } else {
                cout << "id: " << value << " | str: " << strTemp << endl;
                if (stack.push(value, &strTemp, errorPtr)) {
                    cout << "pushed" << endl;
                    errorCases(errorCode);
                } else {
                    cout << "not pushed" << endl;
                    errorCases(errorCode);
                }
            }
            cout << endl;
        } errorCode = 0;

        // testing isEmpty() on full stack
        if (stack.isEmpty()) {
            cout << "stack is empty" << endl;
        } else {
            cout << "stack is NOT empty" << endl;
        } errorCode = 0;

        // testing peek() and pop() on full stack
        if(stack.peek(&d, errorPtr)) {
            cout << "peeked " << d.id << " value: " << d.information << endl;
        } errorCode = 0;

        if(stack.pop(&d, errorPtr)){
            cout << "popped " << d.id << " value: " << d.information << endl;
        } errorCode = 0;

        cout << endl;

        /************************************************
    	******** EMPTYING AND EMPTY TESTS ***************
    	************************************************/

        cout << "Testing peek and pop, and emptying stack..." << endl;
        cout << "=====================================================" << endl;

        for(int i = 0; i < stackSize*MULTIPLIER; i++){
            if (stack.peek(&d, errorPtr)) {
                cout << "peeked " << d.id << " value: " << d.information << endl;
            }
            errorCases(errorCode);
            if (stack.pop(&d, errorPtr)) {
                cout << "popped " << d.id << " value: " << d.information << endl;

            }
            errorCases(errorCode);
            cout << endl;
        }
        cout << endl;

        // testing peek() and pop() on empty stack
        if(stack.peek(&d, errorPtr)) {
            cout << "peeked " << d.id << " value: " << d.information << endl;
        }
        errorCases(errorCode);

        if(stack.pop(&d, errorPtr)){
            cout << "popped " << d.id << " value: " << d.information << endl;
        }
        errorCases(errorCode);
        errorCode = 0;
        /************************************************
        ******** MID-STACK TESTS ************************
        ************************************************/

        cout << "Filling stack halfway and testing the middle of the stack..." << endl;
        cout << "============================================================" << endl;

        // filling the stack half way to test the middle of the stack
        for (int i = 0; i < stackSize/2; i++) {
            rand_string(&strTemp);
            value = rand()%2 ? -(i + 1) : i+1; // 50/50 negative or positive number
            if (strTemp.empty()) {
                *errorPtr = 8;
                errorCases(errorCode);
            } else {
                cout << "id: " << value << " | str: " << strTemp << endl;
                if (stack.push(value, &strTemp, errorPtr)) {
                    cout << "pushed" << endl;
                    errorCases(errorCode);
                } else {
                    cout << "not pushed" << endl;
                    errorCases(errorCode);
                }
            }
            cout << endl;
        } errorCode = 0;

        // testing middle in a narrow band
        for (int i = 0; i < stackSize*NARROW; i++) {
            if (stack.isEmpty()) {
                cout << "stack is empty" << endl;
            } else {
                cout << "stack is NOT empty" << endl;
            }
            cout << endl;

            // testing peek() and pop() on empty stack
            if(stack.peek(&d, errorPtr)) {
                cout << "peeked " << d.id << " value: " << d.information << endl;
                errorCases(errorCode);
            } errorCode = 0;

            if (stack.pop(&d, errorPtr)) {
                cout << "popped " << d.id << " value: " << d.information << endl;
                errorCases(errorCode);
            } errorCode = 0;

            value = rand()%2 ? rand() % MAX_INT/2 + 1 : -(rand() % MAX_INT/2 + 1);
            rand_string(&strTemp);
            if(stack.push(value, &strTemp, errorPtr)) {
                cout << "pushed " << value << " value: " << strTemp << endl;
                errorCases(errorCode);
            } errorCode = 0;
            cout << endl;
        }

        /************************************************
        ******** RANDOM TESTS ***************************
        ************************************************/

        cout << "Random testing..." << endl;
        cout << "============================================================" << endl;

        // clearing stack to start
        while(!stack.isEmpty()){
            stack.pop(&d, errorPtr);
            cout << "popped " << d.id << " value: " << d.information << endl;
        } errorCode = 0;

        int choice = rand() % CHOICES + 1;
        for (int i = 0; i < stackSize*RANDOM_MULTIPLIER; i++) {
            switch(choice){
                case 1:
                case 2:
                    //push
                    value = rand()%2 ? rand() % MAX_INT/2 + 1 : -(rand() % MAX_INT/2 + 1);
                    rand_string(&strTemp);
                    if(stack.push(value, &strTemp, errorPtr)) {
                        cout << "pushed " << value << " value: " << strTemp << endl;
                        errorCases(errorCode);
                    } errorCode = 0;
                    break;
                case 3:
                case 4:
                    //pop
                    if (stack.pop(&d, errorPtr)) {
                        cout << "popped " << d.id << " value: " << d.information << endl;
                        errorCases(errorCode);
                    } errorCode = 0;
                    break;
                case 5:
                    //peek
                    if(stack.peek(&d, errorPtr)) {
                        cout << "peeked " << d.id << " value: " << d.information << endl;
                        errorCases(errorCode);
                    } errorCode = 0;
                    break;
                case 6:
                    //isEmpty
                    if (stack.isEmpty()) {
                        cout << "stack is empty" << endl;
                    } else {
                        cout << "stack is NOT empty" << endl;
                    }
                    break;
            }
            choice = rand() % CHOICES + 1;
        }
        cout << endl;

        cout << "Testing complete." << endl;
        validInput = false;
    }


    errorCases(errorCode);
    cout << "Program is Ending" << endl;

    return 0;
}
