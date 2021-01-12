.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011E718
/* B4E18 8011E718 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B4E1C 8011E71C AFB20018 */  sw        $s2, 0x18($sp)
/* B4E20 8011E720 0080902D */  daddu     $s2, $a0, $zero
/* B4E24 8011E724 AFB3001C */  sw        $s3, 0x1c($sp)
/* B4E28 8011E728 00A0982D */  daddu     $s3, $a1, $zero
/* B4E2C 8011E72C AFB10014 */  sw        $s1, 0x14($sp)
/* B4E30 8011E730 00C0882D */  daddu     $s1, $a2, $zero
/* B4E34 8011E734 24040100 */  addiu     $a0, $zero, 0x100
/* B4E38 8011E738 AFBF0020 */  sw        $ra, 0x20($sp)
/* B4E3C 8011E73C 0C00AB39 */  jal       heap_malloc
/* B4E40 8011E740 AFB00010 */   sw       $s0, 0x10($sp)
/* B4E44 8011E744 0040802D */  daddu     $s0, $v0, $zero
/* B4E48 8011E748 16000003 */  bnez      $s0, .L8011E758
/* B4E4C 8011E74C 24020010 */   addiu    $v0, $zero, 0x10
.L8011E750:
/* B4E50 8011E750 080479D4 */  j         .L8011E750
/* B4E54 8011E754 00000000 */   nop
.L8011E758:
/* B4E58 8011E758 A60200F4 */  sh        $v0, 0xf4($s0)
/* B4E5C 8011E75C 8E220000 */  lw        $v0, ($s1)
/* B4E60 8011E760 AE020000 */  sw        $v0, ($s0)
/* B4E64 8011E764 C6200004 */  lwc1      $f0, 4($s1)
/* B4E68 8011E768 E6000084 */  swc1      $f0, 0x84($s0)
/* B4E6C 8011E76C C6200008 */  lwc1      $f0, 8($s1)
/* B4E70 8011E770 E6000088 */  swc1      $f0, 0x88($s0)
/* B4E74 8011E774 C620000C */  lwc1      $f0, 0xc($s1)
/* B4E78 8011E778 AE000090 */  sw        $zero, 0x90($s0)
/* B4E7C 8011E77C AE000094 */  sw        $zero, 0x94($s0)
/* B4E80 8011E780 AE000098 */  sw        $zero, 0x98($s0)
/* B4E84 8011E784 E600008C */  swc1      $f0, 0x8c($s0)
/* B4E88 8011E788 C6200010 */  lwc1      $f0, 0x10($s1)
/* B4E8C 8011E78C 2404001F */  addiu     $a0, $zero, 0x1f
/* B4E90 8011E790 E600009C */  swc1      $f0, 0x9c($s0)
/* B4E94 8011E794 C6200014 */  lwc1      $f0, 0x14($s1)
/* B4E98 8011E798 2603007C */  addiu     $v1, $s0, 0x7c
/* B4E9C 8011E79C E60000A0 */  swc1      $f0, 0xa0($s0)
/* B4EA0 8011E7A0 C6220018 */  lwc1      $f2, 0x18($s1)
/* B4EA4 8011E7A4 3C013F80 */  lui       $at, 0x3f80
/* B4EA8 8011E7A8 44810000 */  mtc1      $at, $f0
/* B4EAC 8011E7AC 2402FFFF */  addiu     $v0, $zero, -1
/* B4EB0 8011E7B0 A60200F8 */  sh        $v0, 0xf8($s0)
/* B4EB4 8011E7B4 E60000A8 */  swc1      $f0, 0xa8($s0)
/* B4EB8 8011E7B8 E60000AC */  swc1      $f0, 0xac($s0)
/* B4EBC 8011E7BC E60000B0 */  swc1      $f0, 0xb0($s0)
/* B4EC0 8011E7C0 E60200A4 */  swc1      $f2, 0xa4($s0)
.L8011E7C4:
/* B4EC4 8011E7C4 AC600004 */  sw        $zero, 4($v1)
/* B4EC8 8011E7C8 2484FFFF */  addiu     $a0, $a0, -1
/* B4ECC 8011E7CC 0481FFFD */  bgez      $a0, .L8011E7C4
/* B4ED0 8011E7D0 2463FFFC */   addiu    $v1, $v1, -4
/* B4ED4 8011E7D4 92510014 */  lbu       $s1, 0x14($s2)
/* B4ED8 8011E7D8 1660001A */  bnez      $s3, .L8011E844
/* B4EDC 8011E7DC 26310001 */   addiu    $s1, $s1, 1
/* B4EE0 8011E7E0 8E420010 */  lw        $v0, 0x10($s2)
/* B4EE4 8011E7E4 14400003 */  bnez      $v0, .L8011E7F4
/* B4EE8 8011E7E8 A61100F6 */   sh       $s1, 0xf6($s0)
/* B4EEC 8011E7EC 08047A26 */  j         .L8011E898
/* B4EF0 8011E7F0 AE500010 */   sw       $s0, 0x10($s2)
.L8011E7F4:
/* B4EF4 8011E7F4 8E440010 */  lw        $a0, 0x10($s2)
/* B4EF8 8011E7F8 0C047837 */  jal       func_8011E0DC
/* B4EFC 8011E7FC 24050001 */   addiu    $a1, $zero, 1
/* B4F00 8011E800 14400003 */  bnez      $v0, .L8011E810
/* B4F04 8011E804 0000202D */   daddu    $a0, $zero, $zero
.L8011E808:
/* B4F08 8011E808 08047A02 */  j         .L8011E808
/* B4F0C 8011E80C 00000000 */   nop
.L8011E810:
/* B4F10 8011E810 0040182D */  daddu     $v1, $v0, $zero
.L8011E814:
/* B4F14 8011E814 8C620004 */  lw        $v0, 4($v1)
/* B4F18 8011E818 50400005 */  beql      $v0, $zero, .L8011E830
/* B4F1C 8011E81C AC700004 */   sw       $s0, 4($v1)
/* B4F20 8011E820 24840001 */  addiu     $a0, $a0, 1
/* B4F24 8011E824 28820020 */  slti      $v0, $a0, 0x20
/* B4F28 8011E828 1440FFFA */  bnez      $v0, .L8011E814
/* B4F2C 8011E82C 24630004 */   addiu    $v1, $v1, 4
.L8011E830:
/* B4F30 8011E830 28820020 */  slti      $v0, $a0, 0x20
/* B4F34 8011E834 14400019 */  bnez      $v0, .L8011E89C
/* B4F38 8011E838 0200102D */   daddu    $v0, $s0, $zero
.L8011E83C:
/* B4F3C 8011E83C 08047A0F */  j         .L8011E83C
/* B4F40 8011E840 00000000 */   nop
.L8011E844:
/* B4F44 8011E844 A61100F6 */  sh        $s1, 0xf6($s0)
/* B4F48 8011E848 8E440010 */  lw        $a0, 0x10($s2)
/* B4F4C 8011E84C 0C047837 */  jal       func_8011E0DC
/* B4F50 8011E850 0260282D */   daddu    $a1, $s3, $zero
/* B4F54 8011E854 14400003 */  bnez      $v0, .L8011E864
/* B4F58 8011E858 0000202D */   daddu    $a0, $zero, $zero
.L8011E85C:
/* B4F5C 8011E85C 08047A17 */  j         .L8011E85C
/* B4F60 8011E860 00000000 */   nop
.L8011E864:
/* B4F64 8011E864 0040182D */  daddu     $v1, $v0, $zero
.L8011E868:
/* B4F68 8011E868 8C620004 */  lw        $v0, 4($v1)
/* B4F6C 8011E86C 50400005 */  beql      $v0, $zero, .L8011E884
/* B4F70 8011E870 AC700004 */   sw       $s0, 4($v1)
/* B4F74 8011E874 24840001 */  addiu     $a0, $a0, 1
/* B4F78 8011E878 28820020 */  slti      $v0, $a0, 0x20
/* B4F7C 8011E87C 1440FFFA */  bnez      $v0, .L8011E868
/* B4F80 8011E880 24630004 */   addiu    $v1, $v1, 4
.L8011E884:
/* B4F84 8011E884 28820020 */  slti      $v0, $a0, 0x20
/* B4F88 8011E888 14400004 */  bnez      $v0, .L8011E89C
/* B4F8C 8011E88C 0200102D */   daddu    $v0, $s0, $zero
.L8011E890:
/* B4F90 8011E890 08047A24 */  j         .L8011E890
/* B4F94 8011E894 00000000 */   nop
.L8011E898:
/* B4F98 8011E898 0200102D */  daddu     $v0, $s0, $zero
.L8011E89C:
/* B4F9C 8011E89C A2510014 */  sb        $s1, 0x14($s2)
/* B4FA0 8011E8A0 8FBF0020 */  lw        $ra, 0x20($sp)
/* B4FA4 8011E8A4 8FB3001C */  lw        $s3, 0x1c($sp)
/* B4FA8 8011E8A8 8FB20018 */  lw        $s2, 0x18($sp)
/* B4FAC 8011E8AC 8FB10014 */  lw        $s1, 0x14($sp)
/* B4FB0 8011E8B0 8FB00010 */  lw        $s0, 0x10($sp)
/* B4FB4 8011E8B4 03E00008 */  jr        $ra
/* B4FB8 8011E8B8 27BD0028 */   addiu    $sp, $sp, 0x28
