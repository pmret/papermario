.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240578_99A1E8
/* 99A1E8 80240578 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 99A1EC 8024057C AFB00010 */  sw        $s0, 0x10($sp)
/* 99A1F0 80240580 0080802D */  daddu     $s0, $a0, $zero
/* 99A1F4 80240584 AFBF0014 */  sw        $ra, 0x14($sp)
/* 99A1F8 80240588 8E02000C */  lw        $v0, 0xc($s0)
/* 99A1FC 8024058C 0C0B1EAF */  jal       get_variable
/* 99A200 80240590 8C450000 */   lw       $a1, ($v0)
/* 99A204 80240594 00021140 */  sll       $v0, $v0, 5
/* 99A208 80240598 AE000084 */  sw        $zero, 0x84($s0)
/* 99A20C 8024059C 3C018008 */  lui       $at, 0x8008
/* 99A210 802405A0 00220821 */  addu      $at, $at, $v0
/* 99A214 802405A4 942278F8 */  lhu       $v0, 0x78f8($at)
/* 99A218 802405A8 30420040 */  andi      $v0, $v0, 0x40
/* 99A21C 802405AC 10400002 */  beqz      $v0, .L802405B8
/* 99A220 802405B0 24020001 */   addiu    $v0, $zero, 1
/* 99A224 802405B4 AE020084 */  sw        $v0, 0x84($s0)
.L802405B8:
/* 99A228 802405B8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 99A22C 802405BC 8FB00010 */  lw        $s0, 0x10($sp)
/* 99A230 802405C0 24020002 */  addiu     $v0, $zero, 2
/* 99A234 802405C4 03E00008 */  jr        $ra
/* 99A238 802405C8 27BD0018 */   addiu    $sp, $sp, 0x18
/* 99A23C 802405CC 00000000 */  nop       
