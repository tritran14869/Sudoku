#include "sudoku.h"


void InChonOSudoku()
{
	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t        Nhan phim chon cac cau sudoku sau \n");
	printf("\n\t\t\t\t\t\t\t  _____    1. SUDOKU1 (cap do de)         _____\n");
	printf("\n\t\t\t\t\t\t\t  _____    2. SUDOKU2 (cap do de)         _____\n");
	printf("\n\t\t\t\t\t\t\t  _____    3. SUDOKU3 (cap do de)         _____\n");
	printf("\n\t\t\t\t\t\t\t  _____    4. SUDOKU4 (cap do trung binh) _____\n");
	printf("\n\t\t\t\t\t\t\t  _____    5. SUDOKU5 (cap do kho)        _____\n");
	printf("\n\n\t\t\t\t\t\t\t  _____            6. Tro ve              _____\n");
	printf("\n\t\t\t\t\t\t\t\t        -->> ");
	
}
void InTen(int maMau)
{
	ToMau(maMau);
	printf("\t\t\t\t\t\t\t\t*********************************\n");
	printf("\t\t\t\t\t\t\t\t*				*\n");
	printf("\t\t\t\t\t\t\t\t*				*\n");
	printf("\t\t\t\t\t\t\t\t*  T R O  C H O I  S U D O K U	*\n");
	printf("\t\t\t\t\t\t\t\t*				*\n");
	printf("\t\t\t\t\t\t\t\t*				*\n");
	printf("\t\t\t\t\t\t\t\t*********************************\n");
}

void InChucNangVao()
{
	printf("\n\n\t\t\t\t\t\t\t\tNhan phim chon cac chuc nang sau: \n");
	ToMau(7);
	printf("\n\t\t\t\t\t\t\t\t   _____   1. Huong dan   _____\n");
	ToMau(2);
	printf("\n\t\t\t\t\t\t\t\t   _____  2. Tro choi moi _____\n");
	ToMau(6);
	printf("\n\t\t\t\t\t\t\t\t   _____   3. Choi tiep   _____\n");
	ToMau(8);
	printf("\n\t\t\t\t\t\t\t\t   _____     4. Thoat     _____\n");
}
void HienThiBanChucNang()
{

	printf("\n\n\t\t\t\t\t\t\t\tNhan phim chuc nang de lua chon:\n");
	printf("\t\t\t\t\t\t\t    +----------------------------------------+\n");
	printf(" \t\t\t\t\t\t\t    G. Goi y gia tri mot o\n");
	printf(" \t\t\t\t\t\t\t    I. Tim 1 loi sai khi hoan thanh sudoku\n");
	printf(" \t\t\t\t\t\t\t    M. Loi giai\n");
	printf(" \t\t\t\t\t\t\t    F. Dien het cac o trong con lai\n");
	printf(" \t\t\t\t\t\t\t    C. Kiem tra gia tri duoc cap nhat(sai hien mau do)\n\n");

	printf("\t\t\t\t\t\t\t    +----------------------------------------+\n");
	printf(" \t\t\t\t\t\t\t    R. Ve tuy chon chinh\n");
	printf(" \t\t\t\t\t\t\t    N. Bat dau lai\n");
	printf(" \t\t\t\t\t\t\t    O. Mo mot SUDOKU moi\n\n");

	printf("\t\t\t\t\t\t\t    +----------------------------------------+\n");
	printf(" \t\t\t\t\t\t\t    S. Luu va thoat\n");
	printf(" \t\t\t\t\t\t\t    E. Thoat\n");
}

