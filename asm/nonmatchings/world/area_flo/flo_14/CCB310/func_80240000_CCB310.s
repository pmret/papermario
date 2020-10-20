.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_CCB310
/* CCB310 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CCB314 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* CCB318 80240008 0080802D */  daddu     $s0, $a0, $zero
/* CCB31C 8024000C AFBF0014 */  sw        $ra, 0x14($sp)
/* CCB320 80240010 8E0300A8 */  lw        $v1, 0xa8($s0)
/* CCB324 80240014 8E020088 */  lw        $v0, 0x88($s0)
/* CCB328 80240018 00621821 */  addu      $v1, $v1, $v0
/* CCB32C 8024001C 04610004 */  bgez      $v1, .L80240030
/* CCB330 80240020 AE0300A8 */   sw       $v1, 0xa8($s0)
/* CCB334 80240024 3C020002 */  lui       $v0, 2
/* CCB338 80240028 08090010 */  j         .L80240040
/* CCB33C 8024002C 00621021 */   addu     $v0, $v1, $v0
.L80240030:
/* CCB340 80240030 3C040002 */  lui       $a0, 2
/* CCB344 80240034 0083102A */  slt       $v0, $a0, $v1
/* CCB348 80240038 10400002 */  beqz      $v0, .L80240044
/* CCB34C 8024003C 00641023 */   subu     $v0, $v1, $a0
.L80240040:
/* CCB350 80240040 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80240044:
/* CCB354 80240044 8E0300AC */  lw        $v1, 0xac($s0)
/* CCB358 80240048 8E02008C */  lw        $v0, 0x8c($s0)
/* CCB35C 8024004C 00621821 */  addu      $v1, $v1, $v0
/* CCB360 80240050 04610004 */  bgez      $v1, .L80240064
/* CCB364 80240054 AE0300AC */   sw       $v1, 0xac($s0)
/* CCB368 80240058 3C020002 */  lui       $v0, 2
/* CCB36C 8024005C 0809001D */  j         .L80240074
/* CCB370 80240060 00621021 */   addu     $v0, $v1, $v0
.L80240064:
/* CCB374 80240064 3C040002 */  lui       $a0, 2
/* CCB378 80240068 0083102A */  slt       $v0, $a0, $v1
/* CCB37C 8024006C 10400002 */  beqz      $v0, .L80240078
/* CCB380 80240070 00641023 */   subu     $v0, $v1, $a0
.L80240074:
/* CCB384 80240074 AE0200AC */  sw        $v0, 0xac($s0)
.L80240078:
/* CCB388 80240078 8E0300B0 */  lw        $v1, 0xb0($s0)
/* CCB38C 8024007C 8E020090 */  lw        $v0, 0x90($s0)
/* CCB390 80240080 00621821 */  addu      $v1, $v1, $v0
/* CCB394 80240084 04610004 */  bgez      $v1, .L80240098
/* CCB398 80240088 AE0300B0 */   sw       $v1, 0xb0($s0)
/* CCB39C 8024008C 3C020002 */  lui       $v0, 2
/* CCB3A0 80240090 0809002A */  j         .L802400A8
/* CCB3A4 80240094 00621021 */   addu     $v0, $v1, $v0
.L80240098:
/* CCB3A8 80240098 3C040002 */  lui       $a0, 2
/* CCB3AC 8024009C 0083102A */  slt       $v0, $a0, $v1
/* CCB3B0 802400A0 10400002 */  beqz      $v0, .L802400AC
/* CCB3B4 802400A4 00641023 */   subu     $v0, $v1, $a0
.L802400A8:
/* CCB3B8 802400A8 AE0200B0 */  sw        $v0, 0xb0($s0)
.L802400AC:
/* CCB3BC 802400AC 8E0300B4 */  lw        $v1, 0xb4($s0)
/* CCB3C0 802400B0 8E020094 */  lw        $v0, 0x94($s0)
/* CCB3C4 802400B4 00621821 */  addu      $v1, $v1, $v0
/* CCB3C8 802400B8 04610004 */  bgez      $v1, .L802400CC
/* CCB3CC 802400BC AE0300B4 */   sw       $v1, 0xb4($s0)
/* CCB3D0 802400C0 3C020002 */  lui       $v0, 2
/* CCB3D4 802400C4 08090037 */  j         .L802400DC
/* CCB3D8 802400C8 00621021 */   addu     $v0, $v1, $v0
.L802400CC:
/* CCB3DC 802400CC 3C040002 */  lui       $a0, 2
/* CCB3E0 802400D0 0083102A */  slt       $v0, $a0, $v1
/* CCB3E4 802400D4 10400002 */  beqz      $v0, .L802400E0
/* CCB3E8 802400D8 00641023 */   subu     $v0, $v1, $a0
.L802400DC:
/* CCB3EC 802400DC AE0200B4 */  sw        $v0, 0xb4($s0)
.L802400E0:
/* CCB3F0 802400E0 8E040084 */  lw        $a0, 0x84($s0)
/* CCB3F4 802400E4 0C046F07 */  jal       set_main_pan_u
/* CCB3F8 802400E8 8E0500A8 */   lw       $a1, 0xa8($s0)
/* CCB3FC 802400EC 8E040084 */  lw        $a0, 0x84($s0)
/* CCB400 802400F0 0C046F0D */  jal       set_main_pan_v
/* CCB404 802400F4 8E0500AC */   lw       $a1, 0xac($s0)
/* CCB408 802400F8 8E040084 */  lw        $a0, 0x84($s0)
/* CCB40C 802400FC 0C046F13 */  jal       set_aux_pan_u
/* CCB410 80240100 8E0500B0 */   lw       $a1, 0xb0($s0)
/* CCB414 80240104 8E040084 */  lw        $a0, 0x84($s0)
/* CCB418 80240108 0C046F19 */  jal       set_aux_pan_v
/* CCB41C 8024010C 8E0500B4 */   lw       $a1, 0xb4($s0)
/* CCB420 80240110 8FBF0014 */  lw        $ra, 0x14($sp)
/* CCB424 80240114 8FB00010 */  lw        $s0, 0x10($sp)
/* CCB428 80240118 0000102D */  daddu     $v0, $zero, $zero
/* CCB42C 8024011C 03E00008 */  jr        $ra
/* CCB430 80240120 27BD0018 */   addiu    $sp, $sp, 0x18
