.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802181F4_52B894
/* 52B894 802181F4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 52B898 802181F8 AFB00010 */  sw        $s0, 0x10($sp)
/* 52B89C 802181FC 0080802D */  daddu     $s0, $a0, $zero
/* 52B8A0 80218200 AFBF0018 */  sw        $ra, 0x18($sp)
/* 52B8A4 80218204 AFB10014 */  sw        $s1, 0x14($sp)
/* 52B8A8 80218208 8E040148 */  lw        $a0, 0x148($s0)
/* 52B8AC 8021820C 0C09A75B */  jal       get_actor
/* 52B8B0 80218210 8E11000C */   lw       $s1, 0xc($s0)
/* 52B8B4 80218214 8E250000 */  lw        $a1, ($s1)
/* 52B8B8 80218218 0C0B1EAF */  jal       get_variable
/* 52B8BC 8021821C 0200202D */   daddu    $a0, $s0, $zero
/* 52B8C0 80218220 44820000 */  mtc1      $v0, $f0
/* 52B8C4 80218224 00000000 */  nop
/* 52B8C8 80218228 46800020 */  cvt.s.w   $f0, $f0
/* 52B8CC 8021822C 44050000 */  mfc1      $a1, $f0
/* 52B8D0 80218230 0C04DF69 */  jal       func_80137DA4
/* 52B8D4 80218234 2404000D */   addiu    $a0, $zero, 0xd
/* 52B8D8 80218238 8FBF0018 */  lw        $ra, 0x18($sp)
/* 52B8DC 8021823C 8FB10014 */  lw        $s1, 0x14($sp)
/* 52B8E0 80218240 8FB00010 */  lw        $s0, 0x10($sp)
/* 52B8E4 80218244 24020002 */  addiu     $v0, $zero, 2
/* 52B8E8 80218248 03E00008 */  jr        $ra
/* 52B8EC 8021824C 27BD0020 */   addiu    $sp, $sp, 0x20
