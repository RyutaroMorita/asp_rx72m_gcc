$ 
$		アーキテクチャ依存テンプレート（RX610用）
$ 



/*$NL$
$SPC$*  Architecture-dependent Definitions (RX610)$NL$
$SPC$*/$NL$
$NL$

$ 
$  割込み番号と割込みハンドラ番号の定義
$ 
$  RX610では割込み番号と割込みハンドラ番号が1対1で対応する．
$ 

$INTNO_VALID = { 16, 21, 23 ; 28, 29,...,31 ; 64, 65,...,79 ; 96 ; 98, 99,...,101 ; 104, 105,...,108 ; 111, 112 ; 115, 116,...,118 ; 120, 121,...,128 ; 131, 132,...,134 ; 136, 137,...,142 ; 145, 146 ; 149, 150,...,152 ; 154, 155,...,162 ; 165, 166,...,168 ; 170, 171 ; 174, 175,...,185 ; 198, 199,...,201 ; 214, 215,...,241 ; 246, 247,...,253 }$
$INHNO_VALID = INTNO_VALID$

$ 
$  例外番号の定義
$ 
$  固定ベクタテーブルのベクタテーブルアドレスの小さい順番に例外番号を割振る．
$  (予約領域も含む)
$ 

$EXCNO_VALID = { 20, 23, 25, 30, 31 }$

$ 
$  INT割込みの番号
$ 

$INTNO_INT = { 64, 65,...,79 }$

$ 
$  割込み番号，割込みハンドラ番号，例外番号の範囲
$ 
$ (予約領域も含む)
$ 

$INTNO_RANGE = { 0, 1,...,255 }$
$INHNO_RANGE = INTNO_RANGE$
$EXCNO_RANGE = { 0, 1,...,31 }$

$ 
$  プロセッサ依存のテンプレートファイルのインクルード
$ 

$INCLUDE"rx_gcc/prc.tf"$

