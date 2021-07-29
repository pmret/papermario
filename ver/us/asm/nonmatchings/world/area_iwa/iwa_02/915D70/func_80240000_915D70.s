.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80242D40_918AB0
.double 180.0

glabel D_80242D48_918AB8
.double 75.0

.section .text

glabel func_80240000_915D70
/* 915D70 80240000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 915D74 80240004 AFBF001C */  sw        $ra, 0x1c($sp)
/* 915D78 80240008 AFB20018 */  sw        $s2, 0x18($sp)
/* 915D7C 8024000C AFB10014 */  sw        $s1, 0x14($sp)
/* 915D80 80240010 AFB00010 */  sw        $s0, 0x10($sp)
/* 915D84 80240014 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 915D88 80240018 8C900148 */  lw        $s0, 0x148($a0)
/* 915D8C 8024001C 86040008 */  lh        $a0, 8($s0)
/* 915D90 80240020 3C014387 */  lui       $at, 0x4387
/* 915D94 80240024 4481A000 */  mtc1      $at, $f20
/* 915D98 80240028 0C00EABB */  jal       get_npc_unsafe
/* 915D9C 8024002C 00A0882D */   daddu    $s1, $a1, $zero
/* 915DA0 80240030 0200202D */  daddu     $a0, $s0, $zero
/* 915DA4 80240034 8E26000C */  lw        $a2, 0xc($s1)
/* 915DA8 80240038 8E270010 */  lw        $a3, 0x10($s1)
/* 915DAC 8024003C 0040882D */  daddu     $s1, $v0, $zero
/* 915DB0 80240040 3C03800B */  lui       $v1, %hi(gCameras)
/* 915DB4 80240044 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 915DB8 80240048 3C02800A */  lui       $v0, %hi(gCurrentCamID)
/* 915DBC 8024004C 8442A634 */  lh        $v0, %lo(gCurrentCamID)($v0)
/* 915DC0 80240050 0000282D */  daddu     $a1, $zero, $zero
/* 915DC4 80240054 00028080 */  sll       $s0, $v0, 2
/* 915DC8 80240058 02028021 */  addu      $s0, $s0, $v0
/* 915DCC 8024005C 00108080 */  sll       $s0, $s0, 2
/* 915DD0 80240060 02028023 */  subu      $s0, $s0, $v0
/* 915DD4 80240064 001010C0 */  sll       $v0, $s0, 3
/* 915DD8 80240068 02028021 */  addu      $s0, $s0, $v0
/* 915DDC 8024006C 001080C0 */  sll       $s0, $s0, 3
/* 915DE0 80240070 0C0124FB */  jal       func_800493EC
/* 915DE4 80240074 02038021 */   addu     $s0, $s0, $v1
/* 915DE8 80240078 C60C006C */  lwc1      $f12, 0x6c($s0)
/* 915DEC 8024007C C62E000C */  lwc1      $f14, 0xc($s1)
/* 915DF0 80240080 0C00A70A */  jal       get_clamped_angle_diff
/* 915DF4 80240084 0002802B */   sltu     $s0, $zero, $v0
/* 915DF8 80240088 0C00A6C9 */  jal       clamp_angle
/* 915DFC 8024008C 46000306 */   mov.s    $f12, $f0
/* 915E00 80240090 3C018024 */  lui       $at, %hi(D_80242D40_918AB0)
/* 915E04 80240094 D4222D40 */  ldc1      $f2, %lo(D_80242D40_918AB0)($at)
/* 915E08 80240098 46000021 */  cvt.d.s   $f0, $f0
/* 915E0C 8024009C 4622003C */  c.lt.d    $f0, $f2
/* 915E10 802400A0 00000000 */  nop
/* 915E14 802400A4 45000003 */  bc1f      .L802400B4
/* 915E18 802400A8 00000000 */   nop
/* 915E1C 802400AC 3C0142B4 */  lui       $at, 0x42b4
/* 915E20 802400B0 4481A000 */  mtc1      $at, $f20
.L802400B4:
/* 915E24 802400B4 3C12800F */  lui       $s2, %hi(gPlayerStatusPtr)
/* 915E28 802400B8 26527B30 */  addiu     $s2, $s2, %lo(gPlayerStatusPtr)
/* 915E2C 802400BC C62C0038 */  lwc1      $f12, 0x38($s1)
/* 915E30 802400C0 8E420000 */  lw        $v0, ($s2)
/* 915E34 802400C4 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 915E38 802400C8 8C460028 */  lw        $a2, 0x28($v0)
/* 915E3C 802400CC 0C00A720 */  jal       atan2
/* 915E40 802400D0 8C470030 */   lw       $a3, 0x30($v0)
/* 915E44 802400D4 4600A306 */  mov.s     $f12, $f20
/* 915E48 802400D8 0C00A70A */  jal       get_clamped_angle_diff
/* 915E4C 802400DC 46000386 */   mov.s    $f14, $f0
/* 915E50 802400E0 46000005 */  abs.s     $f0, $f0
/* 915E54 802400E4 3C018024 */  lui       $at, %hi(D_80242D48_918AB8)
/* 915E58 802400E8 D4222D48 */  ldc1      $f2, %lo(D_80242D48_918AB8)($at)
/* 915E5C 802400EC 46000021 */  cvt.d.s   $f0, $f0
/* 915E60 802400F0 4620103C */  c.lt.d    $f2, $f0
/* 915E64 802400F4 00000000 */  nop
/* 915E68 802400F8 45030001 */  bc1tl     .L80240100
/* 915E6C 802400FC 0000802D */   daddu    $s0, $zero, $zero
.L80240100:
/* 915E70 80240100 8E420000 */  lw        $v0, ($s2)
/* 915E74 80240104 C620003C */  lwc1      $f0, 0x3c($s1)
/* 915E78 80240108 C442002C */  lwc1      $f2, 0x2c($v0)
/* 915E7C 8024010C 46020001 */  sub.s     $f0, $f0, $f2
/* 915E80 80240110 3C014220 */  lui       $at, 0x4220
/* 915E84 80240114 44811000 */  mtc1      $at, $f2
/* 915E88 80240118 46000005 */  abs.s     $f0, $f0
/* 915E8C 8024011C 4600103E */  c.le.s    $f2, $f0
/* 915E90 80240120 00000000 */  nop
/* 915E94 80240124 45030001 */  bc1tl     .L8024012C
/* 915E98 80240128 0000802D */   daddu    $s0, $zero, $zero
.L8024012C:
/* 915E9C 8024012C 3C038011 */  lui       $v1, %hi(D_8010EBB0+0x3)
/* 915EA0 80240130 8063EBB3 */  lb        $v1, %lo(D_8010EBB0+0x3)($v1)
/* 915EA4 80240134 24020009 */  addiu     $v0, $zero, 9
/* 915EA8 80240138 50620001 */  beql      $v1, $v0, .L80240140
/* 915EAC 8024013C 0000802D */   daddu    $s0, $zero, $zero
.L80240140:
/* 915EB0 80240140 0200102D */  daddu     $v0, $s0, $zero
/* 915EB4 80240144 8FBF001C */  lw        $ra, 0x1c($sp)
/* 915EB8 80240148 8FB20018 */  lw        $s2, 0x18($sp)
/* 915EBC 8024014C 8FB10014 */  lw        $s1, 0x14($sp)
/* 915EC0 80240150 8FB00010 */  lw        $s0, 0x10($sp)
/* 915EC4 80240154 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 915EC8 80240158 03E00008 */  jr        $ra
/* 915ECC 8024015C 27BD0028 */   addiu    $sp, $sp, 0x28
