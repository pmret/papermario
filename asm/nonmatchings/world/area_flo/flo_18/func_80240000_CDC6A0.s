.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_CDC6A0
/* CDC6A0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CDC6A4 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* CDC6A8 80240008 0080802D */  daddu     $s0, $a0, $zero
/* CDC6AC 8024000C AFBF0014 */  sw        $ra, 0x14($sp)
/* CDC6B0 80240010 8E0300A8 */  lw        $v1, 0xa8($s0)
/* CDC6B4 80240014 8E020088 */  lw        $v0, 0x88($s0)
/* CDC6B8 80240018 00621821 */  addu      $v1, $v1, $v0
/* CDC6BC 8024001C 04610004 */  bgez      $v1, .L80240030
/* CDC6C0 80240020 AE0300A8 */   sw       $v1, 0xa8($s0)
/* CDC6C4 80240024 3C020002 */  lui       $v0, 2
/* CDC6C8 80240028 08090010 */  j         .L80240040
/* CDC6CC 8024002C 00621021 */   addu     $v0, $v1, $v0
.L80240030:
/* CDC6D0 80240030 3C040002 */  lui       $a0, 2
/* CDC6D4 80240034 0083102A */  slt       $v0, $a0, $v1
/* CDC6D8 80240038 10400002 */  beqz      $v0, .L80240044
/* CDC6DC 8024003C 00641023 */   subu     $v0, $v1, $a0
.L80240040:
/* CDC6E0 80240040 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80240044:
/* CDC6E4 80240044 8E0300AC */  lw        $v1, 0xac($s0)
/* CDC6E8 80240048 8E02008C */  lw        $v0, 0x8c($s0)
/* CDC6EC 8024004C 00621821 */  addu      $v1, $v1, $v0
/* CDC6F0 80240050 04610004 */  bgez      $v1, .L80240064
/* CDC6F4 80240054 AE0300AC */   sw       $v1, 0xac($s0)
/* CDC6F8 80240058 3C020002 */  lui       $v0, 2
/* CDC6FC 8024005C 0809001D */  j         .L80240074
/* CDC700 80240060 00621021 */   addu     $v0, $v1, $v0
.L80240064:
/* CDC704 80240064 3C040002 */  lui       $a0, 2
/* CDC708 80240068 0083102A */  slt       $v0, $a0, $v1
/* CDC70C 8024006C 10400002 */  beqz      $v0, .L80240078
/* CDC710 80240070 00641023 */   subu     $v0, $v1, $a0
.L80240074:
/* CDC714 80240074 AE0200AC */  sw        $v0, 0xac($s0)
.L80240078:
/* CDC718 80240078 8E0300B0 */  lw        $v1, 0xb0($s0)
/* CDC71C 8024007C 8E020090 */  lw        $v0, 0x90($s0)
/* CDC720 80240080 00621821 */  addu      $v1, $v1, $v0
/* CDC724 80240084 04610004 */  bgez      $v1, .L80240098
/* CDC728 80240088 AE0300B0 */   sw       $v1, 0xb0($s0)
/* CDC72C 8024008C 3C020002 */  lui       $v0, 2
/* CDC730 80240090 0809002A */  j         .L802400A8
/* CDC734 80240094 00621021 */   addu     $v0, $v1, $v0
.L80240098:
/* CDC738 80240098 3C040002 */  lui       $a0, 2
/* CDC73C 8024009C 0083102A */  slt       $v0, $a0, $v1
/* CDC740 802400A0 10400002 */  beqz      $v0, .L802400AC
/* CDC744 802400A4 00641023 */   subu     $v0, $v1, $a0
.L802400A8:
/* CDC748 802400A8 AE0200B0 */  sw        $v0, 0xb0($s0)
.L802400AC:
/* CDC74C 802400AC 8E0300B4 */  lw        $v1, 0xb4($s0)
/* CDC750 802400B0 8E020094 */  lw        $v0, 0x94($s0)
/* CDC754 802400B4 00621821 */  addu      $v1, $v1, $v0
/* CDC758 802400B8 04610004 */  bgez      $v1, .L802400CC
/* CDC75C 802400BC AE0300B4 */   sw       $v1, 0xb4($s0)
/* CDC760 802400C0 3C020002 */  lui       $v0, 2
/* CDC764 802400C4 08090037 */  j         .L802400DC
/* CDC768 802400C8 00621021 */   addu     $v0, $v1, $v0
.L802400CC:
/* CDC76C 802400CC 3C040002 */  lui       $a0, 2
/* CDC770 802400D0 0083102A */  slt       $v0, $a0, $v1
/* CDC774 802400D4 10400002 */  beqz      $v0, .L802400E0
/* CDC778 802400D8 00641023 */   subu     $v0, $v1, $a0
.L802400DC:
/* CDC77C 802400DC AE0200B4 */  sw        $v0, 0xb4($s0)
.L802400E0:
/* CDC780 802400E0 8E040084 */  lw        $a0, 0x84($s0)
/* CDC784 802400E4 0C046F07 */  jal       set_main_pan_u
/* CDC788 802400E8 8E0500A8 */   lw       $a1, 0xa8($s0)
/* CDC78C 802400EC 8E040084 */  lw        $a0, 0x84($s0)
/* CDC790 802400F0 0C046F0D */  jal       set_main_pan_v
/* CDC794 802400F4 8E0500AC */   lw       $a1, 0xac($s0)
/* CDC798 802400F8 8E040084 */  lw        $a0, 0x84($s0)
/* CDC79C 802400FC 0C046F13 */  jal       set_aux_pan_u
/* CDC7A0 80240100 8E0500B0 */   lw       $a1, 0xb0($s0)
/* CDC7A4 80240104 8E040084 */  lw        $a0, 0x84($s0)
/* CDC7A8 80240108 0C046F19 */  jal       set_aux_pan_v
/* CDC7AC 8024010C 8E0500B4 */   lw       $a1, 0xb4($s0)
/* CDC7B0 80240110 8FBF0014 */  lw        $ra, 0x14($sp)
/* CDC7B4 80240114 8FB00010 */  lw        $s0, 0x10($sp)
/* CDC7B8 80240118 0000102D */  daddu     $v0, $zero, $zero
/* CDC7BC 8024011C 03E00008 */  jr        $ra
/* CDC7C0 80240120 27BD0018 */   addiu    $sp, $sp, 0x18
