.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F4_B1CD44
/* B1CD44 802402F4 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* B1CD48 802402F8 AFB00040 */  sw        $s0, 0x40($sp)
/* B1CD4C 802402FC 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* B1CD50 80240300 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* B1CD54 80240304 AFBF0048 */  sw        $ra, 0x48($sp)
/* B1CD58 80240308 AFB10044 */  sw        $s1, 0x44($sp)
/* B1CD5C 8024030C 8E020000 */  lw        $v0, ($s0)
/* B1CD60 80240310 30420001 */  andi      $v0, $v0, 1
/* B1CD64 80240314 10400023 */  beqz      $v0, .L802403A4
/* B1CD68 80240318 27B10020 */   addiu    $s1, $sp, 0x20
/* B1CD6C 8024031C 8E0400CC */  lw        $a0, 0xcc($s0)
/* B1CD70 80240320 0C044181 */  jal       get_shadow_by_index
/* B1CD74 80240324 00000000 */   nop      
/* B1CD78 80240328 0C048B77 */  jal       func_80122DDC
/* B1CD7C 8024032C 84440008 */   lh       $a0, 8($v0)
/* B1CD80 80240330 8C430000 */  lw        $v1, ($v0)
/* B1CD84 80240334 3C04800A */  lui       $a0, 0x800a
/* B1CD88 80240338 8484A634 */  lh        $a0, -0x59cc($a0)
/* B1CD8C 8024033C 34630200 */  ori       $v1, $v1, 0x200
/* B1CD90 80240340 AC430000 */  sw        $v1, ($v0)
/* B1CD94 80240344 27A20030 */  addiu     $v0, $sp, 0x30
/* B1CD98 80240348 AFA20010 */  sw        $v0, 0x10($sp)
/* B1CD9C 8024034C 27A20034 */  addiu     $v0, $sp, 0x34
/* B1CDA0 80240350 AFA20014 */  sw        $v0, 0x14($sp)
/* B1CDA4 80240354 27A20038 */  addiu     $v0, $sp, 0x38
/* B1CDA8 80240358 AFA20018 */  sw        $v0, 0x18($sp)
/* B1CDAC 8024035C C600002C */  lwc1      $f0, 0x2c($s0)
/* B1CDB0 80240360 8E050028 */  lw        $a1, 0x28($s0)
/* B1CDB4 80240364 8E070030 */  lw        $a3, 0x30($s0)
/* B1CDB8 80240368 46000007 */  neg.s     $f0, $f0
/* B1CDBC 8024036C 44060000 */  mfc1      $a2, $f0
/* B1CDC0 80240370 0C00B94E */  jal       get_screen_coords
/* B1CDC4 80240374 00000000 */   nop      
/* B1CDC8 80240378 0220202D */  daddu     $a0, $s1, $zero
/* B1CDCC 8024037C AFB00028 */  sw        $s0, 0x28($sp)
/* B1CDD0 80240380 820500BE */  lb        $a1, 0xbe($s0)
/* B1CDD4 80240384 8FA30038 */  lw        $v1, 0x38($sp)
/* B1CDD8 80240388 3C028024 */  lui       $v0, 0x8024
/* B1CDDC 8024038C 244203B8 */  addiu     $v0, $v0, 0x3b8
/* B1CDE0 80240390 AFA2002C */  sw        $v0, 0x2c($sp)
/* B1CDE4 80240394 00031823 */  negu      $v1, $v1
/* B1CDE8 80240398 AFA50020 */  sw        $a1, 0x20($sp)
/* B1CDEC 8024039C 0C047644 */  jal       queue_render_task
/* B1CDF0 802403A0 AFA30024 */   sw       $v1, 0x24($sp)
.L802403A4:
/* B1CDF4 802403A4 8FBF0048 */  lw        $ra, 0x48($sp)
/* B1CDF8 802403A8 8FB10044 */  lw        $s1, 0x44($sp)
/* B1CDFC 802403AC 8FB00040 */  lw        $s0, 0x40($sp)
/* B1CE00 802403B0 03E00008 */  jr        $ra
/* B1CE04 802403B4 27BD0050 */   addiu    $sp, $sp, 0x50
