

#include <iostream>
#include <string>

using namespace std;

int startMatrix[48];
int tempMatrix[48];
int workingMatrix[48];
int permutations = 0;
int temp;

bool arraysEqual(int i[48], int j[48]){
    temp = 0;
    for (int k = 0; k < 48; k++){
        if (i[k] != j[k]){
            temp++;
        }
    }
    if (temp == 0){
        return true;
    } else {
        return false;
    }
}

void R(void){
    tempMatrix[0] = workingMatrix[0];
    tempMatrix[1] = workingMatrix[1];
    tempMatrix[2] = workingMatrix[34];
    tempMatrix[3] = workingMatrix[35];
    tempMatrix[4] = workingMatrix[36];
    tempMatrix[5] = workingMatrix[5];
    tempMatrix[6] = workingMatrix[6];
    tempMatrix[7] = workingMatrix[7];
    tempMatrix[8] = workingMatrix[14];
    tempMatrix[9] = workingMatrix[15];
    tempMatrix[10] = workingMatrix[8];
    tempMatrix[11] = workingMatrix[9];
    tempMatrix[12] = workingMatrix[10];
    tempMatrix[13] = workingMatrix[11];
    tempMatrix[14] = workingMatrix[12];
    tempMatrix[15] = workingMatrix[13];
    tempMatrix[16] = workingMatrix[44];
    tempMatrix[17] = workingMatrix[17];
    tempMatrix[18] = workingMatrix[18];
    tempMatrix[19] = workingMatrix[19];
    tempMatrix[20] = workingMatrix[20];
    tempMatrix[21] = workingMatrix[21];
    tempMatrix[22] = workingMatrix[42];
    tempMatrix[23] = workingMatrix[43];
    tempMatrix[24] = workingMatrix[24];
    tempMatrix[25] = workingMatrix[25];
    tempMatrix[26] = workingMatrix[26];
    tempMatrix[27] = workingMatrix[27];
    tempMatrix[28] = workingMatrix[28];
    tempMatrix[29] = workingMatrix[29];
    tempMatrix[30] = workingMatrix[30];
    tempMatrix[31] = workingMatrix[31];
    tempMatrix[32] = workingMatrix[32];
    tempMatrix[33] = workingMatrix[33];
    tempMatrix[34] = workingMatrix[22];
    tempMatrix[35] = workingMatrix[23];
    tempMatrix[36] = workingMatrix[16];
    tempMatrix[37] = workingMatrix[37];
    tempMatrix[38] = workingMatrix[38];
    tempMatrix[39] = workingMatrix[39];
    tempMatrix[40] = workingMatrix[40];
    tempMatrix[41] = workingMatrix[41];
    tempMatrix[42] = workingMatrix[2];
    tempMatrix[43] = workingMatrix[3];
    tempMatrix[44] = workingMatrix[4];
    tempMatrix[45] = workingMatrix[45];
    tempMatrix[46] = workingMatrix[46];
    tempMatrix[47] = workingMatrix[47];
    
    memcpy(workingMatrix, tempMatrix, sizeof(tempMatrix));
}
void U(void){
    tempMatrix[0] = workingMatrix[8];
    tempMatrix[1] = workingMatrix[9];
    tempMatrix[2] = workingMatrix[10];
    tempMatrix[3] = workingMatrix[3];
    tempMatrix[4] = workingMatrix[4];
    tempMatrix[5] = workingMatrix[5];
    tempMatrix[6] = workingMatrix[6];
    tempMatrix[7] = workingMatrix[7];
    tempMatrix[8] = workingMatrix[16];
    tempMatrix[9] = workingMatrix[17];
    tempMatrix[10] = workingMatrix[18];
    tempMatrix[11] = workingMatrix[11];
    tempMatrix[12] = workingMatrix[12];
    tempMatrix[13] = workingMatrix[13];
    tempMatrix[14] = workingMatrix[14];
    tempMatrix[15] = workingMatrix[15];
    tempMatrix[16] = workingMatrix[24];
    tempMatrix[17] = workingMatrix[25];
    tempMatrix[18] = workingMatrix[26];
    tempMatrix[19] = workingMatrix[19];
    tempMatrix[20] = workingMatrix[20];
    tempMatrix[21] = workingMatrix[21];
    tempMatrix[22] = workingMatrix[22];
    tempMatrix[23] = workingMatrix[23];
    tempMatrix[24] = workingMatrix[0];
    tempMatrix[25] = workingMatrix[1];
    tempMatrix[26] = workingMatrix[2];
    tempMatrix[27] = workingMatrix[27];
    tempMatrix[28] = workingMatrix[28];
    tempMatrix[29] = workingMatrix[29];
    tempMatrix[30] = workingMatrix[30];
    tempMatrix[31] = workingMatrix[31];
    tempMatrix[32] = workingMatrix[32];
    tempMatrix[33] = workingMatrix[33];
    tempMatrix[34] = workingMatrix[34];
    tempMatrix[35] = workingMatrix[35];
    tempMatrix[36] = workingMatrix[36];
    tempMatrix[37] = workingMatrix[37];
    tempMatrix[38] = workingMatrix[38];
    tempMatrix[39] = workingMatrix[39];
    tempMatrix[40] = workingMatrix[46];
    tempMatrix[41] = workingMatrix[47];
    tempMatrix[42] = workingMatrix[40];
    tempMatrix[43] = workingMatrix[41];
    tempMatrix[44] = workingMatrix[42];
    tempMatrix[45] = workingMatrix[43];
    tempMatrix[46] = workingMatrix[44];
    tempMatrix[47] = workingMatrix[45];
    
    memcpy(workingMatrix, tempMatrix, sizeof(tempMatrix));
}
void F(void){
    tempMatrix[0] = workingMatrix[6];
    tempMatrix[1] = workingMatrix[7];
    tempMatrix[2] = workingMatrix[0];
    tempMatrix[3] = workingMatrix[1];
    tempMatrix[4] = workingMatrix[2];
    tempMatrix[5] = workingMatrix[3];
    tempMatrix[6] = workingMatrix[4];
    tempMatrix[7] = workingMatrix[5];
    tempMatrix[8] = workingMatrix[46];
    tempMatrix[9] = workingMatrix[9];
    tempMatrix[10] = workingMatrix[10];
    tempMatrix[11] = workingMatrix[11];
    tempMatrix[12] = workingMatrix[12];
    tempMatrix[13] = workingMatrix[13];
    tempMatrix[14] = workingMatrix[44];
    tempMatrix[15] = workingMatrix[45];
    tempMatrix[16] = workingMatrix[16];
    tempMatrix[17] = workingMatrix[17];
    tempMatrix[18] = workingMatrix[18];
    tempMatrix[19] = workingMatrix[19];
    tempMatrix[20] = workingMatrix[20];
    tempMatrix[21] = workingMatrix[21];
    tempMatrix[22] = workingMatrix[22];
    tempMatrix[23] = workingMatrix[23];
    tempMatrix[24] = workingMatrix[24];
    tempMatrix[25] = workingMatrix[25];
    tempMatrix[26] = workingMatrix[32];
    tempMatrix[27] = workingMatrix[33];
    tempMatrix[28] = workingMatrix[34];
    tempMatrix[29] = workingMatrix[29];
    tempMatrix[30] = workingMatrix[30];
    tempMatrix[31] = workingMatrix[31];
    tempMatrix[32] = workingMatrix[14];
    tempMatrix[33] = workingMatrix[15];
    tempMatrix[34] = workingMatrix[8];
    tempMatrix[35] = workingMatrix[35];
    tempMatrix[36] = workingMatrix[36];
    tempMatrix[37] = workingMatrix[37];
    tempMatrix[38] = workingMatrix[38];
    tempMatrix[39] = workingMatrix[39];
    tempMatrix[40] = workingMatrix[40];
    tempMatrix[41] = workingMatrix[41];
    tempMatrix[42] = workingMatrix[42];
    tempMatrix[43] = workingMatrix[43];
    tempMatrix[44] = workingMatrix[26];
    tempMatrix[45] = workingMatrix[27];
    tempMatrix[46] = workingMatrix[28];
    tempMatrix[47] = workingMatrix[47];
    
    memcpy(workingMatrix, tempMatrix, sizeof(tempMatrix));
}
void L(void){
    tempMatrix[0] = workingMatrix[40];
    tempMatrix[1] = workingMatrix[1];
    tempMatrix[2] = workingMatrix[2];
    tempMatrix[3] = workingMatrix[3];
    tempMatrix[4] = workingMatrix[4];
    tempMatrix[5] = workingMatrix[5];
    tempMatrix[6] = workingMatrix[46];
    tempMatrix[7] = workingMatrix[47];
    tempMatrix[8] = workingMatrix[8];
    tempMatrix[9] = workingMatrix[9];
    tempMatrix[10] = workingMatrix[10];
    tempMatrix[11] = workingMatrix[11];
    tempMatrix[12] = workingMatrix[12];
    tempMatrix[13] = workingMatrix[13];
    tempMatrix[14] = workingMatrix[14];
    tempMatrix[15] = workingMatrix[15];
    tempMatrix[16] = workingMatrix[16];
    tempMatrix[17] = workingMatrix[17];
    tempMatrix[18] = workingMatrix[38];
    tempMatrix[19] = workingMatrix[39];
    tempMatrix[20] = workingMatrix[32];
    tempMatrix[21] = workingMatrix[21];
    tempMatrix[22] = workingMatrix[22];
    tempMatrix[23] = workingMatrix[23];
    tempMatrix[24] = workingMatrix[30];
    tempMatrix[25] = workingMatrix[31];
    tempMatrix[26] = workingMatrix[24];
    tempMatrix[27] = workingMatrix[25];
    tempMatrix[28] = workingMatrix[26];
    tempMatrix[29] = workingMatrix[27];
    tempMatrix[30] = workingMatrix[28];
    tempMatrix[31] = workingMatrix[29];
    tempMatrix[32] = workingMatrix[0];
    tempMatrix[33] = workingMatrix[33];
    tempMatrix[34] = workingMatrix[34];
    tempMatrix[35] = workingMatrix[35];
    tempMatrix[36] = workingMatrix[36];
    tempMatrix[37] = workingMatrix[37];
    tempMatrix[38] = workingMatrix[6];
    tempMatrix[39] = workingMatrix[7];
    tempMatrix[40] = workingMatrix[20];
    tempMatrix[41] = workingMatrix[41];
    tempMatrix[42] = workingMatrix[42];
    tempMatrix[43] = workingMatrix[43];
    tempMatrix[44] = workingMatrix[44];
    tempMatrix[45] = workingMatrix[45];
    tempMatrix[46] = workingMatrix[18];
    tempMatrix[47] = workingMatrix[19];
    
    memcpy(workingMatrix, tempMatrix, sizeof(tempMatrix));
}
void B(void){
    tempMatrix[0] = workingMatrix[0];
    tempMatrix[1] = workingMatrix[1];
    tempMatrix[2] = workingMatrix[2];
    tempMatrix[3] = workingMatrix[3];
    tempMatrix[4] = workingMatrix[4];
    tempMatrix[5] = workingMatrix[5];
    tempMatrix[6] = workingMatrix[6];
    tempMatrix[7] = workingMatrix[7];
    tempMatrix[8] = workingMatrix[8];
    tempMatrix[9] = workingMatrix[9];
    tempMatrix[10] = workingMatrix[36];
    tempMatrix[11] = workingMatrix[37];
    tempMatrix[12] = workingMatrix[38];
    tempMatrix[13] = workingMatrix[13];
    tempMatrix[14] = workingMatrix[14];
    tempMatrix[15] = workingMatrix[15];
    tempMatrix[16] = workingMatrix[22];
    tempMatrix[17] = workingMatrix[23];
    tempMatrix[18] = workingMatrix[16];
    tempMatrix[19] = workingMatrix[17];
    tempMatrix[20] = workingMatrix[18];
    tempMatrix[21] = workingMatrix[19];
    tempMatrix[22] = workingMatrix[20];
    tempMatrix[23] = workingMatrix[21];
    tempMatrix[24] = workingMatrix[42];
    tempMatrix[25] = workingMatrix[25];
    tempMatrix[26] = workingMatrix[26];
    tempMatrix[27] = workingMatrix[27];
    tempMatrix[28] = workingMatrix[28];
    tempMatrix[29] = workingMatrix[29];
    tempMatrix[30] = workingMatrix[40];
    tempMatrix[31] = workingMatrix[41];
    tempMatrix[32] = workingMatrix[32];
    tempMatrix[33] = workingMatrix[33];
    tempMatrix[34] = workingMatrix[34];
    tempMatrix[35] = workingMatrix[35];
    tempMatrix[36] = workingMatrix[30];
    tempMatrix[37] = workingMatrix[31];
    tempMatrix[38] = workingMatrix[24];
    tempMatrix[39] = workingMatrix[39];
    tempMatrix[40] = workingMatrix[10];
    tempMatrix[41] = workingMatrix[11];
    tempMatrix[42] = workingMatrix[12];
    tempMatrix[43] = workingMatrix[43];
    tempMatrix[44] = workingMatrix[44];
    tempMatrix[45] = workingMatrix[45];
    tempMatrix[46] = workingMatrix[46];
    tempMatrix[47] = workingMatrix[47];
    
    memcpy(workingMatrix, tempMatrix, sizeof(tempMatrix));
}
void D(void){
    tempMatrix[0] = workingMatrix[0];
    tempMatrix[1] = workingMatrix[1];
    tempMatrix[2] = workingMatrix[2];
    tempMatrix[3] = workingMatrix[3];
    tempMatrix[4] = workingMatrix[28];
    tempMatrix[5] = workingMatrix[29];
    tempMatrix[6] = workingMatrix[30];
    tempMatrix[7] = workingMatrix[7];
    tempMatrix[8] = workingMatrix[8];
    tempMatrix[9] = workingMatrix[9];
    tempMatrix[10] = workingMatrix[10];
    tempMatrix[11] = workingMatrix[11];
    tempMatrix[12] = workingMatrix[4];
    tempMatrix[13] = workingMatrix[5];
    tempMatrix[14] = workingMatrix[6];
    tempMatrix[15] = workingMatrix[15];
    tempMatrix[16] = workingMatrix[16];
    tempMatrix[17] = workingMatrix[17];
    tempMatrix[18] = workingMatrix[18];
    tempMatrix[19] = workingMatrix[19];
    tempMatrix[20] = workingMatrix[12];
    tempMatrix[21] = workingMatrix[13];
    tempMatrix[22] = workingMatrix[14];
    tempMatrix[23] = workingMatrix[23];
    tempMatrix[24] = workingMatrix[24];
    tempMatrix[25] = workingMatrix[25];
    tempMatrix[26] = workingMatrix[26];
    tempMatrix[27] = workingMatrix[27];
    tempMatrix[28] = workingMatrix[20];
    tempMatrix[29] = workingMatrix[21];
    tempMatrix[30] = workingMatrix[22];
    tempMatrix[31] = workingMatrix[31];
    tempMatrix[32] = workingMatrix[38];
    tempMatrix[33] = workingMatrix[39];
    tempMatrix[34] = workingMatrix[32];
    tempMatrix[35] = workingMatrix[33];
    tempMatrix[36] = workingMatrix[34];
    tempMatrix[37] = workingMatrix[35];
    tempMatrix[38] = workingMatrix[36];
    tempMatrix[39] = workingMatrix[37];
    tempMatrix[40] = workingMatrix[40];
    tempMatrix[41] = workingMatrix[41];
    tempMatrix[42] = workingMatrix[42];
    tempMatrix[43] = workingMatrix[43];
    tempMatrix[44] = workingMatrix[44];
    tempMatrix[45] = workingMatrix[45];
    tempMatrix[46] = workingMatrix[46];
    tempMatrix[47] = workingMatrix[47];
    
    memcpy(workingMatrix, tempMatrix, sizeof(tempMatrix));
}
void Ri(void){
    R();
    R();
    R();
}
void Ui(void){
    U();
    U();
    U();
}
void Fi(void){
    F();
    F();
    F();
}
void Li(void){
    L();
    L();
    L();
}
void Bi(void){
    B();
    B();
    B();
}
void Di(void){
    D();
    D();
    D();
}

