#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <locale.h> // Türkçe karakterler için gerekli kütüphane

// Deðerleri 0 ile 100 arasýnda sýnýrlandýran yardýmcý fonksiyon
int sinirla(int deger) {
    if (deger < 0) return 0;
    if (deger > 100) return 100;
    return deger;
}

int main() {
    // Konsolda Türkçe karakter desteðini aktif et
    setlocale(LC_ALL, "Turkish");

    // Rastgelelik için seed ayarý
    srand(time(NULL));

    // Durum Deðiþkenleri
    int saglik = 100;
    int enerji = 100;
    int oksijen = 100;
    int su = 50;
    int yedekParca = 5;
    int modulHasari = 10;
    int kilitMuhurlu = 0;
    int gun = 1;
    int tur = 0;

    char zorluk;
    int firtinaSuresi = 5;
    int i; // Döngü sayacý

    printf("==================================================\n");
    printf("    MARS KOLONÝSÝ YAÞAM DESTEK SÝMÜLATÖRÜ\n");
    printf("==================================================\n");

    // Zorluk Seviyesi Seçimi (SWITCH-CASE)
    do {
        printf("Zorluk Seviyesi Seçin (K: Kolay, N: Normal, Z: Zor): ");
        scanf(" %c", &zorluk);
        zorluk = toupper(zorluk);

        switch (zorluk) {
            case 'K':
                su = 70;
                yedekParca = 7;
                modulHasari = 5;
                firtinaSuresi = 3;
                printf("Zorluk: KOLAY olarak belirlendi.\n");
                break;
            case 'N':
                su = 50;
                yedekParca = 5;
                modulHasari = 15;
                firtinaSuresi = 5;
                printf("Zorluk: NORMAL olarak belirlendi.\n");
                break;
            case 'Z':
                su = 30;
                yedekParca = 3;
                modulHasari = 30;
                firtinaSuresi = 7;
                printf("Zorluk: ZOR olarak belirlendi.\n");
                break;
            default:
                printf("Geçersiz seçim! Lütfen K, N veya Z giriniz.\n");
                zorluk = '\0';
                break;
        }
    } while (zorluk == '\0');

    char komut;
    int oyunBitti = 0;

    printf("\n[ÝPUCU] Komutlar hakkýnda bilgi almak için oyun içinde '?' tuþuna basabilirsiniz.\n");

    // Ana Komut Dinleme Döngüsü (DO-WHILE)
    do {
        if (saglik <= 0 || oksijen <= 0) {
            oyunBitti = 1;
            break;
        }
        if (gun > 15) {
            oyunBitti = 2;
            break;
        }

        printf("\n--------------------------------------------------\n");
        printf("Gün: %d | Tur: %d | Saðlýk: %d | Enerji: %d | Oksijen: %d | Su: %d | Hasar: %d\n", 
               gun, tur, saglik, enerji, oksijen, su, modulHasari);
        printf("Komut Girin (G, O, T, D, U, K, H, Q, ? [Yardým]): ");
        scanf(" %c", &komut);
        komut = toupper(komut);

        int turArttir = 1;

        // Komut Sistemi (SWITCH-CASE ve Fall-Through)
        switch (komut) {
            case 'g':
            case 'G': { // Keþif Görevi
                if (enerji < 15) {
                    printf("Yetersiz enerji! Keþif yapýlamaz.\n");
                    turArttir = 0;
                    break;
                }
                enerji -= 15;
                oksijen -= 10;

                int zar = rand() % 100;
                int esik = (enerji > 40 && oksijen > 30) ? 50 : 30;
                printf("Keþif Zarý: %d / Eþik: %d -> ", zar, esik);

                if (zar < esik) {
                    printf("BAÞARILI (Su bulundu! +20 su)\n");
                    su += 20;
                } else if (zar < esik + 25) {
                    printf("BAÞARILI (Yedek parça bulundu! +2 parça)\n");
                    yedekParca += 2;
                } else {
                    printf("BAÞARISIZ (Eli boþ dönüldü.)\n");
                }

                int yaralanmaZari = rand() % 100;
                printf("Yaralanma Zarý: %d / Eþik: 10 -> ", yaralanmaZari);
                if (yaralanmaZari < 10 || modulHasari > 70) {
                    printf("YARALANDINIZ! Saðlýk düþtü.\n");
                    saglik -= 15;
                } else {
                    printf("Güvendesiniz.\n");
                }
                break;
            }
            case 'o':
            case 'O': { // Oksijen Üretimi
                int harcananSu;
                printf("Üretim için harcanacak su miktarýný girin (Mevcut: %d): ", su);
                scanf("%d", &harcananSu);

                if (harcananSu > su || harcananSu <= 0) {
                    printf("Geçersiz su miktarý!\n");
                    turArttir = 0;
                    break;
                }

                su -= harcananSu;
                int uretilenOksijen = (harcananSu / 2) * 3;
                
                if (harcananSu % 2 != 0) {
                    su += 1;
                    printf("Girilen su tek sayý olduðundan 1 birim artýk depoda býrakýldý.\n");
                }

                oksijen += uretilenOksijen;
                printf("%d birim oksijen üretildi.\n", uretilenOksijen);
                break;
            }
            case 't':
            case 'T': { // Tamir
                if (yedekParca <= 0) {
                    printf("Yedek parçanýz yok! Tamir yapýlamaz.\n");
                    turArttir = 0;
                    break;
                }

                yedekParca--;
                if (modulHasari <= 30) {
                    modulHasari -= 15;
                    printf("Hafif hasar onarýldý.\n");
                } else if (modulHasari <= 70) {
                    modulHasari -= 10;
                    printf("Orta seviye hasar onarýldý.\n");
                } else {
                    printf("Aðýr hasarýn bir kýsmý onarýldý.\n");
                    modulHasari -= 5;
                }
                break;
            }
            case 'd':
            case 'D': { // Durum Raporu
                turArttir = 0;
                printf("\n================ DURUM RAPORU ================\n");
                printf("Saðlýk      : %d\n", saglik);
                printf("Enerji      : %d\n", enerji);
                printf("Oksijen     : %d\n", oksijen);
                printf("Su          : %d birim\n", su);
                printf("Yedek Parça : %d\n", yedekParca);
                printf("Modül Hasarý: %d\n", modulHasari);
                printf("Hava Kilidi : %s\n", kilitMuhurlu ? "Mühürlü" : "Açýk");

                if (oksijen < 25) { printf("- UYARI: Oksijen kritik seviyede!\n"); }
                if (saglik < 30) { printf("- UYARI: Saðlýk kritik seviyede!\n"); }
                if (modulHasari > 70) { printf("- UYARI: Modül hasarý kritik seviyede!\n"); }

                if (oksijen >= 25 && saglik >= 30 && modulHasari <= 70) {
                    printf("TÜM SÝSTEMLER NORMAL\n");
                }
                printf("==============================================\n");
                break;
            }
            case 'u':
            case 'U': { // Uyu / Dinlen
                enerji += 25;
                if (oksijen < 20) {
                    saglik -= 10;
                    printf("Oksijen 20'nin altýnda! Dinlenirken fenalaþtýnýz, saðlýk kaybettiniz.\n");
                } else {
                    saglik += 10;
                    printf("Dinlendiniz. Enerji ve saðlýk arttý.\n");
                }
                break;
            }
            case 'k':
            case 'K': { // Kum Fýrtýnasý (FOR Döngüsü)
                printf("Kum fýrtýnasý simülasyonu baþlatýldý! Süre: %d tur.\n", firtinaSuresi);
                int firtinaHasarToplami = 0;
                int firtinaOksijenToplami = 0;

                for (i = 1; i <= firtinaSuresi; i++) {
                    int siddetKatsayisi = (i % 2 == 0) ? 2 : 1;
                    printf(" -> Fýrtýna Turu %d (Þiddet: %dx):\n", i, siddetKatsayisi);

                    if (kilitMuhurlu == 1) {
                        printf("    Hava kilidi mühürlü olduðu için oksijen sýzýntýsý atlandý (continue).\n");
                    } else {
                        oksijen -= (5 * siddetKatsayisi);
                        firtinaOksijenToplami += (5 * siddetKatsayisi);
                    }

                    int zar = rand() % 100;
                    printf("    Fýrtýna Zarý: %d / Eþik: 50 -> ", zar);
                    if (zar < 50) {
                        modulHasari += (10 * siddetKatsayisi);
                        firtinaHasarToplami += (10 * siddetKatsayisi);
                        printf("Modül hasar aldý!\n");
                    } else {
                        printf("Zararsýz atlatýldý.\n");
                    }

                    saglik = sinirla(saglik);
                    oksijen = sinirla(oksijen);

                    if (saglik <= 0 || oksijen <= 0) {
                        printf("    Kritik durum! Fýrtýna döngüsü sonlandýrýlýyor (break).\n");
                        break;
                    }
                }
                printf("Fýrtýna Özeti -> Toplam Modül Hasarý Artýþý: %d, Oksijen Kaybý: %d\n", firtinaHasarToplami, firtinaOksijenToplami);
                break;
            }
            case 'h':
            case 'H': { // Hava Kilidi Þifresi (DO-WHILE)
                char dogruSifre = 'A' + (gun % 26);
                int denemeHakki = 3;
                char girilen;
                int basarili = 0;

                printf("Hava Kilidi Mühürleme Protokolü Baþlatýldý.\n");
                printf("ÝPUCU: Þifre, alfabede 'A' harfinden bugünün gün sayýsý (%d) kadar ilerideki harftir.\n", gun);

                do {
                    printf("Kalan hak: %d. Bir büyük harf girin: ", denemeHakki);
                    scanf(" %c", &girilen);
                    girilen = toupper(girilen);

                    if (girilen == dogruSifre) {
                        printf("Doðru þifre! Hava kilidi mühürlendi.\n");
                        kilitMuhurlu = 1;
                        basarili = 1;
                        break;
                    } else {
                        denemeHakki--;
                        enerji -= 5;
                        if (girilen < dogruSifre) {
                            printf("Yanlýþ! Ýleri git (daha sonraki bir harf).\n");
                        } else {
                            printf("Yanlýþ! Geri git (daha önceki bir harf).\n");
                        }
                    }
                } while (denemeHakki > 0 && girilen != dogruSifre);

                if (!basarili) {
                    printf("Haklarýnýz bitti! Þifre çözülemedi, modül hasarý arttý.\n");
                    modulHasari += 20;
                }
                break;
            }
            case '?': { // Yardým Menüsü
                turArttir = 0;
                printf("\n================ OYUN KOMUTLARI REHBERÝ ================\n");
                printf(" [G] Keþif     : Enerji (-15) ve oksijen (-10) harcar. Su veya yedek parça arar.\n");
                printf(" [O] Oksijen   : Su harcar ve karþýlýðýnda oksijen üretir (2 su = 3 oksijen).\n");
                printf(" [T] Tamir     : Yedek parça harcayarak istasyonun modül hasarýný azaltýr.\n");
                printf(" [D] Durum     : Anlýk istatistikleri ve sistem uyarýlarýný gösterir (Tur harcamaz).\n");
                printf(" [U] Uyu/Dinlen: Enerjiyi artýrýr. Oksijen düþükse saðlýk tehlikeye girer.\n");
                printf(" [K] Fýrtýna   : Kum fýrtýnasýný simüle eder (Modül hasarý alabilir veya oksijen sýzabilir).\n");
                printf(" [H] Hava Kil.: Þifre çözme bulmacasýdýr. Doðru bilinirse fýrtýna sýzýntýsý engellenir.\n");
                printf(" [Q] Çýkýþ     : Oyunu erken sonlandýrýr.\n");
                printf("=======================================================\n");
                break;
            }
            case 'q':
            case 'Q': {
                oyunBitti = 3;
                break;
            }
            default: {
                printf("Tanýmsýz komut! (Yardým için '?' tuþlayabilirsiniz). Süre harcanmadý.\n");
                turArttir = 0;
                break;
            }
        }

        saglik = sinirla(saglik);
        enerji = sinirla(enerji);
        oksijen = sinirla(oksijen);
        modulHasari = sinirla(modulHasari);

        if (turArttir) {
            tur++;
            if (tur % 3 == 0) {
                gun++;
                oksijen -= 8;
                printf("\n>>> 3 tur tamamlandý, yeni bir gün baþladý! Gün: %d (Oksijen -8 azaldý) <<<\n", gun);
                if (modulHasari > 70) {
                    saglik -= 5;
                    printf("Modül hasarý 70'in üzerinde olduðu için ek olarak 5 saðlýk kaybedildi!\n");
                }
            }
        }

    } while (oyunBitti == 0);

    printf("\n==================================================\n");
    printf("                  OYUN SONU RAPORU\n");
    printf("==================================================\n");
    if (oyunBitti == 1) {
        printf("SONUÇ: KAYBETTÝNÝZ! (Saðlýk veya oksijen tükendi.)\n");
    } else if (oyunBitti == 2) {
        printf("SONUÇ: KAZANDINIZ! (15 günü baþarýyla tamamladýnýz, kurtarma ekibi geldi!)\n");
    } else {
        printf("SONUÇ: Oyundan çýkýþ yaptýnýz (Q komutu).\n");
    }

    int puan = (gun * 100) + saglik + oksijen - modulHasari;

    printf("Hayatta Kalýnan Gün : %d\n", gun);
    printf("Toplam Tur Sayýsý   : %d\n", tur);
    printf("Son Saðlýk          : %d\n", saglik);
    printf("Son Oksijen         : %d\n", oksijen);
    printf("Son Modül Hasarý    : %d\n", modulHasari);
    printf("TOPLAM PUAN         : %d\n", puan);
    printf("==================================================\n");

    return 0;
}
