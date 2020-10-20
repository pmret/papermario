.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243124_A1E224
/* A1E224 80243124 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* A1E228 80243128 AFB20018 */  sw        $s2, 0x18($sp)
/* A1E22C 8024312C 0080902D */  daddu     $s2, $a0, $zero
/* A1E230 80243130 AFBF0030 */  sw        $ra, 0x30($sp)
/* A1E234 80243134 AFB7002C */  sw        $s7, 0x2c($sp)
/* A1E238 80243138 AFB60028 */  sw        $s6, 0x28($sp)
/* A1E23C 8024313C AFB50024 */  sw        $s5, 0x24($sp)
/* A1E240 80243140 AFB40020 */  sw        $s4, 0x20($sp)
/* A1E244 80243144 AFB3001C */  sw        $s3, 0x1c($sp)
/* A1E248 80243148 AFB10014 */  sw        $s1, 0x14($sp)
/* A1E24C 8024314C AFB00010 */  sw        $s0, 0x10($sp)
/* A1E250 80243150 F7B60040 */  sdc1      $f22, 0x40($sp)
/* A1E254 80243154 F7B40038 */  sdc1      $f20, 0x38($sp)
/* A1E258 80243158 8E50000C */  lw        $s0, 0xc($s2)
/* A1E25C 8024315C 8E050000 */  lw        $a1, ($s0)
/* A1E260 80243160 0C0B1EAF */  jal       get_variable
/* A1E264 80243164 26100004 */   addiu    $s0, $s0, 4
/* A1E268 80243168 8E050000 */  lw        $a1, ($s0)
/* A1E26C 8024316C 26100004 */  addiu     $s0, $s0, 4
/* A1E270 80243170 0240202D */  daddu     $a0, $s2, $zero
/* A1E274 80243174 0C0B1EAF */  jal       get_variable
/* A1E278 80243178 0040B82D */   daddu    $s7, $v0, $zero
/* A1E27C 8024317C 8E050000 */  lw        $a1, ($s0)
/* A1E280 80243180 26100004 */  addiu     $s0, $s0, 4
/* A1E284 80243184 0240202D */  daddu     $a0, $s2, $zero
/* A1E288 80243188 0C0B1EAF */  jal       get_variable
/* A1E28C 8024318C 0040B02D */   daddu    $s6, $v0, $zero
/* A1E290 80243190 0240202D */  daddu     $a0, $s2, $zero
/* A1E294 80243194 3C05F4AC */  lui       $a1, 0xf4ac
/* A1E298 80243198 34A5D481 */  ori       $a1, $a1, 0xd481
/* A1E29C 8024319C 3C068007 */  lui       $a2, %hi(gCurrentCameraID)
/* A1E2A0 802431A0 8CC67410 */  lw        $a2, %lo(gCurrentCameraID)($a2)
/* A1E2A4 802431A4 8E140000 */  lw        $s4, ($s0)
/* A1E2A8 802431A8 00061880 */  sll       $v1, $a2, 2
/* A1E2AC 802431AC 00661821 */  addu      $v1, $v1, $a2
/* A1E2B0 802431B0 00031880 */  sll       $v1, $v1, 2
/* A1E2B4 802431B4 00661823 */  subu      $v1, $v1, $a2
/* A1E2B8 802431B8 000330C0 */  sll       $a2, $v1, 3
/* A1E2BC 802431BC 00661821 */  addu      $v1, $v1, $a2
/* A1E2C0 802431C0 000318C0 */  sll       $v1, $v1, 3
/* A1E2C4 802431C4 3C01800B */  lui       $at, 0x800b
/* A1E2C8 802431C8 00230821 */  addu      $at, $at, $v1
/* A1E2CC 802431CC C4201DEC */  lwc1      $f0, 0x1dec($at)
/* A1E2D0 802431D0 8E150004 */  lw        $s5, 4($s0)
/* A1E2D4 802431D4 4600010D */  trunc.w.s $f4, $f0
/* A1E2D8 802431D8 44112000 */  mfc1      $s1, $f4
/* A1E2DC 802431DC 0C0B1EAF */  jal       get_variable
/* A1E2E0 802431E0 0040982D */   daddu    $s3, $v0, $zero
/* A1E2E4 802431E4 4491B000 */  mtc1      $s1, $f22
/* A1E2E8 802431E8 00000000 */  nop       
/* A1E2EC 802431EC 4680B5A0 */  cvt.s.w   $f22, $f22
/* A1E2F0 802431F0 4600B306 */  mov.s     $f12, $f22
/* A1E2F4 802431F4 0C00A8D4 */  jal       cos_deg
/* A1E2F8 802431F8 0040802D */   daddu    $s0, $v0, $zero
/* A1E2FC 802431FC 4493A000 */  mtc1      $s3, $f20
/* A1E300 80243200 00000000 */  nop       
/* A1E304 80243204 4680A520 */  cvt.s.w   $f20, $f20
/* A1E308 80243208 4600A002 */  mul.s     $f0, $f20, $f0
/* A1E30C 8024320C 00000000 */  nop       
/* A1E310 80243210 0240202D */  daddu     $a0, $s2, $zero
/* A1E314 80243214 44901000 */  mtc1      $s0, $f2
/* A1E318 80243218 00000000 */  nop       
/* A1E31C 8024321C 468010A0 */  cvt.s.w   $f2, $f2
/* A1E320 80243220 46001081 */  sub.s     $f2, $f2, $f0
/* A1E324 80243224 3C05F4AC */  lui       $a1, 0xf4ac
/* A1E328 80243228 4600110D */  trunc.w.s $f4, $f2
/* A1E32C 8024322C 44102000 */  mfc1      $s0, $f4
/* A1E330 80243230 0C0B1EAF */  jal       get_variable
/* A1E334 80243234 34A5D483 */   ori      $a1, $a1, 0xd483
/* A1E338 80243238 4600B306 */  mov.s     $f12, $f22
/* A1E33C 8024323C 0C00A8BB */  jal       sin_deg
/* A1E340 80243240 0040882D */   daddu    $s1, $v0, $zero
/* A1E344 80243244 4600A502 */  mul.s     $f20, $f20, $f0
/* A1E348 80243248 00000000 */  nop       
/* A1E34C 8024324C 0240202D */  daddu     $a0, $s2, $zero
/* A1E350 80243250 44910000 */  mtc1      $s1, $f0
/* A1E354 80243254 00000000 */  nop       
/* A1E358 80243258 46800020 */  cvt.s.w   $f0, $f0
/* A1E35C 8024325C 46140001 */  sub.s     $f0, $f0, $f20
/* A1E360 80243260 0280282D */  daddu     $a1, $s4, $zero
/* A1E364 80243264 02173023 */  subu      $a2, $s0, $s7
/* A1E368 80243268 4600010D */  trunc.w.s $f4, $f0
/* A1E36C 8024326C 44102000 */  mfc1      $s0, $f4
/* A1E370 80243270 0C0B2026 */  jal       set_variable
/* A1E374 80243274 02168023 */   subu     $s0, $s0, $s6
/* A1E378 80243278 0240202D */  daddu     $a0, $s2, $zero
/* A1E37C 8024327C 02A0282D */  daddu     $a1, $s5, $zero
/* A1E380 80243280 0C0B2026 */  jal       set_variable
/* A1E384 80243284 0200302D */   daddu    $a2, $s0, $zero
/* A1E388 80243288 8FBF0030 */  lw        $ra, 0x30($sp)
/* A1E38C 8024328C 8FB7002C */  lw        $s7, 0x2c($sp)
/* A1E390 80243290 8FB60028 */  lw        $s6, 0x28($sp)
/* A1E394 80243294 8FB50024 */  lw        $s5, 0x24($sp)
/* A1E398 80243298 8FB40020 */  lw        $s4, 0x20($sp)
/* A1E39C 8024329C 8FB3001C */  lw        $s3, 0x1c($sp)
/* A1E3A0 802432A0 8FB20018 */  lw        $s2, 0x18($sp)
/* A1E3A4 802432A4 8FB10014 */  lw        $s1, 0x14($sp)
/* A1E3A8 802432A8 8FB00010 */  lw        $s0, 0x10($sp)
/* A1E3AC 802432AC D7B60040 */  ldc1      $f22, 0x40($sp)
/* A1E3B0 802432B0 D7B40038 */  ldc1      $f20, 0x38($sp)
/* A1E3B4 802432B4 24020002 */  addiu     $v0, $zero, 2
/* A1E3B8 802432B8 03E00008 */  jr        $ra
/* A1E3BC 802432BC 27BD0048 */   addiu    $sp, $sp, 0x48
