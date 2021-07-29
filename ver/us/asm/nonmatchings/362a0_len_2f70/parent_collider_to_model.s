.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel parent_collider_to_model
/* 36B80 8005B780 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 36B84 8005B784 00042400 */  sll       $a0, $a0, 0x10
/* 36B88 8005B788 00042403 */  sra       $a0, $a0, 0x10
/* 36B8C 8005B78C 000410C0 */  sll       $v0, $a0, 3
/* 36B90 8005B790 00441023 */  subu      $v0, $v0, $a0
/* 36B94 8005B794 3C03800B */  lui       $v1, %hi(gCollisionData+0x4)
/* 36B98 8005B798 8C6342E4 */  lw        $v1, %lo(gCollisionData+0x4)($v1)
/* 36B9C 8005B79C 00021080 */  sll       $v0, $v0, 2
/* 36BA0 8005B7A0 AFB30024 */  sw        $s3, 0x24($sp)
/* 36BA4 8005B7A4 0000982D */  daddu     $s3, $zero, $zero
/* 36BA8 8005B7A8 AFBF0034 */  sw        $ra, 0x34($sp)
/* 36BAC 8005B7AC AFB60030 */  sw        $s6, 0x30($sp)
/* 36BB0 8005B7B0 AFB5002C */  sw        $s5, 0x2c($sp)
/* 36BB4 8005B7B4 AFB40028 */  sw        $s4, 0x28($sp)
/* 36BB8 8005B7B8 AFB20020 */  sw        $s2, 0x20($sp)
/* 36BBC 8005B7BC AFB1001C */  sw        $s1, 0x1c($sp)
/* 36BC0 8005B7C0 AFB00018 */  sw        $s0, 0x18($sp)
/* 36BC4 8005B7C4 0062A021 */  addu      $s4, $v1, $v0
/* 36BC8 8005B7C8 8682000A */  lh        $v0, 0xa($s4)
/* 36BCC 8005B7CC 3C038000 */  lui       $v1, 0x8000
/* 36BD0 8005B7D0 A6850008 */  sh        $a1, 8($s4)
/* 36BD4 8005B7D4 00022040 */  sll       $a0, $v0, 1
/* 36BD8 8005B7D8 00822021 */  addu      $a0, $a0, $v0
/* 36BDC 8005B7DC 8E820000 */  lw        $v0, ($s4)
/* 36BE0 8005B7E0 00042080 */  sll       $a0, $a0, 2
/* 36BE4 8005B7E4 00431025 */  or        $v0, $v0, $v1
/* 36BE8 8005B7E8 0C00AB6C */  jal       collision_heap_malloc
/* 36BEC 8005B7EC AE820000 */   sw       $v0, ($s4)
/* 36BF0 8005B7F0 0040A82D */  daddu     $s5, $v0, $zero
/* 36BF4 8005B7F4 8E91000C */  lw        $s1, 0xc($s4)
/* 36BF8 8005B7F8 8682000A */  lh        $v0, 0xa($s4)
/* 36BFC 8005B7FC 02A0B02D */  daddu     $s6, $s5, $zero
/* 36C00 8005B800 18400015 */  blez      $v0, .L8005B858
/* 36C04 8005B804 AFA00010 */   sw       $zero, 0x10($sp)
/* 36C08 8005B808 27B20010 */  addiu     $s2, $sp, 0x10
/* 36C0C 8005B80C 26300008 */  addiu     $s0, $s1, 8
.L8005B810:
/* 36C10 8005B810 02A0202D */  daddu     $a0, $s5, $zero
/* 36C14 8005B814 0240302D */  daddu     $a2, $s2, $zero
/* 36C18 8005B818 26730001 */  addiu     $s3, $s3, 1
/* 36C1C 8005B81C 8E250000 */  lw        $a1, ($s1)
/* 36C20 8005B820 0C016E68 */  jal       _add_hit_vert_to_buffer
/* 36C24 8005B824 26310040 */   addiu    $s1, $s1, 0x40
/* 36C28 8005B828 02A0202D */  daddu     $a0, $s5, $zero
/* 36C2C 8005B82C 8E05FFFC */  lw        $a1, -4($s0)
/* 36C30 8005B830 0C016E68 */  jal       _add_hit_vert_to_buffer
/* 36C34 8005B834 0240302D */   daddu    $a2, $s2, $zero
/* 36C38 8005B838 02A0202D */  daddu     $a0, $s5, $zero
/* 36C3C 8005B83C 8E050000 */  lw        $a1, ($s0)
/* 36C40 8005B840 0C016E68 */  jal       _add_hit_vert_to_buffer
/* 36C44 8005B844 0240302D */   daddu    $a2, $s2, $zero
/* 36C48 8005B848 8682000A */  lh        $v0, 0xa($s4)
/* 36C4C 8005B84C 0262102A */  slt       $v0, $s3, $v0
/* 36C50 8005B850 1440FFEF */  bnez      $v0, .L8005B810
/* 36C54 8005B854 26100040 */   addiu    $s0, $s0, 0x40
.L8005B858:
/* 36C58 8005B858 8FA20010 */  lw        $v0, 0x10($sp)
/* 36C5C 8005B85C 0000982D */  daddu     $s3, $zero, $zero
/* 36C60 8005B860 00022040 */  sll       $a0, $v0, 1
/* 36C64 8005B864 00822021 */  addu      $a0, $a0, $v0
/* 36C68 8005B868 97A20012 */  lhu       $v0, 0x12($sp)
/* 36C6C 8005B86C 000420C0 */  sll       $a0, $a0, 3
/* 36C70 8005B870 0C00AB6C */  jal       collision_heap_malloc
/* 36C74 8005B874 A6820014 */   sh       $v0, 0x14($s4)
/* 36C78 8005B878 8FA30010 */  lw        $v1, 0x10($sp)
/* 36C7C 8005B87C 0040902D */  daddu     $s2, $v0, $zero
/* 36C80 8005B880 18600013 */  blez      $v1, .L8005B8D0
/* 36C84 8005B884 AE920018 */   sw       $s2, 0x18($s4)
/* 36C88 8005B888 0060202D */  daddu     $a0, $v1, $zero
/* 36C8C 8005B88C 26430008 */  addiu     $v1, $s2, 8
.L8005B890:
/* 36C90 8005B890 8EC20000 */  lw        $v0, ($s6)
/* 36C94 8005B894 26D60004 */  addiu     $s6, $s6, 4
/* 36C98 8005B898 C4400000 */  lwc1      $f0, ($v0)
/* 36C9C 8005B89C 26730001 */  addiu     $s3, $s3, 1
/* 36CA0 8005B8A0 E4600004 */  swc1      $f0, 4($v1)
/* 36CA4 8005B8A4 E6400000 */  swc1      $f0, ($s2)
/* 36CA8 8005B8A8 C4400004 */  lwc1      $f0, 4($v0)
/* 36CAC 8005B8AC 26520018 */  addiu     $s2, $s2, 0x18
/* 36CB0 8005B8B0 E4600008 */  swc1      $f0, 8($v1)
/* 36CB4 8005B8B4 E460FFFC */  swc1      $f0, -4($v1)
/* 36CB8 8005B8B8 C4400008 */  lwc1      $f0, 8($v0)
/* 36CBC 8005B8BC 0264102A */  slt       $v0, $s3, $a0
/* 36CC0 8005B8C0 E460000C */  swc1      $f0, 0xc($v1)
/* 36CC4 8005B8C4 E4600000 */  swc1      $f0, ($v1)
/* 36CC8 8005B8C8 1440FFF1 */  bnez      $v0, .L8005B890
/* 36CCC 8005B8CC 24630018 */   addiu    $v1, $v1, 0x18
.L8005B8D0:
/* 36CD0 8005B8D0 8E920018 */  lw        $s2, 0x18($s4)
/* 36CD4 8005B8D4 8682000A */  lh        $v0, 0xa($s4)
/* 36CD8 8005B8D8 8E91000C */  lw        $s1, 0xc($s4)
/* 36CDC 8005B8DC 18400024 */  blez      $v0, .L8005B970
/* 36CE0 8005B8E0 0000982D */   daddu    $s3, $zero, $zero
/* 36CE4 8005B8E4 27B60010 */  addiu     $s6, $sp, 0x10
/* 36CE8 8005B8E8 26300008 */  addiu     $s0, $s1, 8
.L8005B8EC:
/* 36CEC 8005B8EC 02A0202D */  daddu     $a0, $s5, $zero
/* 36CF0 8005B8F0 02C0302D */  daddu     $a2, $s6, $zero
/* 36CF4 8005B8F4 8E250000 */  lw        $a1, ($s1)
/* 36CF8 8005B8F8 0C016E7D */  jal       _get_hit_vert_index_from_buffer
/* 36CFC 8005B8FC 26730001 */   addiu    $s3, $s3, 1
/* 36D00 8005B900 02A0202D */  daddu     $a0, $s5, $zero
/* 36D04 8005B904 02C0302D */  daddu     $a2, $s6, $zero
/* 36D08 8005B908 00021840 */  sll       $v1, $v0, 1
/* 36D0C 8005B90C 00621821 */  addu      $v1, $v1, $v0
/* 36D10 8005B910 000318C0 */  sll       $v1, $v1, 3
/* 36D14 8005B914 02431821 */  addu      $v1, $s2, $v1
/* 36D18 8005B918 AE230000 */  sw        $v1, ($s1)
/* 36D1C 8005B91C 8E05FFFC */  lw        $a1, -4($s0)
/* 36D20 8005B920 0C016E7D */  jal       _get_hit_vert_index_from_buffer
/* 36D24 8005B924 26310040 */   addiu    $s1, $s1, 0x40
/* 36D28 8005B928 02A0202D */  daddu     $a0, $s5, $zero
/* 36D2C 8005B92C 02C0302D */  daddu     $a2, $s6, $zero
/* 36D30 8005B930 00021840 */  sll       $v1, $v0, 1
/* 36D34 8005B934 00621821 */  addu      $v1, $v1, $v0
/* 36D38 8005B938 000318C0 */  sll       $v1, $v1, 3
/* 36D3C 8005B93C 8E050000 */  lw        $a1, ($s0)
/* 36D40 8005B940 02431821 */  addu      $v1, $s2, $v1
/* 36D44 8005B944 0C016E7D */  jal       _get_hit_vert_index_from_buffer
/* 36D48 8005B948 AE03FFFC */   sw       $v1, -4($s0)
/* 36D4C 8005B94C 00021840 */  sll       $v1, $v0, 1
/* 36D50 8005B950 00621821 */  addu      $v1, $v1, $v0
/* 36D54 8005B954 000318C0 */  sll       $v1, $v1, 3
/* 36D58 8005B958 02431821 */  addu      $v1, $s2, $v1
/* 36D5C 8005B95C AE030000 */  sw        $v1, ($s0)
/* 36D60 8005B960 8682000A */  lh        $v0, 0xa($s4)
/* 36D64 8005B964 0262102A */  slt       $v0, $s3, $v0
/* 36D68 8005B968 1440FFE0 */  bnez      $v0, .L8005B8EC
/* 36D6C 8005B96C 26100040 */   addiu    $s0, $s0, 0x40
.L8005B970:
/* 36D70 8005B970 0C00AB7D */  jal       collision_heap_free
/* 36D74 8005B974 02A0202D */   daddu    $a0, $s5, $zero
/* 36D78 8005B978 8FBF0034 */  lw        $ra, 0x34($sp)
/* 36D7C 8005B97C 8FB60030 */  lw        $s6, 0x30($sp)
/* 36D80 8005B980 8FB5002C */  lw        $s5, 0x2c($sp)
/* 36D84 8005B984 8FB40028 */  lw        $s4, 0x28($sp)
/* 36D88 8005B988 8FB30024 */  lw        $s3, 0x24($sp)
/* 36D8C 8005B98C 8FB20020 */  lw        $s2, 0x20($sp)
/* 36D90 8005B990 8FB1001C */  lw        $s1, 0x1c($sp)
/* 36D94 8005B994 8FB00018 */  lw        $s0, 0x18($sp)
/* 36D98 8005B998 03E00008 */  jr        $ra
/* 36D9C 8005B99C 27BD0038 */   addiu    $sp, $sp, 0x38
