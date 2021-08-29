.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240104_DA5344
/* DA5344 80240104 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DA5348 80240108 AFB10014 */  sw        $s1, 0x14($sp)
/* DA534C 8024010C 0080882D */  daddu     $s1, $a0, $zero
/* DA5350 80240110 AFBF0018 */  sw        $ra, 0x18($sp)
/* DA5354 80240114 AFB00010 */  sw        $s0, 0x10($sp)
/* DA5358 80240118 F7B40020 */  sdc1      $f20, 0x20($sp)
/* DA535C 8024011C 8E30000C */  lw        $s0, 0xc($s1)
/* DA5360 80240120 8E050000 */  lw        $a1, ($s0)
/* DA5364 80240124 0C0B210B */  jal       evt_get_float_variable
/* DA5368 80240128 26100004 */   addiu    $s0, $s0, 4
/* DA536C 8024012C 8E050000 */  lw        $a1, ($s0)
/* DA5370 80240130 26100004 */  addiu     $s0, $s0, 4
/* DA5374 80240134 0220202D */  daddu     $a0, $s1, $zero
/* DA5378 80240138 0C0B210B */  jal       evt_get_float_variable
/* DA537C 8024013C 46000506 */   mov.s    $f20, $f0
/* DA5380 80240140 4614003C */  c.lt.s    $f0, $f20
/* DA5384 80240144 00000000 */  nop
/* DA5388 80240148 45000004 */  bc1f      .L8024015C
/* DA538C 8024014C 0220202D */   daddu    $a0, $s1, $zero
/* DA5390 80240150 8E050000 */  lw        $a1, ($s0)
/* DA5394 80240154 08090059 */  j         .L80240164
/* DA5398 80240158 24060001 */   addiu    $a2, $zero, 1
.L8024015C:
/* DA539C 8024015C 8E050000 */  lw        $a1, ($s0)
/* DA53A0 80240160 0000302D */  daddu     $a2, $zero, $zero
.L80240164:
/* DA53A4 80240164 0C0B2026 */  jal       evt_set_variable
/* DA53A8 80240168 00000000 */   nop
/* DA53AC 8024016C 8FBF0018 */  lw        $ra, 0x18($sp)
/* DA53B0 80240170 8FB10014 */  lw        $s1, 0x14($sp)
/* DA53B4 80240174 8FB00010 */  lw        $s0, 0x10($sp)
/* DA53B8 80240178 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DA53BC 8024017C 24020002 */  addiu     $v0, $zero, 2
/* DA53C0 80240180 03E00008 */  jr        $ra
/* DA53C4 80240184 27BD0028 */   addiu    $sp, $sp, 0x28
