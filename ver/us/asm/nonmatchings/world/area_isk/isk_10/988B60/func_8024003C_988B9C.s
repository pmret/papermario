.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024003C_988B9C
/* 988B9C 8024003C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 988BA0 80240040 AFBF0010 */  sw        $ra, 0x10($sp)
/* 988BA4 80240044 8C82000C */  lw        $v0, 0xc($a0)
/* 988BA8 80240048 0C0B1EAF */  jal       get_variable
/* 988BAC 8024004C 8C450000 */   lw       $a1, ($v0)
/* 988BB0 80240050 0C0B95A4 */  jal       entity_upgrade_block_hide_content
/* 988BB4 80240054 0040202D */   daddu    $a0, $v0, $zero
/* 988BB8 80240058 8FBF0010 */  lw        $ra, 0x10($sp)
/* 988BBC 8024005C 24020002 */  addiu     $v0, $zero, 2
/* 988BC0 80240060 03E00008 */  jr        $ra
/* 988BC4 80240064 27BD0018 */   addiu    $sp, $sp, 0x18
