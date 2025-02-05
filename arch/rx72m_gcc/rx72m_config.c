/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2010 by Witz Corporation, JAPAN
 * 
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 * 
 */

#include <kernel_impl.h>

/*
 *		プロセッサ依存モジュール（RX72M用）
 */

volatile uint8_t * const ipr_reg_addr[ INHNO_MAX ] = {
	NULL,				//   0 - 予約
	NULL,				//   1 - 予約
	NULL,				//   2 - 予約
	NULL,				//   3 - 予約
	NULL,				//   4 - 予約
	NULL,				//   5 - 予約
	NULL,				//   6 - 予約
	NULL,				//   7 - 予約
	NULL,				//   8 - 予約
	NULL,				//   9 - 予約
	NULL,				//  10 - 予約
	NULL,				//  11 - 予約
	NULL,				//  12 - 予約
	NULL,				//  13 - 予約
	NULL,				//  14 - 予約
	NULL,				//  15 - 予約
	ICU_IPR000_ADDR,	//  16 - BUSERR
	ICU_IPR000_ADDR,	//  17 - GROUPIE0
	ICU_IPR000_ADDR,	//  18 - RAMERR
	NULL,				//  19 - 予約
	NULL,				//  20 - 予約
	ICU_IPR001_ADDR,	//  21 - FIFERR
	NULL,				//  22 - 予約
	ICU_IPR002_ADDR,	//  23 - FRDYI
	NULL,				//  24 - 予約
	NULL,				//  25 - 予約
	ICU_IPR003_ADDR,	//  26 - SWINT2
	ICU_IPR003_ADDR,	//  27 - SWINT
	ICU_IPR004_ADDR,	//  28 - CMI0
	ICU_IPR005_ADDR,	//  29 - CMI1
	ICU_IPR006_ADDR,	//  30 - CMWI0
	ICU_IPR007_ADDR,	//  31 - CMWI1
	NULL,				//  32 - 予約
	NULL,				//  33 - 予約
	ICU_IPR034_ADDR,	//  34 - D0FIFO0
	ICU_IPR035_ADDR,	//  35 - D1FIFO0
	NULL,				//  36 - 予約
	NULL,				//  37 - 予約
	ICU_IPR038_ADDR,	//  38 - SPRI0
	ICU_IPR039_ADDR,	//  39 - SPTI0
	ICU_IPR040_ADDR,	//  40 - SPRI1
	ICU_IPR041_ADDR,	//  41 - SPTI1
	ICU_IPR042_ADDR,	//  42 - SPRI
	ICU_IPR043_ADDR,	//  43 - SPTI
	ICU_IPR044_ADDR,	//  44 - SBFAI
	ICU_IPR045_ADDR,	//  45 - MBFAI
	ICU_IPR046_ADDR,	//  46 - SSITXI0
	ICU_IPR047_ADDR,	//  47 - SSIRXI0
	ICU_IPR048_ADDR,	//  48 - SSIRTI1
	NULL,				//  49 - 予約
	ICU_IPR050_ADDR,	//  50 - RXI1
	ICU_IPR051_ADDR,	//  51 - TXI1
	ICU_IPR052_ADDR,	//  52 - RXI0
	ICU_IPR053_ADDR,	//  53 - TXI0
	ICU_IPR054_ADDR,	//  54 - RXI2
	ICU_IPR055_ADDR,	//  55 - TXI2
	NULL,				//  56 - 予約
	NULL,				//  57 - 予約
	ICU_IPR058_ADDR,	//  58 - RXI0
	ICU_IPR059_ADDR,	//  59 - TXI0
	ICU_IPR060_ADDR,	//  60 - RXI1
	ICU_IPR061_ADDR,	//  61 - TXI1
	ICU_IPR062_ADDR,	//  62 - RXI2
	ICU_IPR063_ADDR,	//  63 - TXI2
	ICU_IPR064_ADDR,	//  64 - IRQ0
	ICU_IPR065_ADDR,	//  65 - IRQ1
	ICU_IPR066_ADDR,	//  66 - IRQ2
	ICU_IPR067_ADDR,	//  67 - IRQ3
	ICU_IPR068_ADDR,	//  68 - IRQ4
	ICU_IPR069_ADDR,	//  69 - IRQ5
	ICU_IPR070_ADDR,	//  70 - IRQ6
	ICU_IPR071_ADDR,	//  71 - IRQ7
	ICU_IPR072_ADDR,	//  72 - IRQ8
	ICU_IPR073_ADDR,	//  73 - IRQ9
	ICU_IPR074_ADDR,	//  74 - IRQ10
	ICU_IPR075_ADDR,	//  75 - IRQ11
	ICU_IPR076_ADDR,	//  76 - IRQ12
	ICU_IPR077_ADDR,	//  77 - IRQ13
	ICU_IPR078_ADDR,	//  78 - IRQ14
	ICU_IPR079_ADDR,	//  79 - IRQ15
	ICU_IPR080_ADDR,	//  80 - RXI3
	ICU_IPR081_ADDR,	//  81 - TXI3
	ICU_IPR082_ADDR,	//  82 - RXI4
	ICU_IPR083_ADDR,	//  83 - TXI4
	ICU_IPR084_ADDR,	//  84 - RXI5
	ICU_IPR085_ADDR,	//  85 - TXI5
	ICU_IPR086_ADDR,	//  86 - RXI6
	ICU_IPR087_ADDR,	//  87 - TXI6
	ICU_IPR088_ADDR,	//  88 - LVD1
	ICU_IPR089_ADDR,	//  89 - LVD2
	ICU_IPR090_ADDR,	//  90 - USBR0
	NULL,				//  91 - 予約
	ICU_IPR092_ADDR,	//  92 - ALM
	ICU_IPR093_ADDR,	//  93 - PRD
	NULL,				//  94 - 予約
	ICU_IPR095_ADDR,	//  95 - IWUNI
	ICU_IPR096_ADDR,	//  96 - WUNI
	ICU_IPR097_ADDR,	//  97 - PCDFI
	ICU_IPR098_ADDR,	//  98 - RXI7
	ICU_IPR099_ADDR,	//  99 - TXI7
	ICU_IPR100_ADDR,	// 100 - RXI8
	ICU_IPR101_ADDR,	// 101 - TXI8
	ICU_IPR102_ADDR,	// 102 - RXI9
	ICU_IPR103_ADDR,	// 103 - TXI9
	ICU_IPR104_ADDR,	// 104 - RXI10
	ICU_IPR105_ADDR,	// 105 - TXI10
	ICU_IPR106_ADDR,	// 106 - GROUPBE0
	ICU_IPR107_ADDR,	// 107 - GROUPBL2
	ICU_IPR108_ADDR,	// 108 - SPRI2
	ICU_IPR109_ADDR,	// 109 - SPTI2
	ICU_IPR110_ADDR,	// 110 - GROUPBL0
	ICU_IPR111_ADDR,	// 111 - GROUPBL1
	ICU_IPR112_ADDR,	// 112 - GROUPAL0
	ICU_IPR113_ADDR,	// 113 - GROUPAL1
	ICU_IPR114_ADDR,	// 114 - RXI11
	ICU_IPR115_ADDR,	// 115 - TXI11
	ICU_IPR116_ADDR,	// 116 - RXI12
	ICU_IPR117_ADDR,	// 117 - TXI12
	NULL,				// 118 - 予約
	NULL,				// 119 - 予約
	ICU_IPR120_ADDR,	// 120 - DMAC0I
	ICU_IPR121_ADDR,	// 121 - DMAC1I
	ICU_IPR122_ADDR,	// 122 - DMAC2I
	ICU_IPR123_ADDR,	// 123 - DMAC3I
	ICU_IPR124_ADDR,	// 124 - DMAC74I
	ICU_IPR125_ADDR,	// 125 - OSTDI
	ICU_IPR126_ADDR,	// 126 - EXDMAC0I
	ICU_IPR127_ADDR,	// 127 - EXDMAC1I
	ICU_IPR128_ADDR,	// 128 - INTB128
	ICU_IPR129_ADDR,	// 129 - INTB129
	ICU_IPR130_ADDR,	// 130 - INTB130
	ICU_IPR131_ADDR,	// 131 - INTB131
	ICU_IPR132_ADDR,	// 132 - INTB132
	ICU_IPR133_ADDR,	// 133 - INTB133
	ICU_IPR134_ADDR,	// 134 - INTB134
	ICU_IPR135_ADDR,	// 135 - INTB135
	ICU_IPR136_ADDR,	// 136 - INTB136
	ICU_IPR137_ADDR,	// 137 - INTB137
	ICU_IPR138_ADDR,	// 138 - INTB138
	ICU_IPR139_ADDR,	// 139 - INTB139
	ICU_IPR140_ADDR,	// 140 - INTB140
	ICU_IPR141_ADDR,	// 141 - INTB141
	ICU_IPR142_ADDR,	// 142 - INTB142
	ICU_IPR143_ADDR,	// 143 - INTB143
	ICU_IPR144_ADDR,	// 144 - INTB144
	ICU_IPR145_ADDR,	// 145 - INTB145
	ICU_IPR146_ADDR,	// 146 - INTB146
	ICU_IPR147_ADDR,	// 147 - INTB147
	ICU_IPR148_ADDR,	// 148 - INTB148
	ICU_IPR149_ADDR,	// 149 - INTB149
	ICU_IPR150_ADDR,	// 150 - INTB150
	ICU_IPR151_ADDR,	// 151 - INTB151
	ICU_IPR152_ADDR,	// 152 - INTB152
	ICU_IPR153_ADDR,	// 153 - INTB153
	ICU_IPR154_ADDR,	// 154 - INTB154
	ICU_IPR155_ADDR,	// 155 - INTB155
	ICU_IPR156_ADDR,	// 156 - INTB156
	ICU_IPR157_ADDR,	// 157 - INTB157
	ICU_IPR158_ADDR,	// 158 - INTB158
	ICU_IPR159_ADDR,	// 159 - INTB159
	ICU_IPR160_ADDR,	// 160 - INTB160
	ICU_IPR161_ADDR,	// 161 - INTB161
	ICU_IPR162_ADDR,	// 162 - INTB162
	ICU_IPR163_ADDR,	// 163 - INTB163
	ICU_IPR164_ADDR,	// 164 - INTB164
	ICU_IPR165_ADDR,	// 165 - INTB165
	ICU_IPR166_ADDR,	// 166 - INTB166
	ICU_IPR167_ADDR,	// 167 - INTB167
	ICU_IPR168_ADDR,	// 168 - INTB168
	ICU_IPR169_ADDR,	// 169 - INTB169
	ICU_IPR170_ADDR,	// 170 - INTB170
	ICU_IPR171_ADDR,	// 171 - INTB171
	ICU_IPR172_ADDR,	// 172 - INTB172
	ICU_IPR173_ADDR,	// 173 - INTB173
	ICU_IPR174_ADDR,	// 174 - INTB174
	ICU_IPR175_ADDR,	// 175 - INTB175
	ICU_IPR176_ADDR,	// 176 - INTB176
	ICU_IPR177_ADDR,	// 177 - INTB177
	ICU_IPR178_ADDR,	// 178 - INTB178
	ICU_IPR179_ADDR,	// 179 - INTB179
	ICU_IPR180_ADDR,	// 180 - INTB180
	ICU_IPR181_ADDR,	// 181 - INTB181
	ICU_IPR182_ADDR,	// 182 - INTB182
	ICU_IPR183_ADDR,	// 183 - INTB183
	ICU_IPR184_ADDR,	// 184 - INTB184
	ICU_IPR185_ADDR,	// 185 - INTB185
	ICU_IPR186_ADDR,	// 186 - INTB186
	ICU_IPR187_ADDR,	// 187 - INTB187
	ICU_IPR188_ADDR,	// 188 - INTB188
	ICU_IPR189_ADDR,	// 189 - INTB189
	ICU_IPR190_ADDR,	// 190 - INTB190
	ICU_IPR191_ADDR,	// 191 - INTB191
	ICU_IPR192_ADDR,	// 192 - INTB192
	ICU_IPR193_ADDR,	// 193 - INTB193
	ICU_IPR194_ADDR,	// 194 - INTB194
	ICU_IPR195_ADDR,	// 195 - INTB195
	ICU_IPR196_ADDR,	// 196 - INTB196
	ICU_IPR197_ADDR,	// 197 - INTB197
	ICU_IPR198_ADDR,	// 198 - INTB198
	ICU_IPR199_ADDR,	// 199 - INTB199
	ICU_IPR200_ADDR,	// 200 - INTB200
	ICU_IPR201_ADDR,	// 201 - INTB201
	ICU_IPR202_ADDR,	// 202 - INTB202
	ICU_IPR203_ADDR,	// 203 - INTB203
	ICU_IPR204_ADDR,	// 204 - INTB204
	ICU_IPR205_ADDR,	// 205 - INTB205
	ICU_IPR206_ADDR,	// 206 - INTB206
	ICU_IPR207_ADDR,	// 207 - INTB207
	ICU_IPR208_ADDR,	// 208 - INTB208
	ICU_IPR209_ADDR,	// 209 - INTB209
	ICU_IPR210_ADDR,	// 210 - INTB210
	ICU_IPR211_ADDR,	// 211 - INTB211
	ICU_IPR212_ADDR,	// 212 - INTB212
	ICU_IPR213_ADDR,	// 213 - INTB213
	ICU_IPR214_ADDR,	// 214 - INTB214
	ICU_IPR215_ADDR,	// 215 - INTB215
	ICU_IPR216_ADDR,	// 216 - INTB216
	ICU_IPR217_ADDR,	// 217 - INTB217
	ICU_IPR218_ADDR,	// 218 - INTB218
	ICU_IPR219_ADDR,	// 219 - INTB219
	ICU_IPR220_ADDR,	// 220 - INTB220
	ICU_IPR221_ADDR,	// 221 - INTB221
	ICU_IPR222_ADDR,	// 222 - INTB222
	ICU_IPR223_ADDR,	// 223 - INTB223
	ICU_IPR224_ADDR,	// 224 - INTB224
	ICU_IPR225_ADDR,	// 225 - INTB225
	ICU_IPR226_ADDR,	// 226 - INTB226
	ICU_IPR227_ADDR,	// 227 - INTB227
	ICU_IPR228_ADDR,	// 228 - INTB228
	ICU_IPR229_ADDR,	// 229 - INTB229
	ICU_IPR230_ADDR,	// 230 - INTB230
	ICU_IPR231_ADDR,	// 231 - INTB231
	ICU_IPR232_ADDR,	// 232 - INTB232
	ICU_IPR233_ADDR,	// 233 - INTB233
	ICU_IPR234_ADDR,	// 234 - INTB234
	ICU_IPR235_ADDR,	// 235 - INTB235
	ICU_IPR236_ADDR,	// 236 - INTB236
	ICU_IPR237_ADDR,	// 237 - INTB237
	ICU_IPR238_ADDR,	// 238 - INTB238
	ICU_IPR239_ADDR,	// 239 - INTB239
	ICU_IPR240_ADDR,	// 240 - INTB240
	ICU_IPR241_ADDR,	// 241 - INTB241
	ICU_IPR242_ADDR,	// 242 - INTB242
	ICU_IPR243_ADDR,	// 243 - INTB243
	ICU_IPR244_ADDR,	// 244 - INTB244
	ICU_IPR245_ADDR,	// 245 - INTB245
	ICU_IPR246_ADDR,	// 246 - INTB246
	ICU_IPR247_ADDR,	// 247 - INTB247
	ICU_IPR248_ADDR,	// 248 - INTB248
	ICU_IPR249_ADDR,	// 249 - INTB249
	ICU_IPR250_ADDR,	// 250 - INTB250
	ICU_IPR251_ADDR,	// 251 - INTB251
	ICU_IPR252_ADDR,	// 252 - INTB252
	ICU_IPR253_ADDR,	// 253 - INTB253
	ICU_IPR254_ADDR,	// 254 - INTB254
	ICU_IPR255_ADDR		// 255 - INTB255
};
