.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219A40_448E80
/* 448E80 80219A40 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 448E84 80219A44 AFB60038 */  sw        $s6, 0x38($sp)
/* 448E88 80219A48 0080B02D */  daddu     $s6, $a0, $zero
/* 448E8C 80219A4C 27A50010 */  addiu     $a1, $sp, 0x10
/* 448E90 80219A50 27A60014 */  addiu     $a2, $sp, 0x14
/* 448E94 80219A54 27A70018 */  addiu     $a3, $sp, 0x18
/* 448E98 80219A58 AFBF003C */  sw        $ra, 0x3c($sp)
/* 448E9C 80219A5C AFB50034 */  sw        $s5, 0x34($sp)
/* 448EA0 80219A60 AFB40030 */  sw        $s4, 0x30($sp)
/* 448EA4 80219A64 AFB3002C */  sw        $s3, 0x2c($sp)
/* 448EA8 80219A68 AFB20028 */  sw        $s2, 0x28($sp)
/* 448EAC 80219A6C AFB10024 */  sw        $s1, 0x24($sp)
/* 448EB0 80219A70 0C0470AC */  jal       mdl_get_copied_vertices
/* 448EB4 80219A74 AFB00020 */   sw       $s0, 0x20($sp)
/* 448EB8 80219A78 8FA20018 */  lw        $v0, 0x18($sp)
/* 448EBC 80219A7C 18400052 */  blez      $v0, .L80219BC8
/* 448EC0 80219A80 0000802D */   daddu    $s0, $zero, $zero
/* 448EC4 80219A84 3C038023 */  lui       $v1, %hi(b_area_kmr_part_3_sam_01_D_802336E0_43AB20)
/* 448EC8 80219A88 246336E0 */  addiu     $v1, $v1, %lo(b_area_kmr_part_3_sam_01_D_802336E0_43AB20)
/* 448ECC 80219A8C 00161040 */  sll       $v0, $s6, 1
/* 448ED0 80219A90 0043A021 */  addu      $s4, $v0, $v1
/* 448ED4 80219A94 3C135555 */  lui       $s3, 0x5555
/* 448ED8 80219A98 36735556 */  ori       $s3, $s3, 0x5556
/* 448EDC 80219A9C 34158000 */  ori       $s5, $zero, 0x8000
/* 448EE0 80219AA0 02130018 */  mult      $s0, $s3
.L80219AA4:
/* 448EE4 80219AA4 001097C3 */  sra       $s2, $s0, 0x1f
/* 448EE8 80219AA8 00001810 */  mfhi      $v1
/* 448EEC 80219AAC 00721823 */  subu      $v1, $v1, $s2
/* 448EF0 80219AB0 00031040 */  sll       $v0, $v1, 1
/* 448EF4 80219AB4 00431021 */  addu      $v0, $v0, $v1
/* 448EF8 80219AB8 02021023 */  subu      $v0, $s0, $v0
/* 448EFC 80219ABC 96830000 */  lhu       $v1, ($s4)
/* 448F00 80219AC0 24420001 */  addiu     $v0, $v0, 1
/* 448F04 80219AC4 00620018 */  mult      $v1, $v0
/* 448F08 80219AC8 00101100 */  sll       $v0, $s0, 4
/* 448F0C 80219ACC 00001812 */  mflo      $v1
/* 448F10 80219AD0 00702021 */  addu      $a0, $v1, $s0
/* 448F14 80219AD4 8FA30014 */  lw        $v1, 0x14($sp)
/* 448F18 80219AD8 3084FFFF */  andi      $a0, $a0, 0xffff
/* 448F1C 80219ADC 0C01917C */  jal       sins
/* 448F20 80219AE0 00628821 */   addu     $s1, $v1, $v0
/* 448F24 80219AE4 00021400 */  sll       $v0, $v0, 0x10
/* 448F28 80219AE8 00021403 */  sra       $v0, $v0, 0x10
/* 448F2C 80219AEC 00551021 */  addu      $v0, $v0, $s5
/* 448F30 80219AF0 00021FC2 */  srl       $v1, $v0, 0x1f
/* 448F34 80219AF4 00431021 */  addu      $v0, $v0, $v1
/* 448F38 80219AF8 000213C0 */  sll       $v0, $v0, 0xf
/* 448F3C 80219AFC 00021403 */  sra       $v0, $v0, 0x10
/* 448F40 80219B00 00021880 */  sll       $v1, $v0, 2
/* 448F44 80219B04 00621821 */  addu      $v1, $v1, $v0
/* 448F48 80219B08 00031140 */  sll       $v0, $v1, 5
/* 448F4C 80219B0C 00431823 */  subu      $v1, $v0, $v1
/* 448F50 80219B10 04610002 */  bgez      $v1, .L80219B1C
/* 448F54 80219B14 0060102D */   daddu    $v0, $v1, $zero
/* 448F58 80219B18 24627FFF */  addiu     $v0, $v1, 0x7fff
.L80219B1C:
/* 448F5C 80219B1C 000223C3 */  sra       $a0, $v0, 0xf
/* 448F60 80219B20 24820064 */  addiu     $v0, $a0, 0x64
/* 448F64 80219B24 A222000E */  sb        $v0, 0xe($s1)
/* 448F68 80219B28 24820032 */  addiu     $v0, $a0, 0x32
/* 448F6C 80219B2C 02121823 */  subu      $v1, $s0, $s2
/* 448F70 80219B30 00032843 */  sra       $a1, $v1, 1
/* 448F74 80219B34 00B30018 */  mult      $a1, $s3
/* 448F78 80219B38 A222000D */  sb        $v0, 0xd($s1)
/* 448F7C 80219B3C 96840000 */  lhu       $a0, ($s4)
/* 448F80 80219B40 00031FC3 */  sra       $v1, $v1, 0x1f
/* 448F84 80219B44 000433C2 */  srl       $a2, $a0, 0xf
/* 448F88 80219B48 00004810 */  mfhi      $t1
/* 448F8C 80219B4C 01231823 */  subu      $v1, $t1, $v1
/* 448F90 80219B50 00031040 */  sll       $v0, $v1, 1
/* 448F94 80219B54 00431021 */  addu      $v0, $v0, $v1
/* 448F98 80219B58 00A22823 */  subu      $a1, $a1, $v0
/* 448F9C 80219B5C 24A50001 */  addiu     $a1, $a1, 1
/* 448FA0 80219B60 00052BC0 */  sll       $a1, $a1, 0xf
/* 448FA4 80219B64 00C50018 */  mult      $a2, $a1
/* 448FA8 80219B68 00042382 */  srl       $a0, $a0, 0xe
/* 448FAC 80219B6C 000423C0 */  sll       $a0, $a0, 0xf
/* 448FB0 80219B70 00001812 */  mflo      $v1
/* 448FB4 80219B74 00642021 */  addu      $a0, $v1, $a0
/* 448FB8 80219B78 00902021 */  addu      $a0, $a0, $s0
/* 448FBC 80219B7C 0C01917C */  jal       sins
/* 448FC0 80219B80 3084FFFF */   andi     $a0, $a0, 0xffff
/* 448FC4 80219B84 00021400 */  sll       $v0, $v0, 0x10
/* 448FC8 80219B88 00021403 */  sra       $v0, $v0, 0x10
/* 448FCC 80219B8C 9223000C */  lbu       $v1, 0xc($s1)
/* 448FD0 80219B90 00551021 */  addu      $v0, $v0, $s5
/* 448FD4 80219B94 00620018 */  mult      $v1, $v0
/* 448FD8 80219B98 00001812 */  mflo      $v1
/* 448FDC 80219B9C 04610004 */  bgez      $v1, .L80219BB0
/* 448FE0 80219BA0 00031403 */   sra      $v0, $v1, 0x10
/* 448FE4 80219BA4 3402FFFF */  ori       $v0, $zero, 0xffff
/* 448FE8 80219BA8 00621821 */  addu      $v1, $v1, $v0
/* 448FEC 80219BAC 00031403 */  sra       $v0, $v1, 0x10
.L80219BB0:
/* 448FF0 80219BB0 A222000C */  sb        $v0, 0xc($s1)
/* 448FF4 80219BB4 8FA20018 */  lw        $v0, 0x18($sp)
/* 448FF8 80219BB8 26100001 */  addiu     $s0, $s0, 1
/* 448FFC 80219BBC 0202102A */  slt       $v0, $s0, $v0
/* 449000 80219BC0 1440FFB8 */  bnez      $v0, .L80219AA4
/* 449004 80219BC4 02130018 */   mult     $s0, $s3
.L80219BC8:
/* 449008 80219BC8 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 44900C 80219BCC 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 449010 80219BD0 8C620000 */  lw        $v0, ($v1)
/* 449014 80219BD4 02C0202D */  daddu     $a0, $s6, $zero
/* 449018 80219BD8 0040802D */  daddu     $s0, $v0, $zero
/* 44901C 80219BDC 24420008 */  addiu     $v0, $v0, 8
/* 449020 80219BE0 AC620000 */  sw        $v0, ($v1)
/* 449024 80219BE4 3C02DE00 */  lui       $v0, 0xde00
/* 449028 80219BE8 0C0470BB */  jal       mdl_get_copied_gfx
/* 44902C 80219BEC AE020000 */   sw       $v0, ($s0)
/* 449030 80219BF0 AE020004 */  sw        $v0, 4($s0)
/* 449034 80219BF4 3C028023 */  lui       $v0, %hi(b_area_kmr_part_3_sam_01_D_802336E0_43AB20)
/* 449038 80219BF8 244236E0 */  addiu     $v0, $v0, %lo(b_area_kmr_part_3_sam_01_D_802336E0_43AB20)
/* 44903C 80219BFC 00161840 */  sll       $v1, $s6, 1
/* 449040 80219C00 00621821 */  addu      $v1, $v1, $v0
/* 449044 80219C04 94620000 */  lhu       $v0, ($v1)
/* 449048 80219C08 24420253 */  addiu     $v0, $v0, 0x253
/* 44904C 80219C0C A4620000 */  sh        $v0, ($v1)
/* 449050 80219C10 8FBF003C */  lw        $ra, 0x3c($sp)
/* 449054 80219C14 8FB60038 */  lw        $s6, 0x38($sp)
/* 449058 80219C18 8FB50034 */  lw        $s5, 0x34($sp)
/* 44905C 80219C1C 8FB40030 */  lw        $s4, 0x30($sp)
/* 449060 80219C20 8FB3002C */  lw        $s3, 0x2c($sp)
/* 449064 80219C24 8FB20028 */  lw        $s2, 0x28($sp)
/* 449068 80219C28 8FB10024 */  lw        $s1, 0x24($sp)
/* 44906C 80219C2C 8FB00020 */  lw        $s0, 0x20($sp)
/* 449070 80219C30 03E00008 */  jr        $ra
/* 449074 80219C34 27BD0040 */   addiu    $sp, $sp, 0x40
