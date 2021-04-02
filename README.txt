{\rtf1\ansi\ansicpg1252\cocoartf1671\cocoasubrtf600
{\fonttbl\f0\froman\fcharset0 TimesNewRomanPSMT;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww19780\viewh11300\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\sl360\slmult1\pardirnatural\partightenfactor0

\f0\fs24 \cf0 README\'85\'85.!!!!\
\
1. Deskripsi singkat\
Program ini adalah permainan mengejar dan menembak kecoak yang muncul secara random. User mengejar dan menembak kecoak dengan memasukkan perintah untuk robot pada area yang telah ditentukan.\
Saat permainan diakhiri, akan ditampilkan jumlah kecoak yang berhasil dibunuh.\
\
2. Input (tanpa tanda kutip):\
Bergerak	(Move)			->  \'93M\'94 / \'93m\'94\
	Atas 	(Up)				->  \'93W\'94 / \'93w\'94 \
	Bawah (Down)			->  \'93S\'94 / \'93s\'94 \
	Kanan (RIght)			->  \'93D\'94 / \'93d\'94 \
	Kiri (Left)				->  \'93A\'94 / \'93a\'94 \
Menembak (Kill)			->  \'93K\'94 / \'93k\'94 \
Mengakhiri permainan (Quit)	->  \'93Q\'94 / \'93q\'94\
Menyembuhkan robot (Heal)	->  \'93H\'94 / \'93h\'94\
\
3. Lingkungan dan batasan\
- Area gerak robot dan kecoak adalah bidang kartesius kuadran 1 dengan ukuran 100 x 100\
- Pergerakan robot pada 1 command adalah 1 satuan\
- Damage dari robot adalah 2 poin/hit\
- Damage dari kecoak adalah 1 poin/hit\
- Jarak serang kecoak dan robot maksimal 2 satuan\
	\
4. Skema permainan\
- Robot akan mulai pada posisi (0,0) pada koordinat kartesius dan kecoak akan muncul pada posisi random dan jumlah hit poin yang juga random\
- User dapat memilih untuk bergerak / menembak, jika memilih bergerak akan muncul pilihan arah gerak \
- Jika memilih menembak, maka hit poin kecoak akan berkurang sejumlah damage dari robot \
- Saat kecoak mati, akan muncul kecoak baru di lokasi dan jumlah hit poin yang acak/random\
- Saat user mengakhiri permainan akan ditampilkan jumlah kecoak yang berhasil dibunuh}