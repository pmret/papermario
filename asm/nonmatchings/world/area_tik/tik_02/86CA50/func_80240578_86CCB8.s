.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240578_86CCB8
/* 86CCB8 80240578 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 86CCBC 8024057C AFB00010 */  sw        $s0, 0x10($sp)
/* 86CCC0 80240580 0080802D */  daddu     $s0, $a0, $zero
/* 86CCC4 80240584 AFBF0014 */  sw        $ra, 0x14($sp)
/* 86CCC8 80240588 8E02000C */  lw        $v0, 0xc($s0)
/* 86CCCC 8024058C 0C0B1EAF */  jal       get_variable
/* 86CCD0 80240590 8C450000 */   lw       $a1, ($v0)
/* 86CCD4 80240594 00021140 */  sll       $v0, $v0, 5
/* 86CCD8 80240598 AE000084 */  sw        $zero, 0x84($s0)
/* 86CCDC 8024059C 3C018008 */  lui       $at, 0x8008
/* 86CCE0 802405A0 00220821 */  addu      $at, $at, $v0
/* 86CCE4 802405A4 942278F8 */  lhu       $v0, 0x78f8($at)
/* 86CCE8 802405A8 30420040 */  andi      $v0, $v0, 0x40
/* 86CCEC 802405AC 10400002 */  beqz      $v0, .L802405B8
/* 86CCF0 802405B0 24020001 */   addiu    $v0, $zero, 1
/* 86CCF4 802405B4 AE020084 */  sw        $v0, 0x84($s0)
.L802405B8:
/* 86CCF8 802405B8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 86CCFC 802405BC 8FB00010 */  lw        $s0, 0x10($sp)
/* 86CD00 802405C0 24020002 */  addiu     $v0, $zero, 2
/* 86CD04 802405C4 03E00008 */  jr        $ra
/* 86CD08 802405C8 27BD0018 */   addiu    $sp, $sp, 0x18
/* 86CD0C 802405CC 00000000 */  nop       
