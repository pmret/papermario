.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242BB8
/* D8FE08 80242BB8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D8FE0C 80242BBC AFB00010 */  sw        $s0, 0x10($sp)
/* D8FE10 80242BC0 0080802D */  daddu     $s0, $a0, $zero
/* D8FE14 80242BC4 AFBF0014 */  sw        $ra, 0x14($sp)
/* D8FE18 80242BC8 8E02000C */  lw        $v0, 0xc($s0)
/* D8FE1C 80242BCC 0C0B1EAF */  jal       get_variable
/* D8FE20 80242BD0 8C450000 */   lw       $a1, ($v0)
/* D8FE24 80242BD4 00021140 */  sll       $v0, $v0, 5
/* D8FE28 80242BD8 AE000084 */  sw        $zero, 0x84($s0)
/* D8FE2C 80242BDC 3C018008 */  lui       $at, 0x8008
/* D8FE30 80242BE0 00220821 */  addu      $at, $at, $v0
/* D8FE34 80242BE4 942278F8 */  lhu       $v0, 0x78f8($at)
/* D8FE38 80242BE8 30420040 */  andi      $v0, $v0, 0x40
/* D8FE3C 80242BEC 10400002 */  beqz      $v0, .L80242BF8
/* D8FE40 80242BF0 24020001 */   addiu    $v0, $zero, 1
/* D8FE44 80242BF4 AE020084 */  sw        $v0, 0x84($s0)
.L80242BF8:
/* D8FE48 80242BF8 8FBF0014 */  lw        $ra, 0x14($sp)
/* D8FE4C 80242BFC 8FB00010 */  lw        $s0, 0x10($sp)
/* D8FE50 80242C00 24020002 */  addiu     $v0, $zero, 2
/* D8FE54 80242C04 03E00008 */  jr        $ra
/* D8FE58 80242C08 27BD0018 */   addiu    $sp, $sp, 0x18
/* D8FE5C 80242C0C 00000000 */  nop       
