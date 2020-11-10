.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_update_cursor
/* 13681C 802434DC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 136820 802434E0 AFB10014 */  sw        $s1, 0x14($sp)
/* 136824 802434E4 00A0882D */  daddu     $s1, $a1, $zero
/* 136828 802434E8 AFB20018 */  sw        $s2, 0x18($sp)
/* 13682C 802434EC 00C0902D */  daddu     $s2, $a2, $zero
/* 136830 802434F0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 136834 802434F4 0C090B9B */  jal       pause_interp_cursor
/* 136838 802434F8 AFB00010 */   sw       $s0, 0x10($sp)
/* 13683C 802434FC 3C058025 */  lui       $a1, %hi(gPauseMenuCursorOpacity)
/* 136840 80243500 8CA5EFA4 */  lw        $a1, %lo(gPauseMenuCursorOpacity)($a1)
/* 136844 80243504 18A00012 */  blez      $a1, .L80243550
/* 136848 80243508 28A20100 */   slti     $v0, $a1, 0x100
/* 13684C 8024350C 50400001 */  beql      $v0, $zero, .L80243514
/* 136850 80243510 240500FF */   addiu    $a1, $zero, 0xff
.L80243514:
/* 136854 80243514 3C108027 */  lui       $s0, 0x8027
/* 136858 80243518 261000E8 */  addiu     $s0, $s0, 0xe8
/* 13685C 8024351C 0C0513AC */  jal       icon_set_opacity
/* 136860 80243520 8E040000 */   lw       $a0, ($s0)
/* 136864 80243524 8E040000 */  lw        $a0, ($s0)
/* 136868 80243528 3C058025 */  lui       $a1, %hi(gPauseMenuCursorPos)
/* 13686C 8024352C 8CA5EF9C */  lw        $a1, %lo(gPauseMenuCursorPos)($a1)
/* 136870 80243530 3C068025 */  lui       $a2, 0x8025
/* 136874 80243534 8CC6EFA0 */  lw        $a2, -0x1060($a2)
/* 136878 80243538 02252821 */  addu      $a1, $s1, $a1
/* 13687C 8024353C 0C051261 */  jal       set_icon_render_pos
/* 136880 80243540 02463021 */   addu     $a2, $s2, $a2
/* 136884 80243544 8E040000 */  lw        $a0, ($s0)
/* 136888 80243548 0C0511F8 */  jal       draw_icon_2
/* 13688C 8024354C 00000000 */   nop      
.L80243550:
/* 136890 80243550 8FBF001C */  lw        $ra, 0x1c($sp)
/* 136894 80243554 8FB20018 */  lw        $s2, 0x18($sp)
/* 136898 80243558 8FB10014 */  lw        $s1, 0x14($sp)
/* 13689C 8024355C 8FB00010 */  lw        $s0, 0x10($sp)
/* 1368A0 80243560 03E00008 */  jr        $ra
/* 1368A4 80243564 27BD0020 */   addiu    $sp, $sp, 0x20
