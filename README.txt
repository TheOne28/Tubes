1. Deskripsi singkat
Program ini adalah permainan mengejar dan menembak kecoak yang muncul secara random. User mengejar dan menembak kecoak dengan memasukkan perintah untuk robot pada area yang telah ditentukan.
Saat permainan diakhiri, akan ditampilkan jumlah kecoak yang berhasil dibunuh.

2. Input (tanpa tanda kutip):
Bergerak(Move)			->  “M” / “m”
	Atas (Up)		->  “W” / “w” 
	Bawah (Down)		->  “S” / “s” 
	Kanan (RIght)		->  “D” / “d” 
	Kiri (Left)		->  “A” / “a” 
Menembak (Kill)			->  “K” / “k” 
Mengakhiri permainan (Quit)	->  “Q” / “q”
Menyembuhkan robot (Heal)	->  “H” / “h”

3. Lingkungan dan batasan
- Area gerak robot dan kecoak adalah bidang kartesius kuadran 1 dengan ukuran 100 x 100
- Pergerakan robot pada 1 command adalah 1 satuan
- Damage dari robot adalah 2 poin/hit
- Damage dari kecoak adalah 1 poin/hit
- Jarak serang kecoak dan robot maksimal 2 satuan
	
4. Skema permainan
- Robot akan mulai pada posisi (0,0) pada koordinat kartesius dan kecoak akan muncul pada posisi random dan jumlah hit poin yang juga random
- User dapat memilih untuk bergerak / menembak, jika memilih bergerak akan muncul pilihan arah gerak 
- Jika memilih menembak, maka hit poin kecoak akan berkurang sejumlah damage dari robot 
- Saat kecoak mati, akan muncul kecoak baru di lokasi dan jumlah hit poin yang acak/random
- Saat user mengakhiri permainan akan ditampilkan jumlah kecoak yang berhasil dibunuh
