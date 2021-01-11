.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802424A0_EE0E60
/* EE0E60 802424A0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* EE0E64 802424A4 AFB3003C */  sw        $s3, 0x3c($sp)
/* EE0E68 802424A8 0080982D */  daddu     $s3, $a0, $zero
/* EE0E6C 802424AC AFBF0040 */  sw        $ra, 0x40($sp)
/* EE0E70 802424B0 AFB20038 */  sw        $s2, 0x38($sp)
/* EE0E74 802424B4 AFB10034 */  sw        $s1, 0x34($sp)
/* EE0E78 802424B8 AFB00030 */  sw        $s0, 0x30($sp)
/* EE0E7C 802424BC 8E710148 */  lw        $s1, 0x148($s3)
/* EE0E80 802424C0 0C00F92F */  jal       func_8003E4BC
/* EE0E84 802424C4 86240008 */   lh       $a0, 8($s1)
/* EE0E88 802424C8 0040802D */  daddu     $s0, $v0, $zero
/* EE0E8C 802424CC 8E22007C */  lw        $v0, 0x7c($s1)
/* EE0E90 802424D0 8603008E */  lh        $v1, 0x8e($s0)
/* EE0E94 802424D4 2442FFFF */  addiu     $v0, $v0, -1
/* EE0E98 802424D8 14620012 */  bne       $v1, $v0, .L80242524
/* EE0E9C 802424DC 00000000 */   nop      
/* EE0EA0 802424E0 C6000038 */  lwc1      $f0, 0x38($s0)
/* EE0EA4 802424E4 4600020D */  trunc.w.s $f8, $f0
/* EE0EA8 802424E8 44024000 */  mfc1      $v0, $f8
/* EE0EAC 802424EC 00000000 */  nop       
/* EE0EB0 802424F0 A6220010 */  sh        $v0, 0x10($s1)
/* EE0EB4 802424F4 C600003C */  lwc1      $f0, 0x3c($s0)
/* EE0EB8 802424F8 4600020D */  trunc.w.s $f8, $f0
/* EE0EBC 802424FC 44024000 */  mfc1      $v0, $f8
/* EE0EC0 80242500 00000000 */  nop       
/* EE0EC4 80242504 A6220012 */  sh        $v0, 0x12($s1)
/* EE0EC8 80242508 C6000040 */  lwc1      $f0, 0x40($s0)
/* EE0ECC 8024250C 24020001 */  addiu     $v0, $zero, 1
/* EE0ED0 80242510 A2220007 */  sb        $v0, 7($s1)
/* EE0ED4 80242514 4600020D */  trunc.w.s $f8, $f0
/* EE0ED8 80242518 44024000 */  mfc1      $v0, $f8
/* EE0EDC 8024251C 00000000 */  nop       
/* EE0EE0 80242520 A6220014 */  sh        $v0, 0x14($s1)
.L80242524:
/* EE0EE4 80242524 C6000038 */  lwc1      $f0, 0x38($s0)
/* EE0EE8 80242528 C602003C */  lwc1      $f2, 0x3c($s0)
/* EE0EEC 8024252C C6040040 */  lwc1      $f4, 0x40($s0)
/* EE0EF0 80242530 C6060018 */  lwc1      $f6, 0x18($s0)
/* EE0EF4 80242534 E7A00020 */  swc1      $f0, 0x20($sp)
/* EE0EF8 80242538 E7A20024 */  swc1      $f2, 0x24($sp)
/* EE0EFC 8024253C E7A40028 */  swc1      $f4, 0x28($sp)
/* EE0F00 80242540 E7A60010 */  swc1      $f6, 0x10($sp)
/* EE0F04 80242544 C600000C */  lwc1      $f0, 0xc($s0)
/* EE0F08 80242548 E7A00014 */  swc1      $f0, 0x14($sp)
/* EE0F0C 8024254C 860200A8 */  lh        $v0, 0xa8($s0)
/* EE0F10 80242550 27A50020 */  addiu     $a1, $sp, 0x20
/* EE0F14 80242554 44820000 */  mtc1      $v0, $f0
/* EE0F18 80242558 00000000 */  nop       
/* EE0F1C 8024255C 46800020 */  cvt.s.w   $f0, $f0
/* EE0F20 80242560 E7A00018 */  swc1      $f0, 0x18($sp)
/* EE0F24 80242564 860200A6 */  lh        $v0, 0xa6($s0)
/* EE0F28 80242568 27A60024 */  addiu     $a2, $sp, 0x24
/* EE0F2C 8024256C 44820000 */  mtc1      $v0, $f0
/* EE0F30 80242570 00000000 */  nop       
/* EE0F34 80242574 46800020 */  cvt.s.w   $f0, $f0
/* EE0F38 80242578 E7A0001C */  swc1      $f0, 0x1c($sp)
/* EE0F3C 8024257C 8E040080 */  lw        $a0, 0x80($s0)
/* EE0F40 80242580 0C0394C1 */  jal       func_800E5304
/* EE0F44 80242584 27A70028 */   addiu    $a3, $sp, 0x28
/* EE0F48 80242588 0040902D */  daddu     $s2, $v0, $zero
/* EE0F4C 8024258C 16400005 */  bnez      $s2, .L802425A4
/* EE0F50 80242590 00000000 */   nop      
/* EE0F54 80242594 8E050018 */  lw        $a1, 0x18($s0)
/* EE0F58 80242598 8E06000C */  lw        $a2, 0xc($s0)
/* EE0F5C 8024259C 0C00F909 */  jal       func_8003E424
/* EE0F60 802425A0 0200202D */   daddu    $a0, $s0, $zero
.L802425A4:
/* EE0F64 802425A4 8602008E */  lh        $v0, 0x8e($s0)
/* EE0F68 802425A8 9603008E */  lhu       $v1, 0x8e($s0)
/* EE0F6C 802425AC 18400007 */  blez      $v0, .L802425CC
/* EE0F70 802425B0 2462FFFF */   addiu    $v0, $v1, -1
/* EE0F74 802425B4 A602008E */  sh        $v0, 0x8e($s0)
/* EE0F78 802425B8 00021400 */  sll       $v0, $v0, 0x10
/* EE0F7C 802425BC 18400003 */  blez      $v0, .L802425CC
/* EE0F80 802425C0 00000000 */   nop      
/* EE0F84 802425C4 12400008 */  beqz      $s2, .L802425E8
/* EE0F88 802425C8 00000000 */   nop      
.L802425CC:
/* EE0F8C 802425CC 8E2200CC */  lw        $v0, 0xcc($s1)
/* EE0F90 802425D0 A2200007 */  sb        $zero, 7($s1)
/* EE0F94 802425D4 8C420028 */  lw        $v0, 0x28($v0)
/* EE0F98 802425D8 A600008E */  sh        $zero, 0x8e($s0)
/* EE0F9C 802425DC AE020028 */  sw        $v0, 0x28($s0)
/* EE0FA0 802425E0 2402000F */  addiu     $v0, $zero, 0xf
/* EE0FA4 802425E4 AE620070 */  sw        $v0, 0x70($s3)
.L802425E8:
/* EE0FA8 802425E8 8FBF0040 */  lw        $ra, 0x40($sp)
/* EE0FAC 802425EC 8FB3003C */  lw        $s3, 0x3c($sp)
/* EE0FB0 802425F0 8FB20038 */  lw        $s2, 0x38($sp)
/* EE0FB4 802425F4 8FB10034 */  lw        $s1, 0x34($sp)
/* EE0FB8 802425F8 8FB00030 */  lw        $s0, 0x30($sp)
/* EE0FBC 802425FC 03E00008 */  jr        $ra
/* EE0FC0 80242600 27BD0048 */   addiu    $sp, $sp, 0x48
