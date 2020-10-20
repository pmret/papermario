.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_CAC1F0
/* CAC1F0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CAC1F4 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* CAC1F8 80240008 0080802D */  daddu     $s0, $a0, $zero
/* CAC1FC 8024000C AFBF0014 */  sw        $ra, 0x14($sp)
/* CAC200 80240010 8E0300A8 */  lw        $v1, 0xa8($s0)
/* CAC204 80240014 8E020088 */  lw        $v0, 0x88($s0)
/* CAC208 80240018 00621821 */  addu      $v1, $v1, $v0
/* CAC20C 8024001C 04610004 */  bgez      $v1, .L80240030
/* CAC210 80240020 AE0300A8 */   sw       $v1, 0xa8($s0)
/* CAC214 80240024 3C020002 */  lui       $v0, 2
/* CAC218 80240028 08090010 */  j         .L80240040
/* CAC21C 8024002C 00621021 */   addu     $v0, $v1, $v0
.L80240030:
/* CAC220 80240030 3C040002 */  lui       $a0, 2
/* CAC224 80240034 0083102A */  slt       $v0, $a0, $v1
/* CAC228 80240038 10400002 */  beqz      $v0, .L80240044
/* CAC22C 8024003C 00641023 */   subu     $v0, $v1, $a0
.L80240040:
/* CAC230 80240040 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80240044:
/* CAC234 80240044 8E0300AC */  lw        $v1, 0xac($s0)
/* CAC238 80240048 8E02008C */  lw        $v0, 0x8c($s0)
/* CAC23C 8024004C 00621821 */  addu      $v1, $v1, $v0
/* CAC240 80240050 04610004 */  bgez      $v1, .L80240064
/* CAC244 80240054 AE0300AC */   sw       $v1, 0xac($s0)
/* CAC248 80240058 3C020002 */  lui       $v0, 2
/* CAC24C 8024005C 0809001D */  j         .L80240074
/* CAC250 80240060 00621021 */   addu     $v0, $v1, $v0
.L80240064:
/* CAC254 80240064 3C040002 */  lui       $a0, 2
/* CAC258 80240068 0083102A */  slt       $v0, $a0, $v1
/* CAC25C 8024006C 10400002 */  beqz      $v0, .L80240078
/* CAC260 80240070 00641023 */   subu     $v0, $v1, $a0
.L80240074:
/* CAC264 80240074 AE0200AC */  sw        $v0, 0xac($s0)
.L80240078:
/* CAC268 80240078 8E0300B0 */  lw        $v1, 0xb0($s0)
/* CAC26C 8024007C 8E020090 */  lw        $v0, 0x90($s0)
/* CAC270 80240080 00621821 */  addu      $v1, $v1, $v0
/* CAC274 80240084 04610004 */  bgez      $v1, .L80240098
/* CAC278 80240088 AE0300B0 */   sw       $v1, 0xb0($s0)
/* CAC27C 8024008C 3C020002 */  lui       $v0, 2
/* CAC280 80240090 0809002A */  j         .L802400A8
/* CAC284 80240094 00621021 */   addu     $v0, $v1, $v0
.L80240098:
/* CAC288 80240098 3C040002 */  lui       $a0, 2
/* CAC28C 8024009C 0083102A */  slt       $v0, $a0, $v1
/* CAC290 802400A0 10400002 */  beqz      $v0, .L802400AC
/* CAC294 802400A4 00641023 */   subu     $v0, $v1, $a0
.L802400A8:
/* CAC298 802400A8 AE0200B0 */  sw        $v0, 0xb0($s0)
.L802400AC:
/* CAC29C 802400AC 8E0300B4 */  lw        $v1, 0xb4($s0)
/* CAC2A0 802400B0 8E020094 */  lw        $v0, 0x94($s0)
/* CAC2A4 802400B4 00621821 */  addu      $v1, $v1, $v0
/* CAC2A8 802400B8 04610004 */  bgez      $v1, .L802400CC
/* CAC2AC 802400BC AE0300B4 */   sw       $v1, 0xb4($s0)
/* CAC2B0 802400C0 3C020002 */  lui       $v0, 2
/* CAC2B4 802400C4 08090037 */  j         .L802400DC
/* CAC2B8 802400C8 00621021 */   addu     $v0, $v1, $v0
.L802400CC:
/* CAC2BC 802400CC 3C040002 */  lui       $a0, 2
/* CAC2C0 802400D0 0083102A */  slt       $v0, $a0, $v1
/* CAC2C4 802400D4 10400002 */  beqz      $v0, .L802400E0
/* CAC2C8 802400D8 00641023 */   subu     $v0, $v1, $a0
.L802400DC:
/* CAC2CC 802400DC AE0200B4 */  sw        $v0, 0xb4($s0)
.L802400E0:
/* CAC2D0 802400E0 8E040084 */  lw        $a0, 0x84($s0)
/* CAC2D4 802400E4 0C046F07 */  jal       set_main_pan_u
/* CAC2D8 802400E8 8E0500A8 */   lw       $a1, 0xa8($s0)
/* CAC2DC 802400EC 8E040084 */  lw        $a0, 0x84($s0)
/* CAC2E0 802400F0 0C046F0D */  jal       set_main_pan_v
/* CAC2E4 802400F4 8E0500AC */   lw       $a1, 0xac($s0)
/* CAC2E8 802400F8 8E040084 */  lw        $a0, 0x84($s0)
/* CAC2EC 802400FC 0C046F13 */  jal       set_aux_pan_u
/* CAC2F0 80240100 8E0500B0 */   lw       $a1, 0xb0($s0)
/* CAC2F4 80240104 8E040084 */  lw        $a0, 0x84($s0)
/* CAC2F8 80240108 0C046F19 */  jal       set_aux_pan_v
/* CAC2FC 8024010C 8E0500B4 */   lw       $a1, 0xb4($s0)
/* CAC300 80240110 8FBF0014 */  lw        $ra, 0x14($sp)
/* CAC304 80240114 8FB00010 */  lw        $s0, 0x10($sp)
/* CAC308 80240118 0000102D */  daddu     $v0, $zero, $zero
/* CAC30C 8024011C 03E00008 */  jr        $ra
/* CAC310 80240120 27BD0018 */   addiu    $sp, $sp, 0x18
