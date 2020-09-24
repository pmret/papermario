.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel show_foreground_models_unchecked
/* 196528 80267C48 3C02800E */  lui       $v0, 0x800e
/* 19652C 80267C4C 8C42C4A8 */  lw        $v0, -0x3b58($v0)
/* 196530 80267C50 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 196534 80267C54 AFBF0014 */  sw        $ra, 0x14($sp)
/* 196538 80267C58 10400012 */  beqz      $v0, .L80267CA4
/* 19653C 80267C5C AFB00010 */   sw       $s0, 0x10($sp)
/* 196540 80267C60 8C420018 */  lw        $v0, 0x18($v0)
/* 196544 80267C64 1040000F */  beqz      $v0, .L80267CA4
/* 196548 80267C68 0040802D */   daddu    $s0, $v0, $zero
.L80267C6C:
/* 19654C 80267C6C 8E020000 */  lw        $v0, ($s0)
/* 196550 80267C70 1040000C */  beqz      $v0, .L80267CA4
/* 196554 80267C74 00000000 */   nop      
/* 196558 80267C78 8E040000 */  lw        $a0, ($s0)
/* 19655C 80267C7C 0480FFFB */  bltz      $a0, .L80267C6C
/* 196560 80267C80 26100004 */   addiu    $s0, $s0, 4
/* 196564 80267C84 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 196568 80267C88 00000000 */   nop      
/* 19656C 80267C8C 0C046B4C */  jal       get_model_from_list_index
/* 196570 80267C90 0040202D */   daddu    $a0, $v0, $zero
/* 196574 80267C94 94430000 */  lhu       $v1, ($v0)
/* 196578 80267C98 3063FFFD */  andi      $v1, $v1, 0xfffd
/* 19657C 80267C9C 08099F1B */  j         .L80267C6C
/* 196580 80267CA0 A4430000 */   sh       $v1, ($v0)
.L80267CA4:
/* 196584 80267CA4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 196588 80267CA8 8FB00010 */  lw        $s0, 0x10($sp)
/* 19658C 80267CAC 03E00008 */  jr        $ra
/* 196590 80267CB0 27BD0018 */   addiu    $sp, $sp, 0x18
