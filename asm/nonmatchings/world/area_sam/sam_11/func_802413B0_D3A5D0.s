.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413B0_D3B980
/* D3B980 802413B0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D3B984 802413B4 AFB10014 */  sw        $s1, 0x14($sp)
/* D3B988 802413B8 0080882D */  daddu     $s1, $a0, $zero
/* D3B98C 802413BC AFBF0018 */  sw        $ra, 0x18($sp)
/* D3B990 802413C0 AFB00010 */  sw        $s0, 0x10($sp)
/* D3B994 802413C4 8E30000C */  lw        $s0, 0xc($s1)
/* D3B998 802413C8 8E050000 */  lw        $a1, ($s0)
/* D3B99C 802413CC 0C0B1EAF */  jal       get_variable
/* D3B9A0 802413D0 26100004 */   addiu    $s0, $s0, 4
/* D3B9A4 802413D4 00021880 */  sll       $v1, $v0, 2
/* D3B9A8 802413D8 00621821 */  addu      $v1, $v1, $v0
/* D3B9AC 802413DC 00031880 */  sll       $v1, $v1, 2
/* D3B9B0 802413E0 00621823 */  subu      $v1, $v1, $v0
/* D3B9B4 802413E4 000310C0 */  sll       $v0, $v1, 3
/* D3B9B8 802413E8 00621821 */  addu      $v1, $v1, $v0
/* D3B9BC 802413EC 000318C0 */  sll       $v1, $v1, 3
/* D3B9C0 802413F0 3C01800B */  lui       $at, 0x800b
/* D3B9C4 802413F4 00230821 */  addu      $at, $at, $v1
/* D3B9C8 802413F8 C4221D98 */  lwc1      $f2, 0x1d98($at)
/* D3B9CC 802413FC 3C014480 */  lui       $at, 0x4480
/* D3B9D0 80241400 44810000 */  mtc1      $at, $f0
/* D3B9D4 80241404 00000000 */  nop       
/* D3B9D8 80241408 46001082 */  mul.s     $f2, $f2, $f0
/* D3B9DC 8024140C 00000000 */  nop       
/* D3B9E0 80241410 3C01CD5B */  lui       $at, 0xcd5b
/* D3B9E4 80241414 34215858 */  ori       $at, $at, 0x5858
/* D3B9E8 80241418 44810000 */  mtc1      $at, $f0
/* D3B9EC 8024141C 00000000 */  nop       
/* D3B9F0 80241420 46001080 */  add.s     $f2, $f2, $f0
/* D3B9F4 80241424 8E050000 */  lw        $a1, ($s0)
/* D3B9F8 80241428 4600110D */  trunc.w.s $f4, $f2
/* D3B9FC 8024142C 44062000 */  mfc1      $a2, $f4
/* D3BA00 80241430 0C0B2026 */  jal       set_variable
/* D3BA04 80241434 0220202D */   daddu    $a0, $s1, $zero
/* D3BA08 80241438 8FBF0018 */  lw        $ra, 0x18($sp)
/* D3BA0C 8024143C 8FB10014 */  lw        $s1, 0x14($sp)
/* D3BA10 80241440 8FB00010 */  lw        $s0, 0x10($sp)
/* D3BA14 80241444 24020002 */  addiu     $v0, $zero, 2
/* D3BA18 80241448 03E00008 */  jr        $ra
/* D3BA1C 8024144C 27BD0020 */   addiu    $sp, $sp, 0x20
