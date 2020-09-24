.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetForegroundModelsVisibleUnchecked
/* 182388 80253AA8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 18238C 80253AAC AFBF0010 */  sw        $ra, 0x10($sp)
/* 182390 80253AB0 8C82000C */  lw        $v0, 0xc($a0)
/* 182394 80253AB4 0C0B1EAF */  jal       get_variable
/* 182398 80253AB8 8C450000 */   lw       $a1, ($v0)
/* 18239C 80253ABC 10400005 */  beqz      $v0, .L80253AD4
/* 1823A0 80253AC0 00000000 */   nop      
/* 1823A4 80253AC4 0C099F12 */  jal       show_foreground_models_unchecked
/* 1823A8 80253AC8 00000000 */   nop      
/* 1823AC 80253ACC 08094EB7 */  j         .L80253ADC
/* 1823B0 80253AD0 00000000 */   nop      
.L80253AD4:
/* 1823B4 80253AD4 0C099EF7 */  jal       hide_foreground_models_unchecked
/* 1823B8 80253AD8 00000000 */   nop      
.L80253ADC:
/* 1823BC 80253ADC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1823C0 80253AE0 24020002 */  addiu     $v0, $zero, 2
/* 1823C4 80253AE4 03E00008 */  jr        $ra
/* 1823C8 80253AE8 27BD0018 */   addiu    $sp, $sp, 0x18
