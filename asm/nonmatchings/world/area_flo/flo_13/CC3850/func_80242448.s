.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242448
/* CC5C58 80242448 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* CC5C5C 8024244C AFB3003C */  sw        $s3, 0x3c($sp)
/* CC5C60 80242450 0080982D */  daddu     $s3, $a0, $zero
/* CC5C64 80242454 AFBF0040 */  sw        $ra, 0x40($sp)
/* CC5C68 80242458 AFB20038 */  sw        $s2, 0x38($sp)
/* CC5C6C 8024245C AFB10034 */  sw        $s1, 0x34($sp)
/* CC5C70 80242460 AFB00030 */  sw        $s0, 0x30($sp)
/* CC5C74 80242464 8E710148 */  lw        $s1, 0x148($s3)
/* CC5C78 80242468 0C00EABB */  jal       get_npc_unsafe
/* CC5C7C 8024246C 86240008 */   lh       $a0, 8($s1)
/* CC5C80 80242470 0040802D */  daddu     $s0, $v0, $zero
/* CC5C84 80242474 8E22007C */  lw        $v0, 0x7c($s1)
/* CC5C88 80242478 8603008E */  lh        $v1, 0x8e($s0)
/* CC5C8C 8024247C 2442FFFF */  addiu     $v0, $v0, -1
/* CC5C90 80242480 14620012 */  bne       $v1, $v0, .L802424CC
/* CC5C94 80242484 00000000 */   nop      
/* CC5C98 80242488 C6000038 */  lwc1      $f0, 0x38($s0)
/* CC5C9C 8024248C 4600020D */  trunc.w.s $f8, $f0
/* CC5CA0 80242490 44024000 */  mfc1      $v0, $f8
/* CC5CA4 80242494 00000000 */  nop       
/* CC5CA8 80242498 A6220010 */  sh        $v0, 0x10($s1)
/* CC5CAC 8024249C C600003C */  lwc1      $f0, 0x3c($s0)
/* CC5CB0 802424A0 4600020D */  trunc.w.s $f8, $f0
/* CC5CB4 802424A4 44024000 */  mfc1      $v0, $f8
/* CC5CB8 802424A8 00000000 */  nop       
/* CC5CBC 802424AC A6220012 */  sh        $v0, 0x12($s1)
/* CC5CC0 802424B0 C6000040 */  lwc1      $f0, 0x40($s0)
/* CC5CC4 802424B4 24020001 */  addiu     $v0, $zero, 1
/* CC5CC8 802424B8 A2220007 */  sb        $v0, 7($s1)
/* CC5CCC 802424BC 4600020D */  trunc.w.s $f8, $f0
/* CC5CD0 802424C0 44024000 */  mfc1      $v0, $f8
/* CC5CD4 802424C4 00000000 */  nop       
/* CC5CD8 802424C8 A6220014 */  sh        $v0, 0x14($s1)
.L802424CC:
/* CC5CDC 802424CC C6000038 */  lwc1      $f0, 0x38($s0)
/* CC5CE0 802424D0 C602003C */  lwc1      $f2, 0x3c($s0)
/* CC5CE4 802424D4 C6040040 */  lwc1      $f4, 0x40($s0)
/* CC5CE8 802424D8 C6060018 */  lwc1      $f6, 0x18($s0)
/* CC5CEC 802424DC E7A00020 */  swc1      $f0, 0x20($sp)
/* CC5CF0 802424E0 E7A20024 */  swc1      $f2, 0x24($sp)
/* CC5CF4 802424E4 E7A40028 */  swc1      $f4, 0x28($sp)
/* CC5CF8 802424E8 E7A60010 */  swc1      $f6, 0x10($sp)
/* CC5CFC 802424EC C600000C */  lwc1      $f0, 0xc($s0)
/* CC5D00 802424F0 E7A00014 */  swc1      $f0, 0x14($sp)
/* CC5D04 802424F4 860200A8 */  lh        $v0, 0xa8($s0)
/* CC5D08 802424F8 27A50020 */  addiu     $a1, $sp, 0x20
/* CC5D0C 802424FC 44820000 */  mtc1      $v0, $f0
/* CC5D10 80242500 00000000 */  nop       
/* CC5D14 80242504 46800020 */  cvt.s.w   $f0, $f0
/* CC5D18 80242508 E7A00018 */  swc1      $f0, 0x18($sp)
/* CC5D1C 8024250C 860200A6 */  lh        $v0, 0xa6($s0)
/* CC5D20 80242510 27A60024 */  addiu     $a2, $sp, 0x24
/* CC5D24 80242514 44820000 */  mtc1      $v0, $f0
/* CC5D28 80242518 00000000 */  nop       
/* CC5D2C 8024251C 46800020 */  cvt.s.w   $f0, $f0
/* CC5D30 80242520 E7A0001C */  swc1      $f0, 0x1c($sp)
/* CC5D34 80242524 8E040080 */  lw        $a0, 0x80($s0)
/* CC5D38 80242528 0C037711 */  jal       func_800DDC44
/* CC5D3C 8024252C 27A70028 */   addiu    $a3, $sp, 0x28
/* CC5D40 80242530 0040902D */  daddu     $s2, $v0, $zero
/* CC5D44 80242534 16400005 */  bnez      $s2, .L8024254C
/* CC5D48 80242538 00000000 */   nop      
/* CC5D4C 8024253C 8E050018 */  lw        $a1, 0x18($s0)
/* CC5D50 80242540 8E06000C */  lw        $a2, 0xc($s0)
/* CC5D54 80242544 0C00EA95 */  jal       npc_move_heading
/* CC5D58 80242548 0200202D */   daddu    $a0, $s0, $zero
.L8024254C:
/* CC5D5C 8024254C 8602008E */  lh        $v0, 0x8e($s0)
/* CC5D60 80242550 9603008E */  lhu       $v1, 0x8e($s0)
/* CC5D64 80242554 18400007 */  blez      $v0, .L80242574
/* CC5D68 80242558 2462FFFF */   addiu    $v0, $v1, -1
/* CC5D6C 8024255C A602008E */  sh        $v0, 0x8e($s0)
/* CC5D70 80242560 00021400 */  sll       $v0, $v0, 0x10
/* CC5D74 80242564 18400003 */  blez      $v0, .L80242574
/* CC5D78 80242568 00000000 */   nop      
/* CC5D7C 8024256C 12400008 */  beqz      $s2, .L80242590
/* CC5D80 80242570 00000000 */   nop      
.L80242574:
/* CC5D84 80242574 8E2200CC */  lw        $v0, 0xcc($s1)
/* CC5D88 80242578 A2200007 */  sb        $zero, 7($s1)
/* CC5D8C 8024257C 8C420028 */  lw        $v0, 0x28($v0)
/* CC5D90 80242580 A600008E */  sh        $zero, 0x8e($s0)
/* CC5D94 80242584 AE020028 */  sw        $v0, 0x28($s0)
/* CC5D98 80242588 2402000F */  addiu     $v0, $zero, 0xf
/* CC5D9C 8024258C AE620070 */  sw        $v0, 0x70($s3)
.L80242590:
/* CC5DA0 80242590 8FBF0040 */  lw        $ra, 0x40($sp)
/* CC5DA4 80242594 8FB3003C */  lw        $s3, 0x3c($sp)
/* CC5DA8 80242598 8FB20038 */  lw        $s2, 0x38($sp)
/* CC5DAC 8024259C 8FB10034 */  lw        $s1, 0x34($sp)
/* CC5DB0 802425A0 8FB00030 */  lw        $s0, 0x30($sp)
/* CC5DB4 802425A4 03E00008 */  jr        $ra
/* CC5DB8 802425A8 27BD0048 */   addiu    $sp, $sp, 0x48
