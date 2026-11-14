# Mars Kolonisi Yaşam Destek Simülatörü

Kırklareli Üniversitesi Yazılım Mühendisliği Algoritma ve Programlama dersi kapsamında C dilinin temel yapıları kullanılarak geliştirilmiş metin tabanlı bir hayatta kalma simülasyonudur[cite: 1].

## 🛠️ Teknik Özellikler
* **Switch-Case & Fall-Through:** Komut yönetiminde büyük/küçük harf duyarsızlığı için `case 'g': case 'G':` yapıları kullanılmıştır[cite: 1].
* **Mod Operatörü (%):** Oksijen üretiminde suyun tek/çift kontrolü ve fırtına turlarının şiddetlenmesi için kullanılmıştır[cite: 2].
* **Döngüler:** Kum fırtınası için `for` döngüsü (`break` ve `continue` komutlarıyla), şifre doğrulaması için ise `do-while` döngüsü kullanılmıştır[cite: 2].

## ⚙️ Derleme ve Çalıştırma
```bash
gcc main.c -o mars_simulator
./mars_simulator
