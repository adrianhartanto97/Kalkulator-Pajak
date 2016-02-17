#include <stdio.h>

int main()
{
    /* Aturan Perhitungan
        PTKP Per Tahun:
        Belum Kawin : Rp 24.300.000
        Kawin, anak 0 : Rp. 26.325.000
        Kawin, anak 1 :	Rp. 28.350.000
        Kawin, anak 2 : Rp. 30.375.000
        Kawin, anak 3 : Rp. 32.400.000

        Lapisan Tarif Pajak (per tahun)
        Sampai dengan 50 juta : 5%
        Di atas 50 juta sd 250 juta	: 15%
        Di atas 250 juta sd 500 juta : 25%
        Di atas 500 juta : 30%
    */
    unsigned long int penghasilan_bruto,penghasilan_netto_sebelumPajak;
    printf("=============================================================\n");
    printf("\t\t\tKalkulator Pajak\n");
    printf("=============================================================\n\n");
    printf("Masukkan Penghasilan Bruto Anda (sebulan) : Rp. ");
    scanf("%ld",&penghasilan_bruto);

    jabatan:
    {
        printf("Jabatan dalam perusahaan, jika ada tekan 1, jika tidak ada tekan 0 : ");
        char jabat;
        getchar();
        scanf("%c",&jabat);
        if (jabat == '1') penghasilan_netto_sebelumPajak = 95 * penghasilan_bruto / 100; //pengurangan 5% jika ada jabatan dalam perusahaan.
        else if (jabat == '0') penghasilan_netto_sebelumPajak = penghasilan_bruto;
        else goto jabatan;
    }

    unsigned long int penghasilanBulan_netto_sebelumPajak = penghasilan_netto_sebelumPajak;
    penghasilan_netto_sebelumPajak *= 12; //Disetahunkan

    unsigned long int PTKP;
    nikah :
    {
        printf("Status Menikah ? (y/n)  : ");
        char menikah;
        getchar();
        scanf("%c",&menikah);

        if (menikah == 'y' || menikah == 'Y')
        {
            int anak;
            printf("Jumlah anak : ");
            scanf("%d",&anak);
            if (anak >= 0) PTKP = 26325000;
            else if (anak == 1) PTKP = 28350000;
            else if (anak == 2) PTKP = 30375000;
            else if (anak >= 3) PTKP = 32400000;
        }
        else if (menikah == 'n' || menikah == 'N')
            PTKP = 24300000;
        else
            goto nikah;
    }

    if (penghasilan_netto_sebelumPajak < PTKP)
        penghasilan_netto_sebelumPajak = 0;
    else
        penghasilan_netto_sebelumPajak -= PTKP;
    unsigned long int pajak, X = penghasilan_netto_sebelumPajak, tmp;

    if (X < 50000000)
        pajak = X*5/100;
    else if (X < 250000000)
    {
        X -= 50000000;
        tmp = 50000000*5/100;
        pajak = X*15/100 + tmp;
    }
    else if (X < 500000000)
    {
        X -= 250000000;
        tmp = 250000000*15/100 + 50000000*5/100;
        pajak = X*25/100 + tmp;
    }
    else
    {
        X-=500000000;
        tmp = 500000000*25/100 + 250000000*15/100 + 50000000*5/100;
        pajak = X*30/100 + tmp;
    }

    printf("\n\n--------------------------------------------------");
    printf("\nPenghasilan Netto sebelum dipotong pajak (setahun) : Rp. %ld\nSudah dipotong PTKP\n",penghasilan_netto_sebelumPajak);
    printf("--------------------------------------------------\n");
    printf("\n------------------------------");
    printf("\nBesarnya pajak (dalam setahun) : Rp. %ld\n",pajak);
    printf("------------------------------\n");

    pajak = ceil((float)pajak/12);
    unsigned long int penghasilan_netto_setelahPajak = penghasilanBulan_netto_sebelumPajak - pajak;
    printf("\n-------------------------");
    printf("\nPajak pada bulan berjalan : Rp. %ld\n",pajak);
    printf("-------------------------\n");

    printf("\n----------------------------------------------------");
    printf("\nPenghasilan Netto Setelah dipotong pajak (per bulan) : Rp. %ld\n",penghasilan_netto_setelahPajak);
    printf("----------------------------------------------------\n");

    getch();
    return 0;
}
