.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024277C_B3734C
/* B3734C 8024277C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B37350 80242780 AFB10014 */  sw        $s1, 0x14($sp)
/* B37354 80242784 0080882D */  daddu     $s1, $a0, $zero
/* B37358 80242788 AFBF0018 */  sw        $ra, 0x18($sp)
/* B3735C 8024278C AFB00010 */  sw        $s0, 0x10($sp)
/* B37360 80242790 8E30000C */  lw        $s0, 0xc($s1)
/* B37364 80242794 8E050000 */  lw        $a1, ($s0)
/* B37368 80242798 0C0B1EAF */  jal       get_variable
/* B3736C 8024279C 26100004 */   addiu    $s0, $s0, 4
/* B37370 802427A0 00021880 */  sll       $v1, $v0, 2
/* B37374 802427A4 00621821 */  addu      $v1, $v1, $v0
/* B37378 802427A8 00031880 */  sll       $v1, $v1, 2
/* B3737C 802427AC 00621823 */  subu      $v1, $v1, $v0
/* B37380 802427B0 000310C0 */  sll       $v0, $v1, 3
/* B37384 802427B4 00621821 */  addu      $v1, $v1, $v0
/* B37388 802427B8 000318C0 */  sll       $v1, $v1, 3
/* B3738C 802427BC 3C01800B */  lui       $at, 0x800b
/* B37390 802427C0 00230821 */  addu      $at, $at, $v1
/* B37394 802427C4 C4221D98 */  lwc1      $f2, 0x1d98($at)
/* B37398 802427C8 3C014480 */  lui       $at, 0x4480
/* B3739C 802427CC 44810000 */  mtc1      $at, $f0
/* B373A0 802427D0 00000000 */  nop       
/* B373A4 802427D4 46001082 */  mul.s     $f2, $f2, $f0
/* B373A8 802427D8 00000000 */  nop       
/* B373AC 802427DC 3C01CD5B */  lui       $at, 0xcd5b
/* B373B0 802427E0 34215858 */  ori       $at, $at, 0x5858
/* B373B4 802427E4 44810000 */  mtc1      $at, $f0
/* B373B8 802427E8 00000000 */  nop       
/* B373BC 802427EC 46001080 */  add.s     $f2, $f2, $f0
/* B373C0 802427F0 8E050000 */  lw        $a1, ($s0)
/* B373C4 802427F4 4600110D */  trunc.w.s $f4, $f2
/* B373C8 802427F8 44062000 */  mfc1      $a2, $f4
/* B373CC 802427FC 0C0B2026 */  jal       set_variable
/* B373D0 80242800 0220202D */   daddu    $a0, $s1, $zero
/* B373D4 80242804 8FBF0018 */  lw        $ra, 0x18($sp)
/* B373D8 80242808 8FB10014 */  lw        $s1, 0x14($sp)
/* B373DC 8024280C 8FB00010 */  lw        $s0, 0x10($sp)
/* B373E0 80242810 24020002 */  addiu     $v0, $zero, 2
/* B373E4 80242814 03E00008 */  jr        $ra
/* B373E8 80242818 27BD0020 */   addiu    $sp, $sp, 0x20
