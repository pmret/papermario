.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_C801A0
/* C801A0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C801A4 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* C801A8 80240008 0080802D */  daddu     $s0, $a0, $zero
/* C801AC 8024000C AFBF0014 */  sw        $ra, 0x14($sp)
/* C801B0 80240010 8E0300A8 */  lw        $v1, 0xa8($s0)
/* C801B4 80240014 8E020088 */  lw        $v0, 0x88($s0)
/* C801B8 80240018 00621821 */  addu      $v1, $v1, $v0
/* C801BC 8024001C 04610004 */  bgez      $v1, .L80240030
/* C801C0 80240020 AE0300A8 */   sw       $v1, 0xa8($s0)
/* C801C4 80240024 3C020002 */  lui       $v0, 2
/* C801C8 80240028 08090010 */  j         .L80240040
/* C801CC 8024002C 00621021 */   addu     $v0, $v1, $v0
.L80240030:
/* C801D0 80240030 3C040002 */  lui       $a0, 2
/* C801D4 80240034 0083102A */  slt       $v0, $a0, $v1
/* C801D8 80240038 10400002 */  beqz      $v0, .L80240044
/* C801DC 8024003C 00641023 */   subu     $v0, $v1, $a0
.L80240040:
/* C801E0 80240040 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80240044:
/* C801E4 80240044 8E0300AC */  lw        $v1, 0xac($s0)
/* C801E8 80240048 8E02008C */  lw        $v0, 0x8c($s0)
/* C801EC 8024004C 00621821 */  addu      $v1, $v1, $v0
/* C801F0 80240050 04610004 */  bgez      $v1, .L80240064
/* C801F4 80240054 AE0300AC */   sw       $v1, 0xac($s0)
/* C801F8 80240058 3C020002 */  lui       $v0, 2
/* C801FC 8024005C 0809001D */  j         .L80240074
/* C80200 80240060 00621021 */   addu     $v0, $v1, $v0
.L80240064:
/* C80204 80240064 3C040002 */  lui       $a0, 2
/* C80208 80240068 0083102A */  slt       $v0, $a0, $v1
/* C8020C 8024006C 10400002 */  beqz      $v0, .L80240078
/* C80210 80240070 00641023 */   subu     $v0, $v1, $a0
.L80240074:
/* C80214 80240074 AE0200AC */  sw        $v0, 0xac($s0)
.L80240078:
/* C80218 80240078 8E0300B0 */  lw        $v1, 0xb0($s0)
/* C8021C 8024007C 8E020090 */  lw        $v0, 0x90($s0)
/* C80220 80240080 00621821 */  addu      $v1, $v1, $v0
/* C80224 80240084 04610004 */  bgez      $v1, .L80240098
/* C80228 80240088 AE0300B0 */   sw       $v1, 0xb0($s0)
/* C8022C 8024008C 3C020002 */  lui       $v0, 2
/* C80230 80240090 0809002A */  j         .L802400A8
/* C80234 80240094 00621021 */   addu     $v0, $v1, $v0
.L80240098:
/* C80238 80240098 3C040002 */  lui       $a0, 2
/* C8023C 8024009C 0083102A */  slt       $v0, $a0, $v1
/* C80240 802400A0 10400002 */  beqz      $v0, .L802400AC
/* C80244 802400A4 00641023 */   subu     $v0, $v1, $a0
.L802400A8:
/* C80248 802400A8 AE0200B0 */  sw        $v0, 0xb0($s0)
.L802400AC:
/* C8024C 802400AC 8E0300B4 */  lw        $v1, 0xb4($s0)
/* C80250 802400B0 8E020094 */  lw        $v0, 0x94($s0)
/* C80254 802400B4 00621821 */  addu      $v1, $v1, $v0
/* C80258 802400B8 04610004 */  bgez      $v1, .L802400CC
/* C8025C 802400BC AE0300B4 */   sw       $v1, 0xb4($s0)
/* C80260 802400C0 3C020002 */  lui       $v0, 2
/* C80264 802400C4 08090037 */  j         .L802400DC
/* C80268 802400C8 00621021 */   addu     $v0, $v1, $v0
.L802400CC:
/* C8026C 802400CC 3C040002 */  lui       $a0, 2
/* C80270 802400D0 0083102A */  slt       $v0, $a0, $v1
/* C80274 802400D4 10400002 */  beqz      $v0, .L802400E0
/* C80278 802400D8 00641023 */   subu     $v0, $v1, $a0
.L802400DC:
/* C8027C 802400DC AE0200B4 */  sw        $v0, 0xb4($s0)
.L802400E0:
/* C80280 802400E0 8E040084 */  lw        $a0, 0x84($s0)
/* C80284 802400E4 0C046F07 */  jal       set_main_pan_u
/* C80288 802400E8 8E0500A8 */   lw       $a1, 0xa8($s0)
/* C8028C 802400EC 8E040084 */  lw        $a0, 0x84($s0)
/* C80290 802400F0 0C046F0D */  jal       set_main_pan_v
/* C80294 802400F4 8E0500AC */   lw       $a1, 0xac($s0)
/* C80298 802400F8 8E040084 */  lw        $a0, 0x84($s0)
/* C8029C 802400FC 0C046F13 */  jal       set_aux_pan_u
/* C802A0 80240100 8E0500B0 */   lw       $a1, 0xb0($s0)
/* C802A4 80240104 8E040084 */  lw        $a0, 0x84($s0)
/* C802A8 80240108 0C046F19 */  jal       set_aux_pan_v
/* C802AC 8024010C 8E0500B4 */   lw       $a1, 0xb4($s0)
/* C802B0 80240110 8FBF0014 */  lw        $ra, 0x14($sp)
/* C802B4 80240114 8FB00010 */  lw        $s0, 0x10($sp)
/* C802B8 80240118 0000102D */  daddu     $v0, $zero, $zero
/* C802BC 8024011C 03E00008 */  jr        $ra
/* C802C0 80240120 27BD0018 */   addiu    $sp, $sp, 0x18
