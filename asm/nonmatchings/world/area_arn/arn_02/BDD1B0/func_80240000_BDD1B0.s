.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_BDD1B0
/* BDD1B0 80240000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BDD1B4 80240004 AFBF001C */  sw        $ra, 0x1c($sp)
/* BDD1B8 80240008 AFB20018 */  sw        $s2, 0x18($sp)
/* BDD1BC 8024000C AFB10014 */  sw        $s1, 0x14($sp)
/* BDD1C0 80240010 AFB00010 */  sw        $s0, 0x10($sp)
/* BDD1C4 80240014 F7B40020 */  sdc1      $f20, 0x20($sp)
/* BDD1C8 80240018 8C900148 */  lw        $s0, 0x148($a0)
/* BDD1CC 8024001C 86040008 */  lh        $a0, 8($s0)
/* BDD1D0 80240020 3C014387 */  lui       $at, 0x4387
/* BDD1D4 80240024 4481A000 */  mtc1      $at, $f20
/* BDD1D8 80240028 0C00EABB */  jal       get_npc_unsafe
/* BDD1DC 8024002C 00A0882D */   daddu    $s1, $a1, $zero
/* BDD1E0 80240030 0200202D */  daddu     $a0, $s0, $zero
/* BDD1E4 80240034 8E26000C */  lw        $a2, 0xc($s1)
/* BDD1E8 80240038 8E270010 */  lw        $a3, 0x10($s1)
/* BDD1EC 8024003C 0040882D */  daddu     $s1, $v0, $zero
/* BDD1F0 80240040 3C03800B */  lui       $v1, %hi(gCameras)
/* BDD1F4 80240044 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* BDD1F8 80240048 3C02800A */  lui       $v0, %hi(D_8009A634)
/* BDD1FC 8024004C 8442A634 */  lh        $v0, %lo(D_8009A634)($v0)
/* BDD200 80240050 0000282D */  daddu     $a1, $zero, $zero
/* BDD204 80240054 00028080 */  sll       $s0, $v0, 2
/* BDD208 80240058 02028021 */  addu      $s0, $s0, $v0
/* BDD20C 8024005C 00108080 */  sll       $s0, $s0, 2
/* BDD210 80240060 02028023 */  subu      $s0, $s0, $v0
/* BDD214 80240064 001010C0 */  sll       $v0, $s0, 3
/* BDD218 80240068 02028021 */  addu      $s0, $s0, $v0
/* BDD21C 8024006C 001080C0 */  sll       $s0, $s0, 3
/* BDD220 80240070 0C0124FB */  jal       func_800493EC
/* BDD224 80240074 02038021 */   addu     $s0, $s0, $v1
/* BDD228 80240078 C60C006C */  lwc1      $f12, 0x6c($s0)
/* BDD22C 8024007C C62E000C */  lwc1      $f14, 0xc($s1)
/* BDD230 80240080 0C00A70A */  jal       get_clamped_angle_diff
/* BDD234 80240084 0002802B */   sltu     $s0, $zero, $v0
/* BDD238 80240088 0C00A6C9 */  jal       clamp_angle
/* BDD23C 8024008C 46000306 */   mov.s    $f12, $f0
/* BDD240 80240090 3C018024 */  lui       $at, %hi(func_80241AE0_9F6520)
/* BDD244 80240094 D4221AE0 */  ldc1      $f2, %lo(func_80241AE0_9F6520)($at)
/* BDD248 80240098 46000021 */  cvt.d.s   $f0, $f0
/* BDD24C 8024009C 4622003C */  c.lt.d    $f0, $f2
/* BDD250 802400A0 00000000 */  nop
/* BDD254 802400A4 45000003 */  bc1f      .L802400B4
/* BDD258 802400A8 00000000 */   nop
/* BDD25C 802400AC 3C0142B4 */  lui       $at, 0x42b4
/* BDD260 802400B0 4481A000 */  mtc1      $at, $f20
.L802400B4:
/* BDD264 802400B4 3C12800F */  lui       $s2, %hi(gPlayerStatusPtr)
/* BDD268 802400B8 26527B30 */  addiu     $s2, $s2, %lo(gPlayerStatusPtr)
/* BDD26C 802400BC C62C0038 */  lwc1      $f12, 0x38($s1)
/* BDD270 802400C0 8E420000 */  lw        $v0, ($s2)
/* BDD274 802400C4 C62E0040 */  lwc1      $f14, 0x40($s1)
/* BDD278 802400C8 8C460028 */  lw        $a2, 0x28($v0)
/* BDD27C 802400CC 0C00A720 */  jal       atan2
/* BDD280 802400D0 8C470030 */   lw       $a3, 0x30($v0)
/* BDD284 802400D4 4600A306 */  mov.s     $f12, $f20
/* BDD288 802400D8 0C00A70A */  jal       get_clamped_angle_diff
/* BDD28C 802400DC 46000386 */   mov.s    $f14, $f0
/* BDD290 802400E0 46000005 */  abs.s     $f0, $f0
/* BDD294 802400E4 3C018024 */  lui       $at, %hi(D_80241AE8)
/* BDD298 802400E8 D4221AE8 */  ldc1      $f2, %lo(D_80241AE8)($at)
/* BDD29C 802400EC 46000021 */  cvt.d.s   $f0, $f0
/* BDD2A0 802400F0 4620103C */  c.lt.d    $f2, $f0
/* BDD2A4 802400F4 00000000 */  nop
/* BDD2A8 802400F8 45030001 */  bc1tl     .L80240100
/* BDD2AC 802400FC 0000802D */   daddu    $s0, $zero, $zero
.L80240100:
/* BDD2B0 80240100 8E420000 */  lw        $v0, ($s2)
/* BDD2B4 80240104 C620003C */  lwc1      $f0, 0x3c($s1)
/* BDD2B8 80240108 C442002C */  lwc1      $f2, 0x2c($v0)
/* BDD2BC 8024010C 46020001 */  sub.s     $f0, $f0, $f2
/* BDD2C0 80240110 3C014220 */  lui       $at, 0x4220
/* BDD2C4 80240114 44811000 */  mtc1      $at, $f2
/* BDD2C8 80240118 46000005 */  abs.s     $f0, $f0
/* BDD2CC 8024011C 4600103E */  c.le.s    $f2, $f0
/* BDD2D0 80240120 00000000 */  nop
/* BDD2D4 80240124 45030001 */  bc1tl     .L8024012C
/* BDD2D8 80240128 0000802D */   daddu    $s0, $zero, $zero
.L8024012C:
/* BDD2DC 8024012C 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* BDD2E0 80240130 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* BDD2E4 80240134 24020009 */  addiu     $v0, $zero, 9
/* BDD2E8 80240138 50620001 */  beql      $v1, $v0, .L80240140
/* BDD2EC 8024013C 0000802D */   daddu    $s0, $zero, $zero
.L80240140:
/* BDD2F0 80240140 0200102D */  daddu     $v0, $s0, $zero
/* BDD2F4 80240144 8FBF001C */  lw        $ra, 0x1c($sp)
/* BDD2F8 80240148 8FB20018 */  lw        $s2, 0x18($sp)
/* BDD2FC 8024014C 8FB10014 */  lw        $s1, 0x14($sp)
/* BDD300 80240150 8FB00010 */  lw        $s0, 0x10($sp)
/* BDD304 80240154 D7B40020 */  ldc1      $f20, 0x20($sp)
/* BDD308 80240158 03E00008 */  jr        $ra
/* BDD30C 8024015C 27BD0028 */   addiu    $sp, $sp, 0x28
