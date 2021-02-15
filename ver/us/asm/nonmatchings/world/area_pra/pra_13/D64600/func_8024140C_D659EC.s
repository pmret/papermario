.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024140C_D659EC
/* D659EC 8024140C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D659F0 80241410 0000202D */  daddu     $a0, $zero, $zero
/* D659F4 80241414 AFBF0048 */  sw        $ra, 0x48($sp)
/* D659F8 80241418 AFB10044 */  sw        $s1, 0x44($sp)
/* D659FC 8024141C 0C00EAD2 */  jal       get_npc_safe
/* D65A00 80241420 AFB00040 */   sw       $s0, 0x40($sp)
/* D65A04 80241424 3C03800F */  lui       $v1, %hi(gPlayerStatusPtr)
/* D65A08 80241428 8C637B30 */  lw        $v1, %lo(gPlayerStatusPtr)($v1)
/* D65A0C 8024142C 27B10020 */  addiu     $s1, $sp, 0x20
/* D65A10 80241430 8C630000 */  lw        $v1, ($v1)
/* D65A14 80241434 30630001 */  andi      $v1, $v1, 1
/* D65A18 80241438 1060001B */  beqz      $v1, .L802414A8
/* D65A1C 8024143C 0040802D */   daddu    $s0, $v0, $zero
/* D65A20 80241440 C6000040 */  lwc1      $f0, 0x40($s0)
/* D65A24 80241444 3C04800A */  lui       $a0, %hi(D_8009A634)
/* D65A28 80241448 8484A634 */  lh        $a0, %lo(D_8009A634)($a0)
/* D65A2C 8024144C 27A20030 */  addiu     $v0, $sp, 0x30
/* D65A30 80241450 AFA20010 */  sw        $v0, 0x10($sp)
/* D65A34 80241454 27A20034 */  addiu     $v0, $sp, 0x34
/* D65A38 80241458 AFA20014 */  sw        $v0, 0x14($sp)
/* D65A3C 8024145C 27A20038 */  addiu     $v0, $sp, 0x38
/* D65A40 80241460 AFA20018 */  sw        $v0, 0x18($sp)
/* D65A44 80241464 8E050038 */  lw        $a1, 0x38($s0)
/* D65A48 80241468 8E06003C */  lw        $a2, 0x3c($s0)
/* D65A4C 8024146C 46000007 */  neg.s     $f0, $f0
/* D65A50 80241470 44070000 */  mfc1      $a3, $f0
/* D65A54 80241474 0C00B94E */  jal       get_screen_coords
/* D65A58 80241478 00000000 */   nop
/* D65A5C 8024147C 0220202D */  daddu     $a0, $s1, $zero
/* D65A60 80241480 820500AA */  lb        $a1, 0xaa($s0)
/* D65A64 80241484 8FA30038 */  lw        $v1, 0x38($sp)
/* D65A68 80241488 3C028024 */  lui       $v0, %hi(func_802414BC_D65A9C)
/* D65A6C 8024148C 244214BC */  addiu     $v0, $v0, %lo(func_802414BC_D65A9C)
/* D65A70 80241490 AFB00028 */  sw        $s0, 0x28($sp)
/* D65A74 80241494 AFA2002C */  sw        $v0, 0x2c($sp)
/* D65A78 80241498 00031823 */  negu      $v1, $v1
/* D65A7C 8024149C AFA50020 */  sw        $a1, 0x20($sp)
/* D65A80 802414A0 0C047644 */  jal       queue_render_task
/* D65A84 802414A4 AFA30024 */   sw       $v1, 0x24($sp)
.L802414A8:
/* D65A88 802414A8 8FBF0048 */  lw        $ra, 0x48($sp)
/* D65A8C 802414AC 8FB10044 */  lw        $s1, 0x44($sp)
/* D65A90 802414B0 8FB00040 */  lw        $s0, 0x40($sp)
/* D65A94 802414B4 03E00008 */  jr        $ra
/* D65A98 802414B8 27BD0050 */   addiu    $sp, $sp, 0x50
