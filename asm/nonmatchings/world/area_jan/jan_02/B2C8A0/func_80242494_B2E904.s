.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242494_B2E904
/* B2E904 80242494 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B2E908 80242498 AFB10014 */  sw        $s1, 0x14($sp)
/* B2E90C 8024249C 0080882D */  daddu     $s1, $a0, $zero
/* B2E910 802424A0 AFB00010 */  sw        $s0, 0x10($sp)
/* B2E914 802424A4 00A0802D */  daddu     $s0, $a1, $zero
/* B2E918 802424A8 AFBF0018 */  sw        $ra, 0x18($sp)
/* B2E91C 802424AC 0C00EABB */  jal       get_npc_unsafe
/* B2E920 802424B0 2404FFFC */   addiu    $a0, $zero, -4
/* B2E924 802424B4 12000003 */  beqz      $s0, .L802424C4
/* B2E928 802424B8 0040182D */   daddu    $v1, $v0, $zero
/* B2E92C 802424BC 2402003C */  addiu     $v0, $zero, 0x3c
/* B2E930 802424C0 AE220070 */  sw        $v0, 0x70($s1)
.L802424C4:
/* B2E934 802424C4 C462000C */  lwc1      $f2, 0xc($v1)
/* B2E938 802424C8 3C0141F0 */  lui       $at, 0x41f0
/* B2E93C 802424CC 44810000 */  mtc1      $at, $f0
/* B2E940 802424D0 00000000 */  nop       
/* B2E944 802424D4 46001000 */  add.s     $f0, $f2, $f0
/* B2E948 802424D8 3C0143B4 */  lui       $at, 0x43b4
/* B2E94C 802424DC 44811000 */  mtc1      $at, $f2
/* B2E950 802424E0 00000000 */  nop       
/* B2E954 802424E4 4600103E */  c.le.s    $f2, $f0
/* B2E958 802424E8 00000000 */  nop       
/* B2E95C 802424EC 45000003 */  bc1f      .L802424FC
/* B2E960 802424F0 E460000C */   swc1     $f0, 0xc($v1)
/* B2E964 802424F4 46020001 */  sub.s     $f0, $f0, $f2
/* B2E968 802424F8 E460000C */  swc1      $f0, 0xc($v1)
.L802424FC:
/* B2E96C 802424FC 8E230070 */  lw        $v1, 0x70($s1)
/* B2E970 80242500 2463FFFF */  addiu     $v1, $v1, -1
/* B2E974 80242504 000317C3 */  sra       $v0, $v1, 0x1f
/* B2E978 80242508 AE230070 */  sw        $v1, 0x70($s1)
/* B2E97C 8024250C 8FBF0018 */  lw        $ra, 0x18($sp)
/* B2E980 80242510 8FB10014 */  lw        $s1, 0x14($sp)
/* B2E984 80242514 8FB00010 */  lw        $s0, 0x10($sp)
/* B2E988 80242518 30420002 */  andi      $v0, $v0, 2
/* B2E98C 8024251C 03E00008 */  jr        $ra
/* B2E990 80242520 27BD0020 */   addiu    $sp, $sp, 0x20
