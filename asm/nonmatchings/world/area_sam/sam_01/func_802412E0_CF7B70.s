.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412E0_CF8E50
/* CF8E50 802412E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CF8E54 802412E4 AFB10014 */  sw        $s1, 0x14($sp)
/* CF8E58 802412E8 0080882D */  daddu     $s1, $a0, $zero
/* CF8E5C 802412EC AFBF0018 */  sw        $ra, 0x18($sp)
/* CF8E60 802412F0 AFB00010 */  sw        $s0, 0x10($sp)
/* CF8E64 802412F4 8E30000C */  lw        $s0, 0xc($s1)
/* CF8E68 802412F8 8E050000 */  lw        $a1, ($s0)
/* CF8E6C 802412FC 0C0B1EAF */  jal       get_variable
/* CF8E70 80241300 26100004 */   addiu    $s0, $s0, 4
/* CF8E74 80241304 00021880 */  sll       $v1, $v0, 2
/* CF8E78 80241308 00621821 */  addu      $v1, $v1, $v0
/* CF8E7C 8024130C 00031880 */  sll       $v1, $v1, 2
/* CF8E80 80241310 00621823 */  subu      $v1, $v1, $v0
/* CF8E84 80241314 000310C0 */  sll       $v0, $v1, 3
/* CF8E88 80241318 00621821 */  addu      $v1, $v1, $v0
/* CF8E8C 8024131C 000318C0 */  sll       $v1, $v1, 3
/* CF8E90 80241320 3C01800B */  lui       $at, 0x800b
/* CF8E94 80241324 00230821 */  addu      $at, $at, $v1
/* CF8E98 80241328 C4221D98 */  lwc1      $f2, 0x1d98($at)
/* CF8E9C 8024132C 3C014480 */  lui       $at, 0x4480
/* CF8EA0 80241330 44810000 */  mtc1      $at, $f0
/* CF8EA4 80241334 00000000 */  nop       
/* CF8EA8 80241338 46001082 */  mul.s     $f2, $f2, $f0
/* CF8EAC 8024133C 00000000 */  nop       
/* CF8EB0 80241340 3C01CD5B */  lui       $at, 0xcd5b
/* CF8EB4 80241344 34215858 */  ori       $at, $at, 0x5858
/* CF8EB8 80241348 44810000 */  mtc1      $at, $f0
/* CF8EBC 8024134C 00000000 */  nop       
/* CF8EC0 80241350 46001080 */  add.s     $f2, $f2, $f0
/* CF8EC4 80241354 8E050000 */  lw        $a1, ($s0)
/* CF8EC8 80241358 4600110D */  trunc.w.s $f4, $f2
/* CF8ECC 8024135C 44062000 */  mfc1      $a2, $f4
/* CF8ED0 80241360 0C0B2026 */  jal       set_variable
/* CF8ED4 80241364 0220202D */   daddu    $a0, $s1, $zero
/* CF8ED8 80241368 8FBF0018 */  lw        $ra, 0x18($sp)
/* CF8EDC 8024136C 8FB10014 */  lw        $s1, 0x14($sp)
/* CF8EE0 80241370 8FB00010 */  lw        $s0, 0x10($sp)
/* CF8EE4 80241374 24020002 */  addiu     $v0, $zero, 2
/* CF8EE8 80241378 03E00008 */  jr        $ra
/* CF8EEC 8024137C 27BD0020 */   addiu    $sp, $sp, 0x20
