.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_info_init
/* 168830 80247FD0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 168834 80247FD4 AFB00010 */  sw        $s0, 0x10($sp)
/* 168838 80247FD8 0080802D */  daddu     $s0, $a0, $zero
/* 16883C 80247FDC 0000182D */  daddu     $v1, $zero, $zero
/* 168840 80247FE0 3C028025 */  lui       $v0, %hi(D_8024A134)
/* 168844 80247FE4 2442A134 */  addiu     $v0, $v0, %lo(D_8024A134)
/* 168848 80247FE8 AFBF0014 */  sw        $ra, 0x14($sp)
.L80247FEC:
/* 16884C 80247FEC AC500010 */  sw        $s0, 0x10($v0)
/* 168850 80247FF0 24630001 */  addiu     $v1, $v1, 1
/* 168854 80247FF4 1860FFFD */  blez      $v1, .L80247FEC
/* 168858 80247FF8 24420024 */   addiu    $v0, $v0, 0x24
/* 16885C 80247FFC 3C048025 */  lui       $a0, %hi(D_8024A134)
/* 168860 80248000 2484A134 */  addiu     $a0, $a0, %lo(D_8024A134)
/* 168864 80248004 0C051FCC */  jal       setup_pause_menu_tab
/* 168868 80248008 24050001 */   addiu    $a1, $zero, 1
/* 16886C 8024800C 24020001 */  addiu     $v0, $zero, 1
/* 168870 80248010 A2020000 */  sb        $v0, ($s0)
/* 168874 80248014 8FBF0014 */  lw        $ra, 0x14($sp)
/* 168878 80248018 8FB00010 */  lw        $s0, 0x10($sp)
/* 16887C 8024801C 03E00008 */  jr        $ra
/* 168880 80248020 27BD0018 */   addiu    $sp, $sp, 0x18
