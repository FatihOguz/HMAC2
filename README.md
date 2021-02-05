# HMAC2
HMAC,HASHING,KRIPTOLOJI


Dosyanın bütünlüğünün değişip değişmediğinin kontrolüiçin, HMAC repo daki işlemleri yaparak ilküretilen özüt değer ile karşılaştıran 
doğrulama aracını gerçekleyerek örnek testlerigösteriniz.



HMAC repo da yaptığım hash fonksiyonlarını hashDepo.txt de depoluyorum.
HMAC2 REPODA çalıştığında terminalde 2 adet matris gözükür.
Bu matrislerden biri çalışma anında üretilen hash iken diğeri en son yapılan hash matristir.
Bu iki matrisin değerlerini karşılaştırıp değişimin olup olmadığını kontrol edip terminalde
gösteriyorum.
Aşağıda bununla ilgili 1 görsel bırakıyorum.
İlk make yapışımda plainText4.doc hashDepo.txt ye depolanır.
2.make yaparken dosya sonundaki harfi değiştiriyorum
3. make de değişim gerçekleştiğini gösteriyorum
