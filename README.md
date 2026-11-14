# Mars Kolonisi Yaşam Destek Simülatörü

Kırklareli Üniversitesi Yazılım Mühendisliği Algoritma ve Programlama dersi kapsamında C dilinin temel yapıları kullanılarak geliştirilmiş metin tabanlı bir hayatta kalma simülasyonudur.

## 🛠️ Teknik Özellikler
* **Switch-Case & Fall-Through:** Komut yönetiminde büyük/küçük harf duyarsızlığı için `case 'g': case 'G':` yapıları kullanılmıştır.
* **Mod Operatörü (%):** Oksijen üretiminde suyun tek/çift kontrolü ve fırtına turlarının şiddetlenmesi için kullanılmıştır.
* **Döngüler:** Kum fırtınası için `for` döngüsü (`break` ve `continue` komutlarıyla), şifre doğrulaması için ise `do-while` döngüsü kullanılmıştır.

## ⚙️ Derleme ve Çalıştırma
```bash
gcc main.c -o mars_simulator
./mars_simulator
