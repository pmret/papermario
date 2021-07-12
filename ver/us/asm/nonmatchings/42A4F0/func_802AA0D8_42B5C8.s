.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802AA0D8_42B5C8
/* 42B5C8 802AA0D8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 42B5CC 802AA0DC AFB00010 */  sw        $s0, 0x10($sp)
/* 42B5D0 802AA0E0 3C10802A */  lui       $s0, %hi(D_8029FBE0)
/* 42B5D4 802AA0E4 2610FBE0 */  addiu     $s0, $s0, %lo(D_8029FBE0)
/* 42B5D8 802AA0E8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 42B5DC 802AA0EC 0C05123D */  jal       free_hud_element
/* 42B5E0 802AA0F0 8E040004 */   lw       $a0, 4($s0)
/* 42B5E4 802AA0F4 0C05123D */  jal       free_hud_element
/* 42B5E8 802AA0F8 8E040008 */   lw       $a0, 8($s0)
/* 42B5EC 802AA0FC 0C05123D */  jal       free_hud_element
/* 42B5F0 802AA100 8E04000C */   lw       $a0, 0xc($s0)
/* 42B5F4 802AA104 0C05123D */  jal       free_hud_element
/* 42B5F8 802AA108 8E040010 */   lw       $a0, 0x10($s0)
/* 42B5FC 802AA10C 0C05123D */  jal       free_hud_element
/* 42B600 802AA110 8E040014 */   lw       $a0, 0x14($s0)
/* 42B604 802AA114 0C05123D */  jal       free_hud_element
/* 42B608 802AA118 8E04001C */   lw       $a0, 0x1c($s0)
/* 42B60C 802AA11C 0C05123D */  jal       free_hud_element
/* 42B610 802AA120 8E040020 */   lw       $a0, 0x20($s0)
/* 42B614 802AA124 0C05123D */  jal       free_hud_element
/* 42B618 802AA128 8E040024 */   lw       $a0, 0x24($s0)
/* 42B61C 802AA12C 0C05123D */  jal       free_hud_element
/* 42B620 802AA130 8E04002C */   lw       $a0, 0x2c($s0)
/* 42B624 802AA134 0C05123D */  jal       free_hud_element
/* 42B628 802AA138 8E040030 */   lw       $a0, 0x30($s0)
/* 42B62C 802AA13C 0C05123D */  jal       free_hud_element
/* 42B630 802AA140 8E040034 */   lw       $a0, 0x34($s0)
/* 42B634 802AA144 0C05123D */  jal       free_hud_element
/* 42B638 802AA148 8E040038 */   lw       $a0, 0x38($s0)
/* 42B63C 802AA14C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 42B640 802AA150 8FB00010 */  lw        $s0, 0x10($sp)
/* 42B644 802AA154 03E00008 */  jr        $ra
/* 42B648 802AA158 27BD0018 */   addiu    $sp, $sp, 0x18
/* 42B64C 802AA15C 00000000 */  nop
