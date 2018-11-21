/* Deskripsi     Realisasi/ kode program dari semua prototype yg didefinisikan pada matriks.h */

#include <stdio.h>
#include "matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
	/* ALGORITMA */
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
	/* ALGORITMA */
	return (((BrsMin <= i) && (i <= BrsMax)) && ((KolMin <= j) && (j <= KolMax)));
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
	/* ALGORITMA */
	return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
	/* ALGORITMA */
	return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
	/* ALGORITMA */
	return NBrsEff(M);
}

indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
	/* ALGORITMA */
	return NKolEff(M);
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
	/* ALGORITMA */
	return (((GetFirstIdxBrs(M) <= i) && (i <= GetLastIdxBrs(M))) && ((GetFirstIdxKol(M) <= j) && (j <= GetLastIdxKol(M))));
}

ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
	/* ALGORITMA */
	return Elmt(M,i,i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
	/* ALGORITMA */
	*MHsl = MIn;
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
	/* KAMUS */
	indeks i, j;

	/* ALGORITMA */
	MakeMATRIKS(NB, NK, M);
	for(i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++)
	{
		for(j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++)
		{
			scanf("%d", &Elmt(*M,i,j));
		}
	}
}

void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
	/* KAMUS */
	indeks i, j;

	/* ALGORITMA */
	for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
	{
		for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
		{
			printf("%d", Elmt(M,i,j));
			if(j != GetLastIdxKol(M))
			{
				printf(" ");
			}
		}
		if(i != GetLastIdxBrs(M))
		{
			printf("\n");
		}
	}
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
	/* KAMUS */
	MATRIKS MHsl;
	indeks i, j;

	/* ALGORITMA */
	MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &MHsl);
	for(i = GetFirstIdxBrs(MHsl); i <= GetLastIdxBrs(MHsl); i++)
	{
		for(j = GetFirstIdxKol(MHsl); j <= GetLastIdxKol(MHsl); j++)
		{
			Elmt(MHsl,i,j) = Elmt(M1,i,j) + Elmt(M2,i,j);
		}
	}
	return MHsl;
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{
	/* KAMUS */
	MATRIKS MHsl;
	indeks i, j;

	/* ALGORITMA */
	MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &MHsl);
	for(i = GetFirstIdxBrs(MHsl); i <= GetLastIdxBrs(MHsl); i++)
	{
		for(j = GetFirstIdxKol(MHsl); j <= GetLastIdxKol(MHsl); j++)
		{
			Elmt(MHsl,i,j) = Elmt(M1,i,j) - Elmt(M2,i,j);
		}
	}
	return MHsl;
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
	/* KAMUS */
	MATRIKS MHsl;
	indeks i, j, k;

	/* ALGORITMA */
	MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &MHsl);
	for(i = GetFirstIdxBrs(MHsl); i <= GetLastIdxBrs(MHsl); i++)
	{
		for(j = GetFirstIdxKol(MHsl); j <= GetLastIdxKol(MHsl); j++)
		{
			Elmt(MHsl,i,j) = 0;
			for(k = GetFirstIdxKol(M1); k <= GetLastIdxKol(M1); k++)
			{
				Elmt(MHsl,i,j) += Elmt(M1,i,k) * Elmt(M2,k,j);
			}
		}
	}
	return MHsl;
}

MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
	/* KAMUS */
	MATRIKS MHsl;
	indeks i, j;

	/* ALGORITMA */
	MakeMATRIKS(NBrsEff(M), NKolEff(M), &MHsl);
	for(i = GetFirstIdxBrs(MHsl); i <= GetLastIdxBrs(MHsl); i++)
	{
		for(j = GetFirstIdxKol(MHsl); j <= GetLastIdxKol(MHsl); j++)
		{
			Elmt(MHsl,i,j) = Elmt(M,i,j) * X;
		}
	}
	return MHsl;
}

void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
	*M = KaliKons(*M,K);
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetLastIdxBrs(M1) = GetLastIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
	/* KAMUS */
	indeks i, j;
	boolean eq;

	/* ALGORITMA */
	if((GetLastIdxBrs(M1) == GetLastIdxBrs(M2)) && (GetLastIdxKol(M1) == GetLastIdxKol(M2)))
	{
		eq = true;
		i = GetFirstIdxBrs(M1);
		while((i <= GetLastIdxBrs(M1)) && eq)
		{

			j = GetFirstIdxKol(M1);
			while((j <= GetLastIdxKol(M1)) && eq)
			{
				if(Elmt(M1,i,j) != Elmt(M2,i,j))
				{
					eq = false;
				}
				else
				{
					j++;
				}
			}
			if(eq)
			{
				i++;
			}
		}
		return eq;
	}
	else
	{
		return false;
	}
}

boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
	/* ALGORITMA */
	return !EQ(M1,M2);
}

boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
	/* ALGORITMA */
	return ((NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) = NKolEff(M2)));
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
	/* ALGORITMA */
	return (NBrsEff(M) * NKolEff(M));
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
	/* ALGORITMA */
	return (NBrsEff(M) == NKolEff(M));
}

boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
	/* KAMUS */
	indeks i, j;
	boolean ok;

	/* ALGORITMA */
	if(IsBujurSangkar(M))
	{
		ok = true;
		i = GetFirstIdxBrs(M);
		while((i <= GetLastIdxBrs(M)) && ok)
		{
			j = GetFirstIdxKol(M);
			while((j <= GetLastIdxKol(M)) && ok)
			{
				if(Elmt(M,i,j) != Elmt(M,j,i))
				{
					ok = false;
				}
				else
				{
					j++;
				}
			}
			if(ok)
			{
				i++;
			}
		}
		return ok;
	}
	else
	{
		return false;
	}
}

boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
	/* KAMUS */
	indeks i, j;
	boolean ok;

	/* ALGORITMA */
	if(IsBujurSangkar(M))
	{
		ok = true;
		i = GetFirstIdxBrs(M);
		while((i <= GetLastIdxBrs(M)) && ok)
		{
			j = GetFirstIdxKol(M);
			while((j <= GetLastIdxKol(M)) && ok)
			{
				if(i == j)
				{
					if(Elmt(M,i,j) != 1)
					{
						ok = false;
					}
				}
				else if(Elmt(M,i,j) != 0)
				{
					ok = false;
				}
				if(ok)
				{
					j++;
				}
			}
			if(ok)
			{
				i++;
			}
		}
		return ok;
	}
	else
	{
		return false;
	}
}

boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: matriks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
	/* KAMUS */
	indeks i, j;
	boolean ok;
	int count;

	/* ALGORITMA */
	count = 0;
	ok = true;
	i = GetFirstIdxBrs(M);
	while((i <= GetLastIdxBrs(M)) && ok)
	{
		j = GetFirstIdxKol(M);
		while((j <= GetLastIdxKol(M)) && ok)
		{
			if(Elmt(M,i,j) != 0)
			{
				count++;
				if((20*count) > NBElmt(M))
				{
					ok = false;
				}
			}
			if(ok)
			{
				j++;
			}
		}
		if(ok)
		{
			i++;
		}
	}
	return ok;
}

MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
	/* KAMUS */
	MATRIKS MHsl;
	indeks i, j;

	/* ALGORITMA */
	MakeMATRIKS(NBrsEff(M), NKolEff(M), &MHsl);
	for(i = GetFirstIdxBrs(MHsl); i <= GetLastIdxBrs(MHsl); i++)
	{
		for(j = GetFirstIdxKol(MHsl); j <= GetLastIdxKol(MHsl); j++)
		{
			Elmt(MHsl,i,j) = -1 * Elmt(M,i,j);
		}
	}
	return MHsl;
}

float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
	/* KAMUS */
	float SegitigaAtas[101][101];
	indeks i, j, k;
	float det, factor, temp;
	boolean found;

	/* ALGORITMA */
	det = 1;
	for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
	{
		for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
		{
			SegitigaAtas[i][j] = Elmt(M,i,j);
		}
	}
	i = GetFirstIdxBrs(M);
	while((det !=0) && (i <= GetLastIdxBrs(M)))
	{
		if(SegitigaAtas[i][i] == 0)
		{
			found = false;
			j = i+1;
			while((j <= GetLastIdxBrs(M)) && !found)
			{
				if(Elmt(M,j,i) != 0)
				{
					found = true;
				}
				else
				{
					j++;
				}
			}
			if(found)
			{
				det *= -1;
				for(k = GetFirstIdxKol(M); k <= GetLastIdxKol(M); k++)
				{
					temp = SegitigaAtas[i][k];
					SegitigaAtas[i][k] = SegitigaAtas[j][k];
					SegitigaAtas[j][k] = temp;
				}
			}
			else
			{
				det = 0;
			}
		}
		if(det != 0)
		{
			for(j = i+1; j <= GetLastIdxBrs(M); j++)
			{
				factor = -1 * SegitigaAtas[j][i] / SegitigaAtas[i][i];
				for(k = i; k <= GetLastIdxKol(M); k++)
				{
					SegitigaAtas[j][k] += (factor * SegitigaAtas[i][k]);
				}
			}
			i++;
		}
	}
	if(det != 0)
	{
		for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
		{
			det *= SegitigaAtas[i][i];
		}
	}
	return det;
}

void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
	/* ALGORITMA */
	*M = Inverse1(*M);
}

void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
	/* KAMUS */
	MATRIKS MHsl;
	indeks i, j;

	/* ALGORITMA */
	MakeMATRIKS(NKolEff(*M), NBrsEff(*M), &MHsl);
	for(i = GetFirstIdxBrs(MHsl); i <= GetLastIdxBrs(MHsl); i++)
	{
		for(j = GetFirstIdxKol(MHsl); j <= GetLastIdxKol(MHsl); j++)
		{
			Elmt(MHsl,i,j) = Elmt(*M,j,i);
		}
	}
	*M = MHsl;
}
