.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240050_A6ACF0
/* A6ACF0 80240050 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A6ACF4 80240054 AFB10014 */  sw        $s1, 0x14($sp)
/* A6ACF8 80240058 0080882D */  daddu     $s1, $a0, $zero
/* A6ACFC 8024005C AFBF001C */  sw        $ra, 0x1c($sp)
/* A6AD00 80240060 AFB20018 */  sw        $s2, 0x18($sp)
/* A6AD04 80240064 AFB00010 */  sw        $s0, 0x10($sp)
/* A6AD08 80240068 8E30000C */  lw        $s0, 0xc($s1)
/* A6AD0C 8024006C 8E050000 */  lw        $a1, ($s0)
/* A6AD10 80240070 0C0B1EAF */  jal       get_variable
/* A6AD14 80240074 26100004 */   addiu    $s0, $s0, 4
/* A6AD18 80240078 0220202D */  daddu     $a0, $s1, $zero
/* A6AD1C 8024007C 8E120000 */  lw        $s2, ($s0)
/* A6AD20 80240080 0C0B36B0 */  jal       resolve_npc
/* A6AD24 80240084 0040282D */   daddu    $a1, $v0, $zero
/* A6AD28 80240088 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* A6AD2C 8024008C 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* A6AD30 80240090 0040182D */  daddu     $v1, $v0, $zero
/* A6AD34 80240094 1060002F */  beqz      $v1, .L80240154
/* A6AD38 80240098 24020002 */   addiu    $v0, $zero, 2
/* A6AD3C 8024009C C6000028 */  lwc1      $f0, 0x28($s0)
/* A6AD40 802400A0 3C018024 */  lui       $at, 0x8024
/* A6AD44 802400A4 D4221E50 */  ldc1      $f2, 0x1e50($at)
/* A6AD48 802400A8 4600010D */  trunc.w.s $f4, $f0
/* A6AD4C 802400AC 44022000 */  mfc1      $v0, $f4
/* A6AD50 802400B0 00000000 */  nop       
/* A6AD54 802400B4 2442FD44 */  addiu     $v0, $v0, -0x2bc
/* A6AD58 802400B8 44820000 */  mtc1      $v0, $f0
/* A6AD5C 802400BC 00000000 */  nop       
/* A6AD60 802400C0 46800021 */  cvt.d.w   $f0, $f0
/* A6AD64 802400C4 46220002 */  mul.d     $f0, $f0, $f2
/* A6AD68 802400C8 00000000 */  nop       
/* A6AD6C 802400CC 4620010D */  trunc.w.d $f4, $f0
/* A6AD70 802400D0 44022000 */  mfc1      $v0, $f4
/* A6AD74 802400D4 00000000 */  nop       
/* A6AD78 802400D8 244202FD */  addiu     $v0, $v0, 0x2fd
/* A6AD7C 802400DC 44820000 */  mtc1      $v0, $f0
/* A6AD80 802400E0 00000000 */  nop       
/* A6AD84 802400E4 46800020 */  cvt.s.w   $f0, $f0
/* A6AD88 802400E8 E4600038 */  swc1      $f0, 0x38($v1)
/* A6AD8C 802400EC C6020054 */  lwc1      $f2, 0x54($s0)
/* A6AD90 802400F0 44800000 */  mtc1      $zero, $f0
/* A6AD94 802400F4 00000000 */  nop       
/* A6AD98 802400F8 46001032 */  c.eq.s    $f2, $f0
/* A6AD9C 802400FC 00000000 */  nop       
/* A6ADA0 80240100 45000003 */  bc1f      .L80240110
/* A6ADA4 80240104 3C02000A */   lui      $v0, 0xa
/* A6ADA8 80240108 0809004D */  j         .L80240134
/* A6ADAC 8024010C 34420001 */   ori      $v0, $v0, 1
.L80240110:
/* A6ADB0 80240110 3C014000 */  lui       $at, 0x4000
/* A6ADB4 80240114 44810000 */  mtc1      $at, $f0
/* A6ADB8 80240118 00000000 */  nop       
/* A6ADBC 8024011C 4600103C */  c.lt.s    $f2, $f0
/* A6ADC0 80240120 00000000 */  nop       
/* A6ADC4 80240124 45000003 */  bc1f      .L80240134
/* A6ADC8 80240128 34420003 */   ori      $v0, $v0, 3
/* A6ADCC 8024012C 3C02000A */  lui       $v0, 0xa
/* A6ADD0 80240130 34420002 */  ori       $v0, $v0, 2
.L80240134:
/* A6ADD4 80240134 0220202D */  daddu     $a0, $s1, $zero
/* A6ADD8 80240138 AC620028 */  sw        $v0, 0x28($v1)
/* A6ADDC 8024013C C6000080 */  lwc1      $f0, 0x80($s0)
/* A6ADE0 80240140 4600010D */  trunc.w.s $f4, $f0
/* A6ADE4 80240144 44062000 */  mfc1      $a2, $f4
/* A6ADE8 80240148 0C0B2026 */  jal       set_variable
/* A6ADEC 8024014C 0240282D */   daddu    $a1, $s2, $zero
/* A6ADF0 80240150 24020002 */  addiu     $v0, $zero, 2
.L80240154:
/* A6ADF4 80240154 8FBF001C */  lw        $ra, 0x1c($sp)
/* A6ADF8 80240158 8FB20018 */  lw        $s2, 0x18($sp)
/* A6ADFC 8024015C 8FB10014 */  lw        $s1, 0x14($sp)
/* A6AE00 80240160 8FB00010 */  lw        $s0, 0x10($sp)
/* A6AE04 80240164 03E00008 */  jr        $ra
/* A6AE08 80240168 27BD0020 */   addiu    $sp, $sp, 0x20
/* A6AE0C 8024016C 00000000 */  nop       