void HuongDanChoi()
{
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t        HUONG DAN CHOI SUDUKU 9x9\n");
	printf("\n\n\n\t\t\t\t\t\t\t- Yeu cau de co duoc mot sudoku hoan chinh va dung:\n");
	printf("\t\t\t\t\t\t\t\t+ Cac dong deu co cac so tu 1 den 9.\n");
	printf("\t\t\t\t\t\t\t\t+ Cac cot deu co cac so tu 1 den 9.\n");
	printf("\t\t\t\t\t\t\t\t+ Cac o trong vung 3x3 co cac so tu 1 den 9.\n\n");
	printf("\n\t\t\t\t\t\t\t- Nguoi choi dien vao o trong bang cach:\n");
	printf("\t\t\t\t\t\t\t\t+ Nhap vao dia chi(hoac phim chuc nang).\n");
	printf("\t\t\t\t\t\t\t\t+ Nhap mot gia tri.\n");
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1. Tro ve tuy chon chinh\n");
	printf("\n\t\t\t\t\t\t\t2. Thoat\n");
}
void PhatSinhSudoku0(FILE *f, int z[9][9], int p[9][9], int deSudoku[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			fread(&z[i][j], 4, 1, f);
			p[i][j] = z[i][j];
			deSudoku[i][j] = z[i][j];
		}
	}
}
void XuatSudokuCapNhat(int giaTri, char diaChi[], int p[9][9], int deSudoku[9][9])
{
	int hang = 9, cot = 9;
	for (int i = 0; i < 2; i++)
	{
		if ('a' <= diaChi[i] && diaChi[i] <= 'i')
			cot = diaChi[i] - '0' - 49;
		if ('0' <= diaChi[i] && diaChi[i] <= '8')
			hang = diaChi[i] - '0';
	}
	
	printf("\t\t");
	printf("   ");
	for (int i = 97; i < 106; i++)
	{
		ToMau(14);
		printf("%c ", i);
		ToMau(15);
	}
	printf("\n");
	printf("\t\t");
	printf("  -------------------\n");

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i == hang && j == cot)
			{
				p[i][j] = giaTri;
				if (p[i][j] == 0)
				{
					if (j == 8)
					{
						printf("%c |", 32);
					}

					else if (j == 0)
					{
						ToMau(5);
						printf("\t\t");
						printf("%d", i);
						ToMau(15);
						printf("| %c ", 32);
					}
					else
					{
						printf("%c ", 32);
					}

				}

				else
				{
					if (j == 8)
					{
						ToMau(10);
						printf("%d", p[i][j]);
						ToMau(15);
						printf(" |");
						
					}
						
					else if (j == 0)
					{
						ToMau(5);
						printf("\t\t");
						printf("%d", i);
						ToMau(15);
						printf("| ");
						ToMau(10);
						printf("%d ", p[i][j]);
						ToMau(15);
					}
					else
					{
						ToMau(10);
						printf("%d ", p[i][j]);
						ToMau(15);

					}
						
				}

			}
			else if (deSudoku[i][j] == 0 && p[i][j] != 0)
			{
				if (p[i][j] == 0)
				{
					if (j == 8)
					{
						printf("%c |", 32);
					}

					else if (j == 0)
					{
						ToMau(5);
						printf("\t\t");
						printf("%d", i);
						ToMau(15);
						printf("| %c ", 32);
					}
					else
					{
						printf("%c ", 32);
					}

				}

				else
				{
					if (j == 8)
					{
						ToMau(10);
						printf("%d", p[i][j]);
						ToMau(15);
						printf(" |");

					}

					else if (j == 0)
					{
						ToMau(5);
						printf("\t\t");
						printf("%d", i);
						ToMau(15);
						printf("| ");
						ToMau(10);
						printf("%d ", p[i][j]);
						ToMau(15);
					}
					else
					{
						ToMau(10);
						printf("%d ", p[i][j]);
						ToMau(15);

					}

				}

			}
			else
			{
				if (p[i][j] == 0)
				{
					if (j == 8)
					{
						printf("%c |", 32);
					}

					else if (j == 0)
					{
						ToMau(5);
						printf("\t\t");
						printf("%d", i);
						ToMau(15);
						printf("| %c ", 32);
					}
					else
					{
						printf("%c ", 32);
					}

				}

				else
				{
					if (j == 8)
						printf("%d |", p[i][j]);
					else if (j == 0)
					{
						ToMau(5);
						printf("\t\t");
						printf("%d", i);
						ToMau(15);
						printf("| %d ", p[i][j]);
					}
					else
						printf("%d ", p[i][j]);
				}
			}
		}
		printf("\n");
	}
	printf("\t\t");
	printf("  -------------------\n");
}
int CapNhatSudoku(char diaChi[], int p[9][9], int deSudoku[9][9], int giaTri)
{
	int doDai;
	int hang = 9;
	int cot = 9;

	diaChi = strlwr(diaChi);
	doDai = strlen(diaChi);

	if (doDai > 2)
		return 0;
	if (9 < giaTri && giaTri < 0)
		return 0;
	else
	{
		for (int i = 0; i < 2; i++)
		{
			if ('a' <= diaChi[i] && diaChi[i] <= 'i')
				cot = diaChi[i] - '0' - 49;
			if ('0' <= diaChi[i] && diaChi[i] <= '8')
				hang = diaChi[i] - '0';
		}
		if (hang > 8 || hang < 0 || cot > 8 || cot < 0)
			return 0;
	}
	if (deSudoku[hang][cot] != 0)	// Không cập nhật giá trị do là giá trị của đề.
		return -1;
	else
	{
		return 1;
	}
		
	
}

