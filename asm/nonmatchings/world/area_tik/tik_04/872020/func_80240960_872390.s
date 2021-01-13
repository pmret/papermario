.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240960_872390
/* 872390 80240960 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 872394 80240964 AFB00010 */  sw        $s0, 0x10($sp)
/* 872398 80240968 0080802D */  daddu     $s0, $a0, $zero
/* 87239C 8024096C AFBF0014 */  sw        $ra, 0x14($sp)
/* 8723A0 80240970 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 8723A4 80240974 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 8723A8 80240978 24040012 */   addiu    $a0, $zero, 0x12
/* 8723AC 8024097C 0C046B4C */  jal       get_model_from_list_index
/* 8723B0 80240980 0040202D */   daddu    $a0, $v0, $zero
/* 8723B4 80240984 C440009C */  lwc1      $f0, 0x9c($v0)
/* 8723B8 80240988 3C0142C8 */  lui       $at, 0x42c8
/* 8723BC 8024098C 4481A000 */  mtc1      $at, $f20
/* 8723C0 80240990 00000000 */  nop
/* 8723C4 80240994 46140001 */  sub.s     $f0, $f0, $f20
/* 8723C8 80240998 8C450098 */  lw        $a1, 0x98($v0)
/* 8723CC 8024099C 8C4700A0 */  lw        $a3, 0xa0($v0)
/* 8723D0 802409A0 44060000 */  mfc1      $a2, $f0
/* 8723D4 802409A4 0C044898 */  jal       create_shadow_type
/* 8723D8 802409A8 24040001 */   addiu    $a0, $zero, 1
/* 8723DC 802409AC 8E03013C */  lw        $v1, 0x13c($s0)
/* 8723E0 802409B0 24040014 */  addiu     $a0, $zero, 0x14
/* 8723E4 802409B4 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 8723E8 802409B8 AC620000 */   sw       $v0, ($v1)
/* 8723EC 802409BC 0C046B4C */  jal       get_model_from_list_index
/* 8723F0 802409C0 0040202D */   daddu    $a0, $v0, $zero
/* 8723F4 802409C4 C440009C */  lwc1      $f0, 0x9c($v0)
/* 8723F8 802409C8 46140001 */  sub.s     $f0, $f0, $f20
/* 8723FC 802409CC 8C450098 */  lw        $a1, 0x98($v0)
/* 872400 802409D0 8C4700A0 */  lw        $a3, 0xa0($v0)
/* 872404 802409D4 44060000 */  mfc1      $a2, $f0
/* 872408 802409D8 0C044898 */  jal       create_shadow_type
/* 87240C 802409DC 24040001 */   addiu    $a0, $zero, 1
/* 872410 802409E0 8E03013C */  lw        $v1, 0x13c($s0)
/* 872414 802409E4 AC620004 */  sw        $v0, 4($v1)
/* 872418 802409E8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 87241C 802409EC 8FB00010 */  lw        $s0, 0x10($sp)
/* 872420 802409F0 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 872424 802409F4 24020002 */  addiu     $v0, $zero, 2
/* 872428 802409F8 03E00008 */  jr        $ra
/* 87242C 802409FC 27BD0020 */   addiu    $sp, $sp, 0x20
