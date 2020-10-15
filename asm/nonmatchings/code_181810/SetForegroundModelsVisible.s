.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetForegroundModelsVisible
/* 1823CC 80253AEC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1823D0 80253AF0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1823D4 80253AF4 8C82000C */  lw        $v0, 0xc($a0)
/* 1823D8 80253AF8 0C0B1EAF */  jal       get_variable
/* 1823DC 80253AFC 8C450000 */   lw       $a1, ($v0)
/* 1823E0 80253B00 10400005 */  beqz      $v0, .L80253B18
/* 1823E4 80253B04 00000000 */   nop      
/* 1823E8 80253B08 0C099F4A */  jal       show_foreground_models
/* 1823EC 80253B0C 00000000 */   nop      
/* 1823F0 80253B10 08094EC8 */  j         .L80253B20
/* 1823F4 80253B14 00000000 */   nop      
.L80253B18:
/* 1823F8 80253B18 0C099F2D */  jal       hide_foreground_models
/* 1823FC 80253B1C 00000000 */   nop      
.L80253B20:
/* 182400 80253B20 8FBF0010 */  lw        $ra, 0x10($sp)
/* 182404 80253B24 24020002 */  addiu     $v0, $zero, 2
/* 182408 80253B28 03E00008 */  jr        $ra
/* 18240C 80253B2C 27BD0018 */   addiu    $sp, $sp, 0x18
