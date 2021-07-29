.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045780
/* 20B80 80045780 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 20B84 80045784 AFBF0010 */  sw        $ra, 0x10($sp)
/* 20B88 80045788 0000202D */  daddu     $a0, $zero, $zero
/* 20B8C 8004578C 3C03800A */  lui       $v1, %hi(D_8009E9D0)
/* 20B90 80045790 2463E9D0 */  addiu     $v1, $v1, %lo(D_8009E9D0)
.L80045794:
/* 20B94 80045794 A4600010 */  sh        $zero, 0x10($v1)
/* 20B98 80045798 AC600018 */  sw        $zero, 0x18($v1)
/* 20B9C 8004579C 24840001 */  addiu     $a0, $a0, 1
/* 20BA0 800457A0 28820020 */  slti      $v0, $a0, 0x20
/* 20BA4 800457A4 1440FFFB */  bnez      $v0, .L80045794
/* 20BA8 800457A8 2463001C */   addiu    $v1, $v1, 0x1c
/* 20BAC 800457AC 3C058004 */  lui       $a1, %hi(func_80045888)
/* 20BB0 800457B0 24A55888 */  addiu     $a1, $a1, %lo(func_80045888)
/* 20BB4 800457B4 0C04A0DA */  jal       func_80128368
/* 20BB8 800457B8 0000202D */   daddu    $a0, $zero, $zero
/* 20BBC 800457BC 0C011718 */  jal       func_80045C60
/* 20BC0 800457C0 00000000 */   nop
/* 20BC4 800457C4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 20BC8 800457C8 03E00008 */  jr        $ra
/* 20BCC 800457CC 27BD0018 */   addiu    $sp, $sp, 0x18
