.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417E0_8D2CF0
/* 8D2CF0 802417E0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 8D2CF4 802417E4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 8D2CF8 802417E8 0080982D */  daddu     $s3, $a0, $zero
/* 8D2CFC 802417EC AFBF0028 */  sw        $ra, 0x28($sp)
/* 8D2D00 802417F0 AFB50024 */  sw        $s5, 0x24($sp)
/* 8D2D04 802417F4 AFB40020 */  sw        $s4, 0x20($sp)
/* 8D2D08 802417F8 AFB20018 */  sw        $s2, 0x18($sp)
/* 8D2D0C 802417FC AFB10014 */  sw        $s1, 0x14($sp)
/* 8D2D10 80241800 AFB00010 */  sw        $s0, 0x10($sp)
/* 8D2D14 80241804 8E62000C */  lw        $v0, 0xc($s3)
/* 8D2D18 80241808 0C0B1EAF */  jal       get_variable
/* 8D2D1C 8024180C 8C450000 */   lw       $a1, ($v0)
/* 8D2D20 80241810 24040048 */  addiu     $a0, $zero, 0x48
/* 8D2D24 80241814 0C00AB39 */  jal       heap_malloc
/* 8D2D28 80241818 0040902D */   daddu    $s2, $v0, $zero
/* 8D2D2C 8024181C 24040200 */  addiu     $a0, $zero, 0x200
/* 8D2D30 80241820 0C00AB39 */  jal       heap_malloc
/* 8D2D34 80241824 0040802D */   daddu    $s0, $v0, $zero
/* 8D2D38 80241828 24040020 */  addiu     $a0, $zero, 0x20
/* 8D2D3C 8024182C 0C00AB39 */  jal       heap_malloc
/* 8D2D40 80241830 0040A82D */   daddu    $s5, $v0, $zero
/* 8D2D44 80241834 02A0302D */  daddu     $a2, $s5, $zero
/* 8D2D48 80241838 00129080 */  sll       $s2, $s2, 2
/* 8D2D4C 8024183C 3C11001D */  lui       $s1, 0x1d
/* 8D2D50 80241840 2631C310 */  addiu     $s1, $s1, -0x3cf0
/* 8D2D54 80241844 3C013F80 */  lui       $at, 0x3f80
/* 8D2D58 80241848 44810000 */  mtc1      $at, $f0
/* 8D2D5C 8024184C 26250200 */  addiu     $a1, $s1, 0x200
/* 8D2D60 80241850 AE000008 */  sw        $zero, 8($s0)
/* 8D2D64 80241854 AE00000C */  sw        $zero, 0xc($s0)
/* 8D2D68 80241858 AE000010 */  sw        $zero, 0x10($s0)
/* 8D2D6C 8024185C AE000014 */  sw        $zero, 0x14($s0)
/* 8D2D70 80241860 AE000018 */  sw        $zero, 0x18($s0)
/* 8D2D74 80241864 AE000028 */  sw        $zero, 0x28($s0)
/* 8D2D78 80241868 AE00002C */  sw        $zero, 0x2c($s0)
/* 8D2D7C 8024186C AE000030 */  sw        $zero, 0x30($s0)
/* 8D2D80 80241870 AE000034 */  sw        $zero, 0x34($s0)
/* 8D2D84 80241874 AE000038 */  sw        $zero, 0x38($s0)
/* 8D2D88 80241878 AE00003C */  sw        $zero, 0x3c($s0)
/* 8D2D8C 8024187C AE000040 */  sw        $zero, 0x40($s0)
/* 8D2D90 80241880 AE000044 */  sw        $zero, 0x44($s0)
/* 8D2D94 80241884 E600001C */  swc1      $f0, 0x1c($s0)
/* 8D2D98 80241888 E6000020 */  swc1      $f0, 0x20($s0)
/* 8D2D9C 8024188C E6000024 */  swc1      $f0, 0x24($s0)
/* 8D2DA0 80241890 3C038009 */  lui       $v1, %hi(D_8008E3D8)
/* 8D2DA4 80241894 00721821 */  addu      $v1, $v1, $s2
/* 8D2DA8 80241898 8C63E3D8 */  lw        $v1, %lo(D_8008E3D8)($v1)
/* 8D2DAC 8024189C 0040A02D */  daddu     $s4, $v0, $zero
/* 8D2DB0 802418A0 00712021 */  addu      $a0, $v1, $s1
/* 8D2DB4 802418A4 0C00A5CF */  jal       dma_copy
/* 8D2DB8 802418A8 00652821 */   addu     $a1, $v1, $a1
/* 8D2DBC 802418AC 3C058009 */  lui       $a1, %hi(D_8008E94C)
/* 8D2DC0 802418B0 00B22821 */  addu      $a1, $a1, $s2
/* 8D2DC4 802418B4 8CA5E94C */  lw        $a1, %lo(D_8008E94C)($a1)
/* 8D2DC8 802418B8 0280302D */  daddu     $a2, $s4, $zero
/* 8D2DCC 802418BC 00B12021 */  addu      $a0, $a1, $s1
/* 8D2DD0 802418C0 26310020 */  addiu     $s1, $s1, 0x20
/* 8D2DD4 802418C4 0C00A5CF */  jal       dma_copy
/* 8D2DD8 802418C8 00B12821 */   addu     $a1, $a1, $s1
/* 8D2DDC 802418CC 0C04E9C1 */  jal       func_8013A704
/* 8D2DE0 802418D0 24040001 */   addiu    $a0, $zero, 1
/* 8D2DE4 802418D4 0000202D */  daddu     $a0, $zero, $zero
/* 8D2DE8 802418D8 3C058024 */  lui       $a1, %hi(func_802417A8_8D2CB8)
/* 8D2DEC 802418DC 24A517A8 */  addiu     $a1, $a1, %lo(func_802417A8_8D2CB8)
/* 8D2DF0 802418E0 0C048C56 */  jal       create_generic_entity_world
/* 8D2DF4 802418E4 AE020000 */   sw       $v0, ($s0)
/* 8D2DF8 802418E8 0260202D */  daddu     $a0, $s3, $zero
/* 8D2DFC 802418EC 3C05FD05 */  lui       $a1, 0xfd05
/* 8D2E00 802418F0 34A50F8A */  ori       $a1, $a1, 0xf8a
/* 8D2E04 802418F4 0200302D */  daddu     $a2, $s0, $zero
/* 8D2E08 802418F8 0C0B2026 */  jal       set_variable
/* 8D2E0C 802418FC ACC20004 */   sw       $v0, 4($a2)
/* 8D2E10 80241900 0260202D */  daddu     $a0, $s3, $zero
/* 8D2E14 80241904 3C05FD05 */  lui       $a1, 0xfd05
/* 8D2E18 80241908 34A50F8B */  ori       $a1, $a1, 0xf8b
/* 8D2E1C 8024190C 0C0B2026 */  jal       set_variable
/* 8D2E20 80241910 02A0302D */   daddu    $a2, $s5, $zero
/* 8D2E24 80241914 0260202D */  daddu     $a0, $s3, $zero
/* 8D2E28 80241918 3C05FD05 */  lui       $a1, 0xfd05
/* 8D2E2C 8024191C 34A50F8C */  ori       $a1, $a1, 0xf8c
/* 8D2E30 80241920 0C0B2026 */  jal       set_variable
/* 8D2E34 80241924 0280302D */   daddu    $a2, $s4, $zero
/* 8D2E38 80241928 8FBF0028 */  lw        $ra, 0x28($sp)
/* 8D2E3C 8024192C 8FB50024 */  lw        $s5, 0x24($sp)
/* 8D2E40 80241930 8FB40020 */  lw        $s4, 0x20($sp)
/* 8D2E44 80241934 8FB3001C */  lw        $s3, 0x1c($sp)
/* 8D2E48 80241938 8FB20018 */  lw        $s2, 0x18($sp)
/* 8D2E4C 8024193C 8FB10014 */  lw        $s1, 0x14($sp)
/* 8D2E50 80241940 8FB00010 */  lw        $s0, 0x10($sp)
/* 8D2E54 80241944 24020002 */  addiu     $v0, $zero, 2
/* 8D2E58 80241948 03E00008 */  jr        $ra
/* 8D2E5C 8024194C 27BD0030 */   addiu    $sp, $sp, 0x30
