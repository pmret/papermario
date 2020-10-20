.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A1C_B375EC
/* B375EC 80242A1C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B375F0 80242A20 AFB10014 */  sw        $s1, 0x14($sp)
/* B375F4 80242A24 0080882D */  daddu     $s1, $a0, $zero
/* B375F8 80242A28 AFB00010 */  sw        $s0, 0x10($sp)
/* B375FC 80242A2C 00A0802D */  daddu     $s0, $a1, $zero
/* B37600 80242A30 AFBF0018 */  sw        $ra, 0x18($sp)
/* B37604 80242A34 0C00EABB */  jal       get_npc_unsafe
/* B37608 80242A38 2404FFFC */   addiu    $a0, $zero, -4
/* B3760C 80242A3C 12000003 */  beqz      $s0, .L80242A4C
/* B37610 80242A40 0040182D */   daddu    $v1, $v0, $zero
/* B37614 80242A44 2402003C */  addiu     $v0, $zero, 0x3c
/* B37618 80242A48 AE220070 */  sw        $v0, 0x70($s1)
.L80242A4C:
/* B3761C 80242A4C C462000C */  lwc1      $f2, 0xc($v1)
/* B37620 80242A50 3C0141F0 */  lui       $at, 0x41f0
/* B37624 80242A54 44810000 */  mtc1      $at, $f0
/* B37628 80242A58 00000000 */  nop       
/* B3762C 80242A5C 46001000 */  add.s     $f0, $f2, $f0
/* B37630 80242A60 3C0143B4 */  lui       $at, 0x43b4
/* B37634 80242A64 44811000 */  mtc1      $at, $f2
/* B37638 80242A68 00000000 */  nop       
/* B3763C 80242A6C 4600103E */  c.le.s    $f2, $f0
/* B37640 80242A70 00000000 */  nop       
/* B37644 80242A74 45000003 */  bc1f      .L80242A84
/* B37648 80242A78 E460000C */   swc1     $f0, 0xc($v1)
/* B3764C 80242A7C 46020001 */  sub.s     $f0, $f0, $f2
/* B37650 80242A80 E460000C */  swc1      $f0, 0xc($v1)
.L80242A84:
/* B37654 80242A84 8E230070 */  lw        $v1, 0x70($s1)
/* B37658 80242A88 2463FFFF */  addiu     $v1, $v1, -1
/* B3765C 80242A8C 000317C3 */  sra       $v0, $v1, 0x1f
/* B37660 80242A90 AE230070 */  sw        $v1, 0x70($s1)
/* B37664 80242A94 8FBF0018 */  lw        $ra, 0x18($sp)
/* B37668 80242A98 8FB10014 */  lw        $s1, 0x14($sp)
/* B3766C 80242A9C 8FB00010 */  lw        $s0, 0x10($sp)
/* B37670 80242AA0 30420002 */  andi      $v0, $v0, 2
/* B37674 80242AA4 03E00008 */  jr        $ra
/* B37678 80242AA8 27BD0020 */   addiu    $sp, $sp, 0x20