int LuuSudoku(FILE *f, int p[9][9]) // Lưu Sudoku người chơi đang chơi.
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			fwrite(&p[i][j], 4, 1, f);
		}
	}
	return 1;
}

int KiemTra1Hang(int p[9][9], int hang, int cot)		// Hàm kiểm tra một dòng
{
	for (int i = 0; i < 9; i++)
	{
		if (i != cot)
		if (p[hang][cot] == p[hang][i])
			return 0;
	}
	return 1;
}

int KiemTra1Cot(int p[9][9],int dong, int cot)		// Hàm kiểm tra một cột
{
	for (int i = 0; i < 9; i++)
	{
		if (dong != i)
			if (p[dong][cot] == p[i][cot])
					return 0;
	}
	return 1;
}


int KiemTraVung3x3(int p[9][9], int x, int y) // Kiểm tra tại vùng 3 ô hợp lệ
{
	if (x >= 0 && x <= 2)
	{
		if (y >= 0 && y <= 2) // Xét các giá trị tại vùng 1
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (i == x && j == y)
						continue;
					else if (p[x][y] == p[i][j])
						return 0;
				}
			}
			return 1;
		}

		if (y >= 3 && y >= 5) // Xét các giá trị tại vùng 2
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 3; j < 5; j++)
				{
					if (i == x && j == y)
						continue;
					else if (p[x][y] == p[i][j])
						return 0;
				}
			}
			return 1;
		}

		if (y >= 6 && y <= 8) // Xét các giá trị tại vùng 3
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 6; j < 8; j++)
				{
					if (i == x && j == y)
						continue;
					else if (p[x][y] == p[i][j])
						return 0;
				}
			}
			return 1;
		}
	}
	if (x >= 3 && x <= 5)
	{
		if (y >= 0 && y <= 2) // Xét các giá trị tại vùng 4
		{
			for (int i = 3; i < 5; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (i == x && j == y)
						continue;
					else if (p[x][y] == p[i][j])
						return 0;
				}
			}
			return 1;
		}

		if (y >= 3 && y >= 5) // Xét các giá trị tại vùng 5
		{
			for (int i = 3; i < 5; i++)
			{
				for (int j = 3; j < 5; j++)
				{
					if (i == x && j == y)
						continue;
					else if (p[x][y] == p[i][j])
						return 0;
				}
			}
			return 1;
		}

		if (y >= 6 && y <= 8) // Xét các giá trị tại vùng 6
		{
			for (int i = 3; i < 5; i++)
			{
				for (int j = 6; j < 8; j++)
				{
					if (i == x && j == y)
						continue;
					else if (p[x][y] == p[i][j])
						return 0;
				}
			}
			return 1;
		}
	}

	if (x >= 6 && x <= 8)
	{
		if (y >= 0 && y <= 2) // Xét các giá trị tại vùng 7
		{
			for (int i = 6; i < 8; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (i == x && j == y)
						continue;
					else if (p[x][y] == p[i][j])
						return 0;
				}
			}
			return 1;
		}

		if (y >= 3 && y >= 5) // Xét các giá trị tại vùng 8
		{
			for (int i = 6; i < 8; i++)
			{
				for (int j = 3; j < 5; j++)
				{
					if (i == x && j == y)
						continue;
					else if (p[x][y] == p[i][j])
						return 0;
				}
			}
			return 1;
		}

		if (y >= 6 && y <= 8) // Xét các giá trị tại vùng 9
		{
			for (int i = 6; i < 8; i++)
			{
				for (int j = 6; j < 8; j++)
				{
					if (i == x && j == y)
						continue;
					else if (p[x][y] == p[i][j])
						return 0;
				}
			}
			return 1;
		}
	}
}

