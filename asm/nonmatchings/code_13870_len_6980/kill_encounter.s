.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kill_encounter
/* 19B30 8003E730 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19B34 8003E734 AFBF001C */  sw        $ra, 0x1c($sp)
/* 19B38 8003E738 AFB20018 */  sw        $s2, 0x18($sp)
/* 19B3C 8003E73C AFB10014 */  sw        $s1, 0x14($sp)
/* 19B40 8003E740 AFB00010 */  sw        $s0, 0x10($sp)
/* 19B44 8003E744 80820004 */  lb        $v0, 4($a0)
/* 19B48 8003E748 00021080 */  sll       $v0, $v0, 2
/* 19B4C 8003E74C 3C12800B */  lui       $s2, 0x800b
/* 19B50 8003E750 02429021 */  addu      $s2, $s2, $v0
/* 19B54 8003E754 8E520F38 */  lw        $s2, 0xf38($s2)
/* 19B58 8003E758 8E420000 */  lw        $v0, ($s2)
/* 19B5C 8003E75C 1840000D */  blez      $v0, .L8003E794
/* 19B60 8003E760 0000882D */   daddu    $s1, $zero, $zero
/* 19B64 8003E764 0240802D */  daddu     $s0, $s2, $zero
.L8003E768:
/* 19B68 8003E768 8E040004 */  lw        $a0, 4($s0)
/* 19B6C 8003E76C 10800004 */  beqz      $a0, .L8003E780
/* 19B70 8003E770 00000000 */   nop      
/* 19B74 8003E774 0C00F9EB */  jal       kill_enemy
/* 19B78 8003E778 00000000 */   nop      
/* 19B7C 8003E77C AE000004 */  sw        $zero, 4($s0)
.L8003E780:
/* 19B80 8003E780 8E420000 */  lw        $v0, ($s2)
/* 19B84 8003E784 26310001 */  addiu     $s1, $s1, 1
/* 19B88 8003E788 0222102A */  slt       $v0, $s1, $v0
/* 19B8C 8003E78C 1440FFF6 */  bnez      $v0, .L8003E768
/* 19B90 8003E790 26100004 */   addiu    $s0, $s0, 4
.L8003E794:
/* 19B94 8003E794 8FBF001C */  lw        $ra, 0x1c($sp)
/* 19B98 8003E798 8FB20018 */  lw        $s2, 0x18($sp)
/* 19B9C 8003E79C 8FB10014 */  lw        $s1, 0x14($sp)
/* 19BA0 8003E7A0 8FB00010 */  lw        $s0, 0x10($sp)
/* 19BA4 8003E7A4 03E00008 */  jr        $ra
/* 19BA8 8003E7A8 27BD0020 */   addiu    $sp, $sp, 0x20
