.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel remove_item_entity_by_index
/* 0CA0FC 801339FC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0CA100 80133A00 AFB00010 */  sw    $s0, 0x10($sp)
/* 0CA104 80133A04 0080802D */  daddu $s0, $a0, $zero
/* 0CA108 80133A08 3C028015 */  lui   $v0, 0x8015
/* 0CA10C 80133A0C 8C4265A0 */  lw    $v0, 0x65a0($v0)
/* 0CA110 80133A10 00101880 */  sll   $v1, $s0, 2
/* 0CA114 80133A14 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0CA118 80133A18 AFB10014 */  sw    $s1, 0x14($sp)
/* 0CA11C 80133A1C 00621821 */  addu  $v1, $v1, $v0
/* 0CA120 80133A20 8C630000 */  lw    $v1, ($v1)
/* 0CA124 80133A24 8064001B */  lb    $a0, 0x1b($v1)
/* 0CA128 80133A28 2C82001D */  sltiu $v0, $a0, 0x1d
/* 0CA12C 80133A2C 10400008 */  beqz  $v0, .L80133A50
/* 0CA130 80133A30 00041080 */   sll   $v0, $a0, 2
/* 0CA134 80133A34 3C018015 */  lui   $at, 0x8015
/* 0CA138 80133A38 00220821 */  addu  $at, $at, $v0
/* 0CA13C 80133A3C 8C220DA0 */  lw    $v0, 0xda0($at)
/* 0CA140 80133A40 00400008 */  jr    $v0
/* 0CA144 80133A44 00000000 */   nop   
/* 0CA148 80133A48 0C0448CA */  jal   func_80112328
/* 0CA14C 80133A4C 84640020 */   lh    $a0, 0x20($v1)
.L80133A50:
/* 0CA150 80133A50 3C118015 */  lui   $s1, 0x8015
/* 0CA154 80133A54 263165A0 */  addiu $s1, $s1, 0x65a0
/* 0CA158 80133A58 8E220000 */  lw    $v0, ($s1)
/* 0CA15C 80133A5C 00108080 */  sll   $s0, $s0, 2
/* 0CA160 80133A60 02021021 */  addu  $v0, $s0, $v0
/* 0CA164 80133A64 0C00AB4B */  jal   heap_free
/* 0CA168 80133A68 8C440000 */   lw    $a0, ($v0)
/* 0CA16C 80133A6C 8E220000 */  lw    $v0, ($s1)
/* 0CA170 80133A70 02028021 */  addu  $s0, $s0, $v0
/* 0CA174 80133A74 AE000000 */  sw    $zero, ($s0)
/* 0CA178 80133A78 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0CA17C 80133A7C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0CA180 80133A80 8FB00010 */  lw    $s0, 0x10($sp)
/* 0CA184 80133A84 3C018015 */  lui   $at, 0x8015
/* 0CA188 80133A88 A42065A4 */  sh    $zero, 0x65a4($at)
/* 0CA18C 80133A8C 03E00008 */  jr    $ra
/* 0CA190 80133A90 27BD0020 */   addiu $sp, $sp, 0x20

/* 0CA194 80133A94 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0CA198 80133A98 3C028015 */  lui   $v0, 0x8015
/* 0CA19C 80133A9C 8C4265A0 */  lw    $v0, 0x65a0($v0)
/* 0CA1A0 80133AA0 00042080 */  sll   $a0, $a0, 2
/* 0CA1A4 80133AA4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0CA1A8 80133AA8 00822021 */  addu  $a0, $a0, $v0
/* 0CA1AC 80133AAC 8C840000 */  lw    $a0, ($a0)
/* 0CA1B0 80133AB0 3C03FFFB */  lui   $v1, 0xfffb
/* 0CA1B4 80133AB4 8C820000 */  lw    $v0, ($a0)
/* 0CA1B8 80133AB8 3463FFFF */  ori   $v1, $v1, 0xffff
/* 0CA1BC 80133ABC A4850018 */  sh    $a1, 0x18($a0)
/* 0CA1C0 80133AC0 00052940 */  sll   $a1, $a1, 5
/* 0CA1C4 80133AC4 34424000 */  ori   $v0, $v0, 0x4000
/* 0CA1C8 80133AC8 00431824 */  and   $v1, $v0, $v1
/* 0CA1CC 80133ACC AC830000 */  sw    $v1, ($a0)
/* 0CA1D0 80133AD0 3C028008 */  lui   $v0, 0x8008
/* 0CA1D4 80133AD4 00451021 */  addu  $v0, $v0, $a1
/* 0CA1D8 80133AD8 944278F8 */  lhu   $v0, 0x78f8($v0)
/* 0CA1DC 80133ADC 30421000 */  andi  $v0, $v0, 0x1000
/* 0CA1E0 80133AE0 10400005 */  beqz  $v0, .L80133AF8
/* 0CA1E4 80133AE4 3C020004 */   lui   $v0, 4
/* 0CA1E8 80133AE8 00621025 */  or    $v0, $v1, $v0
/* 0CA1EC 80133AEC 2403BFFF */  addiu $v1, $zero, -0x4001
/* 0CA1F0 80133AF0 00431024 */  and   $v0, $v0, $v1
/* 0CA1F4 80133AF4 AC820000 */  sw    $v0, ($a0)
.L80133AF8:
/* 0CA1F8 80133AF8 0C04C44A */  jal   func_80131128
/* 0CA1FC 80133AFC 00000000 */   nop   
/* 0CA200 80133B00 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0CA204 80133B04 03E00008 */  jr    $ra
/* 0CA208 80133B08 27BD0018 */   addiu $sp, $sp, 0x18