void KiemTraMotGiaTriDuocCapNhat(int p[9][9],int z[9][9], int deSudoku[9][9], int hang, int cot) // Kiểm tra số vừa nhập.
{
		printf("\t\t");
		printf("   ");
		for (int i = 97; i < 106; i++)
		{
			ToMau(14);
			printf("%c ", i);
			ToMau(15);
		}
		printf("\n");
		printf("\t\t");
		printf("  -------------------\n");

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (i == hang && j == cot)
				{
					if (p[i][j] != z[i][j] && deSudoku[i][j] == 0)
					{
						if (j == 8)
						{
							ToMau(4);
							printf("%d", p[i][j]);
							ToMau(15);
							printf(" |");
						}

						else if (j == 0)
						{
							ToMau(5);
							printf("\t\t");
							printf("%d", i);
							ToMau(15);
							printf("| ");
							ToMau(4);
							printf("%d ", p[i][j]);
							ToMau(15);
						}
						else
						{
							ToMau(4);
							printf("%d ", p[i][j]);
							ToMau(15);
						}
					}
					if (p[i][j] == z[i][j] && deSudoku[i][j] == 0)
					{
						if (j == 8)
						{
							ToMau(10);
							printf("%d", p[i][j]);
							ToMau(15);
							printf(" |");
						}

						else if (j == 0)
						{
							ToMau(5);
							printf("\t\t");
							printf("%d", i);
							ToMau(15);
							printf("| ");
							ToMau(10);
							printf("%d ", p[i][j]);
							ToMau(15);
						}
						else
						{
							ToMau(10);
							printf("%d ", p[i][j]);
							ToMau(15);
						}
					}
				}
				else
				{
					if (p[i][j] != 0 && deSudoku[i][j] == 0)
					{
						if (j == 8)
						{
							ToMau(10);
							printf("%d", p[i][j]);
							ToMau(15);
							printf(" |");
						}

						else if (j == 0)
						{
							ToMau(5);
							printf("\t\t");
							printf("%d", i);
							ToMau(15);
							printf("| ");
							ToMau(10);
							printf("%d ", p[i][j]);
							ToMau(15);
						}
						else
						{
							ToMau(10);
							printf("%d ", p[i][j]);
							ToMau(15);
						}
					}
					if (p[i][j] != 0 && deSudoku[i][j] != 0 && p[i][j] == deSudoku[i][j])
					{
						if (j == 8)
						{
							ToMau(15);
							printf("%d", p[i][j]);
							ToMau(15);
							printf(" |");
						}

						else if (j == 0)
						{
							ToMau(5);
							printf("\t\t");
							printf("%d", i);
							ToMau(15);
							printf("| ");
							ToMau(15);
							printf("%d ", p[i][j]);
							ToMau(15);
						}
						else
						{
							ToMau(15);
							printf("%d ", p[i][j]);
							ToMau(15);
						}
					}
					if (p[i][j] == 0)
					{
						if (j == 8)
						{
							printf("%c |", 32);
						}

						else if (j == 0)
						{
							ToMau(5);
							printf("\t\t");
							printf("%d", i);
							ToMau(15);
							printf("| %c ", 32);
						}
						else
						{
							printf("%c ", 32);
						}
					}
				}
			}
			printf("\n");
		}
		printf("\t\t");
		printf("  -------------------\n");
}

