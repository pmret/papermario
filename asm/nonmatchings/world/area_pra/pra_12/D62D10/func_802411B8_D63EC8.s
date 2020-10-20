.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411B8_D63EC8
/* D63EC8 802411B8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D63ECC 802411BC AFB00010 */  sw        $s0, 0x10($sp)
/* D63ED0 802411C0 0080802D */  daddu     $s0, $a0, $zero
/* D63ED4 802411C4 AFBF0014 */  sw        $ra, 0x14($sp)
/* D63ED8 802411C8 8E02000C */  lw        $v0, 0xc($s0)
/* D63EDC 802411CC 0C0B1EAF */  jal       get_variable
/* D63EE0 802411D0 8C450000 */   lw       $a1, ($v0)
/* D63EE4 802411D4 00021140 */  sll       $v0, $v0, 5
/* D63EE8 802411D8 AE000084 */  sw        $zero, 0x84($s0)
/* D63EEC 802411DC 3C018008 */  lui       $at, 0x8008
/* D63EF0 802411E0 00220821 */  addu      $at, $at, $v0
/* D63EF4 802411E4 942278F8 */  lhu       $v0, 0x78f8($at)
/* D63EF8 802411E8 30420040 */  andi      $v0, $v0, 0x40
/* D63EFC 802411EC 10400002 */  beqz      $v0, .L802411F8
/* D63F00 802411F0 24020001 */   addiu    $v0, $zero, 1
/* D63F04 802411F4 AE020084 */  sw        $v0, 0x84($s0)
.L802411F8:
/* D63F08 802411F8 8FBF0014 */  lw        $ra, 0x14($sp)
/* D63F0C 802411FC 8FB00010 */  lw        $s0, 0x10($sp)
/* D63F10 80241200 24020002 */  addiu     $v0, $zero, 2
/* D63F14 80241204 03E00008 */  jr        $ra
/* D63F18 80241208 27BD0018 */   addiu    $sp, $sp, 0x18
/* D63F1C 8024120C 00000000 */  nop       
