.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241358_BCFF48
/* BCFF48 80241358 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BCFF4C 8024135C AFBF0014 */  sw        $ra, 0x14($sp)
/* BCFF50 80241360 0C090150 */  jal       func_80240540_BCF130
/* BCFF54 80241364 AFB00010 */   sw       $s0, 0x10($sp)
/* BCFF58 80241368 0000202D */  daddu     $a0, $zero, $zero
/* BCFF5C 8024136C 3C05FD05 */  lui       $a1, 0xfd05
/* BCFF60 80241370 34A50F88 */  ori       $a1, $a1, 0xf88
/* BCFF64 80241374 0040802D */  daddu     $s0, $v0, $zero
/* BCFF68 80241378 2402000A */  addiu     $v0, $zero, 0xa
/* BCFF6C 8024137C 0C0B1EAF */  jal       evt_get_variable
/* BCFF70 80241380 AE020030 */   sw       $v0, 0x30($s0)
/* BCFF74 80241384 0000202D */  daddu     $a0, $zero, $zero
/* BCFF78 80241388 3C05FD05 */  lui       $a1, 0xfd05
/* BCFF7C 8024138C 34A50F89 */  ori       $a1, $a1, 0xf89
/* BCFF80 80241390 0C0B1EAF */  jal       evt_get_variable
/* BCFF84 80241394 AE02004C */   sw       $v0, 0x4c($s0)
/* BCFF88 80241398 0000202D */  daddu     $a0, $zero, $zero
/* BCFF8C 8024139C 3C05FD05 */  lui       $a1, 0xfd05
/* BCFF90 802413A0 34A50F8A */  ori       $a1, $a1, 0xf8a
/* BCFF94 802413A4 0C0B1EAF */  jal       evt_get_variable
/* BCFF98 802413A8 AE020050 */   sw       $v0, 0x50($s0)
/* BCFF9C 802413AC AE020054 */  sw        $v0, 0x54($s0)
/* BCFFA0 802413B0 3C038016 */  lui       $v1, %hi(D_80159B08)
/* BCFFA4 802413B4 8C639B08 */  lw        $v1, %lo(D_80159B08)($v1)
/* BCFFA8 802413B8 AE03000C */  sw        $v1, 0xc($s0)
/* BCFFAC 802413BC 8FBF0014 */  lw        $ra, 0x14($sp)
/* BCFFB0 802413C0 8FB00010 */  lw        $s0, 0x10($sp)
/* BCFFB4 802413C4 24020002 */  addiu     $v0, $zero, 2
/* BCFFB8 802413C8 03E00008 */  jr        $ra
/* BCFFBC 802413CC 27BD0018 */   addiu    $sp, $sp, 0x18
