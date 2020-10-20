.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024047C_864FBC
/* 864FBC 8024047C 44800000 */  mtc1      $zero, $f0
/* 864FC0 80240480 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 864FC4 80240484 44050000 */  mfc1      $a1, $f0
/* 864FC8 80240488 0000202D */  daddu     $a0, $zero, $zero
/* 864FCC 8024048C AFBF0018 */  sw        $ra, 0x18($sp)
/* 864FD0 80240490 AFA00014 */  sw        $zero, 0x14($sp)
/* 864FD4 80240494 E7A00010 */  swc1      $f0, 0x10($sp)
/* 864FD8 80240498 00A0302D */  daddu     $a2, $a1, $zero
/* 864FDC 8024049C 0C01CA54 */  jal       func_80072950
/* 864FE0 802404A0 00A0382D */   daddu    $a3, $a1, $zero
/* 864FE4 802404A4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 864FE8 802404A8 24020002 */  addiu     $v0, $zero, 2
/* 864FEC 802404AC 03E00008 */  jr        $ra
/* 864FF0 802404B0 27BD0020 */   addiu    $sp, $sp, 0x20
/* 864FF4 802404B4 00000000 */  nop       
/* 864FF8 802404B8 00000000 */  nop       
/* 864FFC 802404BC 00000000 */  nop       
