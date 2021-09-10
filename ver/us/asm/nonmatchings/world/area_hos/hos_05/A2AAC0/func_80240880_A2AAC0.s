.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240880_A2AAC0
/* A2AAC0 80240880 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A2AAC4 80240884 AFB1002C */  sw        $s1, 0x2c($sp)
/* A2AAC8 80240888 0080882D */  daddu     $s1, $a0, $zero
/* A2AACC 8024088C AFBF004C */  sw        $ra, 0x4c($sp)
/* A2AAD0 80240890 AFBE0048 */  sw        $fp, 0x48($sp)
/* A2AAD4 80240894 AFB70044 */  sw        $s7, 0x44($sp)
/* A2AAD8 80240898 AFB60040 */  sw        $s6, 0x40($sp)
/* A2AADC 8024089C AFB5003C */  sw        $s5, 0x3c($sp)
/* A2AAE0 802408A0 AFB40038 */  sw        $s4, 0x38($sp)
/* A2AAE4 802408A4 AFB30034 */  sw        $s3, 0x34($sp)
/* A2AAE8 802408A8 AFB20030 */  sw        $s2, 0x30($sp)
/* A2AAEC 802408AC AFB00028 */  sw        $s0, 0x28($sp)
/* A2AAF0 802408B0 8E30000C */  lw        $s0, 0xc($s1)
/* A2AAF4 802408B4 8E050000 */  lw        $a1, ($s0)
/* A2AAF8 802408B8 0C0B1EAF */  jal       evt_get_variable
/* A2AAFC 802408BC 26100004 */   addiu    $s0, $s0, 4
/* A2AB00 802408C0 8E050000 */  lw        $a1, ($s0)
/* A2AB04 802408C4 26100004 */  addiu     $s0, $s0, 4
/* A2AB08 802408C8 0220202D */  daddu     $a0, $s1, $zero
/* A2AB0C 802408CC 0C0B1EAF */  jal       evt_get_variable
/* A2AB10 802408D0 0040F02D */   daddu    $fp, $v0, $zero
/* A2AB14 802408D4 8E050000 */  lw        $a1, ($s0)
/* A2AB18 802408D8 26100004 */  addiu     $s0, $s0, 4
/* A2AB1C 802408DC 0220202D */  daddu     $a0, $s1, $zero
/* A2AB20 802408E0 0C0B1EAF */  jal       evt_get_variable
/* A2AB24 802408E4 0040B02D */   daddu    $s6, $v0, $zero
/* A2AB28 802408E8 8E050000 */  lw        $a1, ($s0)
/* A2AB2C 802408EC 26100004 */  addiu     $s0, $s0, 4
/* A2AB30 802408F0 0220202D */  daddu     $a0, $s1, $zero
/* A2AB34 802408F4 0C0B1EAF */  jal       evt_get_variable
/* A2AB38 802408F8 0040B82D */   daddu    $s7, $v0, $zero
/* A2AB3C 802408FC 8E050000 */  lw        $a1, ($s0)
/* A2AB40 80240900 26100004 */  addiu     $s0, $s0, 4
/* A2AB44 80240904 0220202D */  daddu     $a0, $s1, $zero
/* A2AB48 80240908 0C0B1EAF */  jal       evt_get_variable
/* A2AB4C 8024090C 0040A82D */   daddu    $s5, $v0, $zero
/* A2AB50 80240910 8E050000 */  lw        $a1, ($s0)
/* A2AB54 80240914 26100004 */  addiu     $s0, $s0, 4
/* A2AB58 80240918 0220202D */  daddu     $a0, $s1, $zero
/* A2AB5C 8024091C 0C0B1EAF */  jal       evt_get_variable
/* A2AB60 80240920 0040A02D */   daddu    $s4, $v0, $zero
/* A2AB64 80240924 8E050000 */  lw        $a1, ($s0)
/* A2AB68 80240928 26100004 */  addiu     $s0, $s0, 4
/* A2AB6C 8024092C 0220202D */  daddu     $a0, $s1, $zero
/* A2AB70 80240930 0C0B1EAF */  jal       evt_get_variable
/* A2AB74 80240934 0040982D */   daddu    $s3, $v0, $zero
/* A2AB78 80240938 8E050000 */  lw        $a1, ($s0)
/* A2AB7C 8024093C 26100004 */  addiu     $s0, $s0, 4
/* A2AB80 80240940 0220202D */  daddu     $a0, $s1, $zero
/* A2AB84 80240944 0C0B1EAF */  jal       evt_get_variable
/* A2AB88 80240948 0040902D */   daddu    $s2, $v0, $zero
/* A2AB8C 8024094C 0220202D */  daddu     $a0, $s1, $zero
/* A2AB90 80240950 8E050000 */  lw        $a1, ($s0)
/* A2AB94 80240954 0C0B1EAF */  jal       evt_get_variable
/* A2AB98 80240958 0040802D */   daddu    $s0, $v0, $zero
/* A2AB9C 8024095C 33C400FF */  andi      $a0, $fp, 0xff
/* A2ABA0 80240960 32C500FF */  andi      $a1, $s6, 0xff
/* A2ABA4 80240964 329400FF */  andi      $s4, $s4, 0xff
/* A2ABA8 80240968 327300FF */  andi      $s3, $s3, 0xff
/* A2ABAC 8024096C 325200FF */  andi      $s2, $s2, 0xff
/* A2ABB0 80240970 32E600FF */  andi      $a2, $s7, 0xff
/* A2ABB4 80240974 32A700FF */  andi      $a3, $s5, 0xff
/* A2ABB8 80240978 AFB40010 */  sw        $s4, 0x10($sp)
/* A2ABBC 8024097C AFB30014 */  sw        $s3, 0x14($sp)
/* A2ABC0 80240980 AFB20018 */  sw        $s2, 0x18($sp)
/* A2ABC4 80240984 AFB0001C */  sw        $s0, 0x1c($sp)
/* A2ABC8 80240988 0C046FAD */  jal       set_model_fog_color_parameters
/* A2ABCC 8024098C AFA20020 */   sw       $v0, 0x20($sp)
/* A2ABD0 80240990 8FBF004C */  lw        $ra, 0x4c($sp)
/* A2ABD4 80240994 8FBE0048 */  lw        $fp, 0x48($sp)
/* A2ABD8 80240998 8FB70044 */  lw        $s7, 0x44($sp)
/* A2ABDC 8024099C 8FB60040 */  lw        $s6, 0x40($sp)
/* A2ABE0 802409A0 8FB5003C */  lw        $s5, 0x3c($sp)
/* A2ABE4 802409A4 8FB40038 */  lw        $s4, 0x38($sp)
/* A2ABE8 802409A8 8FB30034 */  lw        $s3, 0x34($sp)
/* A2ABEC 802409AC 8FB20030 */  lw        $s2, 0x30($sp)
/* A2ABF0 802409B0 8FB1002C */  lw        $s1, 0x2c($sp)
/* A2ABF4 802409B4 8FB00028 */  lw        $s0, 0x28($sp)
/* A2ABF8 802409B8 24020002 */  addiu     $v0, $zero, 2
/* A2ABFC 802409BC 03E00008 */  jr        $ra
/* A2AC00 802409C0 27BD0050 */   addiu    $sp, $sp, 0x50
