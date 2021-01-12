.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024E748
/* 17D028 8024E748 3C028028 */  lui       $v0, %hi(D_80280CE0)
/* 17D02C 8024E74C 80420CE0 */  lb        $v0, %lo(D_80280CE0)($v0)
/* 17D030 8024E750 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 17D034 8024E754 AFB20018 */  sw        $s2, 0x18($sp)
/* 17D038 8024E758 0080902D */  daddu     $s2, $a0, $zero
/* 17D03C 8024E75C AFB10014 */  sw        $s1, 0x14($sp)
/* 17D040 8024E760 3C11800B */  lui       $s1, %hi(D_800B22D8)
/* 17D044 8024E764 263122D8 */  addiu     $s1, $s1, %lo(D_800B22D8)
/* 17D048 8024E768 AFBF001C */  sw        $ra, 0x1c($sp)
/* 17D04C 8024E76C AFB00010 */  sw        $s0, 0x10($sp)
/* 17D050 8024E770 8E50000C */  lw        $s0, 0xc($s2)
/* 17D054 8024E774 14400024 */  bnez      $v0, .L8024E808
/* 17D058 8024E778 24020002 */   addiu    $v0, $zero, 2
/* 17D05C 8024E77C 8E050000 */  lw        $a1, ($s0)
/* 17D060 8024E780 26100004 */  addiu     $s0, $s0, 4
/* 17D064 8024E784 0C0B1EAF */  jal       get_variable
/* 17D068 8024E788 0240202D */   daddu    $a0, $s2, $zero
/* 17D06C 8024E78C 0240202D */  daddu     $a0, $s2, $zero
/* 17D070 8024E790 8E050000 */  lw        $a1, ($s0)
/* 17D074 8024E794 0C0B1EAF */  jal       get_variable
/* 17D078 8024E798 0040802D */   daddu    $s0, $v0, $zero
/* 17D07C 8024E79C 0040182D */  daddu     $v1, $v0, $zero
/* 17D080 8024E7A0 2610FFFF */  addiu     $s0, $s0, -1
/* 17D084 8024E7A4 2E020008 */  sltiu     $v0, $s0, 8
/* 17D088 8024E7A8 10400016 */  beqz      $v0, .L8024E804
/* 17D08C 8024E7AC 00101080 */   sll      $v0, $s0, 2
/* 17D090 8024E7B0 3C01802A */  lui       $at, %hi(jtbl_8029CD70_1CB650)
/* 17D094 8024E7B4 00220821 */  addu      $at, $at, $v0
/* 17D098 8024E7B8 8C22CD70 */  lw        $v0, %lo(jtbl_8029CD70_1CB650)($at)
/* 17D09C 8024E7BC 00400008 */  jr        $v0
/* 17D0A0 8024E7C0 00000000 */   nop
glabel L8024E7C4_17D0A4
/* 17D0A4 8024E7C4 08093A01 */  j         .L8024E804
/* 17D0A8 8024E7C8 A623001C */   sh       $v1, 0x1c($s1)
glabel L8024E7CC_17D0AC
/* 17D0AC 8024E7CC 08093A01 */  j         .L8024E804
/* 17D0B0 8024E7D0 A623001E */   sh       $v1, 0x1e($s1)
glabel L8024E7D4_17D0B4
/* 17D0B4 8024E7D4 08093A01 */  j         .L8024E804
/* 17D0B8 8024E7D8 A6230020 */   sh       $v1, 0x20($s1)
glabel L8024E7DC_17D0BC
/* 17D0BC 8024E7DC 08093A01 */  j         .L8024E804
/* 17D0C0 8024E7E0 A6230022 */   sh       $v1, 0x22($s1)
glabel L8024E7E4_17D0C4
/* 17D0C4 8024E7E4 08093A01 */  j         .L8024E804
/* 17D0C8 8024E7E8 A6230024 */   sh       $v1, 0x24($s1)
glabel L8024E7EC_17D0CC
/* 17D0CC 8024E7EC 00031200 */  sll       $v0, $v1, 8
/* 17D0D0 8024E7F0 08093A01 */  j         .L8024E804
/* 17D0D4 8024E7F4 A6220026 */   sh       $v0, 0x26($s1)
glabel L8024E7F8_17D0D8
/* 17D0D8 8024E7F8 08093A01 */  j         .L8024E804
/* 17D0DC 8024E7FC A6230028 */   sh       $v1, 0x28($s1)
glabel L8024E800_17D0E0
/* 17D0E0 8024E800 A623002A */  sh        $v1, 0x2a($s1)
.L8024E804:
/* 17D0E4 8024E804 24020002 */  addiu     $v0, $zero, 2
.L8024E808:
/* 17D0E8 8024E808 8FBF001C */  lw        $ra, 0x1c($sp)
/* 17D0EC 8024E80C 8FB20018 */  lw        $s2, 0x18($sp)
/* 17D0F0 8024E810 8FB10014 */  lw        $s1, 0x14($sp)
/* 17D0F4 8024E814 8FB00010 */  lw        $s0, 0x10($sp)
/* 17D0F8 8024E818 03E00008 */  jr        $ra
/* 17D0FC 8024E81C 27BD0020 */   addiu    $sp, $sp, 0x20