void algorithm(void){
    U();
    R();
    Fi();
    Di();
    U();
    L();
    B();
}

int main(int argc, const char * argv[])
{
    startMatrix[0] = 0;
    startMatrix[1] = 0;
    startMatrix[2] = 0;
    startMatrix[3] = 0;
    startMatrix[4] = 0;
    startMatrix[5] = 0;
    startMatrix[6] = 0;
    startMatrix[7] = 0;
    startMatrix[8] = 1;
    startMatrix[9] = 1;
    startMatrix[10] = 1;
    startMatrix[11] = 1;
    startMatrix[12] = 1;
    startMatrix[13] = 1;
    startMatrix[14] = 1;
    startMatrix[15] = 1;
    startMatrix[16] = 2;
    startMatrix[17] = 2;
    startMatrix[18] = 2;
    startMatrix[19] = 2;
    startMatrix[20] = 2;
    startMatrix[21] = 2;
    startMatrix[22] = 2;
    startMatrix[23] = 2;
    startMatrix[24] = 3;
    startMatrix[25] = 3;
    startMatrix[26] = 3;
    startMatrix[27] = 3;
    startMatrix[28] = 3;
    startMatrix[29] = 3;
    startMatrix[30] = 3;
    startMatrix[31] = 3;
    startMatrix[32] = 4;
    startMatrix[33] = 4;
    startMatrix[34] = 4;
    startMatrix[35] = 4;
    startMatrix[36] = 4;
    startMatrix[37] = 4;
    startMatrix[38] = 4;
    startMatrix[39] = 4;
    startMatrix[40] = 5;
    startMatrix[41] = 5;
    startMatrix[42] = 5;
    startMatrix[43] = 5;
    startMatrix[44] = 5;
    startMatrix[45] = 5;
    startMatrix[46] = 5;
    startMatrix[47] = 5;
    
    memcpy(workingMatrix, startMatrix, sizeof(startMatrix));
    
    cout << "\nAfter " << permutations << " permutations:\n";
    for (int i = 0; i < 48; i++){
        cout << workingMatrix[i] << ", ";
    }
    algorithm();
    permutations++;
    while (arraysEqual(startMatrix, workingMatrix) == false){
        cout << "\nAfter " << permutations << " permutations:\n";
        for (int i = 0; i < 48; i++){
            cout << workingMatrix[i] << ", ";
        }
        algorithm();
        permutations++;
    }
    cout << "\nAfter " << permutations << " permutations:\n";
    for (int i = 0; i < 48; i++){
        cout << workingMatrix[i] << ", ";
    }
    cout << "\nNumber of permutations: " << permutations;
    
    return 0;
}
