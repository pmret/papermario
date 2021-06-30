.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_draw_contents_option_left
/* 165630 80244DD0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 165634 80244DD4 AFB00018 */  sw        $s0, 0x18($sp)
/* 165638 80244DD8 00A0802D */  daddu     $s0, $a1, $zero
/* 16563C 80244DDC AFB1001C */  sw        $s1, 0x1c($sp)
/* 165640 80244DE0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 165644 80244DE4 80830004 */  lb        $v1, 4($a0)
/* 165648 80244DE8 24020002 */  addiu     $v0, $zero, 2
/* 16564C 80244DEC 10620014 */  beq       $v1, $v0, .L80244E40
/* 165650 80244DF0 00C0882D */   daddu    $s1, $a2, $zero
/* 165654 80244DF4 3C0200FF */  lui       $v0, 0xff
/* 165658 80244DF8 8C830000 */  lw        $v1, ($a0)
/* 16565C 80244DFC 3442FF00 */  ori       $v0, $v0, 0xff00
/* 165660 80244E00 00621824 */  and       $v1, $v1, $v0
/* 165664 80244E04 24020200 */  addiu     $v0, $zero, 0x200
/* 165668 80244E08 14620003 */  bne       $v1, $v0, .L80244E18
/* 16566C 80244E0C 24040035 */   addiu    $a0, $zero, 0x35
/* 165670 80244E10 0C090B80 */  jal       filemenu_set_cursor_goal_pos
/* 165674 80244E14 26260008 */   addiu    $a2, $s1, 8
.L80244E18:
/* 165678 80244E18 0C0926A9 */  jal       filemenu_get_menu_message
/* 16567C 80244E1C 24040009 */   addiu    $a0, $zero, 9
/* 165680 80244E20 0040202D */  daddu     $a0, $v0, $zero
/* 165684 80244E24 26050008 */  addiu     $a1, $s0, 8
/* 165688 80244E28 26260002 */  addiu     $a2, $s1, 2
/* 16568C 80244E2C 24020001 */  addiu     $v0, $zero, 1
/* 165690 80244E30 240700FF */  addiu     $a3, $zero, 0xff
/* 165694 80244E34 AFA00010 */  sw        $zero, 0x10($sp)
/* 165698 80244E38 0C09265F */  jal       filemenu_draw_message
/* 16569C 80244E3C AFA20014 */   sw       $v0, 0x14($sp)
.L80244E40:
/* 1656A0 80244E40 8FBF0020 */  lw        $ra, 0x20($sp)
/* 1656A4 80244E44 8FB1001C */  lw        $s1, 0x1c($sp)
/* 1656A8 80244E48 8FB00018 */  lw        $s0, 0x18($sp)
/* 1656AC 80244E4C 03E00008 */  jr        $ra
/* 1656B0 80244E50 27BD0028 */   addiu    $sp, $sp, 0x28
