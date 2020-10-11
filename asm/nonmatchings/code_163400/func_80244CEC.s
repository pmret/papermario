.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244CEC
/* 16554C 80244CEC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 165550 80244CF0 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 165554 80244CF4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 165558 80244CF8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 16555C 80244CFC AFB00010 */  sw        $s0, 0x10($sp)
/* 165560 80244D00 904300AB */  lbu       $v1, 0xab($v0)
/* 165564 80244D04 24020001 */  addiu     $v0, $zero, 1
/* 165568 80244D08 14620009 */  bne       $v1, $v0, .L80244D30
/* 16556C 80244D0C 24A50022 */   addiu    $a1, $a1, 0x22
/* 165570 80244D10 3C108025 */  lui       $s0, 0x8025
/* 165574 80244D14 2610C0B0 */  addiu     $s0, $s0, -0x3f50
/* 165578 80244D18 8E040048 */  lw        $a0, 0x48($s0)
/* 16557C 80244D1C 0C051261 */  jal       set_icon_render_pos
/* 165580 80244D20 24C6000A */   addiu    $a2, $a2, 0xa
/* 165584 80244D24 8E040048 */  lw        $a0, 0x48($s0)
/* 165588 80244D28 08091352 */  j         .L80244D48
/* 16558C 80244D2C 00000000 */   nop      
.L80244D30:
/* 165590 80244D30 3C108025 */  lui       $s0, 0x8025
/* 165594 80244D34 2610C0B0 */  addiu     $s0, $s0, -0x3f50
/* 165598 80244D38 8E04004C */  lw        $a0, 0x4c($s0)
/* 16559C 80244D3C 0C051261 */  jal       set_icon_render_pos
/* 1655A0 80244D40 24C6000A */   addiu    $a2, $a2, 0xa
/* 1655A4 80244D44 8E04004C */  lw        $a0, 0x4c($s0)
.L80244D48:
/* 1655A8 80244D48 0C0511F8 */  jal       draw_icon_2
/* 1655AC 80244D4C 00000000 */   nop      
/* 1655B0 80244D50 8FBF0014 */  lw        $ra, 0x14($sp)
/* 1655B4 80244D54 8FB00010 */  lw        $s0, 0x10($sp)
/* 1655B8 80244D58 03E00008 */  jr        $ra
/* 1655BC 80244D5C 27BD0018 */   addiu    $sp, $sp, 0x18
