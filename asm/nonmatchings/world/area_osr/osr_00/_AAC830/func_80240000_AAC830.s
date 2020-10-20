.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_AAC830
/* AAC830 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AAC834 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* AAC838 80240008 0080802D */  daddu     $s0, $a0, $zero
/* AAC83C 8024000C AFBF0014 */  sw        $ra, 0x14($sp)
/* AAC840 80240010 8E0300A8 */  lw        $v1, 0xa8($s0)
/* AAC844 80240014 8E020088 */  lw        $v0, 0x88($s0)
/* AAC848 80240018 00621821 */  addu      $v1, $v1, $v0
/* AAC84C 8024001C 04610004 */  bgez      $v1, .L80240030
/* AAC850 80240020 AE0300A8 */   sw       $v1, 0xa8($s0)
/* AAC854 80240024 3C020002 */  lui       $v0, 2
/* AAC858 80240028 08090010 */  j         .L80240040
/* AAC85C 8024002C 00621021 */   addu     $v0, $v1, $v0
.L80240030:
/* AAC860 80240030 3C040002 */  lui       $a0, 2
/* AAC864 80240034 0083102A */  slt       $v0, $a0, $v1
/* AAC868 80240038 10400002 */  beqz      $v0, .L80240044
/* AAC86C 8024003C 00641023 */   subu     $v0, $v1, $a0
.L80240040:
/* AAC870 80240040 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80240044:
/* AAC874 80240044 8E0300AC */  lw        $v1, 0xac($s0)
/* AAC878 80240048 8E02008C */  lw        $v0, 0x8c($s0)
/* AAC87C 8024004C 00621821 */  addu      $v1, $v1, $v0
/* AAC880 80240050 04610004 */  bgez      $v1, .L80240064
/* AAC884 80240054 AE0300AC */   sw       $v1, 0xac($s0)
/* AAC888 80240058 3C020002 */  lui       $v0, 2
/* AAC88C 8024005C 0809001D */  j         .L80240074
/* AAC890 80240060 00621021 */   addu     $v0, $v1, $v0
.L80240064:
/* AAC894 80240064 3C040002 */  lui       $a0, 2
/* AAC898 80240068 0083102A */  slt       $v0, $a0, $v1
/* AAC89C 8024006C 10400002 */  beqz      $v0, .L80240078
/* AAC8A0 80240070 00641023 */   subu     $v0, $v1, $a0
.L80240074:
/* AAC8A4 80240074 AE0200AC */  sw        $v0, 0xac($s0)
.L80240078:
/* AAC8A8 80240078 8E0300B0 */  lw        $v1, 0xb0($s0)
/* AAC8AC 8024007C 8E020090 */  lw        $v0, 0x90($s0)
/* AAC8B0 80240080 00621821 */  addu      $v1, $v1, $v0
/* AAC8B4 80240084 04610004 */  bgez      $v1, .L80240098
/* AAC8B8 80240088 AE0300B0 */   sw       $v1, 0xb0($s0)
/* AAC8BC 8024008C 3C020002 */  lui       $v0, 2
/* AAC8C0 80240090 0809002A */  j         .L802400A8
/* AAC8C4 80240094 00621021 */   addu     $v0, $v1, $v0
.L80240098:
/* AAC8C8 80240098 3C040002 */  lui       $a0, 2
/* AAC8CC 8024009C 0083102A */  slt       $v0, $a0, $v1
/* AAC8D0 802400A0 10400002 */  beqz      $v0, .L802400AC
/* AAC8D4 802400A4 00641023 */   subu     $v0, $v1, $a0
.L802400A8:
/* AAC8D8 802400A8 AE0200B0 */  sw        $v0, 0xb0($s0)
.L802400AC:
/* AAC8DC 802400AC 8E0300B4 */  lw        $v1, 0xb4($s0)
/* AAC8E0 802400B0 8E020094 */  lw        $v0, 0x94($s0)
/* AAC8E4 802400B4 00621821 */  addu      $v1, $v1, $v0
/* AAC8E8 802400B8 04610004 */  bgez      $v1, .L802400CC
/* AAC8EC 802400BC AE0300B4 */   sw       $v1, 0xb4($s0)
/* AAC8F0 802400C0 3C020002 */  lui       $v0, 2
/* AAC8F4 802400C4 08090037 */  j         .L802400DC
/* AAC8F8 802400C8 00621021 */   addu     $v0, $v1, $v0
.L802400CC:
/* AAC8FC 802400CC 3C040002 */  lui       $a0, 2
/* AAC900 802400D0 0083102A */  slt       $v0, $a0, $v1
/* AAC904 802400D4 10400002 */  beqz      $v0, .L802400E0
/* AAC908 802400D8 00641023 */   subu     $v0, $v1, $a0
.L802400DC:
/* AAC90C 802400DC AE0200B4 */  sw        $v0, 0xb4($s0)
.L802400E0:
/* AAC910 802400E0 8E040084 */  lw        $a0, 0x84($s0)
/* AAC914 802400E4 0C046F07 */  jal       set_main_pan_u
/* AAC918 802400E8 8E0500A8 */   lw       $a1, 0xa8($s0)
/* AAC91C 802400EC 8E040084 */  lw        $a0, 0x84($s0)
/* AAC920 802400F0 0C046F0D */  jal       set_main_pan_v
/* AAC924 802400F4 8E0500AC */   lw       $a1, 0xac($s0)
/* AAC928 802400F8 8E040084 */  lw        $a0, 0x84($s0)
/* AAC92C 802400FC 0C046F13 */  jal       set_aux_pan_u
/* AAC930 80240100 8E0500B0 */   lw       $a1, 0xb0($s0)
/* AAC934 80240104 8E040084 */  lw        $a0, 0x84($s0)
/* AAC938 80240108 0C046F19 */  jal       set_aux_pan_v
/* AAC93C 8024010C 8E0500B4 */   lw       $a1, 0xb4($s0)
/* AAC940 80240110 8FBF0014 */  lw        $ra, 0x14($sp)
/* AAC944 80240114 8FB00010 */  lw        $s0, 0x10($sp)
/* AAC948 80240118 0000102D */  daddu     $v0, $zero, $zero
/* AAC94C 8024011C 03E00008 */  jr        $ra
/* AAC950 80240120 27BD0018 */   addiu    $sp, $sp, 0x18
