.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B10_8A2EE0
/* 8A2EE0 80240B10 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 8A2EE4 80240B14 AFB3003C */  sw        $s3, 0x3c($sp)
/* 8A2EE8 80240B18 0080982D */  daddu     $s3, $a0, $zero
/* 8A2EEC 80240B1C AFBF0040 */  sw        $ra, 0x40($sp)
/* 8A2EF0 80240B20 AFB20038 */  sw        $s2, 0x38($sp)
/* 8A2EF4 80240B24 AFB10034 */  sw        $s1, 0x34($sp)
/* 8A2EF8 80240B28 AFB00030 */  sw        $s0, 0x30($sp)
/* 8A2EFC 80240B2C 8E710148 */  lw        $s1, 0x148($s3)
/* 8A2F00 80240B30 0C00EABB */  jal       get_npc_unsafe
/* 8A2F04 80240B34 86240008 */   lh       $a0, 8($s1)
/* 8A2F08 80240B38 0040802D */  daddu     $s0, $v0, $zero
/* 8A2F0C 80240B3C 8E22007C */  lw        $v0, 0x7c($s1)
/* 8A2F10 80240B40 8603008E */  lh        $v1, 0x8e($s0)
/* 8A2F14 80240B44 2442FFFF */  addiu     $v0, $v0, -1
/* 8A2F18 80240B48 14620012 */  bne       $v1, $v0, .L80240B94
/* 8A2F1C 80240B4C 00000000 */   nop      
/* 8A2F20 80240B50 C6000038 */  lwc1      $f0, 0x38($s0)
/* 8A2F24 80240B54 4600020D */  trunc.w.s $f8, $f0
/* 8A2F28 80240B58 44024000 */  mfc1      $v0, $f8
/* 8A2F2C 80240B5C 00000000 */  nop       
/* 8A2F30 80240B60 A6220010 */  sh        $v0, 0x10($s1)
/* 8A2F34 80240B64 C600003C */  lwc1      $f0, 0x3c($s0)
/* 8A2F38 80240B68 4600020D */  trunc.w.s $f8, $f0
/* 8A2F3C 80240B6C 44024000 */  mfc1      $v0, $f8
/* 8A2F40 80240B70 00000000 */  nop       
/* 8A2F44 80240B74 A6220012 */  sh        $v0, 0x12($s1)
/* 8A2F48 80240B78 C6000040 */  lwc1      $f0, 0x40($s0)
/* 8A2F4C 80240B7C 24020001 */  addiu     $v0, $zero, 1
/* 8A2F50 80240B80 A2220007 */  sb        $v0, 7($s1)
/* 8A2F54 80240B84 4600020D */  trunc.w.s $f8, $f0
/* 8A2F58 80240B88 44024000 */  mfc1      $v0, $f8
/* 8A2F5C 80240B8C 00000000 */  nop       
/* 8A2F60 80240B90 A6220014 */  sh        $v0, 0x14($s1)
.L80240B94:
/* 8A2F64 80240B94 C6000038 */  lwc1      $f0, 0x38($s0)
/* 8A2F68 80240B98 C602003C */  lwc1      $f2, 0x3c($s0)
/* 8A2F6C 80240B9C C6040040 */  lwc1      $f4, 0x40($s0)
/* 8A2F70 80240BA0 C6060018 */  lwc1      $f6, 0x18($s0)
/* 8A2F74 80240BA4 E7A00020 */  swc1      $f0, 0x20($sp)
/* 8A2F78 80240BA8 E7A20024 */  swc1      $f2, 0x24($sp)
/* 8A2F7C 80240BAC E7A40028 */  swc1      $f4, 0x28($sp)
/* 8A2F80 80240BB0 E7A60010 */  swc1      $f6, 0x10($sp)
/* 8A2F84 80240BB4 C600000C */  lwc1      $f0, 0xc($s0)
/* 8A2F88 80240BB8 E7A00014 */  swc1      $f0, 0x14($sp)
/* 8A2F8C 80240BBC 860200A8 */  lh        $v0, 0xa8($s0)
/* 8A2F90 80240BC0 27A50020 */  addiu     $a1, $sp, 0x20
/* 8A2F94 80240BC4 44820000 */  mtc1      $v0, $f0
/* 8A2F98 80240BC8 00000000 */  nop       
/* 8A2F9C 80240BCC 46800020 */  cvt.s.w   $f0, $f0
/* 8A2FA0 80240BD0 E7A00018 */  swc1      $f0, 0x18($sp)
/* 8A2FA4 80240BD4 860200A6 */  lh        $v0, 0xa6($s0)
/* 8A2FA8 80240BD8 27A60024 */  addiu     $a2, $sp, 0x24
/* 8A2FAC 80240BDC 44820000 */  mtc1      $v0, $f0
/* 8A2FB0 80240BE0 00000000 */  nop       
/* 8A2FB4 80240BE4 46800020 */  cvt.s.w   $f0, $f0
/* 8A2FB8 80240BE8 E7A0001C */  swc1      $f0, 0x1c($sp)
/* 8A2FBC 80240BEC 8E040080 */  lw        $a0, 0x80($s0)
/* 8A2FC0 80240BF0 0C037711 */  jal       func_800DDC44
/* 8A2FC4 80240BF4 27A70028 */   addiu    $a3, $sp, 0x28
/* 8A2FC8 80240BF8 0040902D */  daddu     $s2, $v0, $zero
/* 8A2FCC 80240BFC 16400005 */  bnez      $s2, .L80240C14
/* 8A2FD0 80240C00 00000000 */   nop      
/* 8A2FD4 80240C04 8E050018 */  lw        $a1, 0x18($s0)
/* 8A2FD8 80240C08 8E06000C */  lw        $a2, 0xc($s0)
/* 8A2FDC 80240C0C 0C00EA95 */  jal       npc_move_heading
/* 8A2FE0 80240C10 0200202D */   daddu    $a0, $s0, $zero
.L80240C14:
/* 8A2FE4 80240C14 8602008E */  lh        $v0, 0x8e($s0)
/* 8A2FE8 80240C18 9603008E */  lhu       $v1, 0x8e($s0)
/* 8A2FEC 80240C1C 18400007 */  blez      $v0, .L80240C3C
/* 8A2FF0 80240C20 2462FFFF */   addiu    $v0, $v1, -1
/* 8A2FF4 80240C24 A602008E */  sh        $v0, 0x8e($s0)
/* 8A2FF8 80240C28 00021400 */  sll       $v0, $v0, 0x10
/* 8A2FFC 80240C2C 18400003 */  blez      $v0, .L80240C3C
/* 8A3000 80240C30 00000000 */   nop      
/* 8A3004 80240C34 12400008 */  beqz      $s2, .L80240C58
/* 8A3008 80240C38 00000000 */   nop      
.L80240C3C:
/* 8A300C 80240C3C 8E2200CC */  lw        $v0, 0xcc($s1)
/* 8A3010 80240C40 A2200007 */  sb        $zero, 7($s1)
/* 8A3014 80240C44 8C420028 */  lw        $v0, 0x28($v0)
/* 8A3018 80240C48 A600008E */  sh        $zero, 0x8e($s0)
/* 8A301C 80240C4C AE020028 */  sw        $v0, 0x28($s0)
/* 8A3020 80240C50 2402000F */  addiu     $v0, $zero, 0xf
/* 8A3024 80240C54 AE620070 */  sw        $v0, 0x70($s3)
.L80240C58:
/* 8A3028 80240C58 8FBF0040 */  lw        $ra, 0x40($sp)
/* 8A302C 80240C5C 8FB3003C */  lw        $s3, 0x3c($sp)
/* 8A3030 80240C60 8FB20038 */  lw        $s2, 0x38($sp)
/* 8A3034 80240C64 8FB10034 */  lw        $s1, 0x34($sp)
/* 8A3038 80240C68 8FB00030 */  lw        $s0, 0x30($sp)
/* 8A303C 80240C6C 03E00008 */  jr        $ra
/* 8A3040 80240C70 27BD0048 */   addiu    $sp, $sp, 0x48
