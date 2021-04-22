.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024140C_EA9EEC
/* EA9EEC 8024140C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EA9EF0 80241410 AFB00010 */  sw        $s0, 0x10($sp)
/* EA9EF4 80241414 0080802D */  daddu     $s0, $a0, $zero
/* EA9EF8 80241418 AFBF0014 */  sw        $ra, 0x14($sp)
/* EA9EFC 8024141C 0C00AFF5 */  jal       func_8002BFD4
/* EA9F00 80241420 24040780 */   addiu    $a0, $zero, 0x780
/* EA9F04 80241424 0200202D */  daddu     $a0, $s0, $zero
/* EA9F08 80241428 3C05FD05 */  lui       $a1, 0xfd05
/* EA9F0C 8024142C 34A50F80 */  ori       $a1, $a1, 0xf80
/* EA9F10 80241430 0C0B551A */  jal       dead_set_variable
/* EA9F14 80241434 0040302D */   daddu    $a2, $v0, $zero
/* EA9F18 80241438 2402FFFF */  addiu     $v0, $zero, -1
/* EA9F1C 8024143C 3C058024 */  lui       $a1, %hi(func_802413C0_EA9EA0)
/* EA9F20 80241440 24A513C0 */  addiu     $a1, $a1, %lo(func_802413C0_EA9EA0)
/* EA9F24 80241444 3C018025 */  lui       $at, %hi(D_80248380)
/* EA9F28 80241448 AC228380 */  sw        $v0, %lo(D_80248380)($at)
/* EA9F2C 8024144C 0C04B7FA */  jal       func_8012DFE8
/* EA9F30 80241450 0000202D */   daddu    $a0, $zero, $zero
/* EA9F34 80241454 8FBF0014 */  lw        $ra, 0x14($sp)
/* EA9F38 80241458 8FB00010 */  lw        $s0, 0x10($sp)
/* EA9F3C 8024145C 24020002 */  addiu     $v0, $zero, 2
/* EA9F40 80241460 03E00008 */  jr        $ra
/* EA9F44 80241464 27BD0018 */   addiu    $sp, $sp, 0x18
