.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80280954
/* 7E17D4 80280954 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 7E17D8 80280958 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 7E17DC 8028095C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 7E17E0 80280960 AFBF003C */  sw        $ra, 0x3c($sp)
/* 7E17E4 80280964 AFBE0038 */  sw        $fp, 0x38($sp)
/* 7E17E8 80280968 AFB70034 */  sw        $s7, 0x34($sp)
/* 7E17EC 8028096C AFB60030 */  sw        $s6, 0x30($sp)
/* 7E17F0 80280970 AFB5002C */  sw        $s5, 0x2c($sp)
/* 7E17F4 80280974 AFB40028 */  sw        $s4, 0x28($sp)
/* 7E17F8 80280978 AFB30024 */  sw        $s3, 0x24($sp)
/* 7E17FC 8028097C AFB20020 */  sw        $s2, 0x20($sp)
/* 7E1800 80280980 AFB1001C */  sw        $s1, 0x1c($sp)
/* 7E1804 80280984 AFB00018 */  sw        $s0, 0x18($sp)
/* 7E1808 80280988 8C420144 */  lw        $v0, 0x144($v0)
/* 7E180C 8028098C 0080B82D */  daddu     $s7, $a0, $zero
/* 7E1810 80280990 24420028 */  addiu     $v0, $v0, 0x28
/* 7E1814 80280994 12E00006 */  beqz      $s7, .L802809B0
/* 7E1818 80280998 AFA20010 */   sw       $v0, 0x10($sp)
/* 7E181C 8028099C 24020001 */  addiu     $v0, $zero, 1
/* 7E1820 802809A0 12E20006 */  beq       $s7, $v0, .L802809BC
/* 7E1824 802809A4 24150007 */   addiu    $s5, $zero, 7
/* 7E1828 802809A8 080A0271 */  j         .L802809C4
/* 7E182C 802809AC 24140020 */   addiu    $s4, $zero, 0x20
.L802809B0:
/* 7E1830 802809B0 24150005 */  addiu     $s5, $zero, 5
/* 7E1834 802809B4 080A0271 */  j         .L802809C4
/* 7E1838 802809B8 2414000A */   addiu    $s4, $zero, 0xa
.L802809BC:
/* 7E183C 802809BC 24150006 */  addiu     $s5, $zero, 6
/* 7E1840 802809C0 2414000A */  addiu     $s4, $zero, 0xa
.L802809C4:
/* 7E1844 802809C4 0000902D */  daddu     $s2, $zero, $zero
/* 7E1848 802809C8 12800027 */  beqz      $s4, .L80280A68
/* 7E184C 802809CC 0240982D */   daddu    $s3, $s2, $zero
/* 7E1850 802809D0 2AFE0002 */  slti      $fp, $s7, 2
/* 7E1854 802809D4 3C168008 */  lui       $s6, %hi(gItemTable)
/* 7E1858 802809D8 26D678E0 */  addiu     $s6, $s6, %lo(gItemTable)
/* 7E185C 802809DC 3C118011 */  lui       $s1, %hi(gPlayerData)
/* 7E1860 802809E0 2631F290 */  addiu     $s1, $s1, %lo(gPlayerData)
/* 7E1864 802809E4 8FB00010 */  lw        $s0, 0x10($sp)
.L802809E8:
/* 7E1868 802809E8 13C00005 */  beqz      $fp, .L80280A00
/* 7E186C 802809EC 00000000 */   nop
/* 7E1870 802809F0 06E00003 */  bltz      $s7, .L80280A00
/* 7E1874 802809F4 00000000 */   nop
/* 7E1878 802809F8 080A0281 */  j         .L80280A04
/* 7E187C 802809FC 862401B4 */   lh       $a0, 0x1b4($s1)
.L80280A00:
/* 7E1880 80280A00 862401C8 */  lh        $a0, 0x1c8($s1)
.L80280A04:
/* 7E1884 80280A04 10800014 */  beqz      $a0, .L80280A58
/* 7E1888 80280A08 00041140 */   sll      $v0, $a0, 5
/* 7E188C 80280A0C 00561821 */  addu      $v1, $v0, $s6
/* 7E1890 80280A10 84620004 */  lh        $v0, 4($v1)
/* 7E1894 80280A14 3C058009 */  lui       $a1, %hi(D_8008A680)
/* 7E1898 80280A18 24A5A680 */  addiu     $a1, $a1, %lo(D_8008A680)
/* 7E189C 80280A1C 000210C0 */  sll       $v0, $v0, 3
/* 7E18A0 80280A20 00451021 */  addu      $v0, $v0, $a1
/* 7E18A4 80280A24 8C420000 */  lw        $v0, ($v0)
/* 7E18A8 80280A28 24050001 */  addiu     $a1, $zero, 1
/* 7E18AC 80280A2C AE120108 */  sw        $s2, 0x108($s0)
/* 7E18B0 80280A30 AE05018C */  sw        $a1, 0x18c($s0)
/* 7E18B4 80280A34 AE020000 */  sw        $v0, ($s0)
/* 7E18B8 80280A38 8C620000 */  lw        $v0, ($v1)
/* 7E18BC 80280A3C AE020084 */  sw        $v0, 0x84($s0)
/* 7E18C0 80280A40 8C620014 */  lw        $v0, 0x14($v1)
/* 7E18C4 80280A44 02659821 */  addu      $s3, $s3, $a1
/* 7E18C8 80280A48 0C0A02DE */  jal       func_80280B78
/* 7E18CC 80280A4C AE020294 */   sw       $v0, 0x294($s0)
/* 7E18D0 80280A50 AE020210 */  sw        $v0, 0x210($s0)
/* 7E18D4 80280A54 26100004 */  addiu     $s0, $s0, 4
.L80280A58:
/* 7E18D8 80280A58 26520001 */  addiu     $s2, $s2, 1
/* 7E18DC 80280A5C 0254102A */  slt       $v0, $s2, $s4
/* 7E18E0 80280A60 1440FFE1 */  bnez      $v0, .L802809E8
/* 7E18E4 80280A64 26310002 */   addiu    $s1, $s1, 2
.L80280A68:
/* 7E18E8 80280A68 8FA40010 */  lw        $a0, 0x10($sp)
/* 7E18EC 80280A6C AC950318 */  sw        $s5, 0x318($a0)
/* 7E18F0 80280A70 AC930324 */  sw        $s3, 0x324($a0)
/* 7E18F4 80280A74 0C03D3F1 */  jal       func_800F4FC4
/* 7E18F8 80280A78 AC800328 */   sw       $zero, 0x328($a0)
/* 7E18FC 80280A7C 0C03A625 */  jal       func_800E9894
/* 7E1900 80280A80 00000000 */   nop
/* 7E1904 80280A84 0C03A63B */  jal       func_800E98EC
/* 7E1908 80280A88 00000000 */   nop
/* 7E190C 80280A8C 0C03A5E3 */  jal       open_status_menu_short
/* 7E1910 80280A90 00000000 */   nop
/* 7E1914 80280A94 8FBF003C */  lw        $ra, 0x3c($sp)
/* 7E1918 80280A98 8FBE0038 */  lw        $fp, 0x38($sp)
/* 7E191C 80280A9C 8FB70034 */  lw        $s7, 0x34($sp)
/* 7E1920 80280AA0 8FB60030 */  lw        $s6, 0x30($sp)
/* 7E1924 80280AA4 8FB5002C */  lw        $s5, 0x2c($sp)
/* 7E1928 80280AA8 8FB40028 */  lw        $s4, 0x28($sp)
/* 7E192C 80280AAC 8FB30024 */  lw        $s3, 0x24($sp)
/* 7E1930 80280AB0 8FB20020 */  lw        $s2, 0x20($sp)
/* 7E1934 80280AB4 8FB1001C */  lw        $s1, 0x1c($sp)
/* 7E1938 80280AB8 8FB00018 */  lw        $s0, 0x18($sp)
/* 7E193C 80280ABC 03E00008 */  jr        $ra
/* 7E1940 80280AC0 27BD0040 */   addiu    $sp, $sp, 0x40
