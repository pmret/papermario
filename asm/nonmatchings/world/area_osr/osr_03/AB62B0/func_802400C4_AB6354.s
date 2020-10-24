.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400C4_AB6354
/* AB6354 802400C4 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* AB6358 802400C8 AFB10014 */  sw        $s1, 0x14($sp)
/* AB635C 802400CC 0080882D */  daddu     $s1, $a0, $zero
/* AB6360 802400D0 AFBF001C */  sw        $ra, 0x1c($sp)
/* AB6364 802400D4 AFB20018 */  sw        $s2, 0x18($sp)
/* AB6368 802400D8 AFB00010 */  sw        $s0, 0x10($sp)
/* AB636C 802400DC F7B60028 */  sdc1      $f22, 0x28($sp)
/* AB6370 802400E0 F7B40020 */  sdc1      $f20, 0x20($sp)
/* AB6374 802400E4 0C00EABB */  jal       get_npc_unsafe
/* AB6378 802400E8 0000202D */   daddu    $a0, $zero, $zero
/* AB637C 802400EC 0040802D */  daddu     $s0, $v0, $zero
/* AB6380 802400F0 3C12800B */  lui       $s2, %hi(gCameras)
/* AB6384 802400F4 26521D80 */  addiu     $s2, $s2, %lo(gCameras)
/* AB6388 802400F8 C60C000C */  lwc1      $f12, 0xc($s0)
/* AB638C 802400FC C640006C */  lwc1      $f0, 0x6c($s2)
/* AB6390 80240100 46006300 */  add.s     $f12, $f12, $f0
/* AB6394 80240104 3C014334 */  lui       $at, 0x4334
/* AB6398 80240108 4481A000 */  mtc1      $at, $f20
/* AB639C 8024010C 3C0141A0 */  lui       $at, 0x41a0
/* AB63A0 80240110 4481B000 */  mtc1      $at, $f22
/* AB63A4 80240114 0C00A8BB */  jal       sin_deg
/* AB63A8 80240118 46146300 */   add.s    $f12, $f12, $f20
/* AB63AC 8024011C 46160002 */  mul.s     $f0, $f0, $f22
/* AB63B0 80240120 00000000 */  nop       
/* AB63B4 80240124 C6020038 */  lwc1      $f2, 0x38($s0)
/* AB63B8 80240128 46001080 */  add.s     $f2, $f2, $f0
/* AB63BC 8024012C 4600110D */  trunc.w.s $f4, $f2
/* AB63C0 80240130 E6240084 */  swc1      $f4, 0x84($s1)
/* AB63C4 80240134 C600003C */  lwc1      $f0, 0x3c($s0)
/* AB63C8 80240138 3C014190 */  lui       $at, 0x4190
/* AB63CC 8024013C 44811000 */  mtc1      $at, $f2
/* AB63D0 80240140 00000000 */  nop       
/* AB63D4 80240144 46020000 */  add.s     $f0, $f0, $f2
/* AB63D8 80240148 4600010D */  trunc.w.s $f4, $f0
/* AB63DC 8024014C E6240088 */  swc1      $f4, 0x88($s1)
/* AB63E0 80240150 C60C000C */  lwc1      $f12, 0xc($s0)
/* AB63E4 80240154 C640006C */  lwc1      $f0, 0x6c($s2)
/* AB63E8 80240158 46006300 */  add.s     $f12, $f12, $f0
/* AB63EC 8024015C 0C00A8D4 */  jal       cos_deg
/* AB63F0 80240160 46146300 */   add.s    $f12, $f12, $f20
/* AB63F4 80240164 46160002 */  mul.s     $f0, $f0, $f22
/* AB63F8 80240168 00000000 */  nop       
/* AB63FC 8024016C C6020040 */  lwc1      $f2, 0x40($s0)
/* AB6400 80240170 46001081 */  sub.s     $f2, $f2, $f0
/* AB6404 80240174 4600110D */  trunc.w.s $f4, $f2
/* AB6408 80240178 E624008C */  swc1      $f4, 0x8c($s1)
/* AB640C 8024017C 8FBF001C */  lw        $ra, 0x1c($sp)
/* AB6410 80240180 8FB20018 */  lw        $s2, 0x18($sp)
/* AB6414 80240184 8FB10014 */  lw        $s1, 0x14($sp)
/* AB6418 80240188 8FB00010 */  lw        $s0, 0x10($sp)
/* AB641C 8024018C D7B60028 */  ldc1      $f22, 0x28($sp)
/* AB6420 80240190 D7B40020 */  ldc1      $f20, 0x20($sp)
/* AB6424 80240194 24020002 */  addiu     $v0, $zero, 2
/* AB6428 80240198 03E00008 */  jr        $ra
/* AB642C 8024019C 27BD0030 */   addiu    $sp, $sp, 0x30
