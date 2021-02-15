.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240050_842C20
/* 842C20 80240050 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 842C24 80240054 AFB1002C */  sw        $s1, 0x2c($sp)
/* 842C28 80240058 0080882D */  daddu     $s1, $a0, $zero
/* 842C2C 8024005C AFBF004C */  sw        $ra, 0x4c($sp)
/* 842C30 80240060 AFBE0048 */  sw        $fp, 0x48($sp)
/* 842C34 80240064 AFB70044 */  sw        $s7, 0x44($sp)
/* 842C38 80240068 AFB60040 */  sw        $s6, 0x40($sp)
/* 842C3C 8024006C AFB5003C */  sw        $s5, 0x3c($sp)
/* 842C40 80240070 AFB40038 */  sw        $s4, 0x38($sp)
/* 842C44 80240074 AFB30034 */  sw        $s3, 0x34($sp)
/* 842C48 80240078 AFB20030 */  sw        $s2, 0x30($sp)
/* 842C4C 8024007C AFB00028 */  sw        $s0, 0x28($sp)
/* 842C50 80240080 8E30000C */  lw        $s0, 0xc($s1)
/* 842C54 80240084 8E050000 */  lw        $a1, ($s0)
/* 842C58 80240088 0C0B1EAF */  jal       get_variable
/* 842C5C 8024008C 26100004 */   addiu    $s0, $s0, 4
/* 842C60 80240090 8E050000 */  lw        $a1, ($s0)
/* 842C64 80240094 26100004 */  addiu     $s0, $s0, 4
/* 842C68 80240098 0220202D */  daddu     $a0, $s1, $zero
/* 842C6C 8024009C 0C0B1EAF */  jal       get_variable
/* 842C70 802400A0 0040F02D */   daddu    $fp, $v0, $zero
/* 842C74 802400A4 8E050000 */  lw        $a1, ($s0)
/* 842C78 802400A8 26100004 */  addiu     $s0, $s0, 4
/* 842C7C 802400AC 0220202D */  daddu     $a0, $s1, $zero
/* 842C80 802400B0 0C0B1EAF */  jal       get_variable
/* 842C84 802400B4 0040B02D */   daddu    $s6, $v0, $zero
/* 842C88 802400B8 8E050000 */  lw        $a1, ($s0)
/* 842C8C 802400BC 26100004 */  addiu     $s0, $s0, 4
/* 842C90 802400C0 0220202D */  daddu     $a0, $s1, $zero
/* 842C94 802400C4 0C0B1EAF */  jal       get_variable
/* 842C98 802400C8 0040B82D */   daddu    $s7, $v0, $zero
/* 842C9C 802400CC 8E050000 */  lw        $a1, ($s0)
/* 842CA0 802400D0 26100004 */  addiu     $s0, $s0, 4
/* 842CA4 802400D4 0220202D */  daddu     $a0, $s1, $zero
/* 842CA8 802400D8 0C0B1EAF */  jal       get_variable
/* 842CAC 802400DC 0040A82D */   daddu    $s5, $v0, $zero
/* 842CB0 802400E0 8E050000 */  lw        $a1, ($s0)
/* 842CB4 802400E4 26100004 */  addiu     $s0, $s0, 4
/* 842CB8 802400E8 0220202D */  daddu     $a0, $s1, $zero
/* 842CBC 802400EC 0C0B1EAF */  jal       get_variable
/* 842CC0 802400F0 0040A02D */   daddu    $s4, $v0, $zero
/* 842CC4 802400F4 8E050000 */  lw        $a1, ($s0)
/* 842CC8 802400F8 26100004 */  addiu     $s0, $s0, 4
/* 842CCC 802400FC 0220202D */  daddu     $a0, $s1, $zero
/* 842CD0 80240100 0C0B1EAF */  jal       get_variable
/* 842CD4 80240104 0040982D */   daddu    $s3, $v0, $zero
/* 842CD8 80240108 8E050000 */  lw        $a1, ($s0)
/* 842CDC 8024010C 26100004 */  addiu     $s0, $s0, 4
/* 842CE0 80240110 0220202D */  daddu     $a0, $s1, $zero
/* 842CE4 80240114 0C0B1EAF */  jal       get_variable
/* 842CE8 80240118 0040902D */   daddu    $s2, $v0, $zero
/* 842CEC 8024011C 0220202D */  daddu     $a0, $s1, $zero
/* 842CF0 80240120 8E050000 */  lw        $a1, ($s0)
/* 842CF4 80240124 0C0B1EAF */  jal       get_variable
/* 842CF8 80240128 0040802D */   daddu    $s0, $v0, $zero
/* 842CFC 8024012C 33C400FF */  andi      $a0, $fp, 0xff
/* 842D00 80240130 32C500FF */  andi      $a1, $s6, 0xff
/* 842D04 80240134 329400FF */  andi      $s4, $s4, 0xff
/* 842D08 80240138 327300FF */  andi      $s3, $s3, 0xff
/* 842D0C 8024013C 325200FF */  andi      $s2, $s2, 0xff
/* 842D10 80240140 32E600FF */  andi      $a2, $s7, 0xff
/* 842D14 80240144 32A700FF */  andi      $a3, $s5, 0xff
/* 842D18 80240148 AFB40010 */  sw        $s4, 0x10($sp)
/* 842D1C 8024014C AFB30014 */  sw        $s3, 0x14($sp)
/* 842D20 80240150 AFB20018 */  sw        $s2, 0x18($sp)
/* 842D24 80240154 AFB0001C */  sw        $s0, 0x1c($sp)
/* 842D28 80240158 0C046FAD */  jal       func_8011BEB4
/* 842D2C 8024015C AFA20020 */   sw       $v0, 0x20($sp)
/* 842D30 80240160 8FBF004C */  lw        $ra, 0x4c($sp)
/* 842D34 80240164 8FBE0048 */  lw        $fp, 0x48($sp)
/* 842D38 80240168 8FB70044 */  lw        $s7, 0x44($sp)
/* 842D3C 8024016C 8FB60040 */  lw        $s6, 0x40($sp)
/* 842D40 80240170 8FB5003C */  lw        $s5, 0x3c($sp)
/* 842D44 80240174 8FB40038 */  lw        $s4, 0x38($sp)
/* 842D48 80240178 8FB30034 */  lw        $s3, 0x34($sp)
/* 842D4C 8024017C 8FB20030 */  lw        $s2, 0x30($sp)
/* 842D50 80240180 8FB1002C */  lw        $s1, 0x2c($sp)
/* 842D54 80240184 8FB00028 */  lw        $s0, 0x28($sp)
/* 842D58 80240188 24020002 */  addiu     $v0, $zero, 2
/* 842D5C 8024018C 03E00008 */  jr        $ra
/* 842D60 80240190 27BD0050 */   addiu    $sp, $sp, 0x50
