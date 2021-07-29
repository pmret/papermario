.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel load_simple_entity_data
/* A79A4 801112A4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A79A8 801112A8 AFB20020 */  sw        $s2, 0x20($sp)
/* A79AC 801112AC 0080902D */  daddu     $s2, $a0, $zero
/* A79B0 801112B0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* A79B4 801112B4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* A79B8 801112B8 2403000A */  addiu     $v1, $zero, 0xa
/* A79BC 801112BC AFBF0024 */  sw        $ra, 0x24($sp)
/* A79C0 801112C0 AFB1001C */  sw        $s1, 0x1c($sp)
/* A79C4 801112C4 AFB00018 */  sw        $s0, 0x18($sp)
/* A79C8 801112C8 A6430012 */  sh        $v1, 0x12($s2)
/* A79CC 801112CC 80420070 */  lb        $v0, 0x70($v0)
/* A79D0 801112D0 14400005 */  bnez      $v0, .L801112E8
/* A79D4 801112D4 00A0882D */   daddu    $s1, $a1, $zero
/* A79D8 801112D8 3C108015 */  lui       $s0, %hi(D_8015165C)
/* A79DC 801112DC 8E10165C */  lw        $s0, %lo(D_8015165C)($s0)
/* A79E0 801112E0 080444BD */  j         .L801112F4
/* A79E4 801112E4 0240202D */   daddu    $a0, $s2, $zero
.L801112E8:
/* A79E8 801112E8 3C108015 */  lui       $s0, %hi(D_80151660)
/* A79EC 801112EC 8E101660 */  lw        $s0, %lo(D_80151660)($s0)
/* A79F0 801112F0 0240202D */  daddu     $a0, $s2, $zero
.L801112F4:
/* A79F4 801112F4 0220282D */  daddu     $a1, $s1, $zero
/* A79F8 801112F8 27A60010 */  addiu     $a2, $sp, 0x10
/* A79FC 801112FC 0C044457 */  jal       is_entity_data_loaded
/* A7A00 80111300 27A70014 */   addiu    $a3, $sp, 0x14
/* A7A04 80111304 10400020 */  beqz      $v0, .L80111388
/* A7A08 80111308 00000000 */   nop
/* A7A0C 8011130C 8E22001C */  lw        $v0, 0x1c($s1)
/* A7A10 80111310 8E230018 */  lw        $v1, 0x18($s1)
/* A7A14 80111314 00431023 */  subu      $v0, $v0, $v1
/* A7A18 80111318 00021083 */  sra       $v0, $v0, 2
/* A7A1C 8011131C 02021021 */  addu      $v0, $s0, $v0
/* A7A20 80111320 2C425FFD */  sltiu     $v0, $v0, 0x5ffd
/* A7A24 80111324 14400007 */  bnez      $v0, .L80111344
/* A7A28 80111328 00000000 */   nop
/* A7A2C 8011132C 0C0441A9 */  jal       get_entity_type
/* A7A30 80111330 92440004 */   lbu      $a0, 4($s2)
/* A7A34 80111334 0C0441A9 */  jal       get_entity_type
/* A7A38 80111338 92440004 */   lbu      $a0, 4($s2)
.L8011133C:
/* A7A3C 8011133C 080444CF */  j         .L8011133C
/* A7A40 80111340 00000000 */   nop
.L80111344:
/* A7A44 80111344 8E22001C */  lw        $v0, 0x1c($s1)
/* A7A48 80111348 3C068015 */  lui       $a2, %hi(D_801512C4)
/* A7A4C 8011134C 8CC612C4 */  lw        $a2, %lo(D_801512C4)($a2)
/* A7A50 80111350 00431023 */  subu      $v0, $v0, $v1
/* A7A54 80111354 00022883 */  sra       $a1, $v0, 2
/* A7A58 80111358 00101080 */  sll       $v0, $s0, 2
/* A7A5C 8011135C 00C23023 */  subu      $a2, $a2, $v0
/* A7A60 80111360 00051080 */  sll       $v0, $a1, 2
/* A7A64 80111364 00C23023 */  subu      $a2, $a2, $v0
/* A7A68 80111368 AE460044 */  sw        $a2, 0x44($s2)
/* A7A6C 8011136C 8E240018 */  lw        $a0, 0x18($s1)
/* A7A70 80111370 0C00A5CF */  jal       dma_copy
/* A7A74 80111374 8E25001C */   lw       $a1, 0x1c($s1)
/* A7A78 80111378 00021082 */  srl       $v0, $v0, 2
/* A7A7C 8011137C 92440004 */  lbu       $a0, 4($s2)
/* A7A80 80111380 080444EF */  j         .L801113BC
/* A7A84 80111384 02028021 */   addu     $s0, $s0, $v0
.L80111388:
/* A7A88 80111388 8E22001C */  lw        $v0, 0x1c($s1)
/* A7A8C 8011138C 8E230018 */  lw        $v1, 0x18($s1)
/* A7A90 80111390 92440004 */  lbu       $a0, 4($s2)
/* A7A94 80111394 00431023 */  subu      $v0, $v0, $v1
/* A7A98 80111398 00022883 */  sra       $a1, $v0, 2
/* A7A9C 8011139C 8FA20010 */  lw        $v0, 0x10($sp)
/* A7AA0 801113A0 3C038015 */  lui       $v1, %hi(D_801512C4)
/* A7AA4 801113A4 8C6312C4 */  lw        $v1, %lo(D_801512C4)($v1)
/* A7AA8 801113A8 00021080 */  sll       $v0, $v0, 2
/* A7AAC 801113AC 00621823 */  subu      $v1, $v1, $v0
/* A7AB0 801113B0 00051080 */  sll       $v0, $a1, 2
/* A7AB4 801113B4 00621823 */  subu      $v1, $v1, $v0
/* A7AB8 801113B8 AE430044 */  sw        $v1, 0x44($s2)
.L801113BC:
/* A7ABC 801113BC 0C0441A9 */  jal       get_entity_type
/* A7AC0 801113C0 00000000 */   nop
/* A7AC4 801113C4 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* A7AC8 801113C8 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* A7ACC 801113CC 80420070 */  lb        $v0, 0x70($v0)
/* A7AD0 801113D0 14400005 */  bnez      $v0, .L801113E8
/* A7AD4 801113D4 00000000 */   nop
/* A7AD8 801113D8 3C018015 */  lui       $at, %hi(D_8015165C)
/* A7ADC 801113DC AC30165C */  sw        $s0, %lo(D_8015165C)($at)
/* A7AE0 801113E0 080444FC */  j         .L801113F0
/* A7AE4 801113E4 00000000 */   nop
.L801113E8:
/* A7AE8 801113E8 3C018015 */  lui       $at, %hi(D_80151660)
/* A7AEC 801113EC AC301660 */  sw        $s0, %lo(D_80151660)($at)
.L801113F0:
/* A7AF0 801113F0 8FBF0024 */  lw        $ra, 0x24($sp)
/* A7AF4 801113F4 8FB20020 */  lw        $s2, 0x20($sp)
/* A7AF8 801113F8 8FB1001C */  lw        $s1, 0x1c($sp)
/* A7AFC 801113FC 8FB00018 */  lw        $s0, 0x18($sp)
/* A7B00 80111400 03E00008 */  jr        $ra
/* A7B04 80111404 27BD0028 */   addiu    $sp, $sp, 0x28
