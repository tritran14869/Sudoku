#include "sudoku.h"

void main()
{
	int static z[9][9];
	int static p[9][9];
	int static deSudoku[9][9];
	int w[81];
	char static diaChi[2], chucNang;
	char static chonTenSudoku[11] = "SUDOKU", chu[1], vungDemChonTenSudoku[11];
	int giaTri;
	int doDai;
	int coSai = 0;
	int kiemTraSudoku, chonChucNangVao, coKhong, chon, hang, cot;
	//int ktDong, ktCot, ktBang0; // Khai báo kiểm tra sudoku.


	FILE *s, *f;

	/*----------------------------------------TUY CHON DAU VAO----------------------------------------------*/
	dau:
	InTen(11);
	//HienThiBanChucNang();
	
	InChucNangVao();
	do
	{
		ToMau(13);
		printf("\n\t\t\t\t\t\t\t\t\t   -->> ");
		scanf("%d", &chonChucNangVao);
		ToMau(15);
		if (!(1 <= chonChucNangVao  && chonChucNangVao <= 4))
		{
			system("cls");
			goto dau;
		}
	} while (!(1 <= chonChucNangVao  && chonChucNangVao <= 4));


	if (chonChucNangVao == 1)
	{
		system("cls");
		HuongDanChoi();
		do
		{
			scanf("%d", &chon);
			if (chon == 1)
			{
				system("cls");
				goto dau;
			}
			if (chon == 2)
			{
				system("cls");
				goto S;
			}
		} while (2 < chon || chon < 1);
	}

	if (chonChucNangVao == 2)					// Chức năng 2: Chọn một sudoku mới.
	{
		O:
		do
		{
			fflush(stdin);
			system("cls");
			InTen(11);
			InChonOSudoku();
			scanf("%d", &chon);
			if (chonChucNangVao == 6)
			{
				system("cls");
				goto dau;
			}
		} while (6 < chonChucNangVao || chonChucNangVao <= 0);
		
		strcpy(vungDemChonTenSudoku, chonTenSudoku);
		itoa(chon, chu, 10);
		strcat(vungDemChonTenSudoku, chu);
		strcat(vungDemChonTenSudoku, ".in");
		system("cls");

		s = fopen(vungDemChonTenSudoku, "rb");
	}

	if (chonChucNangVao == 3)					// Chức năng 3: Chơi tiếp tục sudoku đã lưu.
	{
		system("cls");
		InTen(11);
		s = fopen("LuuSudoku.out", "rb");
	}

	if (chonChucNangVao == 4)					// Chức năng 4: thoát chương trình.
	{
		S:
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t       -- DANG DUNG CHUONG TRINH --\n");
		Sleep(2000);
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t      -- THOAT --\n");
		Sleep(1000);
		goto thoat;
	}



	/*-------------------------------------------VAO TRO CHOI-------------------------------------------------*/
	if (s != NULL)
	{
		N:
		InTen(11);
		HienThiBanChucNang();
		printf("\n\n");
		PhatSinhSudoku0(s, z, p, deSudoku);				// Phát sinh sudoku từ tập tin vào.
		XuatSudoku(z);
		ChuyenMang2ChieuThanhMang1Chieu(z, w);			// Giải sudoku để người chơi có thể so sánh.
		GiaiSudoku(z, w);
		do
		{
		nhaplai:
			if (coSai == 1)
			{
				printf("%s la o de bai!!!\n", diaChi);
				coSai = 0;
			}
			printf("Nhap dia chi hoac phim chuc nang: ");
			fflush(stdin);
			scanf("%s", &diaChi);
			doDai = strlen(diaChi);

			if (doDai == 1)
			{
				if (diaChi[0] == 'M' || diaChi[0] == 'G' || diaChi[0] == 'F' || diaChi[0] == 'C' || diaChi[0] == 'E' || diaChi[0] == 'S' || diaChi[0] == 'O' || diaChi[0] == 'R' || diaChi[0] == 'N' || diaChi[0] == 'I')
					goto phimchucnang;
			}

		nhaplaigiatri:
			fflush(stdin);
			printf("Gia tri: ");
			scanf("%d", &giaTri);
			if (10 <= giaTri || giaTri <= 0 || 'a' <= giaTri && giaTri <= 'z' || 'A' <= giaTri && giaTri <= 'Z')
			{
				goto nhaplaigiatri;
			}
			

			int k = CapNhatSudoku(diaChi, p, deSudoku, giaTri);

			if (k == -1)
			{
				coSai = 1;
				goto nhaplai;
			}

			if (k == 1)
			{
				system("cls");
				InTen(11);
				HienThiBanChucNang();
				XuatSudokuCapNhat(giaTri, diaChi, p, deSudoku);
			}

			if (k == 0)
			{
				//system("cls");
				//InTen(11);
				//HienThiBanChucNang();
				//XuatSudokuCapNhat(giaTri, diaChi, p, deSudoku);
				printf("\nNhap sai dia chi!!!\n");
				goto nhaplai;
				
			}

			kiemTraSudoku = KiemTraHoanThanhSudoku(p, z);
			if (kiemTraSudoku == 1)
				printf("\n\t\tGiai sudoku thanh cong!!!\n");

			if (kiemTraSudoku == -1)
			{
				system("cls");
				InTen(11);
				HienThiBanChucNang();
				XuatSudokuCapNhat(giaTri, diaChi, p, deSudoku);
				printf("\n\t\tBan da giai sai!!!\n");
			}

		} while (doDai == 2);
		
/*-------------------------------------------PHIM CHUC NANG-------------------------------------------------*/
		phimchucnang:
		if (diaChi[0] == 'G')							// G: Gợi ý một giá trị ô cho người chơi.
		{
			mot:
			system("cls");
			InTen(11);
			HienThiBanChucNang();
			XuatSudokuCapNhat(giaTri, diaChi, p, deSudoku);
			printf("Nhap vao dia chi o can goi y: ");
			scanf("%s", &diaChi);

			int goiY = GoiYNguoiChoi(diaChi, z);

			if (goiY != 0)
			{
				printf("Gia tri o %s la %d.\n", diaChi, goiY);
				goto nhaplai;
			}
				
			else
			{
				printf("Nhap sai dia chi!!!\n");
				printf("Nhap lai nhan \"1\" - nhan \"0\" khong nhap lai.");
				scanf("%d", &coKhong);
				if (coKhong == 1)
					goto mot;
				else
				{
					system("cls");
					InTen(11);
					HienThiBanChucNang();
					XuatSudokuCapNhat(giaTri, diaChi, p, deSudoku);
					goto nhaplai;
				}
					
			}
		}


		if (diaChi[0] == 'M')								// M: Máy chơi và giải toàn bộ sudoku.
		{
			system("cls");
			InTen(11);
			HienThiBanChucNang();
			GiaiToanBoSudokuBoiMay(z, deSudoku);
		}

		if (diaChi[0] == 'I')								// I: Tô màu một giá trị sai khi sudoku hoàn thành.
		{
			system("cls");
			InTen(11);
			HienThiBanChucNang();
				ToMauMotGiaTriSai(z, p, deSudoku);
				do
				{
					fflush(stdin);
					printf("1. Nhap tiep\n");
					printf("2. Luu\n");
					printf("3. Thoat\n");
					scanf("%d", &chon);
				} while (!(1 <= chon && chon <= 3));
				
				if (chon == 1)
					goto nhaplai;
				if (chon == 2)
				{
					LuuSudoku(f, p);
					printf("Da luu sudoku thanh cong!!!\n");
					goto nhaplai;
				}
				if (chon == 3)
					goto S;
		}

		if (diaChi[0] == 'F')								// F: Phủ kín lưới dựa trên kết quả đang thực hiện.
		{
			system("cls");
			InTen(11);
			HienThiBanChucNang();
			ToMauNhieuGiaTriSai(z, p, deSudoku);
			printf("1. Tro ve tuy chon ban dau\n");
			printf("2. Thoat\n");
			do
			{
				scanf("%d", &chon);
				if (chon == 1)
				{
					system("cls");
					goto dau;
				}
				if (chon == 2)
					goto S;
			} while (chon != 1 && chon != 2);
		}

		if (diaChi[0] == 'N')								// N: Bat dau sudoku ban dau.
		{
			system("cls");
			goto N;
		}
		
		if (diaChi[0] == 'R')								// R: Ve tuy chon chinh.
		{
			system("cls");

			goto dau;
		}

		if (diaChi[0] == 'O')								// O: Mo mot sudoku moi. 
		{
			system("cls");
			InTen(11);
			HienThiBanChucNang();
			goto O;
		}

		if (diaChi[0] == 'S')								// S: Lưu sudoku đang chơi và đi đến thoát.
		{
			system("cls");
			f = fopen("LuuSudoku.out", "wb");
			LuuSudoku(f, p);
			fclose(f);
			goto S;
		}

		if (diaChi[0] == 'E')								// E: Thoát chương trình.
		{
			system("cls");
			goto S;
		}

		if (diaChi[0] == 'C')								// C: Kiểm tra giá trị một ô
		{
			int x = 0;
			
			do
			{
				x = 0;
				fflush(stdin);
				printf("Nhap vao dia chi o can kiem tra: ");
				scanf("%s", &diaChi);
				doDai = strlen(diaChi);
				for (int i = 0; i < 2; i++)
				{
					if ('a' <= diaChi[i] && diaChi[i] <= 'i')
						cot = diaChi[i] - '0' - 49;
					if ('0' <= diaChi[i] && diaChi[i] <= '8')
						hang = diaChi[i] - '0';
				}
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						if (p[hang][cot] == 0 || deSudoku[hang][cot] != 0)
						{
							x = 1;
							printf("\nO nay khong hop le!!!\n");
							goto nhaplai;
						}
						
					}
				}
				
			} while (doDai != 2 ||hang > 8 || hang < 0 || cot > 8 || cot < 0);
			
			system("cls");
			InTen(11);
			HienThiBanChucNang();
			KiemTraMotGiaTriDuocCapNhat(p, z, deSudoku, hang, cot);
			Sleep(1000);
			goto nhaplai;
			//printf("Nhan mot phim bat ky de tiep tuc.\n");
		}
	}
	else
		printf("Loi tap tin\n");

	
	thoat:
	fcloseall;
	return;
}