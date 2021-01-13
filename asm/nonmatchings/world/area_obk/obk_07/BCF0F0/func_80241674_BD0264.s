.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241674_BD0264
/* BD0264 80241674 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BD0268 80241678 AFB00010 */  sw        $s0, 0x10($sp)
/* BD026C 8024167C 0080802D */  daddu     $s0, $a0, $zero
/* BD0270 80241680 3C05FE36 */  lui       $a1, 0xfe36
/* BD0274 80241684 AFBF0014 */  sw        $ra, 0x14($sp)
/* BD0278 80241688 F7B40018 */  sdc1      $f20, 0x18($sp)
/* BD027C 8024168C 0C0B210B */  jal       get_float_variable
/* BD0280 80241690 34A53C80 */   ori      $a1, $a1, 0x3c80
/* BD0284 80241694 0200202D */  daddu     $a0, $s0, $zero
/* BD0288 80241698 3C05FE36 */  lui       $a1, 0xfe36
/* BD028C 8024169C 34A53C81 */  ori       $a1, $a1, 0x3c81
/* BD0290 802416A0 0C0B210B */  jal       get_float_variable
/* BD0294 802416A4 46000506 */   mov.s    $f20, $f0
/* BD0298 802416A8 3C013F80 */  lui       $at, 0x3f80
/* BD029C 802416AC 44811000 */  mtc1      $at, $f2
/* BD02A0 802416B0 00000000 */  nop
/* BD02A4 802416B4 4602003E */  c.le.s    $f0, $f2
/* BD02A8 802416B8 00000000 */  nop
/* BD02AC 802416BC 45020008 */  bc1fl     .L802416E0
/* BD02B0 802416C0 AE00008C */   sw       $zero, 0x8c($s0)
/* BD02B4 802416C4 4614103E */  c.le.s    $f2, $f20
/* BD02B8 802416C8 00000000 */  nop
/* BD02BC 802416CC 45000003 */  bc1f      .L802416DC
/* BD02C0 802416D0 24020001 */   addiu    $v0, $zero, 1
/* BD02C4 802416D4 080905B8 */  j         .L802416E0
/* BD02C8 802416D8 AE02008C */   sw       $v0, 0x8c($s0)
.L802416DC:
/* BD02CC 802416DC AE00008C */  sw        $zero, 0x8c($s0)
.L802416E0:
/* BD02D0 802416E0 8FBF0014 */  lw        $ra, 0x14($sp)
/* BD02D4 802416E4 8FB00010 */  lw        $s0, 0x10($sp)
/* BD02D8 802416E8 D7B40018 */  ldc1      $f20, 0x18($sp)
/* BD02DC 802416EC 24020002 */  addiu     $v0, $zero, 2
/* BD02E0 802416F0 03E00008 */  jr        $ra
/* BD02E4 802416F4 27BD0020 */   addiu    $sp, $sp, 0x20
