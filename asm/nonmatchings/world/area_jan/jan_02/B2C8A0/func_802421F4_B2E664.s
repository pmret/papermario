.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802421F4_B2E664
/* B2E664 802421F4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B2E668 802421F8 AFB10014 */  sw        $s1, 0x14($sp)
/* B2E66C 802421FC 0080882D */  daddu     $s1, $a0, $zero
/* B2E670 80242200 AFBF0018 */  sw        $ra, 0x18($sp)
/* B2E674 80242204 AFB00010 */  sw        $s0, 0x10($sp)
/* B2E678 80242208 8E30000C */  lw        $s0, 0xc($s1)
/* B2E67C 8024220C 8E050000 */  lw        $a1, ($s0)
/* B2E680 80242210 0C0B1EAF */  jal       get_variable
/* B2E684 80242214 26100004 */   addiu    $s0, $s0, 4
/* B2E688 80242218 00021880 */  sll       $v1, $v0, 2
/* B2E68C 8024221C 00621821 */  addu      $v1, $v1, $v0
/* B2E690 80242220 00031880 */  sll       $v1, $v1, 2
/* B2E694 80242224 00621823 */  subu      $v1, $v1, $v0
/* B2E698 80242228 000310C0 */  sll       $v0, $v1, 3
/* B2E69C 8024222C 00621821 */  addu      $v1, $v1, $v0
/* B2E6A0 80242230 000318C0 */  sll       $v1, $v1, 3
/* B2E6A4 80242234 3C01800B */  lui       $at, 0x800b
/* B2E6A8 80242238 00230821 */  addu      $at, $at, $v1
/* B2E6AC 8024223C C4221D98 */  lwc1      $f2, 0x1d98($at)
/* B2E6B0 80242240 3C014480 */  lui       $at, 0x4480
/* B2E6B4 80242244 44810000 */  mtc1      $at, $f0
/* B2E6B8 80242248 00000000 */  nop       
/* B2E6BC 8024224C 46001082 */  mul.s     $f2, $f2, $f0
/* B2E6C0 80242250 00000000 */  nop       
/* B2E6C4 80242254 3C01CD5B */  lui       $at, 0xcd5b
/* B2E6C8 80242258 34215858 */  ori       $at, $at, 0x5858
/* B2E6CC 8024225C 44810000 */  mtc1      $at, $f0
/* B2E6D0 80242260 00000000 */  nop       
/* B2E6D4 80242264 46001080 */  add.s     $f2, $f2, $f0
/* B2E6D8 80242268 8E050000 */  lw        $a1, ($s0)
/* B2E6DC 8024226C 4600110D */  trunc.w.s $f4, $f2
/* B2E6E0 80242270 44062000 */  mfc1      $a2, $f4
/* B2E6E4 80242274 0C0B2026 */  jal       set_variable
/* B2E6E8 80242278 0220202D */   daddu    $a0, $s1, $zero
/* B2E6EC 8024227C 8FBF0018 */  lw        $ra, 0x18($sp)
/* B2E6F0 80242280 8FB10014 */  lw        $s1, 0x14($sp)
/* B2E6F4 80242284 8FB00010 */  lw        $s0, 0x10($sp)
/* B2E6F8 80242288 24020002 */  addiu     $v0, $zero, 2
/* B2E6FC 8024228C 03E00008 */  jr        $ra
/* B2E700 80242290 27BD0020 */   addiu    $sp, $sp, 0x20
