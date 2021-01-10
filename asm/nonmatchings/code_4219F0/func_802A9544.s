.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9544
/* 421F34 802A9544 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 421F38 802A9548 AFB00010 */  sw        $s0, 0x10($sp)
/* 421F3C 802A954C 3C10802A */  lui       $s0, %hi(D_8029FBE0)
/* 421F40 802A9550 2610FBE0 */  addiu     $s0, $s0, %lo(D_8029FBE0)
/* 421F44 802A9554 AFBF0014 */  sw        $ra, 0x14($sp)
/* 421F48 802A9558 0C0511EA */  jal       draw_icon_0
/* 421F4C 802A955C 8E040004 */   lw       $a0, 4($s0)
/* 421F50 802A9560 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 421F54 802A9564 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 421F58 802A9568 904200AA */  lbu       $v0, 0xaa($v0)
/* 421F5C 802A956C 30420001 */  andi      $v0, $v0, 1
/* 421F60 802A9570 14400003 */  bnez      $v0, .L802A9580
/* 421F64 802A9574 00000000 */   nop      
/* 421F68 802A9578 0C0511EA */  jal       draw_icon_0
/* 421F6C 802A957C 8E040008 */   lw       $a0, 8($s0)
.L802A9580:
/* 421F70 802A9580 8FBF0014 */  lw        $ra, 0x14($sp)
/* 421F74 802A9584 8FB00010 */  lw        $s0, 0x10($sp)
/* 421F78 802A9588 03E00008 */  jr        $ra
/* 421F7C 802A958C 27BD0018 */   addiu    $sp, $sp, 0x18