void ChuyenMang2ChieuThanhMang1Chieu(int z[9][9], int w[81])
{
	int k = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			w[k] = z[i][j];
			k++;
		}
	}
}
void ChuyenMang1ChieuThanhMang2Chieu(int z[9][9], int w[81])
{
	int k = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			z[i][j] = w[k];
			k++;
		}
	}
}
int TinhKetQuaSudoku(int w[81], int** hang, int** col, int** hinh, int dong)
{
	int i;
	
	if (dong == 81)
		return 1;
	if (w[dong])
		return TinhKetQuaSudoku(w, hang, col, hinh, dong + 1);
	for (i = 0; i < 9; i++)
	{
		if (!(hang[i][dong / 9] || col[i][dong%9] || hinh[i][(dong / 9 / 3)*3 + (dong%9) / 3]))
		{
			w[dong] = i + 1;
			hang[i][dong / 9] = 1;
			col[i][dong%9] = 1;
			hinh[i][(dong / 9 / 3)*3 + (dong%9) / 3] = 1;
			if (!TinhKetQuaSudoku(w, hang, col, hinh, dong + 1))
			{
				w[dong] = 0;
				hang[i][dong / 9] = 0;
				col[i][dong%9] = 0;
				hinh[i][(dong / 9 / 3)*3 + (dong%9) / 3] = 0;
			}
		}
	}
	if (!w[dong])
		return 0;
	return 1;
}

void GiaiSudoku(int z[9][9], int w[])
{
	int i, j;
	int **hang = new int *[9];
	int **col = new int *[9];
	int **hinh = new int *[9];


	for (i = 0; i < 9; i++)
	{
		hang[i] = (int *)calloc(9, sizeof(int));
		col[i] = (int *)calloc(9, sizeof(int));
		hinh[i] = (int *)calloc(9, sizeof(int));
	}

	for (j = 0; j < 81; j++)
	{
		if (w[j])
		{
			if ((hang[w[j] - 1][j / 9] || col[w[j] - 1][j%9] || hinh[w[j] - 1][(j / 9 / 3)*3 + (j%9) / 3]))
			{
				printf("Sudoku sai!!!\n");
				return;
			}
			hang[w[j] - 1][j / 9] = 1;
			col[w[j] - 1][j%9] = 1;
			hinh[w[j] - 1][(j / 9 / 3)*3 + (j%9) / 3] = 1;
		}
	}
	if (TinhKetQuaSudoku(w, hang, col, hinh, 0))
	{
		ChuyenMang1ChieuThanhMang2Chieu(z, w);
		//XuatSudoku(z);
	}
	for (i = 0; i < 9; i++)
	{
		free(hang[i]);
		free(col[i]);
		free(hinh[i]);
	}

	
	free(hang);
	free(col);
	free(hinh);
	
}
void ToMau(int x) // Tô màu chữ
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void DocSudoku(FILE *f, int z[9][9]) // Hàm đọc sudoku từ tập tin đầu vào.
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			fread(&z[i][j], 4, 1, f);
		}
	}
}

void XuatSudoku(int z[9][9]) // Xuất ra sudoku.
{
	printf("\t\t");
	printf("   ");
	for (int i = 97; i < 106; i++)
	{
		ToMau(14);
		printf("%c ", i);
		ToMau(15);
	}
	printf("\n");
	printf("\t\t");
	printf("  -------------------\n");

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (z[i][j] == 0)
			{
				if (j == 8)
				{
					printf("%c |", 32);
				}

				else if (j == 0)
				{
					ToMau(5);
					printf("\t\t");
					printf("%d", i);
					ToMau(15);
					printf("| %c ", 32);
				}
				else
				{
					printf("%c ", 32);
				}
			}

			else
			{
				if (j == 8)
					printf("%d |", z[i][j]);
				else if (j == 0)
				{
					ToMau(5);
					printf("\t\t");
					printf("%d", i);
					ToMau(15);
					printf("| %d ", z[i][j]);
				}
				else
					printf("%d ", z[i][j]);
			}

		}
		printf("\n");
	}
	printf("\t\t");
	printf("  -------------------\n");
}


