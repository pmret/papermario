.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241530_D6FEE0
/* D6FEE0 80241530 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D6FEE4 80241534 24040005 */  addiu     $a0, $zero, 5
/* D6FEE8 80241538 AFBF0048 */  sw        $ra, 0x48($sp)
/* D6FEEC 8024153C AFB10044 */  sw        $s1, 0x44($sp)
/* D6FEF0 80241540 0C00EAD2 */  jal       get_npc_safe
/* D6FEF4 80241544 AFB00040 */   sw       $s0, 0x40($sp)
/* D6FEF8 80241548 3C03800F */  lui       $v1, %hi(gPlayerStatusPtr)
/* D6FEFC 8024154C 8C637B30 */  lw        $v1, %lo(gPlayerStatusPtr)($v1)
/* D6FF00 80241550 27B10020 */  addiu     $s1, $sp, 0x20
/* D6FF04 80241554 8C630000 */  lw        $v1, ($v1)
/* D6FF08 80241558 30630001 */  andi      $v1, $v1, 1
/* D6FF0C 8024155C 1060001B */  beqz      $v1, .L802415CC
/* D6FF10 80241560 0040802D */   daddu    $s0, $v0, $zero
/* D6FF14 80241564 C6000040 */  lwc1      $f0, 0x40($s0)
/* D6FF18 80241568 3C04800A */  lui       $a0, %hi(D_8009A634)
/* D6FF1C 8024156C 8484A634 */  lh        $a0, %lo(D_8009A634)($a0)
/* D6FF20 80241570 27A20030 */  addiu     $v0, $sp, 0x30
/* D6FF24 80241574 AFA20010 */  sw        $v0, 0x10($sp)
/* D6FF28 80241578 27A20034 */  addiu     $v0, $sp, 0x34
/* D6FF2C 8024157C AFA20014 */  sw        $v0, 0x14($sp)
/* D6FF30 80241580 27A20038 */  addiu     $v0, $sp, 0x38
/* D6FF34 80241584 AFA20018 */  sw        $v0, 0x18($sp)
/* D6FF38 80241588 8E050038 */  lw        $a1, 0x38($s0)
/* D6FF3C 8024158C 8E06003C */  lw        $a2, 0x3c($s0)
/* D6FF40 80241590 46000007 */  neg.s     $f0, $f0
/* D6FF44 80241594 44070000 */  mfc1      $a3, $f0
/* D6FF48 80241598 0C00B94E */  jal       get_screen_coords
/* D6FF4C 8024159C 00000000 */   nop      
/* D6FF50 802415A0 0220202D */  daddu     $a0, $s1, $zero
/* D6FF54 802415A4 820500AA */  lb        $a1, 0xaa($s0)
/* D6FF58 802415A8 8FA30038 */  lw        $v1, 0x38($sp)
/* D6FF5C 802415AC 3C028024 */  lui       $v0, %hi(func_802415E0_D6EA80)
/* D6FF60 802415B0 244215E0 */  addiu     $v0, $v0, %lo(func_802415E0_D6EA80)
/* D6FF64 802415B4 AFB00028 */  sw        $s0, 0x28($sp)
/* D6FF68 802415B8 AFA2002C */  sw        $v0, 0x2c($sp)
/* D6FF6C 802415BC 00031823 */  negu      $v1, $v1
/* D6FF70 802415C0 AFA50020 */  sw        $a1, 0x20($sp)
/* D6FF74 802415C4 0C047644 */  jal       queue_render_task
/* D6FF78 802415C8 AFA30024 */   sw       $v1, 0x24($sp)
.L802415CC:
/* D6FF7C 802415CC 8FBF0048 */  lw        $ra, 0x48($sp)
/* D6FF80 802415D0 8FB10044 */  lw        $s1, 0x44($sp)
/* D6FF84 802415D4 8FB00040 */  lw        $s0, 0x40($sp)
/* D6FF88 802415D8 03E00008 */  jr        $ra
/* D6FF8C 802415DC 27BD0050 */   addiu    $sp, $sp, 0x50
