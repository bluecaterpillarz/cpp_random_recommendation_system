# cpp_random_recommendation_system
# C++ Random Recommendation System

Bu proje, metin dosyalarından okunan **kategorik içerikler** üzerinden çalışan,
kullanıcının ilgisine göre **rastgele ama ilgili öneriler** üreten
konsol tabanlı bir C++ uygulamasıdır.

Proje; dosya okuma, veri ayrıştırma, rastgele seçim ve temel recommendation mantığını
uygulamalı olarak göstermek amacıyla geliştirilmiştir.

> This project is a **file-based C++ recommendation system prototype** focusing on data parsing and randomized suggestion logic.

---

## 🎯 Projenin Amacı

- C++ ile **gerçek dosya verisi** üzerinde çalışmak  
- Kategorik verileri uygun veri yapılarıyla temsil etmek  
- Rastgele ama tekrarsız öneriler üretmek  
- Kullanıcı girdisini **case-insensitive** şekilde işlemek  

Bu proje bir ürün değil, **öğrenme ve mimari pratik** odaklı bir prototiptir.

---

## 🧠 Kullanılan Temel Kavramlar

### Türkçe
- Dosya okuma (`ifstream`)
- Metin temizleme (trim, küçük harfe çevirme)
- `vector` ve iç içe veri yapıları
- Rastgele sayı üretimi
- Aynı önerinin tekrar edilmesini engelleme
- Kullanıcı etkileşimi (console input/output)

### English (technical focus)
- File I/O with C++
- STL containers (`vector`)
- Random number generation (`random_device`, `mt19937`)
- Case-insensitive string comparison
- Basic recommendation logic

---

## ▶️ Program Nasıl Çalışır?

1. Kullanıcı bir kategori seçer (spor / film-dizi / kitap)
2. Program ilgili `.txt` dosyasını okur
3. Dosyada `:` ile ayrılmış alt kategoriler parse edilir
4. Her alt kategoriden rastgele bir içerik gösterilir
5. Kullanıcının seçimine göre aynı kategori içinden yeni öneriler üretilir

---

## 🛠️ Kullanılan Teknolojiler

- C++
- STL (vector, algorithm, random)
- Dosya tabanlı veri işleme

---

## ⚠️ Notlar

- Metin dosyalarının doğru dizinde bulunması gerekir.
- Dosya yolu sisteminize göre düzenlenmelidir.
- Proje, geliştirilmeye açık bir **prototype** olarak tasarlanmıştır.

> Text files should be placed in the correct directory or file paths should be adjusted accordingly.

---

## 🚀 Geliştirme Fikirleri

- Dosya yolunun dinamik hale getirilmesi
- Daha gelişmiş recommendation algoritmaları
- OOP yapısının genişletilmesi
- Dosya formatının JSON/CSV’ye taşınması

---

