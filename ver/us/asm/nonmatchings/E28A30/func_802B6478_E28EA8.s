.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6478_E28EA8
/* E28EA8 802B6478 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E28EAC 802B647C 3C058011 */  lui       $a1, %hi(gPlayerStatus)
/* E28EB0 802B6480 24A5EFC8 */  addiu     $a1, $a1, %lo(gPlayerStatus)
/* E28EB4 802B6484 AFBF0014 */  sw        $ra, 0x14($sp)
/* E28EB8 802B6488 AFB00010 */  sw        $s0, 0x10($sp)
/* E28EBC 802B648C 8CA20000 */  lw        $v0, ($a1)
/* E28EC0 802B6490 0441000E */  bgez      $v0, .L802B64CC
/* E28EC4 802B6494 00A0802D */   daddu    $s0, $a1, $zero
/* E28EC8 802B6498 3C037FFF */  lui       $v1, 0x7fff
/* E28ECC 802B649C 3463FFFF */  ori       $v1, $v1, 0xffff
/* E28ED0 802B64A0 3C040001 */  lui       $a0, 1
/* E28ED4 802B64A4 3484001F */  ori       $a0, $a0, 0x1f
/* E28ED8 802B64A8 00431824 */  and       $v1, $v0, $v1
/* E28EDC 802B64AC 3C020008 */  lui       $v0, 8
/* E28EE0 802B64B0 00621825 */  or        $v1, $v1, $v0
/* E28EE4 802B64B4 ACA30000 */  sw        $v1, ($a1)
/* E28EE8 802B64B8 A4A00008 */  sh        $zero, 8($a1)
/* E28EEC 802B64BC A0A000B6 */  sb        $zero, 0xb6($a1)
/* E28EF0 802B64C0 ACA00054 */  sw        $zero, 0x54($a1)
/* E28EF4 802B64C4 0C037FDE */  jal       func_800DFF78
/* E28EF8 802B64C8 ACA0008C */   sw       $zero, 0x8c($a1)
.L802B64CC:
/* E28EFC 802B64CC 8E020004 */  lw        $v0, 4($s0)
/* E28F00 802B64D0 30420200 */  andi      $v0, $v0, 0x200
/* E28F04 802B64D4 14400008 */  bnez      $v0, .L802B64F8
/* E28F08 802B64D8 00000000 */   nop
/* E28F0C 802B64DC 0C039769 */  jal       set_action_state
/* E28F10 802B64E0 0000202D */   daddu    $a0, $zero, $zero
/* E28F14 802B64E4 3C03FFF7 */  lui       $v1, 0xfff7
/* E28F18 802B64E8 8E020000 */  lw        $v0, ($s0)
/* E28F1C 802B64EC 3463FFFF */  ori       $v1, $v1, 0xffff
/* E28F20 802B64F0 00431024 */  and       $v0, $v0, $v1
/* E28F24 802B64F4 AE020000 */  sw        $v0, ($s0)
.L802B64F8:
/* E28F28 802B64F8 8FBF0014 */  lw        $ra, 0x14($sp)
/* E28F2C 802B64FC 8FB00010 */  lw        $s0, 0x10($sp)
/* E28F30 802B6500 03E00008 */  jr        $ra
/* E28F34 802B6504 27BD0018 */   addiu    $sp, $sp, 0x18
