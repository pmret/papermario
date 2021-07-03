.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_8024F260_A394A0
.word L80244A58_A2EC98, L80244AC4_A2ED04, L80244AEC_A2ED2C, L80244B80_A2EDC0, L80244B2C_A2ED6C, 0, 0, 0

.section .text

glabel func_802449F0_A2EC30
/* A2EC30 802449F0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A2EC34 802449F4 3C038025 */  lui       $v1, %hi(D_8024DA98_A37CD8)
/* A2EC38 802449F8 2463DA98 */  addiu     $v1, $v1, %lo(D_8024DA98_A37CD8)
/* A2EC3C 802449FC AFBF0034 */  sw        $ra, 0x34($sp)
/* A2EC40 80244A00 AFB20030 */  sw        $s2, 0x30($sp)
/* A2EC44 80244A04 AFB1002C */  sw        $s1, 0x2c($sp)
/* A2EC48 80244A08 AFB00028 */  sw        $s0, 0x28($sp)
/* A2EC4C 80244A0C 8C620000 */  lw        $v0, ($v1)
/* A2EC50 80244A10 14400007 */  bnez      $v0, .L80244A30
/* A2EC54 80244A14 00000000 */   nop
/* A2EC58 80244A18 3C028007 */  lui       $v0, %hi(D_800779B0)
/* A2EC5C 80244A1C 904279B0 */  lbu       $v0, %lo(D_800779B0)($v0)
/* A2EC60 80244A20 00021080 */  sll       $v0, $v0, 2
/* A2EC64 80244A24 00441021 */  addu      $v0, $v0, $a0
/* A2EC68 80244A28 8C420000 */  lw        $v0, ($v0)
/* A2EC6C 80244A2C AC620000 */  sw        $v0, ($v1)
.L80244A30:
/* A2EC70 80244A30 3C038025 */  lui       $v1, %hi(D_8024DA90_A37CD0)
/* A2EC74 80244A34 8C63DA90 */  lw        $v1, %lo(D_8024DA90_A37CD0)($v1)
/* A2EC78 80244A38 2C620005 */  sltiu     $v0, $v1, 5
/* A2EC7C 80244A3C 10400050 */  beqz      $v0, L80244B80_A2EDC0
/* A2EC80 80244A40 00031080 */   sll      $v0, $v1, 2
/* A2EC84 80244A44 3C018025 */  lui       $at, %hi(jtbl_8024F260_A394A0)
/* A2EC88 80244A48 00220821 */  addu      $at, $at, $v0
/* A2EC8C 80244A4C 8C22F260 */  lw        $v0, %lo(jtbl_8024F260_A394A0)($at)
/* A2EC90 80244A50 00400008 */  jr        $v0
/* A2EC94 80244A54 00000000 */   nop
glabel L80244A58_A2EC98
/* A2EC98 80244A58 3C048025 */  lui       $a0, %hi(D_8024DA98_A37CD8)
/* A2EC9C 80244A5C 8C84DA98 */  lw        $a0, %lo(D_8024DA98_A37CD8)($a0)
/* A2ECA0 80244A60 8C830000 */  lw        $v1, ($a0)
/* A2ECA4 80244A64 2402FFFF */  addiu     $v0, $zero, -1
/* A2ECA8 80244A68 14620004 */  bne       $v1, $v0, .L80244A7C
/* A2ECAC 80244A6C 24020004 */   addiu    $v0, $zero, 4
/* A2ECB0 80244A70 8C830004 */  lw        $v1, 4($a0)
/* A2ECB4 80244A74 080912AB */  j         .L80244AAC
/* A2ECB8 80244A78 00000000 */   nop
.L80244A7C:
/* A2ECBC 80244A7C 3C038025 */  lui       $v1, %hi(D_8024DA94_A37CD4)
/* A2ECC0 80244A80 2463DA94 */  addiu     $v1, $v1, %lo(D_8024DA94_A37CD4)
/* A2ECC4 80244A84 8C620000 */  lw        $v0, ($v1)
/* A2ECC8 80244A88 2442000A */  addiu     $v0, $v0, 0xa
/* A2ECCC 80244A8C AC620000 */  sw        $v0, ($v1)
/* A2ECD0 80244A90 28420100 */  slti      $v0, $v0, 0x100
/* A2ECD4 80244A94 5440003B */  bnel      $v0, $zero, .L80244B84
/* A2ECD8 80244A98 24040001 */   addiu    $a0, $zero, 1
/* A2ECDC 80244A9C 240200FF */  addiu     $v0, $zero, 0xff
/* A2ECE0 80244AA0 AC620000 */  sw        $v0, ($v1)
/* A2ECE4 80244AA4 8C830004 */  lw        $v1, 4($a0)
/* A2ECE8 80244AA8 24020001 */  addiu     $v0, $zero, 1
.L80244AAC:
/* A2ECEC 80244AAC 3C018025 */  lui       $at, %hi(D_8024DA90_A37CD0)
/* A2ECF0 80244AB0 AC22DA90 */  sw        $v0, %lo(D_8024DA90_A37CD0)($at)
/* A2ECF4 80244AB4 3C018025 */  lui       $at, %hi(D_8024F570)
/* A2ECF8 80244AB8 AC23F570 */  sw        $v1, %lo(D_8024F570)($at)
/* A2ECFC 80244ABC 080912E1 */  j         .L80244B84
/* A2ED00 80244AC0 24040001 */   addiu    $a0, $zero, 1
glabel L80244AC4_A2ED04
/* A2ED04 80244AC4 3C038025 */  lui       $v1, %hi(D_8024F570)
/* A2ED08 80244AC8 2463F570 */  addiu     $v1, $v1, %lo(D_8024F570)
/* A2ED0C 80244ACC 8C620000 */  lw        $v0, ($v1)
/* A2ED10 80244AD0 1440001B */  bnez      $v0, .L80244B40
/* A2ED14 80244AD4 2442FFFF */   addiu    $v0, $v0, -1
/* A2ED18 80244AD8 24020002 */  addiu     $v0, $zero, 2
/* A2ED1C 80244ADC 3C018025 */  lui       $at, %hi(D_8024DA90_A37CD0)
/* A2ED20 80244AE0 AC22DA90 */  sw        $v0, %lo(D_8024DA90_A37CD0)($at)
/* A2ED24 80244AE4 080912E1 */  j         .L80244B84
/* A2ED28 80244AE8 24040001 */   addiu    $a0, $zero, 1
glabel L80244AEC_A2ED2C
/* A2ED2C 80244AEC 3C048025 */  lui       $a0, %hi(D_8024DA94_A37CD4)
/* A2ED30 80244AF0 2484DA94 */  addiu     $a0, $a0, %lo(D_8024DA94_A37CD4)
/* A2ED34 80244AF4 8C820000 */  lw        $v0, ($a0)
/* A2ED38 80244AF8 2442FFF6 */  addiu     $v0, $v0, -0xa
/* A2ED3C 80244AFC 04410020 */  bgez      $v0, L80244B80_A2EDC0
/* A2ED40 80244B00 AC820000 */   sw       $v0, ($a0)
/* A2ED44 80244B04 3C028025 */  lui       $v0, %hi(D_8024DA98_A37CD8)
/* A2ED48 80244B08 2442DA98 */  addiu     $v0, $v0, %lo(D_8024DA98_A37CD8)
/* A2ED4C 80244B0C 8C430000 */  lw        $v1, ($v0)
/* A2ED50 80244B10 AC800000 */  sw        $zero, ($a0)
/* A2ED54 80244B14 8C640008 */  lw        $a0, 8($v1)
/* A2ED58 80244B18 24630008 */  addiu     $v1, $v1, 8
/* A2ED5C 80244B1C 10800011 */  beqz      $a0, .L80244B64
/* A2ED60 80244B20 AC430000 */   sw       $v1, ($v0)
/* A2ED64 80244B24 080912DE */  j         .L80244B78
/* A2ED68 80244B28 00000000 */   nop
glabel L80244B2C_A2ED6C
/* A2ED6C 80244B2C 3C038025 */  lui       $v1, %hi(D_8024F570)
/* A2ED70 80244B30 2463F570 */  addiu     $v1, $v1, %lo(D_8024F570)
/* A2ED74 80244B34 8C620000 */  lw        $v0, ($v1)
/* A2ED78 80244B38 10400003 */  beqz      $v0, .L80244B48
/* A2ED7C 80244B3C 2442FFFF */   addiu    $v0, $v0, -1
.L80244B40:
/* A2ED80 80244B40 080912E0 */  j         L80244B80_A2EDC0
/* A2ED84 80244B44 AC620000 */   sw       $v0, ($v1)
.L80244B48:
/* A2ED88 80244B48 3C028025 */  lui       $v0, %hi(D_8024DA98_A37CD8)
/* A2ED8C 80244B4C 2442DA98 */  addiu     $v0, $v0, %lo(D_8024DA98_A37CD8)
/* A2ED90 80244B50 8C430000 */  lw        $v1, ($v0)
/* A2ED94 80244B54 8C640008 */  lw        $a0, 8($v1)
/* A2ED98 80244B58 24630008 */  addiu     $v1, $v1, 8
/* A2ED9C 80244B5C 14800006 */  bnez      $a0, .L80244B78
/* A2EDA0 80244B60 AC430000 */   sw       $v1, ($v0)
.L80244B64:
/* A2EDA4 80244B64 24020003 */  addiu     $v0, $zero, 3
/* A2EDA8 80244B68 3C018025 */  lui       $at, %hi(D_8024DA90_A37CD0)
/* A2EDAC 80244B6C AC22DA90 */  sw        $v0, %lo(D_8024DA90_A37CD0)($at)
/* A2EDB0 80244B70 080912E1 */  j         .L80244B84
/* A2EDB4 80244B74 24040001 */   addiu    $a0, $zero, 1
.L80244B78:
/* A2EDB8 80244B78 3C018025 */  lui       $at, %hi(D_8024DA90_A37CD0)
/* A2EDBC 80244B7C AC20DA90 */  sw        $zero, %lo(D_8024DA90_A37CD0)($at)
glabel L80244B80_A2EDC0
/* A2EDC0 80244B80 24040001 */  addiu     $a0, $zero, 1
.L80244B84:
/* A2EDC4 80244B84 27B00018 */  addiu     $s0, $sp, 0x18
/* A2EDC8 80244B88 0200282D */  daddu     $a1, $s0, $zero
/* A2EDCC 80244B8C 0C04DF70 */  jal       get_screen_overlay_params
/* A2EDD0 80244B90 27A6001C */   addiu    $a2, $sp, 0x1c
/* A2EDD4 80244B94 0000202D */  daddu     $a0, $zero, $zero
/* A2EDD8 80244B98 0200282D */  daddu     $a1, $s0, $zero
/* A2EDDC 80244B9C 0C04DF70 */  jal       get_screen_overlay_params
/* A2EDE0 80244BA0 27A60020 */   addiu    $a2, $sp, 0x20
/* A2EDE4 80244BA4 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* A2EDE8 80244BA8 3C01437F */  lui       $at, 0x437f
/* A2EDEC 80244BAC 44812000 */  mtc1      $at, $f4
/* A2EDF0 80244BB0 00000000 */  nop
/* A2EDF4 80244BB4 46022081 */  sub.s     $f2, $f4, $f2
/* A2EDF8 80244BB8 3C018025 */  lui       $at, %hi(D_8024DA94_A37CD4)
/* A2EDFC 80244BBC C420DA94 */  lwc1      $f0, %lo(D_8024DA94_A37CD4)($at)
/* A2EE00 80244BC0 46800020 */  cvt.s.w   $f0, $f0
/* A2EE04 80244BC4 46020002 */  mul.s     $f0, $f0, $f2
/* A2EE08 80244BC8 00000000 */  nop
/* A2EE0C 80244BCC C7A20020 */  lwc1      $f2, 0x20($sp)
/* A2EE10 80244BD0 46022081 */  sub.s     $f2, $f4, $f2
/* A2EE14 80244BD4 46020002 */  mul.s     $f0, $f0, $f2
/* A2EE18 80244BD8 00000000 */  nop
/* A2EE1C 80244BDC 46040003 */  div.s     $f0, $f0, $f4
/* A2EE20 80244BE0 46040003 */  div.s     $f0, $f0, $f4
/* A2EE24 80244BE4 4600018D */  trunc.w.s $f6, $f0
/* A2EE28 80244BE8 44113000 */  mfc1      $s1, $f6
/* A2EE2C 80244BEC 00000000 */  nop
/* A2EE30 80244BF0 1A200015 */  blez      $s1, .L80244C48
/* A2EE34 80244BF4 00000000 */   nop
/* A2EE38 80244BF8 3C128025 */  lui       $s2, %hi(D_8024DA98_A37CD8)
/* A2EE3C 80244BFC 2652DA98 */  addiu     $s2, $s2, %lo(D_8024DA98_A37CD8)
/* A2EE40 80244C00 8E420000 */  lw        $v0, ($s2)
/* A2EE44 80244C04 8C440000 */  lw        $a0, ($v0)
/* A2EE48 80244C08 1080000F */  beqz      $a0, .L80244C48
/* A2EE4C 80244C0C 00000000 */   nop
/* A2EE50 80244C10 0C04992C */  jal       get_string_lines
/* A2EE54 80244C14 0000802D */   daddu    $s0, $zero, $zero
/* A2EE58 80244C18 28420002 */  slti      $v0, $v0, 2
/* A2EE5C 80244C1C 50400001 */  beql      $v0, $zero, .L80244C24
/* A2EE60 80244C20 2410FFF9 */   addiu    $s0, $zero, -7
.L80244C24:
/* A2EE64 80244C24 0000282D */  daddu     $a1, $zero, $zero
/* A2EE68 80244C28 260600C4 */  addiu     $a2, $s0, 0xc4
/* A2EE6C 80244C2C 8E430000 */  lw        $v1, ($s2)
/* A2EE70 80244C30 2402FFFF */  addiu     $v0, $zero, -1
/* A2EE74 80244C34 AFA20010 */  sw        $v0, 0x10($sp)
/* A2EE78 80244C38 AFA00014 */  sw        $zero, 0x14($sp)
/* A2EE7C 80244C3C 8C640000 */  lw        $a0, ($v1)
/* A2EE80 80244C40 0C04993B */  jal       draw_string
/* A2EE84 80244C44 0220382D */   daddu    $a3, $s1, $zero
.L80244C48:
/* A2EE88 80244C48 8FBF0034 */  lw        $ra, 0x34($sp)
/* A2EE8C 80244C4C 8FB20030 */  lw        $s2, 0x30($sp)
/* A2EE90 80244C50 8FB1002C */  lw        $s1, 0x2c($sp)
/* A2EE94 80244C54 8FB00028 */  lw        $s0, 0x28($sp)
/* A2EE98 80244C58 03E00008 */  jr        $ra
/* A2EE9C 80244C5C 27BD0038 */   addiu    $sp, $sp, 0x38
