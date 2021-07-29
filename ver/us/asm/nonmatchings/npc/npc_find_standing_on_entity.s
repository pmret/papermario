.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel npc_find_standing_on_entity
/* 185D4 8003D1D4 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 185D8 8003D1D8 AFB20018 */  sw        $s2, 0x18($sp)
/* 185DC 8003D1DC 34924000 */  ori       $s2, $a0, 0x4000
/* 185E0 8003D1E0 0240202D */  daddu     $a0, $s2, $zero
/* 185E4 8003D1E4 AFBF0028 */  sw        $ra, 0x28($sp)
/* 185E8 8003D1E8 AFB50024 */  sw        $s5, 0x24($sp)
/* 185EC 8003D1EC AFB40020 */  sw        $s4, 0x20($sp)
/* 185F0 8003D1F0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 185F4 8003D1F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 185F8 8003D1F8 0C04417A */  jal       get_entity_by_index
/* 185FC 8003D1FC AFB00010 */   sw       $s0, 0x10($sp)
/* 18600 8003D200 0000882D */  daddu     $s1, $zero, $zero
/* 18604 8003D204 C440004C */  lwc1      $f0, 0x4c($v0)
/* 18608 8003D208 3C014120 */  lui       $at, 0x4120
/* 1860C 8003D20C 44811000 */  mtc1      $at, $f2
/* 18610 8003D210 3C148000 */  lui       $s4, 0x8000
/* 18614 8003D214 46020001 */  sub.s     $f0, $f0, $f2
/* 18618 8003D218 36940004 */  ori       $s4, $s4, 4
/* 1861C 8003D21C 3C150400 */  lui       $s5, 0x400
/* 18620 8003D220 4600010D */  trunc.w.s $f4, $f0
/* 18624 8003D224 44132000 */  mfc1      $s3, $f4
.L8003D228:
/* 18628 8003D228 3C03800A */  lui       $v1, %hi(gCurrentNpcListPtr)
/* 1862C 8003D22C 8C630B90 */  lw        $v1, %lo(gCurrentNpcListPtr)($v1)
/* 18630 8003D230 00111080 */  sll       $v0, $s1, 2
/* 18634 8003D234 00431021 */  addu      $v0, $v0, $v1
/* 18638 8003D238 8C500000 */  lw        $s0, ($v0)
/* 1863C 8003D23C 52000022 */  beql      $s0, $zero, .L8003D2C8
/* 18640 8003D240 26310001 */   addiu    $s1, $s1, 1
/* 18644 8003D244 8E030000 */  lw        $v1, ($s0)
/* 18648 8003D248 5060001F */  beql      $v1, $zero, .L8003D2C8
/* 1864C 8003D24C 26310001 */   addiu    $s1, $s1, 1
/* 18650 8003D250 00741024 */  and       $v0, $v1, $s4
/* 18654 8003D254 5440001C */  bnel      $v0, $zero, .L8003D2C8
/* 18658 8003D258 26310001 */   addiu    $s1, $s1, 1
/* 1865C 8003D25C C602003C */  lwc1      $f2, 0x3c($s0)
/* 18660 8003D260 44930000 */  mtc1      $s3, $f0
/* 18664 8003D264 00000000 */  nop
/* 18668 8003D268 46800020 */  cvt.s.w   $f0, $f0
/* 1866C 8003D26C 4600103C */  c.lt.s    $f2, $f0
/* 18670 8003D270 00000000 */  nop
/* 18674 8003D274 45030014 */  bc1tl     .L8003D2C8
/* 18678 8003D278 26310001 */   addiu    $s1, $s1, 1
/* 1867C 8003D27C 30628008 */  andi      $v0, $v1, 0x8008
/* 18680 8003D280 10400008 */  beqz      $v0, .L8003D2A4
/* 18684 8003D284 00000000 */   nop
/* 18688 8003D288 0C00F4BE */  jal       npc_get_collider_below
/* 1868C 8003D28C 0200202D */   daddu    $a0, $s0, $zero
/* 18690 8003D290 0040182D */  daddu     $v1, $v0, $zero
/* 18694 8003D294 5060000C */  beql      $v1, $zero, .L8003D2C8
/* 18698 8003D298 26310001 */   addiu    $s1, $s1, 1
/* 1869C 8003D29C 0800F4AE */  j         .L8003D2B8
/* 186A0 8003D2A0 00000000 */   nop
.L8003D2A4:
/* 186A4 8003D2A4 96020084 */  lhu       $v0, 0x84($s0)
/* 186A8 8003D2A8 86030084 */  lh        $v1, 0x84($s0)
/* 186AC 8003D2AC 30424000 */  andi      $v0, $v0, 0x4000
/* 186B0 8003D2B0 50400005 */  beql      $v0, $zero, .L8003D2C8
/* 186B4 8003D2B4 26310001 */   addiu    $s1, $s1, 1
.L8003D2B8:
/* 186B8 8003D2B8 56430003 */  bnel      $s2, $v1, .L8003D2C8
/* 186BC 8003D2BC 26310001 */   addiu    $s1, $s1, 1
/* 186C0 8003D2C0 0800F4B5 */  j         .L8003D2D4
/* 186C4 8003D2C4 0220102D */   daddu    $v0, $s1, $zero
.L8003D2C8:
/* 186C8 8003D2C8 2A220040 */  slti      $v0, $s1, 0x40
/* 186CC 8003D2CC 1440FFD6 */  bnez      $v0, .L8003D228
/* 186D0 8003D2D0 2402FFFF */   addiu    $v0, $zero, -1
.L8003D2D4:
/* 186D4 8003D2D4 8FBF0028 */  lw        $ra, 0x28($sp)
/* 186D8 8003D2D8 8FB50024 */  lw        $s5, 0x24($sp)
/* 186DC 8003D2DC 8FB40020 */  lw        $s4, 0x20($sp)
/* 186E0 8003D2E0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 186E4 8003D2E4 8FB20018 */  lw        $s2, 0x18($sp)
/* 186E8 8003D2E8 8FB10014 */  lw        $s1, 0x14($sp)
/* 186EC 8003D2EC 8FB00010 */  lw        $s0, 0x10($sp)
/* 186F0 8003D2F0 03E00008 */  jr        $ra
/* 186F4 8003D2F4 27BD0030 */   addiu    $sp, $sp, 0x30