int KiemTraHoanThanhSudoku(int p[9][9], int z[9][9])		// Kiểm tra sudoku đã hoàn tất và đúng chưa.
{
	int demO = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (p[i][j] == 0)
				return 0;			// Chưa hoàn thành sudoku.
			if (p[i][j] == z[i][j])
				demO++;
		}
	}
	if (demO == 81)
		return 1;			// Hoàn thành và đúng.
	else
		return -1;			// Hoàn thành nhưng sai.
}


int GoiYNguoiChoi(char diaChi[], int z[9][9])			// Gợi ý người chơi theo yêu cầu địa chỉ.
{
	int hang, cot;
	for (int i = 0; i < 2; i++)
	{
		if ('a' <= diaChi[i] && diaChi[i] <= 'i')
			cot = diaChi[i] - '0' - 49;
		if ('0' <= diaChi[i] && diaChi[i] <= '8')
			hang = diaChi[i] - '0';
	}
	if (hang > 8 || hang < 0 || cot > 8 || cot < 0)
		return 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i == hang && j == cot)
				return z[i][j];
		}
	}
	return 0;
}

void GiaiToanBoSudokuBoiMay(int z[9][9], int deSudoku[9][9])
{
	printf("\t\t");
	printf("   ");
	for (int i = 97; i < 106; i++)
	{
		ToMau(14);
		printf("%c ", i);
		ToMau(15);
	}
	printf("\n");
	printf("\t\t");
	printf("  -------------------\n");

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (deSudoku[i][j] == 0)
			{
				if (j == 8)
				{
					ToMau(10);
					printf("%d", z[i][j]);
					ToMau(15);
					printf(" |");
				}

				else if (j == 0)
				{
					ToMau(5);
					printf("\t\t");
					printf("%d", i);
					ToMau(15);
					printf("| ");
					ToMau(10);
					printf("%d ", z[i][j]);
					ToMau(15);
				}
				else
				{
					ToMau(10);
					printf("%d ", z[i][j]);
					ToMau(15);
				}
			}
			else
			{
				if (j == 8)
				{
					ToMau(15);
					printf("%d", z[i][j]);
					ToMau(15);
					printf(" |");
				}

				else if (j == 0)
				{
					ToMau(5);
					printf("\t\t");
					printf("%d", i);
					ToMau(15);
					printf("| ");
					ToMau(15);
					printf("%d ", z[i][j]);
					ToMau(15);
				}
				else
				{
					ToMau(15);
					printf("%d ", z[i][j]);
					ToMau(15);
				}
			}

		}
		printf("\n");
	}
	printf("\t\t");
	printf("  -------------------\n");
}

