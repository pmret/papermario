.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802AA014_42B504
/* 42B504 802AA014 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 42B508 802AA018 AFB00010 */  sw        $s0, 0x10($sp)
/* 42B50C 802AA01C 3C10802A */  lui       $s0, %hi(D_8029FBE0)
/* 42B510 802AA020 2610FBE0 */  addiu     $s0, $s0, %lo(D_8029FBE0)
/* 42B514 802AA024 AFBF0018 */  sw        $ra, 0x18($sp)
/* 42B518 802AA028 AFB10014 */  sw        $s1, 0x14($sp)
/* 42B51C 802AA02C 0C0511EA */  jal       draw_icon_0
/* 42B520 802AA030 8E040004 */   lw       $a0, 4($s0)
/* 42B524 802AA034 0C0511EA */  jal       draw_icon_0
/* 42B528 802AA038 8E040008 */   lw       $a0, 8($s0)
/* 42B52C 802AA03C 0C0511EA */  jal       draw_icon_0
/* 42B530 802AA040 8E04000C */   lw       $a0, 0xc($s0)
/* 42B534 802AA044 0C0511EA */  jal       draw_icon_0
/* 42B538 802AA048 8E040010 */   lw       $a0, 0x10($s0)
/* 42B53C 802AA04C 0C0511EA */  jal       draw_icon_0
/* 42B540 802AA050 8E040014 */   lw       $a0, 0x14($s0)
/* 42B544 802AA054 0C0511EA */  jal       draw_icon_0
/* 42B548 802AA058 8E04001C */   lw       $a0, 0x1c($s0)
/* 42B54C 802AA05C 0C0511EA */  jal       draw_icon_0
/* 42B550 802AA060 8E040020 */   lw       $a0, 0x20($s0)
/* 42B554 802AA064 0C0511EA */  jal       draw_icon_0
/* 42B558 802AA068 8E040024 */   lw       $a0, 0x24($s0)
/* 42B55C 802AA06C 0C0511EA */  jal       draw_icon_0
/* 42B560 802AA070 8E040038 */   lw       $a0, 0x38($s0)
/* 42B564 802AA074 8E11002C */  lw        $s1, 0x2c($s0)
/* 42B568 802AA078 0C05122C */  jal       get_menu_icon_script
/* 42B56C 802AA07C 0220202D */   daddu    $a0, $s1, $zero
/* 42B570 802AA080 3C03800E */  lui       $v1, %hi(gBattleStatus+0x84)
/* 42B574 802AA084 8063C0F4 */  lb        $v1, %lo(gBattleStatus+0x84)($v1)
/* 42B578 802AA088 00031880 */  sll       $v1, $v1, 2
/* 42B57C 802AA08C 3C05802B */  lui       $a1, %hi(D_802AB180)
/* 42B580 802AA090 00A32821 */  addu      $a1, $a1, $v1
/* 42B584 802AA094 8CA5B180 */  lw        $a1, %lo(D_802AB180)($a1)
/* 42B588 802AA098 10450003 */  beq       $v0, $a1, .L802AA0A8
/* 42B58C 802AA09C 00000000 */   nop
/* 42B590 802AA0A0 0C0511FF */  jal       set_menu_icon_script
/* 42B594 802AA0A4 0220202D */   daddu    $a0, $s1, $zero
.L802AA0A8:
/* 42B598 802AA0A8 0C0511EA */  jal       draw_icon_0
/* 42B59C 802AA0AC 0220202D */   daddu    $a0, $s1, $zero
/* 42B5A0 802AA0B0 8E040030 */  lw        $a0, 0x30($s0)
/* 42B5A4 802AA0B4 0C0511EA */  jal       draw_icon_0
/* 42B5A8 802AA0B8 00000000 */   nop
/* 42B5AC 802AA0BC 0C0511EA */  jal       draw_icon_0
/* 42B5B0 802AA0C0 8E040034 */   lw       $a0, 0x34($s0)
/* 42B5B4 802AA0C4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 42B5B8 802AA0C8 8FB10014 */  lw        $s1, 0x14($sp)
/* 42B5BC 802AA0CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 42B5C0 802AA0D0 03E00008 */  jr        $ra
/* 42B5C4 802AA0D4 27BD0020 */   addiu    $sp, $sp, 0x20
