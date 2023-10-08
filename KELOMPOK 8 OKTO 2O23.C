int main() {
    char lanjut;
    do {
        float total_pembelian;
        float diskon = 0.0;
        float persen_diskon = 0.0;
        
        puts("==========================================");
        puts("Selamat datang di program diskon dan kupon");
        puts("==========================================");
        // Input total pembelian
        printf("Masukkan total pembelian (Rp): ");
        scanf("%f", &total_pembelian);

        // Hitung diskon (5% untuk setiap kelipatan Rp 100.000)
        int kelipatan = total_pembelian / 100000;
        diskon = kelipatan * 0.05 * total_pembelian;

        // Hitung persen diskon
        persen_diskon = (diskon / total_pembelian) * 100;

        printf("Anda mendapatkan diskon sebesar Rp %.2f (%.2f%% dari total pembelian).\n", diskon, persen_diskon);

        // Hitung total yang harus dibayar setelah diskon
        float total_setelah_diskon = total_pembelian - diskon;
        printf("Total yang harus dibayar setelah diskon: Rp %.2f\n", total_setelah_diskon);

        // Tanya apakah pengguna ingin melanjutkan atau berhenti
        printf("Apakah Anda ingin melanjutkan (Y/N)? ");
        scanf(" %c", &lanjut);
    } while (lanjut == 'Y' || lanjut == 'y');
	puts("==================================");
	printf("Terima kasih! Program selesai.\n");
	puts("==================================");
    return 0;
}
