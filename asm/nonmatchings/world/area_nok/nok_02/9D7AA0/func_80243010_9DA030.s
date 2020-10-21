.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243010_9DA030
/* 9DA030 80243010 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 9DA034 80243014 AFB10014 */  sw        $s1, 0x14($sp)
/* 9DA038 80243018 0080882D */  daddu     $s1, $a0, $zero
/* 9DA03C 8024301C AFBF0018 */  sw        $ra, 0x18($sp)
/* 9DA040 80243020 AFB00010 */  sw        $s0, 0x10($sp)
/* 9DA044 80243024 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 9DA048 80243028 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 9DA04C 8024302C 8E30000C */  lw        $s0, 0xc($s1)
/* 9DA050 80243030 8E050000 */  lw        $a1, ($s0)
/* 9DA054 80243034 0C0B1EAF */  jal       get_variable
/* 9DA058 80243038 26100004 */   addiu    $s0, $s0, 4
/* 9DA05C 8024303C 8E050000 */  lw        $a1, ($s0)
/* 9DA060 80243040 26100004 */  addiu     $s0, $s0, 4
/* 9DA064 80243044 4482B000 */  mtc1      $v0, $f22
/* 9DA068 80243048 00000000 */  nop       
/* 9DA06C 8024304C 4680B5A0 */  cvt.s.w   $f22, $f22
/* 9DA070 80243050 0C0B1EAF */  jal       get_variable
/* 9DA074 80243054 0220202D */   daddu    $a0, $s1, $zero
/* 9DA078 80243058 8E050000 */  lw        $a1, ($s0)
/* 9DA07C 8024305C 4482A000 */  mtc1      $v0, $f20
/* 9DA080 80243060 00000000 */  nop       
/* 9DA084 80243064 4680A520 */  cvt.s.w   $f20, $f20
/* 9DA088 80243068 0C0B1EAF */  jal       get_variable
/* 9DA08C 8024306C 0220202D */   daddu    $a0, $s1, $zero
/* 9DA090 80243070 3C014170 */  lui       $at, 0x4170
/* 9DA094 80243074 44810000 */  mtc1      $at, $f0
/* 9DA098 80243078 44821000 */  mtc1      $v0, $f2
/* 9DA09C 8024307C 00000000 */  nop       
/* 9DA0A0 80243080 468010A0 */  cvt.s.w   $f2, $f2
/* 9DA0A4 80243084 4600A500 */  add.s     $f20, $f20, $f0
/* 9DA0A8 80243088 4405B000 */  mfc1      $a1, $f22
/* 9DA0AC 8024308C 44071000 */  mfc1      $a3, $f2
/* 9DA0B0 80243090 4406A000 */  mfc1      $a2, $f20
/* 9DA0B4 80243094 0C01C07C */  jal       func_800701F0
/* 9DA0B8 80243098 0000202D */   daddu    $a0, $zero, $zero
/* 9DA0BC 8024309C 0000202D */  daddu     $a0, $zero, $zero
/* 9DA0C0 802430A0 0080282D */  daddu     $a1, $a0, $zero
/* 9DA0C4 802430A4 0C0B2D5B */  jal       exec_ShakeCam1
/* 9DA0C8 802430A8 24060014 */   addiu    $a2, $zero, 0x14
/* 9DA0CC 802430AC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9DA0D0 802430B0 8FB10014 */  lw        $s1, 0x14($sp)
/* 9DA0D4 802430B4 8FB00010 */  lw        $s0, 0x10($sp)
/* 9DA0D8 802430B8 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 9DA0DC 802430BC D7B40020 */  ldc1      $f20, 0x20($sp)
/* 9DA0E0 802430C0 24020002 */  addiu     $v0, $zero, 2
/* 9DA0E4 802430C4 03E00008 */  jr        $ra
/* 9DA0E8 802430C8 27BD0030 */   addiu    $sp, $sp, 0x30
