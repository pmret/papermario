.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E5098
/* 7E548 800E5098 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 7E54C 800E509C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 7E550 800E50A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7E554 800E50A4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 7E558 800E50A8 AFB00010 */  sw        $s0, 0x10($sp)
/* 7E55C 800E50AC 94420134 */  lhu       $v0, 0x134($v0)
/* 7E560 800E50B0 14800002 */  bnez      $a0, .L800E50BC
/* 7E564 800E50B4 0044001A */   div      $zero, $v0, $a0
/* 7E568 800E50B8 0007000D */  break     7
.L800E50BC:
/* 7E56C 800E50BC 2401FFFF */   addiu    $at, $zero, -1
/* 7E570 800E50C0 14810004 */  bne       $a0, $at, .L800E50D4
/* 7E574 800E50C4 3C018000 */   lui      $at, 0x8000
/* 7E578 800E50C8 14410002 */  bne       $v0, $at, .L800E50D4
/* 7E57C 800E50CC 00000000 */   nop      
/* 7E580 800E50D0 0006000D */  break     6
.L800E50D4:
/* 7E584 800E50D4 00001810 */   mfhi     $v1
/* 7E588 800E50D8 14600019 */  bnez      $v1, .L800E5140
/* 7E58C 800E50DC 00000000 */   nop      
/* 7E590 800E50E0 3C048016 */  lui       $a0, %hi(gCollisionStatus+0x2)
/* 7E594 800E50E4 8484A552 */  lh        $a0, %lo(gCollisionStatus+0x2)($a0)
/* 7E598 800E50E8 0C016F6A */  jal       get_collider_type_by_id
/* 7E59C 800E50EC 00000000 */   nop      
/* 7E5A0 800E50F0 304300FF */  andi      $v1, $v0, 0xff
/* 7E5A4 800E50F4 24020006 */  addiu     $v0, $zero, 6
/* 7E5A8 800E50F8 10620003 */  beq       $v1, $v0, .L800E5108
/* 7E5AC 800E50FC 24020009 */   addiu    $v0, $zero, 9
/* 7E5B0 800E5100 14620004 */  bne       $v1, $v0, .L800E5114
/* 7E5B4 800E5104 24040141 */   addiu    $a0, $zero, 0x141
.L800E5108:
/* 7E5B8 800E5108 24040143 */  addiu     $a0, $zero, 0x143
/* 7E5BC 800E510C 08039446 */  j         .L800E5118
/* 7E5C0 800E5110 24030144 */   addiu    $v1, $zero, 0x144
.L800E5114:
/* 7E5C4 800E5114 24030142 */  addiu     $v1, $zero, 0x142
.L800E5118:
/* 7E5C8 800E5118 3C10800F */  lui       $s0, %hi(D_800F7B80)
/* 7E5CC 800E511C 26107B80 */  addiu     $s0, $s0, %lo(D_800F7B80)
/* 7E5D0 800E5120 86020000 */  lh        $v0, ($s0)
/* 7E5D4 800E5124 50400001 */  beql      $v0, $zero, .L800E512C
/* 7E5D8 800E5128 0060202D */   daddu    $a0, $v1, $zero
.L800E512C:
/* 7E5DC 800E512C 0C052736 */  jal       play_sound_at_player
/* 7E5E0 800E5130 0000282D */   daddu    $a1, $zero, $zero
/* 7E5E4 800E5134 96020000 */  lhu       $v0, ($s0)
/* 7E5E8 800E5138 38420001 */  xori      $v0, $v0, 1
/* 7E5EC 800E513C A6020000 */  sh        $v0, ($s0)
.L800E5140:
/* 7E5F0 800E5140 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7E5F4 800E5144 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E5F8 800E5148 03E00008 */  jr        $ra
/* 7E5FC 800E514C 27BD0018 */   addiu    $sp, $sp, 0x18
