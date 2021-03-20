.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A12D4_72BBE4
/* 72BBE4 802A12D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 72BBE8 802A12D8 AFB00010 */  sw        $s0, 0x10($sp)
/* 72BBEC 802A12DC 0080802D */  daddu     $s0, $a0, $zero
/* 72BBF0 802A12E0 10A00003 */  beqz      $a1, .L802A12F0
/* 72BBF4 802A12E4 AFBF0014 */   sw       $ra, 0x14($sp)
/* 72BBF8 802A12E8 24020014 */  addiu     $v0, $zero, 0x14
/* 72BBFC 802A12EC AE020070 */  sw        $v0, 0x70($s0)
.L802A12F0:
/* 72BC00 802A12F0 0000202D */  daddu     $a0, $zero, $zero
/* 72BC04 802A12F4 0080282D */  daddu     $a1, $a0, $zero
/* 72BC08 802A12F8 8E020070 */  lw        $v0, 0x70($s0)
/* 72BC0C 802A12FC 0080302D */  daddu     $a2, $a0, $zero
/* 72BC10 802A1300 00023880 */  sll       $a3, $v0, 2
/* 72BC14 802A1304 00E23821 */  addu      $a3, $a3, $v0
/* 72BC18 802A1308 00073840 */  sll       $a3, $a3, 1
/* 72BC1C 802A130C 0C046F97 */  jal       set_background_color_blend
/* 72BC20 802A1310 30E700FE */   andi     $a3, $a3, 0xfe
/* 72BC24 802A1314 8E020070 */  lw        $v0, 0x70($s0)
/* 72BC28 802A1318 2442FFFF */  addiu     $v0, $v0, -1
/* 72BC2C 802A131C 10400003 */  beqz      $v0, .L802A132C
/* 72BC30 802A1320 AE020070 */   sw       $v0, 0x70($s0)
/* 72BC34 802A1324 080A84D1 */  j         .L802A1344
/* 72BC38 802A1328 0000102D */   daddu    $v0, $zero, $zero
.L802A132C:
/* 72BC3C 802A132C 0000202D */  daddu     $a0, $zero, $zero
/* 72BC40 802A1330 0080282D */  daddu     $a1, $a0, $zero
/* 72BC44 802A1334 0080302D */  daddu     $a2, $a0, $zero
/* 72BC48 802A1338 0C046F97 */  jal       set_background_color_blend
/* 72BC4C 802A133C 0080382D */   daddu    $a3, $a0, $zero
/* 72BC50 802A1340 24020002 */  addiu     $v0, $zero, 2
.L802A1344:
/* 72BC54 802A1344 8FBF0014 */  lw        $ra, 0x14($sp)
/* 72BC58 802A1348 8FB00010 */  lw        $s0, 0x10($sp)
/* 72BC5C 802A134C 03E00008 */  jr        $ra
nop
