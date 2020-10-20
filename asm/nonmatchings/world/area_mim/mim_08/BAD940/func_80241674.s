.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241674
/* BAEFB4 80241674 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* BAEFB8 80241678 AFB10034 */  sw        $s1, 0x34($sp)
/* BAEFBC 8024167C 0080882D */  daddu     $s1, $a0, $zero
/* BAEFC0 80241680 AFBF0038 */  sw        $ra, 0x38($sp)
/* BAEFC4 80241684 AFB00030 */  sw        $s0, 0x30($sp)
/* BAEFC8 80241688 8E300148 */  lw        $s0, 0x148($s1)
/* BAEFCC 8024168C 0C00EABB */  jal       get_npc_unsafe
/* BAEFD0 80241690 86040008 */   lh       $a0, 8($s0)
/* BAEFD4 80241694 0040282D */  daddu     $a1, $v0, $zero
/* BAEFD8 80241698 94A2008E */  lhu       $v0, 0x8e($a1)
/* BAEFDC 8024169C 2442FFFF */  addiu     $v0, $v0, -1
/* BAEFE0 802416A0 A4A2008E */  sh        $v0, 0x8e($a1)
/* BAEFE4 802416A4 00021400 */  sll       $v0, $v0, 0x10
/* BAEFE8 802416A8 1C400023 */  bgtz      $v0, .L80241738
/* BAEFEC 802416AC 24020004 */   addiu    $v0, $zero, 4
/* BAEFF0 802416B0 8E0300CC */  lw        $v1, 0xcc($s0)
/* BAEFF4 802416B4 AE02006C */  sw        $v0, 0x6c($s0)
/* BAEFF8 802416B8 8C620000 */  lw        $v0, ($v1)
/* BAEFFC 802416BC ACA20028 */  sw        $v0, 0x28($a1)
/* BAF000 802416C0 9602007A */  lhu       $v0, 0x7a($s0)
/* BAF004 802416C4 A4A2008E */  sh        $v0, 0x8e($a1)
/* BAF008 802416C8 8E020078 */  lw        $v0, 0x78($s0)
/* BAF00C 802416CC 28420008 */  slti      $v0, $v0, 8
/* BAF010 802416D0 14400018 */  bnez      $v0, .L80241734
/* BAF014 802416D4 24020021 */   addiu    $v0, $zero, 0x21
/* BAF018 802416D8 24040003 */  addiu     $a0, $zero, 3
/* BAF01C 802416DC 27A30028 */  addiu     $v1, $sp, 0x28
/* BAF020 802416E0 84A700A8 */  lh        $a3, 0xa8($a1)
/* BAF024 802416E4 3C013F80 */  lui       $at, 0x3f80
/* BAF028 802416E8 44810000 */  mtc1      $at, $f0
/* BAF02C 802416EC 3C014000 */  lui       $at, 0x4000
/* BAF030 802416F0 44811000 */  mtc1      $at, $f2
/* BAF034 802416F4 3C01C1A0 */  lui       $at, 0xc1a0
/* BAF038 802416F8 44812000 */  mtc1      $at, $f4
/* BAF03C 802416FC 44873000 */  mtc1      $a3, $f6
/* BAF040 80241700 00000000 */  nop       
/* BAF044 80241704 468031A0 */  cvt.s.w   $f6, $f6
/* BAF048 80241708 E7A00010 */  swc1      $f0, 0x10($sp)
/* BAF04C 8024170C E7A20014 */  swc1      $f2, 0x14($sp)
/* BAF050 80241710 E7A40018 */  swc1      $f4, 0x18($sp)
/* BAF054 80241714 8E020078 */  lw        $v0, 0x78($s0)
/* BAF058 80241718 44073000 */  mfc1      $a3, $f6
/* BAF05C 8024171C 0000302D */  daddu     $a2, $zero, $zero
/* BAF060 80241720 AFA30020 */  sw        $v1, 0x20($sp)
/* BAF064 80241724 2442FFFF */  addiu     $v0, $v0, -1
/* BAF068 80241728 0C01BFA4 */  jal       fx_emote
/* BAF06C 8024172C AFA2001C */   sw       $v0, 0x1c($sp)
/* BAF070 80241730 24020021 */  addiu     $v0, $zero, 0x21
.L80241734:
/* BAF074 80241734 AE220070 */  sw        $v0, 0x70($s1)
.L80241738:
/* BAF078 80241738 8FBF0038 */  lw        $ra, 0x38($sp)
/* BAF07C 8024173C 8FB10034 */  lw        $s1, 0x34($sp)
/* BAF080 80241740 8FB00030 */  lw        $s0, 0x30($sp)
/* BAF084 80241744 03E00008 */  jr        $ra
/* BAF088 80241748 27BD0040 */   addiu    $sp, $sp, 0x40
