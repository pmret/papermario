.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CA8_9086D8
/* 9086D8 80240CA8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 9086DC 80240CAC 3C05FD05 */  lui       $a1, 0xfd05
/* 9086E0 80240CB0 AFBF0028 */  sw        $ra, 0x28($sp)
/* 9086E4 80240CB4 0C0B1EAF */  jal       get_variable
/* 9086E8 80240CB8 34A50F80 */   ori      $a1, $a1, 0xf80
/* 9086EC 80240CBC 3C01428C */  lui       $at, 0x428c
/* 9086F0 80240CC0 44810000 */  mtc1      $at, $f0
/* 9086F4 80240CC4 3C0141A0 */  lui       $at, 0x41a0
/* 9086F8 80240CC8 44811000 */  mtc1      $at, $f2
/* 9086FC 80240CCC 3C013FC0 */  lui       $at, 0x3fc0
/* 908700 80240CD0 44812000 */  mtc1      $at, $f4
/* 908704 80240CD4 24030014 */  addiu     $v1, $zero, 0x14
/* 908708 80240CD8 AFA3001C */  sw        $v1, 0x1c($sp)
/* 90870C 80240CDC 2403000F */  addiu     $v1, $zero, 0xf
/* 908710 80240CE0 AFA30020 */  sw        $v1, 0x20($sp)
/* 908714 80240CE4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 908718 80240CE8 E7A20014 */  swc1      $f2, 0x14($sp)
/* 90871C 80240CEC E7A40018 */  swc1      $f4, 0x18($sp)
/* 908720 80240CF0 8C450000 */  lw        $a1, ($v0)
/* 908724 80240CF4 8C460004 */  lw        $a2, 4($v0)
/* 908728 80240CF8 8C470008 */  lw        $a3, 8($v0)
/* 90872C 80240CFC 0C01C8D4 */  jal       func_80072350
/* 908730 80240D00 24040002 */   addiu    $a0, $zero, 2
/* 908734 80240D04 8FBF0028 */  lw        $ra, 0x28($sp)
/* 908738 80240D08 24020002 */  addiu     $v0, $zero, 2
/* 90873C 80240D0C 03E00008 */  jr        $ra
/* 908740 80240D10 27BD0030 */   addiu    $sp, $sp, 0x30
