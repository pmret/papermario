.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244D60
/* 1655C0 80244D60 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 1655C4 80244D64 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 1655C8 80244D68 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1655CC 80244D6C AFBF0014 */  sw        $ra, 0x14($sp)
/* 1655D0 80244D70 AFB00010 */  sw        $s0, 0x10($sp)
/* 1655D4 80244D74 904200AB */  lbu       $v0, 0xab($v0)
/* 1655D8 80244D78 14400009 */  bnez      $v0, .L80244DA0
/* 1655DC 80244D7C 24A50022 */   addiu    $a1, $a1, 0x22
/* 1655E0 80244D80 3C108025 */  lui       $s0, 0x8025
/* 1655E4 80244D84 2610C0B0 */  addiu     $s0, $s0, -0x3f50
/* 1655E8 80244D88 8E040040 */  lw        $a0, 0x40($s0)
/* 1655EC 80244D8C 0C051261 */  jal       set_icon_render_pos
/* 1655F0 80244D90 24C6000A */   addiu    $a2, $a2, 0xa
/* 1655F4 80244D94 8E040040 */  lw        $a0, 0x40($s0)
/* 1655F8 80244D98 0809136E */  j         .L80244DB8
/* 1655FC 80244D9C 00000000 */   nop      
.L80244DA0:
/* 165600 80244DA0 3C108025 */  lui       $s0, 0x8025
/* 165604 80244DA4 2610C0B0 */  addiu     $s0, $s0, -0x3f50
/* 165608 80244DA8 8E040044 */  lw        $a0, 0x44($s0)
/* 16560C 80244DAC 0C051261 */  jal       set_icon_render_pos
/* 165610 80244DB0 24C6000A */   addiu    $a2, $a2, 0xa
/* 165614 80244DB4 8E040044 */  lw        $a0, 0x44($s0)
.L80244DB8:
/* 165618 80244DB8 0C0511F8 */  jal       draw_icon_2
/* 16561C 80244DBC 00000000 */   nop      
/* 165620 80244DC0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 165624 80244DC4 8FB00010 */  lw        $s0, 0x10($sp)
/* 165628 80244DC8 03E00008 */  jr        $ra
/* 16562C 80244DCC 27BD0018 */   addiu    $sp, $sp, 0x18
