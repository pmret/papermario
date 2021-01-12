.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218580_6DE340
/* 6DE340 80218580 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6DE344 80218584 AFB00010 */  sw        $s0, 0x10($sp)
/* 6DE348 80218588 0080802D */  daddu     $s0, $a0, $zero
/* 6DE34C 8021858C AFBF0014 */  sw        $ra, 0x14($sp)
/* 6DE350 80218590 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 6DE354 80218594 8E0400AC */   lw       $a0, 0xac($s0)
/* 6DE358 80218598 0C046B4C */  jal       get_model_from_list_index
/* 6DE35C 8021859C 0040202D */   daddu    $a0, $v0, $zero
/* 6DE360 802185A0 C4400098 */  lwc1      $f0, 0x98($v0)
/* 6DE364 802185A4 4600008D */  trunc.w.s $f2, $f0
/* 6DE368 802185A8 E60200B0 */  swc1      $f2, 0xb0($s0)
/* 6DE36C 802185AC C440009C */  lwc1      $f0, 0x9c($v0)
/* 6DE370 802185B0 4600008D */  trunc.w.s $f2, $f0
/* 6DE374 802185B4 E60200B4 */  swc1      $f2, 0xb4($s0)
/* 6DE378 802185B8 C44000A0 */  lwc1      $f0, 0xa0($v0)
/* 6DE37C 802185BC 4600008D */  trunc.w.s $f2, $f0
/* 6DE380 802185C0 E60200B8 */  swc1      $f2, 0xb8($s0)
/* 6DE384 802185C4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6DE388 802185C8 8FB00010 */  lw        $s0, 0x10($sp)
/* 6DE38C 802185CC 24020002 */  addiu     $v0, $zero, 2
/* 6DE390 802185D0 03E00008 */  jr        $ra
/* 6DE394 802185D4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 6DE398 802185D8 00000000 */  nop
/* 6DE39C 802185DC 00000000 */  nop
