.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6230_E24800
/* E24800 802B6230 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E24804 802B6234 AFB00010 */  sw        $s0, 0x10($sp)
/* E24808 802B6238 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E2480C 802B623C 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E24810 802B6240 AFBF0018 */  sw        $ra, 0x18($sp)
/* E24814 802B6244 AFB10014 */  sw        $s1, 0x14($sp)
/* E24818 802B6248 8E030000 */  lw        $v1, ($s0)
/* E2481C 802B624C 0461000A */  bgez      $v1, .L802B6278
/* E24820 802B6250 0200882D */   daddu    $s1, $s0, $zero
/* E24824 802B6254 3C027FFF */  lui       $v0, 0x7fff
/* E24828 802B6258 3442FFFF */  ori       $v0, $v0, 0xffff
/* E2482C 802B625C 3C04000A */  lui       $a0, 0xa
/* E24830 802B6260 34840005 */  ori       $a0, $a0, 5
/* E24834 802B6264 00621024 */  and       $v0, $v1, $v0
/* E24838 802B6268 0C037FBF */  jal       func_800DFEFC
/* E2483C 802B626C AE020000 */   sw       $v0, ($s0)
/* E24840 802B6270 24020008 */  addiu     $v0, $zero, 8
/* E24844 802B6274 A6020008 */  sh        $v0, 8($s0)
.L802B6278:
/* E24848 802B6278 86020008 */  lh        $v0, 8($s0)
/* E2484C 802B627C 96030008 */  lhu       $v1, 8($s0)
/* E24850 802B6280 1040000B */  beqz      $v0, .L802B62B0
/* E24854 802B6284 2462FFFF */   addiu    $v0, $v1, -1
/* E24858 802B6288 A6020008 */  sh        $v0, 8($s0)
/* E2485C 802B628C 00021400 */  sll       $v0, $v0, 0x10
/* E24860 802B6290 00021403 */  sra       $v0, $v0, 0x10
/* E24864 802B6294 24030004 */  addiu     $v1, $zero, 4
/* E24868 802B6298 14430012 */  bne       $v0, $v1, .L802B62E4
/* E2486C 802B629C 00000000 */   nop
/* E24870 802B62A0 0C039426 */  jal       func_800E5098
/* E24874 802B62A4 24040001 */   addiu    $a0, $zero, 1
/* E24878 802B62A8 080AD8B9 */  j         .L802B62E4
/* E2487C 802B62AC 00000000 */   nop
.L802B62B0:
/* E24880 802B62B0 8E020000 */  lw        $v0, ($s0)
/* E24884 802B62B4 30424000 */  andi      $v0, $v0, 0x4000
/* E24888 802B62B8 10400008 */  beqz      $v0, .L802B62DC
/* E2488C 802B62BC 0000202D */   daddu    $a0, $zero, $zero
/* E24890 802B62C0 C6220054 */  lwc1      $f2, 0x54($s1)
/* E24894 802B62C4 C620005C */  lwc1      $f0, 0x5c($s1)
/* E24898 802B62C8 4602003E */  c.le.s    $f0, $f2
/* E2489C 802B62CC 00000000 */  nop
/* E248A0 802B62D0 45000002 */  bc1f      .L802B62DC
/* E248A4 802B62D4 24040001 */   addiu    $a0, $zero, 1
/* E248A8 802B62D8 24040002 */  addiu     $a0, $zero, 2
.L802B62DC:
/* E248AC 802B62DC 0C039769 */  jal       set_action_state
/* E248B0 802B62E0 00000000 */   nop
.L802B62E4:
/* E248B4 802B62E4 8FBF0018 */  lw        $ra, 0x18($sp)
/* E248B8 802B62E8 8FB10014 */  lw        $s1, 0x14($sp)
/* E248BC 802B62EC 8FB00010 */  lw        $s0, 0x10($sp)
/* E248C0 802B62F0 03E00008 */  jr        $ra
/* E248C4 802B62F4 27BD0020 */   addiu    $sp, $sp, 0x20
/* E248C8 802B62F8 00000000 */  nop
/* E248CC 802B62FC 00000000 */  nop
