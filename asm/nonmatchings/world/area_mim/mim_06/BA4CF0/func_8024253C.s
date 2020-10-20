.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024253C
/* BA6CBC 8024253C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BA6CC0 80242540 AFB40040 */  sw        $s4, 0x40($sp)
/* BA6CC4 80242544 0080A02D */  daddu     $s4, $a0, $zero
/* BA6CC8 80242548 AFBF0044 */  sw        $ra, 0x44($sp)
/* BA6CCC 8024254C AFB3003C */  sw        $s3, 0x3c($sp)
/* BA6CD0 80242550 AFB20038 */  sw        $s2, 0x38($sp)
/* BA6CD4 80242554 AFB10034 */  sw        $s1, 0x34($sp)
/* BA6CD8 80242558 AFB00030 */  sw        $s0, 0x30($sp)
/* BA6CDC 8024255C 8E920148 */  lw        $s2, 0x148($s4)
/* BA6CE0 80242560 00A0882D */  daddu     $s1, $a1, $zero
/* BA6CE4 80242564 86440008 */  lh        $a0, 8($s2)
/* BA6CE8 80242568 0C00EABB */  jal       get_npc_unsafe
/* BA6CEC 8024256C 00C0982D */   daddu    $s3, $a2, $zero
/* BA6CF0 80242570 8E230014 */  lw        $v1, 0x14($s1)
/* BA6CF4 80242574 0460002D */  bltz      $v1, .L8024262C
/* BA6CF8 80242578 0040802D */   daddu    $s0, $v0, $zero
/* BA6CFC 8024257C 0260202D */  daddu     $a0, $s3, $zero
/* BA6D00 80242580 AFA00010 */  sw        $zero, 0x10($sp)
/* BA6D04 80242584 8E260024 */  lw        $a2, 0x24($s1)
/* BA6D08 80242588 8E270028 */  lw        $a3, 0x28($s1)
/* BA6D0C 8024258C 0C01242D */  jal       func_800490B4
/* BA6D10 80242590 0240282D */   daddu    $a1, $s2, $zero
/* BA6D14 80242594 10400025 */  beqz      $v0, .L8024262C
/* BA6D18 80242598 0000202D */   daddu    $a0, $zero, $zero
/* BA6D1C 8024259C 0200282D */  daddu     $a1, $s0, $zero
/* BA6D20 802425A0 0000302D */  daddu     $a2, $zero, $zero
/* BA6D24 802425A4 860300A8 */  lh        $v1, 0xa8($s0)
/* BA6D28 802425A8 3C013F80 */  lui       $at, 0x3f80
/* BA6D2C 802425AC 44810000 */  mtc1      $at, $f0
/* BA6D30 802425B0 3C014000 */  lui       $at, 0x4000
/* BA6D34 802425B4 44811000 */  mtc1      $at, $f2
/* BA6D38 802425B8 3C01C1A0 */  lui       $at, 0xc1a0
/* BA6D3C 802425BC 44812000 */  mtc1      $at, $f4
/* BA6D40 802425C0 2402000F */  addiu     $v0, $zero, 0xf
/* BA6D44 802425C4 AFA2001C */  sw        $v0, 0x1c($sp)
/* BA6D48 802425C8 44833000 */  mtc1      $v1, $f6
/* BA6D4C 802425CC 00000000 */  nop       
/* BA6D50 802425D0 468031A0 */  cvt.s.w   $f6, $f6
/* BA6D54 802425D4 44073000 */  mfc1      $a3, $f6
/* BA6D58 802425D8 27A20028 */  addiu     $v0, $sp, 0x28
/* BA6D5C 802425DC AFA20020 */  sw        $v0, 0x20($sp)
/* BA6D60 802425E0 E7A00010 */  swc1      $f0, 0x10($sp)
/* BA6D64 802425E4 E7A20014 */  swc1      $f2, 0x14($sp)
/* BA6D68 802425E8 0C01BFA4 */  jal       fx_emote
/* BA6D6C 802425EC E7A40018 */   swc1     $f4, 0x18($sp)
/* BA6D70 802425F0 0200202D */  daddu     $a0, $s0, $zero
/* BA6D74 802425F4 240502F4 */  addiu     $a1, $zero, 0x2f4
/* BA6D78 802425F8 0C012530 */  jal       func_800494C0
/* BA6D7C 802425FC 3C060020 */   lui      $a2, 0x20
/* BA6D80 80242600 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BA6D84 80242604 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BA6D88 80242608 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BA6D8C 8024260C C60E0040 */  lwc1      $f14, 0x40($s0)
/* BA6D90 80242610 8C460028 */  lw        $a2, 0x28($v0)
/* BA6D94 80242614 0C00A720 */  jal       atan2
/* BA6D98 80242618 8C470030 */   lw       $a3, 0x30($v0)
/* BA6D9C 8024261C 2402000C */  addiu     $v0, $zero, 0xc
/* BA6DA0 80242620 E600000C */  swc1      $f0, 0xc($s0)
/* BA6DA4 80242624 080909B0 */  j         .L802426C0
/* BA6DA8 80242628 AE820070 */   sw       $v0, 0x70($s4)
.L8024262C:
/* BA6DAC 8024262C 8602008C */  lh        $v0, 0x8c($s0)
/* BA6DB0 80242630 14400023 */  bnez      $v0, .L802426C0
/* BA6DB4 80242634 00000000 */   nop      
/* BA6DB8 80242638 9602008E */  lhu       $v0, 0x8e($s0)
/* BA6DBC 8024263C 2442FFFF */  addiu     $v0, $v0, -1
/* BA6DC0 80242640 A602008E */  sh        $v0, 0x8e($s0)
/* BA6DC4 80242644 00021400 */  sll       $v0, $v0, 0x10
/* BA6DC8 80242648 1C40001D */  bgtz      $v0, .L802426C0
/* BA6DCC 8024264C 00000000 */   nop      
/* BA6DD0 80242650 8E820074 */  lw        $v0, 0x74($s4)
/* BA6DD4 80242654 2442FFFF */  addiu     $v0, $v0, -1
/* BA6DD8 80242658 18400018 */  blez      $v0, .L802426BC
/* BA6DDC 8024265C AE820074 */   sw       $v0, 0x74($s4)
/* BA6DE0 80242660 C600000C */  lwc1      $f0, 0xc($s0)
/* BA6DE4 80242664 3C014334 */  lui       $at, 0x4334
/* BA6DE8 80242668 44816000 */  mtc1      $at, $f12
/* BA6DEC 8024266C 0C00A6C9 */  jal       clamp_angle
/* BA6DF0 80242670 460C0300 */   add.s    $f12, $f0, $f12
/* BA6DF4 80242674 240403E8 */  addiu     $a0, $zero, 0x3e8
/* BA6DF8 80242678 0C00A67F */  jal       rand_int
/* BA6DFC 8024267C E600000C */   swc1     $f0, 0xc($s0)
/* BA6E00 80242680 3C032E8B */  lui       $v1, 0x2e8b
/* BA6E04 80242684 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* BA6E08 80242688 00430018 */  mult      $v0, $v1
/* BA6E0C 8024268C 00021FC3 */  sra       $v1, $v0, 0x1f
/* BA6E10 80242690 00004010 */  mfhi      $t0
/* BA6E14 80242694 00082043 */  sra       $a0, $t0, 1
/* BA6E18 80242698 00832023 */  subu      $a0, $a0, $v1
/* BA6E1C 8024269C 00041840 */  sll       $v1, $a0, 1
/* BA6E20 802426A0 00641821 */  addu      $v1, $v1, $a0
/* BA6E24 802426A4 00031880 */  sll       $v1, $v1, 2
/* BA6E28 802426A8 00641823 */  subu      $v1, $v1, $a0
/* BA6E2C 802426AC 00431023 */  subu      $v0, $v0, $v1
/* BA6E30 802426B0 24420005 */  addiu     $v0, $v0, 5
/* BA6E34 802426B4 080909B0 */  j         .L802426C0
/* BA6E38 802426B8 A602008E */   sh       $v0, 0x8e($s0)
.L802426BC:
/* BA6E3C 802426BC AE800070 */  sw        $zero, 0x70($s4)
.L802426C0:
/* BA6E40 802426C0 8FBF0044 */  lw        $ra, 0x44($sp)
/* BA6E44 802426C4 8FB40040 */  lw        $s4, 0x40($sp)
/* BA6E48 802426C8 8FB3003C */  lw        $s3, 0x3c($sp)
/* BA6E4C 802426CC 8FB20038 */  lw        $s2, 0x38($sp)
/* BA6E50 802426D0 8FB10034 */  lw        $s1, 0x34($sp)
/* BA6E54 802426D4 8FB00030 */  lw        $s0, 0x30($sp)
/* BA6E58 802426D8 03E00008 */  jr        $ra
/* BA6E5C 802426DC 27BD0048 */   addiu    $sp, $sp, 0x48
