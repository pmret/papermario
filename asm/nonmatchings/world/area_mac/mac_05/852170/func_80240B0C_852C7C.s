.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B0C_852C7C
/* 852C7C 80240B0C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 852C80 80240B10 AFB10014 */  sw        $s1, 0x14($sp)
/* 852C84 80240B14 0080882D */  daddu     $s1, $a0, $zero
/* 852C88 80240B18 AFBF001C */  sw        $ra, 0x1c($sp)
/* 852C8C 80240B1C AFB20018 */  sw        $s2, 0x18($sp)
/* 852C90 80240B20 AFB00010 */  sw        $s0, 0x10($sp)
/* 852C94 80240B24 8E300148 */  lw        $s0, 0x148($s1)
/* 852C98 80240B28 86040008 */  lh        $a0, 8($s0)
/* 852C9C 80240B2C 0C00EABB */  jal       get_npc_unsafe
/* 852CA0 80240B30 00A0902D */   daddu    $s2, $a1, $zero
/* 852CA4 80240B34 8E230078 */  lw        $v1, 0x78($s1)
/* 852CA8 80240B38 24630001 */  addiu     $v1, $v1, 1
/* 852CAC 80240B3C AE230078 */  sw        $v1, 0x78($s1)
/* 852CB0 80240B40 8E0400D0 */  lw        $a0, 0xd0($s0)
/* 852CB4 80240B44 8C840000 */  lw        $a0, ($a0)
/* 852CB8 80240B48 0064182A */  slt       $v1, $v1, $a0
/* 852CBC 80240B4C 14600002 */  bnez      $v1, .L80240B58
/* 852CC0 80240B50 0040282D */   daddu    $a1, $v0, $zero
/* 852CC4 80240B54 AE200078 */  sw        $zero, 0x78($s1)
.L80240B58:
/* 852CC8 80240B58 8E0200CC */  lw        $v0, 0xcc($s0)
/* 852CCC 80240B5C 8C420004 */  lw        $v0, 4($v0)
/* 852CD0 80240B60 ACA20028 */  sw        $v0, 0x28($a1)
/* 852CD4 80240B64 8E0200D0 */  lw        $v0, 0xd0($s0)
/* 852CD8 80240B68 8C42007C */  lw        $v0, 0x7c($v0)
/* 852CDC 80240B6C 04410004 */  bgez      $v0, .L80240B80
/* 852CE0 80240B70 00000000 */   nop
/* 852CE4 80240B74 C6400000 */  lwc1      $f0, ($s2)
/* 852CE8 80240B78 080902E8 */  j         .L80240BA0
/* 852CEC 80240B7C E4A00018 */   swc1     $f0, 0x18($a1)
.L80240B80:
/* 852CF0 80240B80 3C018025 */  lui       $at, %hi(D_802527B8_864928)
/* 852CF4 80240B84 D42227B8 */  ldc1      $f2, %lo(D_802527B8_864928)($at)
/* 852CF8 80240B88 44820000 */  mtc1      $v0, $f0
/* 852CFC 80240B8C 00000000 */  nop
/* 852D00 80240B90 46800021 */  cvt.d.w   $f0, $f0
/* 852D04 80240B94 46220003 */  div.d     $f0, $f0, $f2
/* 852D08 80240B98 46200020 */  cvt.s.d   $f0, $f0
/* 852D0C 80240B9C E4A00018 */  swc1      $f0, 0x18($a1)
.L80240BA0:
/* 852D10 80240BA0 24020001 */  addiu     $v0, $zero, 1
/* 852D14 80240BA4 AE220070 */  sw        $v0, 0x70($s1)
/* 852D18 80240BA8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 852D1C 80240BAC 8FB20018 */  lw        $s2, 0x18($sp)
/* 852D20 80240BB0 8FB10014 */  lw        $s1, 0x14($sp)
/* 852D24 80240BB4 8FB00010 */  lw        $s0, 0x10($sp)
/* 852D28 80240BB8 03E00008 */  jr        $ra
/* 852D2C 80240BBC 27BD0020 */   addiu    $sp, $sp, 0x20
