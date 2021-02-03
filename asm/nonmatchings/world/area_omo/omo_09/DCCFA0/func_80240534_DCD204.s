.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240534_DCD204
/* DCD204 80240534 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* DCD208 80240538 AFB40040 */  sw        $s4, 0x40($sp)
/* DCD20C 8024053C AFBF0044 */  sw        $ra, 0x44($sp)
/* DCD210 80240540 AFB3003C */  sw        $s3, 0x3c($sp)
/* DCD214 80240544 AFB20038 */  sw        $s2, 0x38($sp)
/* DCD218 80240548 AFB10034 */  sw        $s1, 0x34($sp)
/* DCD21C 8024054C AFB00030 */  sw        $s0, 0x30($sp)
/* DCD220 80240550 F7B40048 */  sdc1      $f20, 0x48($sp)
/* DCD224 80240554 10A0001B */  beqz      $a1, .L802405C4
/* DCD228 80240558 0080A02D */   daddu    $s4, $a0, $zero
/* DCD22C 8024055C 0C00AB39 */  jal       heap_malloc
/* DCD230 80240560 24040010 */   addiu    $a0, $zero, 0x10
/* DCD234 80240564 0000902D */  daddu     $s2, $zero, $zero
/* DCD238 80240568 0040802D */  daddu     $s0, $v0, $zero
/* DCD23C 8024056C 3C0142C8 */  lui       $at, 0x42c8
/* DCD240 80240570 4481A000 */  mtc1      $at, $f20
/* DCD244 80240574 3C118024 */  lui       $s1, %hi(D_8024636C_DD303C)
/* DCD248 80240578 2631636C */  addiu     $s1, $s1, %lo(D_8024636C_DD303C)
/* DCD24C 8024057C AE900070 */  sw        $s0, 0x70($s4)
.L80240580:
/* DCD250 80240580 8E240000 */  lw        $a0, ($s1)
/* DCD254 80240584 0C046C04 */  jal       get_model_list_index_from_tree_index
/* DCD258 80240588 26310004 */   addiu    $s1, $s1, 4
/* DCD25C 8024058C 0C046B4C */  jal       get_model_from_list_index
/* DCD260 80240590 0040202D */   daddu    $a0, $v0, $zero
/* DCD264 80240594 C440009C */  lwc1      $f0, 0x9c($v0)
/* DCD268 80240598 26520001 */  addiu     $s2, $s2, 1
/* DCD26C 8024059C 46140001 */  sub.s     $f0, $f0, $f20
/* DCD270 802405A0 8C450098 */  lw        $a1, 0x98($v0)
/* DCD274 802405A4 8C4700A0 */  lw        $a3, 0xa0($v0)
/* DCD278 802405A8 44060000 */  mfc1      $a2, $f0
/* DCD27C 802405AC 0C044898 */  jal       create_shadow_type
/* DCD280 802405B0 24040001 */   addiu    $a0, $zero, 1
/* DCD284 802405B4 AE020000 */  sw        $v0, ($s0)
/* DCD288 802405B8 2E420004 */  sltiu     $v0, $s2, 4
/* DCD28C 802405BC 1440FFF0 */  bnez      $v0, .L80240580
/* DCD290 802405C0 26100004 */   addiu    $s0, $s0, 4
.L802405C4:
/* DCD294 802405C4 0000902D */  daddu     $s2, $zero, $zero
/* DCD298 802405C8 3C138024 */  lui       $s3, %hi(D_8024636C_DD303C)
/* DCD29C 802405CC 2673636C */  addiu     $s3, $s3, %lo(D_8024636C_DD303C)
/* DCD2A0 802405D0 3C013FA6 */  lui       $at, 0x3fa6
/* DCD2A4 802405D4 34216666 */  ori       $at, $at, 0x6666
/* DCD2A8 802405D8 4481A000 */  mtc1      $at, $f20
/* DCD2AC 802405DC 8E910070 */  lw        $s1, 0x70($s4)
.L802405E0:
/* DCD2B0 802405E0 8E240000 */  lw        $a0, ($s1)
/* DCD2B4 802405E4 26310004 */  addiu     $s1, $s1, 4
/* DCD2B8 802405E8 0C044181 */  jal       get_shadow_by_index
/* DCD2BC 802405EC 26520001 */   addiu    $s2, $s2, 1
/* DCD2C0 802405F0 8E640000 */  lw        $a0, ($s3)
/* DCD2C4 802405F4 0C046C04 */  jal       get_model_list_index_from_tree_index
/* DCD2C8 802405F8 0040802D */   daddu    $s0, $v0, $zero
/* DCD2CC 802405FC 0C046B4C */  jal       get_model_from_list_index
/* DCD2D0 80240600 0040202D */   daddu    $a0, $v0, $zero
/* DCD2D4 80240604 27A40018 */  addiu     $a0, $sp, 0x18
/* DCD2D8 80240608 27A5001C */  addiu     $a1, $sp, 0x1c
/* DCD2DC 8024060C 27A60020 */  addiu     $a2, $sp, 0x20
/* DCD2E0 80240610 27A70024 */  addiu     $a3, $sp, 0x24
/* DCD2E4 80240614 C4400098 */  lwc1      $f0, 0x98($v0)
/* DCD2E8 80240618 C442009C */  lwc1      $f2, 0x9c($v0)
/* DCD2EC 8024061C C44400A0 */  lwc1      $f4, 0xa0($v0)
/* DCD2F0 80240620 3C01447A */  lui       $at, 0x447a
/* DCD2F4 80240624 44813000 */  mtc1      $at, $f6
/* DCD2F8 80240628 27A20028 */  addiu     $v0, $sp, 0x28
/* DCD2FC 8024062C E7A00018 */  swc1      $f0, 0x18($sp)
/* DCD300 80240630 E7A2001C */  swc1      $f2, 0x1c($sp)
/* DCD304 80240634 E7A40020 */  swc1      $f4, 0x20($sp)
/* DCD308 80240638 E7A6002C */  swc1      $f6, 0x2c($sp)
/* DCD30C 8024063C AFA20010 */  sw        $v0, 0x10($sp)
/* DCD310 80240640 27A2002C */  addiu     $v0, $sp, 0x2c
/* DCD314 80240644 0C04497A */  jal       func_801125E8
/* DCD318 80240648 AFA20014 */   sw       $v0, 0x14($sp)
/* DCD31C 8024064C 8FA5002C */  lw        $a1, 0x2c($sp)
/* DCD320 80240650 0C044A17 */  jal       set_standard_shadow_scale
/* DCD324 80240654 0200202D */   daddu    $a0, $s0, $zero
/* DCD328 80240658 26730004 */  addiu     $s3, $s3, 4
/* DCD32C 8024065C C7A00018 */  lwc1      $f0, 0x18($sp)
/* DCD330 80240660 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* DCD334 80240664 C604001C */  lwc1      $f4, 0x1c($s0)
/* DCD338 80240668 2E420004 */  sltiu     $v0, $s2, 4
/* DCD33C 8024066C AE00002C */  sw        $zero, 0x2c($s0)
/* DCD340 80240670 46142102 */  mul.s     $f4, $f4, $f20
/* DCD344 80240674 00000000 */  nop
/* DCD348 80240678 E6000010 */  swc1      $f0, 0x10($s0)
/* DCD34C 8024067C E6020014 */  swc1      $f2, 0x14($s0)
/* DCD350 80240680 C7A60020 */  lwc1      $f6, 0x20($sp)
/* DCD354 80240684 C7A80024 */  lwc1      $f8, 0x24($sp)
/* DCD358 80240688 C6000024 */  lwc1      $f0, 0x24($s0)
/* DCD35C 8024068C C7A20028 */  lwc1      $f2, 0x28($sp)
/* DCD360 80240690 46140002 */  mul.s     $f0, $f0, $f20
/* DCD364 80240694 00000000 */  nop
/* DCD368 80240698 E6060018 */  swc1      $f6, 0x18($s0)
/* DCD36C 8024069C E6080028 */  swc1      $f8, 0x28($s0)
/* DCD370 802406A0 E6020030 */  swc1      $f2, 0x30($s0)
/* DCD374 802406A4 E604001C */  swc1      $f4, 0x1c($s0)
/* DCD378 802406A8 1440FFCD */  bnez      $v0, .L802405E0
/* DCD37C 802406AC E6000024 */   swc1     $f0, 0x24($s0)
/* DCD380 802406B0 8FBF0044 */  lw        $ra, 0x44($sp)
/* DCD384 802406B4 8FB40040 */  lw        $s4, 0x40($sp)
/* DCD388 802406B8 8FB3003C */  lw        $s3, 0x3c($sp)
/* DCD38C 802406BC 8FB20038 */  lw        $s2, 0x38($sp)
/* DCD390 802406C0 8FB10034 */  lw        $s1, 0x34($sp)
/* DCD394 802406C4 8FB00030 */  lw        $s0, 0x30($sp)
/* DCD398 802406C8 D7B40048 */  ldc1      $f20, 0x48($sp)
/* DCD39C 802406CC 0000102D */  daddu     $v0, $zero, $zero
/* DCD3A0 802406D0 03E00008 */  jr        $ra
/* DCD3A4 802406D4 27BD0050 */   addiu    $sp, $sp, 0x50
/* DCD3A8 802406D8 00000000 */  nop
/* DCD3AC 802406DC 00000000 */  nop
