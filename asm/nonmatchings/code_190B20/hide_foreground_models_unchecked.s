.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel hide_foreground_models_unchecked
/* 1964BC 80267BDC 3C02800E */  lui       $v0, 0x800e
/* 1964C0 80267BE0 8C42C4A8 */  lw        $v0, -0x3b58($v0)
/* 1964C4 80267BE4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1964C8 80267BE8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 1964CC 80267BEC 10400012 */  beqz      $v0, .L80267C38
/* 1964D0 80267BF0 AFB00010 */   sw       $s0, 0x10($sp)
/* 1964D4 80267BF4 8C420018 */  lw        $v0, 0x18($v0)
/* 1964D8 80267BF8 1040000F */  beqz      $v0, .L80267C38
/* 1964DC 80267BFC 0040802D */   daddu    $s0, $v0, $zero
.L80267C00:
/* 1964E0 80267C00 8E020000 */  lw        $v0, ($s0)
/* 1964E4 80267C04 1040000C */  beqz      $v0, .L80267C38
/* 1964E8 80267C08 00000000 */   nop      
/* 1964EC 80267C0C 8E040000 */  lw        $a0, ($s0)
/* 1964F0 80267C10 0480FFFB */  bltz      $a0, .L80267C00
/* 1964F4 80267C14 26100004 */   addiu    $s0, $s0, 4
/* 1964F8 80267C18 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 1964FC 80267C1C 00000000 */   nop      
/* 196500 80267C20 0C046B4C */  jal       get_model_from_list_index
/* 196504 80267C24 0040202D */   daddu    $a0, $v0, $zero
/* 196508 80267C28 94430000 */  lhu       $v1, ($v0)
/* 19650C 80267C2C 34630002 */  ori       $v1, $v1, 2
/* 196510 80267C30 08099F00 */  j         .L80267C00
/* 196514 80267C34 A4430000 */   sh       $v1, ($v0)
.L80267C38:
/* 196518 80267C38 8FBF0014 */  lw        $ra, 0x14($sp)
/* 19651C 80267C3C 8FB00010 */  lw        $s0, 0x10($sp)
/* 196520 80267C40 03E00008 */  jr        $ra
/* 196524 80267C44 27BD0018 */   addiu    $sp, $sp, 0x18
