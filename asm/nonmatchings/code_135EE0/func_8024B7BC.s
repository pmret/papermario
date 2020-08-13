.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024B7BC
/* 13EAFC 8024B7BC AC620008 */  sw    $v0, 8($v1)
/* 13EB00 8024B7C0 00751021 */  addu  $v0, $v1, $s5
/* 13EB04 8024B7C4 AC60000C */  sw    $zero, 0xc($v1)
/* 13EB08 8024B7C8 AE220000 */  sw    $v0, ($s1)
/* 13EB0C 8024B7CC 3C020700 */  lui   $v0, 0x700
/* 13EB10 8024B7D0 AC620014 */  sw    $v0, 0x14($v1)
/* 13EB14 8024B7D4 24620020 */  addiu $v0, $v1, 0x20
/* 13EB18 8024B7D8 3C18E600 */  lui   $t8, 0xe600
/* 13EB1C 8024B7DC AC650010 */  sw    $a1, 0x10($v1)
/* 13EB20 8024B7E0 AE220000 */  sw    $v0, ($s1)
/* 13EB24 8024B7E4 24620028 */  addiu $v0, $v1, 0x28
/* 13EB28 8024B7E8 AC780018 */  sw    $t8, 0x18($v1)
/* 13EB2C 8024B7EC AC60001C */  sw    $zero, 0x1c($v1)
/* 13EB30 8024B7F0 AE220000 */  sw    $v0, ($s1)
/* 13EB34 8024B7F4 3C02F000 */  lui   $v0, 0xf000
/* 13EB38 8024B7F8 AC620020 */  sw    $v0, 0x20($v1)
/* 13EB3C 8024B7FC 24620030 */  addiu $v0, $v1, 0x30
/* 13EB40 8024B800 AC660024 */  sw    $a2, 0x24($v1)
/* 13EB44 8024B804 AE220000 */  sw    $v0, ($s1)
/* 13EB48 8024B808 AC790028 */  sw    $t9, 0x28($v1)
/* 13EB4C 8024B80C AC60002C */  sw    $zero, 0x2c($v1)
/* 13EB50 8024B810 AC640004 */  sw    $a0, 4($v1)
.L8024B814:
/* 13EB54 8024B814 2A62006A */  slti  $v0, $s3, 0x6a
/* 13EB58 8024B818 14400003 */  bnez  $v0, .L8024B828
/* 13EB5C 8024B81C 240E000C */   addiu $t6, $zero, 0xc
/* 13EB60 8024B820 2402006A */  addiu $v0, $zero, 0x6a
/* 13EB64 8024B824 00527023 */  subu  $t6, $v0, $s2
.L8024B828:
/* 13EB68 8024B828 3C02FD48 */  lui   $v0, 0xfd48
/* 13EB6C 8024B82C 34420095 */  ori   $v0, $v0, 0x95
/* 13EB70 8024B830 3C0B0708 */  lui   $t3, 0x708
/* 13EB74 8024B834 356B0200 */  ori   $t3, $t3, 0x200
/* 13EB78 8024B838 3C0A0725 */  lui   $t2, 0x725
/* 13EB7C 8024B83C 354A4000 */  ori   $t2, $t2, 0x4000
/* 13EB80 8024B840 3C0C0008 */  lui   $t4, 8
/* 13EB84 8024B844 358C0200 */  ori   $t4, $t4, 0x200
/* 13EB88 8024B848 8FAF0128 */  lw    $t7, 0x128($sp)
/* 13EB8C 8024B84C 8FB80190 */  lw    $t8, 0x190($sp)
/* 13EB90 8024B850 3C0D0025 */  lui   $t5, 0x25
/* 13EB94 8024B854 AFAC012C */  sw    $t4, 0x12c($sp)
/* 13EB98 8024B858 8FAC0124 */  lw    $t4, 0x124($sp)
/* 13EB9C 8024B85C 35AD4000 */  ori   $t5, $t5, 0x4000
/* 13EBA0 8024B860 AFAD0130 */  sw    $t5, 0x130($sp)
/* 13EBA4 8024B864 8E280000 */  lw    $t0, ($s1)
/* 13EBA8 8024B868 000F2080 */  sll   $a0, $t7, 2
/* 13EBAC 8024B86C 03153821 */  addu  $a3, $t8, $s5
/* 13EBB0 8024B870 00072880 */  sll   $a1, $a3, 2
/* 13EBB4 8024B874 000C3080 */  sll   $a2, $t4, 2
/* 13EBB8 8024B878 00EE3821 */  addu  $a3, $a3, $t6
/* 13EBBC 8024B87C 00073880 */  sll   $a3, $a3, 2
/* 13EBC0 8024B880 0100482D */  daddu $t1, $t0, $zero
/* 13EBC4 8024B884 25080008 */  addiu $t0, $t0, 8
/* 13EBC8 8024B888 AE280000 */  sw    $t0, ($s1)
/* 13EBCC 8024B88C AD220000 */  sw    $v0, ($t1)
/* 13EBD0 8024B890 25020008 */  addiu $v0, $t0, 8
/* 13EBD4 8024B894 AE220000 */  sw    $v0, ($s1)
/* 13EBD8 8024B898 25020010 */  addiu $v0, $t0, 0x10
/* 13EBDC 8024B89C AE220000 */  sw    $v0, ($s1)
/* 13EBE0 8024B8A0 25020018 */  addiu $v0, $t0, 0x18
/* 13EBE4 8024B8A4 AE220000 */  sw    $v0, ($s1)
/* 13EBE8 8024B8A8 25020020 */  addiu $v0, $t0, 0x20
/* 13EBEC 8024B8AC AE220000 */  sw    $v0, ($s1)
/* 13EBF0 8024B8B0 25020028 */  addiu $v0, $t0, 0x28
/* 13EBF4 8024B8B4 AE220000 */  sw    $v0, ($s1)
/* 13EBF8 8024B8B8 8FC30000 */  lw    $v1, ($fp)
/* 13EBFC 8024B8BC 25020030 */  addiu $v0, $t0, 0x30
/* 13EC00 8024B8C0 AE220000 */  sw    $v0, ($s1)
/* 13EC04 8024B8C4 3C02F400 */  lui   $v0, 0xf400
/* 13EC08 8024B8C8 AD230004 */  sw    $v1, 4($t1)
/* 13EC0C 8024B8CC 3C0FE600 */  lui   $t7, 0xe600
/* 13EC10 8024B8D0 32890FFF */  andi  $t1, $s4, 0xfff
/* 13EC14 8024B8D4 01221025 */  or    $v0, $t1, $v0
/* 13EC18 8024B8D8 024E1821 */  addu  $v1, $s2, $t6
/* 13EC1C 8024B8DC 2463FFFF */  addiu $v1, $v1, -1
/* 13EC20 8024B8E0 00031880 */  sll   $v1, $v1, 2
/* 13EC24 8024B8E4 30630FFF */  andi  $v1, $v1, 0xfff
/* 13EC28 8024B8E8 8FAD0110 */  lw    $t5, 0x110($sp)
/* 13EC2C 8024B8EC 006A5025 */  or    $t2, $v1, $t2
/* 13EC30 8024B8F0 AD020010 */  sw    $v0, 0x10($t0)
/* 13EC34 8024B8F4 3C02F200 */  lui   $v0, 0xf200
/* 13EC38 8024B8F8 AD0B0004 */  sw    $t3, 4($t0)
/* 13EC3C 8024B8FC AD0F0008 */  sw    $t7, 8($t0)
/* 13EC40 8024B900 AD00000C */  sw    $zero, 0xc($t0)
/* 13EC44 8024B904 AD0A0014 */  sw    $t2, 0x14($t0)
/* 13EC48 8024B908 AD190018 */  sw    $t9, 0x18($t0)
/* 13EC4C 8024B90C AD00001C */  sw    $zero, 0x1c($t0)
/* 13EC50 8024B910 AD0D0000 */  sw    $t5, ($t0)
/* 13EC54 8024B914 AD0D0020 */  sw    $t5, 0x20($t0)
/* 13EC58 8024B918 8FB8012C */  lw    $t8, 0x12c($sp)
/* 13EC5C 8024B91C 01224825 */  or    $t1, $t1, $v0
/* 13EC60 8024B920 AD180024 */  sw    $t8, 0x24($t0)
/* 13EC64 8024B924 AD090028 */  sw    $t1, 0x28($t0)
/* 13EC68 8024B928 8FAC0130 */  lw    $t4, 0x130($sp)
/* 13EC6C 8024B92C 24020400 */  addiu $v0, $zero, 0x400
/* 13EC70 8024B930 006C1825 */  or    $v1, $v1, $t4
/* 13EC74 8024B934 AD03002C */  sw    $v1, 0x2c($t0)
/* 13EC78 8024B938 AFA00010 */  sw    $zero, 0x10($sp)
/* 13EC7C 8024B93C AFA00014 */  sw    $zero, 0x14($sp)
/* 13EC80 8024B940 AFB60018 */  sw    $s6, 0x18($sp)
/* 13EC84 8024B944 AFA2001C */  sw    $v0, 0x1c($sp)
/* 13EC88 8024B948 AFA20020 */  sw    $v0, 0x20($sp)
/* 13EC8C 8024B94C 0C091216 */  jal   func_80244858
/* 13EC90 8024B950 AFB90120 */   sw    $t9, 0x120($sp)
/* 13EC94 8024B954 8E220000 */  lw    $v0, ($s1)
/* 13EC98 8024B958 0040182D */  daddu $v1, $v0, $zero
/* 13EC9C 8024B95C 24420008 */  addiu $v0, $v0, 8
/* 13ECA0 8024B960 AE220000 */  sw    $v0, ($s1)
/* 13ECA4 8024B964 8FB90120 */  lw    $t9, 0x120($sp)
/* 13ECA8 8024B968 2A620069 */  slti  $v0, $s3, 0x69
/* 13ECAC 8024B96C AC600004 */  sw    $zero, 4($v1)
/* 13ECB0 8024B970 10400009 */  beqz  $v0, .L8024B998
