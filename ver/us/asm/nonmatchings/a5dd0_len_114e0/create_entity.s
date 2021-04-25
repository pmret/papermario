.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_8014F878
.word L80111B80_A8280, L80111B80_A8280, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B8C_A828C, L80111B80_A8280, L80111B80_A8280, L80111B8C_A828C, L80111B80_A8280, 0

.section .text

glabel create_entity
/* A7FC4 801118C4 AFA40000 */  sw        $a0, ($sp)
/* A7FC8 801118C8 AFA50004 */  sw        $a1, 4($sp)
/* A7FCC 801118CC AFA60008 */  sw        $a2, 8($sp)
/* A7FD0 801118D0 AFA7000C */  sw        $a3, 0xc($sp)
/* A7FD4 801118D4 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* A7FD8 801118D8 AFBF001C */  sw        $ra, 0x1c($sp)
/* A7FDC 801118DC AFB20018 */  sw        $s2, 0x18($sp)
/* A7FE0 801118E0 AFB10014 */  sw        $s1, 0x14($sp)
/* A7FE4 801118E4 AFB00010 */  sw        $s0, 0x10($sp)
/* A7FE8 801118E8 F7BA0038 */  sdc1      $f26, 0x38($sp)
/* A7FEC 801118EC F7B80030 */  sdc1      $f24, 0x30($sp)
/* A7FF0 801118F0 F7B60028 */  sdc1      $f22, 0x28($sp)
/* A7FF4 801118F4 F7B40020 */  sdc1      $f20, 0x20($sp)
/* A7FF8 801118F8 0C044305 */  jal       load_area_specific_entity_data
/* A7FFC 801118FC AFA40040 */   sw       $a0, 0x40($sp)
/* A8000 80111900 27A40054 */  addiu     $a0, $sp, 0x54
/* A8004 80111904 3C038016 */  lui       $v1, %hi(D_8015C7D8)
/* A8008 80111908 2463C7D8 */  addiu     $v1, $v1, %lo(D_8015C7D8)
/* A800C 8011190C C7B60044 */  lwc1      $f22, 0x44($sp)
/* A8010 80111910 4680B5A0 */  cvt.s.w   $f22, $f22
/* A8014 80111914 C7B80048 */  lwc1      $f24, 0x48($sp)
/* A8018 80111918 4680C620 */  cvt.s.w   $f24, $f24
/* A801C 8011191C C7BA004C */  lwc1      $f26, 0x4c($sp)
/* A8020 80111920 4680D6A0 */  cvt.s.w   $f26, $f26
/* A8024 80111924 C7B40050 */  lwc1      $f20, 0x50($sp)
/* A8028 80111928 4680A520 */  cvt.s.w   $f20, $f20
/* A802C 8011192C AC600000 */  sw        $zero, ($v1)
/* A8030 80111930 2463FFFC */  addiu     $v1, $v1, -4
/* A8034 80111934 AC600000 */  sw        $zero, ($v1)
/* A8038 80111938 2463FFFC */  addiu     $v1, $v1, -4
/* A803C 8011193C 24110003 */  addiu     $s1, $zero, 3
/* A8040 80111940 3C058000 */  lui       $a1, 0x8000
/* A8044 80111944 AC600000 */  sw        $zero, ($v1)
.L80111948:
/* A8048 80111948 24840004 */  addiu     $a0, $a0, 4
/* A804C 8011194C 8C82FFFC */  lw        $v0, -4($a0)
/* A8050 80111950 10450004 */  beq       $v0, $a1, .L80111964
/* A8054 80111954 2631FFFF */   addiu    $s1, $s1, -1
/* A8058 80111958 AC620000 */  sw        $v0, ($v1)
/* A805C 8011195C 1E20FFFA */  bgtz      $s1, .L80111948
/* A8060 80111960 24630004 */   addiu    $v1, $v1, 4
.L80111964:
/* A8064 80111964 0000882D */  daddu     $s1, $zero, $zero
/* A8068 80111968 3C128015 */  lui       $s2, %hi(gCurrentEntityListPtr)
/* A806C 8011196C 26521470 */  addiu     $s2, $s2, %lo(gCurrentEntityListPtr)
/* A8070 80111970 8E430000 */  lw        $v1, ($s2)
.L80111974:
/* A8074 80111974 8C620000 */  lw        $v0, ($v1)
/* A8078 80111978 10400006 */  beqz      $v0, .L80111994
/* A807C 8011197C 2A22001E */   slti     $v0, $s1, 0x1e
/* A8080 80111980 26310001 */  addiu     $s1, $s1, 1
/* A8084 80111984 2A22001E */  slti      $v0, $s1, 0x1e
/* A8088 80111988 1440FFFA */  bnez      $v0, .L80111974
/* A808C 8011198C 24630004 */   addiu    $v1, $v1, 4
/* A8090 80111990 2A22001E */  slti      $v0, $s1, 0x1e
.L80111994:
/* A8094 80111994 10400086 */  beqz      $v0, .L80111BB0
/* A8098 80111998 2402FFFF */   addiu    $v0, $zero, -1
/* A809C 8011199C 0C00AB39 */  jal       heap_malloc
/* A80A0 801119A0 240400F8 */   addiu    $a0, $zero, 0xf8
/* A80A4 801119A4 0040802D */  daddu     $s0, $v0, $zero
/* A80A8 801119A8 0200202D */  daddu     $a0, $s0, $zero
/* A80AC 801119AC 240500F8 */  addiu     $a1, $zero, 0xf8
/* A80B0 801119B0 8E420000 */  lw        $v0, ($s2)
/* A80B4 801119B4 00111880 */  sll       $v1, $s1, 2
/* A80B8 801119B8 00621821 */  addu      $v1, $v1, $v0
/* A80BC 801119BC 0C00A580 */  jal       mem_clear
/* A80C0 801119C0 AC700000 */   sw       $s0, ($v1)
/* A80C4 801119C4 8FA30040 */  lw        $v1, 0x40($sp)
/* A80C8 801119C8 AE000040 */  sw        $zero, 0x40($s0)
/* A80CC 801119CC 94620002 */  lhu       $v0, 2($v1)
/* A80D0 801119D0 10400008 */  beqz      $v0, .L801119F4
/* A80D4 801119D4 00000000 */   nop
/* A80D8 801119D8 0C00AB39 */  jal       heap_malloc
/* A80DC 801119DC 0040202D */   daddu    $a0, $v0, $zero
/* A80E0 801119E0 8FA30040 */  lw        $v1, 0x40($sp)
/* A80E4 801119E4 AE020040 */  sw        $v0, 0x40($s0)
/* A80E8 801119E8 94650002 */  lhu       $a1, 2($v1)
/* A80EC 801119EC 0C00A580 */  jal       mem_clear
/* A80F0 801119F0 0040202D */   daddu    $a0, $v0, $zero
.L801119F4:
/* A80F4 801119F4 8FA20040 */  lw        $v0, 0x40($sp)
/* A80F8 801119F8 90420020 */  lbu       $v0, 0x20($v0)
/* A80FC 801119FC A2110004 */  sb        $s1, 4($s0)
/* A8100 80111A00 A202000A */  sb        $v0, 0xa($s0)
/* A8104 80111A04 8FA20040 */  lw        $v0, 0x40($sp)
/* A8108 80111A08 AE000024 */  sw        $zero, 0x24($s0)
/* A810C 80111A0C AE000020 */  sw        $zero, 0x20($s0)
/* A8110 80111A10 AE020038 */  sw        $v0, 0x38($s0)
/* A8114 80111A14 8C430010 */  lw        $v1, 0x10($v0)
/* A8118 80111A18 3C013F80 */  lui       $at, 0x3f80
/* A811C 80111A1C 44810000 */  mtc1      $at, $f0
/* A8120 80111A20 0003102B */  sltu      $v0, $zero, $v1
/* A8124 80111A24 A2020009 */  sb        $v0, 9($s0)
/* A8128 80111A28 8FA40040 */  lw        $a0, 0x40($sp)
/* A812C 80111A2C AE030018 */  sw        $v1, 0x18($s0)
/* A8130 80111A30 8C820010 */  lw        $v0, 0x10($a0)
/* A8134 80111A34 AE00001C */  sw        $zero, 0x1c($s0)
/* A8138 80111A38 AE02002C */  sw        $v0, 0x2c($s0)
/* A813C 80111A3C 94840000 */  lhu       $a0, ($a0)
/* A8140 80111A40 3C028000 */  lui       $v0, 0x8000
/* A8144 80111A44 A2000006 */  sb        $zero, 6($s0)
/* A8148 80111A48 A2000007 */  sb        $zero, 7($s0)
/* A814C 80111A4C AE00003C */  sw        $zero, 0x3c($s0)
/* A8150 80111A50 E6160048 */  swc1      $f22, 0x48($s0)
/* A8154 80111A54 E618004C */  swc1      $f24, 0x4c($s0)
/* A8158 80111A58 E61A0050 */  swc1      $f26, 0x50($s0)
/* A815C 80111A5C AE000060 */  sw        $zero, 0x60($s0)
/* A8160 80111A60 E6140064 */  swc1      $f20, 0x64($s0)
/* A8164 80111A64 AE000068 */  sw        $zero, 0x68($s0)
/* A8168 80111A68 E6000054 */  swc1      $f0, 0x54($s0)
/* A816C 80111A6C E6000058 */  swc1      $f0, 0x58($s0)
/* A8170 80111A70 E600005C */  swc1      $f0, 0x5c($s0)
/* A8174 80111A74 8FA30040 */  lw        $v1, 0x40($sp)
/* A8178 80111A78 00822025 */  or        $a0, $a0, $v0
/* A817C 80111A7C AE040000 */  sw        $a0, ($s0)
/* A8180 80111A80 90620021 */  lbu       $v0, 0x21($v1)
/* A8184 80111A84 A602000C */  sh        $v0, 0xc($s0)
/* A8188 80111A88 90620022 */  lbu       $v0, 0x22($v1)
/* A818C 80111A8C A602000E */  sh        $v0, 0xe($s0)
/* A8190 80111A90 90630023 */  lbu       $v1, 0x23($v1)
/* A8194 80111A94 24020001 */  addiu     $v0, $zero, 1
/* A8198 80111A98 A2020005 */  sb        $v0, 5($s0)
/* A819C 80111A9C 240200FF */  addiu     $v0, $zero, 0xff
/* A81A0 80111AA0 A2020008 */  sb        $v0, 8($s0)
/* A81A4 80111AA4 A202000B */  sb        $v0, 0xb($s0)
/* A81A8 80111AA8 8FA50040 */  lw        $a1, 0x40($sp)
/* A81AC 80111AAC 2402FFFF */  addiu     $v0, $zero, -1
/* A81B0 80111AB0 A6020014 */  sh        $v0, 0x14($s0)
/* A81B4 80111AB4 A6020016 */  sh        $v0, 0x16($s0)
/* A81B8 80111AB8 AE000044 */  sw        $zero, 0x44($s0)
/* A81BC 80111ABC A6030010 */  sh        $v1, 0x10($s0)
/* A81C0 80111AC0 94A20000 */  lhu       $v0, ($a1)
/* A81C4 80111AC4 30420008 */  andi      $v0, $v0, 8
/* A81C8 80111AC8 14400012 */  bnez      $v0, .L80111B14
/* A81CC 80111ACC 0200202D */   daddu    $a0, $s0, $zero
/* A81D0 80111AD0 8CA20018 */  lw        $v0, 0x18($a1)
/* A81D4 80111AD4 10400003 */  beqz      $v0, .L80111AE4
/* A81D8 80111AD8 00000000 */   nop
/* A81DC 80111ADC 0C0444A9 */  jal       load_simple_entity_data
/* A81E0 80111AE0 0220302D */   daddu    $a2, $s1, $zero
.L80111AE4:
/* A81E4 80111AE4 8FA20040 */  lw        $v0, 0x40($sp)
/* A81E8 80111AE8 8C440004 */  lw        $a0, 4($v0)
/* A81EC 80111AEC 1080000C */  beqz      $a0, .L80111B20
/* A81F0 80111AF0 00000000 */   nop
/* A81F4 80111AF4 0C048338 */  jal       load_entity_model
/* A81F8 80111AF8 00000000 */   nop
/* A81FC 80111AFC A6020014 */  sh        $v0, 0x14($s0)
/* A8200 80111B00 00021400 */  sll       $v0, $v0, 0x10
/* A8204 80111B04 0C0483C1 */  jal       exec_entity_model_commandlist
/* A8208 80111B08 00022403 */   sra      $a0, $v0, 0x10
/* A820C 80111B0C 080446C7 */  j         .L80111B1C
/* A8210 80111B10 00000000 */   nop
.L80111B14:
/* A8214 80111B14 0C044502 */  jal       load_split_entity_data
/* A8218 80111B18 0220302D */   daddu    $a2, $s1, $zero
.L80111B1C:
/* A821C 80111B1C 8FA20040 */  lw        $v0, 0x40($sp)
.L80111B20:
/* A8220 80111B20 90430020 */  lbu       $v1, 0x20($v0)
/* A8224 80111B24 24020001 */  addiu     $v0, $zero, 1
/* A8228 80111B28 1062000A */  beq       $v1, $v0, .L80111B54
/* A822C 80111B2C 00000000 */   nop
/* A8230 80111B30 8E020000 */  lw        $v0, ($s0)
/* A8234 80111B34 30420300 */  andi      $v0, $v0, 0x300
/* A8238 80111B38 10400006 */  beqz      $v0, .L80111B54
/* A823C 80111B3C 00000000 */   nop
/* A8240 80111B40 4405B000 */  mfc1      $a1, $f22
/* A8244 80111B44 4406C000 */  mfc1      $a2, $f24
/* A8248 80111B48 4407D000 */  mfc1      $a3, $f26
/* A824C 80111B4C 0C044873 */  jal       create_entity_shadow
/* A8250 80111B50 0200202D */   daddu    $a0, $s0, $zero
.L80111B54:
/* A8254 80111B54 8FA20040 */  lw        $v0, 0x40($sp)
/* A8258 80111B58 90420020 */  lbu       $v0, 0x20($v0)
/* A825C 80111B5C 2443FFF9 */  addiu     $v1, $v0, -7
/* A8260 80111B60 2C62002B */  sltiu     $v0, $v1, 0x2b
/* A8264 80111B64 10400009 */  beqz      $v0, L80111B8C_A828C
/* A8268 80111B68 00031080 */   sll      $v0, $v1, 2
/* A826C 80111B6C 3C018015 */  lui       $at, %hi(jtbl_8014F878)
/* A8270 80111B70 00220821 */  addu      $at, $at, $v0
/* A8274 80111B74 8C22F878 */  lw        $v0, %lo(jtbl_8014F878)($at)
/* A8278 80111B78 00400008 */  jr        $v0
/* A827C 80111B7C 00000000 */   nop
glabel L80111B80_A8280
/* A8280 80111B80 8E020000 */  lw        $v0, ($s0)
/* A8284 80111B84 34424000 */  ori       $v0, $v0, 0x4000
/* A8288 80111B88 AE020000 */  sw        $v0, ($s0)
glabel L80111B8C_A828C
/* A828C 80111B8C 8FA20040 */  lw        $v0, 0x40($sp)
/* A8290 80111B90 8C42000C */  lw        $v0, 0xc($v0)
/* A8294 80111B94 10400003 */  beqz      $v0, .L80111BA4
/* A8298 80111B98 00000000 */   nop
/* A829C 80111B9C 0040F809 */  jalr      $v0
/* A82A0 80111BA0 0200202D */   daddu    $a0, $s0, $zero
.L80111BA4:
/* A82A4 80111BA4 0C04408B */  jal       update_entity_transform_matrix
/* A82A8 80111BA8 0200202D */   daddu    $a0, $s0, $zero
/* A82AC 80111BAC 92020004 */  lbu       $v0, 4($s0)
.L80111BB0:
/* A82B0 80111BB0 8FBF001C */  lw        $ra, 0x1c($sp)
/* A82B4 80111BB4 8FB20018 */  lw        $s2, 0x18($sp)
/* A82B8 80111BB8 8FB10014 */  lw        $s1, 0x14($sp)
/* A82BC 80111BBC 8FB00010 */  lw        $s0, 0x10($sp)
/* A82C0 80111BC0 D7BA0038 */  ldc1      $f26, 0x38($sp)
/* A82C4 80111BC4 D7B80030 */  ldc1      $f24, 0x30($sp)
/* A82C8 80111BC8 D7B60028 */  ldc1      $f22, 0x28($sp)
/* A82CC 80111BCC D7B40020 */  ldc1      $f20, 0x20($sp)
/* A82D0 80111BD0 03E00008 */  jr        $ra
/* A82D4 80111BD4 27BD0040 */   addiu    $sp, $sp, 0x40