void ToMauMotGiaTriSai(int z[9][9], int p[9][9], int deSudoku[9][9])
{
	int demSai = 0;
	printf("\t\t");
	printf("   ");
	for (int i = 97; i < 106; i++)
	{
		ToMau(14);
		printf("%c ", i);
		ToMau(15);
	}
	printf("\n");
	printf("\t\t");
	printf("  -------------------\n");

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (p[i][j] != z[i][j])
			{
				if (demSai == 0)
				{
					demSai++;
					if (j == 8)
					{
						ToMau(4);
						printf("%d", p[i][j]);
						ToMau(15);
						printf(" |");
					}

					else if (j == 0)
					{
						ToMau(5);
						printf("\t\t");
						printf("%d", i);
						ToMau(15);
						printf("| ");
						ToMau(4);
						printf("%d ", p[i][j]);
						ToMau(15);
					}
					else
					{
						ToMau(4);
						printf("%d ", p[i][j]);
						ToMau(15);
					}
				}
				else
				{
					if (j == 8)
					{
						ToMau(10);
						printf("%d", p[i][j]);
						ToMau(15);
						printf(" |");
					}

					else if (j == 0)
					{
						ToMau(5);
						printf("\t\t");
						printf("%d", i);
						ToMau(15);
						printf("| ");
						ToMau(10);
						printf("%d ", p[i][j]);
						ToMau(15);
					}
					else
					{
						ToMau(10);
						printf("%d ", p[i][j]);
						ToMau(15);
					}
				}
			}
			
			else
			{
				if (deSudoku[i][j] == 0)
				{
					if (j == 8)
					{
						ToMau(10);
						printf("%d", p[i][j]);
						ToMau(15);
						printf(" |");
					}

					else if (j == 0)
					{
						ToMau(5);
						printf("\t\t");
						printf("%d", i);
						ToMau(15);
						printf("| ");
						ToMau(10);
						printf("%d ", p[i][j]);
						ToMau(15);
					}
					else
					{
						ToMau(10);
						printf("%d ", p[i][j]);
						ToMau(15);
					}
				}
				else
				{
					if (j == 8)
					{
						ToMau(15);
						printf("%d", p[i][j]);
						ToMau(15);
						printf(" |");
					}

					else if (j == 0)
					{
						ToMau(5);
						printf("\t\t");
						printf("%d", i);
						ToMau(15);
						printf("| ");
						ToMau(15);
						printf("%d ", p[i][j]);
						ToMau(15);
					}
					else
					{
						ToMau(15);
						printf("%d ", p[i][j]);
						ToMau(15);
					}
				}

			}
				
		}
		printf("\n");
	}
	printf("\t\t");
	printf("  -------------------\n");
}

void ToMauNhieuGiaTriSai(int z[9][9], int p[9][9], int deSudoku[9][9])
{
	printf("\t\t");
	printf("   ");
	for (int i = 97; i < 106; i++)
	{
		ToMau(14);
		printf("%c ", i);
		ToMau(15);
	}
	printf("\n");
	printf("\t\t");
	printf("  -------------------\n");

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (p[i][j] != z[i][j])
			{
				if (j == 8)
				{
					ToMau(4);
					printf("%d", z[i][j]);
					ToMau(15);
					printf(" |");
				}
				else if (j == 0)
				{
					ToMau(5);
					printf("\t\t");
					printf("%d", i);
					ToMau(15);
					printf("| ");
					ToMau(4);
					printf("%d ", z[i][j]);
					ToMau(15);
				}
				else
				{
					ToMau(4);
					printf("%d ", z[i][j]);
					ToMau(15);
				}
		}
		else if (deSudoku[i][j] == 0)
		{
			if (j == 8)
			{
				ToMau(10);
				printf("%d", z[i][j]);
				ToMau(15);
				printf(" |");
			}

			else if (j == 0)
			{
				ToMau(5);
				printf("\t\t");
				printf("%d", i);
				ToMau(15);
				printf("| ");
				ToMau(10);
				printf("%d ", z[i][j]);
				ToMau(15);
			}
			else
			{
				ToMau(10);
				printf("%d ", z[i][j]);
				ToMau(15);
			}
		}
		else
			{
				if (j == 8)
				{
					ToMau(15);
					printf("%d", p[i][j]);
					ToMau(15);
					printf(" |");
				}

				else if (j == 0)
				{
					ToMau(5);
					printf("\t\t");
					printf("%d", i);
					ToMau(15);
					printf("| ");
					ToMau(15);
					printf("%d ", p[i][j]);
					ToMau(15);
				}
				else
				{
					ToMau(15);
					printf("%d ", p[i][j]);
					ToMau(15);
				}
			}
	}
		printf("\n");
	}
	printf("\t\t");
	printf("  -------------------\n");
}