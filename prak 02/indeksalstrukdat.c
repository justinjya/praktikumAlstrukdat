#include <stdio.h>

int main()
{
    int nilai, lulus, mhs;
    float jumlah, rata;
    mhs = 0;
    lulus = 0;
    jumlah = 0;
    scanf("%d", &nilai);
    while (nilai != -999)
    {
        if ((nilai >= 0) && (nilai <= 4))
        {
            jumlah += nilai;
            mhs += 1;
            if (nilai >= 3)
            {
                lulus += 1;
            }
        }
        scanf("%d", &nilai);
    }
    if (mhs == 0)
    {
        printf("Tidak ada data\n");
    }
    else
    {
        rata = jumlah / mhs;
        printf("Jumlah mahasiswa yang lulus = %d\n", lulus);
        printf("Nilai rata-rata = %.2f\n", rata);
        if (rata == 4)
        {
            printf("Indeks akhir kelas = A\n");
        }
        else if ((rata >= 3) && (rata < 4))
        {
            printf("Indeks akhir kelas = B\n");
        }
        else if ((rata >= 2) && (rata < 3))
        {
            printf("Indeks akhir kelas = C\n");
        }
        else if ((rata >= 1) && (rata < 2))
        {
            printf("Indeks akhir kelas = D\n");
        }
        else
        {
            printf("Indeks akhir kelas = E\n");
        }
    }
    return 0;
}