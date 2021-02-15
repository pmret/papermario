.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241360_A01960
/* A01960 80241360 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A01964 80241364 AFB10014 */  sw        $s1, 0x14($sp)
/* A01968 80241368 0080882D */  daddu     $s1, $a0, $zero
/* A0196C 8024136C 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* A01970 80241370 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* A01974 80241374 AFBF0018 */  sw        $ra, 0x18($sp)
/* A01978 80241378 AFB00010 */  sw        $s0, 0x10($sp)
/* A0197C 8024137C 8C460028 */  lw        $a2, 0x28($v0)
/* A01980 80241380 8E23000C */  lw        $v1, 0xc($s1)
/* A01984 80241384 3C01C3B6 */  lui       $at, 0xc3b6
/* A01988 80241388 44816000 */  mtc1      $at, $f12
/* A0198C 8024138C 3C01C307 */  lui       $at, 0xc307
/* A01990 80241390 44817000 */  mtc1      $at, $f14
/* A01994 80241394 8C470030 */  lw        $a3, 0x30($v0)
/* A01998 80241398 0C00A720 */  jal       atan2
/* A0199C 8024139C 8C700000 */   lw       $s0, ($v1)
/* A019A0 802413A0 4600008D */  trunc.w.s $f2, $f0
/* A019A4 802413A4 44061000 */  mfc1      $a2, $f2
/* A019A8 802413A8 0220202D */  daddu     $a0, $s1, $zero
/* A019AC 802413AC 0C0B2026 */  jal       set_variable
/* A019B0 802413B0 0200282D */   daddu    $a1, $s0, $zero
/* A019B4 802413B4 8FBF0018 */  lw        $ra, 0x18($sp)
/* A019B8 802413B8 8FB10014 */  lw        $s1, 0x14($sp)
/* A019BC 802413BC 8FB00010 */  lw        $s0, 0x10($sp)
/* A019C0 802413C0 24020002 */  addiu     $v0, $zero, 2
/* A019C4 802413C4 03E00008 */  jr        $ra
/* A019C8 802413C8 27BD0020 */   addiu    $sp, $sp, 0x20
