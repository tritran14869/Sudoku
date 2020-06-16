#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctype.h>


// Hiển thị và phát sinh:
void InTen(int maMau);
void PhatSinhSudoku0(FILE *f, int z[9][9], int p[9][9], int deSudoku[9][9]);
void DocSudoku(FILE *f, int z[9][9]);
void XuatSudoku(int z[9][9]);
int CapNhatSudoku(char diaChi[], int p[9][9], int deSudoku[9][9], int giaTri);
void XuatSudokuCapNhat(int giaTri, char diaChi[], int p[9][9], int deSudoku[9][9]);
int LuuSudoku(FILE *f, int p[9][9]);
void InChonOSudoku();
void InChucNangVao();
void ToMau(int x);

// Kiểm tra:
int KiemTra1Hang(int p[9][9], int dong, int x);
int KiemTra1Cot(int p[9][9], int cot);
int KiemTraVung3x3(int p[9][9], int x, int y);
int KiemTraHoanThanhSudoku(int p[9][9], int z[9][9]);
void KiemTraMotGiaTriDuocCapNhat(int p[9][9], int z[9][9], int deSudoku[9][9], int dong, int cot);

// Chức năng:
void HienThiBanChucNang();
void HuongDanChoi();
int GoiYNguoiChoi(char diaChi[], int z[9][9]);
void GiaiToanBoSudokuBoiMay(int z[9][9], int deSudoku[9][9]);
void ToMauMotGiaTriSai(int z[9][9], int p[9][9], int deSudoku[9][9]);
void ToMauNhieuGiaTriSai(int z[9][9], int p[9][9], int deSudoku[9][9]);

// Hàm phụ tính kết quả sudoku:
void ChuyenMang2ChieuThanhMang1Chieu(int z[9][9], int w[81]);
void ChuyenMang1ChieuThanhMang2Chieu(int z[9][9], int w[81]);

// Tính kết quả sudoku:
int TinhKetQuaSudoku(int w[81], int** hang, int** col, int** hinh, int khuon, int dong);
void GiaiSudoku(int z[9][9], int w[81]);