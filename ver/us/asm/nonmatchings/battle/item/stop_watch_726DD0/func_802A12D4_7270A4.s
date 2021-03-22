.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A12D4_7270A4
/* 7270A4 802A12D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7270A8 802A12D8 AFB00010 */  sw        $s0, 0x10($sp)
/* 7270AC 802A12DC 0080802D */  daddu     $s0, $a0, $zero
/* 7270B0 802A12E0 10A00003 */  beqz      $a1, .L802A12F0
/* 7270B4 802A12E4 AFBF0014 */   sw       $ra, 0x14($sp)
/* 7270B8 802A12E8 24020014 */  addiu     $v0, $zero, 0x14
/* 7270BC 802A12EC AE020070 */  sw        $v0, 0x70($s0)
.L802A12F0:
/* 7270C0 802A12F0 0000202D */  daddu     $a0, $zero, $zero
/* 7270C4 802A12F4 0080282D */  daddu     $a1, $a0, $zero
/* 7270C8 802A12F8 8E020070 */  lw        $v0, 0x70($s0)
/* 7270CC 802A12FC 0080302D */  daddu     $a2, $a0, $zero
/* 7270D0 802A1300 00023880 */  sll       $a3, $v0, 2
/* 7270D4 802A1304 00E23821 */  addu      $a3, $a3, $v0
/* 7270D8 802A1308 00073840 */  sll       $a3, $a3, 1
/* 7270DC 802A130C 0C046F97 */  jal       set_background_color_blend
/* 7270E0 802A1310 30E700FE */   andi     $a3, $a3, 0xfe
/* 7270E4 802A1314 8E020070 */  lw        $v0, 0x70($s0)
/* 7270E8 802A1318 2442FFFF */  addiu     $v0, $v0, -1
/* 7270EC 802A131C 10400003 */  beqz      $v0, .L802A132C
/* 7270F0 802A1320 AE020070 */   sw       $v0, 0x70($s0)
/* 7270F4 802A1324 080A84D1 */  j         .L802A1344
/* 7270F8 802A1328 0000102D */   daddu    $v0, $zero, $zero
.L802A132C:
/* 7270FC 802A132C 0000202D */  daddu     $a0, $zero, $zero
/* 727100 802A1330 0080282D */  daddu     $a1, $a0, $zero
/* 727104 802A1334 0080302D */  daddu     $a2, $a0, $zero
/* 727108 802A1338 0C046F97 */  jal       set_background_color_blend
/* 72710C 802A133C 0080382D */   daddu    $a3, $a0, $zero
/* 727110 802A1340 24020002 */  addiu     $v0, $zero, 2
.L802A1344:
/* 727114 802A1344 8FBF0014 */  lw        $ra, 0x14($sp)
/* 727118 802A1348 8FB00010 */  lw        $s0, 0x10($sp)
/* 72711C 802A134C 03E00008 */  jr        $ra
nop
