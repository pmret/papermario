.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6550_E23C30
/* E23C30 802B6550 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E23C34 802B6554 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* E23C38 802B6558 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* E23C3C 802B655C AFBF0010 */  sw        $ra, 0x10($sp)
/* E23C40 802B6560 8C620004 */  lw        $v0, 4($v1)
/* E23C44 802B6564 30422000 */  andi      $v0, $v0, 0x2000
/* E23C48 802B6568 14400013 */  bnez      $v0, .L802B65B8
/* E23C4C 802B656C 00000000 */   nop      
/* E23C50 802B6570 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* E23C54 802B6574 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* E23C58 802B6578 9062007E */  lbu       $v0, 0x7e($v1)
/* E23C5C 802B657C 30420010 */  andi      $v0, $v0, 0x10
/* E23C60 802B6580 14400009 */  bnez      $v0, .L802B65A8
/* E23C64 802B6584 3C04000D */   lui      $a0, 0xd
/* E23C68 802B6588 90620080 */  lbu       $v0, 0x80($v1)
/* E23C6C 802B658C 00021080 */  sll       $v0, $v0, 2
/* E23C70 802B6590 3C04802B */  lui       $a0, %hi(D_802B6910)
/* E23C74 802B6594 00822021 */  addu      $a0, $a0, $v0
/* E23C78 802B6598 0C037FBF */  jal       func_800DFEFC
/* E23C7C 802B659C 8C846910 */   lw       $a0, %lo(D_802B6910)($a0)
/* E23C80 802B65A0 080AD977 */  j         .L802B65DC
/* E23C84 802B65A4 00000000 */   nop      
.L802B65A8:
/* E23C88 802B65A8 0C037FBF */  jal       func_800DFEFC
/* E23C8C 802B65AC 3484000D */   ori      $a0, $a0, 0xd
/* E23C90 802B65B0 080AD977 */  j         .L802B65DC
/* E23C94 802B65B4 00000000 */   nop      
.L802B65B8:
/* E23C98 802B65B8 8063000C */  lb        $v1, 0xc($v1)
/* E23C9C 802B65BC 00031040 */  sll       $v0, $v1, 1
/* E23CA0 802B65C0 00431021 */  addu      $v0, $v0, $v1
/* E23CA4 802B65C4 000210C0 */  sll       $v0, $v0, 3
/* E23CA8 802B65C8 3C04800F */  lui       $a0, %hi(D_800F7C20)
/* E23CAC 802B65CC 00822021 */  addu      $a0, $a0, $v0
/* E23CB0 802B65D0 8C847C20 */  lw        $a0, %lo(D_800F7C20)($a0)
/* E23CB4 802B65D4 0C0398DB */  jal       func_800E636C
/* E23CB8 802B65D8 00000000 */   nop      
.L802B65DC:
/* E23CBC 802B65DC 8FBF0010 */  lw        $ra, 0x10($sp)
/* E23CC0 802B65E0 03E00008 */  jr        $ra
/* E23CC4 802B65E4 27BD0018 */   addiu    $sp, $sp, 0x18
