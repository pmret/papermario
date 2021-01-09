.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024003C_B1CA8C
/* B1CA8C 8024003C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* B1CA90 80240040 AFB00040 */  sw        $s0, 0x40($sp)
/* B1CA94 80240044 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* B1CA98 80240048 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* B1CA9C 8024004C AFBF0048 */  sw        $ra, 0x48($sp)
/* B1CAA0 80240050 AFB10044 */  sw        $s1, 0x44($sp)
/* B1CAA4 80240054 8E020000 */  lw        $v0, ($s0)
/* B1CAA8 80240058 30420001 */  andi      $v0, $v0, 1
/* B1CAAC 8024005C 10400023 */  beqz      $v0, .L802400EC
/* B1CAB0 80240060 27B10020 */   addiu    $s1, $sp, 0x20
/* B1CAB4 80240064 8E0400CC */  lw        $a0, 0xcc($s0)
/* B1CAB8 80240068 0C044181 */  jal       get_shadow_by_index
/* B1CABC 8024006C 00000000 */   nop      
/* B1CAC0 80240070 0C048B77 */  jal       func_80122DDC
/* B1CAC4 80240074 84440008 */   lh       $a0, 8($v0)
/* B1CAC8 80240078 8C430000 */  lw        $v1, ($v0)
/* B1CACC 8024007C 3C04800A */  lui       $a0, %hi(D_8009A634)
/* B1CAD0 80240080 8484A634 */  lh        $a0, %lo(D_8009A634)($a0)
/* B1CAD4 80240084 34630200 */  ori       $v1, $v1, 0x200
/* B1CAD8 80240088 AC430000 */  sw        $v1, ($v0)
/* B1CADC 8024008C 27A20030 */  addiu     $v0, $sp, 0x30
/* B1CAE0 80240090 AFA20010 */  sw        $v0, 0x10($sp)
/* B1CAE4 80240094 27A20034 */  addiu     $v0, $sp, 0x34
/* B1CAE8 80240098 AFA20014 */  sw        $v0, 0x14($sp)
/* B1CAEC 8024009C 27A20038 */  addiu     $v0, $sp, 0x38
/* B1CAF0 802400A0 AFA20018 */  sw        $v0, 0x18($sp)
/* B1CAF4 802400A4 C6000030 */  lwc1      $f0, 0x30($s0)
/* B1CAF8 802400A8 8E050028 */  lw        $a1, 0x28($s0)
/* B1CAFC 802400AC 8E06002C */  lw        $a2, 0x2c($s0)
/* B1CB00 802400B0 46000007 */  neg.s     $f0, $f0
/* B1CB04 802400B4 44070000 */  mfc1      $a3, $f0
/* B1CB08 802400B8 0C00B94E */  jal       get_screen_coords
/* B1CB0C 802400BC 00000000 */   nop      
/* B1CB10 802400C0 0220202D */  daddu     $a0, $s1, $zero
/* B1CB14 802400C4 AFB00028 */  sw        $s0, 0x28($sp)
/* B1CB18 802400C8 820500BE */  lb        $a1, 0xbe($s0)
/* B1CB1C 802400CC 8FA30038 */  lw        $v1, 0x38($sp)
/* B1CB20 802400D0 3C028024 */  lui       $v0, %hi(func_80240100_B1CB50)
/* B1CB24 802400D4 24420100 */  addiu     $v0, $v0, %lo(func_80240100_B1CB50)
/* B1CB28 802400D8 AFA2002C */  sw        $v0, 0x2c($sp)
/* B1CB2C 802400DC 00031823 */  negu      $v1, $v1
/* B1CB30 802400E0 AFA50020 */  sw        $a1, 0x20($sp)
/* B1CB34 802400E4 0C047644 */  jal       queue_render_task
/* B1CB38 802400E8 AFA30024 */   sw       $v1, 0x24($sp)
.L802400EC:
/* B1CB3C 802400EC 8FBF0048 */  lw        $ra, 0x48($sp)
/* B1CB40 802400F0 8FB10044 */  lw        $s1, 0x44($sp)
/* B1CB44 802400F4 8FB00040 */  lw        $s0, 0x40($sp)
/* B1CB48 802400F8 03E00008 */  jr        $ra
/* B1CB4C 802400FC 27BD0050 */   addiu    $sp, $sp, 0x50
