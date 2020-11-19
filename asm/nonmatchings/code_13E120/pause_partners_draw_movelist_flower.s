.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_partners_draw_movelist_flower
/* 13F3E0 8024C0A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 13F3E4 8024C0A4 AFB00010 */  sw        $s0, 0x10($sp)
/* 13F3E8 8024C0A8 3C108027 */  lui       $s0, 0x8027
/* 13F3EC 8024C0AC 26100640 */  addiu     $s0, $s0, 0x640
/* 13F3F0 8024C0B0 24A50011 */  addiu     $a1, $a1, 0x11
/* 13F3F4 8024C0B4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 13F3F8 8024C0B8 8E040004 */  lw        $a0, 4($s0)
/* 13F3FC 8024C0BC 0C051261 */  jal       set_icon_render_pos
/* 13F400 8024C0C0 24C60010 */   addiu    $a2, $a2, 0x10
/* 13F404 8024C0C4 8E040004 */  lw        $a0, 4($s0)
/* 13F408 8024C0C8 0C0511F8 */  jal       draw_icon_2
/* 13F40C 8024C0CC 00000000 */   nop      
/* 13F410 8024C0D0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 13F414 8024C0D4 8FB00010 */  lw        $s0, 0x10($sp)
/* 13F418 8024C0D8 03E00008 */  jr        $ra
/* 13F41C 8024C0DC 27BD0018 */   addiu    $sp, $sp, 0x18
