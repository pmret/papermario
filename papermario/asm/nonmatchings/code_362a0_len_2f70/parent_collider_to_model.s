.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel parent_collider_to_model
/* 036B80 8005B780 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 036B84 8005B784 00042400 */  sll   $a0, $a0, 0x10
/* 036B88 8005B788 00042403 */  sra   $a0, $a0, 0x10
/* 036B8C 8005B78C 000410C0 */  sll   $v0, $a0, 3
/* 036B90 8005B790 00441023 */  subu  $v0, $v0, $a0
/* 036B94 8005B794 3C03800B */  lui   $v1, 0x800b
/* 036B98 8005B798 8C6342E4 */  lw    $v1, 0x42e4($v1)
/* 036B9C 8005B79C 00021080 */  sll   $v0, $v0, 2
/* 036BA0 8005B7A0 AFB30024 */  sw    $s3, 0x24($sp)
/* 036BA4 8005B7A4 0000982D */  daddu $s3, $zero, $zero
/* 036BA8 8005B7A8 AFBF0034 */  sw    $ra, 0x34($sp)
/* 036BAC 8005B7AC AFB60030 */  sw    $s6, 0x30($sp)
/* 036BB0 8005B7B0 AFB5002C */  sw    $s5, 0x2c($sp)
/* 036BB4 8005B7B4 AFB40028 */  sw    $s4, 0x28($sp)
/* 036BB8 8005B7B8 AFB20020 */  sw    $s2, 0x20($sp)
/* 036BBC 8005B7BC AFB1001C */  sw    $s1, 0x1c($sp)
/* 036BC0 8005B7C0 AFB00018 */  sw    $s0, 0x18($sp)
/* 036BC4 8005B7C4 0062A021 */  addu  $s4, $v1, $v0
/* 036BC8 8005B7C8 8682000A */  lh    $v0, 0xa($s4)
/* 036BCC 8005B7CC 3C038000 */  lui   $v1, 0x8000
/* 036BD0 8005B7D0 A6850008 */  sh    $a1, 8($s4)
/* 036BD4 8005B7D4 00022040 */  sll   $a0, $v0, 1
/* 036BD8 8005B7D8 00822021 */  addu  $a0, $a0, $v0
/* 036BDC 8005B7DC 8E820000 */  lw    $v0, ($s4)
/* 036BE0 8005B7E0 00042080 */  sll   $a0, $a0, 2
/* 036BE4 8005B7E4 00431025 */  or    $v0, $v0, $v1
/* 036BE8 8005B7E8 0C00AB6C */  jal   collision_heap_malloc
/* 036BEC 8005B7EC AE820000 */   sw    $v0, ($s4)
/* 036BF0 8005B7F0 0040A82D */  daddu $s5, $v0, $zero
/* 036BF4 8005B7F4 8E91000C */  lw    $s1, 0xc($s4)
/* 036BF8 8005B7F8 8682000A */  lh    $v0, 0xa($s4)
/* 036BFC 8005B7FC 02A0B02D */  daddu $s6, $s5, $zero
/* 036C00 8005B800 18400015 */  blez  $v0, .L8005B858
/* 036C04 8005B804 AFA00010 */   sw    $zero, 0x10($sp)
/* 036C08 8005B808 27B20010 */  addiu $s2, $sp, 0x10
/* 036C0C 8005B80C 26300008 */  addiu $s0, $s1, 8
.L8005B810:
/* 036C10 8005B810 02A0202D */  daddu $a0, $s5, $zero
/* 036C14 8005B814 0240302D */  daddu $a2, $s2, $zero
/* 036C18 8005B818 26730001 */  addiu $s3, $s3, 1
/* 036C1C 8005B81C 8E250000 */  lw    $a1, ($s1)
/* 036C20 8005B820 0C016E68 */  jal   _add_hit_vert_to_buffer
/* 036C24 8005B824 26310040 */   addiu $s1, $s1, 0x40
/* 036C28 8005B828 02A0202D */  daddu $a0, $s5, $zero
/* 036C2C 8005B82C 8E05FFFC */  lw    $a1, -4($s0)
/* 036C30 8005B830 0C016E68 */  jal   _add_hit_vert_to_buffer
/* 036C34 8005B834 0240302D */   daddu $a2, $s2, $zero
/* 036C38 8005B838 02A0202D */  daddu $a0, $s5, $zero
/* 036C3C 8005B83C 8E050000 */  lw    $a1, ($s0)
/* 036C40 8005B840 0C016E68 */  jal   _add_hit_vert_to_buffer
/* 036C44 8005B844 0240302D */   daddu $a2, $s2, $zero
/* 036C48 8005B848 8682000A */  lh    $v0, 0xa($s4)
/* 036C4C 8005B84C 0262102A */  slt   $v0, $s3, $v0
/* 036C50 8005B850 1440FFEF */  bnez  $v0, .L8005B810
/* 036C54 8005B854 26100040 */   addiu $s0, $s0, 0x40
.L8005B858:
/* 036C58 8005B858 8FA20010 */  lw    $v0, 0x10($sp)
/* 036C5C 8005B85C 0000982D */  daddu $s3, $zero, $zero
/* 036C60 8005B860 00022040 */  sll   $a0, $v0, 1
/* 036C64 8005B864 00822021 */  addu  $a0, $a0, $v0
/* 036C68 8005B868 97A20012 */  lhu   $v0, 0x12($sp)
/* 036C6C 8005B86C 000420C0 */  sll   $a0, $a0, 3
/* 036C70 8005B870 0C00AB6C */  jal   collision_heap_malloc
/* 036C74 8005B874 A6820014 */   sh    $v0, 0x14($s4)
/* 036C78 8005B878 8FA30010 */  lw    $v1, 0x10($sp)
/* 036C7C 8005B87C 0040902D */  daddu $s2, $v0, $zero
/* 036C80 8005B880 18600013 */  blez  $v1, .L8005B8D0
/* 036C84 8005B884 AE920018 */   sw    $s2, 0x18($s4)
/* 036C88 8005B888 0060202D */  daddu $a0, $v1, $zero
/* 036C8C 8005B88C 26430008 */  addiu $v1, $s2, 8
.L8005B890:
/* 036C90 8005B890 8EC20000 */  lw    $v0, ($s6)
/* 036C94 8005B894 26D60004 */  addiu $s6, $s6, 4
/* 036C98 8005B898 C4400000 */  lwc1  $f0, ($v0)
/* 036C9C 8005B89C 26730001 */  addiu $s3, $s3, 1
/* 036CA0 8005B8A0 E4600004 */  swc1  $f0, 4($v1)
/* 036CA4 8005B8A4 E6400000 */  swc1  $f0, ($s2)
/* 036CA8 8005B8A8 C4400004 */  lwc1  $f0, 4($v0)
/* 036CAC 8005B8AC 26520018 */  addiu $s2, $s2, 0x18
/* 036CB0 8005B8B0 E4600008 */  swc1  $f0, 8($v1)
/* 036CB4 8005B8B4 E460FFFC */  swc1  $f0, -4($v1)
/* 036CB8 8005B8B8 C4400008 */  lwc1  $f0, 8($v0)
/* 036CBC 8005B8BC 0264102A */  slt   $v0, $s3, $a0
/* 036CC0 8005B8C0 E460000C */  swc1  $f0, 0xc($v1)
/* 036CC4 8005B8C4 E4600000 */  swc1  $f0, ($v1)
/* 036CC8 8005B8C8 1440FFF1 */  bnez  $v0, .L8005B890
/* 036CCC 8005B8CC 24630018 */   addiu $v1, $v1, 0x18
.L8005B8D0:
/* 036CD0 8005B8D0 8E920018 */  lw    $s2, 0x18($s4)
/* 036CD4 8005B8D4 8682000A */  lh    $v0, 0xa($s4)
/* 036CD8 8005B8D8 8E91000C */  lw    $s1, 0xc($s4)
/* 036CDC 8005B8DC 18400024 */  blez  $v0, .L8005B970
/* 036CE0 8005B8E0 0000982D */   daddu $s3, $zero, $zero
/* 036CE4 8005B8E4 27B60010 */  addiu $s6, $sp, 0x10
/* 036CE8 8005B8E8 26300008 */  addiu $s0, $s1, 8
.L8005B8EC:
/* 036CEC 8005B8EC 02A0202D */  daddu $a0, $s5, $zero
/* 036CF0 8005B8F0 02C0302D */  daddu $a2, $s6, $zero
/* 036CF4 8005B8F4 8E250000 */  lw    $a1, ($s1)
/* 036CF8 8005B8F8 0C016E7D */  jal   _get_hit_vert_index_from_buffer
/* 036CFC 8005B8FC 26730001 */   addiu $s3, $s3, 1
/* 036D00 8005B900 02A0202D */  daddu $a0, $s5, $zero
/* 036D04 8005B904 02C0302D */  daddu $a2, $s6, $zero
/* 036D08 8005B908 00021840 */  sll   $v1, $v0, 1
/* 036D0C 8005B90C 00621821 */  addu  $v1, $v1, $v0
/* 036D10 8005B910 000318C0 */  sll   $v1, $v1, 3
/* 036D14 8005B914 02431821 */  addu  $v1, $s2, $v1
/* 036D18 8005B918 AE230000 */  sw    $v1, ($s1)
/* 036D1C 8005B91C 8E05FFFC */  lw    $a1, -4($s0)
/* 036D20 8005B920 0C016E7D */  jal   _get_hit_vert_index_from_buffer
/* 036D24 8005B924 26310040 */   addiu $s1, $s1, 0x40
/* 036D28 8005B928 02A0202D */  daddu $a0, $s5, $zero
/* 036D2C 8005B92C 02C0302D */  daddu $a2, $s6, $zero
/* 036D30 8005B930 00021840 */  sll   $v1, $v0, 1
/* 036D34 8005B934 00621821 */  addu  $v1, $v1, $v0
/* 036D38 8005B938 000318C0 */  sll   $v1, $v1, 3
/* 036D3C 8005B93C 8E050000 */  lw    $a1, ($s0)
/* 036D40 8005B940 02431821 */  addu  $v1, $s2, $v1
/* 036D44 8005B944 0C016E7D */  jal   _get_hit_vert_index_from_buffer
/* 036D48 8005B948 AE03FFFC */   sw    $v1, -4($s0)
/* 036D4C 8005B94C 00021840 */  sll   $v1, $v0, 1
/* 036D50 8005B950 00621821 */  addu  $v1, $v1, $v0
/* 036D54 8005B954 000318C0 */  sll   $v1, $v1, 3
/* 036D58 8005B958 02431821 */  addu  $v1, $s2, $v1
/* 036D5C 8005B95C AE030000 */  sw    $v1, ($s0)
/* 036D60 8005B960 8682000A */  lh    $v0, 0xa($s4)
/* 036D64 8005B964 0262102A */  slt   $v0, $s3, $v0
/* 036D68 8005B968 1440FFE0 */  bnez  $v0, .L8005B8EC
/* 036D6C 8005B96C 26100040 */   addiu $s0, $s0, 0x40
.L8005B970:
/* 036D70 8005B970 0C00AB7D */  jal   collision_heap_free
/* 036D74 8005B974 02A0202D */   daddu $a0, $s5, $zero
/* 036D78 8005B978 8FBF0034 */  lw    $ra, 0x34($sp)
/* 036D7C 8005B97C 8FB60030 */  lw    $s6, 0x30($sp)
/* 036D80 8005B980 8FB5002C */  lw    $s5, 0x2c($sp)
/* 036D84 8005B984 8FB40028 */  lw    $s4, 0x28($sp)
/* 036D88 8005B988 8FB30024 */  lw    $s3, 0x24($sp)
/* 036D8C 8005B98C 8FB20020 */  lw    $s2, 0x20($sp)
/* 036D90 8005B990 8FB1001C */  lw    $s1, 0x1c($sp)
/* 036D94 8005B994 8FB00018 */  lw    $s0, 0x18($sp)
/* 036D98 8005B998 03E00008 */  jr    $ra
/* 036D9C 8005B99C 27BD0038 */   addiu $sp, $sp, 0x38

